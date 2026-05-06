# LAB – Message Queue Systems

*Hands on experience with RabbitMQ*

**References:**
- RabbitMQ documentation: https://www.rabbitmq.com/tutorials/

---

## RabbitMQ

RabbitMQ is an open-source message-broker software that implements the **Advanced Message Queuing Protocol (AMQP)**.

Different libraries are available for different languages to interface with RabbitMQ. For Python, the main library is **Pika**.

The basic architecture includes:
- A **Producer** application that enqueues messages
- A **Consumer** application that dequeues them
- The **Broker** (RabbitMQ) that routes messages between them

---

## RabbitMQ Message Flow

RabbitMQ is internally composed of:
- A set of **queues** (one for each consumer)
- A set of **exchanges** that route messages according to a set of rules (**bindings**)

The flow works as follows:

1. The **producer** publishes a message to an exchange (specifying the exchange type at creation time)
2. The **exchange** receives the message and routes it based on message attributes (e.g. routing key)
3. **Bindings** connect exchanges to queues; the exchange routes messages into the appropriate queues
4. **Messages** stay in the queue until consumed
5. The **consumer** handles the message

---

## Exchange Types

Each queue has an associated **routing key**. Three exchange types are available:

| Type | Behavior |
|------|----------|
| **Direct** | Routes to the queue whose binding key exactly matches the message's routing key |
| **Fanout** | Routes messages to **all** queues bound to the exchange |
| **Topic** | Performs a **wildcard match** between the routing key and the binding pattern |

---

## Deploy RabbitMQ in a Container

```bash
docker run -d --hostname my-rabbit --name some-rabbit rabbitmq:3
docker network inspect bridge
```

> Default credentials: `guest` / `guest`

---

## Create a RabbitMQ Producer

### Dockerfile

```dockerfile
FROM python:3-alpine

RUN mkdir -p /usr/src/app
WORKDIR /usr/src/app

# Install the Pika library
RUN pip3 install pika

# Force Pika to print output
ENV PYTHONUNBUFFERED=1

COPY producer.py /usr/src/app

ENTRYPOINT ["python3"]
CMD ["producer.py"]
```

### producer.py

```python
import pika

# Connect to RabbitMQ
connection = pika.BlockingConnection(pika.ConnectionParameters('172.17.0.5'))
channel = connection.channel()

# Create a queue
channel.queue_declare(queue='hello')

# Send the message (uses the default direct exchange)
channel.basic_publish(exchange='', routing_key='hello', body='Hello World!')

# Close the connection
connection.close()
```

> `exchange=''` selects the **default exchange** (direct type).

---

## Consumer Code

### consumer.py

```python
import pika

# Connect to RabbitMQ
connection = pika.BlockingConnection(pika.ConnectionParameters(host='172.17.0.5'))
channel = connection.channel()

# Declare the queue to consume from
channel.queue_declare(queue='hello')

# Callback invoked every time a message is received
def callback(ch, method, properties, body):
    print(" [x] Received %r" % body)

# Subscribe to the queue and assign the callback
channel.basic_consume(queue='hello', on_message_callback=callback, auto_ack=True)

print(' [*] Waiting for messages. To exit press CTRL+C')
channel.start_consuming()
```

---

## Build and Run

```bash
# Build images
docker build -t rabbitmq-consumer .
docker build -t rabbitmq-producer .

# Run containers
docker run -d --name consumer rabbitmq-consumer
docker run -d --name producer rabbitmq-producer
```

---

## Check Logs

```bash
docker logs consumer
docker logs producer
docker logs some-rabbit
```

---

## Work Queues

**Work Queues** (or Task Queues) dispatch work-intensive tasks among multiple workers:

1. One or more **task producers** encapsulate a task into a message and send it to the queue
2. A **worker** from a pool eventually becomes available and processes the task

### Deploy and Test Multiple Consumers

```bash
# Deploy more than one consumer, then restart the producer multiple times
docker restart producer
```

Check that messages are distributed across consumers. To prevent a busy consumer from receiving new messages before finishing the current one:

```python
channel.basic_qos(prefetch_count=1)
```

---

## Message Routing

Complex routing is achieved through **multiple exchanges and bindings**.

A **binding** is a relationship between an exchange and a queue:

```python
channel.queue_bind(exchange=exchange_name, queue=queue_name)
```

*"The queue is interested in messages from this exchange."*

Routing behavior depends on the exchange type. With **direct** exchange, a message goes to the queue whose binding key exactly matches the message's routing key.

---

## Exchange Example – Direct

### Producer

```python
# Declare a direct exchange
channel.exchange_declare(exchange='exchange_name', exchange_type='direct')

# Publish messages with different routing keys
channel.basic_publish(exchange='exchange_name', routing_key='name1', body='hello1')
channel.basic_publish(exchange='exchange_name', routing_key='name2', body='hello2')

connection.close()
```

### Consumer

```python
channel.exchange_declare(exchange='exchange_name', exchange_type='direct')

# Let the system generate a unique queue name
result = channel.queue_declare(queue='', exclusive=True)
queue_name = result.method.queue

# Bind the queue to one or more routing keys (can be done at runtime)
channel.queue_bind(exchange='exchange_name', queue=queue_name, routing_key='name1')
channel.queue_bind(exchange='exchange_name', queue=queue_name, routing_key='name2')

channel.basic_consume(queue=queue_name, on_message_callback=callback, auto_ack=True)
channel.start_consuming()
```

---

## Message Broadcast – Fanout Exchange

In the direct exchange example, messages sent to the same queue are dispatched **round-robin** across consumers. To deliver a message to **all** subscribers, use the **fanout** exchange type:

```python
channel.exchange_declare(exchange='logs', exchange_type='fanout')
```

Every queue bound to the `logs` exchange will receive a copy of each message.

---

## Message Exchange by Topic

The **topic** exchange type routes messages based on a **list of words** (topics) delimited by dots. Binding keys can use wildcards:

| Wildcard | Meaning |
|----------|---------|
| `*` | Substitutes for exactly **one** word |
| `#` | Substitutes for **zero or more** words |

**Example routing key pattern:** `<celerity>.<colour>.<species>`

- A queue bound to `*.orange.*` receives all messages about orange animals
- A queue bound to `*.*.rabbit` or `lazy.#` receives messages about rabbits or lazy animals

### Producer – Topic

```python
channel.exchange_declare(exchange='topics', exchange_type='topic')

routing_key1 = 'lazy.green.rabbit'
routing_key2 = 'fast.yellow.zebra'
message = 'Hello World!'

channel.basic_publish(exchange='topics', routing_key=routing_key1, body=message)
channel.basic_publish(exchange='topics', routing_key=routing_key2, body=message)

connection.close()
```

### Consumer – Topic

```python
channel.exchange_declare(exchange='topics', exchange_type='topic')

result = channel.queue_declare('', exclusive=True)
queue_name = result.method.queue

# Subscribe to all rabbits AND all lazy animals
channel.queue_bind(exchange='topics', queue=queue_name, routing_key='*.*.rabbit')
channel.queue_bind(exchange='topics', queue=queue_name, routing_key='lazy.#')
```

> With the producer above, only `lazy.green.rabbit` matches (`*.*.rabbit` and `lazy.#`) — so only the **first message** is received.

---

## Check RabbitMQ Status

Run these commands inside the RabbitMQ container:

```bash
# List all queues
docker exec CONTAINER_ID rabbitmqctl list_queues

# Show message stats per queue
docker exec CONTAINER_ID rabbitmqctl list_queues name messages_ready messages_unacknowledged
```
