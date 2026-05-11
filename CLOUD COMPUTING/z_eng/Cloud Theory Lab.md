
# 0B4 Virtualization

- **KVM**: is the virtualization module for the linux kernel, it functions as hypervisor
- **LibVirt**: tool for manage, create and configure VMs

- KVM allows the creation of VMs, LibVirt to manage them

- Usually the best installation method is to *import a preinstalled VM*

- **virsh**: CLI-based virtualization management toolkit, is the main command to interact with the vm 

- `virsh destroy` stop the virtual machine, is like a shut down
- `virsh undefine` delete the virtual machine (only context information)
- `virsh suspends` is like close the laptop, all program continue to run with their status preserved, is like a pause

- **Ciros**: small vm used to test environment

---

- `ip addr show`: shows all the network adapter, it comprehend the loopback address and the real ones

- A **Linux bridge** is a virtual interface that bridges different interfaces of a linux system (real interfaces or virtual interfaces)
- The bridge is performed at layer 2, so it is like connecting different networks through a switch

- Every virtual machine is equipped with a virtual network adapter managed by the hv and it behave like a real one,

- For each vnet0 you have a connection with the host os, the traffic that goes out the vm it is transmitted through the port connected to the vnet0 in the host machine
- All response will be injected in the vm through the vnet0 connected to the port that is receiving packets

- **virtbr0** is a linux bridge, another fake na (*network adapter*) that can be used in any linux system to put together multiple interfaces into a single network that is local to the machine
- It collect traffic from all the VMs and reroute them outside on the net, the result is that all the VMs can comunicate with each other using the bridge as a common area, and comunicate with the outside as well

##### Libvirt networking
- The virtual NIC of each VM created by the hypervisor has a corresponding virtual interface on the Host OS
- To create a virtual network all the virtual interfaces can be added to a bridge, so data is exchanged among different VMs
- The bridge can be connected to a physical interface to allow data exchange with external network
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260405164404.png|300]]


##### Default Network (NAT)
- By default the VMs are connected to an internal network and get internet access via NAT
- The creation of a new network is managed by LibVirt through the command `virsh net-define`
- The specifications of the new network must be described in a XML file
- Check networks available `virsh net-list`


##### Storage Pool
-  Storage for VM hard drives is offered by **storage pool**
-  Each storage pool allows to create different volumes, i.e. different virtual hard drives that can be attached to VMs
- Pools can be created using an existing file system or a whole partition

- **root hard drive**: the vm hd with the os
- each hd is created in the storage pool

- virtual hd in linux is created in form of file, you can have reference to them
- each hd is a set of partitions, a partition is a part dedicated to some functions 

- **snapshot**: create a snapshot of the *current image* of the VM, with its disk and memory content 
- then it is possible to use the snapshot to restore the status of the vm (like a *backup*)
- snapshot do not support secondary hard drive
- since it save entirely the status of a vm it can be used to clone a vm or to create a template of the vm 


# 0B6 Containers (Docker)

- **Docker**: an application that offers OS level virtualization to deliver sw in packages into *container*
- **Container** allow to isolate software and manage dependency
- is open source but managed by a private company


- **Docker** is a container technology for Linux that allows a developer to package up an application with all of the parts it needs.
- Containers are created from *locally available images*. Images are created from standard images that can be downloaded from public repositories. All operations are managed by the *Docker daemon*
- If you run a container, you download automatically the image
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260405161118.png|500]]

- We have a centralized point called *docker registry* a server that contains all the images and packages of the virtualized environment available to everyone
- every host install a docker service that takes care to install the **docker image** locally 
- Image are an image of the file system that docker will recreate locally, it contains binary file, configuration, data and library, all already configured

##### Define a custom image
- A custom docker image can be created from an existing one
- To this aim a Dockerfile must be created to describe the set of customizations to be performed
- For instance create an Ubuntu image that includes a python interpreter and run a python program at startup


**Difference between a VM and an image?**
- The ubuntu vm run a fully fledged machine, the os is not aware to be on a virtualized environment, the ubuntu container only have the file system (tools and libraries) the kernel is from the host

- Some docker repositories have a *rate limit*, so there is a limited number of machine that can access them at the same time 

- The command `run` without `-it` will run and end immediately, because it is usually used to perform single command, `-it` allow to run a command via *interactive manner*, in this way we do not terminate immediately, for instance with docker run -it ubuntu we run a terminal 

- `docker ps` give the list of container, with the flag `-a` it return the list of container that is running and that is stopped 

- To destroy an image, you need first to destroy all the container associated with that image

- To create a custom image we define a test file in a folder a file named `Dockerfile`



##### Docker Networking
- The **Virtual router** is created in the same way as the virtual private network 
- you need to expose at least one tier to the outside

- The *Docker engine* creates a **virtual network** to allow communication among different containers.
- In the default mode, for every container a virtual network adapter is created
- Every virtual interface have a private IPv4 address, communication among different containers can happen through routing or trough L2 forwarding if interfaces a bridged (as in the picture).
- A service listening on one port can be published to the external network, by using port forwarding
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260405165224.png]]


- Run the container and expose the port publicly through the command: `docker run -p 80:80 nginx-ubuntu`
- The option` -p 80:80` (in the command run, when run a container) we tell the system we want to expose the port 80 of the container as the port 80 of the host

- **Docker Compose** is a tool that allow definition of application and environment made up by multiple container that run concurrently 
- You need to create a YAML file to define all the containers inside, and then manage them with a set of simple commands, they share the same network, so they can easily comunicate with each others

- **Volume**: shared store between the container and the host system 

- Container running in the same host can communicate via their private IP address on the virtual network of containers



# 0C3. REST Interfaces (LAB)

### Design a REST interface
- There are no official guideline for the definition of REST API, but there are some common rules

- Basic terms:
	- **Resource**, an object or representation of something. It has associated some data and a set of methods to operate (e.g. an Employee of a company, you can create, add or delete it) 
	- **Collections**, a set of resources, e.g. Employees is the collection of Employee resources 
	- **URL**, the Uniform Resource Locator and the path corresponding to the resource (through which the resource can be accessed

- Every *action* is mapped to one of the basic four CRUD operation GET, SET, POST, DELETE
- The name of the endpoints should never include the action, the action should be included in the called request of the endpoint, e.g. $\color{red} \text{/getEmployee()}$ is wrong, $\color{green} \text{/GET/employee()}$ is right 

- The four basic operation are associated with the basic four operation used on database
  - Get: used to request data without producing any modification 
  - Post: used to create a new resource 
  - Put: used to update a resource (using a payload)
  - Delete: used to delete a resource

- A collection is represented with its name (e.g. employers), while a single resource within a collection can be represented with a unique ID or name (e.g. employers/ID)

##### API design
- We can use **swagger** to create the APIs documentation, and also a skeleton of our application 
- We can run a docker container with swagger and open it using the ip of the VM


- Swagger use *YAML* to describe the APIs, it describe a set of data and their method, you need to specify the basic URL of the system, the paths of the method and the response type
- you have also to define the structure of the requests 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260418171339.png]]

- You can also define resources' schema 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260418171353.png]]


- **Generate Server** of swagger allow to generate a skeleton of the API code defined in Yaml
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260410101503.png]]

- You can pass local variables to docker with `-e` 
- It is possible to use a database hosted into a container from other containers 

- It is also possible to generate curl commands from swagger 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260501201633.png]]


### Apache Tomcat
- **Apache tomcat** is an open-source implementation of the Java Servlet, a software component that extends the functionalities of a web server allowing to run Java code in response to an HTTP request 
- Java Servlets are the Java counterpart to other dynamic web content technologies such as PHP and ASP.NET 
- Tomcat instantiates an HTTP server to receive requests from clients 
- The server can have one or more servlets instantiated 
- A **Servlet** is an object that receives a request and generates a response based on that request 
- Servlets are packaged in a WAR file (Web Application)

### Python flask
- **Flask** is a lightweight web service application framework designed to produce REST applications as simple as possible
- The package that swagger produces is ready to be executed into a container


### HAProxy
- **HAProxy** can be used to balance request among multiple VMs

- Here 8081 is the port for external requests, and 8080 is used for internal requests
``` bash
docker run --name=flask1 --network=labnet -p 8081:8080 -d rest-server
```

![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260418172327.png]]

- What HAProxy adds to the multi-tier architecture:
  - **Space uncoupling**: the client sends requests to a single stable endpoint (:80), unaware of how many backend instances exist
  - **Load balancing**: requests are distributed across Flask replicas (round-robin by default); more replicas can be added without changing the client
  - **Health checks**: HAProxy monitors backends and stops routing to failed containers automatically




# 0C5. Message Queue Systems (LAB)  
### RabbitMQ
- **RabbitMQ** is an open-source message-broker software that implements the **Advanced Message queuing Protocol** (*AMQP*)
- Different libraries available for different languages implement the functionalities required to interface with RabbitMQ, among them we have _PIKA_, a python library
- PIKA is an interface for Rabbit via python 

- The basic architecture includes a Producer application and a Consumer application, the producer enqueues messages, the consumer dequeues them 
- Broker functionalities implemented by RabbitMQ take care of routing the messages between them
- This paradigm can also be bidirectional, the Producer produce a request, the consumer consume the request and give the response to the request
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260501202535.png]]


### RabbitMQ flow
- RabbitMQ internally is composed of a *set of queues* (one for each consumer) and a set of exchanges that take care of routing the messages. Routing occurs according to a set of rules (*binding*)

1. The producer publishes a message to an exchange. When creating an exchange, the type must be specified. 
2. The exchange receives the message and is now responsible for routing the message. The exchange takes different message attributes into account, such as the routing key, depending on the exchange type.
3. Bindings must be created from the exchange to queues. In this case, there are two bindings to two different queues from the exchange. The exchange routes the message into the queues depending on message attributes.
4. The messages stay in the queue until they are handled by a consumer
5. The consumer handles the message.
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260418173123.png|400]]

- The exchange mq is an entity implementing a certain messaging policy
- A broker can have different exchanges that implement different policies 
- The exchange choose in which queue put the message, the routing depend on various factor for instance the routing key and the exchange type 
- Every exchange have associated a set of queue, an each of them is bonded to certain queue


### Exchange types
- Each queue has associated a *routing key*

- There are three types of exchange:
  - **Direct**: The message is routed to the queues whose binding key exactly matches the routing key of the message. 
  - **Fanout**: A fanout exchange routes messages to all the queues bound to it. 
  - **Topic**: The topic exchange performs a wildcard match between the routing key and the routing pattern specified in the binding
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260418172814.png]]

---
- Docker network inspect bridge retrieve the ip address of the container
- Il parameter è l'indirizzo di rabbit
- Exchange choose the type of exchange, the default is usually the direct
- The *routing key* is a label assigned to the message used for the exchange
- Body is the content of the message

- The consumer stay awake waiting for message to consume
- The consumer have a callback function that is automatically invoked each time a message from a specific queue arrive
- Basic consume allow you to subscribe to a channel 
- Start consuming will halt che execution of the program that will wait for messages

### Work Queues
- **Work Queues** (or *Task Queues*) can be created to dispatch work- intensive tasks among different workers 
- One or more tasks producers encapsulate the task into a message and send the message to the message queue system 
- A worker (from a pool of workers) eventually becomes available and receives and processes the task

- Each worker subscribe to the queue, and receive message 

### Message routing 
- *Complex message routing* can be performed by creating multiple exchanges and bindings 
- A **binding** is a relationship between an exchange and a queue 
- The message routing behavior for a binding depends on the type of exchange 
- For instance, direct exchange is simple: a message goes to the queues whose binding key (the name of the queue) exactly matches the routing key of the message

### Message broadcast
- In the previous example messages were dispatched to the different consumers registered to the same queue in a round robin fashion (direct message exchange type)
- If we want the messages to be delivered to all the subscribers, we need to change the exchange type to **fanout**


### Message Exchange by Topic
- The **topic exchange** type allows to route messages based not on a routing key but on a list of words (topics) delimited by dots 
- Topic definitions can exploit *wildcards*, like * to substitute for exactly one word or # to substitute for zero or more words, through them bindings key that receive messages from different producers can be created 
- In the example, if we consider a routing key with the following pattern, **\<celerity>.\<color>.\<species>**, Q1 will receive all the messages regarding oranges animals, while Q2 all messages about rabbits or lazy animals 
 ![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260418173721.png]]



# 0D2. OpenStack Installation (LAB)

### Key Concepts (Summary)

- **MicroStack**
  → single-node OpenStack deployment

- **Snap**
  → package manager used for installation

- **Initialization**
  → configures all OpenStack services automatically

- **Horizon**
  → web interface for management

- **Keystone password**
  → required for authentication

- **Single-node limitation**
  → suitable for testing, not production


# 0D3. OpenStack Operations (LAB)

### Flavors

- A **Flavor** defines the hardware configuration of a VM:
  - CPU (vCPUs)
  - RAM
  - Disk size

- It determines how many resources are allocated **at VM creation time**

- Important:
  → at least one flavor must exist before creating VMs

- Create a flavor:
  - Admin → Flavors → Create Flavor
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260501203650.png|333]]

### Pre-created Flavors
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260501203731.png]]

---

### Images

- VMs are instantiated from **Images**:
  → templates of virtual disks with pre-installed OS

- Requirements:
  - at least one image must be available

- Example image (Cirros - lightweight test OS):
  http://download.cirros-cloud.net/0.4.0/cirros-0.4.0-x86_64-disk.img

- Upload image:
  - Admin → Images → Create Image
  - Select downloaded file

---

### Instantiate a VM

- Launch instance:
  - Project → Compute → Instances → Launch Instance

- During creation:
  - choose image
  - choose flavor
  - assign network

---

### Inspect Running VM

- View instances:
  - Admin → Compute → Instances

- Each VM has:
  - a host (physical node)
  - an internal IP address (private network)

---

### Console Access

- OpenStack provides a **web console**
  → direct access to VM (like a remote terminal)

---

### Network Configuration

- By default:
  - 1 internal network (private)
  - 1 external network (public)

---

### Create a New Network

- Path:
  - Admin → Network → Networks → Create Network

- Purpose:
  → isolate VMs or create custom network topologies

---

### Attach VM to Network

- Connect VM to new network:
  - Instances → Attach Interface

- A VM can:
  → have multiple network interfaces

---

### Floating IPs

- Used to expose a VM to the Internet

- Key idea:
  - VM has private IP
  - Floating IP is mapped via **NAT**

- Important:
  → Floating IP is NOT directly assigned to the VM interface

- Assign floating IP:
  - Instance → Associate Floating IP → Request new IP

---

### Security Groups (Firewall)

- By default:
  → **all incoming traffic is blocked**

- Enable ingress traffic:
  - Network → Security Groups → Manage Rules → Add Rule

- Example:
  - allow SSH (port 22)
  - allow HTTP (port 80)

---

### Virtual Router

- Required to connect:
  → internal network ↔ external network

- Create router:
  - Project → Network → Routers → Create Router

- The router:
  - has an interface on external network
  - performs routing + NAT

---

### Connect Router to Internal Network

- Steps:
  - Open router configuration
  - Go to Interfaces tab
  - Add Interface to internal network

- Without this:
  → VMs cannot reach external network

---

### Volumes

- A **Volume**:
  → additional virtual disk attached to VM

- Features:
  - can be attached/detached dynamically
  - persists independently from VM lifecycle

- Create volume:
  - Volumes → Create Volume

- Note:
  → may not be available in MicroStack installations

---

### OpenStack SDK (Python)

- OpenStack provides SDK for automation

- Install:
```
apt-get install python3-pip
pip3 install openstacksdk
```

- Authenticate:
  - download credentials file (e.g. `openstack.sh`)
```
source openstack.sh
```

---

### Example Python Application

```python
import openstack

# Connect to OpenStack
conn = openstack.connect()

# List images
for image in conn.compute.images():
    print(image)

# List servers (VMs)
print("List Servers:")
for server in conn.compute.servers():
    print(server)
```

---

### Key Concepts (Summary)

- **Flavor** → defines VM resources
- **Image** → OS template
- **Instance** → running VM
- **Floating IP** → external access via NAT
- **Security Groups** → firewall rules
- **Router** → connects private ↔ public network
- **Volume** → persistent storage
- **SDK / CLI** → automation tools


# 0D5. Kubernetes Installation (LAB)

### Charmed Bundle (Juju-based Installation)

- A **Charmed Bundle** is an automated deployment mechanism based on **Juju**
- It uses a **YAML file** to describe:
  - which components to install (e.g., control plane, workers)
  - where to install them (specific machines)
  - configuration parameters for each component

- Key idea:
  → fully automated Kubernetes deployment on multiple machines

---

### Minikube (Single-node Kubernetes)

- **Minikube** is a lightweight Kubernetes installation:
  - runs on a single machine
  - used for testing and development
  - does NOT represent production environment

- Uses:
  → Docker (or other runtimes) as container engine

---
### Key Concepts (Summary)

- **Juju / Charmed Bundle**
  → production-like multi-node deployment

- **Minikube**
  → local testing environment

- **Docker**
  → container runtime

- **kubectl**
  → CLI to interact with cluster

- **CNI plugins**
  → networking layer for Pods

- **MetalLB**
  → external load balancing in local environments


# 0D6. Kubernetes Operations (LAB)

### Define a Pod

- Kubernetes works with a **declarative model**:
  → you describe the desired state, and Kubernetes enforces it.

- A **Pod**:
  - smallest deployable unit
  - contains one or more containers
  - containers share:
    - network (same IP)
    - storage
    - lifecycle

- Pod configuration is defined via a **YAML file**
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260501204522.png]]

### Pod Operations

- Create the Pod  
  `kubectl apply -f pod.yaml`

- Check status  
  `kubectl get pods`

- Delete Pod  
  `kubectl delete pod helloworld`

---

### Deployment with Replicas

- Pods alone:
  → no lifecycle management (no restart, no scaling)

- A **Deployment**:
  - manages Pods
  - ensures:
    - desired number of replicas
    - automatic restart (self-healing)
    - rolling updates
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260501204634.png|300]]

### Deployment Operations

- Create deployment  
  `kubectl apply -f deployment.yaml`

- Check deployment  
  `kubectl get deployments`  
  `kubectl get pods`

- Test self-healing (Kubernetes recreates the Pod)  
  `kubectl delete pod <pod-name>`

---

### Service Exposure

- Pods are not directly accessible → need a **Service**

#### Internal service (ClusterIP)

- Create service  
  `kubectl expose deployment/helloworld`

- Check services  
  `kubectl get services`

- **ClusterIP**:
  - internal virtual IP
  - reachable only inside cluster
  - used for service-to-service communication

---

### Endpoints

- Each Pod has:
  → internal IP (private network)

- Problem:
  → Pods are dynamic → IP changes when recreated

- Solution:
  → Service provides a **stable virtual IP**

---

### ClusterIP Behavior

- Service exposes a **Virtual IP**
- Requests sent to this IP are:
  → load-balanced across Pods

---

### Expose the Service to External Systems  
  
- To expose a service outside the Kubernetes cluster, use **NodePort**  
  
```  
kubectl expose deployment/helloworld --type=NodePort  
kubectl get services  
```  
  
- Behavior:  
- Kubernetes opens a port on each node  
- The port is **randomly assigned** (within a predefined range, usually 30000–32767)  
- Incoming traffic → forwarded to the service → then to Pods  
  
---  
  
### LoadBalancer (Preferred Solution)  
  
- Best approach in production environments:  
→ use an **external Load Balancer**  
  
- Features:  
- assigns a **public IP address**  
- distributes traffic across multiple Pods  
- implements load balancing policies automatically  
  
- Steps:  
  
```  
kubectl delete service helloworld  
  
kubectl expose deployment helloworld \  
--port=8080 \  
--type=LoadBalancer  
```  
  
- Then:  
→ check service and test connectivity  
  
---  
  
### Minikube Bug (Known Issue)  
  
- Reference:  
https://github.com/kubernetes/minikube/issues/13898  
  
- Problem:  
→ LoadBalancer / networking may not work correctly in Minikube  
  
---  
  
### Fix Before Next Exercise  
  
- Restart Minikube with updated configuration:  
  
```  
minikube stop  
  
minikube start --extra-config=kubelet.housekeeping-interval=10s  
```  
  
- Purpose:  
→ improve resource cleanup and stability  
  
---  
  
### Horizontal Autoscaling  
  
- Goal:  
→ automatically scale number of Pods based on workload  
  
- Example scenario:  
- create a deployment  
- simulate heavy computation  
- limit CPU usage per Pod  
- Kubernetes scales replicas dynamically
### Key Concepts (Summary)

- **Pod** → smallest unit (container group)
- **Deployment** → manages Pods lifecycle
- **Service** → stable access point
- **ClusterIP** → internal communication
- **NodePort / LoadBalancer** → external access
- **HPA** → automatic scaling based on metrics
