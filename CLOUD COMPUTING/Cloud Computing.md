
# 01 Storia del Cloud Computing

- ==The **Cloud Computing** is a model for enabling always present, convenient, on-demand network access to a shared pool of configurable computing resources that can be rapidly provisioned and released with minimal management effort of service provider interactions==

- The Cloud computing is not a sudden innovation, it is the result of a series of developments that have taken place over the past few decades
- The first concept of cloud computing dates back to 1960, when it was coined by **McCarthy** (“computation may someday be organized as a public utility”). However, it took more than 40 years for the idea to develop and mature through the union of a series of key technologies
- Cloud computing is therefore the composition of several key technologies, each of which represents an essential pillar


##### The origin - Mainframes
- The commercial usage of computing starts in the 1970 with the mainframes, large and costly super computer that occupy an entire room, it was used simultaneously by different users (usually with a time shared utilization) from multiple terminals 
- Terminal were dumb, so only able to transfer input-output data to/from the mainframe, there was a bottleneck and users had to wait in queue 

- At the end of 70' personal computer started to spread, those allowed to reduce costs and multiple person could run their own computations and applications, but they had limited capability 
- At the same time was born networking, connecting computer together to exchange data and coordinate to execute complex tasks, at this time LAN and WAN were introduced for the first time


##### Distributed Application
- There are two different paradigm:
  - *Client/Server computing*: server offers service or information to some clients
  - *Peer to peer computing*: each computer can offers or require information
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260304093847.png]]

- In the 80' there was a breakthrough in computing power, but at some point we crash in a wall on how much computing power can have a single machine, this lead to the **parallel processing paradigm**, multiple processors working together to solve a single task

- parallel task evolved into **distributed computing systems** thanks to the advancements in data transfer rates, now we have different machines that comunicate with each other to complete complex tasks and exchange data
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260304094120.png]]


##### Cluster computing
- At the beginning, machines in *distributed computing systems* where organized in **clusters**, groups of multiple nodes connected to the same LAN to perform similar tasks
- The cluster was a revolution because you can run difficult tasks, but each cluster was a single point of failure, each cluster have a **cluster head** responsible to receive and assign tasks inside the cluster, and if the head fail the cluster can't receive any task

- We have tasks that can be divided in multiple subtasks, each of them can be classified in different categories
- Each cluster can execute a subtask, each computer of the cluster could execute a sub-subtask (this is how at the beginning distributed system where organized)
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260304094434.png]]


##### Grid Computing
- To resolve the single point of failure problem we introduced **grid computing**, where task were assigned in a *distributed manner* without a cluster head 
- Every computer inside the cluster is coordinated with the other computer inside the cluster to select another computer for the execution of the task received by the cluster 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260304094559.png]]

- In cluster it was difficult to elect another head because head usually have a specialized hardware, so you can't elect another way easily
 - In grid computer hardware was not specialized instead inside a cluster 


- Grid computing *drawbacks*: 
  - is impossible to have real time scale because you have to reinstall all the software
  - Expansion could take days or weeks
  - The system was not fault tolerant, the failure of a node results in the failure of a task
  - We had heterogeneous hardware an this require to adjust code 


##### Hardware Virtualization
- The heterogeneous natures of computing systems was challenging to code portability (because we needed to adapt the code to the different hardware)

-  **Hardware virtualization** is a technology that is able to create an environment where software can be executed in different hardware without changes
- Is a layer to hidden hardware specific to software
- is one of the pillar of cloud computer

##### Web Based Technologies
- The **web based technology** provided a simple mechanism to give access to application or cloud computing infrastructures to users

##### Service Oriented Architecture
- **Service Oriented Architecture** is a development method that develop application divided in software component that interact with each other, each component is independent and comunicate with the others via messages
- a key idea is to break down complex logic in to simpler smaller modules

##### Utility Computing Model
- **Utility Computing Model**: delivering of computing resource as utility, following a *pay per use* model and *on demand*

##### Timeline
- Cloud Computing is the evolution of a set of technologies happened on a wide amount of time from the 70' to the late 90', in 90' we had the first cc service, commercialized by amazon, it was called the EC2
- CC today is a market that is valued around 210 billion, 80% of company have a positive impact by its adoption 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260304095654.png]]


# 02 Introduction and Foundation Concepts
- Cloud Computing is a buzzword that refer to both the applications delivered as services over the internet, and the hw and sw infrastructures in the datacenter that provides those services 

- **Cloud Computing**: is a distinct IT environment designed for the purpose of remotely providing *scalable* and *measured* IT resources that are accessible via the internet

- The distinct IT environment are for instance Datacenter, some example of IT resources are memory and computing power (RAM + CPU)
- If resources aren't scalable and measurable you simply have a remote server hosting a resource, and is not cloud computing 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260304100320.png]]

##### Cloud Services
- **Cloud infrastructure**: is the remote IT distinct environment providing the resources (e.g. the datacenter that host the resources)
- It provides the resources to implement the cloud service

- **Cloud Service**: is an application or a service provided by the infrastructure
- in the first case usually it provides an interface that is accessed directly by users via web pages, in the second case it expose a set of API and not an interface, in this case is usually accessed by other application and not directly by users

##### Everything as a Service - XaaS
- **Everything as a services Xaas** is the trend to evolve everything to a services that execute remotely on the cloud in the form of a cloud service 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260304100335.png]]

- Cloud service examples:
  - cloud file storage service: file are uploaded to the cloud, from there you can download, share and access them
  - cloud ERP service: the ERP (software used by companies to manage the internal processes) is deployed in the cloud (usually on a server inside the company network), and employees can access it through a web interface or a dedicated client 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260304100507.png]]


##### Roles
- There are *seven main roles* in a cloud infrastructure 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260304101242.png]]

- The **Cloud Provider** is an organization that provides cloud-based IT resources, they usually design and manage a cloud platform for property (e.g. AWS)

- The **Cloud Consumer** is an organization (or a human) that has a formal contract or arrangement with the Cloud Provider to use IT resources. He can own a cloud service, however, it does need to be the user of the service (it can sell it to other customers)

- The **Cloud Service Owner** is the person or organization that create a cloud service running on the resources provided by the cloud infrastructure. It create the cloud service for profit, so it is usually sold as a product to cloud service users, they usually pay a month fee to access to the service

- The **Cloud Resource Administrator** is the person or the organization responsible for administering cloud-based IT resources. The administrator usually belongs to the cloud provider, but it can belong also to the cloud consumer

- The **Cloud Carrier** is the party responsible for providing connectivity between users and the cloud provide, for instance an *Internet Service provider* (e.g. ILIAD)

- The **Cloud Auditor** is a third party role that conducts independent assessments of the cloud environment. Its role typically includes evaluating security and performance

- The **Cloud Service User** is the final user of a cloud service

- the service owner and provider are usually different entities, but they can be the same, e.g. the google services run on the google infrastructure 




##### Cloud Model
- the cloud model for the delivery of IT resources is scalable and measured, this mean that:
  - **scalable**: resource can be provisioned (assigned) dynamically on demand, resource must be allocated or instantiated in a short amount of time and with the minimal effort and *minimal need for human intervention*. resources can be provisioned not only as per request of a human, but also under the orchestration of a software 
  - **measured**: the cloud provider adopts a utility-based model, so you pay for what you consume, so the usage of the resource is *metered*, and at the end of the month they bill the user proportionally on what they consumed (for instance in terms of memory, bandwidth, computing power)


### Business model
- In cloud computing **Business model**, cloud computing providers sell IT resources, and other company buy such resources to create services and applications that they can use internally or sell it to their customers


### Cloud Computing Infrastructure
- The **Cloud Computing Infrastructure** is the infrastructure designed to host resources, is deployed in *datacenters* (a dedicated space to house servers and networks equipment)
- Such hardware provides IT resources such as Computing, storage and networking, and those resources can be accessed by multiple cloud consumer at the same time via internet connection

### Multy-tenancy
- In the traditional approach we host a resource in a datacenter, and we need to set up the datacenter, set up the resource and connect the datacenter to access the resource, but the client service owner is limited to access only resources offered by the cloud administrator, and cannot customize the environment at all, and they are aware that they are deploying the resource on a shared device, and you cannot have much *customization*

- In a *multi tenant environment* you can have a much higher customization (e.g. check in at a hotel vs rent an apartment, in the first case you are limited to what you can do, in the second one you can do more thing and personalize more like paint walls, buy a new mattress ecc)

- **Multi-Tenacity** is the property of a system that is provided by the owner, the owner get the *impression* to be the only user in the environment and they can do whatever they want 
- obviously it is only an impression, because in reality the provider sells the same server multiple times, to as many as owner as possible 

### Virtualization
- To obtain the impression of being the only user in the environment we exploit virtualization, virtualization allow to create a virtual representation of something (in this case we are virtualizing the resources or an entire server)
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260304102745.png|300]]

- The most important virtualization technique is hw virtualization, that allow to create a complete virtual representation of a server with all its components
- It resemble so much a real environment that it can run an operating system without any modification 
- Hardware virtualization allows multiple operating system to run on the same hw, they access the virtualized version of a resource

##### Hypervisor
- The virtual hardware is managed and controlled by the **Virtualization layer**
- A core element of such layer is the **Hypervisor**, called also *VM manager*, a sw that recreates the virtualized hw environment in which the guest operating system runs
- The real machine on which the hypervisor runs is called **Host**

- **Full Virtualization** refers to totally virtualize a server with all its component, but there are other two techniques that differ for the level of abstraction they use 
  - **Para virtualization**
  - **Operating system virtualization** (*Container*)

##### Cloud Virtualized Infrastructure
- In a datacenter you have multiple interconnected servers, and each of them run an hypervisor
- VMs can be created dynamically as cloud consumers require new resources to host new cloud services
- Each VM can comunicate with external host (to expose services) or with other VMs (to implement complex services)
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260304103255.png]]


##### Dynamic provisioning
- **Dynamic provisioning** refers to create/destroy VMs (*horizontal scaling*), or increase/decrease the resource of existing VMs (*vertical scaling*)
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260304103535.png|300]]
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260304103540.png|300]]

- *scaling out*: new resource are allocated
- *scaling down*: resources are deallocated 

- Horizontal scaling is the most popular approach, vertical scaling is less common because it takes more time to allocate ad deallocate the resource of an entire VM, but is convenient because it doesn't require technical changes to the application, but you are limited by the total resource available in one single physical server
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260304103651.png]]

- **Metering**: virtualization allows the actual metering of computing resources (measure and monitor the usage of a resource), in traditional computing we have only a basic set of metering function that were not adequate



# 03 Advantages of Cloud Computing
- In this chapter we will se advantages and benefit of cloud computing and new business model create thanks to cloud computing

### Cloud for Business
- CC radically change how IT system are designed and deployed, the reason is that they provides a huge range of advantages, and those set of advantages have changes how business are organized and created new possible strategies

- In the **traditional approach** you need to design and deploy a complete IT infrastructure in-house. This can be performed only with a significant initial investment in terms of hardware and personnel, and you also need to design and maintain all the aspect of the system so you also need a fixed cost for personnel and hardware repairs
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260304103931.png]]
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260304103957.png]]

- another problem is that the system can grow unexpectedly and fast, so you need to scale up your system and spend more money, but it can also shrink, in this case part of the resources are unused and so wasted

### Cloud computing benefits
- If instead of creating your own infrastructure you use cloud computing you have an utility based paradigm, so you can access dynamically to new resources on demand (this can be done automatically with software), and with a metered bill, you have a **dynamic scalability** and **lower initial and maintain cost**

- other than scalability another huge advantage is that we are **eliminating fixed costs** because we don't need an infrastructure anymore, we don't need an initial investment and we don't need any maintenance costs, and at last we don't need specialized personnel to maintain and manage the infrastructure

- We have a **general cost reduction** due to the fact that the cloud providers operates at a larger scale that you would use if you operate alone, so the cost per resource is significantly lower for the provider, because they can buy resource in bulk and obtain a lower cost per unit, and more importantly that cost is shared between different customers at different time
- Also fixed costs are shared and reduced

##### Other indirect advantages
- There are other indirect advantages: 
  - **Minimal management responsibility**: we don't have the responsibility on the security of data, availability of a service, the legal responsibility is now shifted to the provider. The provider also implement redundancy and replication 
  - **Higher quality of services**: the services offered by providers are usually offered with sota hardware and techniques
  - **Reliability**: thanks to the sota technologies and practices their infrastructure is more reliable than the one you would create internally 
  - **Continuous availability**: it is obtained by using sota redundancy mechanism 
  - **Minimal sw management**: the provider manage the license for all the software like the operating system one, so you minimize the cost and complexity of licensing
  - **Location independent**: you can access from everywhere
  - **Companies are focused on their business**: because they don't spend time managing the infrastructure they have more time to work on business logic 


### Cloudification
- **Cloudification**: the process to move application and services from local computing deployment to somewhere in the cloud
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260304105027.png]]

- example of cloudification: 
  - *large enterprises* offload some of their activity to cloud to reduce fixed cost, like Expedia that reduced infrastructure costs and minimized response latency
  - *start up* can implement their ideas without excessive front up costs, like Airbnb that launched their entire infrastructure on AWS that allow them to scale without any problem 
  - companies that need *sporadic high performance computing* (HPC), so they need hpc capabilities only for a short amount of time a year, they can rent it for a short period of time without maintaining their own infrastructure (e.g. Pixar)



### Global scale services
- It is impossible to support a service with billions of users with the traditional approach, because all the requests around the world would be redirected to a single infrastructure and the network will be flooded (it is probable that the bottleneck would be the infrastructures of the Internet Service Provider)

- With cloud it is possible to have multiple server that offers the same services to resolve this, moreover you can cover different areas efficiently, and also offer cloud consumer ad hoc solutions to replicate cloud services on different data centers 

- an example is google search, that handle 15 exabytes of data
- support for billions of user is solved creating a network of distributed datacenter that run the same application, the request of a user is routed to the closest datacenter, in this way the user receive data as fast as possible, and moreover the load of the network is scattered across the datacenters and this allow to avoid bottleneck
- the problem of the huge amount of data is resolved with the paradigm divide et impera 


### Global-scale content distribution
- **Content Distribution** is a specific service that requires to distribute a set of data to a large number of users rapidly and in an efficient manner, the content can be heterogeneous and can have some *maximum latency* constraint.
- Also software update can have constraints on the maximum latency and bandwidth, especially for critical update 

- sometimes the content have to be adjusted to the need of the user (e.g. stream a video in different resolution to a laptop or a phone)
- other time for example with candy crush, you can have multiple devices connected with heterogeneous bandwidth and location 


### Challenges/Risks
 - Cloud computing have several disadvantages compared with the traditional approach:
   - **Network Cost**: you need constant network connectivity to access the service, and this introduces an additional cost for network bandwidth
   - **Network Bandwidth**: you can have limitation on the maximum bandwidth of your connection, if you are dealing with critical and huge amount of data the network might represent a bottleneck
   - **Network availability**: if the user doesn't have connectivity, he can't access the service at all
   - **Limited Portability**: we don't have a *standardization* of computing technology, different cloud computing providers have different technology and solutions that are proprietary and interoperable, so a service developed to run on the infrastructure of a cloud provider can hardly run on a different one. Because there wasn't any strong need for standardization 
   - **Legal Issues**: Cloud computing providers build data centers at location geographical and economical convenient. The storage location of cloud consumer's data might be outside their country region, and since in different country is possible to have different privacy or compliance rules this can create problems

### Data security
- In cloud computing users and enterprises need to store data outside the organizational boundaries, data is *transmitted* over a network (that can be unreliable) and *stored* in the infrastructure of the cloud provider
- the transmission of the data over an unreliable network connection requires security mechanism like encryption, and it is also a risk that your data are stored on a server that is not yours 

![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260304110349.png]]




# 04 Cloud NIST model, service types and deployment models
- Cloud computing *standardization is limited* because the technology is recent
- Cloud provider standardized internally their own solution so it is difficult to make them change their infrastructure

- In the early days there was some standardization effort, it was not focus on technology or API, but on **basic terminology** and **standard definition**, and it was created the NIST (National Institute of Standards and Technology) **Cloud Computing Reference Architecture**, the model provide a *definition of cloud computing* and highlights *all the components* of a cloud system

## NIST Model
- The *NIST model* is a basic set of definitions which provides a common understanding of what cc is it is, what service is provides and it's components

- NIST define:
- **Essential characteristic**: the set of mandatory features that each cloud computing system must have 
- **Service Model**: the set of different service that are provided to consumers
- **Deployment Model**: the set of different models that can be adopted by a provider to design the architecture of their cloud infrastructure
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260306212408.png]]

### Essential characteristics
- NIST introduce 5 essential characteristic that have to be there so that an infrastructure is defined as cc:
  - **Broad Network Access**: the infrastructure must be accessed from anywhere
  - **Rapid Elasticity**: resources are allocated/deallocated rapidly
  - **Measured Service**: the resources are measured and billed proportionally to usage
  - **On-Demand**: resources are allocated upon request
  - **Resource Pooling**: computing resources (processor, memory, storage, and network) are installed and available on a certain cloud infrastructure on demand to satisfy their need. Those pools must be maintained remotely and must be sufficiently large to satisfy the needs of multiple users at the same time. User get the *impression that resources are infinite*, each time that a user ask for more resources it receive it. A cloud provider should never finish its resources. 

- Usually the lifespan of a datacenter is 5/10 years, it takes some times to build a datacenter, usually around 1/2 years so you have to plan in advance its construction 


### Service delivery and Deployment
- The NIST Model define three category of service, based on what kind of service it is offered to consumers and how the service is provided:
  - IasS
  - PaaS
  - SaaS
- Depending on the *delivery model* we have different level of abstraction 


- There are 4 types of **Deployment** that changes the architecture created by the cloud provider:
  - Public cloud
  - Private cloud
  - Community cloud
  - Hybrid cloud


### NIST Reference Architecture
- The reference architecture defines the set of elements that *compose* the cloud ecosystem 
- It focuses on what composes the cloud, and not how it is implemented, and gives also a definition of the involved Actors 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260306213201.png]]

- Based on the model, the actors involved are: Cloud Consumer, Cloud Provider, Cloud Auditor, Cloud Carrier and Cloud Broker

- The **Cloud Broker** is getting popular nowadays, is an intermediate between the cloud consumer and provider, that provide brokering services for cloud resources in order to sell cloud resources for less. He establish a relation with multiple cloud provider, buying resources in bulk at a lower cost and then sell them to customer 
- In this way the users can pay less and he can make a profit 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260306213304.png]]


### Deployment Models
- **Deployment Model** define how a CC infrastructure expose its resources, since they can exposed in several way, usually they are related on how the infrastructure is organized and accessed

### Public clouds
- **Public Cloud**: is the definition of the cloud presented until now, is a scenario where a company create an infrastructure, and make it available to everyone for profit. It is the more popular one, it promotes multi tendency at the highest level, the same physically resources are shared among multiple unrelated consumers 
- It is also called *External Cloud*
- The infrastructure can offers higher quality of people and technology because of the reduced cost
- It has the disadvantage that data are placed off-premises



### Private clouds
- **Private Cloud**: is a CC infrastructure created by a company, which access and management is restricted to only the actor of the same company, it is still created using cloud technology, but access is restricted.
- It can reside in the consumer's private location, you have the maximum control on it
- It is adopted when the user want *fine-grained control*, usually because it has very specific requirements, however non all the company can afford to use this solution because it cost a lot more money 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260306213613.png]]

### Public vs Private
- The main difference between Private and Public, is that in the last multi tenancy is at maximum and cost at minimum, in the first is at tenancy is at minimum and cost at maximum
- Private cloud shares one-to-one relationship with consumer while a public cloud maintains one-to-many relationship. In this case the feature of multi-tenancy does not apply
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260306213821.png]]


### Community clouds
- If you need a Private Cloud, but you don't have the money you can adopt intermediate solution 
- **Community clouds**: cloud infrastructure that are deployed after a community effort, for example you are a small medical company, you need a private network but you don't have enough money to build it on your own, you can join force with other company to create an infrastructure accessible only by the member of the infrastructure 
- Community cloud deployments might reside on-premises or off-premises, like private clouds they can be managed by members of the community or by some external computing vendors
- The advantages is that you have multi tenancy (not very high), it offers the advantage of the public cloud, but you keep control on the infrastructure, cost are shared between the member of the community, the pay per use model can be adopted inside the community



### Hybrid clouds
- **Hybrid Cloud**: are created combining together public and private clouds, you keep non critical data on public cloud, and critical data on a private cloud, for example a health company that handle both medical sensitive data and telemetry non sensitive data. Instead of a Public cloud can use a community cloud
- In this way cost are minimized, you are using the private network only for data you are constrained to, the rest of data is handled in a cheaper way 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260306214122.png]]


### Selecting the model
- **How do you select the model?** usually 99% of the time a public one is fine, but if your company need special feature like data security or extreme low latency and if your organization is big enough then you can use a private cloud, or if you aren't big enough you can use an hybrid or community solution based on your constraints


### Service Delivery models
- **Service delivery models** defines three models to *deliver the service to consumers*:
  - Infrastructure as a Service (IaaS) 
  - Platform as a Service (PaaS)
  - Software as a Service (SaaS)

- They are well established and offered by almost all cloud providers in the market
- they differ with each other on the level of the *abstraction* from the hw to the sw provided to the customer
- this result in a different set of aspect and function that the owner needs to handle in order to create the service
- the higher is the abstraction the less the number of function the consumer need to handle, because a lot or function are already handled by the provider 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260306214524.png]]

### Conventional computing model 
- In the conventional computing model, you need to take care of :
  - Creating a physical infrastructure with servers, storage and network
  - Install and configure the operating systems on the servers
  - Install on each server a middleware/runtimes software to develop applications/services
  - Develop and deploy the service
  - Manage/store the data
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260306214646.png]]
- In the traditional computing service all these aspects are managed by the consumer


### Infrastructure as a Service (IaaS)
- **IaaS** (*Infrastructure as a Service*) is the one with the lowest level of abstraction, it divide in half the responsibility between provider and owner
- it delivers *virtualized resources to consumers*, the owner will use that resources to deploy his services
- is the most popular approach
- it is also called Hardware as a Service (HaaS)
- the line in the stack is drawn in the middle, in the middle there is a layer of virtualization
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260306214701.png]]
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260306214753.png]]
- The consumer no longer need to manage and control the computing infrastructure that is managed by the provider, but he still need to take care of all the component of the platform and applications:
 - installing an operating system on the virtualized hardware
 - configuring the middleware and the run time environment
 - program and deploy the application
 - manage the data

- IaaS remove the costs to build and maintain the physical computing infrastructure, with good control on the environment on which services are deployed 




### Platform as a Service (PaaS)
- **PaaS** (Platform as a Service) has the line drawn a little bit higher, the provider handle the creation of the infrastructure and also the creation of an environment. 
- Owner create application using the environment created by the provider. 
- It gives a run time environment, so a platform
- The owner handle only the programming of the application logic and the management of the data
- it has an higher abstraction level, it decrease the amount of stuff that the owner has to handle 
- *drawbacks*: by programming your application on the environment created by the provider, your application is bounded to that environment, so it can't run on the environment of another provider, you have to adapt the API and the application if you want to change provider, so there is a *lack of flexibility*

![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260306215853.png]]



### Software as a Service (SaaS)
- **SaaS** (Software as a Service) have an *extreme level of abstraction*, here the provider deliver to customer an application ready to use (usually offered via web interface), the application is almost finalize, the provider basically manage all the aspects, the owner can ask for customization and twiks, but not rewrite completely the application 
- in this model the provider manage everything from the hardware to the software development, the owner manage the relationship with the customer and other small things 
- you cannot change anything except the thing that the provider tell you can 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260306215720.png]]

### Cloud/Pizza Delivery
- suppose that you want to eat pizza:
  - you can make pizza at home, in this case you handle anything (traditional approach)
  - you can buy the dough and put toping (IaaS)
  - you can have pizza delivered to your home, you have to prepare the table, and take beverages (PaaS)
  - you can eat at a restaurant (SaaS)
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260306215638.png]]


### Model Examples
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260306215613.png]]

### PaaS/SaaS Implementation
- PaaS and SaaS can be **implemented on top** of an IaaS infrastructure
- An IaaS infrastructure can be used to create a PaaS infrastructure: VMs are created a software platform is installed on them
- A PaaS infrastructure can be used to create a SaaS system: a PaaS platform is used to create a software that is provided as SaaS.
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260306215541.png]]

### Other Cloud Services
- There are other delivery model in the market:
  - **Storage as a service**: is a service that is used to store a large amount of data, the storage is efficient, you can also make retrieve and lookup. Is a subcategory of IaaS
  - **Database as a Service** (DBaaS): you can access a remote database. Is a subcategory of PaaS
  - **Backup as a Service** (BaaS): backup your data on the cloud 
  - **Desktop as a Service**: you can access a remote computer with more computational power and a personalized desktop environment 
  - **Function as a service**: is provided by many provider, popular in the IOT, the idea is to allow owner and customer to implement their business application logic in *form of a collection of function*, each function is assigned to an *event*, assume that you want to create a smart alarm system for your alarm, there are several event that can happen, you then organize the logic as a set of function, when an event is reported the corresponding function is executed in a fast and lightweight manner


# 05 Virtualization
- **Virtualization** refers to the representation of physical computing resources in simulated form through an additional software layer 

- The main idea is that you have a physical component and you create a virtual representation out of a physical one via software
- This software is usually referred as the **virtualization layer**, it is installed on top of a physical machine, and it creates those virtual representations 
- In cloud computing those resources are used to satisfy the users needs, and the user use those resources as they were real 
- Virtualization completely *decouple* the physical computing resources form direct access of users, so it is not possible to access directly the physical resources
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260311132152.png|300]]


- Any kind of resource can be virtualized, usually we have a distinction (two type of resources):
  - **Basic computing resources**: those resource are mandatory in a computing system, e.g. cpu, ram, hd, 
  - **Optional computing resources**: they are not mandatory in a computing system, e.g. keyboard, printer, network adapter

- *Basic computing devices* can be virtualized only when a physical resource empowers the virtual representation, so you need to have a real one to simulate a virtual one, e.g. i need a real cpu to simulate a virtual cpu
- for the *other resources* instead you have two option, you can power them using a real component (e.g. a real keyboard that share input with the virtual one), or simulate them totally virtually

- Even in case of basic resources, the virtual representation can be very different from the real one that is empowering it, e.g. i can create from a real cpu with 64 bit to create a virtual cpu with 32 bits, or i can create from a cpu, n different cpu with less core

##### Machine/Server Virtualization
- **Machine/server virtualization** is the process to create a virtual machine (or server) on top of a physical machine
- it look like a true physical machine, it is the union of different virtualization technique 
- the physical machine is called the *host system*, the virtualized machine is called *guest system*

- With virtualization you have one host system, that handle multiple guest on top of it 
- one main advantage is that all vm executed in the same system are strictly *independent*, one vm cannot access memory, storage or registry of another vm
- the only boundary that you don't have is from the host system and the vm itself, the host can look inside to what is happened inside the vm (but there are techniques that hide the content for privacy reason)
- every vm can have its own os, the os that run inside a vm is called guest os
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260311132620.png]]


##### Hypervisor
- The **Virtualization layer** is a set of programs that creates the environment for the virtual machines to run on 
- This layer provides the access to system resources (CPU, RAM, Disk, etc) to the virtual machines and controls and monitors the execution of the virtual machines over it

- This software is usually referred as **Hypervisor** or **virtual machine monitor** (**vmm**)

- Virtualization techniques can be divided into 3 main category:
  - *Full virtualization*
  - *Para virtualization*
  - *Hardware assisted virtualization*

- there are also other techniques like operating system virtualization

##### Hypervisor types
- There are two different techniques of server virtualization:
  - **Hosted Approach** (*type 2*): the hypervisor is not capable to running the physical system by itself, so you need to install on top of the physical machine an host operating system, and on top of that you run the hypervisor (e.g. virtual box)
  - **Bare Metal Approach** (*type 1*): the hypervisor is not just a software, it also have the functionality of a os to manage the hw, it is placed directly on the physical hardware without an os in the middle and offers a lot more functionality, it can create by himself the vm (e.g. VMWare ESX, Microsoft Hyper-V) 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260311133156.png|200]]
- they differ on how the hypervisor is implemented and if it is able to manage alone the system with its hardware
- the bare metal approach is the one used by cloud provider

- Pro and Cons of the two approaches:
  - In the *hosted approach* we loose resources, because we are not really using the os, it is there just to manage the hw, so we have an overhead, but it support a wide range of hardware and you have less problem of hardware compatibility 
  - The *bare metal approach* have less overhead, but the hypervisors are more complex to implement, and can have a limited hardware compatibility 


##### Full Virtualization
- In **Full virtualization** (or *native virtualization*) the hypervisor simulate the underlining hardware completely, their representation is so real that the guest os is unaware that they have been virtualized, and it can support execution of os unchanged 
- It is responsibility of the hypervisor all the translations required to make believe to the os to be running in a real machine
- The guest os runs isolated from the host system and the other guest systems that are running concurrently 


##### Para virtualization
- Para virtualization was an evolution of full virtualization that overcome its main drawback
- In full virtualization to emulate a complete system (emulate all peripheral as they were real) require a huge overhead (additional instruction and data structure), but has a lot of advantages

- **Para virtualization** was developed to reduce this overhead, to do this they removed the main assumptions of the full virtualization, that the os  *cannot change* and its *unawareness*

- All the virtualization activities are managed by the hypervisor, e.g. instruction emulation, establishing communication with the underlying hardware
- But a portion of the tasks are transferred from the hypervisor to the guest os

- To do so we need to modify the os
- Basically we are creating a symbiosis to comunicate and exchange data and additional functionality with the os, to speed up execution, the main drawbacks is that vm only support os that are modified, the os require a special modification called **porting**, usually to the kernel of the os, that makes the os aware to be inside a vm, and it also know in which virtualization environment it is being executed

- The use of modified OS reduces the virtualization overhead, and the virtualization layer can exploit the drivers of the guest os
- its main limitation is that it does not support *unmodified operating system*, and there are *less security* because the guest os is not fully separated from the host


##### Hardware assisted virtualization
- **Hardware assisted** virtualization is an evolution of the full virtualization introduced to reduce the overhead problem
- it is done by *modify the hardware* (processor) to perform some operation of full virtualization via hardware instead of via software, those operation don't need to be translated and so they are faster to run
- this kind of virtualization is only possible when specific combinations of hardware components are used
- when a cpu does not support hw assisted is used the full


##### Operating system level virtualization
 - In **Operating system level virtualization** (*system level virtualization*) we don't use an hypervisor, all it's managed by the os itself, is a totally different virtualization approach whose objective is to have zero additional overhead, all it's implemented in the kernel of the os
 - It create *virtual environments* and not virtual machines
 - e.g. linux container or docker 

- The kernel of the operating system in the physical system is shared among all the virtual servers running over it
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260311135153.png]]


- Its *advantages* is that this is the most lightweight approach with minimal or zero overhead, so you can maximize the number of environment without wasting resource
- Its *limitation* is that you dont have real vm, and all the virtual environment share the same os, and there are some security issues 
##### Other type of virtualization
- There are other types of virtualization, usually referred to singolar components
  - **Network virtualization**: is the process of combining network resources and network functionalities into a single, (usually software-based) administrative entity called as a virtual network. It allows to create a virtual network for VMs to communicate. The virtual network usually exploits the real network infrastructure for data transmission
  - **Storage virtualization**: is virtualizing a storage, you have a storage pool, and that pool is reconfigured such that you create a virtual storage on top of the physical one 

##### Emulation
- **Emulation** is the act of creating a system that imitates another one
- Virtualization instead assumes that the *instruction set* of the system that we are virtualizing is the same, the architecture and instruction set are the same as the physical one, we are only creating a virtual representation of them, but their structure is the same 
- An emulator is a system that emulates completely one system on top on another one *without any assumption* that connect those two, so you can have different instruction set 

- There are two ways for implementation of emulations:
  - In **binary translation** (also known as recompilation), a total conversion of the binary data (made for the emulated platform) is done. The conversion recompiles the whole instruction into another binary form suitable to run on the actual or targeted platform
  - In **interpretation**, each instruction is interpreted by the emulator every time it is being encountered. This method is easier to implement but slower than binary translation process

##### Emulation vs Virtualization
- Emulation emulate all the components of a target system, the basic one, the optional one and the instruction set
- Virtualization is a particular type of emulation that assumes that the instruction set used by the virtual system is the same as the one used by the real one, except in some exception you don't need any translation of the instruction set, and this *speed up* the process a lot

- virtualization in some case still require emulation, when the code in your vm would like to run some action, it cannot do directly, so the hypervisor emulate them

##### Virtualization Advantages
- Virtualization **advantages** are:
  - *Server consolidation*: is the action to executing more VM on the same hw, this allow to achieve a better utilization of the system resources, this lead to *lower costs*
  - *Simplifying the system administration*, by creating the two environment, the real one and the virtualized one 
  - *Simplifies system installation* as the new system can be created cloning another one instead of reconfigure it totally from zero
  - Improve the management of *fault tolerance*, because the code that is running on a virtual machine can run in any other vm, if you need to shut a server down you can just run the vm on another server
  - It *improves security* because each vm is isolated from the others thanks to the additional isolation provided by the virtualization layer


##### Virtualization Downsides
- Virtualization **downside**:
  - Every physical machine is a *single point of failure* for many vm
  - Virtualization results in *lower performance*, a virtualized environment can achieve up to 85/90% of the performance of the real system, but this overhead is reducing with the evolution of the technology


# 06 Virtualization Technologies (non-hw assisted)
(in this chapter we are talking about full virtualization, so technology that do not exploit hw to accelerate virtualization)

### Virtualization Requirements
- There are three important requirements that virtualization must satisfy:
    - **Equivalence**: an OS running in a VM should exhibit a behavior equivalent to the behavior on a real equivalent machine
    - **Resource Control**: the hypervisor must be in complete control of the physical resources, the guest os must have complete control on the virtualized resources
    - **Efficiency**: the majority of the virtual machine instruction must be executed without hypervisor intervention to ensure efficiency


### Multiprogramming
- The requirement of virtualization are similar to the one of multiprogramming 

- A **Multi programming environment** is an approach implemented by modern os that e emulate machine with more processors than we have in the real hardware
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260311140750.png|300]]

- We do this by assign to each processor its own **virtual processor** (**VCPU**), and each virtual processor is reserved for the execution of a process

- Virtual processors are multiplexed over time on the host machine physical processor for the execution of the specific program 
- The result is that every application have the impression to have complete control on the processor when it runs and to be the only program executed on it 


### VCPU Execution
- The OS implements multiprogramming by creating a *virtual representation* of the processor that contains a copy of the state of the processor (its registers)
- A machine with one physical processor emulates only one virtual processor at a time, this is obtained by *loading* the registers of the host processor with the values stored in the virtual processor representation (a data structure) and then by letting the host processor *continuing the execution*
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260311141227.png|200]]

- After some time the execution may be *paused* to run another application, to do so it *updates* the vcpu data structure then it will *restore* the status when the execution will rerun again 
- by executing different VCPUs frequently we give processes that they are executed continuously


### Context Switch
- The operation of switch from one processor to another is called **context switch**, it include saving the status of the current operation in ram and upload the new status from the ram into the vcpu data structure
- it is determined by a timer of an interrupt

- those operation are mainly performed in hardware

### Multiprogramming support
- The multiprogramming require some hardware support:
  - an **interrupt**, for instance a periodic timer
  - automated mechanisms to **copy** the state of the registries 
  - a **protection** mechanism that prevents unauthorized processes to run certain instruction and access certain portion of ram 


- The *Protection Mechanism* can be implemented exploiting the different **privilege levels** implemented by modern processors, usually there are two types of execution level:
  - **System level**: it is the higher privilege, can run any type of instruction, even kernel code 
  - **User level**: is the code assigned for the execution of application, it can run only a restricted subset of instruction
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260311141613.png|300]]
- application are executed at user level, kernel at system level
- if you try to execute kernel instruction at user level it triggers a *protection mechanism*

- The CPU can operate in **user mode** or **kernel mode** 
- ring 3 are user mode, ring zero is kernel mode, in the middle there are drivers and stuff like that that have a bit more privilege, but always protected


### Multiprogramming support
- The **Protection support** includes:
  - A *sys registry*, that contain a flag that specifies if the CPU is currently in system or user mode
  - A *sys-mem registry* that contains the starting address of the privileged memory where VCPUs data structure are stored
  - A *ret register* that stores a memory address to be used when returning to user mode from kernel mode

- When the timer for the context switch is triggered, the OS performs the following operations:
  - Save the state of the host CPU on the VCPU representation
  - Select a new VCPU to run and loads its state into the registers of the host CPU
  - Executes a special instruction to jump to the address stored in ret and return to user mode



### Virtual Memory
- With memory management we want multiple application, and each application have to have the impression of having the full control on the memory available on the system 
- We do that implementing a virtual memory mechanism, the real memory is managed by the kernel of the OS, VMs access to its virtual memory space, and thinks that all memory its reserved to him, addresses are continuous and start from zero 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260314133249.png|300]]

### Memory Management Unit (MMU)
- Virtual memory is implemented through two mechanism:
   - translate the virtual address in real physical memory address
   - managing address spaces

- All virtual address spaces are mapped on the physical memory
- We translate the virtual address into a physical address in the CPU with an hardware component called **Memory Management Unit** (*MMU*), and those translation are managed by the kernel of the host os
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260314133736.png|300]]


### Page Table
- The **Page Table** is a data structure, managed by the OS, that contains the translation from the the virtual to the physical space, it is used by the MMU for its translation
- The CPU has a registry called PTBR (page table base registry) that points to the physical address of the first byte of the page table
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260314134148.png]]

- It is stored in RAM, and is organized into a multi-level structure, multiple directories must be accessed to translate the virtual address into a physical address
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260314134259.png]]

### Segmentation
- The sum of all the virtual memory can be greater than the real memory, if not all application use all memory you don't have any problem, if they do you can have problem, but you can extend the primary memory using secondary storage, to do so we move not frequently used data structure into secondary storage, we want to perform this less frequent as possible because obviously secondary storage is slower
- when we want to access page stored in secondary storage we trigger a **page fault event**, when a page fault is performed we move the page back to ram and after that we can resume the execution of the application 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260314134434.png]]

### Interrupt/Exceptions
- Interrupt and Exceptions are two mechanism included in the processor that allow to temporary halt the execution of a process and perform an urgent operation 
- They are both the result of an exceptional event which require immediate attention from the cpu and intervention from the operating system 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260314134623.png|300]]

 
- **Exceptions** (or **trap**) are *internal* and *synchronous*, they are used to handle internal program errors (usually triggered by the last executed command)
- **Interrupt** are *external* and *asynchronous*, they can be invoked via software with the *int* command, but they are usually caused by some hardware components that require attention from the CPU
- Interrupt are used to notify the CPU of external event, that are usually generated by hardware devices outside the CPU at arbitrary times (e.g. a key pressed in the keyboard)
- they both trigger the execution of a dedicated function called *handler* in the kernel space

- When we have an interrupt or an exception the system stops the execution of the program, move from user to kernel mode, then it perform a context switch by pausing the execution of the application and triggering the handler linked to the action that triggered the interrupt or exception, we move the data required by the handler in ram, and when is finished we have another context switch, we return to user mode and continue the execution the application 


### Interrupt descriptor table (IDT)
- The **Interrupt descriptor table** (*IDT*), also named Interrupt vector (IV), is a table used by the processor to link interruptions and exceptions with their handlers, each handler is a function in the kernel that performs operations to handle the interrupt or exception 
- The table have a fixed length, the os fill the second part, for each id it fill 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260314135615.png|300]]

## Virtualization Technologies
(This part of the chapter will speak about Full Virtualization)

### Virtualization – Full Virtualization
- Multiprogramming already include several virtualization mechanism, like memory and processor management (VCPU and Virtual memory space)
- We need to have an entire os with its kernel that have the impression to run on a dedicated hardware 
- We want to achieve a system where kernel is the hypervisor and programs are virtual machine
- A VM is a multiprogrammed system itself that host not only a program, but an entire OS

### Hypervisor
- We want to reuse in our hypervisor as much as possible the tools of multiprogramming that are already available and implemented in hw (so really fast)
- if the guest and host architecture are the same we also want to minimize the use of emulation that introduce overhead, we want to execute the code of the VM directly on the hw without the hypervisor intervention



- **How to implement full virtualization in a multiprogramming environment without hardware support?**

### Virtualizing CPU
- The VMM adopt he same technique adopted for creating VCPUs in a multiprogramming environment
- The VMM loads the state of a VCPU into the host processor, then it lets the host CPU to run the target code as it is, until the CPU finds an instruction that cannot be executed directly
- As the context switch occurs the VMM regains control and emulate the target instruction that couldn’t be executed by the guest OS in software and then re-load the virtual CPU into the host CPU to continue the execution

- when there is an illegal instruction we do not kill the vm, we look what is the privilege instruction that trigger the exception and we emulate the execution of that instruction (we mimic the result of the instruction) 


### Guest OS Execution
- The guest os need to create its own multiprogramming environment, it also need to access all registry of the cpu, even protected one, so we need to emulate this behavior too 
- each time you have a privilege instruction you need to emulate the result that you would have if you would have executed that instruction 


### Trap and Emulate Virtualization Model
- There are **4 Level of Privilege**, from Ring 0 to Ring 3, the lower the ring, the higher are the permit 
- In full virtualization we have ring zero reserved to the hypervisor, the other three rings are reserved to the vm, inside the vm you have another multiprogramming environment, the kernel of the vm will run on ring one, the application at ring 2 and 3
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260314145408.png|300]]

- exception are thrown when the vm try to run something it cannot do (at ring 0), this exception allow the hypervisor to regain control, then it emulates the instruction that the vm was trying to perform, for instance instruction related to page table or i/o, and after emulate its result, the control is returned to the VMM
- This code that cannot be executed directly by the VMM is also called **Trap Code**, and we want to minimize this kind of code to reduce the overhead
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260314145616.png|300]]





 - There are instructions that are *difficult to emulate*, for instance if we use the instruction *INT* in the application of the guest os to trigger a system call:
   - (1) This kind of instruction cannot be executed by the VM, because it require the ring zero, so we need to perform a *context switch*
   - (2) The INT operation in the host can use a different handler from the guest, so we need to obtain the handler of the guest
   - Then we need to emulate this handler, this handler will have a lot of privileged instruction, and each of them will trigger a context switch that require to (3) emulate the instruction, and then after each emulated instruction we perform a context switch to emulate the next instruction into the handler (4)
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260314150352.png|300]]

- In the processor you have a registry that point to the first entry of the **IDT**, in a virtualized environment **each vm have its own IDT**, but only one is selected to be configured in the registry of the processor, but only the one in the hypervisor is pointed by the CPU, the one of the guest are floating, they are **not directly connected** to the hardware, because there would be the risk of loosing the control of the system 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260314150456.png]]


### Virtualizing Physical Memory
- **How do we virtualize ram?**
- A part of the memory will be reserved to the VMM
- Each VM will have a subset of the host physical memory, the guest VM must have access only to the portion assigned to it and it must think that its memory starts from the physical address 0
- To map a portion of the physical memory to the host physical memory, we use the MMU unit of the host CPU, that keeps track of the address range in the physical memory assigned to each VM
- if a *pagefault* occurs the VMM move the page to the memory 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260314150701.png|300]]
- guest virtual address
- guest physical address: what the vm thinks is the real physical address 
- host virtual address
- host virtual address

- we can translate directly from **guest physical address** to **host physical address** with the hypervisor, so you need only two translation and not three 

### Virtual MMU
- The guest OS should have a page table to translate the virtual address in its physical address (what he think is the physical address)
- Having a guest virtual address $V$, we map it to the guest physical address $F$ with the function $G$
- Then we map the guest physical address $F$, with the host physical address $F'$ with the function $H$ 

- The **Virtual MMU** translate guest virtual addresses into host physical addresses by implementing the $G \cdot H$ **mapping**     

![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260314151322.png|300]]

### Brute Force Method
- How can we implement those two function without hw support? we can use the **Brute Force Method**, the page table is modified in order to add an additional level (the **shadow page tables**) that implements the H function (that translate from the guest physical address to the host physical address). The first level implement instead the g function
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260314152153.png|300]]


### Shadow tables
- Shadow Tables are *written protected*, so if the VM try to write on them there is a context switch, this allow to protect them but it adds a significant overhead 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260314154221.png|300]]

- In order to update the shadow and introduce new ones, the hypervisor need to trap all the actions related with the MMU and the page table: 
  - a change in the PTBR (e.g. if the VM want to replace the table completely)
  - a change in the page table entries in some directory (e.g. because the guest VM wants to change the mapping of some areas)

- Every time a change in the page table occurs a trap is executed, the VMM takes control and update (or add) a shadow table


### Virtualizing I/O Devices
- I/O instructions are usually privileged instruction and they cannot be executed in userspace
- In multiprogramming we access to the I/O space with an abstraction implemented by the kernel called *system calls*, but the VM have to have the illusion to be in control of the hardware and that he can access the hardware directly, to do so we must **emulate the real hw** creating a virtual representation that is implemented as a set of data structure in memory
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260314155018.png|300]]
- The virtual representation is updated by the VMM each time a read/write is executed, the VMM translate also command given to the virtualized peripherals to instruction for the real devices


### Interrupt Management
- The VMM must take care of the interrupts coming from the physical devices
- VMM must keep a host interrupt description table (inaccessible to the guest) that the host CPU will use to handle interrupts

- in order to avoid active waits interrupt are introduced, so we can do something else while we wait for the signal of the input from the peripheral 
- the hypervisor needs to give the illusion to the guest os that he is in total control of the peripheral, to do so we emulate completely the peripheral
- Each guest VM have its own interrupt descriptor table managed by the guest OS
- The VMM must takes care of the interrupts that are generated from the virtual devices emulated by VMM for the guest OSs
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260314155322.png|300]]


### Virtualizing Interrupts
- When the VMM want to emulate the reception of an interrupt in a VM (e.g. emulate an input from a virtual device) it must look up the guest interrupt descriptor table, and perform the operations required to execute the interrupt code in the guest OS:
  - save the current state
  - change the instruction pointer, to the value of the first instruction in the interrupt code
  - give back control to the guest VM, so the interrupt code is executed
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260314155408.png|300]]



### Hardware Interrupt
- The VMM is the only one accessing the real hardware, so it is he only one that handle interrupts from devices
- An hw interrupt trigger the execution of the interrupt at the VMM even if a VM is running
- Then the VMM handler can execute the handler inside a guest os emulating it via sw
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260314155339.png|300]]


### QEMU
- **QEMU** (*Quick EMUlator*) is an open source emulator that performs hardware virtualization
- Is a VMM software that emulates the machine hardware, it support a wide set of hardware emulations, it can run a guest OS with an instruction set different from the one of the host through binary translation
- If instead it run a VM with the same IS, it has an acceleration to speed up emulation in order some of the code of the guest as user mode code



# 07 Virtualization Technologies (Hardware assisted virtualization)

##### NON-hw assisted virtualization
- Full virtualization *without* hw support result in a huge overhead, the main reason is that the guest os run in *user space*, and all the privileged operation cannot be executed autonomously by the vm, for this reason you need a context switch for each instruction to emulate privileged instructions, interrupts, or i/o operations, and in some case this operation require even a series of context switches 
- In the past this was ok to have it given all the advantages of full virtualization

- In order to solve the overhead problem, in 2006 CPU producers (intel and amd) started to introduce hardware support to reduce the need for context switches, to do so we need a hw that allow the vm to execute some privileged instruction autonomously. 
- Those set of instructions can be customize, so you can decide when and which operations are safe to delegate to to the vm, and which not
- The system created by intel are called (**Virtual Machine eXtention**) **VMX** 


##### Root and non-root modes
- **VMX** was the first hw support to virtualization, it introduce two new **operating modes**:
  - *root*
  - *non root*

- Those two modes are orthogonal in respect to the existing system and user modes, and this allow to create 4 combination of privilege:
	 - *root/system*
	 - *root/user*
	 - *non-root/system* 
	 - *non-root/user*

- The root mode is intended for the VMM running on the host, the non-root mode is intended for the guest software running in the VM
- in root/user and root/system i execute code directly on bare metal, in root/system i run the os and root/user application on the host os
- non-root level are introduced to allow fine grained control on what the vm can and cannot do


- Another hw support introduced are *new assembly instruction* that can automate the copy in the ram of the vm, or the resume of a vm (**VMLAUNCH**, **VMRESUME**) and can be used only in root/system mode
- **VM Exit** are the reason for which the VM returns to the root mode and switch back to the VMM execution, in then goes back to execute the VM for reasons called **VM Entry**
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260318170535.png]]

- The introduction of those two new modes already result into some improvement, because we are reducing the need for emulation, because we can execute directly some privileged instruction and handle directly some interrupt in the vm without the vmm intervention 

##### Interrupt management
- We want to achieve a system where a subset of interrupts can be delegated directly to the vm
- We do that in hw, by introducing an additional table called **Interrupt Remapping Table** (**IRT**), a data structure in between the *Interrupt descriptor table* (*IDT*) and the *processors*, that can be used to remap the mapping of the interrupt allowing to do a mix of entry belonging to different descriptor table 
- The IRT is in between and link the IDT of the host with the IDT of the guests, and link single functions, it has an entry for each possible interrupt request. Each entry maps the requests to the interrupt vector of a VM or to the interrupt vector of the VMM
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260318171158.png]]
- An example a system call, before this mechanism the INT ad IRET require complete emulation, context switch, fake the system call and give back the control to the guest, but with hw support the execution of those two can be delegated to the vm thanks to non-root level, in addition to this the IRT is used to map the the function 

- Graphical representation of the advantages, in the left it is shown the procedure without hardware support, on the right with hardware support:
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260318171438.png]]
- The root user mode is something reserved to execute application directly on top of an hypervisor, if the hypervisor is an application in a os, it is partly executed in root system, part in root user. if the hv run directly on bare metal and they are the os, then the root user is used for third party software that you want to confine, secondary services that you don't want to run at the highest privilege level, so it allow to sandbox services to enhance security



##### Virtual Machine Control Structure 

- another hw support is a data structure called **Virtual Machine Control Structure** (**VMCS**), that contains all *information associated with a single vm*, we will have an instance of VMCS for each instantiated vm
- we also have also a set of in-hardware instruction to manipulate this data structure efficiently 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260318171941.png]]


### VMCS States
- VMCS have *several fields* that can be grouped in 6 area:
  - **Guest State**: it store the state of the Virtual CPU (VCPU) associated with the VM, the state is loaded during VM launch, and saved during its exit
  - **Host State**: store the state of the physical processor before launching the VM, it can contain the state of the VMM before a VM launch. The state is saved during a VM launch and loaded during a VM exit (this information is stored only in the data structure of the vm that is currently running)
  - **VM execution control**: specifies which instructions are allowed, and which not during non-root mode. Unallowed actions cause a VM exit. It also contain flags exploited in *peripheral passthrough*
  - **VM enter control**: it contains flags and fields that determine some optional behavior that can be activate during *root to non-root* transition 
  - **VM exit control**: it contains flags and fields that determine some optional behavior that can be activate during *non-root to root* transition 
  - **VM exit reason**: it contains information related to the reason that caused the latest VM exit event


- Every time we have a context switch we need to save the status of the processor of the vm, and restore the state of the hypervisor (and viceversa), we cannot have a context switch from one vm to the other (for example stop the execution of a vm and start the execution of another one), we need to have a context switch from a vm to the hv, and then a second one from the hv to the second vm 

- VM execution control mainly contain a set of flags that are used by the hypervisor to specify how interrupt and io management should be executed and what is the set of privilege instruction that should require a context switch or not 
- Another flag specify which critical instruction should cause a vm exit or not


### RAM MANAGEMENT
- The goal is to make believe that each VM have all the memory for them (is the same as the non hw-assisted case) and that memory start from zero
- We have the Guest physical and virtual space and the Host physical and virtual space 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260318174443.png]]


### Extended Page Tables
- The hypervisor goal is to manage the physical memory, and map the guest physical memory to a portion of the physical host memory
- We do that thanks to the **Extended Page Table** implemented in hw
 

- The idea is the same as the non hw supported one, you have the function g that map to guest virtual addresses into guest physical addresses and h that map to guest physical addresses to host physical addresses  
- It was introduced an  **extended management unit** (**MMU**)  that manage the composition of $G$ and $H$ that are applied sequentially
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260318180418.png|500]]

- Thanks to the MMU extension, there is no longer any need for VM exits every time the VM modifies the page table, but translation require more accesses
- Recent version of the MMU also have a cache to reduce accesses


### Hw passthrough
- I/O emulation remain the biggest performance challenge in virtual machine 
- vm is not able of access real hw, he can only access virtual hardware, the vmm has to partecipate in every interaction between the VM and the I/O peripherals (often emulated), and this results in several VM exits

- You can break this rule for one peripheral if you really need performance and give to the vm full control of the hw, for example take control of the gpu to perform heavy computation 
- **Hardware passthrough** can allow to do this, it maps the devices directly to the guest VM without performing any translation

- The drawback is that the hardware is not virtualized, the vm is the only one capable to accessing that hardware, so you can access a piece of hw to only one of the VM, the other vm nor the hv cannot access that resources 
- This passthrough makes a huge boost in performance, but in order to implement this approach we need explicit hardware support


##### Passed-through device
- In order to implement a **passed-through device** we need two main functionalities: 
  - *Direct mapping* of the I/O physical memory space, in the virtual physical memory of the VM, so the guest OS can write directly on the registries of the peripheral
  - *Direct assignment of the interrupts* linked with the peripheral, so the VM can handle interrupts coming from the passed-through device, white the VMM handles the others 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260318181323.png]]


##### I/O Mapping
- We want to perform I/O operation from the VM without the VMM intervention for passed-through peripherals, we want to intercept the operation and give the control back to the VMM for others


- Intel VMX architecture includes in the VMCS an **I/O bitmap**, with one bit for each possible I/O address to specifically support hardware passthrough
- When a device passthrough is set for a VM, the I/O bitmap is modified in order to set all the bits corresponding to the addresses of the I/O space of the device, to grant direct access
- In non-root mode, the CPU first checks the bitmap when a read/write is performed in the I/O space: if the bit is set the instruction is completed, otherwise a VM exit is triggered to give back control to the VMM 


##### Interrupts
- Intel VMX extensions allow two options for the management of interrupts:
  1. the interrupt causes a VM exit, so the interrupt is managed by VMM
  2. the interrupt is managed directly by the VM without a VM exit

- For instance in case of passed-through devices we use the second option, in this case the hw look at the **Interruption Vector Table** (**IVT**) of the guest os and execute the corresponding handler

- The VM, might receive an interrupt while not running, to this aim the system needs to handle the interrupts coming from the passed-through device also in this case



### VM States

- vm can be in three states:
   - **Running**: its currently being executed by one of the physical processor
   - **Ready**: it is not running, but is ready to run and to be selected by the hv
   - **Halted**: the vm is available in the system, but is not ready to run, for instance when it is power off
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260318181657.png|300]]

- The vm goes to running to halted state with the *hlt* command, when it is halted it can go back to ready state for two reason, it is being powered on, or in case the vm has a pt device, an interrupt from him has been triggered, for example it is possible to turn on a vm when a event like "connect to internet" happen

##### Interrupts management
- How do we manage interrupt to support this three states?
  - If the vm is *running* and an interrupt is received we can handle him directly without vmm intervention 
  - if the vm is *ready* and an interrupt is received, we store the interrupt request somewhere and it will be managed when the cpu will move from ready to running  
  - if the vm is *halted* and an interrupt is received then we store the interrupt and change the vm to the ready state 
- The **posted interrupt mechanism** is able to store interrupt and manage them later
- it is implemented thanks to an additional data structure called **Posted Interrupt Descriptor** (**PID**), a buffer that store the interrupt 

##### Posted Interrupts
- The posted interrupts mechanism allows to store interrupts signals (post) for later notification to the VM, without VMM intervention
- It also exploit the **Posted Interrupt Descriptor** (**PID**) of each VM
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260318182906.png|300 ]]

- PID are used in the IRT, each entry in the IRT can point to an entry to an interrupt vector or to a PID, which points to the actual interrupt vector if the VM is active
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260318183120.png|200]]


##### Posted Interrupt Descriptor
- The PID contains info on the vm status, how to store the interrupt and how to notify the vm, it usually have:
  - The **Posted Interrupt Request** (**PIR**) in which we store interrupts temporarily 
  - A **Suppress Notification** (**SN**) that is a flag that tell if an interrupt can be notified to the CPU immediately or not, if it is zero request are not suppressed, if it is set (=1) then the posted mechanism is functioning, probably because the vm is ready or halted
  - A **Notification Vector** (**NV**) that point to the interruption vector to notify the VCPU of the VM 


##### Interrupt delivery (da rivedere)
- How we deliver the interrupt to the VM? 
- An interrupt is receive, the cpu look to the IRM, if that interrupt is associated to a pass-through device then we set the PIR data structure, then if the suppress notification is set nothing else is performed, otherwise if the vm is running the interrupt is forwarded, if instead the vm is halted, it triggers the awakening of the VM 


##### PID update
- What happen every time the vm change its state?
- First the vm change its **PID status**, it set the value of SN based on its new state, 
  - if its new state is running, set SN=0 we also update the value of NV to a vector named *Active Notification Vector* (*ANV*) that points to the IDT of the VM
  - If its new state is ready, set SN=1
  - if its new state is halted, set SN=0, and update the NV to point to a special vector named *Wake up notification vector* that trigger the vm awakening 

- every time the vmm change the state to run, it means to inject all waiting interrupt, to do so it looks to the PIR



##### DMA devices
- **DMA devices** are I/O devices that reads data directly from RAM
- **DMA** allow data transfer that allow to read and write directly from ram, you specify the beginning and the end of the portion of ram that you want to read
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260318183744.png|300]]


- **IOMMU** is a MMU circuit used to translate virtual addresses into physical addresses for the IO devices to read or write from RAM
- it is also capable to trigger page faults interrupts if it found pages not stored in RAM
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260318184237.png|300]]


### Nested Virtualization
- What if i want to run a vm inside a vm?
- this is used quite often, and is called **nested virtualization**, is a system where you have a physical server, a level 1 hv (host hv) running on the hw, with that you create a vm, and inside the VM you can install a level 2 hv (guest hv) that will create VMs on its own, and this nested virtualization can go on 
- a use case is to install a platform inside a vm that is able to create vm
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260318185158.png|400]]


- The hw of the level 1 vm is an hw without hw support, so in the level 2 vm, we are constrained to use full virtualization without hw support
- If the hv at level 1 and level 2 are the same, they can understand to be in a nested system and can start talking and help each other, in this way the level 2 hv can delegate the management of the vm of the level 2 to the level 1 hv, they will be managed by the level 2 but executed by level 1 (This require a specific hardware support, and usually support only a *single virtualization level*)
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260318185415.png|300]]

### KVM
- **Kernel-based Virtual Machine** (**KVM**) is a virtualization infrastructure of the Linux Kernel 
- It allow to exploit hardware virtualization support to run VMs inside an execution environment nearly identical to the physical hardware 
- It does not run as a normal program inside linux, it relies on the Linux kernel infrastructure to run
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260318185638.png|300]]


# 08 Virtualization (Paravirtualization)
(here we present an alternative to full virtualization with hw support called Paravirtualization)

### Paravirtualization
- Having the guest OS **unchanged** lead to a huge number of context switch (without hw support), because some instruction cannot be directly executed and need to be emulated by the VMM 
- **Paravirtualization**: we modify the guest OS to speed things up, those modification are usually limited to the kernel and application are unaware of that


![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260318191414.png|300]]
- Those modification are **expose API** (we broke the *isolation assumption* and *unchanged assumption*), exposed by the VMM through an interface named Virtualization Layer
- The hypervisor is now visible inside the vm, and we don't need unnecessary context switch  

### Paravirtualization – Implementation
- those exposed API are called **Hypercalls**, they trigger the execution of some code in the hypervisor2 and executed them in *system mode* (so in privilege mode) 
- we are moving some functionalities of the kernel of the guest os from ring 1 to ring zero 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260318191722.png|300]]

- The *pros* are that this approach improve the performance and it does not require hw support
- The *cons* are that it only support modified os, and those modification can be performed only to open source os, closed source os require assistance from the publisher of that os, and those are critical drawbacks 

- Paravirtualization loose most of its popularity with the advent of hardware support 

### Xen
- **Xen** is a paravirtualizer hv, it is based on a set of modification on the linux kernel, but the advent of hw support full virtualization made him obsolete, it now support both paravirtualization and full virtualization via hardware support
- It tried to find a compromise between modification of the kernel and extensive emulation

- Xen is a small kernel that control directly the hardware, at lower level we have the **domains**, they are isolated from each other, and used to implement vm
- *Dom 0* is a special domain that has access to the Xen API to create and destroy other domains, inside Dom 0 we can install any Linux OS
- Domains can be paravirtualized, full virtualize, and can be given direct access to some io devices
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260318192042.png|300]]

##### Virtualization Overhead
- We use this approach if we have a physical machine and we want to deploy on it different application/services, sometimes application from different customers that don't have to interfere with each other, and some of them can use the same library/os

- It is possible to use virtualization to isolate applications in a machine (so create a vm for each application we want to isolate), but this require a substantial overhead in term of memory and performance
- *how can we reduce this overhead?* with lightweight virtualization 

### Lightweight Virtualization
- The idea of this kind of virtualization is create an environment that doesn't require an hv, and support the deploy of multiple application on the same server with a minimum overhead, and provides the minimal set of requirements to host multiple application on the same environment
- It doesn't use vm

- The environment should offer:
  - isolation
  - dynamic instantiation
  - self contained environment
- but it shouldn't use any virtual machine

- e.g. we can instantiate 100 linux system without running 100 kernel

##### Operating System Virtualization
- The **Operating System Virtualization** is a lightweight virtualization approach, with this approach we remove the hv, we orchestrate the virtual servers with the kernel of the host machine that is shared among all 
- we can do this by modifying the linux kernel to allow the instantiation of isolated environment (NELLE SLIDE C'è SCRITTO VM, NON SONO VM)
- the applications are all build on top of a common kernel, modified to offer more services, the application is removed
- kernel create the different user space to host the different environment
- an example of this approach is FreeBSD or Docker 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260405160842.png]]

- *Pros*: the environment is lighter since all the vm share the same instance of the kernel, so a single system with the same amount of resources can support more VMs than full virtualization
- the performance are almost the same as running the application on the original hw 
- *Cons*: all the VMs must share the same kernel, so you can have some security issues, in addition not all the OSs offers OS virtualization solution

##### Container 
- **Container** are an example of os virtualization, it isolate a set of processes with a mechanism that gives the process the impression that they are running alone in the machine
- the result is that an application that run on a container cannot access other application on the system
- we can also reduce the set of resources available for the process (e.g. the process can access only to a subset of the RAM) 
- container are not vm so there are no additional kernel nor a great overhead, but you are bounded to use the os that is running on the host
- the bigger pro is that overhead is negligible compared to run the application on the host
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260405160900.png]]

##### Linux Container
- **Linux Container** are implemented using two different kernel feature:
  - linux namespaces
  - control groups
- they assure that the isolated environment that can access only the set of processes and resources assigned to the container 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260405161025.png]]

##### Namespaces
- **Namespaces** are a feature of the kernel that allow to segregate system resources accessible from the point of view of a process
- it is an evolution of chroot that can be used to limit the file at which an application can access (usually a subdirectory)
- it is not enough to isolate a process completely because it does not control how much resource that a process can access (e.g. the CPU time), if we want full isolation we need to solve this
- Different namespaces are defined, e.g. network namespaces to hide network interfaces or to create virtual interfaces, pid namespaces to hide processes
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260405161105.png]]
##### Control Group
- **Control Group** are used to enforce the amount of resource available for a process, it specify how much RAM and CPU time a process can use 
##### Docker
- **Docker** exploit linux container for software distribution and lightweight virtualization
- Containers are perfect for software delivery as they provide an isolated bundle in which software, libraries and configuration files can be included
- A Docker package after installation is ready to run, as it does not require the installation of additional libraries or dependencies

- You can instantiate a container from an image downloaded form the **Docker registry**, the images are downloaded and run with the *Docker engine*
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260405161118.png]]

### Serverless Computing 
- Containers enabled a new type of cloud computing called **Serverless Computing** o **microservices**
- Cloud consumer do not create full VMs to deploy their services of software on the cloud, but they create containers with their software running into an environment with sw dependency and libraries pre-installed an ready to use


# 0C1 application architecture
##### Recap
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260405174059.png]]

##### Traditional application
- The traditional approach in developing application is to have a monolithical logic that run on a physical single server, data are stored in its local hard disks
- on the other end we have a simple lightweight client that provides the users the interface to the system (a webpage or a GUI)
- Clients and servers comunicate using LAN or WAN



### Cloudification
- **Cloudification**: a process through which an application could be cloudified, so it is deployed *without being changed* on a remote virtual machine (that run on a physical server). The architecture remain intact, users access to the application through the network

- Cloudified application are not *true native cloud application* they are only classical application that run on a remote server, and for this reason they **cannot benefit from most of the benefits** provided by cloud computing, for instance *scalability*, or higher availability, it only benefits of cheaper computer resources

- To exploit the full benefit of cloud we need to *redesign* the applications


### Cloud Application Architecture
- **True Native Cloud Application**: they are based on the idea to divide the functionalities of an application from one giant monolithic service to many modules that comunicate and offer each different different functionalities. 

- Each module can be deployed standalone in a different machine (so in a different VM)
- The simplest example is an architecture composed by two tier, one contain the data and perform queries, and one for handling users' requests
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260405174859.png|300]]


### Multi-tier Architecture
- You need to organize the modules (functionalities) in **tiers**, every tier implement a specific functionality of an application, each tier can have redundancy, and those tiers are organized as a **chain** (so the output of a functionality goes as a input of the next one)  
- One tier can comprise one or more VM (for instance for availability, reliability, redundancy, performance, and balancing) that offers the same functionality

- The organization of VMs inside a tier depend on the application need (e.g. redundancy or availability)

- The first tier in the chain usually offers API, and is the only tier that can be accessed from the outside 

- For instance you can have the application server tier connected linearly with the database tier that store the data that comes from the application tier, and the output of queries in the database query are sent to the application tier (the chain is not unidirectional, it can be bidirectional)

- Another example is to have an application tier that expose the frontend and the API, a database tier that perform query, and the storage tier that physically store the data
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260405174955.png|300]]

### Chain of interactions
- The length of the chain depend on the use case, the result is given back to the user after a **chain of interaction**, so the response must pass through a long part of the chain (it depend on the request) 
- Each VM in a tier comunicate via LAN in the same Datacenter to make communications faster and use an application protocol that can be implemented as a **middleware** (the middleware is standard you don't need to develop it from zero each time, like a DBMS)
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260405175343.png|500]]

### Compute Cluster
- A set of VMs that belong to the same tier are called **Compute Cluster**, it can be organized in two ways:
  - they can implement the same functionality: you have multiple VMs, that can handle the same request in the same manner, if one goes down is not a problem, the other can perform its work 
  - they can coordinate to perform a collective computation, in this case if you have a complex task that cannot be completed in a single VM, here you can distribuite that work between VM dividing the computation (or data) among them

- Cluster's node don't handle many io operation, the overall cluster architecture differs depending on the specific application requirements that depends on the specific use case


## Clusters Types
- There are three way to organize Compute Clusters:
  - High availability clusters
  - Load balancing clusters
  - Compute intensive clusters

### High Availability Clusters
- **High availability clusters**: are cluster whose functionality is crucial to the application or the user, so that functionalities need to be available all the time  
- Outrages are not tolerated, to do so we replicate the replication logic into different VMs, so if some of them are not working the others can perform their work.

- One machine is the **master** the others are **slave/backup**, request are directed only to the master application, the other replicas are sitting there idle waiting for the master to fail, if the master fail, then one backup instance will became the new master that will handle and process user request. 
- It is possible to have an election procedure, or have a *static order*, so when a machine fail the next machine in the ordering will become the new master. The backup have to respond to the request in the same way as the master was doing, this is done by data and internal status, data usually are in a external tier, the internal status instead is created by a replication mechanism from the current master to the slave (we replicate also the data if they are not in a external database tier). 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260405211031.png|500]]

### Load-Balancing Clusters
- **Load-Balancing Clusters**: the main goal is support a load that could increase in the future, obtain an high system utilization, and spread out request from users

- All the nodes share the workload, if your load increases then you can create more VMs, this increase performance and lower the response time. You monitor the response time, if that increase above a certain threshold then you create new VMs, to do so we implement a new later called *surprise load balancer*, sometimes it is implemented in hw, other times we can implement it via sw in the VMs
- The job of the load balancer is to assign the job to one of the vm of the next tier, usually using a round robin scheduling. It is possible to implement a load balancer tier between each tier, or create a path that assign for example each application in the application tier to a database in the database tier. The load balancer tier is managed by the cloud provider.

- Data must be synchronized among the instances on the same tier, in this case data synchronization need to be performed *immediately*, in the HA architecture the backup don't do anything and stay idle, here all the machine answer to requests, so all the vm have to be always updated, the synchronization mechanism should be lightweight and be working all the time 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260405211418.png|500]]


### Computing Intensive Clusters
- **Computing Intensive Clusters**: are clusters designed to handle and process a large amount of data, big data don't fit inside a single vm, to handle it we adopt a *divide et impera approach*:
    - The analysis task is divided into simpler sub-tasks (Jobs) 
    - Data is divided into smaller chunks, each one assigned to a job
    - A jobs and a chunk is assigned to a single server (a worker) for analysis
    - The server perform the task on the data assigned and return the result to a collector
    - The collector merges together the results


- We need also in this case a load balancer, the application tier divide the request in smaller one, data into chunk, and assign jobs to the workers, if data is large you can have a storage tier, that can also allow to limit communication overhead  
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260405211609.png|500]]


### Dynamic Adaptation
- One of the big advantage of cloud is **Dynamic Adaptation**, so you can scale up and down dynamically your system based on the number of requests 
- The best solution is to scale horizontally, creating new VMs with the same functions to handle requests 
- LB and CI architectures, with a balancing tier are ready to scale horizontally to reduce the load, in HA architecture, horizontal scalability can be exploited to improve redundancy


# 0C2 Application Design Methodology
### Cloud application design
- Cloud application are generally distributed system made with different components that interact with each other and exchange data, the implementation of the sw part of a cloud application is complex, moreover when we need to implement a large amount of functionalities
- The traditional development workflow is unfit to drive the development of a cloud application, for this reason it was mandatory to adopt a different approach

### Cloud application design requirements
- Before to understand how to develop a cloud application we need to understand, *what are the requirements of the development process?*
  - the application have to be divided into component
  - **Interoperability**: the components of the cloud application can exchange data in a interoperable way and they can understand each other (so if i send data to a component, he understand me), to do so we develop a standard interface that can be easily invoked by other component, and the data returned by that interface has the same meaning for all component. In short, all the components can exchange data with a meaning that is the same for everyone
  - **Scalability**: the application should be designed in order to be ready to be integrated with a growing number of components, dynamically and effortlessly
  - **Composability**: is the property of a sw component to be self contained, with a clear interface, and this lead that it can be reused in a different project without or with minimal changes (e.g. the google login interface that is used among all Google's applications)

## Service-Oriented Architecture
- Those property are embedded in the **Service-Oriented Architecture** (**SOA**). It is not a tool, a framework or an implementation, is a *concept*, so a design methodology
- Is an approach to design an application as a composition of component called **services** (or *microservices*), each service is a self contained component that implement a set of functionalities
- Applications are highly modular rather than a single massive program
- Software components can be developed using different programming languages and run on heterogeneous hosts in a distributed manner

- **Microservices** are an evolution of SOA that structures an application as a collection of smaller and even more independently deployable services 


### SOA - Architecture
- *How i can organize and put together services?* services comunicate with each other with message that can contain data or requests (**messages passing**)
- Every message has a specific structure that define the format of data, each one is handled internally, it is important to define well the format of the messages 
- This message exchange approach is different from classical distributed application systems, but allow to remove *technological dependency* among components, the only need is to implement the message schema and behave accordingly 
- For every service you have a description (service schema) that tell us what the service do, what functionality can provide, which messages can receive, and which messages can generate
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260406105310.png|300]]

### SOA - Roles
- In SOA, interactions occurs in pairs, and there are roles
- The **producer**/**provider** and **the consumer**
- the *provider* is a service that offer a certain functionality, the *consumer* is another service that want to consume or use the functionality offered by the provider. A service can be a provider, a consumer, or it can be both in different situation 

### SOA – Broker
- In general providers and consumer interact with each other, however at the beginning the consumer is unaware of the address and the constructor of the provider
- To resolve this we introduce the **broker**, a middleman introducer in SOA that provide a *service catalog* (or *registry*) to all services, it is possible given a functionality to retrieve the address of all services that implement them
- Each service publish a list of all the functionality that it offers in the broker when they are created
- Then consumer can contact the broker to search a provider that provide a certain functionality, moreover the broker offers a service description (that allow to implement interoperability)
- There is the assumption that the broker address and schema is well known by everyone 
- Once the interface and address of a provider are known, the consumer can contact directly the provider
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260406105858.png|400]]

- You can have multiple broker to avoid bottleneck and single point of failure
- You invoke the broker only when you want a functionality for the first time you call that functionality

### SOA - Advantages
- Every service has an interface defined by the schema, and as long the schema remain unmodified, is possible to change the implementation of the internal logic of the module without triggering a cascade effect (the modification inside a module that trigger modification inside other modules), this separation is also called *loose coupling*, a feature that allows to plug and unplug specific services from an application effortlessly
- SOA also ensure *composability*, so a system can be assembled using a combination of existing services, we can have this thanks to loose coupling and message based communication that allow to have a *stateless* communication (so each transaction are threats separately in an independent manner of any other transaction)

### SOA - Scalability
- Broker also help scalability, if we introduce new consumer or provider, them can find the other consumer and provider searching the functionalities they need inside the broker
- when an instance is destroyed is removed from the broker's registry
- Another thing that help the scalability of the system is the *stateless communication* 


### Web Services
- SOA is an idea, a set of practices, is not a real workflow, so *how are cloud application implemented in practice?* one of the main implementation is an implementation that use **web technology**
- **Web services** (**WS**) are services using SOA practices and web technology, so self-contained, self-describing modular application designed to be used and accessible by other software applications across the web
- *web technology*: all the technology standardized by W3C, that define services as a sw system to provide interoperable machine to machine interaction over a network
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260406110757.png|300]]

### World Wide Web
- At the beginning the www was just a collection of websites and encoding protocol
- then it evolve and provide mechanism to develop more complex solutions (web 2.0), and those solution where flexible enough to be used also for communication between two machines 
- WS are the natural evolution and adoption of the SOA paradigm over the Web

### Uniform Resource Identifier (URI)
- *What are the component of www?*
  is mainly made by tree pillar, all standardized by w3c
- the first component is a standard, **URL**/**URI** that is a compact string of characters for identifying an abstract or physical resource 
- It has a protocol, the ip address or the host name that is hosting the resource, the port (usually is omitted, and in this case use the default value) and then the path of the resource hosted by the host server
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260406111002.png]]

- the second component is **HTTP**, an application protocol behind the web used to retrieve resource, is a client server protocol, based on a request-response paradigm, this protocol is used to embed every type of data, usually the data is embed in the payload, it can embed payload data in both directions, but it dont know how to organize data inside the payload
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260406111111.png|500]]


- The third component is a way to **encode information** in a way that the message is clear for both part, it gives a structure to the messages. To encode language is usually used HTML on the web, for web services this was not efficient, it is used instead *XML* that can be used to encode any type of information into some payload in a way that data can be both human readable and machine readable, and that is achieved specify a set of syntax rule, you can specify in a meta document the meaning of information contained in a XML document and a set of rules to check if the information made sense 

### XML
- An XML document has a hierarchical structure and is composed of several elements
- An element is a logical document component that begins with a start-tag and ends with an end-tag
- The document usually begins with a root element, named XML declaration that describes some information about the document itself
- A tag is a markup construct that begins with ‘<‘ and ends with ‘>’
- Tags can contain attributes, a name-value pair tat can be specified within a start-tag
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260406111353.png]]

- One of its strength of XML is that it specify some *syntax rules* that tell if the document make sense or not (e.g. all open tag must be closed), some rules are present in all document, but you can also specify new rules thanks to the XML schema, a document with a list of metadata (additional info) that specify the type of data in a document with respect to the use case that you are considering (e.g. you can specify the mandatory fields of an element)
- This meta document can be used by machine to check if a document make sense of not
- This can help to achieve interoperability, and it can also be used to define the schema of the message that the message it is should have


### WS Interaction 
- A WS has an interface described in a machine executable format, the **Web Service Description Language** (*WSDL*)
- WSDL is a standard that specify the format of messages between the broker and the consumer and the broker and the producer
- Service consumer and provider interact  instead using the *Simple Object Access Protocol* (**SOAP**) that provides a standard messaging format
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260406112301.png|400]]
- So you comunicate with the broker using WSDL, consumer and producer comunicate among themself with SOAP

### SOAP
- **SOAP** define a standard way to package info exchanged between consumer and producer, embedded as XML and exchanged via HTTP
- Every message has this structure:
  - **Envelope**: is the shell of the message, contain a header and a body
      - *Header*: has some meta and security information
      - *Body*: include the payload (information to exchange), it maybe not included in the request, but it is included in the response, and a fault section that include exception and errors
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260406112526.png|300]]

### SOAP Message Example - Request
- A message look like an XML document, SOAP specify the needed elements, all is contained in the *Envelope tag*, the request contain the link of the resource that you want, and some parameter
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260406112554.png]]

### SOAP Message Example - Response
- The response contain in the body the fault section
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260406112625.png]]

### SOAP Binding
- SOAP messages are send through HTTP request and response, for instance GET or POST
- if you use GET the response is a SOAP message and the request can be something else, with POST, both the request and the response have to be POST messages


### WSDL
- **WSDL** describes the interface and the set of operations supported by a WS in a standard format
- It allow users to understand what a service can do, where is located and how can it be invoked


### WDSL – Message architecture
- A WDSL message is a XML document divided into two sections:
  - **Service Interface Definition**: provide information about the service in an abstract manner, like the type of data (*types*), the messages exchanged between requestor and provider (*messages*), and the operations that can be performed (*portType*)
  - **Service Implementation Definition**: define for every operation defines how to invoke that operation via an HTTP request, it comprise how to transfer messages (*binding*), and how to invoke the service (*service*)
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260406113241.png|400]]

### WSDL - Type
- WSDL *Type* can be used to define the type of data used for the parameter of a specific service 
- WSDL *Messages* is used to define the message exchanged between client and the WS
- WSDL *PortType* can be used to link input and output messages into one logical operation (da rivedere)
- WSDL *Binding* is used specify how the messages associated to one PortType operation are exchanged
- WSDL *Service* is used to specify how the operation is practically invoked, i.e. the URI associated with the service


### REST
- The SOAP architecture is *complex*, and designed to be interoperable, but it was not a good fit for small and medium project due to the complexity of protocol

- From the idea of creating a standard that provide a *minimal set of functionalities* was born REST, to have a faster and simpler system
- It is still based on the three pillar of the web
- In a RESTful system, a client sends a request over HTTP using the standard HTTP methods (PUT, GET, POST, and DELETE), and the server issues a response that includes the representation of the resource
- By relying on the minimal support offered by HTTP, it is possible to provide whatever it is needed to replace the basic and most important functionality provided by SOAP: the method invocation
- data can be encoded in XML or some alternative like JSON 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260406113745.png|400]]



##### REST Basics (Summary)
- **Core HTTP Methods (CRUD)**
  - `GET` → retrieve data  
  - `POST` → create data  
  - `PUT` → update/modify data  
  - `DELETE` → remove data  

- **Data Transmission**
  - Via **query parameters** (in URL)  
  - Via **request payload/body**  

- **Resource Identification**
  - Each resource has a **unique URI**  
  - Uniform access: any client can access a resource via its address  

- **Operational Completeness**
  - HTTP methods + well-designed URIs enable all basic WS operations  

- **REST vs SOAP**
  - REST is **lightweight**  
  - Suitable when advanced features beyond HTTP are not required  

- **Data Formats**
  - Supports multiple formats: **JSON, XML, plain text**, or others by agreement  
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260406113858.png|500]]

### JSON
- JavaScript Object Notation (JSON) is an open standard format that uses human-readable text to transmit data objects
-  It is designed to be a lightweight data encoding, based on only two structures
  - Collection of name/value pairs
  - Ordered list of values

### CRUD
- The acronym CRUD refers to all of the major functions that are implemented in relational database applications: Create, Read, Update and Delete
- Each letter in the acronym can map to a standard Structured Query Language (SQL) statement, Hypertext Transfer Protocol (HTTP) method



# 0C4 Scalable Applications
### Recap: Cloud applications architecture
- **Cloud applications** are developed as distributed systems, whose implementation is the composition of different functionalities hosted on different VMs
- Such VMs are clustered into **tiers**, within each tier the VMs replicate the functionalities in order to ensure high availability and scalability
- Requests from clients are received by the VMs of the first tier, named frontend tier and then dispatched to the other tiers, named backend tiers
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260411134418.png|300]]

### Recap: Design methodology
- A service oriented architecture is adopted: each VM hosts one (or more) self-contained software component, referred as service that interact with others via **message passing**
- Two different solutions have been defined for service construction, i.e. to define the way messages are exchanged between software components:
  - SOAP
  - REST
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260411135219.png|500]]
- REST, due to its simplicity, is often adopted as interface towards clients, i.e. for the client/frontend communication
- SOAP adoption is decreasing recently, although it is still used in the frontend/backend communication and, rarely, in the client/frontend communication

### Request-Reply communication
- Both SOAP and REST have a strong drawback, the fact that both adopt a *request-reply communication*, it is a drawback because it is a **synchronous communication**, so the client perform a request and then it blocks until the answer arrive (time-coupled)
- this approach is reliable, and the reply is acknowledge of the reception of the message

- The second drawback is that this is a **direct communication**, so the client interacts directly with the server without intermediaries
- However in a cloud system there are a lot of dynamic creation and destruction, sometimes you want to handle a request with a machine that does not exist yet and is being created
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260411135416.png|300]]


### Space/Time coupling
- **Request-Response** paradigm meets the requirements for the communication interface between clients and the cloud *frontend*: the paradigm is simple and reliable and client implementations can tolerate space and time coupling
- The communication between frontend and backend is different, because the backend is expected to have a varying number of VMs to support scalability through load-balancing or availability through data replication, this is difficult to support with space coupling and time coupling

- How can we support better this kind of systems?
- we would like to have a indirect communication using a **man in the middle**, this could give us space and time uncoupling:
  - *space uncoupling*: two party comunicate in a indirect way, they may don't even know the identity of the other, its benefit is to have a request generated by a user, and that request can be manage by a producer that does not jet exist at the time that request was sent
  - *time uncoupling*: the sender and the receiver do not wait for the other in communication, so you don't have active wait and no time is wasted

- Space uncoupling is achieved by introducing an intermediary with no direct coupling between the sender and the receiver 
- Time uncoupling is ensured by the intermediary that adopts an asynchronous communication paradigm: the sender sends a message to the intermediary, then continues (without blocking) the intermediary takes care of delivering the message. The result is that there is no need to meet in time with the receiver to communicate

### Message oriented communication
- There are two approaches to implement this paradigm, and both of them are implemented introducing in the middle a **Message Bus** (the middleman), the most important are:
  - message broker 
  - message queue
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260411140319.png|300]]

### Message broker
- **Message broker**: (***different from the broker from before***): its a message bus, so it dispatch message, and does that by adopting a **publisher subscriber system**, the first produce data, and the seconds are interests into receive some kind of data. Every message injected in the system is usually associated with a topic (the topic is usually related to a certain functionality)
- The result is a one-to-many communication
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260411140745.png|300]]

### Subscription types
- There are many subscription types, different criteria can be used to define a filter for subscription:
  - **Channel-based**: publisher publish data to named channels and subscribers then subscribe to one of these named channels to receive all data sent to that channel
  - **Topic-based**: each data has a set of fields, on of them is the *topic* of the data, subscription are then defined in terms of the topic of interest, this approach is equivalent to channel-based approaches, with the difference that topics are implicitly defined in the case of channel but declared as one of the field in the topic-based approach
  - **Type-based**: subscription are defined in terms of types of events and matching is defined in terms of types or subtypes of the given filter

### Message Queue
- **Message Queue**: it is the most popular approach, is a system that handles data coming from services and dispatch them to another tier, it change how data are organize, the system is organized using queues, a message is asked to be enqueued in a specific queue, the consumer ask to be notified when a message is available in a certain queue, if the queue is empty the message is dispatched immediately, otherwise it is enqueued
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260411141234.png|300]]
### Message Queueing System Operations
- The basic operation of a message queueing system:
  - **Send**: a producer place a message in a queue
  - **Blocking Receive**: a consumer block until a certain message arrive 
  - **Non Blocking Receive** (*polling operation*): a consumer check if a message is available or not (check the status of the queue)
  - **Notify**: the message queue system notify a subscribed consumer when a message is available in its associated queue


### Messages
- **Messages** are designed to be anything, they can carry anything, they include a *destination* (an unique identifier that identify a designated queue), *metadata* (e.g. priority, delivery mode), and the *body* that contain the real content of the message and is usually opaque and is not touched by the queueing messaging system

- Messages are enqueued and dequeued in FIFO order (usually), but some system use also priority
- messages are *persistent*, so message queues will store messages indefinitely (until they are consumed), and also commit the messages to disk

### Message Transformation
- The message can be modified, for instance we can change format to deal with heterogeneity
- For instance we can change thing like the byte order (big-endian to little-endian) or the external data representation

### Scalability
- By introducing a message queueing system, if the message queue is just one node we are introducing a bottleneck and a single point of failure, that's why usually we implement them in a redundant manner, sometimes the message queueing system is even a *tier* used just for that 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260411144656.png|300]]

- Message queue can handle the varying number of VMs in a tier to scale the system, moreover producer fo not have to wait for the request-response blocking message exchanged

### Implementations
- Message brokers and message queueing system can be implemented in a centralized and distributed manner
  - In a **centralized** implementation, the broker or the message queueing system is implemented on a single system (e.g. a single VM), this lack scalability and introduce a single point of failure
  - In a **distributed** implementation we have a network of broker/message queueing system, this is more complex, we need coordination and data replication, but we obtain resiliency and scalability

- The **Advanced Message Queueing Protocol** (*AMQP*) is one of the most widely adopted implementation for Message Queueing System

## Data replication 
- Every tier usually replicate data inside a tier, and we synchronize data that belongs to the same tier because the backup must respond in the same way the primary was doing, to ensure this we replicate data (status of data structure and data stored internally in each vm) 
- Data replication is usually implemented via message exchange 

- When a large dataset is involved is unfeasible to synchronize data only with message exchange, so it is better to use a shared database putted in a new tier, accessed to each replica in a tier
- But we still use messages for coordination
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260411145547.png|400]]

### Requirements
- Data replication across different VMs should take into account the following requirements:
	- **Replication Transparency**: the mechanism should run in background and the user should be unaware of the synchronization mechanism
	- **Consistency**: replica should be consistent with each other, e.g. an operation performed on any replica should produce the same result 
	- **Resiliency**: the system should be resilient from VM failure, (NOTE: we assume that network partitioning cannot occur, because the data replication system that we will see do not handle that), so we assume that the network always work

- Data replication mechanism can be internal to a datacenter, and method that allow to handle network partitions 

### System Model 
- The data in the system is a collection of objects, i.e. a file, a class or a set of records. Each logical object is implemented as a collection of physical copies, named **replicas**
- Each replica is stored in a different **replica manager**, a different component that stores an instance of the replica (a VM composing the cluster of a tier, in our case)
- In order to ensure consistency, replicas are state machines, meaning that in addition to data, the state machine is also replicated
- Each replica manager accepts update operations on the data in a recoverable manner, so inconsistencies due to failure can be recovered
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260411150031.png|300]]

### Request handling
- every VM in the backend should **handle requests** following a *five phases* approach:
  1. **Request**: can be of two type, query (a request that want to retrieve some data and don't want to modify the status of the system), and update (a request that is going to change some data structure or internal data of the system). In this phase we receive the request in the frontend module that will forward it to the replica managers (the first backend tier)
  2. **Coordination**: as soon the request is received from the backend, the replica manager coordinate with other replica manager to prepare the execution, on which of them should process the request, during this phase there is a lot of exchange of data, and the result of this phase is to decide if execute the request immediately or wait some times to ensure that all replica manager are consistent  
  3. **Execution**: here we start the execution in the replica manager, usually we have the option to execute the request tentatively (so we can undo it to recover from faults)
  4. **Agreement**: here multiple manager execute the request to check if results are consistent or not, if an agreement is reached, the execution of the request is committed
  5. **Response**: in this phase we simply send back the answer to the front end using one or more replica manager

- those are the general phase, it is possible to have different schemas 


### Group/Multicast Communication
- usually the communication across different manager is based on **Multicast communication**, a communication mechanism that allow one node to comunicate with a group of others, this is used to implement replications, there are different types of multicast communication, that gives different *guarantees* and with different complexity in the mechanism, usually more reliability means a more complex communication 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260411150830.png|400]]

- Main *Multicast Communication method*: 
  + Reliable Multicast
  + Total order Multicast
  + View-synchronous communication

- The less complex one is **Reliable Atomic multicast** that is the one with less guarantees, it dispatch messages to a group of nodes, with the only guarantee that messages will be delivered at some point in the future, but we do not have assurance on when and on the order of delivery 

- **Total Order Multicast**: is in the middle, we have reliable communication at some point in the future in a assured order, but we do no have any guarantee on when, it can happen that one node receive a second message before another receive the first one, message are delivered in order, but one node can be behind in the communication

- **View-synchronous communication** is the more complex, you are guarantee that message are received in order and also the guarantee that nodes are not leaved behind, but we still not have any guarantee on the time in which we will receive the messages (we need an even more complex system for that)

### Primary-Backup Replication
- The **passive replication** or **primary-backup replication** model is adopted to guarantee *fault tolerance*
- At any time, a single replica manager is selected as primary, while the others are backups or slaves

- The frontends communicate only with the primary replica manager, which is responsible for handling the requests and sending copies of the updated data to the backups
- If the primary fails, one fo the backups are promoted to primary
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260411151641.png|300]]
- we waste resource because a lot of VMs are sitting idle without doing nothing

##### Primary-Backup Request Handling
1. **Request**: the frontend issues a request, the request contains a unique identifier, which identifies univocally the request (so we can ignore already duplicated requests) 
2. **Coordination**: The primary handles requests atomically, in the order in which they have been received. It checks the unique identifier, if the request has been already executed, the same response is sent back. No coordination with other replica managers is needed
3. **Execution**: The primary executes the request and stores the response
4. **Agreement**: If the request is a query we check we can answer immediately, if the request is an update we don't answer immediately (we need to propagate the update to all the slaves), the primary sends the updated state, the response and the unique identifier to all the backups. The backups send an acknowledgment. For this kind of communication atomic multicast is sufficient
5. **Response**: the primary responds to the frontend, which hands back the response to the client

### Active Replication
- Another different approach to guarantee high availability is **active replication**
- Replica managers are *organized in groups*, frontends multicast their requests directly to the group so all the replica managers in the group can process the request independently and reply (identically)
- If a crash occurs in any of the replica managers, there is no impact on the performance as the remaining replica managers can reply

![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260411151816.png|400]]
- we are wasting resources because all the VMs are processing the response of the user 
##### Active Replication - Request handling
1. **Request**: The frontend attaches a unique identifier to the request and multicast it to all the replica managers.
2. **Coordination**: No coordination is needed in this phase, the multicast method takes care of sending the request to all the replica managers. The method adopted has to be a *total order multicast* to ensure that requests are received in the same order by all the replica managers (because if we process request not in order the result could change)
3. **Execution**: Every replica manager executes the request. Since the requests are delivered in total order, replica managers process the request identically
4. **Agreement**: Thanks to the total order multicast, there is *no need for agreement* 
5. **Response**: Each replica manager sends its response to the frontend. Considering that the multicast algorithm is a total ordered algorithm the frontend can forward the first response received (so we are discarding the others)

### Passive/active approaches
- **Passive/active approaches** focus on providing *high availability*:
  - In the passive approach, backup replicas do not take part at handling users request, consequently the load is all on the primary replica, while in the active approach the replicas serve the replicas in a redundant manner
  
- A different approach has been defined to provide high availability and scalability at the same time:
  - Different replica managers are involved in handling requests from the frontend (*not just one or all handling the same request*), in parallel, thus maximizing utilization
  - Replica managers *do not propagate updates in a prompt manner* (as soon as they are available and before passing back control to the client), updates are deferred when possible, while the control is given back to the client as soon as possible (even before propagating the update to other replica managers)
- This approach is called the *gossip architecture*

### The Gossip architecture
- In the **Gossip architecture**, the replica managers exchange gossip messages periodically in order to convey the updates they have received from clients
- Clients are assigned to specific FE (Front End) instances for load balancing, even though they can change, if the assigned instance crashes

- Data structure and status of the replica manager are updated via message send in a lazy approach (if you have to send an update that update message is not forwarder immediately, but later when it is really needed in background), by doing this you are not blocking the replica manager in waiting for the update
- However the exchange of messages in a lazy way can create inconsistency if it ask data to a non-updated replica manager


- The service provides two basic types of operations:
  - **Query**, which are read-only operations
  - **Update**, which modifies the state of an object. The update operation does no read the state
 
- The gossip system makes two guarantees:
  - Each client obtain a consistent service over time, i.e. in answer to a query, a replica manager provides a response with data that reflects the last updates that the client has observed so far (its own updates). 
  - The consistency between replicas can be relaxed in time due to the frequency of the exchange of gossip messages, i.e. a client receive an old (but consistent) information when a query is issued. *Sequential consistency is guaranteed*

- So the same user asking for the same data structure over time will receive a view consistent with its view, however two different user can receive slightly non updated view. But the view and the status will always be consistent 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260411152551.png|300]]


##### Gossip Architecture - Request handling
1. **Request**: The front end normally sends requests to only a single replica manager at a time (only one replica manager receive it not everyone)
2. **Coordination**: The replica manager that receives the request does not process it until it can apply the request according to the required ordering constraints. This may involve receiving updates from other replica managers, in gossip messages. No other coordination between replica managers is involved (it does not execute the request until it is sure that is inter status is updated with the view of the user, if it is not updated it does not execute the request, otherwise it would produce a response that is not updated with the response that the user received in the past). The update between replica manager happen usually every x minutes, so if a replica manager is not updated it will wait until an update message will arrive
3. **Execution**: The replica manager executes the request
4. **Agreement**: The replica managers update the data by exchanging gossip messages, which contain the most recent updates they have received. The updates are exchanged in a lazy fashion, i.e. gossip messages are exchanged only occasionally, after several updates have been collected, or after a certain amount of time
5. **Response**: If the request is a query, the replica manager replies after the execution, if it is an update, it replies right after receiving it

- using a lazy update we can reduce the overhead of messages because we exchange less messages, and additionally we do not block managers for update 

### Timestamps
- The *coordination* phase is implemented using timestamps

- In order to keep ordering of requests, **timestamps** are adopted (to this aim FEs must have their clock synchronized)
- Specifically, each FE keeps a vector of timestamps that reflect the version of the latest data values accessed
- This timestamp is sent to the replica manager (the field prev) together with the query, it is used to check if the datastructure is updated with respect to the user
- The replica manager supplies a new timestamp with the response (the field new)
- Each returned timestamp is merged with the previous timestamp value

- We keep a timestamp about when a user has lastly accessed a certain data structure (we keep a list with all the users and all the accessed data structures)
- We use it to check if the view of the manager is updated with the view of the user
- If we instead we pair each user with a certain FE that is paired with a certain RM we don't need this check 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260411152939.png|300]]


### Processing Query
- Assuming that a user want to perform a **Query**
- The timestamp associated with the query request reflects the latest version of the value that the frontend has read or submitted as update
- For this reason, every time a query is received, the replica manager has to return a value that is at least as recent as the value provided with the query
- For this reason, if the timestamp of the latest local replica’s update is oldest than the timestamp provided $\text{(valueTS < prev)}$ the request is deferred and kept on a list of pending operation, in order to wait for a missing update
- Once the query can be executed, the replica manager returns the $valueTS$ of the last value update to the frontend

### Processing Updates 
- If instead a user want to perform an **Update**
- When a replica manager receives an update request from a FE it first analyzes the request ID to check if the request has been received and processed already (the frontend uses the same ID each time)
- If the request is not duplicated, the replica manager creates a unique timestamp by incrementing the prev value received from the FE and then it sends back the response with the updated timestamp
- It also adds a new entry to the local log record of pending update operations
- If the same timestamp condition of the query is satisfied $(prev <= valueTS)$ the update operation is committed, otherwise it is deferred until it is satisfied (every time a next gossip update is received the condition is verified)


### Replica Manager
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260411145349.png|600]]

### Example - ZooKeeper
- **ZooKeeper** is a high-available service usually exploited for data exchange among different services
- It can be used to store configuration information, create a distributed directory or a naming system
- ZooKeeper is a replicated service, it requires to operate that a majority of nodes are not crashed to progress
- Crashed servers are excluded automatically, if they recover can rejoin
- It uses a primary-backup scheme to operate and implements an atomic broadcast algorithm named Zab to operate





# 0C6. Geographically Distributed Applications  


### Global-scale applications
- In the previous lessons we assume that network partitions cannot occurs (because the vms are located inside the same datacenter and the network is reliable)
- This is not always true, some application must be globally available to million of users, and to support those application we need a different design where vms are deployed among multiple data centers
- For instance if you want to handle google search engine, even if you are able to put together a lot of computational resource in just one place, you will have as bottleneck the internet infrastructure 
- It is better to have scattered data center around the world


- You can have multiple internet providers to have redundancy
- Usually it is better to have one datacenter per region and redirect user requests to the closest data center 
- If one datacenter is down you will be redirected to another data center


### Load Balancing
- We want control on the policy on which data center the request is directed 
- The idea is to introduce a two layer **Load balancing** for handling the requests:
  - *Global level*: dispatch globally the request among different datacenter
  - *Local level*: decide which vm serves a request inside a data center

- So you have to policy, one to select the datacenter, one to select the vm 
- The balancer could be a software (like ha proxy), or a piece of hardware

- At the Local level usually we want to balance the load for scalability
- At Global level we can use complex policies, that depend usually on the application, because the quality usage of a user change in different application (e.g. in google search it can be latency, in WhatsApp it is more important the bandwidth that is used to upload videos)


##### Global Load Balancing using DNS
- Before the client can send its request, it has to lookup an IP address using **DNS** (*Dynamic Name Server*) a mechanism that resolve a nome into an ip address

- Many sites has many ip address for redundancy, if one ip doesn't work, the DNS try another
- The DNS protocol do not provide any indication which ip we should take form the list


- DNS exploit this phase to introduce a first layer for request dispatch
- The simplest solution is to configure the DNS records to return multiple A or AAAA records in the DNS reply and let the client pick an IP address arbitrarily
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260417135918.png]]

- The solution is simple, but provide very little control over the client behavior
- Record are randomly selected by clients, which cannot determine which address is the closest
- To mitigate this issue we can use a localized DNS system, to allow responses based on the geographical location of the client, however this method offers only a *coarse-grained control*, and update a DNS record takes several hours, so you cannot apply policy that are changing very frequently 
- A fine-grained control can be obtained by employing **Virtual IPs**
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260417140409.png|400]]



### Virtual IP Addresses
- **Virtual IP**: is an IP address that is not assigned to any host or any particular network interface and it is shared among different devices

- From the point of view of the user it seems a regular IP address

- A set of VIPs could be assigned to an application (e.g. the web search engine) and each VIP (or a subset) could be assigned to a region, in each region (e.g. western Europe) multiple datacenters could be available
- The ISP take care of sending data to the closest global load balancer
- The regional DNS service is configured with the VIPs assigned to that region for a specific service
- For each region, one (or more) global load balancer are deployed. A global load balancer could be installed within the ISP networks or in certain exchange points (where different ISPs interconnect)
- Each global load balancer has assigned the VIP associated to the service in that region

##### Packet Encapsulation
- The global load balancer receive requests and dispatch them to data center, to do so it *incapsulate* each request in a **packet** and sent to the selected data center
- At the destination data center, the packet is decapsulated and processed like it were received directly by the data center 

- **Generic Routing Encapsulation** (**GRE**) is usually adopted to establish a tunnel between the global load balancer and the datacenter
- It allow to encapsulate an IP packet in the inside of another IP packet, where the outer IP packet contain the destination IP address of the load balancer at the destination data center
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260417140903.png|500]]



### Geographically distributed system
- Data replication and synchronization is a challenge across distant sites interconnected via wide area network links due to
  - *limited bandwidth* that increase time needed for synchronization operation 
  - *lower communication reliability* that create frequent network partitions

- For those reason we cannot use traditional data replication strategies that assume low latency and high reliability
- Moreover they do not manage **network partitioning**, while us want to node to continue to offer a service even if they are partitioned


### ACID
- In traditional system (e.g. relational db) consistent is ensured all the time, they ensure the ACID properties (Atomicity, Consistency, Isolation, Durability), if a system is not consistent is not available 
- Availability is ensured through replication, which is performed strictly in order to ensure strict consistency


##### CAP
- We can have different approaches to handle data partitions, we can see all the strategies with the CAP theorem that tell us that you cannot have availability, partitions-tollerance and consistency at the same time, only two of those can be guarantee at the same time

- It doesn't mean that the third property will never be respected, it is possible to have some compromise 
- CAP tells that *perfect* availability and consistency are not feasible in presence of partitions, but you can have different level of availability and consistency 

![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260417143303.png]]

##### BASE
- BASE system (Basically Available, Soft state and Eventual consistency) picks availability and tolerance partition and compromise on consistency, the system is always available, and during partition can be inconsistent for some time, but it will return eventually consistent after a period of time (*eventual consistency*)
- This approaches can be used by all applications that can tollerate not updated data for some period of time and require an high availability (e.g. social media)

- The main difference is how updates are managed, in ACID updates are propagated immediately in a synchronous manner (this create delay, and user cannot read during updates), in BASE data are replicated asynchronous in background via a protocol that is called **anti-entropy protocol** (but locally we execute the update immediately)
- Due to this deferred propagation, inconsistency might arise (query can return inconsistent data), it can also happen to have conflicts, as two different location can accept two conflicting values
- When a site receives an update that conflicts with the local copy, it must run a *conflict resolution mechanism* (e.g. accept the update with the latest timestamp)

- Query operations instead are handled in the same manner in the two systems, they provide an answer based on the local status
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260417092111.png]]

##### Advantages/Disadvantages
- The **advantages** of the this approach is that you can manage network partitions by design, and response delay are minimal, but this approach is not suitable for system that do *not tolerate conflicts*


### Bayou
- The **Bayou architecture** is an *eventual consistent* architecture with the goal of high availability, and with weak guarantee on *sequential consistency*
- Each replica manager exchanges updates on the data using an anti-entropy protocol that provides updates in group
- It use a conflict resolution policy to ensure that data are the same in the long run

##### Bayou operations
- When it receive an update it is applied locally, but marked as **tentative**, while an update is tentative, it can be undo if it is necessary to reach a consistent state
- Instead, once an update is **committed** it remains applied
- Committed updates are ordered in their order of commitment
- Tentative updates are ordered on the local reception timestamp

- Every time a new update is received it is added to the list of updates, some of them are committed other are tentative
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260417145219.png|400]]


- Bayou adopts a *primary commit scheme*, there is one replica manager (usually the primary), responsible for deciding when a data is committed 
- The policy between on when committing an update depend on the specific application requirements

- If the primary replica manager is unavailable, the system cannot commit update, but every manager will continue to accept update as tentative in the order they are received by users, and query are answered without problem
- When the primary is being reconnect it will start to commit update again from the tentative, but during the period in which is unavailable you can have some inconsistency


##### Conflict detection and resolution
- How you resolve inconsistency? when an update is received it can result in a inconsistency, there are two mechanism used to manage them:
  - The **dependency check**: a query provided by the developer, that check a set of conditions, if the result of the query is different from the expected result then a conflict is arisen
  - A **merge procedure** which is a procedure capable of resolve a conflict, ita can be run independently by each replica 

- Both dependency check and merge procedure have to be deterministic, every replica can run them and resolve conflicts in the same way


##### Performance measurement
- The performance of the system depend on the anti entropy protocol, the more frequent the update, the shorter is the conflicts window, however the greater the overhead introduced (and so more time is required to perform query)
- There are mathematical model to model the life of inconsistency 




# 0D1. Cloud Platforms Technologies 

### Recap
- For now, the cloud is an infrastructure offering the possibility to create VMs
- Such infrastructure is designed, deployed and maintained by the cloud provider, which sell virtualized resources for profit 
- On top of VMs cloud applications are deployed (by cloud consumers), whose services are offered to end-users, in some cases for profit 
- We know how a VM can be created on a single machine using virtualization technologies 
- What is a cloud computing infrastructure? How do we manage to create an infrastructure that allows to create and control a large number of VMs on a large scale?
- One possibility is to have a system administrator that manage manually everything, but this is not feasible for bigger system, we need the infrastructure to manage itself

### The cloud infrastructure
- Recent virtualization technologies allow VMs to be created on top of regular hardware
- The **Cloud Infrastructure** is a group of servers (with an hv installed in each server) interconnected via LAN, and with the internet via a router, and deployed in a datacenter
- The Cloud Infrastructure exploit regular unmodified hardware to support the creation of VMs, it does not require any specific modified hardware


### Cloud Platform
- A **Cloud Platform** is a pool of servers, each one running an hypervisor
- It is a distributed system (it can be considered a special type of cloud application) that controls the hypervisors of all the servers in the infrastructure, it manage the creation and destruction of VMs on the infrastructure

- In order to allow the management of the VMs, the platform exposes a management interface that can be used by humans or sw
- The cloud platform allows to implement the IaaS cloud model as it enables the creation/destruction of VMs


##### General Architecture
- The overall architecture of a cloud platform is simple, it is just a set of servers connected to an high speed local area network (>10Gbps)
- Every server has an os installed on bare metal, an hv is installed on top of the os to virtualize resources of the server
- With a bare metal hv is fine as well, and it is an os itself 

- A cloud platform sw (called the **agent of the cloud platform**) is installed on all the server on the os, to control the local resources virtualized by the hv
- We have also another category of servers called **cloud platform controller**, that implement a system wide management functionality, they usually doesn't have an hv, and are dedicated to hosting the controlling system. The software is responsible for controlling the overall platform communicating with the agents
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260417154323.png|500]]

##### Cloud Platform Implementations
- Some cloud platforms implementation are sold as product, other are open source 
- We don't have a standard architecture, but all solutions are similar, we will study the intern of open source solutions like openstack 

### OpenStack
- **OpenStack** is a free open-source software platform for *IaaS cloud computing*
- It started as a NASA project, it is now supported by the OpenStack foundation which is composed by more than 500 companies, it gained a lot of attention because proprietary solution costs sky-rocketed, is the main solution adopted for private cloud computing

- It can be used as multi site computing platform
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260417154548.png|300]]

##### OpenStack Software Platform
- One of its main property is it can run on any hw, even commodity hw, it run on top of any linux os, and support multiple hv technologies
- Through each hv, openstack instantiate or destroy VMs

- Every server that has installed the openstack sw is called an **OpenStack Node** 
- It manage the connection of vm with virtual network
- In addition to virtual machine and virtual network, it manage also virtual storage (so it can create virtual hd for the vms)

##### OpenStack Instance
- Nodes running the OpenStack software are configured to from a single **OpenStack instance**, combining together computing, memory and storage capabilities to create VMs
- In a instance, at least one node is configured as *controller* that coordinate all the open stack controlling functionalities like the creation and destruction of vm (we can have one or more controller nodes)
- The other nodes are the *workers*, called also **compute nodes**, that offer computation and storage resources to run virtual machines
- Nodes are connected via the lan of the datacenter, this allow to make comunicate the different components of openstack, and used as fabric for virtual networks 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260417155543.png|300]]


### OpenStack architecture 

- The platform exposes a **web dashboard** to allow users and administrators to manage virtual resources
- It also offer a command line for users, and it expose also a set of **REST API** that can be used by external programs
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260417155604.png]]


- One of the main feature of openstack is that every piece is highly **modular**
- The functionalities are grouped into services, each service is implemented in a cell contained module, each of them could work separately and is developed and maintained as a separate project 
- Each service expose a set of rest api that can be used to interact with the service and receive request
- Communication among module is performed using a message queue system 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260417155744.png]]


- Open stack **services** are grouped in *4 layers* depending on their role inside the platform and depending on how crucial they are
- The order represent how likely that a service is adopted by an installation, at the lower layer there are the mandatory services, on level 2 there are very likely to be included, at level 3 optional services that are usually included, at level 4 you have very optional services, used only in specific use cases
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260417160335.png]]


- An open stack installation can be customized (you can choose which services download)
- Every service is installed on the controller or compute nodes, some services are required to be installed on both
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260417160551.png|200]]
- All the services installed in the controller node leverage some *supporting services*, a database (for status and configuration) and a data broker for message exchange across different modules

##### Information Exchange/Communication
- Communication between services can happen in three ways:
  - **Message broker**: services exchange direct message via the message broker
  - **Rest api**: a service invoke the rest api interface in the same manner performed by an external program 
  - **Database** two modules exchanges information via the database, request and response are performed via TCP/IP connection
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260417160902.png|500]]


## Main Services
### Keystone
- keystone is the **identity management component**
- Keystone is used by OpenStack for *authentication* and high-level *authorization*
- It ensures security by granting/denying access to objects (e.g. Virtual Machines or Virtual Networks, Virtual Hard drive) to different **Users** 
- Objects are grouped into **projects**, authorizations can be granted per project that is assigned to a user 
- Keystone is usually installed on the Controller node
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260417163043.png|300]]

- Keystone implements a *token-based authorization* 
- A user first interacts with keystone using an user/pass based authentication 
- If successful a token is received 
- The token is used to access all OpenStack services 
- Each service takes care of validating the token
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260417163148.png|500]]

### Nova
- Nova the **VM management** component
- It is responsible for the instantiation and management of Virtual Machines 
- Nova does not implement a new virtualization technology, but it interfaces with existing hypervisors to manage VMs 
- Different virtualization technologies can be used
- It includes two different modules, the **nova controller** installed on the *controller node* and the **nova agent** installed on the *compute node*
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260417163402.png]]

##### Nova –Subcomponents
- The Nova module is installed on the controller node and on the compute node
- On the controller node the nova component is responsible for handling the requests from the users and managing the resources available on the compute nodes. Specifically, it collects the requests of VM creation/destruction from the interface, it evaluates the corresponding actions to be performed and sends the commands to the compute node
- On the compute node, the component is responsible for receiving instructions from the controller module and to translate it to the corresponding commands for the hypervisor
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260417163547.png|500]]


##### Nova – Controller Subcomponents
- The Nova module installed on the *controller* node is composed of the following sub-components:
  - **Nova-API**: exposes the external REST interface used by users and other services 
  - **Nova-Conductor**: manages all the control operations
  - **Nova-Scheduler**: evaluate the proper placement for a new VM according to the status of the compute nodes and the resource available 
  - **Nova-Network**: implements basic networking services for VMs or interfaces with other network services if installed 
  - **Nova-Consoleauth** and **Nova-Novncproxy**: implements a console service through which users can connect to VMs 
 
- All the components interact through the messaging queue


##### Nova – Compute Subcomponents 
- The nova *compute* component is simpler, it just has a single module responsible to receive commands from the controller (e.g. create and destroy vm) and implement those command interacting with te hv
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260417163928.png|500]]


### Nova – VM Creation Workflow
- *What is the vm creation workflow in OpenStack?*
- When a request for the creation of a new VM is issued by the user the nova components perform the following steps:
   1. Nova-API receives the request that is forwarded to Nova-Conductor
   2. Nova-Conductor forwards the request to Nova-Scheduler, which suggests the proper placement for the new VM (which compute node has available resources) 
   3. If the Nova-Scheduler allows the creation of the VM (sufficient resources are available in the system) Nova- Conductor forwards the request to the Nova-Network service to instantiate the proper network configuration
   4. As the Network is properly configured, the request is forwarded to the Nova- Compute service of the node selected by Nova-Scheduler 
   5. The local Nova-Compute interacts with the hypervisor to create the VM 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260417163958.png|500]]


##### Nova Scheduling Strategy and overcommitment
- The nova scheduler is highly configurable and customizable 
- Other than spread the load you can implement other modes, for instance if you have windows vm, you pay the license for the hw server, so you need to minimize the number of server with windows vm
- The scheduler performs an initial filtering phase in which not suitable hosts are removed (they don’t have a specific characteristic like a passed through device or they are out of resources), then an ordering of the hosts 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260417164350.png|300]]

- Cloud providers want to maximize revenue, to do so we need to pack as many vm as possible on the minimum number of server
- This could lead to a lower performance if all vm request for resources at the same time, and this could lead to a bad user experience 
- If all users request resource at the same time is called hotspot

- You need to find a tradeoff between user experience and revenue, to measure this there is a measure called **over commitment**, the ratio between physical device in which will empower the virtual counterparts
- It tells how much virtual resource you want to create out of one real resource

- At maximum we can use a cpu to create 16 virtual cpu, with a over commitment of 1 you will have a virtual cpu for each real cpu
- you usually use high values 

- Over commitment for ram is usually much lower, between 1.5 because page faults slower the program a lot

- It is very important to tune all the over commitment values



### Glance
- VMs are usually instantiated via an image because some of them can be pre-configured and so ready to be used
- **Glance** is the *image management service* 

- Each VM is instantiated from an image which includes a specific operating system pre-installed and pre-configured 
- Images can be customized, e.g. a web server image can have pre-installed a web server package 
- Glance manages the collection of VM templates 

- Glance subcomponents are: *glance* (for image management) and *glance storage* (for storage management) 
	- **Glance** is responsible for exposing a REST API for managing the images (e.g. uploading an image, delete an image, etc) and store the list of the images available and its features on the DB 
	- **Glance storage**, instead, is responsible for storing the images. It supports different storage options via different drivers
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260417164542.png|300]]



### Neutron
- **Neutron** si the *network management component*
- VMs require a virtual network to communicate each other
- Different Virtual Networks are instantiated for different VMs in order to ensure isolation among them, i.e. VMs created by different tenants cannot communicate 
- Neutron is the service responsible for managing the virtual network infrastructure, it allows the *creation of Virtual Networks* among VMs that can run on different Openstack compute nodes 
- The Local Physical Network that interconnects Computing nodes is exploited as infrastructure to enable the virtual networks across different compute nodes
- It implement some networks virtualization technologies that allow to create virtual network on top of some physical networks 
- Green VMs comunicate only with the other green vms (da scrivere meglio)
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260418102022.png]]

##### Neutro Subcomponents
- Neutron subcomponents are:
  - neutron-server
  - neutro-agent


- **Neutron-Server**: it is installed on the controller and it is responsible for managing the Virtual Networks by coordinating the neutron-agents running on the computing nodes. It is also responsible for exposing the REST APIs for the management of Virtual Networks to users 

- **Neutron-Agent**: it is responsible for managing the traffic to/from VMs running on the compute node on which it is installed. Specifically, it dispatches the traffic directed to/generated from the local VMs in order to emulates different virtual networks that span across different compute nodes. Data is dispatched on top of the local physical network. The agent must enforce isolation between different Virtual Networks

- blue packet are control data, red and green are reserved for the two different virtual networks
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260418102158.png]]


##### Network Node
- Virtual Networks are usually private networks 
- Neutron allows VMs to be connected to external networks, so VMs can connect to the Internet and vice-versa they can be accessible from the Internet 
- In order to connect Virtual Networks to the Internet, a **Network Node** must be instantiated

- A Network Node is a node (usually the *controller node*, but can be instantiated on a dedicated node) that is connected to an external network (towards the Internet) in addition to the local network that connects the OpenStack nodes 
- This node runs a particular agent, named **Neutron-L3-Agent** that is responsible for rerouting traffic from/to the private Virtual Networks to/from the public networks 
- This functionality is performed by instantiating *Virtual Routers*, which are responsible for implementing traffic routing and NAT functionalities, it route traffic from public network to network node, and from viceversa
- In addition to this, the Network Node also hosts a module named *Neutron-DHCP-Agent*, which is responsible for managing the network configuration assignment to VMs. It set things like ip and dns address 


![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260418102350.png]]

- Neutron allow to create virtual networks, each vm is connected to at least one virtual network, each virtual network is connected to at least one router
- Public IP addresses can be assigned to VMs
- Virtual Routers at the edge of each Virtual  Network will take care of  implementing Network  Address Translation  
- The platform allows to  assign public IP  addresses dynamically  (*floating IP address*: expose a vm to public network assigning to it a public ip)
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260418102448.png|500]]

##### Physical Network Infrastructure
- A typical OpenStack network infrastructure connected to an external network is usually configured with three different physical networks: 
  - A management network, exploited for OpenStack services communication 
  - A VM internal network (the physical network), exploited to dispatch the internal communication among different VMs 
  - An external network for Internet access 

- The internal physical network is used as the fabric to construct the virtual networks
- We divide the physical in different virtual network, by tagging the packets to tell at which virtual network they belong (e.g. the red or green network)

- The management network and the VM internal network can be implemented on the same physical LAN, i.e. OpenStack management traffic and internal VM traffic can be transmitted on the same LAN
- Is used to transmit command and requests
- Only one node, the Network Node, must be connected on the external network 
- The controller node can be connected only to the management network 

- It is possible to use the same physical network for both the internal network and the management network

- The external network is an external connection to an external network (the internet)
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260418103020.png|400]]



### Neutron Agent

- *How do we implement the tagging of packet to isolate communication from the different virtual network (so only the green vm, can read green packet)?* This is done by the network agent

- The **Neutron Agent** running on each compute node is highly configurable, different configurations are possible exploiting different technologies to process and forward traffic 
- One of the last version exploits *OpenVSwitch* to implement the local network functionalities to process and forward traffic between compute nodes and the network node 
- OpenVSwitch allows to rapidly reconfigure the behavior of each agent following the directives from the nova server
- It implement the *Networking Route* for each packet
- It interacts with OpenVSwitch that allow to reconfigure and change the behavior of nova 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260418103035.png|400]]



### OpenVSwitch
- **OpenVSwitch** (**OVS**) is an open-source implementation of a *distributed network virtual switch* 
- It is specifically designed to provide a switching stack for hardware virtualization environments, it can run directly within (or jointly with) the hypervisor to manage the traffic to/from VMs 
- It supports the implementation of packet filtering, routing, switching and manipulation functionalities 
- OVS adopts a centralized approach (**SDN**): every node has its own OVS instance, which is controlled by a controller
- Following the directives of the controller, all the OVS instances implements a distributed virtual switch 

- It is a component that manage traffic following a set of rules received by a controller, can implement any rule and network functionalities
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260418103304.png|300s]]


### Software Defined Networking (SDN)
- *OVS* adopt the **SDN paradigm**: network rules are configured dynamically on each instance based on the directives coming from a centralized controller 
- Each OVS node has a table (the *flow table*) that describes the features of any incoming packet (e.g. the source IP, the destination MAC address, etc.) and the corresponding action to be executed (e.g. forward the packet, modify the packet, etc.) 
- Whenever a packet is received, the table is accessed, if the packet has a match with one of the entry in the table the corresponding action is executed 
- If no match is found, OVS sends a query message to the controller, which replies with a new rule to be added in the local table or a specific action to be performed once 
- The protocol that implements the communication between OVS instances and the controller is named *OpenFlow*


- Switch implement rules via sw, which rules is implemented depend on the current configuration, they are dumb component that execute what they are told to do 
- packet flow in, they are analyzed by a table with a set of rules, the rules tells to which packet a rule must be applied (*Flow Table*), and if there is a match we implement the corresponding action (*Execution Action*) and the packet can continue its route, the flow table and the execution action are part of the **switch** 
- usually the controller is who tells the switch what to do 

-INSERISCI L'IMMAGINE

### VM – OVS communication
- Each VM has a **Virtual NIC** (Network Interface Card, a device that allow to a system to connect to a network), whose hardware is emulated by the hypervisor 
- In order to connect with the OVS instance of the computing node, the *vNIC* is linked to another virtual NIC created in the host operating system, e.g. tap0, tap1 
- A **tap** is a virtual network interface that can be linked with a software, the hypervisor in this case, to receive/send network traffic (layer 2 data frames) to from the software 
- The tap is used to receive/send data traffic from/to the VM 
- Traffic from tap interfaces of from the physical interfaces is managed by OVS to implement routing and forwarding functionalities 

- we have two Virtual Network Adapter for each VM, vNIC and tap
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260418103622.png|300]]



### Network Node
- OVS instances can be programmed by the *Neutron Server* to dispatch the data across different VMs running on the same compute node or on different compute nodes 
- When the data is directed towards an external network, instead, it is dispatched to the network node 
- In order to implement L3 routing functionalities and data dispatching, an OVS instance is also installed on the network node 
- Through the OVS instance running on the network node, L3 virtual routing functionalities are implemented to route traffic to/from the external network and the VMs (or in general the local Virtual Networks) 

- is the one that choose the rules to forward to the switch, but it also interconnect virtual networks with external networks
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260418103859.png|400]]



### Network Virtualization
- *But how do we tag each packet with a different color and recognize to which network they belong?*

- **Network Virtualization** is the process through which different Virtual Networks (VNs) for VMs are created on top of the same physical infrastructure  

- VNs are Layer2 networks, specifically Ethernet networks 
- The implementation of a Virtual Network requires the following: 
  - Layer 2 data forwarding between VMs belonging to the same VN 
  - Isolation between VNs, i.e. two VMs belonging to different VNs cannot communicate, unless there is a *router connecting* at Layer 3 the two VNs 

- In OpenStack, Network Virtualization requires that traffic is forwarded across different compute nodes and to/from the network node according to VN existence, i.e. if two compute nodes host two VMs belonging to the same VN the network service should be configured to forward traffic between them 
- To this aim each packet should be marked with the ID of the VN to which it belongs so it can be properly dispatched 
- Different existing network technologies are adopted: *packet tagging* or *tunneling* 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260418104116.png|400]]


### Virtual LAN
- **VLAN** is one of the most widely adopted for network virtualization 
- The IEEE 802.1Q Ethernet networking standard was defined specifically to allow the creation of Virtual LANs on top of a regular Ethernet network 
- To this aim, the standard adds a new field on the Ethernet header, the *VLAN ID* (*VID*), that specifies the ID of the Virtual LAN to which it belongs 
- A switch (virtual of physical) that supports IEEE 802.1Q is responsible for adding the VID field when a packet is injected in the network, for removing it when it reaches destination and for delivering it according to the VID 
- For instance, broadcast frames must be delivered only to hosts belonging to the same VID, to guarantee isolation

- This technique allow to create layer 2 virtual network on top of a physical one
- It add the VID that contain an integer associated to one virtual network, when a frame with this field enter a switch it is forwarded only to host connected with that Virtual lan ID

### Neutron VLAN Operations  
- Neutron can be configured to use VLAN to create VNs 
- When a VN is created to connect two or more VMs, a VID is assigned to the VN by the *Nova-Server* 
- The latter configures the OVS of the compute nodes involved consequently, in order to tag traffic coming from a VM with the VID assigned to its VN and to forward packets to all compute nodes involved 
- When a packet is received by a compute node, the VID is removed and the packet is forwarded to all the VMs involved 
- In case the VN is connected to the Internet via a Virtual Router, the Neutron-Server configures also the OVS running on the Network Node to tag the packets coming from/directed to the Router assigned to the VN   
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260418104911.png|400]]



### GRE Tunneling  
- Is another virtualization technique that operate to a different level than VLAN 
- The gre encapsulation is used to create tunnel among compute nodes, so two nodes hosting vm that belongs to the same VN, create a gre tunnel, each tunnel have a gre tunnel id that is used to route packet 
- A packet is forwarded to each node to all nodes that has at least one node connected to the tunnel

- Another virtualization mechanisms adopted is *packet tunneling via GRE* protocol 
- **Generic Routing Encapsulation** (**GRE**) is a tunneling protocol that allows to encapsulate network IP packets inside another IP packet 
- The protocol is used to create a tunnel between two hosts 
- The protocol adds an additional *GRE header* to specify the type of the encapsulated protocol 
- GRE can be used as mechanism to create Virtual Networks: a GRE tunnel is created for each pair of compute nodes (and between the compute node and the network node) that runs VMs belonging to a specific virtual network 
- Different GRE tunnel IDs are used for each Virtual Network 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260418105308.png|400]]


##### Neutron GRE Operations  
- GRE can be used to create VNs 
- For each VN a *GRE ID* is instantiated by the Nova Server 
- The latter instructs the OVS instances to create a virtual network adapter (gre-1) on top of the physical interface 
- The GRE interface is responsible for creating the tunnel across the involved computing nodes (nodes that have at least one VM that belongs to the VN, or computing nodes and the Network Server) and encapsulate/decapsulate the traffic 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260418105356.png|500]]



### VXLAN  
- Is the third technique other than VLAN and GRE


- VLAN has a limit, VLAN identifiers are 12 bits long, consequently the maximum number of VLANs is set to *4094*
- In large cloud implementations this number, even if high, can be an issue
- **Virtual Extensible LAN** (**VXLAN**) is a network virtualization technology that attempts to address the scalability problems associated with large cloud computing deployments in order to remove this limit 
- With VXLAN you can have up to 16 millions of different VNs 

- VXLAN is still a *packet encapsulation methodology* between two endpoints, called **Virtual tunnel endpoints** (**VTE**) in this case
- Frames are encapsulated within UDP packets, while at the IP level the source and destination of the VTEs are specified 
- A *VXLAN header* is included to report the ID of the virtual LAN as two VTEs can support multiple VLANs at the same time 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260418105801.png|400]]


##### Neutron VXLAN Operations  
- VXLAN tunnels are exploited by neutron in the same manner GRE tunnels are exploited 
- For each VN a new *VXLAN ID* is instantiated by the Nova Server 
- The latter instructs the OVS instances to encapsulate packets into VXLANs tunnels according to the VNs instantiation  
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260418105910.png|400]]

### Cinder  
- **Cinder** is the component responsible for *managing volumes* (is a virtual hd that can store the os or some data)
- Each VM has a default **virtual hard drive** which stores the operating system 
- If a VM requires extra storage additional volumes can be dynamically created and attached to an instance 
- Such volumes are seen as virtual hard drives by the VM 
- Eventually, a virtual hard drive is stored in the file system as an image (a file or an object) 
- Cinder is responsible for managing those images and exposing them to the VMs 
- A virtual hard drive is exposed by the hypervisor, which accesses the actual virtual hard drive via the *iSCSI protocol  
- **iSCSI** is an Internet Protocol based storage networking standard which provide block-level access to the storage 
- Cinder stores the volume images in the local file system of the node on which the service is installed or in a **cloud file system**
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260418105952.png|400]]

##### Cinder - Architecture  
- Cinder comprises the following components:
  - **Cinder-Api**, which exposes a rest interface to clients to control cinder operations 
  - **Cinder-Volume**, which is responsible for handling directly the requests from the rest interface 
  - **Cinder-Scheduler**, which is responsible for selecting the proper storage to store new drives 
  - **Cinder-Backup**, which is responsible for creating backup of existing volumes when requested by the users
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260418110257.png|400]]

### Ceilometer  
- **Ceilometer** is the *telemetry component*
- It monitors all the component of the instance, **measuring the resource being used** by each User 
- Data collected by Ceilometer can be used for **billing purposes** 
- Ceilometer also collects **telemetry statistics** which can be used to check the status of the system 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260418110410.png|400]]


### Ceilometer - Architecture  
- **Ceilometer** has a centralized *Ceilometer-Collector* that is responsible for receiving all the data from all the OpenStack components and store them into a *DB* (usually a NoSQL DB like Mongo DB) 
- In order to collect data from all the compute node, a **Ceilometer-Agent** is installed on each node. The agent is responsible for collecting all the notifications from all the local components and forward them to the collector 
- Eventually the collector exposes a set of REST APIs to retrieve the data from the database 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260418110425.png|400]]


### Horizon  
- OpenStack functionalities are exposed to Users though a **web interface** by a component called *Horizon*
- The dashboard is usually exposed by the controller 
- It allows management of all the instances aspects 
- A set of command line tools are also included for backend management ![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260418110728.png|500]]


### Service APIs  
- Every OpenStack **service exposes a set of APIs** 
- All APIs communication is REST 
- APIs are exposed by each service for inter-service interaction and to expose a set of functionalities to Users 
- APIs can be exploited by Users to embed automation process in external applications  
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260418110835.png|300]]


### Swift
- **Swift** is the *object storage service* available in OpenStack 
- It allows users and other OpenStack modules to store data (represented as objects) in the cloud platform 
- Other services, like for instance Cinder or Glance, can use Swift to store Volumes backups or images, respectively 
- The component is responsible for handling all the aspect of data storage, from receiving and storing the data to retrieving it 
- Data is usually eventually stored in a ***cloud storage***, to guarantee scalability (even though local storage in the server where the service is installed is allowed) 

- Swift is composed of two components: 
  - **Swift-Proxy**, which is responsible to expose the REST interface and handle request (to store a new object or to retrieve an object) 
  - **Swift-Storage-Node**, which is installed on each Storage Node (a node that hosts some of the data) to actually store the data on a physical drive
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260418110957.png|300]]


### Heat  
- **Heat** is the *OpenStack orchestrator* 
- It can manage VMs creation/destruction or their settings automatically
- This automation is based on a set of rules that specify when certain conditions to trigger actions on the VM 
- Through heat, for instance, an autoscaling service can be created that exploit the status data from ceilometer to create/destroy VMs according to the status of the system 

- The component is composed of the following modules:
  - **Heat-API** that exposes the interface for the users to configure the orchestrator 
  - **Heat-Engine** that is responsible for handling user request and implementing them  
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260418111006.png|400]]

### OpenStack Service Interactions Summary
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260418110901.png]]

- In the simplest OpenStack installation each component is instantiated only one time, but in this way we have multiple single points of failure, it is also possible to have an high availability configuration

##### High Availability (HA)  
- The current architecture includes only one instance of the managing components 
- OpenStack can be installed in the so-called *high availability configuration*, i.e. multiple instances of each service can be deployed in order to ensure high availability and resiliency 
- This can be performed in a similar manner cloud applications are deployed in a redundant manner to ensure high availability 
- In the high availability configuration, multiple instances of controller nodes are deployed with all the corresponding services to control the same set of computing nodes  

##### HA with dedicated node  
- Overall OpenStack APIs are exposed not directly by the controller node but through a *HA proxy*  
- The **HA proxy** is responsible for receiving the requests and dispatch them to one of the controller nodes 
- The proxy must implement functionalities to detect when Controller node failures occur to remove failing controller node to the list of active nodes 
- The State storage must be replicated across the controller nodes 

##### HA with simple redundancy  
- Overall OpenStack APIs are exposed directly by one controller, selected as *master controller* 
- The functionalities of the HA proxy are implemented on all the controller, one of them is marked as active and serves requests, while the others are marked as inactive 
- The HA proxy instances must coordinate to detect failures and trigger reconfiguration when needed 
- Again, the State storage must be replicated across the controller nodes




# 0D4. Lightweight IaaS DevOps  

### Software development IN THE PAST
- Some years back, most software applications were big monoliths, running as a single process or a small number of processes 
- They have slow-release cycles and are updated infrequently since the development is complex and unpractical. Developers usually package up the whole system and hand it over to the ops team, the team of system administrators responsible for managing the infrastructures (the servers)
- Changes to one part of the application could requires a redeployment of the whole application (cascade effect)
- Over time the lack of boundaries between the software components increased the complexity of the development and maintenance, thus deteriorating the quality of the whole application 
- Monolithic applications usually requires a small number of power servers 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260418114301.png|100]]
##### Legacy Systems
- Those systems, named *legacy systems*, are still up and running today (even though they are slowly replaced) 
- If convenient they are cloudified, it means that physical servers are replaced by VMs 
- This process simplify the maintenance of the infrastructure, the software development process and maintenance is still complex 
- When the application has to deal with an increasing load, resources are added to the servers, i.e. vertical scalability is adopted, as it does not require modification to the original architecture of the application
- Vertical scaling, however, has limits and it is not always feasible


### Software development NOW
- Cloud computing radically changed the way software applications are developed and deployed 
- Big monolithic legacy applications are now *broken down into independent components*, named services or microservices 
- Services are decoupled from each other, and they can be developed, deployed, updated and scaled individually
- Each service/microservice runs as an independent process and communicates with the others via well-defined interfaces 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260418114320.png|200]]



### Service independency
- This structure enables a *more rapid application lifecycle*: components can be changed quickly and easily, as often as necessary to keep up with rapidly changing business requirements 
- Services communicate through synchronous protocols (e.g. SOAP, HTTP/RESTful) or asynchronously via message exchange (e.g. message queue). Such protocols are simple and well known by developers
- Services can be developed separately, a change in one does not require changes or the redeployment of other services (provided that the interface does not change)

 
### Application development process
- This new architecture also changed the whole application development process and, in particular, how applications are managed and deployed in production 
- In the past, the application lifecycle was managed by two different (usually separated teams): 
  - **The development team** (*dev team*), whose task was to design and program the applications software 
  - **The operations team** (*ops team*), which took care of deploying and maintaining the application 

- We used to use different team because them have different expertise 
- Now organizations are adopting a different approach: the same team that develops the application also take part in its deployment and its maintenance for its whole lifetime. This approach is called **DevOps**

### DevOps
- The main advantage of this approach is to have developers more involved in running the application in production 
- This leads to a better understanding of both the users’ needs and issues and also the problems in deploying the application 
- The deployment process is streamlined, it means that releases can be performed more often: ideally you can have developers deploying their application themselves without having the ops team involved 
- Such practice, however, requires developers to have a deep knowledge of the details of the underlying infrastructure, which is not always feasible or desirable

### NoOps
- Even though developers and system administrators work towards achieving the same goal, they usually have different background, experiences and motivations 
- Even if the *DevOps* model is considered a target for its advantages, its implementation is hard as the members of the dev team hardly have the background and experience to take care of the infrastructure 
- An ideal solution would be to put in practice a **NoOps** approach, in which developers deploy applications themselves without knowing anything about the infrastructure and without having to deal with the peculiarities of deploying an application 
- *A solution to enable automatic service deployment and maintenance would make feasible to implement a DevOps or NoOps approach*
- You would still need to have a ops team to manage the infrastructure, but developers would be allowed to deploy their software easily
- The ops team is not remove, they create and maintain the infrastructure used by the dev team used to automatically deploy the sw

### Service deployment and management
- Regardless of the knowledge required for application deployment and management, a service based architecture has other drawbacks 
- When an application consists of a small number of components, their management is simple 
- When the number of components increases, the complexity of deployment operations increases 
- Manual configuration and deployment is tedious, error prone and unfeasible when the number of services reaches a certain number 
- *A solution to automate the deployment and configuration of components is required to manage large applications with a large number of services*

### Service Dependencies
- As mentioned, services are developed as separate components independently by different teams 
- Due to their independence, it is common to have different teams using different libraries 
- Each team select their own library, when the same library is the same it might happen that different versions are selected 
- In addition to this, different teams want to have the freedom to replace the library whenever the need arises 
- Deploying different services/application with crossed dependencies can be a nightmare for the ops team 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260418114620.png|400]]

### Consistent Application Environment
- Regardless of the number of individual components, one of the biggest problems that developers and operations teams have is to deal with the differences in the environment they run the applications 
- A method to simplify such operations is to deploy applications in an ideal confined environment where all the libraries are pre-installed and the real hardware on which the software is running is somehow abstracted 
- This environment can be created through full virtualization, i.e. running he software in a VM 
- This solution, however, is expensive as full virtualization has a significant overhead (virtualization itself, guest OS, etc) 
- In addition to this, using VMs has an overhead in terms of configuring the VM and its guest OS by configuring it and by installing the proper libraries


## Lightweight Virtualization

- **Lightweight virtualization mechanisms**, like containers, *can be a solution to the high overhead required by full virtualization*

- Containers can be used to prepare a virtualized environment in which libraries and dependencies are pre-installed and configured to run a certain application or a service, which is part of an application 
- In addition, containers can be easily shipped and installed on different machines using ad-hoc distribution systems that take care of distributing and installing images on different machines

 - An example of this is Docker 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260418114632.png|400]]


### Kubernetes
- Docker simplify the deployment, but is not automated 

- **Kubernetes** is a software systems developed by google that allows to easily deploy and manage containerized applications on top of it (il allow to *automatize the deployment* of an application)
- A containerized application is an application whose components (independent services) are deployed and shipped as different containers 
- Kubernetes aims at simplifying completely the overall process of deploying and managing the containers composing the application, taking care of aspects regarding scalability, failure tolerance, resource management, etc. 
- The goal is to offer a *lightweight IaaS infrastructure to deploy applications in a simple and effective manner*, so developers can take care of it without having to deal many of the aspects 
- The operation team is still required, in this case, however their roles changes, they are responsible to maintain and run the Kubernetes infrastructure 

### Kubernetes Core Operations
- Kubernetes is a *distributed platform* that is composed of a **master** node and a varying number of **worker** nodes  
- Its architecture is similar to *OpenStack* 
- Kubernetes nodes can be installed directly on the physical servers or they can be installed on a cloud platform on top of VMs (this is the most used installation)
- Kubernetes master node exposes an interface to developers, which can request to execute a specific application
- The worker node instead host the containerized components
- The developer has to submit an **app descriptor** (a configuration file) which only includes the list of components that compose the app 
- For each component the configuration is specified 
- The Kubernetes master takes care of deploying the app components on the worker nodes according to the description provided by the developer in a complete automatic manner
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260418114644.png|600]]

- Through the interface the developer can specify that certain services *must run together* consequently they are developed on the same working node (the components that must run together are called **pod**) 
- Others will be spread around the cluster according to the status of each working node

- In addition to the configuration of each component the developer must specify the *desired number of instances* in order to ensure scalability
- The platform will take care of replicating each component and load-balance the traffic among them in order to ensure scalability 
- The platform takes care of monitoring the status of each component and handle failures: in case one instance fails (or fails the working node on which it is executed) the platform takes care of *replacing the instance* with a new one

##### Advantages
- Kubernetes relieves applications developers from having to implement infrastructure-related functionalities into their applications 
- The platform takes care of implementing functionalities like scaling, load-balancing, self-healing
- Consequently application developers can focus on developing applications without wasting time figuring out how to integrate the application within the infrastructure
- The duties of the ops team are simplified: they are relieved from taking care of deploying the components, configuring them and fix failures, as all those functionalities are handled by the platform itself 
- In addition to this Kubernetes can achieve a better utilization of the resources available in the infrastructure

### Cluster Architecture
- The *master node* implements the **control plane**, which is responsible for controlling the cluster. Each component of the control plane can be installed on a single master node, can be split across multiple nodes or they can be replicated in order to ensure high availability.
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260418114655.png]]

### Cluster Architecture
- The *master node* (control plane) is composed by the following components: 
  - **API server**, which exposes an interface for developers 
  - **Scheduler**, which schedules apps
  - **Controller manager**, which performs cluster-level functions such as replicating components and handling node failures 
  - **Etcd**, which is a reliable distributed data store 

- The *worker nodes* instead include the following components: 
  - **Container runtime**, a container runtime environment (like Docker or others) that takes care of running the containers 
  - **Kublet**, which talks with the API server and manages containers on the node 
  - **Kubernetes Service Proxy**, which takes care of balancing the network traffic between application components and forward requests, while containers are migrated across working nodes 

### Application Deployment
- The *application description* provided by the developer lists the container that composes the application 
- Containers are grouped together into *pods* 
- A **pod** is a group of containers that must run on the same worker nodes, in other words they must be deployed together and shouldn’t be isolated (a pod can be one container) 
- A pod is a base components of Kubernetes, *everything is a pod*, even one single container is a pod
- For each pod/single container the developer specifies the configuration (e.g. from which image it must be instantiated) and the number of replicas to be deployed 
- The worker nodes are connected with a virtual network to allow components to comunicate 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260418114703.png]]

- After submitting the descriptor to the control plane of the master node, the scheduler schedules the specified number of replicas of pods to the available worker nodes 
- The *kublets* running on the worker node takes care of controlling Docker to pull the container images from the repository and run them  


### Management and Maintenance
- Once the application is running, Kubernetes continuously makes sure that the deployed state of the application always matches the description provided by developers
- If one or more instance stops working properly (e.g. the application crashes) Kubernetes will take care of *restarting it*  
- If the instance, or a whole working node, becomes inaccessible, Kubernetes will select a new node for all the containers that were running on the node 
- While the application is running the developer can decide to increase/decrease the number of instances, in this case the platform can take care of adding/removing instances at runtime 
- The developer can even let the platform decide the optimal number of instances of a certain container, in this case the platform will adjust the number of running instances based on real-time metrics like CPU load, memory consumption, query per second, etc.


### Container Migration
- The platform automatically takes care of instantiating containers and migrating them when required (e.g. when a working node fails) 
- When a container provides a service to external client, the platform has to take care of forwarding requests as the container is moved across the platform 
- What it is usually performed is that the platform exposes a specific service with a single public IP address, regardless of the number of containers and their location 
- The platform with the *kube-proxy component* takes care of connecting to the containers and forwarding the traffic in a proper manner 
- In addition, the component takes care of implementing load-balancing policies to forward the traffic in a balanced manner in order to ensure scalability



### Exposing Applications
- Pods are connected to a local private networks, in order to allow communication among them 
- Each pod gets its own IP address, however, this address is internal to this network and it is not accessible from outside 
- Such local private network allows the communication among containers running on the same or different workers 
- If a service needs to be exposed to external networks (e.g. because it exposes the web or the REST API interface of the application) the developer needs to *define a* **service object** 
- A *service object* instructs the platform to associate with a pod an external IP address and port so that the service exposed by the pod can be reached from external hosts 
- The service takes care of forwarding the request coming to that external IP address to the local IP address of one of the associated pod instances 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260418114717.png]]



### Load Balancing
- A service can be connected to a pod that requires multiple redundant instances for load balancing 
- In this case the service spreads the requests across the different instances 
- To each pod the platform associates a replication controller for taking care that the proper number of instances is always running
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260418114722.png]]


### Failure handling
- The replication controller is also responsible for monitoring the instances of a pod to detect failures 
- If the failure of a working node is detected, the replication controller detects it and react by creating a new pod instance
 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260418114727.png]]


### Pod design
- The general rule to group containers into pods is that developers should always run containers in separate pods unless a specific reason requires them to be part of the same pod, so they are deployed on the same working node 
- For instance an application might have latency requirement in the data exchange between two container, in this case it is convenient to group them in the same pod so they do not communicate over the network
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260418114733.png]]



# 0E1. Cloud Storage
### Storage Technology Evolution
- In the last decade storage technologies have evolved at an accelerated pace: the volume of data stored and the access speed have increased tremendously 
- Hard Disk technologies, in particular, has evolved providing significant more capacity and performance 
- Their capacity evolved from Megabytes to Terabytes with a significant reduction in costs 
- The transition to the Solid State Drive (SSD) technology allowed to remove moving parts from Hard Drives thus ensuring a significant reduction in data access time, from hundreds milliseconds to tens milliseconds 

### Block storage and File System
- The simplest type of storage that can be implemented with a hard drive is **block storage**, the possibility of store a *continuous blocks of raw unstructured data* 
- A **block**, often referred as physical record, is a sequence of bytes or bits, blocks can directly stored on the physical sector of the hard drive 
- It is the simplest file system that you can have, so it usually not used directly, but you use something on top of it
- On top of a set of blocks, a file system is usually created: the **file system** organizes the data into files and manages the metadata required to store files on different blocks (the file system is an *abstraction* for human to use a block storage)
- A file system is usually adopted by OS to store user’s and systems’ files
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260418115334.png]]


### Object storage
- Recently a new storage type has been created, the **object storage**
- **Objects** are bundled data (for instance a file) with the corresponding metadata 
- Each object has associated a *unique ID*, that is calculated based on the file content and meta-data 
- Applications can access the object via its ID, the set of metadata is not defined a-priori and can be extended 
- **Each object is immutable** (once a object is created it cannot be modified), a change produces another version that is stored as a new object (an incremental change system can be introduce to minimize data replication in the system)
- Having immutable object make super easy to manage object and big quantity of object (e.g. for ML applications)
- You can save new versions of an object as a sequence of objects with all the versions

### Comparison
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260418115340.png]]

### Single Server Storage Model
- The storage of the traditional computing model is composed of one or more hard drives connected to one server 
- Hard Drives can fail, their lifespan depends on the load, on average they have an expectancy of approximately 5 years 
- In order to handle *failure on a single server* the **RAID technology** is employed, to ensure replica and fault tolerance 
- The maximum storage is limited to the physical number of bays (hard drives slots) of the server 
- In order to overcome this physical limitation ***distributed file systems*** are employed
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260418115348.png]]



### RAID
- **RAID** (*Redundant Array of Independent Disks*) is a technology for single server storage systems, that combines multiple physical hard drives into one or more *logical hard drive* (virtual) 
- Different RAID schema are possible depending on the purpose: data redundancy, performance improvement, or both 

- RAID functionalities can be implemented in hardware (through a *RAID controller* to which the hard drives are connected) or via software 
- In the former, the **RAID controller** takes care of managing the hard drivers, consequently RAID functionalities are hidden from the OS, which access only to the logical hard drive 
- In the latter, RAID functionalities are implemented by the OS which manages access to the physical hard drives and the creation of the logical unit

- so it can be implemented via hw (by the RAID controller) or sw (by the OS)


### RAID Schema
- According to the RAID schema adopted, the blocks of the logical hard drive are stored in the physical drives

- *Three schema* are popular:
  - **RAID 0**, adopted for performance, where blocks are striped across the physical hard drive for performance (because you can read and write data in parallel, so they require half of the time, but you have no redundancy)
  - **RAID 1**, adopted for maximum redundancy, where blocks are mirrored across the physical hard drives for redundancy (this require more than double of the time for write operations)
  - **RAID 5**, tradeoff between performance and redundancy, where blocks are striped across hard drives, however, a *parity block* (e.g. calculated via XOR) is added to a set of block to ensure fault tolerance, i.e. to recover the data if a failure occurs. To implement it we need at least three hard drive. It is possible to obtain A from B and p1, or B from A and p1
  - If one hd fail it is possible to recover all the data, if two or more fail it is not
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260418115353.png]]
- RAID 6: variant where parity blocks are duplicated two times 

### Distributed File System
- In order to overcome the limitations of a single server storage, **Distributed File Systems** (**DFS**) were defined 
- A DFS allows to improve server’s storage capabilities by distributing the file system over different servers 
- Data transfer and synchronization is achieved exploiting a local LAN 
- A DFS can be used to create a large file system that puts together all the storage of different servers or it can be used to enlarge the storage of a single server by extending its capacity through the storage another server that usually have large storage capacity 
- Different distributed file systems have been defined, one of the first examples (still widely adopted today) is **NFS** or **Network File System**

### NFS
- **NFS** adopts a *client-server approach*: a central server offers access to clients to its local file system 
- NFS defines a communication protocol between client and server, the messages are synchronous messages in order to ensure consistency and simplify the implementation 
- The remote file system is accessed by applications running in each client in the same manner of local files are accessed 
- All NFS functionalities are implemented inside the Linux kernel, NFS functionalities are hidden from applications 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260418115400.png]]

### GlusterFS
- Although NFS is a shared storage, its *centralized architecture* refrains its usage in practical deployments 
- Distributed alternatives are usually adopted to increase resiliency to failure and guarantee scalability exploiting storage locally available 
- **GlusterFS** is an example of *DFS* that creates a distributed file system piecing together the storage capabilities available on all nodes 
- GlusterFS can be used locally in the same way is configured NFS 
- There is no distinction between clients and server, all the nodes participate offering some of the local storage 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260418115405.png]]

##### GlusterFS – Basic Modes
- GlusterFS is highly configurable, with different levels of redundancy and replica
- Basic configuration includes: replicated volumes, distributed volumes and striped volumes (striped volumes divide data into different disk in different blocks)
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260418115419.png]]
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260418115416.png]]
### GlusterFS – Advanced Modes
- In order to meet different requirements different combination of basic modes are allowed, for instance: striped replicated and distributed replicated
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260418115425.png]]


### Cloud Storage
- Storage requirements of cloud computing platforms is different from the traditional computing model 
- Its main requirement is that the storage scales, i.e. it can scale with the amount of data that the platform has to store, for instance: 
  - It scales with the number of VMs that the platform has to handle 
  - It scales with the number and the size of the volumes created 
  - It scales with the amount of data the data generated by different service, e.g. the object storage Swift 

- Exploiting local hard drives in cloud computing platforms is feasible, the hypervisor creates virtual drives or volumes for the VMs on the local hard drive of the physical machine on which it is installed 
- Such solution, however, is not scalable as it still has the limitations of the traditional computing model

##### VM Live Migration
- In addition to this, using the *local storage* does not allows to implement **VM live migration** 
- Live Migration allows a VM to be moved dynamically from one compute node to another, while still the VM is up and running 
- Live Migration a cloud platform to move a VM minimizing the down-time and without turning the VM off Live migration *requires a shared storage*, otherwise, it needs the VM to be shut off and the virtual hard drive to be moved from the local storage of a compute node to another with significant downtime
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260418115430.png]]


### Storage Area Network
- In order to overcome this limitation a **Storage Area Network** (**SAN**) can be introduced 
- A *SAN* is a high-speed network of specific high-capacity *storage devices* 
- Those ad hoc storage devices (they are not regular servers) are connected to the servers that compose the cloud platform to provide block-level storage 
- The storage can be exploited by the platform to run its services, e.g. create VMs virtual hard drive, create volumes, etc. 
- While SAN storage devices can include tape libraries, disk-based devices are more common, they use high speed communication technologies like Fiber Channel 
- Ad hoc protocols are introduced for the communication between servers and storage devices, one of them is the **iSCSI protocol**, an IP- based storage networking standard for linking data storage facilities, which provides block-level access to storage devices by carrying SCSI commands over a TCP/IP network 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260418115436.png]]

### Software Storage Solutions
- SANs require ad-hoc hardware solutions that are complex and expensive 
- For these reasons not all cloud deployments can justify them 
- In order to overcome the need of expensive storage solutions, recently distributed storage systems have gained popularity as inexpensive alternatives to SANs 
- These solutions, inspired by the literature on DFS, have as main goal to provide a unified storage solution to offer scalable, high-performing, without single point of failure that is based on general-purpose commodity hardware 
- Among those solutions, one of the most popular at the moment is **Ceph**

### Ceph
- **Ceph** provides an enterprise-grade, robust, and highly reliable storage system on top of commodity hardware 
- At the core of Ceph there are the following features:
  - Every component must be scalable 
  - There can be no single point of failure 
  - The solution must be software-based, open source, and adaptable 
  - Ceph software should run on readily available commodity hardware 
  - Everything must self-manageable wherever possible 
  
- The result is that ceph handles by itself data replication and failure recovery, consequently there is no need anymore to employ technologies like RAID for reliability and failure handling 

##### Ceph Services
- It can be installed on regular servers to create a distributed storage system (a **Ceph cluster**) in which the capacity of all the hard drives of all the servers is made available 
- Ceph offers different storage types: *object storage*, *block storage* and *file system storage*

![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260418115444.png]]

### Ceph Architecture
- A *Ceph storage cluster* is made up of several different software services 

- Each of these service takes care of unique Ceph functionalities and it is separated from the others 
- Clients (i.e. applications or cloud services) interact with one of such components depending on the required storage service type 
- At the core of Ceph we have **RADOS** (**Reliable Autonomic Distributed** **Object Store**)
- Everything in Ceph is stored in the form of objects, and the *RADOS object store* is responsible for storing these objects, irrespective of their data type. Other storage types are created on top of this basic object storage 
- The RADOS layer makes sure that data always remains in a consistent state and is reliable. For data consistency, it performs data replication, failure detection, and recovery, as well as data migration and rebalancing across cluster nodes 
- Applications that want to access to the object storage service interacts with RADOS via **LIBRADOS**, a library that offers a native interface to RADOS available for different programming languages 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260418115450.png]]

- In order to offer clients storage services other than the object storage, additional services are created on top of LIBRADOS: 
  - **Ceph Block Device**, formerly known as *RADOS block device* (**RBD**), provides block storage, which can be mapped, formatted, and mounted just like any other disk to the server. A Ceph block device is equipped with enterprise storage features such as thin provisioning and snapshots. It can be exploited to create volumes or virtual hard drives for VMs 
  - **Ceph File System** (**CephFS**) offers a POSIX-compliant, distributed filesystem of any size. CephFS relies on Ceph MDS, *Ceph Metadata Server* (*MDS*), which keeps track of file hierarchy and stores metadata only for CephFS. A Ceph block device and RADOS gateway do not require metadata, hence they do not need a Ceph MDS daemon. 



- Core of Ceph is the RADOS layer, which provides all Ceph's features, including distributed object store 
- Functionalities like high availability, reliability, no single point of failure, self-healing are provided by implementing in the RADOS layer the *CRASH algorithm* 
- The RADOS layer functionalities are implemented in a distributed manner by the services OSD and MON 
  - **OSD**, *Ceph Object Storage Device*, is the most important building blocks in Ceph, as it takes care of storing the actual data on the physical hard disk drives of each node in the cluster handling single I/O operations on the disks. Usually, for each physical hard drive a different OSD instance is created. 
  - **MON**, *Ceph monitor*, is responsible for monitoring the health of the entire cluster. These monitor services maintain the cluster state and store critical cluster information (both status and configuration). A set of MON instances is deployed in order to ensure fault tolerance



### Ceph Object
- A **Ceph object** comprises data and metadata components that are bundled together and provided with a globally unique identifier 
- The unique identifier makes sure that there is no other object with the same object ID in the entire storage cluster, and thus guarantees object uniqueness 
- Unlike file-based storage, where files are limited by size, objects can be of enormous size along with variable-sized metadata 
- Objects are stored in *Object-based Storage Device* (**OSDs**) in a replicated fashion, which provide high availability. When the Ceph storage cluster receives data-write requests from clients, it stores the data as objects. 
- The OSD daemon then writes the data to a file in the OSD filesystem
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260418115500.png]]


### CRUSH Algorithm
- Ceph Clients and Ceph OSDs both use the **CRUSH algorithm** to efficiently compute information about *object location* 
- Through this algorithm both clients and OSDs can compute the location of an object (for write or read) independently instead of having to depend on a central lookup table 
- CRUSH provides a better data management mechanism compared to older approaches, and enables massive scale by cleanly distributing the work to all the clients and OSD daemons in the cluster 
- CRUSH uses intelligent data replication to ensure resiliency, which is better suited to hyper-scale storage

- The algorithm computes the location of an object based on the current cluster status
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260418115505.png]]

### Cluster Map
- The status of the cluster is represented through a **Cluster Map** 
- The Map can be retrieved from any MON instance includes the following information:
  - The Monitor Map contains indicates the current epoch, when the map was created, and the last time it changed 
  - The OSD Map contains the list of pools, replica sizes the list of OSDs and their status (e.g., up, in) 
  - The PG Map contains the details on each placement group such as the PG ID, the Up Set, the Acting Set, the state of the PG (e.g., active + clean) 
  - The Cluster Map contains a list of storage devices, the failure domain hierarchy (e.g., device, host, rack, row, room, etc.), and rules for traversing the hierarchy when storing data 

- A placement group determines the actual OSD (and consequently the physical hard drive) on which an object is saved



### Data Placement
- Before Ceph Clients can read or write data, they must contact a Ceph Monitor to obtain the most recent copy of the cluster map 
- Then, the client first derives the placement group by applying a hash function to the object ID 
- In order to compute the actual OSDs to save the objects the CRUSH algorithm is executed to translate the placement group on the list of OSDs based on the cluster state 
- The result is a list of ordered OSDs, a primary OSD and a set of secondary OSDs that store the object (primary OSD) and its replicas (secondary OSDs)
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260418115511.png]]


### Data Replication
- The client writes the object to the identified placement group in the primary OSD 
- Then, the primary OSD with its own copy of the CRUSH map identifies the secondary and tertiary OSDs for replication purposes 
- After that it replicates the object to the appropriate placement groups in the secondary and tertiary OSDs (as many OSDs as additional replicas) 
- Eventually it responds to the client once it has confirmed the object is stored successfully 
- With this mechanism, Ceph OSDs relieve Ceph clients from that duty, while ensuring high data availability and data safety
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260418115516.png]]


### Pools
- The Ceph storage system supports the notion of ‘**Pools**’, which are *logical partitions for storing objects* 
- Ceph Clients retrieve a Cluster Map from a Ceph Monitor, and write objects to pools 
- Different pools can be instantiated to accommodate data of different applications, which also have different requirements for instance in term of replication
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260418115528.png]]


### MON Redundancy
- A Ceph Storage Cluster can operate with a single monitor; however, this introduces a single point of failure (i.e., if the monitor goes down, Ceph Clients cannot read or write data) 
- For added reliability and fault tolerance, Ceph supports a cluster of monitors. In a cluster of monitors, latency and other faults can cause one or more monitors to fall behind the current state of the cluster. 
- Ceph must have agreement among various monitor instances regarding the state of the cluster. Ceph always uses a majority of monitors (e.g., 1, 2:3, 3:5, 4:6, etc.) and the **Paxos** algorithm to establish a consensus among the monitors about the current state of the cluster.
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260418115534.png]]


### Placement groups computation
- Each pool has a number of *placement groups*. CRUSH maps PGs to OSDs dynamically. 
- When a Ceph Client stores objects, the hash will map each object to a placement group 
- The CRUSH algorithm maps each placement group to one or more Ceph OSDs 
- This mapping is computed based on the current failure zones of the cluster, so data can be considered safe and available even if some components fail 
- In addition to this, groups are mapped in order to ensure proper data balancing across OSDs, proportionally to the physical disk size of each one 


- The definition of failure zones does not only take into account different hard drives and different servers but it can be modified in order to include other factors like the network infrastructure or the architecture of the power supply system
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260418115539.png]]


### Recovering and Rebalancing
- Mapping objects to placement groups creates a layer of indirection between the Ceph OSD Daemon and the Ceph Client 
- This layer of indirection between the Ceph OSDs and the Ceph Client allows the Ceph Storage Cluster to grow (or shrink) and rebalance where it stores objects dynamically, for instance due to failures
- For instance, when you add a Ceph OSD Daemon to a Ceph Storage Cluster, the cluster map gets updated with the new OSD and consequently all the mapping of the placement groups 
- This changes the object placement, thus resulting in rebalancing, i.e. movement of data across different OSDs to ensure proper balance across OSDs
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260418115543.png]]


### Caph and OpenStack
- Many OpenStack services can exploit Ceph as cloud storage technology, for instance:
  - *Cinder* can exploit Ceph to store VM volumes, in this case Ceph block storage is exploited 
  - *Swift* can exploit Ceph to store the its objects by using the default object storage service 
  - *Ceilometer* can use Ceph to store telemetry data 
  - *Glance* can use Ceph to store OS templates for Instance creation 
  - *Nova* can use Ceph to store VM virtual hard drives

![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260418115549.png]]

### Storage as a Service
- Among the services offered by cloud provider one of them is the **Storage as a Service** (**STaaS**) 
- This service offers access to cloud storage capabilities over the Internet •
- In other words they offer access to their cloud storage infrastructure 
- Often STaaS services adopts the Object storage model, they exposes a REST interface to store/read objects 
- This can be used for backup or long term storage of large data 
- One example is the *Swift OpenStack* service that can be used to expose a Ceph cloud storage for instance 
- AWS exposes a large set of cloud storage services, from S3 storage (similar so Swift) or AWS Glacier (for cheap long term storage) 