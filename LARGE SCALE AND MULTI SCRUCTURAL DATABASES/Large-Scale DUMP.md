# 0 Introduction 
- Java is **platform independent**: the same program can run on any correctly implemented Java system
-  Java is **object-oriented**:
  - Structured in terms of classes, which group data with operations on that data
  - Can construct new classes by extending existing ones

 - Java designed as
   - A *core language* (a full complete language) 
   - A *rich collection of commonly available packages*

- Java can be embedded in Web pages

- **Structure**:
	- you should have only one main classes
	- file name should be the same of the class defined in it 

##### Processing and execution
- we begin with **Java source code** in text files (with *.java* extension)
- a **Java source code compiler** (*Javac*) produces Java *byte code*, and give one output file for each class with extension *.class*
- a **Java virtual machine** loads and executes class files (it can compile them internally)


# 1 JDBC and Maven
- Let suppose that we need to access and manipulate data stored in a Database Management System
- we could have some difficulties (*Impedance Mismatch*), depending on:
  - **Different access modes**: SQL is a set-oriented language (that operates on sets of tuples), while applications operate on a single tuple at a time
  - **Different type of data**: each programming language define its own types of data, which may differ from those of the SQL (and DBMS), e.g. Java have only one type to represent string while SQL have many of it

- **Object-Relational Impedance Mismatch**: problem occurred when mapping concept of the DB within object-oriented languages, they are mainly given by *difference between your code object and database object*
- for each databases you need to properly manage the interaction with the DBMS and map the connection between object in database and object in the code

- **Connectors**: an additional layer of sw which help developer to handle the interaction between DBMS and any language
- initially they had low portability (because DBMS wanted to use their DMBS), but with the introduction of ODBC this has changed

- **JDBC** (*Java DataBase Connectivity*): connectors for java, it provides a standard way to handle interaction between Java and a DBMS
- it is basically an api in java that enable java application to interact with database

![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251019161913.png]]
- **driver manager**: contain the entry-point to work with a relational database


### Basic Workflow of JDBC
1. Load the **JDBC Driver**
2. Establish a *Connection*: Create a connection to the database using **DriverManager**
3. *Create a Statement*: After establishing the connection, you can create a **Statement** or **PreparedStatement** to execute queries
4. Execute *SQL Queries*: Queries are executed using the **executeQuery** or **executeUpdate** methods
5. *Process Results*: The **ResultSet object** contains the results of the query, and you can iterate through it to retrieve data
6. *Close the Connection*: It’s important to close the Connection, Statement, and ResultSet to free up database resources

- **prepared statements** are safer than **performing queries**, less prone to *SQL injection*
- the execute method return a true if the command is a select, false otherwise

### JDBC Driver Manager
- The class **DriverManager** manages the JDBC drivers and *creates connections to the DBMS*
- a **connection string** is required to obtain a connection, it is expressed in form of **URN** (*Uniform Resource Name*), the string is specific for the DBMS and specify:
  - the type of driver 
  - the type of DBMS
  - the host of the DBMS
  - access credentials
  - the database to which you can connect
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251019162549.png]]
- at the end of all operation we need to close the connection


### Performing Queries
- To *perform queries* we use the object **createStatement**, the **ResultSet** object allows to *iterate on each tuple* of the table returned by the query
- we use specific methods to obtain values from individual columns
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251019162635.png]]
- at the end we need to close the ResultSet and the createStatement object

### Prepared Statements
- with the interface **java.sql.Statement** the SQL statement is compiled at the execution time
- Using prepared statements allows us to pre-fill a statement and improves performance when the same query is executed multiple times, even with different parameters.

- parameter are indicated by *question marks* "**?**" 
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251019163050.png]]

### When use Statement or PreparedStatement

- Use **Statement** when:
  - you are executing *simple, static SQL queries* without parameters
  - the query is executed once and doesn't need to be reused 
  - performance and security are not major concerns


- Use **PreparedStatement** when:
  - you are executing **parameterized queries**, especially when the input comes from user data
  - you need to execute the same query *multiple times* with different parameters
  - you want to *prevent SQL injection*
  - you want to improve performance of frequently executed queries
  - you are handling *large object* (e.g. BLOBs or CLOBs) or doing batch processing


### Updating Tables
- INSERT, UPDATE and DELETE statements do not return a ResultSet object.
- The **executeUpdate()** method executes the statement and returns the *number of rows* actually inserted/modified/deleted
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251019163546.png]]

# 1.2 Maven
- **Apache Maven** is a *software project manager* and comprehension tool 
- Maven can manage a project's **build**, **reporting** and **documentation** form a *central piece of information*. we will use it to **manage dependencies**

- **POM file**: is an XML file that contains information about the project and configuration details used by Maven to build the project
- we can set our *dependencies* in the field **dependencies list**
- **groupId** uniquely identifies a project across all projects
- **artifactId** is the name of the jar without version
- by default, Maven will download dependencies from the central repository
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251019164034.png|300]]

- we would like to interact with a MySQL database so it is required to add the **MySQL JDBC Driver**
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251019164206.png|400]]

- Program example:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251019164237.png]]



# 3 Restful API
## Java Spring Boot
- NOTE: using spring boot in the project is not mandatory
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251019180547.png|300]]
- **Java Spring Boot** is a framework that simplifies the development of Java-based RESTful web service
- is a *convention-over-configuration framework*, so it reduces the need for boilerplate code and configuration, allowing developers to focus more on writing business logic
- with spring boot you can set up and run an application with minimal configuration and setup
- it provides built-in support for HTTP methods, auto-configuration and embedded servers like *Tomcat*

- It is used for building RESTful Web Services, it allows to build REST APIs quickly and provides everything you need, from managing requests, routing them, to managing responses

- Spring Boot is popular for *microservice architecture*
- **Microservices**: each service is designed as an independent loosely-coupled component



### Spring Boot Project Structure
- When you create a *Spring Boot project*, you typically follow a **standard project structure** that helps *organize your code in a clean and modular way*:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251019181256.png|300]]
- **NOTE: use this structure for the project**

### Purpose of Each Package in Spring Boot Project
- **Controller**: Maps API requests to handler methods
- **Model**: Entity classes that map to database tables
- **Service**: Contains business logic
- **Repository**: Interfaces for CRUD operations via Spring Data JPA, provides data access logic. it is used to offer functionality to the user
- **Config**: Configuration classes for the project
- **Resources**: External configurations (e.g., application.properties)

## File of the project 
### Spring Boot Application Main Class
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251019181430.png]]
- this folder contains all the Java source code for your Spring Boot application
- All the components such as controllers, services, repositories, and configurations go here
- It follow a hierarchical structure with packages to organize different layer of the application



![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251019181558.png]]
- This is the main class of your Spring Boot application, annotated with **@SpringBootApplication.** It acts as the *entry point of the application* and contains the main() method that bootstraps the Spring Boot application

- Main Boot class example: 
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251019181636.png]]


### Spring Boot Project Structure: controller
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251019181732.png]]
- **Controller** is a package that contains the *REST controllers* that handle incoming HTTP requests to the exposed end-point and return responses
- It's where you define the logic of REST request handlers, using the main annotations in Spring Boot

- **@RestController**: indicates that the class will handle REST requests and return data as JSON or XML object as response

- **@GetMapping**, **@PostMapping**, **@RequestMapping**, **@DeleteMapping**: Map HTTP methods to Java methods (map java method to rest request)

- **@RequestBody** and **@ResponseBody**: Handle JSON data in the request body and response body (specify the structure and the format of the JSON data used)

- **@PathVariable** and **@RequestParam**: Capture path variables and query parameters from the URL (used to manage parameters in requests)

- controller class example:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251019182038.png]]

##### Example Spring Boot GET Method
- example of get method, which is returning all existing events, the handler is simply calling get all event in the event service
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251019182101.png]]


##### Example Spring Boot POST Method
- same thing, but for post 
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251019182111.png]]


##### Example Spring Boot PUT Method
- example of event update 
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251019182124.png]]

##### Example Spring Boot DELETE Method
- an example of deletion of an event
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251019182136.png]]


### Spring Boot Project Structure: model
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251019182150.png]]
- **Model** is a package that holds the *domains models* or *entity classes* representing the business object in your application, if you are using a database, this is where you define JPA entities
- holds the implementation of entity in the data model 

- Example of model: we are implementing the event class using JPA
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251019182314.png|400]]

### Spring Boot Project Structure: repository
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251019182334.png]]
- **Repository** is a package where the *repository interfaces* live. These interfaces are typically based on Spring Data JPA and provide data access logic (e.g. CRUD like operation in database)
- provide standard interface where you can attach multiple implementation 

### Spring Boot Project Structure: service
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251019182459.png]]
- **Service** is a package that contains the business logic and is often used to *mediate between the controllers and repositories*. Services usually contain the main logic for handling data processing and are annotated with *@Service*

- Service example:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251019182614.png|500]]

### Spring Boot Project Structure: config
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251019182704.png]]
- **Config** is the package where you put configuration classes
- configuration classes could be related to security, custom beans or Swagger configuration
- you need to use *@Configuration* annotations in these classes

- The config packages is primarily used to centralize and organize all the configuration classes of the application
- it helps *separate the configuration logic* (which handles the application's specific settings and behavior) *from the business logic of the application itself*

- It can be used for example to implement an authentication mechanism


# Recap Software Engineer 
- Step when developing an app:
  - **Requirement elicitation** from customer (e.g. obtain the requirement from the customer, usually by an interview)
  - **Requirement definition** (both functional and non functional)
  - **Use Case definition** with UML diagrams or *Mockup*
  - Identification of the main data structures (including the main process) and the relationship between them (**Analysis Workflow / Data Modelling**)
  - Refine of the previous point (**Project Workflow / DB design**)
  - **Implementation** and **test**
  - **Deploy**

- Agile Approach: is a loop on 6 step
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250930114553.png|300]]


##### Role of the Architect / Engineer
- The **Architect** should identify the *most suitable*:
  1) software and hardware architecture
  2) programming languages and environments 
  3) DBMS

- Every choices must be driven by:
  - requirement
  - common sense
  - experience

##### Functional Requirements
- **Functional Requirements** describe *the main functionalities* of the application
- they depends on the software type, expected users and the type of system where the software is used
- they usually are *high level statements* of what the system should do, and can define *if/then behaviors*, e.g. **Use cases** and **Mockups**
- They usually refer to an actor

- Functional requirements can include: 
  - input and output of the system (what the system accepts and produces)
  - interaction with users or other systems
  - business rules (e.g. if a stock reach a level below 10 then send an alert)

###### Example of functional requirements
- The system must send a confirmation email whenever an order is placed
- The system must allow blog visitors to sign up for the newsletter by leaving their email
- The system must allow users to verify their accounts using their phone number



##### Non-functional requirements
- **Non functional requirements** define **quality attributes and constraints** of the system, e.g.
  - performance (constraint on response time and throughput)
  - scalability (how the system handle a growing load)
  - reliability (fault tolerance and recovery)
  - usability (how easy to use and accessible have to be a system)
  - security (constraint on authentication, authorization and data protection)
  - maintainability (how easy is to update and fix bug in the system)

- Non functional requirements can also be about programming language and development method
- Non functional requirements are *more critical* than functional requirements. If they are not met, the system could be useless


- Functional and non functional requirements guide the design of our application and database

### Non functional classification
- **Product requirements**: requirements that specify that the delivered product must behave in a certain way, e.g. execution speed or reliability

- **Organizational requirements**: requirements which are derived from the organization rules and policy (e.g. process standards or the programming language used)

- **External requirements**: requirements which came from factor external to the system and its development process, e.g. legislative requirements, law requirements

- Types of Non-functional requirement:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250930150857.png]]


### Use Cases
- **Use Case**: is a formal description of how actor *interact* with the system
- represent the *activities* performed by users through the system 
- they are defined by a sequence of action that produces a meaningful result for an actor
- they always describe an interaction between actors an the system
- define what functionalities can be used for interact with the system
- usually expressed in UML


### Use Cases Diagrams
- **Use Cases Diagrams**: describe what a system does from the point of view of an external observer
- The emphasis is on what a system *does* rather than how
- Use case diagrams are connected to *scenarios*
- A **Scenario** is an example of what happens when someone interact with the system


### Use Case Analysis


- an **Actor** can be an user or any **outside system** that interact with the system to obtain some *value* from that interaction


- data modeling three stages:
  - analysis of the data
  - identify the entity-relationship model
  - convert the data model in an actual database

- project classes is not needed

- the data model does not depend on the database

- one data model
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250930153543.png]]

- different database to represent the data model
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250930153608.png]]


![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250930150935.png]]

![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250930150953.png]]


![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250930151005.png]]



- mockup is mandatory
- data modeling is also mandatory
- use case diagram is facultative 

topic to know:
- functional and non functional requirements and constraints
- analyze data, entity and relationship
- class data
- codify use cases as mockups 
- design database in third normal form





### Redis: Main Features
- **Redis** (*REmote DIctionary Server*) is an in-memory, multi-model key-value database
- it save all data on RAM, but also on the disk, so that it is possible to reconstruct the database if you reboot the system

- it is possible to distribute the backend other than the database data

- data are structured in key-value, it is like a giant dictionary with key and value
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251118163059.png]]
- it is usually used as cache, but it can also be used as as primary database

- everything that you store it is in a string form
- it has two level of persistence to recover data:
  - snapshotting
  - aof 

- it is possible to use **hash** to store complex data structure, you have a single hash, with some key-value associated
- it has atomic transaction (atomic *group of operation*), so or they perform all or nothing, the db cannot be in a **partial state**

- *Objects* consist mainly of string and various types of collections of strings such as *list* and *hash maps*


- Only *primary key lookups* are supported (you need special attention to secondary indexing)
- in the past was possible to swap less frequently used key to the disk, now this option is deprecated
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251025160415.png]]
- Redis supports *asynchronous master/slave replication*
- if performance is critical and data loss is acceptable, then a replica can be used as a backup database
- in this case the master is configured with *minimal disk-based persistence*
- redis may replicate the state of the master database asynchronously to slaved redis server


# 0 EXTRA SW ENGINEERING 
- **Model-View-Controller (MVC)**: is an architectural pattern that separates an application into three components:
  - *Model*: comprehend data and business logic  
  - *View*: user interface or API representation, it present data to the user
  - *Controller*: mediator that handle user requests and return the response to those request

- the goal of the MVC is to improve **separation of concerns**, maintainability, testability and scalability

- in Java Spring Boot MVC is extended into a multi-layered code organization:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20260104131532.png|100]]


- the **Controller layer** is the entry point for HTTPS requests, maps URL to handler methods accept input, delegate works to the Service later and return API responses
- the **Service later** holds the application business rule, process data, coordinate interaction between controller and **DAO** (repository later)
- the **Repository layer** (*DAO*) encapsulate access ot database, map Java object to database record, should not contain business logic, only interacts with entities

- **DAO** (*Data Access Object*):
  - A general design pattern for accessing data
  - Used when you manually implement database operations
- **Repository** is the Spring's implementation of the DAO concept