# MQTT Applications
## Java - Paho
### Paho
Paho is a Java library implementing MQTT **client** functionalities.

### Include Paho into the Java project
```xml
<repositories>
	<repository>
		<id>Eclipse Paho Repo</id>
		<url>https://repo.eclipse.org/content/repositories/paho-releases/</url>
	</repository>
</repositories>

<dependencies>
	<dependency>
		<groupId>org.eclipse.paho</groupId>
		<artifactId>org.eclipse.paho.client.mqttv3</artifactId>
		<version>1.2.0</version>
	</dependency>
</dependencies>
```

### Publisher example
```java
String topic = "alert";
String content = "Message from Java Client";
String broker = "tcp://127.0.0.1:1883";
String clientId = "JavaApp";

try {
	MqttClient sampleClient = new MqttClient(broker, clientId);
	sampleClient.connect();
	
	MqttMessage message = new MqttMessage(content.getBytes());
	
	sampleClient.publish(topic, message);
	sampleClient.disconnect();
	
} catch(MqttException me) {
	me.printStackTrace();
}
```

### Subscriber example
Subscriber works asynchronously. The structure is different as callbacks must be used. A class is created to implement the functions of the subscriber. It implements the MqttCallback interface.
```java
public class MyClient implements MqttCallback {
	public MyClient() throws MqttException {
	MqttClient mqttClient = new MqttClient(broker,clientId);
	mqttClient.setCallback( this );
	mqttClient.connect();
	mqttClient.subscribe(topic);
	}
```

The MqttCallback interface implements some functions that are invoked automatically by Paho when an event is received.
The function message Arrived is invoked automatically when a notification is received.
``` java
public void connectionLost(Throwable cause) {
// TODO Auto-generated method stub
}

public void messageArrived(String topic, MqttMessage message) throws Exception {
	System.out.println(String.format("[%s] %s", topic, new String(
		message.getPayload())));
}

public void deliveryComplete(IMqttDeliveryToken token) {
	// TODO Auto-generated method stub
}
```

The main function instantiates the class.
```java
public static void main(String[] args) {
	try {
		MyClient mc = new MyClient();
	} catch(MqttException me) {
		me.printStackTrace();
	}
}
```

## python - Paho
### Paho
The same MQTT implementation is provided for Python
`sudo pip install paho-mqtt`
Documentation and examples: https://pypi.org/project/paho-mqtt/

### MQTT Example
```python
import paho.mqtt.client as mqtt

# The callback for when the client receives a CONNACK response from the server.
def on_connect(client, userdata, flags, rc):
	print("Connected with result code "+str(rc))
	
	client.subscribe("alert")

# The callback for when a PUBLISH message is received from the server.
def on_message(client, userdata, msg):
	print(msg.topic+" "+str(msg.payload))

client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message

client.connect("127.0.0.1", 1883, 60)

client.publish("alert", payload="ciao")

client.loop_forever()
```
