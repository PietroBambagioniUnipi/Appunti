# 0 Introduction
- The evolution of database (the 3 big revolution):
  1) First type of database, Hierarchical Database
  2) Relational database
  3) NoSQL database
  ![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250922211923.png|400]]`

##### ACID and BASE property
- ACID properties are used in RDBMS (Relational Data-Base Management System)
- BASE properties are used in many NOSQL system
- NOSQL (Not Only SQL) database include also relational database

- *ACID*:
  - **Atomicity**: each transaction is "*all or nothing*", if one part fails, the entire transaction is rolled back, it is impossible to have partial transaction, or the transaction is made all, or it isn't made
  - **Consistency**: transactions bring the database from *one valid state to another*, you can't execute a transaction that doesn't respect the rules and constraints
  - **Isolation**: concurrent transaction do not interfere with each other, results are as if all the transactions were executed sequentially
  - **Durability**: once a transaction is committed, its effects persist even in case of a crash or a power failure 

- ACID ensures **strong guarantees** of *correctness*, *integrity*, and *reliability*.


- *BASE*:
  - **Basically Available**: the system give always a result, even if it doesn't know the result to a query
  - **Soft State**: if you have any type of record, the information in it can change also if no input operation are made on it
  - **Eventually Consistent**: the system does not guarantee immediate consistency, but data will become consistent over time (eventually, so at some point in time)

- BASE sacrifices strict guarantees in favor of **scalability and performance**, especially in distributed systems.



- **Key-Value Database**: stores data as simple pairs of key and value, like a dictionary or a hash map, fast lookups when the key is known
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250922212334.png]]


- **Document Databases**: stores data as documents (usually JSON, BSON or XML), has a flexible schema, each document can have different fields (e.g. MongoDB)
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250922212349.png]]


- **Column Databases**: organize data in tables with rows and columns, optimized for large distributed storages, columns are grouped into families, making queries more efficient (e.g. Apache Cassandra)
- columnar database are more efficient because store information on the same record in adjacent space on memory
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250922212412.png]]


- **Graph Databases**: store data as *nodes* and *edges*, optimized for exploring complex connections and relationships 
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250922212432.png]]


![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250928175528.png]]

- **Functional Requirements**: specify _what_ the system must do (features, behaviors, services, e.g. the user must be able to subscribe)
- **Non Functional Requirements**: specify _how_ the system must operate (performance, security, scalability, usability, e.g. the system must support up to 1000 user simultaneously connected)
- **UML Class Diagram**: is a diagram that model classes, attributes, methods and their relationships
- **UML Use Case Diagrams**: is a diagram that show system functionalities and their interactions with the actors

# 0.1 The Big Data Era
- **Big Data**: refers to *extremely large and complex datasets* that are difficult to process, store, and analyze using traditional data management tools
- Not only internet generate big data, they can also came from genomics, sensor or tracking device
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250928181216.png]]

- Big data are commonly described through the **“V” model**, which highlights its key characteristics:
  1) **Volume**: The huge amount of data generated (terabytes, petabytes, exabytes)
  2) **Velocity**: The speed at which data is produced and must be processed (e.g., real-time streaming).
  3) **Variety**: The wide range of data formats (structured, semi-structured, unstructured text, video, logs, sensors, etc.)
  4) **Veracity** (veridicita'): The uncertainty or quality issues in data (noise, inconsistencies)
  5) **Value**: The potential insights and business value extracted from analyzing data.
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250928181208.png]]

- There are also other 5 **Vs** related to Big Data:
  1) **Variability**: The inconsistency of data flows and data sources (e.g. peaks and troughs, seasonal trends, or sudden bursts of activity)
  2) **Validity**: Ensuring that the data is correct and relevant to the intended analysis (e.g. the data can be valid only for a certain period of time, for instance location)
  3) **Venue**: Where the data is generated, stored and processed (data center, cloud, user's device)
  4) **Vocabulary**: Standard and metadata used to ensure data is interpretable and meaningful
  5) **Vagueness**: Ambiguities and uncertainties in data interpretations

- but there are much more Vs


### The Main Big Data Issue
- Big data refers to any problem characteristic that represents a challenge to process it with *traditional applications*
- Big data involves data whose volume, diversity and complexity requires new techniques, algorithms and analyses to fetch, to store and to elaborate them

- **classical data elaboration algorithms cannot directly applied to Big Data**, new technology are needed for both storage and computational tasks
- we also need new paradigms for designing, implementing and experimenting for handling big data

- **Scale up** (*vertical scaling*): buy a bigger system. If the system fail everything stop to work, and there are a limit to the dimension of a certain machine, its easier to manage
- **Scale out** (*horizontal scaling*): add new machines to the system, is less expensive than scaling up, it can scale basically without any limit, but require specific software and it's more difficult to manage
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250929143906.png]]


### Distributed systems in Big Data
- We have the objective to apply an operation to all data, one machine cannot process or store all data, data is distributed in a cluster of computing nodes, it does not matter which machine execute the operation, and it does not matter if an operation is executed twice. We look for an abstraction of the complexity behind distributed system

- when dealing with distributed data is important to exploit as much as possible the **data locality**, to *avoid data transfer* between machines as much as possible, it is better to run the compute job on the node where the data resides, rather than transferring the dataset over the network.
- we use data replica for dealing with faults
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250929144533.png]]

### MapReduce
- **MapReduce**: moving computation is cheaper than moving computation and data at the same time. 

 - Main ideas:
   - Data are distributed among the nodes (distributed file system)
   - Function and operation to process data are distributed to *all* computing nodes
   - Each computing node works with the data stored in it, and only the *necessary* data is moved across the network

- It's a **Parallel Programming model**
- It exploits a *divide and conquer strategy*:
  - *divide*: partition dataset into smaller, independent chunks to be processed in parallel (**map**)
  - *conquer*: combine, merge or otherwise aggregate the results from previous step (**reduce**)
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250929145526.png]]
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250929145621.png]]

- **WordCount  Example**:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250929145654.png]]
```Python
from mrjob.job import MRJob

class MRWordCount(MRJob):
    def mapper(self, _, line):
        # divide the line in words
        for word in line.split(): # splitter
            # return (word, 1)
            yield word.lower(), 1

    def reducer(self, word, counts):
        # sum all the word occurence
        yield word, sum(counts)

if __name__ == '__main__':
    MRWordCount.run()
```

- we can have more mapper than the number of computing unity
- each input of the splitter is given to the mapper as a pair of key value
- the reducer apply the final merging


### Google architecture for Big Data
- The first architecture by google has a lot of server stored in container, each have its own disk and CPU
- The **Google file system** is used as an abstraction 
- with the distributed file system we can exploit easily the data locality 
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250929150207.png|400]]


### Hadoop 
- **Hadoop** is the first open source framework in java which offer:
  - *Distributed Storage* for Big Data
  - *Distributed Processing* for Big Data

- Hadoop **modules**:
  - **Hadoop Common**: common utilities that support the other Hadoop modules
  - **Hadoop Distributed File System** (*HDFS*)
  - **Hadoop YARN**: a framework for job scheduling and cluster resource management
  - **Hadoop MapReduce**: offer the MapReduce programming model

#### Distributed File System: HDFS
- *HDFS* is a distributed file system written in Java, that scales to clusters with *thousands of computing nodes* (each node stores part of the data in the system). 
- It's **fault tolerant** due to data replication, its designed for big files and low-cost hardware. It is also very *efficient for read and append operations*, and not so good with random update (so update in the middle of data)

- Hadoop is optimized for **one-pass batch** processing of on-disk data, it is really bad for **interactive data exploration** and **loop**, because it need to load all the data in memory again at each cycle 
- Due to a **poor inter-communication** capability and inadequacy for in-memory computation , Hadoop *is not* suitable for those applications that require *iterative and online computation*


### SPARK
- **Apache Spark** is an open source tool with enhanced **flexibility** and **efficiency** compared to Hadoop
- Allow to use *different distributed programming models*, such as MapReduce and **Pregel**, and has proved to perform **faster** than Hadoop, especially in *iterative and online application* (so it's better for loop)
- The paradigm MapReduce used by Hadoop is disk-based, on the other hand Spark employs the concept of **in-memory cluster computing** where datasets are cached in memory to reduce their access latency

#### Driver and Executor
- At high level, a *Spark* runs as a set of independent processes to the top of dataset distributed across the machines of the cluster and consist of **one driver program** and **several executors**


- The **Driver Program** is hosted in the *primary machine*, and runs the user's *main function* and *distributes* operation on the cluster by sending several units of work called tasks to the executors
- Each **Executor**, is hosted in a *secondary machine*, and runs tasks in parallel, and keeps data in memory or disk storage across them
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250929153050.png|400]]


#### SPARK RDD
- **Resilient Distributed Dataset** (*RDD*): is an abstraction used to represent data inside spark
- It's a *fault tolerant* collection of elements partitioned across the machines of the cluster that can be processed in parallel
- These collections are *resilient*, because they **can be rebuilt** if a portion of the dataset is lost
- The applications developed using the Spark framework are *totally independent of the file system* or the database management system used for storing data

- There exist *connectors* for reading data, creating the RDD and writing back results on files or on databases
- In the last years, Data Frames and Datasets have been recently released as an abstraction on top of the RDD

- Spark Ecosystem:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250929152951.png|400]]

- HadoopBinMem is an optimization of Hadoop
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250929152941.png|400]]

- **Open source solutions for Big Data**:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250929152844.png]]

##### Data Partitioning
- **Shoddy Partitioning**: bad data subdivision, some nodes are too much data, some nodes have to little data, there are more data transferring in the network, so it has poor performance
- **Optimal Partitioning**: a good data subdivision, load data balancing between nodes, *data locality* to reduce data transfer, minimize latency and computation time, it requires more sophisticated algorithms to be achieved
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250929152348.png]]




# 1 The database revolutions
- There are three main Database's era:
  1) **Pre Relational** (*1950-1972*)
  2) **Relational** (*1972-2005*)
  3) **Next Generation** (*2005-2015*)
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250929195337.png|600]]
(80% of modern application still use relational database)

### The “Pre historic” Databases
- **Database**: an organized collection of data. Thus Books like dictionaries and encyclopedias that have an enforced structure can be considered database, but also libraries, indexed archives of information, punched papers (used in tabulating machine), carillons,
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250929195619.png|500]]

- With the invention of **Tape**, data were stored sequentially, you can fast forward and rewind through the dataset, but there were no direct high-speed access to individual records

- **ISAM**: you organize the file with an index, the data file can be accessed in any order and are easier to access thanks to the index that allow to find them more easily, but it does not have any DBMS

- without the DBMS every application had to reimplement the database logic form zero, with the implementation from zero every time there were more errors

- **DBMS**: is an application, that allowed the separation between the database handling logic and the application itself
- it offers a *scheme* for the data and an *access path* to navigate among the data records

- the architecture of the application identify the used data-structure, the one of db identify how to store those data


- **Navigational Model** it's a data access model where the information are retrieved following path between connected data, starting from a known initial point. the user navigate through data using link or pointer  
- *Issues*: it can run only in mainframe, it is difficult to add new data, CRUD operation are hard coded, the query are based on the data structure

- **Hierarchical model**: similar to a tree, from each node i can extract more precise information about the children node, you can't go from a child to a parents, so if you want to obtain all the product bought by a customer you need to scan all the product  

- **Network model**: similar to a graph, it is less rigid, if we define an edges we can go back to an old node, in the example we can obtain the info of the sale from the customer, but not the product info

- the first db revolution dbms
- the second was the relational db

### Relational Theory: Tuples and Relations
- **Relational db** are based on *relational algebra*, the old navigation model hadn't any background

- relation = table
- tuple = rows 

- **Constraint** are the strong point of relational database
- example of *consistency constraints*:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251214112739.png]]
- example of *integrity constraints*:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251214112817.png]]

- There are consistency problem for relational db distributed in more nodes, so rdb are good with scale up, but not with scale out

### Relational Theory: Normal Forms
- **Third Normal Form**: non-key attributes must be dependent only on the key

### OOP Problem
- Some object in OOP are defined usually by multiple tables of the relational model, so a lot of operation are needed to reconstruct the original object
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251214113510.png]]

- **OODBMS** (*Object Oriented Database Management System*) allow you to store program object **without normalization**, so it is easier to store and load object. but this paradigm has never gain popularity
### ORM
- **ORM** (*Object-Relational Mapping tool*): is a framework to simplify the translation between object and table
- it can use class definitions to create, maintain and provide full access to objects' data and their database persistence


### Limit of the RDBM
- the main limits of Relational database is:
  - it's hard to modify the *structure* of existing data (e.g. add an attribute)
  - it is hard to manage them on multiple servers
  - there are performance issues for table stored on different nodes
  - it is hard to implement procedures for ACID transaction on multiple servers
  - the RDBMs system used by enterprises and organizations have often a licensing cost that depends on the number of users, this could be a problem for system with a lot of users


### Massive web-scale applications (MWSAs)
- massive web-scale applications are system characterized by:
  - large volume of read and write operations
  - low latency response times
  - high availability
- they serve an huge amount of users, and they need a DBMS that has:
  - *Scalability*: increase the dimension of the system 
  - *Flexibility*: adding, removing or modifying fields from an object
  - *Availability*: have the system always active (it can be done with multiple servers and replicas)
  - *Low cost*

### NoSQL Databases
- NoSQL databases ensure usually Scalability, Availability, Flexibility, Open Source
- acid transaction may be not supported
- reject the consistency and schemas


### SQL on cloud
- It is possible to pay to use Relation system that can scale on the cloud, but this cost a lot and you still do not have schema flexibility
- you also have privacy and security issues


# 2 ACID vs BASE
- Databases must allow users to store and retrieve data, to do this **three task** must be done by the DBMS:
  1) **Store data *persistently***
  2) **Maintain data *consistency***
  3) **Ensure data *availability***

### Distributed System
- Most of the recent NoSQL DBMS can be deployed and used on distributed system so on multiple server

- **Pro** of distributed system: 
  - ensure **scalability**, **flexibility**, **cost control** and **availability**
  - It is easier to add new nodes (horizontal scalability) than to add memory or upgrade a single server (vertical scalability)
  - Allow to implement **fault tolerance** strategies

- **Cons** of distributed system: 
  - We need to **balance** data *consistency* and system *availability*
  - We need to protect the system from *networks failures* that may leave some nodes *isolated*


##### Data persistency
- **Data persistency**: data must be stored in a way that is not lost when the database server is shut down
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250929201109.png|300]]

##### Data Consistency and Integrity
- *Consistency* and *Integrity* describe a state in which the memorized data does not contradict itself
- **Consistency** ensure that a transaction can only bring the database from one valid state to another
- **Integrity** constraints are used to ensure that data consistency is maintained for all insert and update operations



##### Data Availability
- Data stored in a single DBMS may be not available for several reason (such as operating system failure of disk break down), one possible solution that ensures a high data availability is to use the **two-phase commit**. the two-phase commit implement a **strong consistency** on a main server and *one* backup server
- If the primary server goes down, the *backup server* takes it places and the DBMS continues to offer its services to the users
- However, using the *two-phase commit* require a longer time to execute because you have to duplicate the transactions
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250929201753.png|300]]

### ACID Transactions
- An **ACID** transaction should be:
    - *Atomic*: the transaction is **indivisible**, either all the statements in the transaction are applied to the database or none are
    - *Consistent*: the database remains in a consistent state before and after transaction execution
    - *Isolated*: while multiple transaction can be executed by one or more users simultaneously, one transaction should **not see the effects** of other **ongoing transaction**
    - *Durable*: when a transaction is saved in a database, its changes remain even if there is a software or hardware failure 


- There is some applications in which is not acceptable waiting too much time, in this kind of applications, the *availability* of the system and a *fast response* is more important than having consistency on data (e.g. e-commerce application)
- This is achieved by NoSQL databases by **eventual consistency**, so there might be a certain period where data in different servers have different values, but *eventually* (at some point) all the copies will have the same value, it is given more importance to **availability** rather than consistency 

- Availability can be of two type: short term availability and long term availability, giving priority to the availability reduce latency and make the system less ACID

- *Available but not consistent*: we always can access to the data, but they can be not updated yet if the primary server has fault
- *Consistent but not available*: in cases like the use of the *two-phase commits*, data can be consistent (updated in all the servers), but not available for a short period of time (while a commit is being updated)


### The CAP Theorem (Brewer’s theorem)
- *Distributed Systems* cannot ensure at the same time:
  - **Consistency** (*C*): every read receives the most recent write
  - **Availability** (*A*): provide a response to any query (without guarantee that it is the most recent)
  - **Partition Protection** (*P*): the system continues to operate despite network partitions (its not assure that all the service will be available)

- **Network partition** occurs when nodes are split into groups that cannot communicate with each other, one of the group is called *Partition*
- A distributed database can have at maximum **Two** of these feature
- In the presence of a network partition, a distributed system must choose between Consistency and Availability.


- Based of the two properties that you want in your system, there will be problems:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250929203633.png|600]]

##### CA Solutions
- Choose C and A in compromise of P (e.g. banking and finance application, system which must have transaction connected to RDBMS)
- CA systems provide consistency and availability **as long as no network partition occurs**. When a partition occurs, the system becomes unavailable.
- If we choose to adopt total consistency the latency can increase
- A network problem might stop the system

- there are 2 type of failure:
  - single server failure (not a problem in this case)
  - partition failure (like the failure of isolated server, in this case the services become unavailable) 

##### AP Solutions
- Choose A and P in compromise of C (e.g. shopping cart, news site)
- Client may read inconsistent data
- It return the most recent version of the data that you have (that can be not updated), you can do write operations that will be processed later
- *system is still available under partitioning, but some of the data returned may be inaccurate*?

- in case of partition failure you can continue to offer services, but some data can be inconsistent

##### CP Solutions
- Choose C and P in compromise of A
- Some data may become unavailable to the client
- It is used in application which require consistency and partition tolerance, and where long response times are acceptable (e.g. bank ATMs)
- During a partition, some requests are rejected or blocked.
- Used in applications where correctness is critical and unavailability is acceptable.



### Network Partition Resilience
- you can choose two option:
    - remaining available and serving requests with possibly inconsistent data (Availability but not consistency)
    - preserving consistency by rejecting or blocking requests in some partitions (Consistency but not availability)

- In the presence of a network partition, it is impossible to guarantee both Consistency and Availability


### BASE Properties of NoSQL Databases
- **BASE** properties:
  - **Basically Available** (*BA*): partial failures of the distributed database may be handled in order to ensure the availability of the service (often with *data replication*)
  - **Soft state** (*S*): data stored in the nodes may be updated with more recent data because of eventual consistency model
  - **Eventually consistent** (*E*): at some point in the future data in all nodes will converge to a consistent state


### The Latency Issue
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250929203807.png]]
- different level of consistency, have different level of latency

### Types of Eventual Consistency
- **Read your writes consistency**: when a user has updated a record, all of his reads of that record will return the updated value, but another user might read the not updated value
- **Session consistency**: ensure the "*Read your writes consistency*" during a session, if the user ends a session and starts another session with the same DBMS there is no guarantee that the server will remember the writes made by the user in the previous session
- **Monotonic read consistency**: if a user require a query and sees a result, all the users will never see an earlier version of the value
- **Monotonic write consistency**: ensure that if a user makes several update operation, they will be executed in order
- **Causal consistency**: the user will see result consistent with the causal relationship between operation (if there is a causal relation between operation is said that the operation *causally depend* on the previous operation)

- It is possible to have a combination of these tipe of consistency, the type of usable consistency depends on the DBMS

##### Example of Read your writes consistency
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250929215410.png]]
##### Example of Monotonic read consistency
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250929215447.png]]
##### Example of Monotonic write consistency
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250929215505.png]]
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250929215546.png]]
##### Example of Causal consistency
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251214121031.png]]



# 3 Key-value Databases

- An **Associative Array** (or map) associates keys to values. Keys are arbitrary identifiers (e.g., strings, integers), and values may be heterogeneous. Ordering is not guaranteed
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251214144556.png]]


- **Key value databases** have data *persistently stored*, there is no need for table (if we do not need groups of related attributes)
- the unique requirement is that each value has a unique identifier in the form of key
- keys must be *unique* within the *namespace* defined in each specific **bucket** (a bucket is an associative array, you can have a bucket as a instance of the database in a specific server and each of the bucket has a unique namespace so the key in a bucket has to be unique)
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251214144644.png]]

- usually we use just one bucket, element with the same key in different bucket can be different object
- DO NOT BUILD A RELATIONAL MODEL USING A KEY VALUE DATABASE, NOT USE MONGODB OR OTHER NON RELATIONAL ARCHITECTURE TO BUILD RELATIONAL DATABASE

- Developers tend to use key-value databases when an easy way to memorize and retrieving data are more important than organizing data in complex data structure (e.g. tables and networks)


### Essential Features of Key-Value Databases
- *Features* of Key-value DB:
  - **Simplicity**: when all the feature of classical relational database are not needed (e.g. join and complex queries), we do not need to define a database schema or data types for each attribute. If we need to manage new attribute we can change the code instead of the database. Key-value databases are **flexible** and **forgiving**, we can assign a wrong data type to an attribute or use a different type for a specific attribute (e.g. cart of an ecommerce, or booking a restaurant and check or delete the booking, another use are to store configuration file for application. You could need a key value db if your UML diagram is very simple and you need *flexibility* on the type of an attribute)
  - **Speed**: using this scheme the key-value database can *write* the recently updated value to the disk while the user program is doing something else (this type of db is used usually as a **caching memory**, so you load everything or a part of it in RAM and you can access everything fast). *read operation* can be faster if data is stored in memory, this is the motivation for using *cache*, the first time a program fetches the data, it will need to read from the disk, but after that the results can be saved in memory ![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250930201844.png]]
  - **Scalability**: is the ability to add and remove server from a cluster of servers as needed to accomodate the load on the system. In the contest of the key-value database there are two main approaches:
    - **Master-Slave Replication**
    - **Masterless Replication**
- in relational database is difficult to partition table, but here is easier to have horizontal scalability 


- When the key-value database uses all the RAM memory allocated to it, the database will need to *free* some records, it can use various way the record to remove from the ram (e.g. Least Recently Used (LRU), is on of the most used that removed data that weren't read or written for the longest time)

### Master-Slave Replication
- **Master** (*primary server*): a server that accepts write and read requests. It is in charge of collecting all the modification of the data and updating data to all the slaves
- The **slaves** (*secondary server*) may only responds to read requests
- This architecture is good for application with growing demand for read operation
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250930202813.png|300]]

- **Pro**: it is a very simple architecture, only the master communicates with other servers, there is *no need to coordinate* write operations or resolve conflicts between multiple servers accepting writes

- **Cons**: if the **master fails**, the cluster cannot accept writes, in this case **the entire system fails** or at least loses a critical capacity such as accepting writes

##### The Higher the Complexity, the Better the Availability
- Each single slave server may send a simple message to ask a random secondary server in the cluster if it is still active and if it received recently messages from the master
- if a number of slave servers *do not receive a message* from the master within some period of time, the slaves may determine that the master has failed, so the slaves initiate a protocol to *promote* one of the slaves as a *new master*
- with this method we resolve the single point of failure, but we increase the number of exchanged messages


### Masterless Replication
- Used in application where number of writes may increase and achieve peak
- In this case the *master-slave replication* architecture can suffer an increased number of writes request (that can be accepted only by the master). The solution is a model where all nodes can accept requests, the **masterless replication architecture**

- There is not a single server that has the master copy of updated data, and there is not a single server that can copy its data to all other server, each node **help its neighbors** (this type of database is used usually with Cassandra)
- with replicated data on the network we can balance the load in a easier way
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250930204224.png|250]]

- Each time there is a write operation to one of the servers, it replicates that change to the other n server holding its replica and if a request is down and a request is done to it, the request will be resolved by someone with data replica (there are replicated chunks, not entire data)



### How to Construct a Key
Design a key value db mean to design its key, it has to be design the *structure of the key*, the value will be computed on runtime

- In relational model the **primary key** is used to retrieve a row in a table and it must be unique
- Similarly, a *key* in a *key-value* database is used to retrieve a value and must be unique in a specific namespace 
- It is a good practice adopting meaningless keys IN A RELATIONAL DATABASE, in a key value database it is better to use *meaningful keys*   
- The key is the unique mean to retrieve a value, but it also be selected *without a specific meaning*, because **primary keys are immutable** and if one value change in the tuple we cannot change the pk value

- Value are in the form: **EntityName : Entity id: EntityAttribute**
- id is the same for the same tuple of data (instance) 
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251001093501.png|300]]
it is possible to have a key not for each attribute, but one key for a set of attributes (e.g. inside a JSON file)


##### Hashing for Selecting Server
- a way to choose the primary server to store info of a specific key is to divide the hash of a key with modulo from 0 to number of server
- we can use a balancer to choose the server for read operation, but write operation are made on the *main* server for that key
- We need to balance the write loads among servers in a masterless replication architecture, if we divide the Hash value by the number of servers we can collect the **reminder**, namely the **modulus**
- if someone want to buy the same ticket, in the same venue, in the same city, on the same moment there will be two identical primary key
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251001102627.png]]
- key-value db offer ACID transaction, but have a limit on the dimension of keys and values

### Operations Allowed in Key-Value Databases
- Allowed operation in a key-value db:
  - Retrive a value by a key
  - Set a value by a key
  - Delete a value by a key
- **Note**: if we want to do a query we need to use an external application program (it's not so far from pre relational DBMS)

- some key-value db incorporate *search functionality* directly into the database
- a built-in *search functionality* directly into the database, the build-in search system would index the string value stored in the database and create an **index** for rapid retrieval, if done manually has to be update to each update of the original database
- the search system keeps a *list of words* with the keys of each key-value pair in which that word appears
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251214150613.png]]


# 4 Key-value Databases Insights

- String representing keys should not be too long, long keys will *use more memory*
- String representing keys should not be too short too, because they are more likely to lead to *conflicts*

- A value is an *object*, typically a set of bytes that has been associated with a key, they can be simple type, or complex one  (any type of value can be stored in a key-value db)

### Namespace
- **Namespace**: is a *collection* of key-value pairs that has *no duplicate keys*, but can have duplicate values
- namespace are useful when multiple application use the same key-value database, they help to organize data into **subunits**
- namespace are used to create **bucket**, one server can have multiple bucket, but it's good practice to use only one, if you need a complex structure it is better to use another type of database (even with one bucket we can have replicas)
- we can use namespace/bucket to create a db with the same instances but with the attributes expressed at a different granularity, and we can use the same keys for an instance in the two buckets
- *bucket* = data structure of the database
- *namespace* = set of all the key in a bucket
- key are defined at run time when you add a new object

- to get a value you have to specify the bucket

- you first create a bucket and then insert data, you *cannot* create a populated data


### Data Partitioning
- Different *subset of data* (**partitions** or **shard**) may be handled by different nodes of cluster, a cluster may contain more than one partition
- For data partition exists several strategies. The main objective is to achieve *evenly balance*, in both read and write operation among servers, it should also be possible to add easily new nodes to the cluster and *reallocate* the data appropriately (and reallocate the keys) among the new number of server
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251003121119.png|150]]
- the main objective of partition is to balance work

### Partition Keys
- A **Partition key** identifies the specific partition in which the value has been stored
- In a key-value db, any key is a partition key
- usually partition or cluster are identified by hash function applied on the key
- this process is done by the **partition algorithm** 

### Schema-less
- key-value db are **Schema-less**, so we don't need to define all the keys and types of value we will use prior. we can also *change* how storing the attribute of a specific entity
- singular instances can have different attributes and missing attributes or attributes replicated in different forms
- we can make the attributes types change at execution time easily 
- integrity and consistency constraints are not assured, redundancy is assured and can help to do certain operation faster (e.g. if i memorize name, surname, and name-surname in 3 fields, i can access to just one or the two of them with just one operation)

### Cluster
- in Key-value db, cluster tend to be **loosely coupled**, so they are *fairly independent* and complete many function on their own with minimal coordination with other server in the cluster
- each server is responsible for the operation on its own partitions and routinely send messages to each other to indicate they are still functioning
- when a node fails the other nodes in the cluster can respond by taking over the work of that node

### Replication
- the number of replica is a *parameter* to set, we have to choose it considering the performance required and the probability of loose data
- replication ensure high availability but the system performance will be lower
- We use a low number of replica when data is easily regenerable and reloadable 

### Write/Read operations with Replicas
- with n replicas in the classic method you need to do n write operation and 1 read operation, with the **quorum assembly** you can specify how many writing operation do before returning the data and how many read operation do in a read request (to ensure that the returned data are consistent among servers), so how many read operation you have to do to consider valid a read operation 
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251003115108.png|400]]
- the parameters values depend on the use cases
- in the first one you are writing on all the servers, so you have to need only one read because you are sure that the read data will be that, you have slow write and fast read 
- in the second one the write operation will be faster, but you need two read, because it can happen that you read the not updated one, so you have two read operation and this is a slower reading than before, but a faster writing

![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251214152201.png]]
- in the third case write operation operate just on one server, but you need to read all of them to find the more recent one, the write operation are really fast, but read operation are slower
- in the forth case you only write and read one server, this doesn't ensure consistency, but if you can accept that this is the faster solution



### Hash function
- **Hash function properties**:
  - A small change in input can change a lot the output
  - it distribute the input evenly among the set of all possible output, no matter how much similar are the starting key
  

- we can use the _most significant digit_ of the hash value (or more) to identify the server of the data cluster, in this case data would be assigned to partition 4 and 12
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251003115439.png]]


### Collision Resolution Strategy 
- **Open Hashing**: each cell of the hash table doesn't contain a single element representing a value, but a list of pair key-value, when two key are being mapped to the same element we add them to the corresponding list, but we keep also the original key to recognize them for retrieve the correct value
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251214152512.png]]


- **Linear Probing**: in case of collision doesn't use a list, but find the next free cell by using a linear search
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251214152442.png]]

### Consistent hashing 
- **Consistent Hashing**: in a classic distributed system we use hash function to assign keys to the nodes, but when the number of nodes in the system changes we have to reassign all the key

- The *Consistent Hashing* use a circular structure called *hash ring* that apply an hash function (the same hash function that also have to be in the **same range**) to the nodes and to the keys, it places the nodes in a circle and a keys is being assigned to the first node of the ring clock wise

- if i add a new node to the ring, only the keys between the previous node and the new have to be remapped, all the others key remain stable
- when a nodes is being removed, its keys are being assigned to the next node alive in the ring, all the others keys remain stable
- there are like position of the node in a ring, key are assigned to certain position and base on the position they are clockwise assigned to the next node, if we add a node in a position, the key clockwise near to him become assigned to him, if we remove a node, its key are being assigned to the next node in clockwise position
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251004142317.png]]

- The actual server node kj is associated with a specific key oi that is its *successor* in the hashing space (or address space)
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251004143432.png]]

- As the number of nodes changes, only a small fraction of keys change assignment
- It is useful for big cluster and distributed system
- Consistent hashing ensure a good load balance among servers



### Data Compression for KV Databases
- Key-Value Database are **memory intensive**
- Operating System can exploit *virtual memory management* (so write data on disk instead of the ram), but that process is slower than reading from ram
- One way to optimize memory usage is to use **compression techniques**

- there is a trade off between speed and size of compression, the more fast is the algorithm, the less it compress, you set manually the parameter to set this threshold 
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251004143816.png]]


### Using Key-Value Databases
- if **data organization** and **management** are more important than *performance* it is better to use *relational database*, if performance (high availability, short response time, etc.) are more important and the **data model is not too much complicated** (no hierarchy, limited number of relation), we can use key-value database
- if we have a complex data structure and we want performance we still don't use key-value database
- key-value are simple and easy to handle if they have a simple structure


- considering this data structure:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251004144858.png]]

- in a relational database we can represent the one to many relationship using a *foreign key*
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251004144947.png]]

- in a key value database we can write simply the employer table like this:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251004145109.png]]

- to translate the payment table and the one to many relation we can define the following key-value configuration, that for each value specify the associated foreign key:
**payment:\$payment_id:\$employee_id:$attribute_name = $value**
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251004145201.png]]

- at the end we will have a *unique bucket* for all our data
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251004145327.png]]
- all of this can be created dynamically, it is useful to follow some convention, particularly if you are in a group or company
- some DBMS maintain a graphic order based on the key to have more readability 


# Key-value Databases Design Tips and Case Study

### Coding Tips
- with **well designed** key pattern, you can minimize the amount of code a developer needs to write to create functions that access and set values

- it is a good practice to use *generalized set and get function* for improve readability
- it is a good practice to use a *naming convention* for namespace
- it is a good practice to use an appropriate *error check and handling*

### Naming convention for keys
- use meaningful and unambiguous naming components for keys (e.g. cust for customer), but not too short to avoid ambiguity
- use **range-based** components when you need to retrieve ranges of value (range includes also dates and integer counters)
- use a **common delimiter** when appending the key components (e.g. : or -)


### Get and Set Functions
- Example of get and set function (AppNameSpace is the name of the namespace where the keys are defined):
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251004151859.png]]

### Simple or Complex Values
- one way to access the data faster is to store attributes usually accessed together in a new variable:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251004152200.png]]
- in this case you can access faster to the data but you occupy more memory, if you only memorize the data together instead you use more band when you need only one of the attributes in the list
- key-value database usually store the entire list together in a **data block**, so we just need to access one block rather to do an access for each attribute

- when the data structure become to much complex, the system will store it in **more than one memory block** and read and write operation time will increase (if we need complex structure in our database it is better to use document database) and is possible to have fragmentation 
- in a document database instead everything is stored together 

### Limitation of Key Value DB
- **The only way to look up values is by key**
- **Key-value database may not support range queries** (only some DBMSs, called ordered KV databases allow it)
- **There is no standard query language comparable to SQL for relational database**
 
- it is difficult to model the key
- you can't have many relationship and entities 
- some database like redis allow more complex searches on values, but still doesn't exist a common query language, only set, get and delete operation are documented
- there are not constraints on the type of data (you have to manage that in the setter and getter)




# 16 In Memory Database

- The design of a database solution is driven by the application **requirements**
- so if our application *does not need* to handle huge amount of data and to scale, both vertically and horizontally, we can think about adopting *different solutions* than the ones discussed so far

- **In-memory databases**: may be suitable for application whose handled data may *fit all* in the memory of a single server
- moreover there also can be database that can reside in the memory capacity of a cluster

- as memory increases, the cost per megabyte decreases 
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251025155548.png|300]]

- **Features of In-Memory Databases**:
  - *Fast access* to the data, avoiding bottleneck of I/O transfer
  - Suitable for application that doesn't need *to write continuously* to a persistent medium
  - *Ad-hoc architecture* for being aware that its data are resident in memory and for *avoiding data loss*
  - *Cache-less architecture*, because everything is already in memory (usually all type of databases has some caching system)

- there can be fragmentations problems, you need to store frequently accessed together data near

### Solutions for Data Persistency
- Solution for avoiding data loss in case of **system failure**:
  - writing complete database *images* (called snapshots or checkpoints) to disk files
  - writing out transaction/operation records to an append-only disk file (called a *transaction log* or *journal*)
  - *replicating data* to other members of a cluster (replicate data to other servers)


### TimesTen (Oracle Solution)
- **Oracle TimesTen** is an in-memory relational SQL database. All data resides in memory, enabling extremely fast access.  
- Persistence is achieved through **periodic memory snapshots** and a **transaction log** that records committed changes.  
- By default, disk writes are asynchronous for performance; synchronous writes can be enabled to guarantee full ACID compliance at the cost of throughput. Applications interact directly with in-memory tables, while snapshots and logs ensure durability and recovery.
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251025160349.png]]

### HANA DB (an SAP product)
- **SAP**: family of software used for business intelligence 
- it must be installed on an *optimized hardware configuration*
- **SAP HANA** is an in-memory relational database combining **row-based** and **column-based** storage.

- **Row tables** are always memory-resident and optimized for OLTP operations.
- **Columnar tables** are optimized for OLAP queries, compressed, and loaded in memory on-demand (or fully preloaded).

**Persistence** is ensured via periodic **savepoints**, merging with data files, and a **redo log** for transaction recovery. This design allows high-performance in-memory operations while maintaining ACID compliance.
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251025161348.png]]

### Oracle 12c: Architecture
**Oracle 12c In-Memory Architecture**
- Data is stored on disk but cached in memory for fast OLTP and OLAP operations.
- OLTP transactions primarily read and write in memory; committed transactions are immediately written to the transaction log for durability.
- Row data can be transformed into a **columnar format** for analytical queries.
- Changes occurring after columnar loading are recorded in a **journal**, ensuring analytic queries see consistent and up-to-date data.
- Queries consult the column store and, if necessary, the journal or row store to rebuild columnar structures with recent changes.
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251025161401.png]]


# 12 Column Database
### OLTP vs OLAP 
- **OLTP** (*Online Transaction Processing*): it is a software architecture oriented toward **Handling ACID transaction** *quickly*, it is write oriented 
	- it can manage high volumes of transaction
	- it can do fast processing
	- have normalized data
	- it has many table

- **OLAP** (*Online Analytics Processing*): it is a software architecture oriented towards *interactive* and *fast analysis* of data. Typical of *Business Intelligence* software, it is read oriented
	- it can manage high volume of data
	- it has low latency
	- it uses denormalized data
	- it has fewer table

- you can have a OLTP db that manage fast write and then put data in a OLAP db that manage fast read
- OLTP is better for specific request (e.g. the precise user that have bought a specific product)
- OLAP is better for analysis (report, graph, statistics)
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251024104553.png]]

### Row Data Organization 
- Since the beginning of *digital files* the data of each record were organized in *rows*
- OTLP processing is mainly oriented towards handling **one record** at a time processing
- OTLP were used when *the first relational database* was designed
- the **record-oriented workflow** handled by the first relational databases, and the **row-oriented** physical structure if early digital files provided *good performance*

### CRUD and Queries
- In the **record-based processing era** (up to the end of 80s), CRUD operations (Create Read Update Delete) were the most *time-critical*
- **Report programs** were typically iterated though entire tables and were run in a *background* batch mode. The time response to queries became a *critical issue* to appropriately handle when OLAP assumed relevance and Business Intelligent software started to spread



### Star Schemas in Data Warehouse
- **Star Schemas** is a *relational solution* where a central **large fact table** (with the most important facts) is associated with *numerous smaller dimensions tables* (with relevant information)
- Star scheme do **not represent** a fully **normalized** relational model of data (it can accept redundancy and sometimes information depend partly on the primary key), e.g., here StoreRegion is redundant, but we memorize it a lot of time in Store because we often access it, but because of this we do not obtain the third normal form of the DB
- with this approach aggregate queries could execute quickly
- **Main drawbacks**: high CPU and I/O usage, rapid data growth with user demands, and storage overhead due to denormalization.
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251024111934.png]]


### The Columnar Storage 
- when processing data for making *analytics*, in most of cases, we are not interested in retrieving *all data information* of each single records 
- indeed we are interested for example in retrieving the values of *one attribute* of a *set of records*

- When dealing with **row based storage** of records, we have *access all the attributes* of the considered set for retrieving just the values of one attribute
- **Columnar storage** organizes data by attribute, storing all values of a column together.  
- Columnar storage accelerates queries accessing few attributes across many rows (typical OLAP), while row storage is faster for queries accessing many attributes of few rows (typical OLTP). 
- Columnar storage preserves relational structure and normalization (it is the same as row storage, it change only how data are memorized at low level)
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251024113043.png]]


- in rows storage different rows are in different block of the disk, in columnar storage different column are in the same block
- for query that access to *multiple records* are significantly accelerated in a columnar database, query that access multiple attributes in a limited number of row will run faster in a row storage db 
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251024113056.png]]


### Concrete Example
- If data are **stored by rows** in order to retrieve the sum of the salaries, then we must scan *five blocks*, in the case of *column store* a single block access in enough
- in general queries that work across **multiple rows** are accelerated in a columnar database
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251024113131.png|448]]

### Columnar Compression
- Data compression algorithms *remove redundancy* within data value
- the higher the redundancy, the higher the compression ratios
- to find redundancy, data compressions algorithm usually try to **work on localized subset** of the data
- if data are stored in a columns database, we can achieve an high compression ration with a low computational overheads. e.g., often data are sorted, we can represent each value in a column is represented as a **delta** from the **preceding value**


### Single Row Operations Penalty
- Column database perform *poorly* during *single row modification*
- the overhead needed for reading rows can be partly reduced by **caching** and **multicolumn projection** (storing multiple columns together on disk)
- in general handling a row means accessing to more than one block of the disk
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251024113142.png]]

### Delta Store
- Columnar storage is inefficient for frequent *row-level updates*, which are required for real-time analytics. To address this, columnar databases use a **delta store**: an in-memory, uncompressed, row-oriented structure optimized for high-frequency modifications.  
- Updates are first written to the delta store and are periodically merged into the main columnar store through a **delta merge process**. Queries access both stores to return complete and consistent results.

- **Queries** access *both* the delta store and the columnar store in order to return complete and accurate results
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251024113155.png]]



### Projections
- **Problem**: complex query need to read *combination* of column data
- **Solution**: some column database adopt *projection*
- **Projections**: combination of columns that are *frequently* accessed together
- columns of a specific projection are *stored together* on the disk

- here we have a db with 4 column, and 3 different projection, one with all element, one with 3 and one with one pair. each one optimize a specific query
- the super projection is not sorted, the other one are sorted by one or more columns 

- Projections trade storage redundancy for query performance by physically co-locating frequently accessed columns.
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251024113206.png]]
- a Projection is basically an optimized view for a single query
- a physical projection is basically a family
 
# 13 Column Databases insights 
### BigTable: The Google NoSQL Database
- **BigTable** was introduced by google in 2006 for google large services, it is the first columnar like database
  - is *column based* with a *dynamic* control over columns, so it is schemeless  
  - data values are indexed by *row identifier*, *column name*, and a *time stamp* (all three together), this allow to **quickly identify a single record**, this also allow to store different version of a datum thanks to the time stamp (it is possible to set how much version of a data you want to store, and allow to implement drawback to previous version)
  - reads and writes of a row are *atomic* (the operation are done entirely or nothing)
  - *rows* are maintained in a *sorted order* at low level 

##### BigTable Example
- a data record is a *row* composed of several *column families*
- we identity a row using a *row id*
- each family consists of a set of *related columns* (usually they are frequently used together columns or have some semantic relationship)
- *columns value* within a column family are *kept together* on the disk, whereas values of the same row belonging to different families may be stored far
- *columns families* must be **defined a priori** (like relational tables), they cannot be added dynamically later, on the other hand projections can be added dynamically if they are just logic projections
- application may *add* and *remove column* inside families (like key-value pairs)

- here we have 2 columns families, one for the customer info, and one for the address info
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251025163918.png]]

##### BigTable: Indexing
- A *Data Value* is indexed by its:
  - **row identifier**, similar role to a primary key in a relational database, so a single row share the same row identifier
  - **column name**, which identifies the column 
  - **time stamp**, which allow the existence of *multi version* of a column value
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251025164204.png]]


##### Keyspace
- **Keyspace**: is the *top-level logical container*. It holds column families, *row keys*, and related data structure for manage partition, sharding, and replicas
- typically there is *only one keyspace* per application
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251025164515.png]]


##### Row Keys
- **Row keys** are one of the components used to *uniquely identify* values stored in a database
- they are also used to *partition* and *order* data (the algorithms for doing this depend on specific databases, e.g. Cassandra adopt the **partitioner**, a specific object which is used for sorting data)
- by default the partitioner *randomly distributes* rows across nodes

- in this example we have 4 column family, the row key it is the primary key that associate the data from different family, data with the same row key are usually in the same server (but can be in different sector if there are different families)
- the row key can be a number, an id or something more complicated with a meaning, it can be used for sort information, and can be also used as a sharding key
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251025164545.png]]

##### Columns
- a **Column** with its *row key* and *time stamp*, uniquely identifies value, values can be **typed** or not (so you have to specify the data type in some solution, in other is not mandatory)
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251025165409.png]]

##### Column Families
- columns that are *frequently* used together are *grouped* in the same **column family**, it is the analogous of a *table* in a relational db, however:
  - rows in a column family are usually *ordered* and *versioned*
  - columns in a family can be *dynamically modified*
  - modification just need to making a reference to them from the client application

- in this example we use different attribute of the record if the customer lives in Canada or usa, in relational table we should put "null" as value, here we can put nothing and save memory thanks to sparse matrix, and group the attributes related to being from Canada in one family and the attributes related to being from usa in another. we can use the nation as a sharding key to split data in different servers 
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251214162831.png]]
- with just one column family, the db will try to put everything together, this can be difficult with just one disk, so columnar db should be used **only when we have the division in family**
- you can define two column with the same name in different families, you have to specify the column family in the column name when indexing

### Cluster and Partitions
- recent column databases ensure high *availability* (with replicas) and *scalability* (with partitioning or sharding) along with different *consistency levels*
- clusters and partitions are fundamental for the **distributed implementation** fo the databases


### Column DB Architectures
- we can have two main type architecture:
  - _HBase_: we have different types of server which run different kind of software (**Master-slave**)
  - *Cassandra*: all the nodes are exactly the same (**peer to peer masterless ring architecture**)
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251025170503.png]]

### HBase
- **HBase** depends on multiple types of nodes that make up the **Hadoop** environment
- **Hmaster**: assigns regions to Region Server (slave)
- **Region Servers**: are the end nodes that handle all user requests
- **Regions** in a specific region server contain all the rows between specified keys (Region = Data stored)
- **Zookeeper** is a type of node that enables coordination between nodes within a Hadoop cluster. coordinate the different interaction between different types of servers 
- **NameNode**: keep the metadata of the filesystem
- **DataNode**: memorize the blocks of data
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251025170535.png]]

- we have a master slave organization, the master assign region (a subset of data) to different region servers, and ask to different region server to perform request, while in region server we can have more than one region, contains data and perform computation 
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251025170518.png]]


### Cassandra
- all **Cassandra** nodes run the *same software*, but nodes may serve *different functions* for the cluster
- it is a masterless ring organization, so each server has the same software and offer the same functionality, and we haven't any point of failure, moreover it is easy to remove and add server
- if one server go down the other will do its work

- **Advantages** of Cassandra:
  - Simplicity
  - No node can be a single point of failure
  - Scaling up and down is fairly straightforward
  - Servers communicate with each other
  - When a node is removed, servers hosting replicas of data from the removed node respond to read and write requests

![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251025170738.png]]

##### Bloom Filters
- **Bloom Filters** are *probabilistic data structures*, they help to *reduce* the number of *reading operations*, avoiding reading partitions that certainly **do not contain a specific searched data**
- a Bloom Filter tests whether or not an element is a *member of a set*, the answer of the test is "no" or "maybe", it is possible to have False Positive
- However if the answer is "no", then the element for sure isn't in that specific partition

- it is used to reduce the accesses to the disk in a read operation 
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251025170745.png]]

##### Bloom Filters Example
- Let consider a *specific partition*, a bloom filter for this partition can be an **array of n binary values**. at the beginning, all the elements are set to zero
- let also consider a set of **k** (where $k < n$, so very low in respect to n) **hash function** which *map each data* to be stored or read into the partition *in an element* of the array

- when a new data is *added* (write operation) to the partition, all the hash functions are calculated and the corresponding bit are *set to one*

- when a *read* operation is required, all the hash function are calculated and the access to the partition is actually performed **if and only if** all the corresponding element in the array **are set to 1**

- The maximum false positive rate depends on the values of n and k


- Let consider a Bloom Filter with n = 10 and k = 3.
- The *Insert* function describes a *write* operation
- The *Lookup* function describes a *read* operation
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251025170752.png]]
- I'm sure that y is not in the partition because in the past i never added y in the database
- the higher the number of bit (k?), the lower the possibility of a false positive
- after insert a lot of things all the value will be practically 1, but if i remove one object i cannot put the bit back to zero, because maybe in the meantime i had insert another object that would have put that bit to 1 and i cannot put it back to zero, otherwise i will have a false negative (so i will receive a no when it is a maybe)



##### Some consideration on Bloom Filters
- an important property of Bloom Filters is that the **time** it takes both to add an element, and to check if an element is in the set is **constant**
- The **probability** of a false positive *decreases* as n increases, while it *increases* as the number of elements stored in the Bloom filter decreases
- **Removing** an element from the simple Bloom Filter is *impossible*, because *false negative are not allowed*

- use n = O(h) and k=ln2(n/h)where h is the number of value to check against the filter.


### Consistency Level
- **Consistency level** refers to the consistency *between copies* of data on *different replicas*

- We can consider three different level of consistency:
  - **Strict consistency**: all replicas must have the same data (high latency in write operation)
  - **Low consistency**: data must be written in at least one replica
  - **Moderate consistency**: all intermediate solution

- the consistency level depends on the application requirements


### Replication
- Consistency level is related to the **replication process**
- the replication process regards where *place replica*, and how to *keep them updated*

- usually there is a pre-defined server for the *first replica* which is in charge of identifying the position of the other replicas among the available servers
- the primary server is often determined by an *hash function*

- each databases has its own replication strategies, e.g., cassandra uses clusters organized in **logical rings** and additional replicas are stored in successive nodes in the rings in *clockwise directions*

### Anti-Entropy
- **Anti-entropy** is the process of *detecting differences* in replicas
- it is important to resolve inconsistency exchanging a low amount of data

- **Hash trees** may be exchanged among servers in order to easily check differences, each leaf of the tree contains *the hash value of a data set* in the partition, each parent node contains the *hash value of the hashes* its child nodes
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251025170801.png]]
- each server build a binary tree that summarize the content of its memorized data, by exploiting hashing function of *block of data*. if the hashing value of two block of two server are the same it means that they have the same data (except for collisions) 
- so we apply the hashing function to the block of different server, then we apply a hashing function to the hashing value obtained, and we check the single hashing value to check if there are consistency problem between servers
- we can exploit the tree to know even where are the inconsistency 

### Communication Protocols
- In distributed systems, each node needs to be aware about the status of the other nodes
- In small cluster, each node can exchange messages with each other node. 
- The number of total messages to exchange for a complete communication is equal to n×(n– 1)/2, where n is the number of nodes of a cluster
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251025170809.png]]

### Hinted Handoff
- What happens if the node interested in a write operation is down?
- Two scenarios may happen:
1) The operation will be lost, thus the target node will be in inconsistent state after its recover
2) A specific node can be designated to receive write operations and forward them to the target node when it becomes available

- The **Hinted handoff process** is in charge of:
1. Creating a data structure to store information about the write operation and where it should ultimately be sent
2. Periodically checking the status of the target server
3. Sending the write operation when the target is available
- Once the write data is successfully written to the target node, it can be considered a successful write for the purposes of consistency and replication


# 14 Column Databases Design Tips
### Column DB Design
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251025181942.png]]

- **Typical queries** that may led to choose **column DB**: 
	 - How many new orders were placed in the Northwest region yesterday? 
		   data like region, order date and order status can be stored in separate columns
	 - When did a particular customer last place an order? 
		   we only need data from customer ID and order date columns
	 - What orders are en route to customers in London, England? 
		   we only need order status and customer location columns
	 - What products in the Ohio warehouse have fewer than the stock keeping minimum number of items?
		   we only need data from  warehouse location, product ID and inventory count columns

- data like region, order date and order status can be stored in separate columns, we can access to only these columns without scanning unrelated data
- allowing fast access to only the relevant columns without reading unnecessary data, this minimize I/O and speeds up the aggregation

### Information Needed for the DB Design
- queries provide information needed to effectively design column family databases
- The information includes:
  - *entities*
  - *attributes of entities*
  - *query criteria* 
  - *derived values*

- designer start with this information and then use **the features of column-based** databases management system to **select** the most appropriate **implementation**


### Information Needed for the DB Design
- **Entities**: a single row describe the instance of a single entity, rows are uniquely identified by *row keys*
- **Attributes of entities**: attributes of entities are modeled using columns
- **Query criteria**: the selection criteria should be used to determine optimal ways to organize data with tables and column families and how to build partitions
- **Derived values**: it is an indication that additional attributes may be needed to store derived data (e.g. count of orders placed yesterday by a user)


### Differences with Relational DBs
- Column databases are implemented as **sparse** and multidimensional **maps**
- columns can **vary** between rows
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251026110405.png]]

- columns can be **added dynamically**

- **joins** are **not used** because data is **denormalized**
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251026110425.png]]

- it is suggested to use **separate keyspace** for each application

### Use Both Column Names and Column Values to Store Data
- because the column value is not used for anything else, we can store the product name there
- this can avoid the access to the product table, if we want to produce a report listing products bought by a customer

- keeping a copy of the product name in the customer table will *increase the amount of storage used*, so we can improve the read performance

- example with a many to many relationship:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251026110519.png]]


### Model an Entity with a Single Row
- a single instance of one entity, such as a particular customer or a specific product, should have **all its attributes** in a **single row**
- in this case, some rows store more column values than other

- classical organization in a relational DB of an entity that can assume different **shapes**:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251026110824.png]]

- in order to **ensure the atomicity** of the operation in a column DB, the same entity must be organized in just *one table with 4 column families*
- create only 2 column families, one with general information and one for all the specification **WOULD BE WRONG** BECAUSE WE WOULD BE GROUPING DIFFERENT TYPE OF ATTRIBUTES THAT ARE NOT ACCESSED TOGETHER (e.g. the one of book and cloth)
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251026111423.png]]
- the **atomicity** is typically ensured at **row level**
- column DB may *not support* strong *ACID transaction*
- for each product there will be a row in the product general info and one in one of the three of the specialized information 

### Avoid Hotspotting in Row Keys
- **Hotspotting** occurs when many operations are performed on a small number of servers (compared to the total number of server)

- we can prevent hotspotting by **hashing sequential values** generated by other systems and used as row key in column DB
- alternatively we can **add random string** as a prefix to the sequential value, example: `A_1001`, `B_1002`, `C_1003`
- these strategies would *eliminate* the effects of *lexicographic order* of the source file on the data load process
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251026111745.png]]

### Keep an Appropriate Number of Column Value Versions
- some columns DBMSs provides a **column value version**
- the number of version maintained is controlled by *database parameter* (you can set the min and max number of data version)
- the parameters *depend* on the application *requirements*
- versioning is useful if we need to *roll back changes* that we have done to column values

- the *oldest version of values* if needed will be removed during **data compaction** procedures
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251026112658.png]]


### Avoid Complex Data Structures in Column Values
- **Any kind of data structure may be stored in a column value** such a JSON file
- Store complex data structure *only if you need to store and retrieve it as is*

- Important:
  - using *separate columns* for each attribute makes it easier to apply database features to the attributes (**indexing**)
  - *separating attributes* into individual columns allows you to use different *column families* if needed

 
### Indexing: Primary and Secondary Indexes
- **Index**: a specific data structure in a DBMS that allows the database engine to *retrieve* data *faster* than it otherwise would
- in column databases we can *look up* a *column value* to quickly *find rows* that reference that column value

- **Primary indexes**: are indexes on the *row keys* of a table (created and maintained by the DBMS)
- **Secondary indexes**: indexes created on one or more *column value* (created by the DBMS or your application)


### Secondary Indexes Managed by the Database Management System
- **General and common sense rule**: “if we need secondary indexes on column values and the column family database system provides automatically managed secondary indexes, then we should use them.”
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251026114314.png]]
- Typically the DBMS will use the **most selective** index first
- the automatic use of a secondary indexes has the advantage the we do not have to change our code to use indexes, if the application requirements will change


### When avoiding to use automatically managed indexes
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251026113123.png]]


### Create and Manage Secondary Indexes Using Tables
- in this case we have to **explicitly create** and manage tables to store data we would like to access via the index
- the *programmer* will be *responsible* for maintaining  the indexes and two main strategies may be adopted
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251026114555.png]]
- in the case that secondary indexes are not available in the DBMS we can craft them with some table (extra data structure), we can choose to always keep an index updated and then return the control to the application or updating it after return the control (faster but can bring consistency problem)





# 6 Document Databases
- **Document databases** are *non-relational* database that store data as structured documents usually in XML and JSON
- they ensure a *high flexibility* that allow to handle *complex data structure*
- they are **schema less**
- they allow complex operation such as query ad filtering
- and they also allow **ACID transaction**

- a single record is represented as a document
- its easier to represent programming object with document 


### XML Documents
- **XML** (*eXtensible Markup Language*): a markup language specifies the structure and content of a document
- **Tags** are added to the document to provide *extra information*
- tags give to the reader an idea of what the data means
- with XML is possible to represent almost any form of information

- Use case of XML documents:
  1. XML and CSS documents allow **second generation database** that separate data and format
  2. XML is the base for many *data interchangeable protocols* (so it was use to exchange information) and and in particular for **SOAP** (Simple Object Access Protocol)
  3. XML is also a standard format for many document types, like word processing document and spreadsheets (e.g. docx, xlsx and pptx)

- *Advantage* of XML:
  - is a unicode based text (unicode based), so it can be transmitted efficiently
  - an XML documents can be displayed differently in different media and software platform
  - XML documents can be *modularized* (so you can reuse some parts)

- example of XML document:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251010105248.png]]


##### XML Ecosystem
- **XPath**: it is a framework useful to *navigate* through elements and attributes in an XML document
- **XQuery**: is the querying language for XML build on XPath expressions
- **XML Schema**: a special type of XML documents that describes the *element* present in a specified class of XML documents
- **XSLT** (*Extensible Stylesheet Language Transformations*): is a language for *transforming* XML documents into other formats (including some non-XML documents like HTML)
- **DOM** (*Document Object Model*): a platform and language neutral interface for dynamically managing the content, structure and style of document like XML and XHTML (each document is handled like a *tree*). so it can be use to represent XML at a low level

### XML Databases
- **XML Databases**: is a platform that implement the various XML standards such as XQuery and XSLT
- they provide *service* for the storage, indexing, security, and concurrent access of XML file
- XML databases are not an alternative for Relational Database Management Systems
- Some RDMSs introduced XML, allowing to store XML within a **BLOB** column (a binary large object column) 

- XML db in general use to much grammar to represent a little piece of information
- **processing layer**: allow to use the XML tools (defined in the XML ecosystem)

##### Main XML Drawbacks
- XML tags are *verbose* and *repetitious*, thus the amount of storages increases
- XML documents are *wasteful of space* and *computationally expensive* to parse
- in general XML databases are used as **content-management systems**, so collection of text files (such as academic papers and business documents)
- **Json-based** document database are more suitable for *web-based operation* and operational *workload* such as storing and modifying dynamic contents

### JSON Documents 
- **JSON** (*JavaScript Object Notation*): is a document used to format data
- thanks to its integration with JavaScript, a JSON file is often preferred to an XML documents for **data interchanging** on the internet
- e.g. MongoDB exploit an extended version of JSON 

- it is mostly a language independent way to specifying object as *name-value* pairs
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251010110845.png]]
- anything inside a pair of {} is a document

##### JSON syntax
- an **Object** is an unordered set of *name-value pairs* (name are also called key)
  - the pairs are enclosed within *braces* "{}"
  - there is a *colon* ":" between th name and the value
  - pairs are separated by a *comma* ","
  - Example: {"name": "html", "years": 5}

- an **Array** is an **ordered** *collection* of values 
  - the values are enclosed within *brackets* "\[ ]"
  - values are separated by *commas* ","
  - Example: \[ "html", ”xml", "css"] 

- a **value** can be: a string, a number, a bool, a null, an object or an array
- values can be *nested*
- strings are enclosed in double quotes and can contains the usual assortment of escaped characters
- number are all decimal, they use the C notation and can be in exponential notation


- Nested Object
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251010111449.png]]

- Nested Array
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251010111507.png]]



##### JSON and XML comparison
- Similarities:
  - both are human readable
  - both have simple syntax
  - both are hierarchical
  - both are language independent
  - both are supported in APIs of many programming languages

- Differences:
  - Syntax is different
  - JSON is less verbose
  - JSON includes array
  - name in JSON must not be JavaScript reserved words

- JSON is much more *compact*:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251010111729.png]]


##### Main feature of JSON Databases
- data are stored in JSON format
- a *document* is the **basic unit of storage**, it include one or more *key-value pairs* and may also contain *nested documents* and arrays
- arrays can also *contain documents* (allowing a complex hierarchical structure)
- a **collection** (or **data bucket**) is a set of documents sharing some *common purpose*, so a list of different document ({}, {}, {})
- is **schema less**: you don't need to define predefined document elements
- it has a **Polymorphic Scheme**: the document in a collection may be different


##### Schema-less vs Schema definition
- a **Schema** is a specification that describes the *structure of an object* (e.g. specifies the structure of a table)
- **Data modelers** have to define *tables* in a relational database before developers can execute code to add, remove or update row in the table
- but document database doesn't require this step, so developers can create collections and documents by simply *inserting* them into the database
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251010112416.png]]

- Schema-less Pro: *high flexibility* in handling the structure of objects to store
- Schema-less Cons: the DBMS may be not allowed to *enforce rules* based on the structure of the data (you also can have problem when you change info on a object references by a lot of instances, so if you change something in an instance, you are not sure that that will change everywhere)



- a document database could *theoretically* implement a **third normal form schema**
- table as in relational database can be "*simulated*" considering collection with JSON documents with identical *pre-defined structure*

- but they usually adopts a *reduced number* of collections for modeling data
- **Nested documents** are used for representing **relationship** among different entities 
- document database DO NOT PROVIDE JOIN OPERATION
- it is more comfortable for programmers to have the JSON structure map *closely to the object structure of their code* as much as possible

- Document databases are not general purpose databases

# 7 Document Database considerations
- a document database can simulate with json document a relational database and so you can implement a third normal form schema
	- table are simulated with a collection of JSON documents with an identical **pre-defined structure**
### Data Modeling: Document Embedding ![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251010112945.png]]
- the above solution allows the user to *retrieve* a film and list all its actors in a *single operation*
- however "**actors**" result to be *duplicated* across multiple documents
- so you trade memory usage for performance
- this could lead to issues and inconsistency if one of the actors attribute need to be updated
- Another problem is that some JSON database have limitations of the maximum dimension of a single document


### Document Linking 
- There are two types of document linking

- type one embed an **array of id** that belong to *another collection* (this can be used in some specific cases)
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251010114703.png]]

- type two use **create a join table** (NEVER USE THIS APPROACH)
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20260111092351.png]]
- we are **rolling back** to a relational model, now we must define at least two collections of documents. 
- and we are also rolling back to the third normal form
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251010115149.png]]
- there are also mixed solution 


- **NOTE**: **Document linking**: can be done, but don't use it in the project, if you need a relational models use a relational database, the "wrong one" is *just one kind* of document linking



##### Some discussions
- **Document linking** approaches are usually somewhat an *unnatural* style for a document database
- However for *some workload* it may provide the best *balance* between performance and maintainability
- When modeling data for a document databases, there is no equivalent of third normal form that defines a "**correct**" model
- in this context the *nature of the queries* to be executed *drives* the approach to *model* the data
 
### One to Many Relationship: Document Embedding
- Let consider a customer entity which may have associated a list of address entities
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251010115528.png]]
- the basic pattern is that the *one* entity in a one to many relationship is the **primary document**, and the *many* entities are represented as an array of **embedded documents**
- we use this in case that we always access together the info on the primary and secondary documents

### One to Many Relationship: Document Linking
- if we access less often to the secondary object we can put an array of id in the "one" part that reference the "many" document
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251226105902.png]]

- **NEVER** use a foreign key, so do not put the reference to the "one" part in the "many", because in this way you recreate a relational db, BECAUSE IN THIS WAY YOU NEED TO CHECK ALL DOCUMENTS IN ADDESSES COLLECTION
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251226110324.png]]
- **NOTE**: don't put the id of an entity inside another to make a 1 to n relationship, because you have to scan ALL the other type of entity to find the relationed one, instead with the other type of document linking you have the address and make much less read operation


### One to Many Relationship: Partial Document Embedding
- there is also a mixed solution called **Partial document linking**: we memorize only some attributes of the secondary documents, the remaining attributes will be accessed using their ID
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251226110408.png]]



### Many to Many relationship
- Let consider an example where a student can enroll to many course and a course can have many student enrolled to it, we can model this situation considering the following two collections:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251010115751.png|785]]
- to manage a n to n relationship we can use document linking with the list of **id** (most common solution), in this case is instantiated as the fields *enrolledStudents* and *courses*, WE WILL SAVE A LIST OF ID IN BOTH PARTS
- we have to take care when updating data in this kind of relationship, indeed the DBMS *will not control the* **referential integrity** as in relational DBMSs


### (Partial) Document Embedding
- another solution is to use the **partial document embedding** where we save both id and courses' name, if we want to access to other courses attributes we have to use the id, but we can access fast to the name of the courses or in the other table save student id and name
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251226110858.png|1050]]

### Mixing Document Embedding and document linking
- finally we can even **mix document embedding and linking**, in some tuple partial access to the attributes and other ones with access with id to everything (keep info on the first years courses, but only the link on the exams of the second one)
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251226111226.png]]


### Data Modeling Example 
- Scenario: Trucks in a company fleet have to transmit location, fuel consumption and other metrics every three minutes to a fleet management data base (one-to-many relationship between a truck and the transmitted details)
- We may consider to generate a new document to add to the DB for each data transmission

- note: document db are not the best solution for *timeseries data*

Let consider a document as follows:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251010120016.png]]
- there are repeated information in each new document
- at the end of the day we will have 200 new documents for each truck
- we will have some fields repeated like id, driver and date

- an **alternative** is to use an *embedded document* as the follow, with the constant fields outside and the variable keep in a list:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251010120133.png]]
- but like this we can have potential **performance problem


### Planning for Mutable Documents 
- When a document is created the DBMS allocates a certain amount of space for the document (usually more than the document size)
- if the document *grows more* than the allocated space, the DBMS has to *relocate* it to another location
- moreover the DBMS *must free* the previously allocated space 
- those operation can adversely affect the system performance

- one solution is to allocate sufficient space at the moment in which the document is created. so we have to consider the *life cycle* of a document and use strategies to handle its grow. for example for the truck problem, we know in advance that we will allocate 200 element in the array at the end of the day. *But we have to know the lifecycle of the document, not always*, we have to consider how often and how much the document will grow and estimate the final size

### Indexing document database
- In order to avoid to scan al the db, some DBMSs for document database (e.g. MongoDB) allow the definition of **indexes**
- indexes are a *structured set of information* created by the DBMS that maps from one attribute to related information

- in general *indexes* are a special data structures that stores a small portion of the collection's data set in an **easy to traverse** form 
- the index stores the value for a field or set of fields **ordered by the value of the field**
- the ordering of index entries support *efficient equality matches* and range-based query operations

- one index is defined on one or multiple attributes, in the example below the score, we order the score in ascending order with our DBMS, when we have a new document we generate a new index that point to the value, if you have new document with the same value of a field we can use the same index 

- example:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251010121209.png]]


##### Read heavy applications 
- **Read heavy applications**: in this kind of applications, the use *of several indexes*, allowing the user to quickly access to the database, for example indexes can be defined for easily retrieve document describing object related to a specific *geographical region* or to a specific type, e.g. business intelligence and analytics applications
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251010121515.png]]


##### Write-Heavy Applications
- the example of the truck application (a transmission each tree minutes) is an example of a write heavy application 
- the *higher* the number of indexes adopted, the higher the amount of time required for closing a write operation 
- all the indexes must be **updated** and **created at the beginning** 
- *with a reduced number of indexes we can have faster write operation responses, but slower reading operation*, so there is a trade-off 


### Transaction Processing System 
- The **Transaction Processing Systems** are designed for fast write operation and *targeted reads*
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251010140538.png]]
- we have two module, one for read operation and OLAP operation and the other one for write operation, we can have different format database in the two module (e.g. relational in one and document in the other one), usually the write one have normalized data and read one have denormalized data, in read there are several indexes and in the write we could not have any

### Sharding
- **Sharding** (or *Horizontal Partitioning*): is the process of dividing data into blocks or *chunks*
- each block is labeled as **shard**, is deployed on a **specific node** (server) of a **cluster**
- usually each node contain only one shard
- in case of *data replication* a shard can be hosted by more than one node
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251010140821.png]]

- *Advantage* of sharding:
  - allow the handling of *heavy loads* and the *increase* of system users
  - data can be *easily distributed* on a variable number of servers that may be *added* or *removed* by a request
  - is *cheaper* than vertical scaling 
  - combined with replication ensures an *high availability* of the system and *fast* responses
 

### Shard Key
- to implement sharding, a document database designer have to select a **shard key** and a **partition method**
- a shard key is *one or more fields*, that *exists in all documents* in a collection that is used to separate documents
- example of shard key can be a document id or the timestamp
- **any atomic field** in a document can be chosen as a shard key
- the sharding key should never be a missing attributes

### Partition algorithm
- There are three type of partition algorithms:
  - **Range**: you can use a numerical attribute as sharding key to divide document in range (e.g. you can divide documents with a date field in monthly shards)
  - **Hashing**: a hash function is used on the sharding key to determine where to place a document. *Consistent hashing* can also be used
  - **List**: you can use a categorical attribute (e.g. type) as a shard key to allocate document in different servers


- hashing is not always the best solution, yes it can distribute evenly the data, but with date range for example we can do some operations in a much more efficient way (so the range solution), but also use the list solution and memorize different category of data in different servers could be useful 


# 8 Document databases Design Tips

- **Collections** are *sets* of documents
- a collection can store documents of **different type** (you don't need a specific structure or scheme for a document)
- in general collection *should store documents of the same type of entity*


- **Type of entity**: 
  - web clickstream data: say that someone click on a link
  - server log data: say a log data
- are they the same entity or they should be different entities? it depends on how we are going to use those information, they can be the same entities or different instances of different entities 

- but we can create collection with both types on entity (mixing document)


- Mixing document types in the same collection can lead to *multiple document types* in a **disk data block**
- it is useful when the two types of entities are often read together, if not read together lead to inefficiency because you scan the entire collection but only consider half of the information for some information, in this case create two different collection is more convenient 
- this can lead to *inefficiencies* whenever the data is read from disk but not used by the application that filters documents based on type
- **Filtering collection** is often *slower* than working directly with multiple collections, each of which contains a single document type


- The code written for *manipulating* collection, should have:
  - A **substantial** amount of code that apply to all documents
  - **Some** amount of code that accommodates *specialized fields* is some documents

- the case of **High-Level Branching** like in the figure underneath, can indicate a need to create *separate collections*
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251010143823.png]]
- high level branching is used when different type of data are in the same collection, low level is used when in the collection entities have almost all the same attributes and then just some little different to manage at the end (in the above example the value of the attribute *ebook*)
- if you have to much high level code maybe you need more than one collection

- **Branching at lower level** is common when some documents have *optional attributes*

- ***NOTE***: **keep the data in the code less possible, use an instance of a class to retrieve and update data and commit instantly the new update in the database, don't continue to work with da data inside the code**

### Follow the definition of Queries
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251010143927.png]]

- our application have to be able to answer the following queries:
  - What is the average number of products bought by each customer?
  - What is the range of number of products purchased by customers
  - What are the top 20 most popular products by customer state?
  - What is the average value of sales by customer state
  - How many of each type of product were sold in the last 30 days?

- we can create a document for the common part and a document for each type of specialization (so four type in total)
- we should have a collection with everything or tree different collections? **it depends on the requirements and query**
- if the query are mainly regards the common attribute it's better to have one collection, if the query are more about specific attribute is better to have distinct collection



![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251010143927.png]]
- immagine now to have a customers connected with the general entity product in a n to n relationship, we need now to design a collection for the customers with a fields with an array of object with the id of the product that he bought and the price, types
- given the same class diagram we can have very different structure of our database, based on the requirements 



![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251010144050.png]]
- if we separate the product into different collections, and the number of product types grows the number of collections would become *unwieldly* 

##### Normalization and Denormalization
- **Normalization** helps *avoid data anomalies*, but it can cause *performance problem*
- with normalized data we need *join operation* (which reduce the system performance), which must be optimized for improving performance

- if we use **Denormalized** data, we may introduce *redundancies* and cause anomalies
- on the other hand it can improve the performance of the queries because we reduce the number of collections and *avoid join operation*
- denormalization supports improving read operation when indexes are adopted


- it is possible to shard information on the same entity on more than one file, you can shard on attribute like category, time, ecc..., but this make more difficult to analyze the info in it




# 9 Graph Database Design

- **Graph**: a collection of Vertices and Edges that connect vertices
- **Vertex**: specifies an instances of an entity, (usually entity belong or not to the same category, e.g. "Rome" instances of the city entity)
- **Edge**: specifies a relation between two vertices (can be a short term relation or a long term relation), it is possible to have some value about the *strength* of the relationship

- Vertices and Edges may have *properties* (attributes associated to entities and relationship)


- **IMPORTANT**: one typical error is to output the nodes' ID as a result of a query and not the associated name of those entities, another error is to do a *join operation* to show those attributes, is much better to have redundancy
- you can also not save all the information on the graph because it will use a lot of space, the better solution is to save only the attributes required for the most frequent queries


##### Example: modeling highways
- In this case each city is a vertex, and an highway could be an edge between cities, or we can use two edges, one for each travel direction
- the right way to choose how to model the edges (if use one or two) depend on the details that we want to represent. e.g. if we want to know only the connection between cities you can use just an edge between two nodes, but if you want to know the exact time for traveling from one city to another, and it's different in the two direction, then you need two edges

### Graph Databases
- **Graph Databases** adopt vertices and edges to *store* explicit *relationship* between *entities*
- in relational db connection are not represented as link, but as *common attribute value*, known as a *key*, then join operations are used to find connection or link, but this kind of operation becomes computationally expensive when we deal with huge amount of data
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251019103755.png]]


- Graph databases allow also to model **many-to-many relations** easier than relational databases
- Edges allow to *explicitly* modeling n to n relations rather than using a new table
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251019103914.png]]



### Modeling Multiple Relations between Entities
- **Different** type of relations between entities may be handled exploiting *multiple type of edges*
- Multiple type of edges can be obtained specifying **different values of the edges properties**
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251019104059.png]]

# 10 Graph Database Insights

- a vertex can represent any **instance** of an entity, that can have *relation* with other entities
- edges can have properties too, e.g. in the highways example we can have distance, speed limit and number of lanes
- usually relationship have also a **weight**, a value that represent some value about the *strength* of the relationship
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251019105033.png|300]]

- Edges can have a *Direction*, the presence or not of a direction depends on *specific applications*
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251019105120.png|200]]


### Path in a Graph
- A **Path** through a graph is a *set of vertices* along with the edges between those vertices, path allow us to capture information about the relations of vertices in a graph
- there may be *multiple path* between two vertices, often we want to *find the best* (e.g. the shortest)

- A **Loop** represent a *relation* that a vertex has with *itself*, the presence of loop may not have sense in some specific domains
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251019105423.png|200]]

- you can intersect and union graphs:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251019105441.png|300]]

- **Graph Traversal** is the process of *visiting all vertices* in a graph
- the purpose of this is usually to either *set* or *read* some property value in a graph
- usually we want to *minimize the cost* of the path

### Isomorphism
- Two graphs are **Isomorphic** if:
  - *for each vertex* in the first graph there is a *corresponding vertex* in the second graph
  - *for each edge* between a pair of vertices in the first graph, there is a *corresponding edge* between the corresponding vertices of the other graph
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251214155026.png]]
- detecting isomorphism allow to identify **useful patterns**


### Order and Size of Graphs
- **Order**: number of vertices
- **Size**: number of edges
- these two measures are important to evaluate time and memory occupancy required to handle specific operations

 
### Degree and Closeness of a Vertex
- **Degree**: the number of edges linked to a vertex, it measures the *importance* of any given vertex in a graph
- useful for instance to evaluate the spread of disease in a graph of connected person 

- **Closeness**: it measure how far the vertex is from all others in the graph, it can be calculated, in a fully connected graph, as the **reciprocal of the sum** of the length of the *shortest path* between the node and all other nodes in the graph
- it is useful to evaluate the speed of information spreading in a network


### Betweenness of a Vertex
- **Betweenness** is a measure of how much of a **bottleneck** a given vertex is (so how much problem it generates if it is disconnected from the graph)
- in the example, vertices 1 and 2 have *high betweenness* levels, they form a bottleneck, and if they are removed, it would leave the graph *disconnected*
- we can use various measures of betweenness 
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251019112701.png]]


### Flow Networks
- A **Flow Network** is a *direct graph*
- it adopts *capacitated* edges
- each vertex has a set of *incoming* and *outcoming* edges
- in each vertex, the **sum of the capacities** of incoming edges *cannot be greater* than the sum of the capacities of outcoming edges
- the unique exception to the previous rule are the **source** and the **sink** nodes (the sink is the final destination node, in this case we don't have a true sink node)
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251019112937.png|300]]


### Bipartite Graph
- in a **Bipartite Graph** there are *two distinct sets* of vertices
- each vertex is connected only with vertices of *the other set*
- it can be used for example to model relationship between students and professors
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251019113014.png]]


### Multigraph
- A **Multigraph** is characterized by the presence of **multiple edges** between vertices
- in the example above, each edge may represents a *different way* to ship item between cities
- each edge can be equipped with **different sets of properties**
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251019113008.png]]




# 11 Graph Database Tips

- It is not easy to decide which no SQL db adopt for a solution, it is important to consider the **kind of queries** that the application will perform on the data
- **Graph Database**: are *suitable* for problems domains easily described in terms of entities and relations (e.g. network)

- query examples:
  - how many *hops* (edges) does it takes to get from vertex A to vertex B?
  - how many edges are linked to vertex A
  - if vertex C is removed, which part of the graph become disconnected

- so in those kind of queries there is *less emphasis* on **selecting** by particular properties, and **aggregating** values across a group of entities. Moreover they are **fairly abstract** (so it has to be translated), designer needs to *translate* queries from the problem domain to the *domain of expert* working on graphs

- queries for graph database shouldn't have selection by some attributes or joining operation 

##### Example
- Let suppose to design a DB for handling movies, actors and directors.
- Let suppose to offer the following services for users:
	1. Find all the actors that have ever appeared as a co-star in a movie starring a specific actor (for example: Keanu Reeves).
	2. Find all movies and actors directed by a specific director (for example Andy Wachowski).
	3. Find all movies in which specific actor has starred in, together with all co-stars and directors

- in relational models SQL lacks the syntax to easily perform graph traversal, especially where the depth is unknown or *unbounded*
- performance degrades quickly as we traverse the graph, each level of traversal adds significantly response time to a specific query

- in the first query we start by selecting a person called Kenue Reves, then we join with actor, join with movies, join again with actor, and join again with people, this require a lot of time and memory 
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251214155802.png]]



- with graph db the operation is much easier, there are way to easily translate high level graph query with low level query language
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251019100106.png]]
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251019095844.png]]


##### Example of social network
- Let consider the database developer as the main actor of the social network. The main use cases may be:
1. Join and leave the site
2. Follow the postings of other developers
3. Post questions for others with expertise in a particular area
4. Answer posted questions
5. Suggest new connections with other developers based on shared interests
6. Rank members according to their number of connections, posts and answer 

- entity and properties:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251019100240.png|500]]


- considering the two entities in our db we have four *candidate* relationship:
  - dev - dev
  - dev - post
  - post - dev 
  - post - post
- as the number of entities grows you should focus on relationship based on the requirements

- if a developer follow another developer he should be able to see his post. the **depth of the path**, so how many edges traverse for identifying the interesting posts is a parameter that can be defined and handled at a level of *application code*

- we also need the relation between developer and post to see who create the post

- **undirected edge** are created as two pointer in code, so it will use double the memory

- we need a relationship between post to model that a post answer to another post
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251019100927.png]]


### Mapping Queries
- Queries **drive** the design of graph databases
- *Domain-specific* queries must *be translated* into **Graph-centric queries**, after the identification of entities and relations between entities
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251019101940.png]]

### Basic Steps for Designing a GraphDB
- Steps:
  - Identify the **queries** you would like to perform
  - Identify **entities** in the graph
  - Identify **relations** between entities
  - *Map* domain-specific *queries* to more abstract (graph-based) queries
  - *Implement* graph *queries* and use **graph algorithms** (graph algorithm are also available in the DBMS)

### Advices
- Pay attention to the *dimension* of the graph, the bigger the graph, the more computational expensive will be performing queries and the more difficult will be to retrieve information 
- if available, define and use **indexes** to improve retrieval time
- Use **appropriate type of edges**:
  - for *symmetrical* relations, use *undirected* edge, otherwise *direct* edges (they require less memory)
  - properties requires memory, if possible, **use simple edge** without properties, and pay attention to the data type of properties. use less property as possible, only put necessary property
- **Watch for cycles** when traversing a graph, in order to avoid endless cycles, use appropriate data structure to **keeping track** of visited nodes
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251019102518.png]]

### Scalability
- most of the first implementation of graph databases did not consider the deployment on cluster of servers (so they don't have *data partitions nor replicas*), indeed they were designed for running on a *single server* and they could be only *vertically scaled*
- the developer must pay attention to the growing number of:
  - nodes and edges
  - user
  - number of properties and their size
 



# 15 Guidelines for Selecting a Database
- Step to design a software application: 
  1) *Requirements elicitation* from customer
  2) *Requirements definition* (you have to define functional and non functional requirements)
  3) *Use cases definition*, this is usually done with UML diagrams or with some simple mockup. It's not a static approach, we can ask for feedback from the client and iterate to improve use case 
  4) Identification of the main data structure (including the main procedures) and the relations among them (**Analysis Workflow** step)
  5) Refinement of step 4 (**Project Workflow** and *DB Design*)
  6) *implementation* and *test*
  7) *Deploy* the application

![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251028115227.png|300]]

### Role of the Architect
- The **Role of the Architect** is to identify:
  1) Software and hardware architecture
  2) Programming languages and development environment
  3) Database management system

- Every choice must be driven by:
	- Requirements
	- Experience
	- Common sense

### Are Relational DB still useful?
- **Relational DB** are useful for **data integrity** and reducing the **risk of anomalies**, thanks to immediate consistency and ACID transaction support
- They are still used to support *transaction* processing system and for *OTPL* applications
- Moreover we have decades to experience that led to *best practice* and design principles that continue to meet the needs of business, governments and other organizations
- They can also cooperate with other types of DB

### Modern Application World
- Modern data management infrastructure use a wide range of application and data type. 
- We need to manage:
  - Big Data
  - IoT
  - Large scale web application 
  - Mobile application 

- and in these cases **performance** and **availability** are more important than *consistency* and *ACID transaction*


### Available Choices
- Based on our requirements, analysis and project workflow, we can choose among:
	- **Relational databases**, such as PostgreSQL and MySQL,
	- **Key-value databases**, such as Redis, Riak, and DinamoDB
	- **Document databases**, such as MongoDB and CouchDB
	- **Column family databases**, such as Cassandra and HBase
	- **Graph databases**, such as Neo4j and Titan 


### Requirements Guide Us
- Requirements are **the most important thing** to decide what kind of database exploit in out application
- Functional requirement are related to the *type of queries* that describe how the data will be used, they also influence the *nature of relations* among entities and the *needs of flexibility* in data models

- Non functional requirement are also important, e.g.:
  - The *volume* of reads and writes
  - *Tolerance* for inconsistent data in replicas
  - *Availability* and *disaster recovery* (how much is important to not loose data, it influence the number of **replications**) requirements
  - *Latency* requirements

### Key-value DB
- **Key value DB** are used for *simple data model* (little number of entity and simple relations between them)
  - the application has to handle *frequent but small* read and write operations
  - *simple query* are needed

- this kind of DB do not allow too much flexibility and the possibility of making queries on different attributes

- **Typical use case**:
  - *Caching data* for relational database to improve performance
  - *Tracking* **transient attributes** in a web application (e.g. shopping cart)
  - *Storing configuration* and used data *information* for mobile application (so if can be used as a substitution for configuration file)
  - *Storing large object* such as images and audio, to quickly retrieve them

### Document DB
- **Document DB**  are suitable for applications that need:
  - To store varying attributes, in terms of number and type
  - To store and elaborate large amount of data
  - To make complex queries (on different types of attribute), to use indexing and to make advanced filtering on attributes.

- *Flexibility* is the main feature of document databases, along with high performance capabilities and easy of use.
- *Embedded documents* allow to use few collections of documents that store together attributes frequently accessed together (denormalization).

- **Typical use case**:
  - Back-end support for websites with *high volumes* of reads and writes
  - Managing data types with *variable attributes*, such as products
  - Applications that use *JSON* data structures 
  - Applications benefiting from *denormalization* by embedding structures within structures

### Column DB
- **Column DB** are used for application that:
   - Require the ability to *frequently read/write* to the database
   - Are *geographically distributed* over multiple data centers
   - Can tolerate some *short-term inconsistency* in replicas
   - Manage *dynamic fields* 
   - Actually have to deal with *huge amount of data*, such as hundreds of terabytes

- avoid them if the data can be handled by a single server

- **Typical use case**:
  - Security analytics using network traffic and log data mode
  - Big Science, such as bioinformatics using genetic and proteomic data
  - Stock market analysis using trade data
  - Web-scale applications such as search
  - Social network services

### Graph DB
- **Graph DB** are used for application that:
  - need to represent their domain as a *network* of connected entities
  - handle instances of entities that have *relations* to other instances of entities
  - require to *rapidly traverse* path between entities 

- it is possible to build networks for specific use cases, even if original data are not connected we can connect them 

- e.g. Two orders in an e-commerce application probably have no connection to each other. They might be ordered by the same customer, but that is a shared attribute, not a connection.
- but we can put the data in a graph and do recommendation of products to similar users based on what other users buy 

- **Typical use case**:
  - network and IT infrastructure management
  - business process management
  - recommending products and services
  - social network


### Use multiple types
- We can use different types of DB in a single application **concurrently**

- **Typical use case**:
  - *Large scale graph processing* such as large social network can use *column families database* for storage and retrieval, and a graph in-memory database for graph operation
  - OLTP handled with a relational database and use OLAP (MongoDB) for fast analytics

- using different types for manage data can be difficult for consistency, it is a sort of replication 




# 1 Object Oriented Programming
##### Class and Objects
- the **class** is the *unit of programming*
- a java program is a *collection of classes*
- each class definition is in its own **.java file**
- and the file name match with the class name

- a class describes **objects** (*instances*), it describe their common characteristics, that can be:
  - *Data fields*: attributes of the object
  - *Methods*: operation that that the object can do
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251019145000.png]]

- **encapsulation**: pack code in object and allow to define which part are accessible
- **static classes**: a class defined *inside another class*, doesn't require an instances of the incapsulating class to instantiated it
- a **static method** can be called without an instance, can be used as utility function 

- **polymorphism**: is the ability to create a variable, a function, or an object that has *more than one form*
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251019145105.png]]
- in java you can implement polymorphism with *overloading* and *overwriting* 

- **overloading** (*compile time polymorphism*): you can implement method with the same logic, but that change a bit based on the input (it is polymorphism because you are developing method with the same name, but with different behavior, this can help code readability and flexibility) ![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251019145206.png]]
- **overwriting** (*run time polymorphism*): exploited when you have inheritance between classes, create classes that inherit from a class, and redefine  some method to have a different behavior (the new method have to have same name and signature)
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251019145213.png]]

- **Reference Variables**: store the address of an object
- we can declare reference variables to reference *object of a specified types*
- two reference variables can reference the same object
- the **new** operator creates an instance of a class
- a **constructor** is a method executed when a new object is created

- a method that is *not static* is called an **instance method**
- al method argument are **call by value**

- **JDBC**: standard Java API to connect Java applications to relational databases
- **Maven**: build and dependency management tool for Java projects




# 3 RESTful APIs
### Event Description Enhancer Service
- **Event Description Enhancer Service**: used to enrich the description of an event

- **REST** (*Representational State Transfer*): an architectural style used to design networked applications, particularly to implement web services
- Its a loose set of rules that is used as a standard de facto for building API

- **REST APIs**: are a standard used to facilitate communication between clients and servers and is based *over HTTP* by using standard HTTP methods (GET, POST, PUT, DELETE) to operate on resources



-  **REST** is just a ***loose set of rule*** to expose API, is not a specification
- **RESTful API**: an API that follow the REST standard
- restful is a way to manage and offer resources

- **Resources**: any piece of information that can be named, such as a user, document or product
- each resources is represented by a **URI** (*Uniform Resource Identifier*)
- a RESTful API organizes resources into a set of unique URIs. 
- so *a resource is identify by a unique URI*
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251019165805.png]]

### HTTP Methods in REST APIs
- HTTP Methods:
  - **GET**: retrieve a resource
  - **POST**: create a new resource
  - **PUT**: update an existing resource 
  - **DELETE**: remove a resource
  - **PATCH**: partial update of an existing resource
  - **OPTIONS**: used for HTTP methods, can be used to see other methods
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251019170055.png|300]]



 
- ***Convention***: The **resources should be grouped by noun and not verb**, an API to get all products should be: https://site.com/api/v1/products (not getProducts)
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251019170147.png]]
- NOTE: we do this because we also specify the action to perform on the resource (e.g. GET) and it will be redundant to write it also in the API 


### Introduction to REST APIs
- **Clients** interact with resources by sending requests to manipulate or retrieve them, and the **server** responds with *the current state of the resource or the result of the action*
- in this example a client is using an HTTP method on a resource and the server is giving back the requested information via a JSON file (the standard to exchange information in RESTful API (it is also used XML, but less))
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251019170248.png]]


- Example of request:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251019170317.png|600]]
- in the body of these requests there could be *an optional HTTP request body* that contains a **custom payload of data** (here the details of the product), usually in JSON format:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251019170421.png|600]]
- the server receives the request, processes it and **formats the result into a response**
- the *first line of the response contains the HTTP* **status code** to tell the client what happened to the request, in this case the code 200 means that the operation was a success 
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251019170606.png]]
- A well-implemented RESTful API returns proper HTTP status codes

### A REST implementation should be Stateless
- A REST implementation should be **Stateless**, so the two parties don't need to store any information about each other and *every request and response is independent from all others* (don't need to memorize the state of the request, this allow to occupy less memory and manage more client because you are using an easier logic)
- this lead to application that are **easy to scale** and well-behaved


### Idempotence
- An API is **Idempotente** when making multiple identical requests has the same effect as making a single request (POST and DELETE aren't idempotent, *da rivedere*)
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251019175732.png]]


### Pagination
- if an API endpoint returns a **huge amount of data, then use pagination**, a common pagination scheme uses *limit and offset*, if they are not specified, the server should assume sensible default values
- pagination return a subset of the data, instead of sending all the data in a unique answer (like the item of Amazon divided in pages), this can improve performance, memory usage, and allow a greater scalability
- in pagination we define **limit** (the number of item per page) and **offset** (the initial position)
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251213153938.png]]


### Versioning
- **Versioning** of an API is very important, it allows an implementation to *provide backward compatibility*, so that if we introduce breaking changes from one version to another, consumers get enough time to move to the next version
- there are many ways to version an API, the most straightforward is *to prefix the version before the resource on the URI*
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251213153945.png]]


## Best practice to implement RESTful APIs (Summary)
- use **nouns** in endpoints *(e.g., /events instead of /getEvents)* and NOT USE VERB
- leverage HTTP **status codes** *(e.g., `200 OK`, `201 Created`, `404 Not Found`, `400 Bad Request`)* YOU CAN FIND THEM ONLINE
- **statelessness**: *each request should be self-contained* CLIENT AND SERVER DON'T MEMORIZE INFO ON EACHOTHER, ALL THE INFORMATION NEEDED ARE IN THE REQUEST ITSELF
- **versioning your API** *(e.g., /api/v1/events)* PUT THE PREFIX OF THE VERSION BEFORE THE URI
- **secure you API** with authentication and authorization 


## Java Spring Boot
- **Java Spring Boot**: a framework to develop RESTful web services in Java

## OpenAPI
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251019183049.png|300]]

- The **OpenAPI Specification** (*OAS*) is a *standardized format* for describing RESTful APIs
- it allows developer to define:
  - endpoint
  - request structure
  - response structure
  - data types 
  - authentication methods
- and other essential aspects of an API in a *machine-readable* format (usually JSON or YAML(**a human-readable data serialization language that is often used for writing configuration files**))

- the OpenAPI specification is often used to generate *API documentation*, client SDKs and server stubs **automatically**

- SDK stands for **software development kit**. Also known as a devkit, the SDK is a set of software-building tools for a specific platform, including the building blocks, debuggers and, often, a framework or group of code libraries such as a set of routines specific to an operating system (OS)

- A **server stub** is a small piece of code that acts as a *middleman* between a client and a real server program
- It receives requests from the client, unpacks the data, and then calls the actual server function. When the server finishes, the stub packs the result and sends it back to the client.


### Springdoc OpenAPI
- **Springdoc OpenAPI** is a library that helps *integrate the OpenAPI specification into Spring Boot applications*
 - it automatically generates OpenAPI documentation for your REST services, based on the annotations in your spring boot code
 - it also **provides an interactive Swagger UI** for *testing and interacting with the API directly from the browser*


## Swagger
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251019184340.png|200]]
- **Swagger** is a set of open-source tools built around the OpenAPI Specification that help design, build, document and consume RESTful APIs
- it provides a way to *generate interactive documentation* for your APIs and makes it easy for developers to explore, understand, and *test the API endpoints*

- it is basically a web service that allow user to test if a certain logic is working
- Swagger simplifies testing and document APIs, it provides an interactive swagger ui for API testing
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251019184618.png]]

- example of Swagger UI which is an example of RESTful API documentation 
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251019184659.png]]
- you have the possibility to see the HTML with all the *exposed endpoint details*
- **POSTMAN**: a rest client that provide the user to configure automatic test and collection to show the functionality of an application 



# 17 Introduction to MongoDB
- MongoDB is a document database that stores data in BSON documents, the document are organized in collections where they can be queried, data have a flexible schema, so different document can have different fields, thanks to sharding it makes easier to scale horizontally the db
- when you create a new documents, MongoDB assign to it an unique object id (\_id) which is unique to that collection
- secondary index allow to make common query extremely fast
- it support geodata, it also support data aggregation pipeline which can group document together and reduce to a single result


- **MongoDB** (Hu**mongo**us **DB**) is:
  - Open source
  - Document based
  - high performance, high scalability and availability
  - can use different configuration on **CAP triangle** (usually CP and AP)



### Data Model
- **MongoDB** is a *document based* DB, it can manage max 16 MB of data *per document* (there are way to increase it thanks to an abstraction that divide bigger documents in chunks, but we will not use them)
- documents are in **BSON format**, it is similar to JSON, composed in *field-value* pairs
- each document is stored in a *collection*, documents in the same collection usually share a *common purpose*

- **Collections** are like *tables* in relational DB, the documents in a collection *do not* need to have **uniform structure**, but have a **set of index** in common


- **JSON** is an unordered collection of field-value pairs, with 6 main *data type* (string, number, object, array, boolean, null), object can be nested, *fields are not ordered*, but array elements are

- **BSON** (*Binary JSON*): is a **Binary-encoded serialization** of JSON-like docs
- it extends the JSON model, providing:
  - **new data type**
  - **ordered fields**
  - **efficient** encoding and decoding for a lot of languages
- it provides a lot of things to improve the performance of data modifications 

- New BSON types (the ones not highlighted):  
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251109174139.png]]

### Documents in MongoDB
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251109174155.png]]
- the **advantages** of using documents are: 
  - document correspond to **native data type** in many programming languages (you can have a documents with the same fields as a Python class instance) 
  - **embedded documents** and **array** reduce need for *expensive joins* 
  - **dynamic schema** supports fluent *polymorphism* (because you can change which fields you want in each document)

- if you design well the DB based on your requisite, you won't need any join operation 

### The \_id Field
- By default, each document contains an **\_id field**, this field has several special characteristics:
  - it is automatically created if you don't create it
  - is used as **primary key** for collection
  - is **unique**, **immutable** and **non-array** (any non-array type can be used as a pk) 
  - by default its type is *ObjectId* which is small, unique, fast to generate and ordered
  - Sorting on ObjectId is roughly the same as sorting on creation time

- it is usually one part of the *sharding key*

### Key Features of MongoDB
- **High performance**: MongoDB provides:
  - high performance data *persistence* 
  - support for *embedded data models* to *reduces I/O activity* on database system
  - *index* support for *faster queries*, and can include keys from embedded documents and array

- **Rich Query Language**: MongoDB supports a *rich query language* to support:
  - read and write CRUD operation
  - data aggregation
  - text search 
  - geospatial queries

- **High Availability**: MongoDB's replication facility is called *replica set* and provides:
  - automatic failover
  - data redundancy (this give us the possibility to make answer a secondary server to a request and increase the performance)

- **Horizontal Scalability**: MongoDB provides horizontal scalability as part of its core functionality:
  - *Sharding* distributes data across a *cluster of machines* (we will not use shard in the course) 
  - MongoDB supports creating *zones* of data based on the *shard key*
  - in a balanced cluster MongoDB directs read and writes covered by a zone only to those shards inside the zone

### Core Processes
- core components in MongoDB:
	- **`mongod`** is the main process that **stores the data and handles database requests**.
	- **`mongos`** is the **query router** that directs client requests to the correct servers in a sharded cluster.

- **mongo** (*old version*): the interactive MongoDB shell, it is transitioning to **mongosh** (which is shipped with MongoDB Compass) 

### Replica Architecture
- the replica architecture of MongoDB, have a client application that use a driver to do read and write operation to a primary server, and the primary server implement consistency, so propagate the operation information on secondary server
- it is also possible to read info from secondary server to balance read operation, if you are using *eventual consistency* then you risk to access old version of the data
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251109214414.png]]


### Sharding Architecture
- MongoDB shards data at the **collection level**, distributing part of a single collection across the shards in the cluster
- in this simple sharding scheme, there are 4 shard, for each shard we have a primary and two secondary server, we need also a server called Config Server that also have one primary and two secondary that contains metadata to answer the request that the user do to the system, this allow to make the request to the correct shard 
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251109214444.png]]


### MongoDB vs. SQL
- the main differences between MongoDB and SQL:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251109214521.png]]
- MongoDB doesn't need normalized data

### Mongo Shell
- The mongo shell is an **interactive JavaScript** interface to MongoDB
- We can use the mongo shell to **query and update data** as well as perform *administrative operations*

To connect to a MongoDB instance:
```
mongosh "mongodb://localhost:27017"
mongosh "mongodb://mongodb0.example.com:28015" --
username alice --authenticationDatabase admin
```

To shutdown the server (from the shell)
``db.shutdownServer()``


Check the list of databases:
```
show databases (or show dbs)
```

Display the database currently used:
```
db
```

Switch databases (\<database> is the name of a specific database):
```
use <database>
```


Create both the database myNewDatabase and the collection myCollection during the insertOne() operation:
```
use myNewDatabase
db.myCollection.insertOne( { x: 1 } );
```
### Mongo ATLAS: Cloud Service
- **Mongo Atlas**: is a service that allow to manage mongo DB instances on the cloud without worrying about the underling infrastructure
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251109214604.png]]

 
# 18 MongoDB CRUD Operations
### Create Operations
- the **Create Operation** allow to add new documents to a collection
- if the collection does not exists, the *insert* operation will *create* the collection 
- insert collection target just one single collection
- write operation are *atomic* to the level of a single document (atomicity is not assured for the entire operation when insert many file)

- each document stored in a collection requires a **unique_id field** that act as a primary key
- if an insert operation omits the *unique_id* field, then it will be automatically generated by MongoDB 


### InsertOne() Operation
- the command **InsertOne()** insert a document into a specific collection 
- here we are inserting a document with the fields name, age and status in the collection users:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251114134207.png]]

### insertMany()
- **insertMany()** can insert *multiple* documents in a collection 
- it takes as input an array of documents, and by default they will be inserted *in order*

- in this example we insert three documents to the inventory collection:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251114134552.png]]

### Query Documents
- let suppose to have the following collection in the DB:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251114134650.png]]

- this is an example of selecting all the document from the collection inventory (**SELECT * FROM INVENTORY** -> *db.inventory.find()*):
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251114134813.png]]



### Specify Equality Condition
- to specify **equality condition** you need to specify a "*field: value*" expression in the *find()* function 
- e.g. **SELECT * FROM inventory WHERE status = "D"** -> *db.inventory.find({status: "D"})*
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251114135147.png]]


### Specify Conditions Using Query Operators
- a query filter document can use the **query operator to specify conditions** in the form: "*{field1: {operator1: value1}, ...}"

- e.g. **SELECT * FROM inventory WHERE status in ("A", "D")** -> *db.inventory.find({status: {$in: \["A", "D"]}})*

### AND Conditions (,)
- The following example retrieves all documents in the inventory collection where the status equals "A" and qty is less than (**$lt**) 30
- e.g. **SELECT * FROM inventory WHERE status = "A" AND qty < 30** -> *db.inventory.find({status: "A", qty: {$lt: 30}})*
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251114135722.png]]


### OR Condition 
- The following example (last query in the figure) retrieves all documents in the collection where the status equals "A" or qty is less than ($lt) 30
- e.g. **SELECT * FROM inventory WHERE status = "A" OR qty < 30** -> *db.inventory.find({ $or: \[{status: "A"}], \[{qty: { $lt: 30}}]})*
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251114140005.png]]


### AND and OR conditions 
- In the following example, the compound query document selects all documents in the collection where the status equals "A" and either qty is less than ($lt) 30 or item starts with the character p:
- **SELECT * FROM inventory WHERE status = "A" AND ( qty < 30 OR item LIKE "p%")** -> *db.inventory.find({ status: "A", $or: \[ {qty: { $lt: 30}}, {item: /^p/}]*
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251114143015.png]]


### Comparison between operators
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251114143049.png]]


### Update Documents 

- There are three functions to update documents:
  - updateOne
  - updateMany
  - replaceOne (change all the structure except for the id)

- in each of them you specify:
  - **filter**: a query that specify what documents modify
  - **update**: specify what modification apply
  - **options**: specify a set of parameters for the modifications 

- in the *update* operator we need to specify the fields to modify and the new values, you alse need to specify an **update operator** that says what kind of update operation you can do (add, subtract, divide, multiply)
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251114143627.png]]

- Some update operators, such as $set, will create the field if the field does not exist

### Update operator 
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251114143727.png]]

- let's now consider a new database:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251114144059.png]]

### Update a Single Document
- in this example we use the method *updateOne* to update the first document where item equals paper
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251114144232.png]]
- the **$set** operator updates the value of the field size.uom to "cm" and the value of the field status to "P"
- the **$currentDate** operator update the value of the last modified field to the current date, and will create the field if it do not exists 

### Update Multiple Documents
- The following example uses the db.collection.updateMany() method on the inventory collection to update all documents where qty is less than 50
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251114144500.png]]

### Replace a Document
- to replace the *entire content* of a document (except the id), it is possible to pass an entire document as the second argument of replaceOne 
- the replacement document cannot include update operation expression 
- the replace document can also have *different fields* from the original one 
- e.g. we replace the first document from inventory where item = "paper"
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251114144809.png]]

### Delete Documents
- to delete all documents in a collection, pass an *empty filter* to the deleteMany. method
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251114144928.png]]
- after the ack you have back the control, but it is not certain that the consistency is resolved

- but we can also specify *criteria* or filters that identify the documents to delete
- the filter are the same as the one for query operation 
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251114145049.png]]
 
- delete all documents where status = "A"
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251114145124.png]]

### Delete a Single Document
- to delete **at most** one file you can use the *deleteOne* method (the first one that respect the filter)
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251114145226.png]]


### Export Document 
- we can use the **mongoexport** command-line tool to produce a CSV or JSON export of the data stored in the database (it has to be run from the command line, NOT from the mongo shell)

- to export a **specified collection** to a specified output file from a *local MongoDB instance* running on port 27017:
 ![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251114145529.png]]

- to export from a specific host and port we can use this command:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251114145604.png]]
- you can specify the fields that you want export, and you can choose various formats 


### Import Documents 
- the **mongoimport** tool, imports content form an *Extended* JSON, CSV or TSV export created by **mongoexport** or another third party export tool (has to be run on the system command line, not the mongo shell), it only support *UTF-8 encoded file*, json has to be extended json version 2
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251114145843.png]]



### Backup vs Data Exchange Tools
- import and export operate on single file, and **doesn't preserve indexes**, sharding information and other, to preserve this information you can use **mongodump** and **mongorestore** that preserve *indexes*, *metadata* and *collection structure* 



# 19 Mongo DB Query 1
## Cursor Methods
### Loading Data
- the **find()** method returns a **cursor** to the results

- a **Cursor** is an object that maintains a connection to the result set returned by the server, retrieves documents gradually as they are read, it doesn't load all documents on memory all at once, but they load them *on demand*

- in the mongo shell if the returned cursor is not assigned to a variable using the var keyword, then the cursor iterated to access *up to the first 20 documents* that match the query
- to *manually iterate* over the results, assign the returned cursor to a variable with the var keyword

- the mongo shell and the **drivers** provide several cursor methods that call on the cursor returned by the find() method to modify its behavior

- example of cursor considering a collection `inventory`:
``` java
db.inventory.find();
var myCursor = db.inventory.find();
var myDocument = myCursor.hasNext() ? myCursor.next() : null;

if (myDocument){
   var myName = myDocument.item;
   print(tojson(myName));
}
```

### Find and Limit
- the **limit()** method limits the number of documents in the result set
- e.g. limit the result to at most *three* document: 
``` java
db.inventory.find().limit(3); 
```

### Find and Skip
- the **skip()** method controls the *starting point* of the results set
- e.g. skips the first 3 document
``` java
db.inventory.find().skip(3);
```

### Find and Sort
- the **sort()** method orders the documents in the result set
- e.g. returns documents in the inventory collection sorted in *ascending* (1) order by the qty field
``` java
dn.inventory.find().sort({qty:1});
```
- ascending order by status, and *descending* order (-1) by qty:
``` java
dn.inventory.find().sort({status:1, qty:-1});
```

- **NOTE**: *indexes* are effective only if the order of the index is the same as the order of the query

### Counting Documents
- The method **db.collection.countDocuments(query, options)** returns the *count* of documents that would match a find() query for the collection, it does not return the find result, only the number of documents
``` java
db.inventory.countDocument({status:"A"})
```

## Query on Embedded/Nested Documents
### Match an Embedded Document
- we can use a **query filter** to filter the match result
- e.g. find all the document where the size (a nested) field has value 14 for h, 21 for w and cm for uom
```java
db.inventory.find({size:{w:21, h:14, uom:"cm"}})
```

- you can also use the **dot notation** if you are interested in one of the nested fields
- e.g. all the document where the field uom is equal to cm:
```java
db.inventory.find({"size.uom": "cm"})
```

### Specify Match using Query Operator
- use a **little than ($lt)** operator:
```java
db.inventory.find({"size.h": {$lt: 15}})
```

### AND Condition:
- all documents where the nested field “h” is less than 15, the nested field “uom” equals "in", and the “status” field equals "D":
```java
db.inventory.find({"size.h": {$lt: 15}, "size.uom": "in", status: "D"})
```


## Query an Array
### Match an Array
- to specify an **equality condition on an array** you have to use the *query document* `{field: value}` where value is the exacted *ordered* value of the elements of the array
- e.g.  all documents where the field “tags” value is an array with exactly two elements, "red" and "blank", in the **specified order** (the order is important, the array have to be *Exactly the same*)
``` java
db.inventory.find({tags: ["red", "black"]})
```

- if we want to search for the element without considering the order (or there is other values) we use the operator **$all**:
``` java
db.inventory.find({tags: {$all: ["red", "black"]}})
```

- to query if the array field contains **at least one element** with the specified value, use the filter `{field: value}` where value is the element value:
``` java
db.inventory.find({tags: "red"})
```

- to use **query operator** `{field: {$operator: value}}`: 
``` java
db.inventory.find({dim_cm: {$lt: 15}})
```

- The following example, queries for documents where the “dim_cm” array contains elements that in some combination satisfy the query conditions; e.g., one element can satisfy the greater than 15 condition and another element can satisfy the less than 20 condition, or a single element can satisfy both:
``` java
db.inventory.find({dim_cm: {$lt: 20, $gt: 15}})
```

- The following example queries for documents where the “dim_cm” array contains **at least one element that is both** greater than ($gt) 15 and less than (\$lt) 20:
``` java
db.inventory.find({dim_cm: {$elemMatch{$lt: 20, $gt: 15}}})
```


- Using dot notation, we can specify query conditions for an **element at a particular index** or position of the array. The array uses zero-based indexing
- e.g. queries for all documents where the second element in the array “dim_cm” is greater than 15:
``` java
db.inventory.find({dim_cm.1: {$gt: 15}})
```


- Use the **$size** operator to query for arrays by *number of elements*
- e.g.  selects documents where the array “tags” has 3 elements:
``` java
db.inventory.find({"tags": {$size: 3}})
```


# 20 Projection operations and Aggregations in MongoDB

## Project Fields   

- by default queries in MongoDB return **all fields** in a matching documents
- to limit the amount of data that MongoDB sends to applications, we can include a **projection document** to specify or *restrict fields* to return

- a **projection** can explicitly include several fields by setting `field: 1` in the projection document, or exclude them setting `field: 0`
- the **\_id** field is always returned if not explicitly excluded
- e.g.
```java
db.inventory.find({status: "A"}, {item: 1, status: 1, _id: 0})
```

- if you don't set any field to 1, all the fields are set to 1, you just need to specify which fields exclude
- e.g.
```java
db.inventory.find({status: "A"}, {_id: 0})
```

- if you set something to 1, you will receive only the fields set to 1:
```java
db.inventory.find({status: "A"}, {status: 1})
```

- you can specify to return only some **embedded fields** using the *dot notation*
```java
db.inventory.find({status: "A"}, {status: 1, size.uom: 1})
```

- or exclude just specific embedded field
```java
db.inventory.find({status: "A"}, {size.uom: 0})
```

- for manipulate **fields that contains array** there are 3 operators: **\$elemMatch**, **\$slice** and **\$exists** 
- we *cannot project specific array elements* using array index 

- the **\$elemMatch** operator, when used in **projection**, returns **only the first array element that matches the specified condition**.  
- If no array elements match, the array field is **omitted** from the result.
```java
db.inventory.find({status: "A"}, {"instock:"{$elemMatch: {qty: {$gt: 20}}}})
```


- **$slice** allow to specify which documents (e.g. the first, the last, ecc) you want to return
```java
db.inventory.find().slice(-1)
```



- the `{item: null}` query matches documents that contains the value of item equal to *null* or that does not contain the item field in the document


- it is possible to query documents that contains field of a **specific type** like numerical, boolean, categorical (e.g. 2=string, 10=null). in this example i will receive all te document where the field item has associated a *string* value
```java
db.inventory.find({item: {$type: 2}})
```

- **$exists** query all document that contain or not a specific field (return even the fields which value is "null"):
```java
db.inventory.find({item: {$exists: true}})

db.inventory.find({item: {$exists: false}})
```


## Aggregation
- **Aggregation** operation *process data records* and *return computed results*
- aggregation operation *group values* from multiple documents and perform some operation to return a *single result*

- there are three ways to perform an aggregation in MongoDB:
  - **the aggregation pipeline**
  - map-reduce function
  - single purpose aggregation methods

### Aggregation Pipeline
- in the *aggregation pipeline*, documents enter a *multi-stage pipeline* that transform documents in **aggregated results**

- **First stage**: we perform a query to filter document (*$match stage*)
- **Second stage**: we group the documents using a field to obtain an aggregate metrics (*$group stage*)

- e.g.
  - The **$match stage** filters the documents by the status field and passes to the next stage those documents that have status equal to "A"
  - The **$group stage** groups the documents by the cust_id field to calculate the sum of the amount for each unique cust_id
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251115153127.png]]

- pipeline stages does not need to produce one output document for every input document (some stage may generate document or filter them)
- pipeline consist of stages, **a stages can appear multiple times** except:
- $out
- $merge
- $geoNear

- **most important stages**:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251115153727.png]]
- **NEVER** use lookup (never do a join operation), also unwind is unadvised, it has an high cost and we don't have any integrity check, so if the original data are updated, the unwind-ed one will not be update and will be inconsistent, so you need to consider how frequently you need to use unwind  
- if you use a lot of time the unwind command, maybe you can find a better data model

### Example
- having a collection `zipcodes` with this documents structure:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251115153857.png]]

- return states with population above 10 million:
``` java
db.zipcodes.aggregate([
{$group: { _id: "$state", totalPop: {$sum: "$pop"}}},
{$match: {totalPop: {$gte: 10000000}}}
])
```
- the *group stage* groups document with the same `state` and calculate the new field `totalPop` equal to the sum of the `pop` field of the aggregated documents. the new document in the pipeline has only 2 fields: `state` (that will also be the id of the document) and `totalPop`
- the *match stage* filter the documents whose `totalPop` value is greater or equal to 10 million



- return average city population by state
``` java
db.zipcodes.aggregate([
{$group: { _id: {state: "$state", city: "$city"}, pop: {$sum: "$pop"}}},
{$group: { _id: "_id.state" avgCityPop: {$avg: "$pop"}}},
])
```
- the *first group stage* groups the documents by the combination of city and state, and calculate the sum of the population for each combination, the result documents has state, city and the population sum
- the *second group stage* group the documents by state and compute the average of city population, the resulting documents have the state field and `avgCityPop` field


- return largest and smallest cities by state
```java
db.zipcodes.aggregate([
{$group:
  { 
    _id: {state: "$state", city: "$city"},
    pop: {$sum: "$pop"}
  }
},
{$sort: {pop: 1}},
{$group:
  {
    _id: "$_id.state",
    biggestCity: {$last: "$_id.city"},
    biggestPop: {$last: "$pop"},
    smallestCity: {$first: "$_id.city"},
    smallestPop: {$first: "$pop"},
  }
}, 
{$project:
  {
  _id: 0.
  state: "$_id",
  biggestCity: {name: "$biggestCity", pop: "$biggestCity"},
  smallestCity: {name: "$smallestCity", pop: "$smallestCity"}
  }
}
])
```
- The *first $group stage* groups the documents by the combination of the city and state, calculates the sum of the pop values for each combination, and outputs a document for each city and state combination (here the id is a document with 2 fields)

- The *$sort stage* orders the documents in the pipeline by the pop field value, from smallest to largest; i.e. by increasing order. This operation does not alter the documents.

- The *second \$group stage* in groups the sorted documents by the `_id.state` field and outputs a document for each state. Using the \$last (\$first) expression, the $group operator creates the `biggestCity` (`smallestCity`) and `biggestPop` (`smallestPop`) fields

- The final *$project stage* renames the `_id field` to state and moves the `biggestCity`, `biggestPop`, `smallestCity`, and `smallestPop` into `biggestCity` and `smallestCity` embedded documents


# 21 Indexes in MongoDB
- **indexes** support the *efficient execution* of read queries in MongoDB
- their main objective is to **speed up read operation**
- without indexes, MongoDB must scan **every document** in a collection to select those that match a query
- but if an *appropriate index exists* for a query, MongoDB can use it to **limit** the number of documents it must inspect

- **indexes** are *special data structure* that store a *small portion* of the collection's data set in a easy way to traverse form
- they store the value of a field or a set of fields **ordered** by the value of the field
- due to the ordering it is possible to perform efficient **equality matches** and **range based** *query* operation

-  MongoDB can return sorted results by using the ordering in the index

- indexes are defined at the **collection level** and can be defined for any field or sub-field of the document

- e.g. of an index where document are sorted by the score field: the indexes are basically a sorted list of pointers to documents, and their sorting depend on the value of one or more fields
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251115162552.png]]

- indexes *speed up* read operation, but they will make **write operation slower** because you will also have to write the index associated to the document

### Default _id Index
- MongoDB creates a **unique index** on the **\_id** field during the creation of a collection
- this ensure that there are not duplicates value in the collection
- it prevents to insert two documents with the same value for the \_id field
- the index on the \_id field cannot be dropped

- a unique indexes ensure to not having duplicates on the field for which the index is defined, this allow to ensure the unicity constraint for a primary key (so the \_id)
- this index is defined by default, and cannot be deleted 
- **IMPORTANT**: it is used to 1 to n relationship, rather than using a foreign key (*the foreign key is a bad solution*). use a list of indexes and not a list of document, because the list of indexes ensure a direct access to the documents because they are pointers

### Creating an Index
- to **create** an index is possible to use the command:
```java
db.collection.creteIndex(keys, options)
```
- **keys** is a document that contains the field and value pairs where:
  - the *field* is the index key
  - the *value* describes the type of index for that field (ascending index has value 1, descending index has value -1)

 - **options**: is an (*optional*) document which contains a set of options that controls the creation of the index

- this method create an index, only if an index with the *same specification* does not already exists
- e.g. create an index for population in ascending order:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251115163400.png]]
 
- for a *single-field index* the *sort order* does not matter
- the method `db.collection.getIndexes()` allow us to see index names (if you do not define it at the creation a name will be automatically given by MongoDB)
- we cannot **rename** an index after once created, but it is possible to drop it and recreate it
- to drop an index it is possible to use the function `db.collection.dropIndex()`, you have to define the name of the index that you want to delete 

### Compound Index
- it is possible to define **indexes on multiple fields** (*compound index*), in this case the *order* of fields has significance (in simple index no)
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251115163643.png]]
- here we will order by alphabetic order the document by the user id, and the document with the same id will be sorted from the highest to the lowest value of score associated to that userid
- it will be an equivalent an indexes with a user id in descending order and score in ascending one


- we can specify a sort query on **all the keys** of the index or on a *subset*
- the sort key must be listed in the **same order** as they appear in the index, e.g. an index key pattern { a: 1, b: 1 } can support a sort on { a: 1, b: 1 } but not on { b: 1, a: 1 }

- for a query to use a compound index for a sort, the specified **sort direction** for all keys, must match the *index key pattern* or match the *inverse of the index key pattern*, e.g. n index key pattern { a: 1, b: -1 } can support a sort on { a: 1, b: -1 } and { a: -1, b: 1 } but not on { a: -1, b: -1 } or {a: 1, b: 1}.

### Indexing Embedded Document
- index can be created on keys in **embedded documents** in the same way that they are created on normal keys using the *dot notation*

- e.g. having the following document structure:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251115170535.png]]
- we can define an index for the *subfield* city as:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251115170555.png]]

- if we use *loc* as the index (so if we use an entire embedded field) you need to **index the entire subdocument**, in a query you will have to specify all the subfields (as the number of the document inside grows it is a really bad idea because it creates too much combinations)
  - valid:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251115170733.png]]

  - not valid: (it is not supported by the index defined on all the fields)
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251115170739.png]]
 
### Indexing Arrays
- we can create an index on a *subfield* of an array, but this create **an index entry for each element of the array**, here we create 2 indexes because we have two dates inside our array in the document:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251115170900.png]]


- so if a post had 20 comments, it would have *20 index* entries just for *one post*
- this make array indexes **more expensive** than a single-value ones, it update every entry of the index for every insert, update or remove

- in this case we create three keys that points to the same document, because we don't have subfields, but just normal value, and we *do not keep information on the position of the value in the array*:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251115171303.png]]

- moreover indexes on array element *do not keep any notion of position*, so we cannot use an index for a query that is looking for a specific array element

- use of array indexes:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251115171418.png]]

### Advanced Indexes
- type of *advanced indexes*:
  - **Geospatial index**: support queries for geospatial coordinate data, can be *2d indexes* or *2dsphere indexes* 
  - **Text index**: support *text search* queries on string content, can include any field whose value is a string or an array of string elements
  - **Hash index**: support *hash based sharding* and indexes the hash of the value of a field. only support *equality* matches, does not support *range-based* queries. it is used to support sharding in your system

- **IMPORTANT**: It is possible to use advanced ai based query

### Types of Indexes
- **Unique indexes**: used to *reject duplicate* values for the indexed field (e.g. if you define a document with an index on city name, then you can insert only one document for each city)
- **Partial indexes**: only index the document in a collection that *satisfy a specific filter expression*, so they index only a subset of document and this use less storage and performance usage for indexes creation
- **Sparse indexes**: it's a property that ensures that the index *only contains entries for documents that have the indexed field*. so it skip the indexing of documents that does not have the indexed field. (MongoDB create the list of document not associated with the index) 
- **TTL indexes**: those are special indexes that MongoDB use to *automatically remove* documents from a collection after a certain amount of time, this is idea for certain types of information like machine generated event data, logs and session information that *need to persist in the db for a limited amount of time*. 


## EVALUATE THE PERFORMANCE OF A QUERY
- considering the following collection:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251115172319.png]]

- to **evaluate the performance of a query** you need to chain  `.explain("executionStats")` with the `find()` method, e.g.
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251115172547.png]]
- the most important thing to check is the number of returned document, the total document examined and the total key examined (related to index defined to fields related to query, here we have zero keys examined because we don't have any index), the execution time depend on the machine and by other running processes, so it is not the most relevant metric

- same evaluation but with the definition of an index with the `quantity` attribute:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251115172639.png]]
- it is much better because we have examined less documents 

- we can use **hint()** to **compare performance** of different *index order*, e.g.
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251115172734.png]]
- the best index depend on the data distribution and the query to perform 

- first index:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251115172838.png]]

- second index:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251115172852.png]]





# 6 MongoDB Java Driver

- the command **MongoClients.create()** allows us to make a connection to a running MongoDB instances
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251116115457.png]]

- You can control the behavior of your *MongoClient* by creating and passing in a *MongoClientSettings* object to the MongoClients.create() method
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251116115623.png]]

- The MongoClient instance represents a **pool of connections to the database**
- we will only need one instance of class MongoClient even with multiple threads

- **IMPORTANT**: Mongoclient is thread-safe. Multiple access to the single instance is *managed by the class itself*
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251116115728.png]]

- Typically, for simple projects, we only create one MongoClient instance for a given MongoDB deployment (e.g. standalone, replica set, or a sharded cluster) and use it across the whole application.

- Call `MongoClient.close()` to clean up resources at the end of the application

### Access a Database
- we can use the method **MongoClient.getDatabase()** to access to a database, you have to give as a parameter the name of the database, if it does not exist it will be created 

### Access a Collection 
- if you have a MongoDatabase instance we can use **getCollection()** to access a collection, takes as a parameter the collection name 

- Drop a collection delete permanently all documents within that collection 

### Document Validation
- document validation consist in check if the documents respect a series of filters, the filters are specified using the **ValidationOptions** class
- all document inserts must match the rules
- the *schema validation level* defines how the rules are applied to existing documents and document update

### Insert Document 
- you can insert a document as a string or using a class instance
- it is possible to iterate through a query result

### Query a collection
- you can query a collection with the `find()` method


### Aggregation Pipeline 
- **Aggregation operations** process data in your MongoDB collections and return *computed results*

- aggregation operation allow to:
  - perform find operation (filter document, filter fields, sort results)
  - rename fields 
  - calculate fields
  - summarize data
  - group values

- it takes as argument a *list of aggregations stages*


### Pipeline - Match
- the **match** operator filter the documents to pass
- the documents that don't respect the match condition are not passed through the next pipeline step

### Pipeline Group
- the **group** operator group document by the value of a field and perform an operation like sum, avg, max, min (is a **group by**)

### Pipeline - project
- the **project** operator filter which *attributes* pass to the next stage (it can also include or compute new fields)

### Pipeline - sort
- the **sort** operator sorts all input documents and returns them to the pipeline in a sorted order (the order can be ascending or descending)

### Pipeline - limit, skip
- the **limit** operator limits the number of documents passed to the next stage. it is useful for search the "top n result"
- the **skip** operator skips over the specified number of documents that pass into the next stage

### Pipeline – unwind
- the **unwind** operator *deconstruct an array field* and create a document for each element of the array

### Create Indexes
- the `createIndex()` method allow to create an **index** on one or more fields
- an *index key specification document* contains the fields to index and the index type for each field
`new Document(<field1>, <type1>).append(<field2>, <type2>) ...`
- for an **ascending** index type specify **+1** for `<type>`, **-1** for an **descending** one

- e.g. create an index on the field city:
```java
collection.createIndex(new Document("city", 1));
```



# MongoDB Clustering
- typical configuration:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20260104113255.png]]

- here the secondary servers check the state of the others:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20260104113330.png]]
and if they do not receive any update they promote one of the secondary:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20260104113402.png]]

- here an example of an **Arbiter**: it does not contain data, it only vote to decide who will be the new primary server
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20260104113427.png]]

### MongoDB Replication
- the more specific write commands will overwrite the less specific ones
- the acknowledge guarantee that the write operation has been successfully completed before return the control 
- you can specify the number of server that have to send the acknowledge if you have more server

### Write concern
- the **write concern** include *tree fields*:
  - **w**: it specify the number of *acknowledgment* that it have to receive from mongod instances with specified tags
  - **j**: if set true the write operation require an acknowledgment that the write operation has been written to the disk journal
  - **wtimeout**: specify a time limit to prevent write operation to block indefinitely the system

- *w* and *j* determine when `mongod` acknowledge write operation, for a standalone machine we can have **6 combination**: 
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251213173548.png]]

- the value specified to w determines the number of replica set members that must acknowledge the write before returning success. 
- for each eligible replica set member, the j option determines whether the member acknowledges writes after applying the write operation in memory or after writing to the on-disk journal

- when the member can acknowledge is defined by j:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251213173909.png]]

- type of concerns:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251213174016.png]]
- the default value is *majority*


### Causal consistency
- if an operation logically depend on a preceding operation, then there is a *causal relationship* between them (e.g. a write operation create a record, and a read operation verify that the record exists)
- with **causal consistency** we execute causal operation in order so to have consistent results

- it make sure that if you have two causally linked operation, then any read operation related to the causally linked operation, will read things in the proper order (so it is impossible to read the result before the consequence, e.g. you can't read a comment to a post that has not been publish yet)
- it does not to read the most recent version of the data (that's strong consistency)

- in causally consistent contest are guarantee only if the read and write operations use the *majority* concern 

- e.g. of a write operation with majority concern:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251213174506.png]]
- when there is a write operation with acknowledgment, first the data are updated in the primary server, after that they are updated to the majority of the secondary servers, the control will be return, and only then the data will be updated in the remaining servers  
- during the operation we are in an inconsistent state in the rest of the secondary servers (for this reason it is call causal consistency)

### Write Concern is organized into hierarchical levels
- write concerns can be organized into **hierarchical level**, it is possible to use different level in different part of the database (*use different concert for different functional requirements*) if you dont specify anything you use the write concern of the server level value, you can specify different write concert for different:
  - operation
  - client
  - DB
  - collection
- **NOTE**: use this different level for different functional requirements in the project
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251213174734.png]]


### Read Preference
- A **read preference** specifies which nodes are used for read operation (e.g. read always from primary, read always from secondary)
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251213174937.png]]
- all read preferences modes except `primary` may return *stale* because secondaries replicate operations from the primary in an asynchronous process
- **ensure that your application can tolerate stale data**

### Read Preference Modes
- There are five read preferences mode:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251213174831.png]]

- it is possible to use some load balancing for redirect read operations to different node 
- do not leave this at the default level, in that case the primary will manage all the read requests, it is better to redirect some of the traffic onto another data, but in this case there is the risk to read stale data so be careful to what read operation you redirect
- you can redirect the read operation to the nearest server (server with the less latency)
- you can also specify to do read request only to secondary nodes, or only to specific secondary nodes

- all secondary nodes could return stale data, read preference doesn't affect the visibility of data (if you read stale data or not), that depends on write preferences
- you can specify a preference on which server you wanna read, with also flexible preferences 

- We can use the **tags** configured into our *replicas* to state preferences on secondary replicas (cannot specify a tag preference on a primary)





# 4 Redis
### What is Redis?
- **REDIS**: REmote DIctionaty Server

- Redis it's a *data structure server*
- Redis is an **in-memory (in RAM) database used as a cache** in front of another "real" database to help improve application performance
- it leverages the speed of the main memory and alleviates load off the central application database

- it is good for data that *changes infrequently* and is requested often, and for data that is less mission-critical and if frequently evolving
- it can read and write very fast
- it is basically a python dictionary in RAM used as a cache to support other database 


- example of use of redis as a cache used to support a main database, the application can be faster because the access to the database is less frequent  
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251026171853.png]]
- for some cases Redis offers enough guarantees to be used as a primary database



- Redis is an **in-memory data structure store** used as a database
- It can be used also as a **cache**, *message broker* and **streaming engine** (it also offer a method to publish and read messages between services)
- Redis provides different data structures such as strings, lists, etc.
- It offers *atomic operations* like incrementing the value in a hash, pushing an element to a list, etc.
- Periodically data persistence feature (dumping the dataset to disk), this feature can be disabled, so it has a personalize persistence

- Redis also includes: Transactions, Pub/Sub, *keys with limited time-to-live*, replication, scaling and many other features
- **key with limited time to live**: key that are removed from memory after a certain period of type (to not full the RAM)


### Installing Redis
 - it is officially supported on windows right now, but can be used by WSL (Windows Subsystem for Linux)
 - by default allows connection from 127.0.0.1 
 

### Redis Keys
- keys are **unique** in redis
- keys are used to *locate a specific value*
- keys are *binary safe* (you can use a string or the content of a JPEG file)
- empty string is also a valid key

- **Use a namespace to identify your applications keys** (sometimes the same redis *instances* can be used by different application)
- it can be used to link logically a set of related keys

- if the name of the key is significant they can be used in a research
- long keys are not a good idea

- **Key must be readable**, e.g. a key used to store the quantity of follower of a user:
  ![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251026173611.png]]

- **Dots and Dashes are often used for multi-word fields**:  ![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251026173714.png]]

- the maximum allowed key size is *512 MB* (try to not reach this value)

- **Try to stick with a schema, a good rule for define a keys is**:
   `EntityName:EntityID:EntityAttribute`
- e.g. `User:001:name`


- you can exploit a prefix in the key for implement a **version number**
- the key name have to describe what the key is and not how is gonna be used

### Redis datatypes
- Redis support different *datatypes*
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251026173916.png]]


### Redis commands
- To define a new key-value pair:
	**SET \<key> \<value>**
	SET hello:key "hello world"

- To retrieve the value from a key:
	**GET \<key>**
	GET hello:key

 - To define the expiration on a key:
	**EXPIRE \<key> \<seconds> NX**
	or
	**SET \<key> \<value> EX \<seconds>**
	EXPIRE hello:key 10
	SET hello:key EX 10

- To see the time to live of a key:
	**TTL \<key>**
	TTL hello:key

- To delete a key:
	**DEL \<key>**
	DELETE hello:key 

- To persist a key (set an infinite time to live to a key):
	**PERSIST <key\>**
	PERSIST hello:key

- There are also *atomic operations* to avoid conflicts
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251026173941.png]]

- Scenario: there is a counter with the value 10 and two client want to increase this value at the same time
- Problem: both client could read the value 10 at the same time and set the value to 11 when the expected value should be 12
- Solution: to make use of atomic operations line INCR, INCRBY, DECR, DECRBY...



### Pipelining
- **Pipelining**: It is a technique for improving performance, multiple commands are sent at once without waiting for the response to each of them
- can allow to execute fast a large number of action in sequence ![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251026174337.png]]
- it gives to the server a batch of instruction, the server will execute the operation in order and the order of results it's also guarantee 
- it can decrease the RTT by a lot (RTT: Time of a packet to travel from a client to a server and back from the server to a client to carry the response)


### Transactions
- **Transactions**: execute a group of commands in a single step
- all the commands defined in a transaction are serialized and executed sequentially

- command: **MULTI, EXEC, DISCARD, WATCH**
- *MULTI* start the transaction, then you write all the comment, and *EXEC* triggers the execution of *all* commands in the transaction

```
MULTI
INCR counter
LPUSH log "increment"
EXEC
```


- Redis does not support **rollbacks**, you can only *DISCARD* previous sent command (so DISCARD abort a enqueued command, but cannot stop an executed command)
- a rollback revert the database to a consistent state 

- you have the guarantee that commands in a transaction will be atomic and executed in order

-  Keys involved in a transaction may be modified by other transaction, you can use *WATCH* to monitor the state of these keys, and in some case abort the modification of them
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251026175408.png]]
- Client 2, queue a set of commands and execute them first.
- After client 2 commands execution, client 1 executes their commands.
- Since my-key was modified first by client 2, client 1 transaction is aborted.
 
- when you create a transaction the commands are not executed, they are *enqueued*


### Jedis: Java client for Redis
 - **Jedis**: it's a Java library for connecting java to redis



### When to use Redis?
- a lot of companies like git-hub, twitter and stack overflow use redis 

- Redis can be **used when**:
  - an application has to deal with **volatile data** (e.g. shopping cart)
  - data is always queried, but **hardly ever modified** (e.g. list of countries)
  - you have to **access data by using only an identifier and you want to reduce response time** (e.g. access to product details)
  - when you need to access to something really quick and flexibility 

# 5 Redis Part 2
- Objective of this Class:
   - To learn what the key eviction policies are and how they work.
   - To learn how the persistence works.
   - To learn how to activate the High Availability (HA) - Replication feature.
   - To learn how Horizontal Scaling works and how to configure it.
   - To review Keyspace notifications.
   - To learn other features of Redis: Publisher/Subscriber scheme.
   - Use cases scenarios.

### Eviction (sfratto)
- an **Eviction policy** (*max-memory-policy*) is activated when the max memory limit (*maxmemory*) is reached, maxmemory it is equal to all the RAM free space if it not set 
- It is a policy activated when the memory of Redis is full

- There are a lot of different policies:
  - **noeviction**: *new values aren't saved* when memory limit is reached, when you use replication this applies to the primary db (so they are saved in secondary one???) (*it is the default approach*)
  - **allkeys-LRU**: keeps in memory only the most recently used keys, remove from memory the Least *Recently* Used (LRU)
  - **allkeys-LFU**: keeps in memory the most frequently used keys, remove the Least *Frequently* Used (LFU)
  - **volatile-LRU**: remove the least recently used keys with the *expire* field set to true
  - **volatile-LFU**: remove the least frequently used keys with the *expire* field set to true
  - **allkeys-RANDOM**: randomly removes keys 
  - **volatile-RANDOM**: randomly removes keys with the *expire* field set to true
  - **volatile-TTL**: removes keys with expire field set to true and the shortest remaining Time-To-Live (TTL) value

### Persistence
- **Persistence**: persistence refers to writing data to durable storage like SSD or HD, Redis offers a lot of option to do so: 
  - **RDB** (*Redis Database*): perform point-in-time *snapshots* of your dataset at specific intervals of time or number of write operation (if the system crash between two snapshot you loose data saved during that time)
  - **Append Only File** (*AOF*): every write operation is written into a log file (need a lot of computation to reconstruct all the db just with this)
  - **No persistence**: it does not write anything persistently, the database exist only when the server is running
  - **RDB+AOF**: use the AOF to reconstruct the original dataset (*best solution*)

- use the partition mechanism consume a lot of resources that so are not available for the db

### High Availability (HA) - Replication
- in a **replica database** when the primary server goes down, the replica takes over
- Redis uses by default **asynchronous replication**, put it is possible to perform synchronous replication of certain data, the number of replica needed depends on the system

- the operation is concluded and only after it return the result to the user it is propagated to replicas
- replication can also be used for **scalability**, because we can organize a load-balancing for *read-operations* (but not for write operations)
- what is the minimum number of replica do i need to have to ensure **high availability**? the most important factor is *how sensitive the data is*, it is important or not if i loose my data?

### Clustered Database (Scaling): Key Distribution Model
- With redis you can have sharding (horizontal scaling)
- **SHARDING IS DIFFERENT FROM REPLICATION**, THEY ARE USED FOR DIFFERENT REQUIREMENTS
- Keys are distributed across *cluster nodes*
- To determine in which node a key is stored, it is used an HASH SLOT
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251109163852.png]]
- there are **16384 hash slots** in redis cluster, each node of the cluster has assigned a range of them

- example with 3 nodes:
   - Node A contains hash slots from 0 to 5500.
   - Node B contains hash slots from 5501 to 11000.
   - Node C contains hash slots from 11001 to 16383.

### HA Clustered Database
- The Redis client/connector computes the HASH SLOT for a key to determine a Master node to work with.
- Clustered environment with replicas:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251109164010.png]]

### Keyspace notifications
- Redis offers **monitoring changes on keys and values in real time**
- Clients must *subscribe to Pub/Sub channels to receives these events*

- Two types of events: *Key-space* and *Key-event*:
  - **Key-space Events**: triggered when a specific operation is *performed on a particular key* (e.g., setting or deleting a key). Keyspace events are prefixed with the `__keyspace@<db>__: pattern`, followed by the key name. (db is the number of database, from 0 to 15)
  - **Key-event Events**: triggered when an operation is performed on any key and are focused on *the type of action itself* (e.g., "SET", "DEL", "EXPIRE"). Keyevent events are prefixed with `__keyevent@<db>__`: followed by the event name

- First, let's enable notifications in Redis to capture the events we are interested in. You can configure this in the Redis configuration or via the command line. Here, we'll enable notifications for all key events, expirations, and evictions:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251109172331.png]]
- **E**: Eviction events
- **x**: Expiration events
- **g**: Generic commands (such as DEL)
- **K**: String commands (such as SET)


### Publisher – Subscriber
- Redis implements the **Publish/Subscribe messaging paradigm** by offering the *SUBSCRIBE*, *UNSUBSCRIBE* and *PUBLISH* commands

- A client must perform the *SUBSCRIBE* operation to specific channel(s)
- A *publication* on a channel will be notified to all the subscripted clients
- To stop receiving notifications, the *UNSUBSCRIBE* command need to be executed


### Use case scenario: Web Server Session Externalization
- typical use case of redis where there are multiple client, multiple server, and you need to handle data on user session, redis centralize user data of all the users from all the servers, this allow good load balance and centralize and simplify the logic to handle the session of each user
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251109171731.png]]


# Neo4J
- **Neo4J** is very used in ML and DL application
- It is a **native graph DB**, it is used for kg augmentation and model training, it can exploit data not only on nodes, but also on relationships
- **native**: each node have information on the directed connected nodes, it does not use an *index* for create relationship

- its major strength is that the **connections are stored in each nodes**, this allow to *avoid join operation* 
- in constant time you can obtain all the nodes connected to a specific node by following the pointers associated to the node

### Neo4J Main Concepts
- A Neo4J graph is composed by:
  - **Nodes** (can have different type): describes the entity of the domain
  - **Labels**: one nodes have associated zero or more label to define the *kind of nodes*
  - **Relationships** (can have different type): connect node in a directed way (source -> target), always have a *direction*, and ONE *type*
  - **Properties**: key-value pairs that describe nodes and relationships 
  - **Indexes**: allow to order nodes to perform faster read operations
  - **Constraints**



### Neo4J Node
- a **Node** stores data similarly to a row in a relational db or document in a document db, they are *schema-free*, have some associated properties (they can have different properties because the graph is schema free). they can be labeled, indexed, and connected with other nodes through relationships
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251203141638.png]]

### Neo4J Labels
- **Labels** are used to group nodes into sets, nodes with the same labels belongs to the *same set*
- a node can have zero to many label and the label associated with a nodes can be added and removed *dynamically* 
- they can be used to represent temporary states (because they can be added dynamically, e.g. a temporary banned user)
- conventionally the label are written in *CamelCase*
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251203141747.png]]

### Neo4J Relationship
- A **Relation** connects two nodes
- Relationship organize nodes into structures, allowing a graph to resemble a list, a tree, a map or a compound entity

- a relationship must have **exactly one relationship type**, expressed in UPPER CASE
- it can also have associated property
- can be added and removed dynamically
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251203142429.png]]
- the *shape* of a portion of a graph is important, because query can search for patterns (e.g. search for a node of only type A connected exacted with two nodes of type B)
- you can have redundant relationship if it make sense, but not all the cases 
- a node can also have a relationship to itself 



### Neo4J Property
- **Property** are name-value pairs that are used to *add quality to nodes and relationship*
- main property types:
  - number: an abstract type which has the subtypes Integer and Float
  - string
  - boolean
  - Point: a spatial type
  - the temporal types Date, Time, LocalTime, DataTime, LocalDateTime, and Duration

- it is possible to have array of property attached to an element
- the more property you attach, the *heavier* the node will be

### Neo4J Traversal and Path
- **Traversing a graph**: visiting nodes by following relationships according to some rules
- the traversal result could be turned into a **path**
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251203142743.png]]
- traversing the graph to find a specific nodes, is a very heavy operation, it is the operation with the largest cost


### Neo4J indexes 
- **Indexes** can help to speed up the query, they allow to **find the starting point of a graph traversal** (that is the most difficult part, the others are more optimized)

- an index can be:
  - **single property**: the index refers to a single property for a given label, it can *match ranges*
  - **multiple properties**: the index refers to multiple properties for a given label, it can *match only by equality*


### Neo4J Constraints
- **Constraints** are used to make sure that the data adheres to the rules of the domain
- they can be assigned dynamically 

- they can be used to:
  - Enforce *uniqueness* (e.g. each person node is unique)
  - Enforce *existence* of a property in a node (e.g. each person node must have a defined name)

### Neo4J Naming Conventions
- Naming conventions:
  - *label* are expressed in **CamelCase**
  - *relationships* are in **CAPS LOCK**
  - *properties* are expressed in **lowerCamelCase**


### Neo4J SuperNode
- **SuperNode**: a node with a huge number of relationships (e.g. a celebrity in a social network graph)
- they are problematic because they slow down the graph traversal when all relationships are traversed




# 9 Cypher

- Neo4J is an environment with a lot of tools, a lot are used for data science and ML, we will use Cypher, Drivers API connector, and Visualized
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251210215817.png]]


- Relationships in Relational DBMS requires *foreign key* and sometimes a *lookup table*, traversing a foreign key requires an *index lookup*
- the purpose of graphs is to do **rapid traversal**


### Pointers in IFA
- **IFA** uses pointers to the target address
- pointers allow to don't use indexes or lookup table and reduce the duplication of foreign key 
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251210220231.png]]


### What is Cypher?
- **Cypher** is a *declarative* query language
- it focus on **what** retrive, not on how
- its main keywords are MATCH, WHERE, CREATE
- and is **heavily based on patterns**, and it is designed to recognize various versions of these patterns in data
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251210220442.png]]


- Example of a node connection:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251210220508.png]]
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251210220554.png]]

- example of a graph:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251210220619.png]]



### Creating a Node

- example of node creation:
``` Cypher
CREATE (ee:Person { name: "Emil", from: "Sweden", age: 29 })
```
- `ee` is the name of the **variable**
- `Person` is the label **associated**
- `name, from, age` are the **attributes**

- `CREATE` is the command to create the node
- `()` indicates the node
- `{}` indicates the attributes

![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251210221121.png]]

### Retrieving a Node
- example of node retrieval:
``` Cypher
MATCH (ee:Person) WHERE ee.name = "Emil" RETURN ee;
```
- return the node of label Person with the value name equal to Emil
- `MATCH` specify the pattern of nodes and relationships 
- `(ee:Person)` means: a *single node* pattern with *label 'Person'* which will assign matches to the variable `ee`
- `WHERE` filter the results
- `RETURN` is used to specify what we want to obtain, in this case the variable with the node


### Creating a graph
- **CREATE** clauses can create many nodes and relationships at once. Combining MATCH and CREATE allows to attach a new sub-graph to existing nodes of the current graph

- Example of graph creation
``` Cypher
MATCH (ee:Person) WHERE ee.name = "Emil"
CREATE (js:Person { name: "Johan", from: "Sweden", learn: "surfing" }),
(ir:Person {name: "Ian", from: "England", title: "author" }),
(rvb:Person {name: "Rik", from: "Belgium", pet: "Orval" }),
(ally:Person {name: "Allison", from: "California", hobby: "surfing" }),
(ee)-[:KNOWS {since: 2001}]->(js),(ee)-[:KNOWS {rating: 5}]->(ir),
(js)-[:KNOWS]->(ir),(js)-[:KNOWS]->(rvb),
(ir)-[:KNOWS]->(js),(ir)-[:KNOWS]->(ally),
(rvb)-[:KNOWS]->(ally)
```
- we are attaching new nodes with CREATE to an existing part of the graph find thanks to a MATCH operation 
- we save nodes in variables to connect them in a easier way

- if we don't use **MATCH** we can also create a graph from scratch without attaching it to existing nodes:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251210221649.png]]
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251210221705.png]]


### Adding a node and a relationship
- add a new node to a graph:
``` Cypher
CREATE (pp:Person { name: "Pietro", from: "Italy", learn: "neo4j" })
```

- we can add relationship to existing nodes:
``` Cypher
MATCH (ee:Person) WHERE ee.name = "Emil"
MATCH (pp:Person) WHERE pp.name = "Pietro"
CREATE (pp)-[:KNOWS {since: 2019}]->(ee)
```

### Adding a node if not present
- in is possible to use **MERGE** to introduce information without introducing duplicates
- another way to avoid duplicates is to use a constraint of uniqueness 

- add a node to the graph (but is is added only if it does not exists):
``` Cypher
MERGE (pp:Person { name: "Pietro", from: "Italy"})
```

- here we add a node to the graph and set a property if it not exists:
``` Cypher
MERGE (keanu:Person { name: 'Keanu Reeves’ })
ON CREATE SET keanu.created = timestamp()
```

- set the property of found nodes:
``` Cypher
MERGE (pp:Person)
ON MATCH SET pp.found = TRUE
```

### Pattern Matching
- example of pattern matching: "find all the friends of Johan" (return all the node where Johan is connected with a KNOWS relationship)
``` Cypher
MATCH (ee:Person)-[:KNOWS]-(friends)
WHERE ee.name = "Johan" RETURN friends
```


- One thing that makes graph unique is its focus on relationships: just as you can filter queries based on node labels or properties, you can also filter results based on relationships or patterns
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251210223428.png]]


### Recommending
- pattern matching can be used to make recommendations
- e.g. recommend a new friends that surf:
``` Cypher
MATCH (js:Person)-[:KNOWS]-()-[:KNOWS]-(surfer)
WHERE js.name = "Johan" AND surfer.hobby = "surfing"
RETURN DISTINCT surfer
```
- `()` empty parenthesis to ignore these nodes
- `DISTINCT` because more than one path will match the pattern
- `surfer` will contain Allison, a friend of a friend who surfs
- friends is the **variable** in this case


### Patterns Variables
- you can assign pattern to *variables* to reduce repetition, this variable for example contains two nodes and their relationship for every found path
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251210223709.png]]



### Updating data with Cypher 

- with the keyword `SET` it is possible to **update properties**
``` Cypher
MATCH (n:Person)
SET n.worksIn = "Google"
RETURN n
```

- the setting may depend on the result of a filtering
``` Cypher
MATCH (n :Person { name: 'Emil' })
SET (
	CASE
	WHEN n.from = 'Sweden’
	THEN n END ).worksIn = 'Malmo'
RETURN n.name, n.worksIn
```




### Setting Properties on Relationships
- set or modify the value of property on relationship:
``` Cypher
MATCH p=()-[r:KNOWS]->() SET r.since="2019" RETURN p
```

### Setting Labels to Nodes
- how to add a Label to a specific node:
``` Cypher
MATCH (ee:Person) WHERE ee.name = "Ian" SET ee:Young
RETURN labels(ee);
```

### Removing a property
- To **remove a property** you just need to set the property value to **NULL**
``` Cypher
MATCH (n:Person)
SET n.worksIn = NULL
RETURN n.name, n.worksIn
```

- one alternative is the command `REMOVE`
``` Cypher
MATCH (n:Person)
REMOVE n.worksIn
```

### Delete Operations
- To delete a relationship of a node :
``` Cypher
MATCH (n:Person { name: 'Ian' })-[r:KNOWS]->
(c :Person { name: 'Allison' })
DELETE r
```
(you are exploiting the fact that the relationship is being assigned to the variable **r**)


- To delete all relationships of a node :
``` Cypher
MATCH (n { name: 'Ian'})-[r:KNOWS]-() DELETE r
```

- To delete a node:
``` Cypher
MATCH (n { name: 'Ian'}) DELETE n
```

- To delete all nodes and relationships:
``` Cypher
MATCH (n) DETACH DELETE n
```
### Neo4j Browser User Interface
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251210222331.png]]




# 10 Neo4J Driver
- Neo4J provides **Drivers** for a lot of programming languages

- The *Driver API* is **topological agnostic**, so the underlying database topology, single instance, Causal Cluster, ecc..., can be altered without requiring an alteration of the code
- So you can use the same interrogation for different organization of the data
- Usually the only thing that changes when we change the topology is the **Connection URI**
- the official driver does not support HTTP communications (but community drivers do)

### The Driver Object
- A Neo4J client application require a **driver instance** in order to provide access to the database
- the driver should be *available to all parts that interact to Neo4J*
- the driver can be considered **thread-safe** (it can be used by multiple thread without causing any race condition)

### Construct a Driver Instance
- to construct a driver instance a **connection URI** and **authentication information** must be supplied
- It is also possible to specify additional details, and all details are **immutable** during the *driver lifetime*
- if you need multiple configuration, you need to create more driver

- for a single server it is possible to create a direct driver with **bolt URI**
- for a cluster you need to use **neo4j URI**

### Connection URI 
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251203144819.png]]
- **Load balancing policies**: a *policy* parameter can be included in the query string of a **neo4j://** URI, to customize how to distribute the request among the cluster's servers
- to *use the load balancing policies* you need a **cluster** and to activate some **server policies**

- in a clustered environment the URI address will be resolved to one or more of the core members, for standalone installation it will simply point to that server address
- the *policy* parameter allows for customization of the routing table 


### Authentication
- Authentication are provided as an **auth token** which contains the username and password to access the database
- Neo4J supports multiple authentication standard, it use *basic authentication* by default
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251203145430.png]]

### Driver Config
- **ConnectionAcquisitionTimeout**: is the maximum of time a session will wait when requesting a connection from the connection pool, if the maximum of connection has been reached and are all busy we will wait this time for a connection to be made 
- it has to be higher than **ConnectionTimeout**
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251203150005.png]]
- there is also the parameter **max connection pool size**
### Connection Pools 
- the driver maintains a **pool of connections**
- the pooled connections are reused by *sessions* and *transactions* to avoid the overhead added by establishing new connections for every query
- the connection pool always starts up empty, new connection are created by sessions and transactions 
- when a session or a transaction has finished its execution, the connection will be *returned* to the pool to be reused
- Application users **can tune connection pool settings** to configure the driver for different use cases based on client performance requirements and database resource consumption limits. 
- you can also configure the `connection timeout` and the `max retry time`


### Logging
- **logging**: used to debug and know connection time and number of connection 

- **Do not hardcode or concatenate parameters directly into queries**, always use *placeholders* and specify the Cypher parameters as shown in the previous examples. This is for:
  - *Performance benefits*: you can caches a queries with an unchanged structure (even with different parameter?)
  - *Security reasons*: you can protect yourself from **Cypher injection**
- do data sanitizing of the database (check if a username of string contain a command)


### Protecting against Cypher Injection using Parameters
- It is possible to *Prevent Cypher injection* by **using parameter**

- Injected name:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251210213224.png]]

- normal query:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251210213218.png]]

- injection result (cancel all the students nodes):
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251210213301.png]]

- query with parameter:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251210213323.png]]

- parametrized resulting query:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251210213403.png]]


### Query configuration
- You can supply further configuration parameters to alter the default behavior of` .executableQuery()`. You do so through the method `.withConfig()`, which takes a **QueryConfig** object.

- it is recommended to *always specify the database explicitly* with the method `.withDatabase(“<dbName>”)`, even on single-database instances, because it allows the driver to work more efficiently, as it saves a network round-trip to the server to resolve the home database
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251210213630.png]]


### Run queries as a different user
- you can run a query with different users with different authorization using the method `.withAuthToken()`, switching a user at the query level is cheaper than *creating a new driver*
- the query is run within the security context of a given user
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251210214211.png]]
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251210214232.png]]



### Run your own transactions
- when you query the database with the function `executablequery()` the driver automatically *creates a transaction*
- you can include multiple Cypher statements in a single query
- for more advanced use-cases, the driver provides functions to take full control over the transaction lifecycle, these are called **managed transactions**, and you can think of them as a way of unwrapping the flow of `executableQuery()` and being able to specify its desired behavior in more places

### Create a session
- to run a transaction you first need to **create a session**, session are a *query channel* between the driver and the server, and ensure *casual consistency*
- you can create a session with the `Driver.session()` function

### Sessions
- a **Session** is a *container* for a sequence of transaction
- session borrow connections from a pool as required and so should be considered *lightweight* and *disposable* 
- sessions are scoped within a context block
- This ensures that they are properly closed and that any underlying connections are released and not leaked.
- session consume resources only during the execution of a transaction 


### Run a managed transaction
- a transaction can contains multiple queries
- since Neo4J is *ACID compliant* (so all the operation of update in the graph are managed as transition that respect the 4 ACID properties, in this way it guarantee correctness and reliability), queries within a transaction will be executed as a whole or not at all
- you can use a transaction to group related queries, e.g. queries which work together to achieve a single logical database operation

### Process query results
- The output of a query done by the driver is a **Result object**, which contains the Cypher result in a rich data structure that requires some parsing on the client side
  - the result records are not immediately and entirely fetched and returned by the server
  - **the result acts as a cursor**, so you cannot retrieve a previous record from the stream unless you saved it in an auxiliary data structure
- The easiest way of processing a result is by calling `.list()` on it, which yields a list of Record objects


