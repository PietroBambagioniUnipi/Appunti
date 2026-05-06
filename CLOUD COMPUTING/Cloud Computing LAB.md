# 01 Big Data Processing

- Big data does not come only by the web, other sources can be particles colliders, observatory, DNA sequencing, finance, smart city, Internet of Things
- Data have grown exponentially in the past years and are expected to grow even more

- *Edge computing*: is a kind of cloud computing closer to the final user, you upload your data to a closer and smaller data center instead to upload them into a large and far one

## Divide The Computation 

- If you have huge amount of data you cannot process them sequentially
- A typical application receive an input, perform a computation and return an output
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260309154424.png|200]]

- Let's assume that data are of normal size, but the processing that you have to perform is really complex. In this case you can handle it by decomposing the application into smaller components called **tasks** of **functions**
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260309154500.png|500]]

- They can be executed sequentially, in parallel or a mix of the two approach
- To execute them in parallel they have to be independent
- In this approach we are not dividing the input data, we are giving all the input to each parallel task (*controlled decomposition*)
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260309154642.png|500]]

- Possible problems:
  - how to divide the code into parallel tasks? (you have to understand which parts are independent or not)
  - how to distribute the code among different machine?
  - how to coordinate them? (i can execute some tasks only if some previous ones are completed)

### Parallel Architectures
- The different portions of your code must exchange data, this can happen in many way, for example they can share a memory (e.g. threads), or they can exchange messages (e.g. processes)
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260309154814.png]]

- Typically you identify which pieces of works can be performed concurrently, you partition them onto independent processors, you distribute the program input, output, and data, coordinate access to share data and avoid conflicts
- Depending on the solution that you choose some problem can appear or disappear, for example if you implement the shared memory model you don't have to distribute data, or for message passing parallel programming model, there is no need to coordinate shared data

### Tasks Dependency Graph
- Given a big process we can represent its decomposition into task using a **Task Dependency Graph**
- A given problem can be decomposed into tasks in many different ways

- It is a directed graph (the arrows have a direction), acyclic, where each node represent a task, and each arrow represent the *control dependency* (task that depend to each other, they does not exchange data all the time, so the arrow doesn't mean that they are exchanging data)
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260406115219.png|500]]
- Nodes can contain number that represent the *computational size* of that node, it can be measured in different way like the number of line of code, the computational complexity, the time required on a precise machine and so on.

### Example
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260309155304.png|500]]
- In this example we have a multiplication between a matrix A and a column vector b, the result is a column vector c
- It is possible to execute each multiplication sequentially, but this kind of operation takes a lot of time, it is better to decompose it into smaller problems

- There are *many way to decompose a problem into smaller ones*, there isn't a way that is always better, it depends on your objectives and motivations
- All the operation on a row i, are independent from the operations on the other rows, so you can consider each row independent from the others. If all part are independent they can be modeled as independent different tasks that can be executed on different machines 
- They are **independent** because no task have to wait for the partial or total completion of the others

### Example 2
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260309155503.png|500]]
- another example is a query that have to be executed on a table T, it is possible to perform the query as a sequential computation or decompose it subtask:
  - in the first subtasks you are filtering for the object that are at least of one attribute and filter the original input, after the 4 filtering task are performed you can perform the logical operator and take the cars with the intersection of attribute that you want and then merge everything to obtain the final result 
- It is better than execute it sequentially because you are operating on subset of data
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260309155555.png|500]]


- For the same task you can have a totally different decomposition 
- The decomposition depend on independence between tasks, the possibility or not to change order of operations, and your computational resources (e.g. maybe you don't have enough CPU or machines to execute n tasks in parallel)
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260309155623.png|500]]

- For example another way to decompose the matrix multiplication is to have m rows for each task and not a single row, or to divide each single multiplication in a different machine
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260309155724.png|500]]
- Since we can have multiple way to decompose a problem in subproblem, we have to measures the differences between compositions

- We want to measure if a decomposition is better than another one or not
- there are three metric to do so:
  - *Granularity*
  - *Degree of concurrency*
  - *Critical path length*

##### Task Granularity
- **Task granularity** represent the number of task in which your problem is decompose (e.g. if i create a subtask for each row or each m rows)

##### Degree of concurrency
- **Degree of concurrency**: the number of task that can be executed in parallel, it can be computed in two different way:
  - The *maximum* number of tasks in any level of the graph
  - The *average* number of tasks computed in parallel across all level
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260309160053.png]]
- For instance in the left decomposition the maximum is 4, the average is 7/3, in the right one is 4 and 7/4
- This two decomposition have the same maximum concurrency, but the left one have a smaller average degree of concurrency

- Usually your decomposition is better as the average degree of concurrency better *approximate the maximum* degree of concurrency (if the maximum is closer to the average is better)

##### Critical Path
- You have several directed path in your task graph (a path in the graph represent a sequence of tasks that must be processed one after the other)

- The **Critical Path** length is the longest directed path inside your decomposition 
- It represent a limit on parallelization on your decomposition, if you have number inside the node you have also to *consider the number*, if you don't have number you consider all nodes with the same weight and you consider the length 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260309160316.png|300]]

- For instance in the left decomposition the Critical path is task 4 -> 6 -> 7 with a length of 27 milliseconds, in the right one is 1 -> 5 -> 6 -> 7 with a length of 34 milliseconds


- The Critical Path represent the minimum execution time for your decomposition, in order to have this critical path length you have to have a certain number of CPUs, because if the CPU are fewer than the maximum degree of concurrency you cannot execute the task in parallel so it may require more time
- It's the longest path, and it represent the minimum execution time because even if you follow a shorter path, you have to wait for dependent task to finish before to aggregate the results


### Parallel Performance Limitations 
- You have **limitations** on the way you decompose your problem that depend on the nature of your problem (e.g. in the matrix multiplication you can create a task for each m rows, for each row or for every single multiplication, so up to $n^2$ task) and based on the limitation on the available hardware 
- Dividing one task into a much smaller grain can lead to an overhead in the messages exchanged by different task 

### Tasks Interaction Graph
- The task dependency graph represent the *control flow* of the application
- The **Tasks Interaction Graph** represent instead the *data flow* between your tasks, each node represent a task, you can have inside a node number that represent the computational size, and arrow here represent data exchange between tasks, arrows can have number to represent the amount of exchanged data  
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260406121420.png|500]]

## MapReduce
- Another type of problems is one with small computation, but a huge amount of input data, in this case we need to talk about data decomposition, so divide data into smaller blocks 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260309160839.png|300]]

- The solution is to use the **divide and conquer paradigm**, divide your problem into a smaller ones, and unite the solution of the smaller problem to obtain the solution to the original problem
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260309160917.png|500]]

- All the processes performed in the red blocks are the same, but data are divided into different blocks, we are giving different piece of input to the same piece of code, after the processing is finished we aggregate all the solution to obtain the output

- One way to implement this, is through a **master slave approach**, in which we partition data statically, we create dynamically a certain amount of slaves, and each slave will be assigned to a portion of data (this paradigm does not function well if the assigned tasks are unbalanced)
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260309161103.png]]


- In a typical Big Data Application we:
  1. iterate over a large amount of records
  2. extract interesting information from each of them
  3. shuffle and sort intermediate results
  4. aggregate the final results to generate the final output


- There are some problem into data split:
  - how do i choose the data division?
  - how i can distribute the data across machines?
  - how i can aggregate the intermediate results to obtain the final output? 

### MapReduce
- Some of this problems are managed by the **MapReduce programming model**
- It is a way in which you can model your big data problem, it tells you how you can solve the problem, giving you general rules for processing big data. It is also a framework (pieces of code where you can place and deploy application to execute them in respect of the mapreduce programming model)

- MapReduce have *three* fundamental pillar:
  - **Right level of abstraction**: when we need to decompose data into smaller chunks we have a lot of problem, some of them can be handled by the mapreduce frameworks, the only problem is that you need to respect some rules, so you have some limitation on what you can do, you cannot implement all types of code and application, for example it is recommended to write very few lines of code
  - **Scale out not Scale up**: we need to store huge amount of data, so we need huge amount of resources, we have two solutions, having very few powerful machines, or having a lot of less powerful machines (usually commodity hardware, hardware that can be normally buy in normal shops). The best approach is the second one, so having many non powerful computer, because a powerful computer is much more expensive than a lot of cheaper computer. The problem of this choice is that the greater the number of the machines, the greater the number of failures that will happen in the system, so you need to implement a *fault tolerant* approach to deal with failures, and again the fault tolerance is managed to someone else
  - **Moving computation to data**: is easier to move the code to a machine that store some data, rather than having the code in a machine and moving data into it, it is better to fix data into precise machines

### MapReduce Functional Programming Principles
- Besides those three design idea there are other three principle that come from another programming model called **functional programming**, in which a big problem is decomposed into small problem:
  - Purity
  - Immutability
  - High-order functions

##### Purity
- **Purity** mean that a function have a **deterministic** behavior, so given a certain input it will produce always the same deterministic output (it is also called *idempotency*)
- for instance a function that perform a sum is deterministic, if it return the current time is not deterministic
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260309161851.png]]

##### Immutability
- **Immutability** refers to the fact that we don't have the concept of **variables**, we only have temporary variable inside functions, but the input of a process is not a variable
- All variables should be considered as constants
- If you want to modify the original input you have to create a copy of that input and work on the copy, this is useful because if you need to only need to read data you can avoid some dependency 
- In this way you cannot have concurrency and the history is never deleted

- another reason is that if you have an input with a data in a certain format, you first need to eliminate all the lines with a missing data, then you will apply the processing of the function to the filtered data
- you don't want to delete intermediate or original data, you need to keep your history, so if there is a problem you can execute again the code on the original data
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260309162101.png]]

##### Higher-order functions
- **Higher-order Functions** are special types of functions that *takes functions as input* or return functions as output
- Mapreduce use them because they provide powerful ways to use function, and this gives more freedom to do certain operations, moreover code are clearer and easier to understand



# 02 MapReduce Programming Model
- Mapreduce is a programming models, it tells the developer how he should develop his function to obtain a certain goal
- The programmer have to specify *two functions*:
  - **mapper**: it takes in input one [key, value] pairs and return some key value (zero or more)
  - **reducer**: it takes in input one [key, list of value] and return a key value pair (zero or more)

- Both functions are *stateless*: the new iteration of the function execution has no idea of the previous state, we do not save any information about previous states 

### Map Reduce Application
- We have our big input, we divide it in smaller pieces, each will be mapped to a mapper that will be produce some key value pairs, those will go in input to MAGIC (shuffle and sort block), that will map the data to the reducers, each of them will process data, produce a result that will be aggregated in the final output
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260406123252.png]]

### More on mappers
- Mappers should run on nodes which hold their portion of the data locally to avoid network traffic 
- Multiple mappers run in parallel, each processing a portion of the input data
- Mapper ignore the input key, they usually care only about the input value and do something with it (sometimes the key is not relevant at all, e.g. in the word count example the initial key can be the offset where the subtext start, but other time is useful)

### More on reducers
- The next step will start when all mappers has finished their execution
- You can have one or more reducer
- All the values associated to a particular intermediate key will be mapped to the same reducer 
- The key are not unique, you can have the same key produced by multiple mapper, so reducer takes as input a key and the list of value, and all element associated to a key will be mapped to the same reducer 
-  The reducer outputs zero or more final key/value pairs (these are written to the distributed file system)


### Wordcount Example
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260406123810.png|500]]

- Mapper and reducer:
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260406123836.png|400]]

- We have as initial input a big chunk of text 
- We split the data in sub chunk and map each of them to a mapper
- Every mapper will return the key as a word, and as value the time that a value appear on the sub chunk
- The shuffler will group them by key (to create a key associated to a list of value) and map them to the reducer
- The reduce will associate all the result and create the final output 
- All the reducer input will be aggregated to obtain the final output

- **Shuffling**: aggregate the input by key to create a key associated with a list of value 
- **Sorting**: sorting the keys in some way, e.g. if they are text we can sort them in alphabetical order, this allow to process the key in a logical order (because we need a deterministic behavior), in this way the final output will be the same
- **Partitioning**: partition the set of key to the reducer, it decide how to map the (key, list of value pairs) to the set of your reducer

##### Cascade Tasks
- It is possible to have multiple map task in cascade 
- For example if we want to know the *frequency* of the words across the document we need to perform two map reduce computation, the first one will compute the number of total words, then we will give this to the next word count task like the one we defined before 

##### Image Data Example (I)
- Another example is: we have several picture of the area of Pisa in different formats, timestamp, resolution, and we want to create a single big image
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260406124532.png]]

- To do so we divide the territory of pisa into tiles with fixed location IDs, we split each source image according to the tiles it covers, for a given tile we take the one with higher resolution, or maybe the newer one
- then we merge all the tiles to obtain the final image of pisa
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260406124631.png]]

- The class mapper will process one portion of data, in the image example are for instance 100 image, then it will process each image one by one, every time for each image we will call the map method that will emit the key value pair and then it will move to the next one
- In the same for word count we will execute the map method for each line of text, the single mapper will finish its execution when all the line of text associated with it are executed

### Partitioners
- **Partitioning** mean take your key space produced by the mappers, and try to split them to the various reducers
- you always have a default partitioner so you don't need to implement one, and 99% of the time it is fine for your task, but is it possible to override it  

- The default one ignore the list of value associated with each key, it partition the space only based on the keys, and split the keys among reducers (its behavior can be seen on the left), this can cause problem if one of the key have a very imbalanced number of value, on the right you can see a overridden partitioner that takes in account also the list of value for the partition 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260406124815.png]]

### Combiners
- **Combining** is an optional step, it is an optimization of your code
- Mapper can generate an output bigger than the original input
- Combiner associate another piece of software at the end of your mapping computation, each combiner will work on the intermediate output of the combiner, they are mini-reducer, they will perform the same logic as the reducer an aggregate data, the only difference between combiner and reducer are that reducer takes in input the list of value produced by each mapper in the system associated to a certain key, instead the combiner is associated to a single mapper and will process only its output. 
- This allow to transfer much less data to the reducer, we transfer partially aggregated data
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260406124901.png]]

### MapReduce Application
- Here we can see an example of the complete scheme of the MapReduce process 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260406124934.png]]

- MapReduce was created by Google, then Yahoo created its open source implementation called *Hadoop*, Spark is a similar software that use the MR paradigm 


## Hadoop 
### Hadoop Terminology
- A **Mapreduce job** is composed by three component:
  - Input data
  - Mapreduce program
  - Configuration information (settings)

- Hadoop can run a *MapReduce job* by dividing it into two tasks that can be of two types, map tasks, and reduce tasks. The tasks are scheduled using **YARN** (**Yet Another Resource Negotiator**). If a task fails it will be automatically rescheduled to run on a different node

- Hadoop divides the input to a MapReduce job into fixed size pieces called **input split** (they are basically a sub portion of data)

- Hadoop spawns one map task for each split, which runs the user-defined map function for each record in the split

### Hadoop Program Execution
- The debugging phase cannot be performed on an IDE, it has to be performed on hadoop
- Once compiled, an Hadoop program is packed in a JAR file and submitted to a Hadoop cluster

- We need to specify where **HDFS** and **Hadoop daemons** are running


- We can run hadoop in three modes:
  - *Local mode* (or standalone): hadoop runs as a single java process (so on a single jvm), it is the default mode, it has an easier debugging, there are no daemons using this mode. We use a local file system to substitute HDFS. The Jobs will run as if there is 1 mapper and 1 reducer 
  - *Pseudo-distributed mode*: we have a separate jvm for every hadoop component, all daemon run on a single machine using the HDFS, this mode mimics the behavior of a cluster, there can be multiple mapper and reducer, 
  - *Fully-distributed mode*: this is how hadoop runs on a real cluster, all the daemon run's on the cluster's machine using the HDFS protocol, with multiple mapper and reducer

###  Word Count in Hadoop Example
- Via code we need the *mapper*, the *reducer*, and a *configuration file*
```java
//MAPPER
public static class TokenizerMapper extends Mapper<Object, Text, Text, IntWritable>
{
	private final static IntWritable one = new IntWritable(1);
	private Text word = new Text();
	public void map(Object key, Text value, Context context)
	throws IOException, InterruptedException {
		StringTokenizer itr = new StringTokenizer(value.toString());
		while (itr.hasMoreTokens()) {
			word.set(itr.nextToken());
			context.write(word, one);
		}
	}
}

//REDUCER
public static class IntSumReducer extends Reducer<Text,IntWritable,Text,IntWritable>
{
	private IntWritable result = new IntWritable();
	public void reduce(Text key, Iterable<IntWritable> values, Context context)
	throws IOException, InterruptedException {
		int sum = 0;
		for (IntWritable val : values) {
			sum += val.get();
		}
		result.set(sum);
		context.write(key, result);
	}
}

//CONFIGURATION FILE
public static void main(String[] args) throws Exception {
	Configuration conf = new Configuration();
	String[] otherArgs = new GenericOptionsParser(conf, args).getRemainingArgs();
	if (otherArgs.length < 2){
	System.err.println("Usage: wordcount <in> [<in>...] <out>");
	System.exit(2);
	}
	Job job = Job.getInstance(conf, "word count");
	job.setJarByClass(WordCount.class);
	job.setMapperClass(TokenizerMapper.class);
	job.setCombinerClass(IntSumReducer.class);
	job.setReducerClass(IntSumReducer.class);
	job.setOutputKeyClass(Text.class);
	job.setOutputValueClass(IntWritable.class);
	for (int i = 0; i < otherArgs.length - 1; ++i)
	FileInputFormat.addInputPath(job, new Path(otherArgs[i]));
	FileOutputFormat.setOutputPath(job, new Path(otherArgs[otherArgs.length - 1]));
	System.exit(job.waitForCompletion(true) ? 0 : 1);
}
```

### Hadoop Types
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260406142926.png]]
- If a *combiner* is used, it has to be in the same form as the reduce function (the combiner function in an implementation of reducer, but its output types are the intermediate key and value type K2, V2)
- Often the combiner and reduce functions are the same, in this case K3 is the same as K2, and V3 is the same as V2
- The partition function operates on the intermediate key and value types (K2 and V2) and returns the partition index. In practice, the partition is determined solely by the key (the value is ignored)

### Hadoop Configuration
- The **configuration file** is the *main file* of your application, in the first time that is executed you need to instantiate a *configuration object*, it pars all the optional arguments and store them into the array `otherArgs`, that allow to tells where the data comes from, where the output data should be saved, or the number of reducer
- The file with the configuration is called **driver code**
- It can be placed in a different executable, in this case you need to specify in the executable of the driver how the mapper and reducer classes are called. You can also specify the combiner class

- Sometimes you may wish to have a *combiner* in your workflow, but you cannot use it because your aggregation logic must be associative and commutative, because you are pre combining before the final aggregation, if your operation is not associative and commutative you need to combine everything at the end 

- You also specify the types of the output key and value of the reducers
- Sometimes you need to also specify the ones of the mappers 

- If you have a custom sort, partitioning, and shuffling you need also to specify them in configuration

- It is possible to have several input path, each of them can be of several type (a single file, a directory, a file pattern with a regrex expression)
- The output path is unique and can be only a directory of files, inside it you will have one file produced for each reducer 

- When you execute your application and specify the output path, the directory must not already exists (so if you execute two times one experiment the second time the experiment will never start, it will not override the old file), you have two possibility:
  - delete the old directory and execute again the experiment (NEVER DO THAT, because it broke the *immutability*)
  - create directory with an incremental suffix

- The last line of code execute the actual application and wait for the completion of the map and reduce, you can specify here if you want a verbose output or not

### Hadoop Job Configuration
- some output key types, output value types, coincide with, input key types and value types, others do not 
- since you have several types you can have some issues, in this schema you can see which types should be the same: 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260406143249.png]]

- Input types given to your map tasks are imposed by this input format class, in case of text file you need to use `TextInputFormat`

- you can set the number of reducer, but not the number of mappers, the number o mappers depend on the types of the input split and this is decided by hadoop 

- Serialization mean take one object and decompose it into a string of bytes, this allow to write the string of bytes to disk or transfer it through the network. Hadoop implement its own serialization because is faster and more compact, and is called **Writable**

- Writable is an interface, it is composed by `write`, `readFields`, and `WritableComparable` (to compare object)
- There are wrapper for all java primitive types


- `InputSplit` is a portion of the data given as input to each mapper, they are logical partition of your data, they are not physical partition, so it is not always true that it correspond to a single file or block or file, so you can have an input split that start from the midpoint of a file and finish at the midpoint of another
- Is a reference to your input data, is like a pointer, it specify the address from which a mapper have to start his processing, it specify also the length of the split
- It order input split from the longer to the shortest and assign the longest first to finish as much as possible at the same time the computation of each mapper


- `getSplit` takes your input and decide the number of split
- createRecordReader is used by each single mapper so that when the mapper task start, before invoke for the first time the map function, it invoke the createRecordReader to create an iterator that allow to extract line by line the input
- You don't need to invoke these functions, they are automatically called by hadoop 


- `setup` is executed before the first map function, it can set parameters, or pass some configuration settings 
- `cleanup` is executed after the last invocation of the last map function, and it is used to clean resources and pass some information to other component 


### Hadoop Job Configuration 
- Input Types are set by the input format, the other types are set explicitly by calling the methods on the job
- If not set explicitly, the intermediate types default to the (final) output types, which default to `LongWritable` and `Text`(custom type of hadoop that represent a string)
- IntWritable: custom type of hadoop that represent an int

- For instance, if K2 and K3 are the same, you don’t need to call `setMapOutputKeyClass()`
- Similarly, if V2 and V3 are the same, you only need to use `setOutputValueClass()`
- It is possible to configure an Hadoop job with incompatible types, because the configuration isn’t checked at compile time.

- **context** is an object used by the mapper to emit the key value pairs

### Hadoop Configuration Defaults
- The only configuration that we set is an input path and an output path.
- The default input format is `TextInputFormat`
- The key is of type `LongWritable`, and the value is of type `Text`
- The default mapper is the Mapper class, which writes the input key and value unchanged to the output
- The output key is of type `LongWritable`, and the output value is of type `Text`
- The default reducer is the Reducer class, which simply writes all its input to its output
- The output key is of type `LongWritable`, and the output value is of type `Text`
- The default partitioner is `HashPartitioner`, which hashes an intermediate key to determine which partition the key belongs to
- Each partition is processed by a reduce task
- So the number of partitions is equal to the number of reduce tasks for the job
- By default there is a single reducer, and therefore a single partition
- We did not set the number of map tasks
- The number is equal to the number of splits that the input is turned into
- It depends on the size of the input and the file’s block size (if the file is in HDFS)




# 03 Hadoop
### Serialization in Hadoop
- **Serialization** is the process of turning objects into a byte stream
- **Deserialization** is the reverse process of turning a byte stream back into a series of objects

- Serialization is used:
  - for interprocess communication
  - for persistent storage

- In Hadoop, *interprocess communication* between nodes in the system is implemented using remote procedure calls (**RPCs**). RPC protocol uses serialization/deserialization
- Hadoop uses its own serialization format called **Writables**, that is compact, fast, and not so easy to extend or use from languages other than Java
- There are other serialization frameworks supported in Hadoop, such as Avro, Thrift, Protobuffers, but Writables are the most used 

### Writable Inferfaces 
```java
package org.apache.hadoop.io;
import java.io.DataOutput;
import java.io.DataInput;
import java.io.IOException;
public interface Writable
{
void write(DataOutput out) throws IOException;
void readFields(DataInput in) throws IOException;
}
package org.apache.hadoop.io;
public interface WritableComparable<T> extends Writable, Comparable<T>
{
}
```

IntWritable Example (I)
```java
package org.apache.hadoop.io;
import java.io.*;
public class IntWritable implements WritableComparable {
private int value;
public IntWritable() {}
public IntWritable(int value) { set(value); }
public void set(int value) {
this.value = value;
}
public int get() {
return value;
}
public void readFields(DataInput in) throws IOException {
value = in.readInt();
}
public void write(DataOutput out) throws IOException {
out.writeInt(value);
}
```

IntWritable Example (II)
```java
public boolean equals(Object o) {
if (!(o instanceof IntWritable))
return false;
IntWritable other = (IntWritable)o;
return this.value == other.value;
}
public int hashCode() {
return value;
}
public int compareTo(Object o) {
int thisValue = this.value;
int thatValue = ((IntWritable)o).value;
return (thisValue<thatValue ? -1 : (thisValue==thatValue ? 0 : 1));
}
public String toString() {
return Integer.toString(value);
}
```

### Writable Wrappers
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260417174046.png]]



### Writable Class Hierarchy
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260417174135.png]]


### Hadoop Input (I)
  - An **input split** is a portion of the input that is processed by a single map task
  - Each split is divided into records, and the map task processes each record, a key-value pair  in turn
  
  - Splits and records are *logical* 
    - Not required to be files, although commonly they are
    - In a database context, a split might correspond to a range of rows from a table, and a record to a row in that range 
    - Input splits are represented by the class `InputSplit` 
    - An InputSplit has a length in bytes and a set of storage locations (i.e., hostname strings) 

- A split doesn’t contain the input data 
  - A split is just a reference to the data 
  - The storage locations are used by Hadoop to place map tasks as close to the split’s data as possible 
  - The size is used to order the splits so that the largest get processed first, to minimize the job runtime

- As a MapReduce application writer, you do not need to deal with `InputSplits` directly, as these are created by an `InputFormat` interface implementation
```Java
public abstract class InputFormat<K, V>
{
public abstract List<InputSplit> getSplits(JobContext context)
throws IOException, InterruptedException;
public abstract RecordReader<K, V> createRecordReader(InputSplit split, TaskAttemptContext context)
throws IOException, InterruptedException;
}
```

- Splits for the job are created through the `getSplits()` method
- Splits are then sent to the application master, which uses their storage locations to schedule map tasks that will process them on the cluster
- The map task passes the split to the `createRecordReader()` method on `InputFormat` to obtain a `RecordReader` for that split.
- A `RecordReader` is little more than an iterator over records, and the map task uses one to generate record key-value pairs, which it passes to the map method.

### InputFormat  Class Hierarchy
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260417174817.png|300]]


### OutputFormat Class Hierarchy
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260417174838.png|300]]

### The setup and cleanup methods
- It is common to want your Mapper or Reducer to execute some code before the map() or reduce() method is called for the first time
  - Initialize data structures
  - Read data from an external file
  - Set parameters

- The **setup()** method is run before the map() or reduce() method is called for the first time
`public void setup(Context context)`

- Similarly, you may wish to perform some action(s) after all the records have been processed by your Mapper or Reducer
- The **cleanup()** method is called before the Mapper or Reducer terminates
`public void cleanup(Context context)`


### Passing parameters
```java
public class MyDriverClass
{ public int main(String[] args) throws Exception
{ int value = 42;
Configuration conf = new Configuration();
conf.setInt ("paramname", value);
Job job = new Job(conf);
// ...
return job.waitForCompletion(true);
}
}
public class MyMapper extends Mapper
{
public void setup(Context context)
{ Configuration conf = context.getConfiguration();
int myParam = conf.getInt("paramname", 0);
// ...
}
public void map...
}
```

## Hadoop Distributed File System
### Requirements/Features for a DFS
- It is a **distributed file system** 
- Manages storage across a network of machines in a cluster
- Designed to run on clusters of low cost commodity hardware (do not require a specific hw) 
- Highly fault-tolerant

### Organization of a DFS
- Files are divided into **chunks** (or *blocks*), typically 64/128 megabytes in size
- **Blocks** are *replicated* at different compute nodes (usually 3 or more)
- Nodes holding copies of one block are located on *different racks* of your cluster (racks are wardrobes with a different servers)
- Block size and the degree of replication can be decided by the user
- A special node (the master node) stores, for each file, the positions of its blocks
- The master node is itself replicated 

### Blocks
- **Single-disk filesystems**: 
	- Minimum amount of data that it can read or write
	- File System Blocks are typically few KB
	- Disk blocks are normally 512 bytes

- **DFS**:
	-  DFS Block is much larger (64/128 MB by default in HDFS) to minimize the cost of seeks
	-  Unlike single-disk file system, the smaller file does not occupy the full 64MB block size
	-  Block abstractions allows, so a file can be larger than any single disk
	- We use the block as unit of abstraction to simplify the storage subsystem

### Namenodes & Datanodes
- HDFS has a **Master/slave** architecture, 
- An HDFS cluster consists of a **single Namenode**, a master server that manages the file system namespace and regulates access to files by clients (The namenode knows anything about everything that regard the storage)
	- Maintains filesystem tree
	- Files metadata
	- File-to-block mapping
	- Location of blocks (i.e., on which datanodes)
	- Access permissions

- There are a number of **Datanodes**, usually one per node in a cluster.
- Datanodes store and manage the actual data blocks.
    - A file is split into one or more blocks, and blocks are stored in Datanodes.
    - The Datanodes manage storage attached to the nodes that they run on.
    - Datanodes serve read/write requests, perform block creation, deletion, and replication upon instruction from Namenode.
    - Each Datanode sends a heartbeat message periodically to the Namenode.

- If the NameNode fails (so the master), everything concern the storage fails, there are some mechanism to resolve this

### HDFS Architecture
- what happen when you want to write a file:
  - you have a client (a middleware between the map task and the HDFS component), it stay between the real client and HDFS
  - periodically DataNode send an Heartbeat to the NameNode do tell him they are alive
  - the client can ask to the Namenode to write a file that is bigger than one node
  - the Namenode check if the client have the permission or not to perform a write in the cluster
  - if the client have the permission, the Namenode will tells to the cluster where to write the blocks
  - then the replication is performed automatically between datanode without any intervention from the namenode


- Example:
		![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260417175753.png|300]]![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260417175759.png|300]]
		![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260417175804.png|300]]
		![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260417175809.png|300]]
		![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260417175814.png|300]]
		![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260417175819.png]]
		![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260417175824.png]]
		![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260417175829.png]]
		


### Anatomy of a read
- Here we can see how a read is performed on HDFS
- Here we have an HDFS client on the left, the client here represent the actual client, for instance a map task
- first he request to open the file that he want to read
- the open operation is performed between the client and the DFS (it is the client of the previous example, so an interface in between the actual client and HDFS)
- the DFS will ask namenode to obtain the location of the block with the file 
- the namenode will return the ordered list of the blocks with all the replicas for one block, where the order is the *proximity between the client and the block*, to minimize the transfer of data in the network. (*how does it know the proximity?*)
- DFS will return this information to the client
- the client will request to read to the FS data input stream, it is asking to read the whole file, the client do not know anything about block because this information is abstracted
- FS know in which datanode is one block and will request to the closest datanodes to the client to read the blocks
- when the client finish to read he call a close operation to the FS

- All this operation are already implemented in HDFS
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260417175921.png]]

### Network Topology and Hadoop
- *how does it know the proximity?*

- Hadoop approach: the network is represented as a tree, and the distance between two nodes is the sum of their distances to their closest common ancestor
- in a single data center you have different *racks*, inside each racks you have servers, the data know use an algorithm to know the proximity, the client is the blue square, it can see if the node are in the same server, in the same rack, in the same data center, on in a different data center, in those case the distance continue to increase
- The distance between two nodes is the number of arcs that you need to traverse in the hierarchy graph to go from a node to another, for instance to go from node n1 to n2 you need to traverse 2 arcs, to go from n1 to n3 you need to traverse 4 arcs instead 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260417175956.png]]


### Anatomy of a write
- You want to create and write a file
- Assume that the client is a reduce task, it compute something and write the result to hdfs
- it request to create the file to the DFS
- DFS forward the request to the NameNode that will decide the number of blocks and their location
- lets assume that we have a replication level equal to 3
- the namenode will return all information on the blocks, that will be abstracted
- those information will be sent from the client to FS 
- FS will write a block in the number of datanode equal to the number of replication chosen 
- the packet are sent to a datanode, the datanode will be in charge to replicate the data to another datanode (there is no intervention from the datanode), the second datanode will replicate the data to another datanode
- this last point is performed for each block
- when the write operation is finished we sent a message to FS that will send a message to the Namenode to tell him that the operation is completed
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260417180009.png]]

### Replication on Datanodes
- *How does the namenode choose which datanodes to store the replicas of each block?*
- First replica is written on the same node as the client
- For clients running outside the cluster, a node is chosen at random
- Second replica on a different rack from the first, chosen at random
- Third replica on the same rack as the second, but on a different node chosen at random
- Further replicas are placed on random nodes in the cluster
- The system always tries to avoid placing too many replicas on the same rack/node

## Hadoop Distributed Resource Management
### Resource management in Hadoop versions
- we have several computer that offers computation and memory, we need to understand how to allocate those resource to perform the map reduce task
- in the first version of hadoop, we had only the map reduce execution framework and the hdfs, the management of resource was performed by the map reduce framework and this created a lot of problem
- in recent version it was introduced YARN to managing resources 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260417180053.png]]

### Hadoop 1.0
- **Job**: Unit of work that the client wants to be performed
- **Task**: Unit of work that Hadoop schedules and runs on nodes in the cluster (map & reduce)
- **Slot**: *Processing element for tasks* (map & reduce slots). but the amount of resources was predefined and cannot be changed, so if your map task was bigger than the slot size or much bigger you could have over utilization or under utilization. Each slot has a tag (map or reduce), and if a slot was tagged "map" you couldn't use it for reduce task  even if it was free. 
- **Job Tracker**: Accepts jobs submitted by users, creates tasks, *assigns map and reduce tasks* to Task Trackers, and *monitors tasks and Task Trackers status*, keeping a record of progress for each job and re-executing tasks upon failure
- **Task Tracker**: Runs map and reduce tasks upon instruction from the Job Tracker, manages storage and transmission of intermediate output, and sends progress reports to the Job Tracker

- Job tracker was basically the master and the task tracker the slaves. The job tracker allocate resources and know everything about the cluster, and it also monitor the tasks execution, since it was in charge of too many duty it was a bottleneck of the system and not scalable

- the blu highlighted concepts (in the test above) are the main problems in Hadoop 1.0
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260417180115.png]]



### Hadoop 1.0 Limitations
- **Scalability**:
  - Job Tracker performs resource allocation and monitoring for all the jobs
  - No more than 4,000 nodes and 40,000 concurrent tasks (whereas with YARN, it goes up to 10,000 nodes and 100,000 tasks)

- **Availability**
  - Job tracker is a single point of failure
  - Any failure kills all queued and running jobs
  - Replicating the state of this component to achieve availability can be complex

- **Resource Utilization** 
  - Due to the predefined number of map and reduce slots for each Task Tracker, utilization issues occur, e.g., a reduce task has to wait because only map slots are available in the cluster
  - Furthermore, a slot can be too big (waste of resources) or too small (which may cause a failure) for a particular task

- The bigger limitation is the bottleneck (the problem with scalability) not the single point of failure

### YARN Components
- **YARN** provides its core services via two types of long-running daemons to manage the resource
  - a *Resource Manager* (one per cluster) to manage the use of resources across the cluster, it is basically the master
  - a *Node Managers* (one per node in the cluster) to launch containers and monitor usage of container resources, reporting stats to resource manager, it is basically a slave

- A **container** is a set of memory and computation resources allocated to run an application-specific process (e.g., a map or reduce task).
- A *resource request* for a set of containers can express
  - the amount of computer resources required for each container (memory and CPU) 
  - locality constraints for the containers in that request (e.g., allocate container on a node where there is a replica of the HDFS block)

- If the *locality constraint* cannot be met (so to execute a task where data reside), no allocation is made (so it is mandatory to execute the application on the same data where data reside) or the constraint can be loosened (e.g., on another node in the same rack)

- A container do not have a predefined set of resource and was not tagged with map or reduce, it can be used by both
- job tracker was performing resource allocation and monitoring, the resource allocation only resource allocation (monitoring is performed by another component called *application master*), to it is less a bottleneck and the system can scale more



# 04 YARN

### YARN Scheduling 
- scheduling: decide where to execute each tasks 

- In the real world, cluster resources are limited
- Scheduling (i.e., allocating resources to applications) is a complex problem and there is no one “best” policy
- **YARN** provides different schedulers that allocate resources to applications based on *different policies*
##### FIFO Scheduler
- The **FIFO Scheduler** places applications in a single queue and runs them in the order of submission (first in, first out)
- Requests for the first application in the queue are allocated first; once its requests have been satisfied, the next application in the queue is served
- Simple to understand and no configuration needed
- Not suitable for shared clusters. Large applications will use all the resources in a cluster, so other applications have to wait their turn
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260418163217.png|300]]
- it is simple but it can cause starvation

##### Capacity Scheduler 
- The **Capacity Scheduler** has *separate queues* 
- Each queue dedicated to an organization accessing the cluster 
- Each queue configured to use a given fraction of the cluster capacity 
- Within a queue, applications are scheduled using FIFO scheduling 
- A large job finishes later than when using FIFO Scheduler 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260418163337.png|300]]
- there could be under utilization even when a queue is free the other user cannot use those resources

##### Fair Scheduler 
- The **Fair Scheduler** have the following characteristics:
  - There is no need to reserve a set amount of capacity 
  - It will dynamically balance resources among all running jobs 
  - E.g., when the first job starts, it gets all cluster resources (it is the only one running). When the second job starts, it gets half of the cluster resources, and so on 
  - *Fair scheduling is per-user*: if user A submits two jobs and user B only one, then each A’s job gets 25% while B’s job gets 50% of resources 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260418163455.png|300]]

##### Delay Scheduling 
- It is not a separated scheduling approach, is a different way to work for capacity and fair

- All YARN schedulers try to honor locality requests. 
- On a busy cluster, however, there is a good chance that a required node is saturated by other containers at the time of a request 
- As seen, we can loosen the constraint by allocating resources on another node on the same rack 
- In practice, waiting a short time (no more than a few seconds) can dramatically increase the chances of being allocated a container on the requested node, and therefore increase the efficiency of the cluster 
- This feature is called **Delay scheduling** and is supported by both the Capacity Scheduler and the Fair Scheduler 
- Every node manager in a YARN cluster periodically sends a heartbeat request to the resource manager:
  - *Heartbeats* contain information about the node manager’s running containers and the resources available for new containers 
  - Each heartbeat is a potential scheduling opportunity for an application to run a container 
  - When using delay scheduling, the scheduler doesn’t simply use the first scheduling opportunity it receives, but waits for up to a given maximum number of scheduling opportunities to occur before loosening the locality constraint

##### Anatomy of a MapReduce application run 
- Here is shown what happen when you submit an application to the hadoop cluster
- we have a lot of components
- all the blue components are offered and provided by hadoop
- the orange one are the one implemented by the developer, where the one on the left is the main, the one on the right is the map reduce task
- when you start the main program 
- it send to job that will wait for completion
- the resource manager assign an ID to each job
- the JOB will go to HDFS to store some information needed for the Job execution 
- then we submit the effective application to resource manager
- him will deploy the application to the node master that will forward it to the application master that will start the execution
- it will require the necessary data to HDFS
- the application master will also monitor the execution, and act as broker between the resource manager and the node manager
- the resource manager tell which resource you can use
- the node manager are used as resource 
- the node manager will start a JVM which contain a yarn child used to start the jvm and retrieve info HDFS
- then we can start the map task

- sometimes when you execute your application you can receive some feedback on the terminal, uber mean that all your job is executing inside the application master that can decide to execute map or reduce inside himself, but it is uncommon if you don't ask him 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260418163704.png|300]]

### Fault Tolerance 
- A lot of component can fail in every moment

 - **When we have a task Failure**. 
   - The user code in the map or reduce task throws a runtime exception
	   - The task JVM reports the error back to its parent application master before it exits. 
	   - The application master marks the task attempt as failed 
	   - The application master frees up the container 
   - Sudden exit of the task JVM
     - The node manager informs the application master 
     - The application master marks the task attempt as failed 
     - The application master frees up the container 
   - Hanging tasks 
     - The application master notices that it hasn’t received a progress update for a while 
     - The task JVM process will be killed automatically after this period (typically 10 minutes) 
     - The application master marks the task as failed 

- When the application master is notified of a task attempt that has failed, it will reschedule execution of the task 
- The application master will try to avoid rescheduling the task on a node manager where it has previously failed 

- it is more dangerous if the application master fails

-  **Application Master Failure**
    - Application master periodically sends heartbeats to the resource manager. 
    - The resource manager will detect the failure and start a new instance of the master running in a new container (managed by a node manager) 
    - The client needs to go back to the resource manager to ask for the new application master’s address (this process is transparent to the user) 
    - If a MapReduce application master fails twice it will not be tried again and the job will fail 

- if the node manager fail is even more dangerous

- **Node Manager Failure** 
    - Node managers periodically send heartbeats to the resource manager 
    - The resource manager will notice a node manager that has stopped sending heartbeats if it hasn’t received one for 10 minutes 
    - The resource manager will remove it from its pool of nodes to schedule containers on 
    - Any task or application master running on the failed node manager will be considered failed and will be therefore recovered by using the mechanisms seen before 
    - Node managers may be blacklisted if the number of failures for the application is high (even if node manager itself has not failed)
    - Blacklisting is done by the application master 

- if the resource manager fails everything crash without a standby resource manager 

- **Resource Manager Failure**  
    - Failure of the resource manager is serious: without it neither jobs nor task containers can be launched 
    - In the default configuration, the resource manager is a single point of failure 
    - To achieve high availability, it is necessary to run a pair of resource managers in an active-standby configuration 
    - Information about all the running applications is stored in a highly available state store 
    - The standby resource manager can recover the core state of the failed active resource manager 
    - The transition of a resource manager from standby to active is handled by a failover controller 
    - The default failover controller uses leader election mechanism to ensure that there is only a single active resource manager at one time 
    - Clients and node managers must be configured to handle resource manager failover. They try connecting to each resource manager in a round-robin fashion until they find the active one. 

### Speculative Execution 
- Problem: **Stragglers** (i.e., slow tasks) significantly lengthen the completion time of the job (e.g. a very slow map task)
- Tasks can be slow due to hardware degradation, or software misconfiguration 
- Solution: *Speculative execution* 
  - Application master tracks the progress of all tasks of the same type (Map and Reduce) in a job 
  - Launches speculative duplicate tasks for the small portion of tasks that are running significantly slower than the average 
  - Whichever one (i.e., original and speculative) finishes first, “wins”. The other is killed. 
- Additional cost: a few percent more resource usage 

### Shuffle and Sort
- Here we can see how the shuffle and sort is performed in hadoop
- we memorize the result of mapper in a buffer in memory, the buffer is not unlimited, when 80% is reached a tread is executed in parallel to mapper task, and it memorize the content of the buffer to the disk in a file called *spill file*, it use the local disk of the machine, not hdfs, on each of the spill file you have partitioning, sort and combining, each area will go to a different reducer, inside each area dara are sorted by key 
- all the spill file will be merged and given to reducers, a single partition will go to a single reducer
- we know that an output of a mapper is ready to be transferred to a reducer thanks to an heartbeat, the reducer will then copy data locally in a mixture of memory and disk (not HDFS), we merge together data from different mapper, and it is given to the reducer that will produce data that will be stored on HDFS 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260418163728.png]]



# 05 Spark
### Hadoop vs Spark
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260418174317.png]]

### Limitations of Map Reduce
- Limitations of Map Reduce:
	- MapReduce is great at *one-pass* computation
	- Inefficient for *multi-pass* algorithms
	- No efficient primitives for **data sharing**
		- State between steps goes to distributed file system
		- State during shuffle and sort goes through local disk storage
	- **Communication and I/O** in MapReduce is the real bottleneck


### Spark Stack
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260419155244.png]]

### Spark Core
- **Spark Core** provides basic functionalities, including:
	- *DAG* scheduler (manages the execution plan)
	- interaction with HDFS and resource managers (e.g., YARN)
	- memory management (access, caching and shuffling)
	- RDD

- **Resilient distributed dataset** (**RDD**) is a collection of items distributed across many compute nodes that can be manipulated in parallel and are resilient 
- *Spark Core* provides many APIs for building and manipulating these collections 
- Written in Scala but has APIs for Java, Python and R

### Resilient distributed dataset (RDD)
- A resilient distributed dataset (RDD) is a distributed *memory abstraction*
- Immutable collection of objects spread across the cluster
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260419155544.png]]

- An RDD is divided into a number of **partitions**, which are *atomic pieces of information*
- Partitions of an RDD can be stored on different nodes of a cluster
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260419155553.png]]


### Lineage

``` Python
file.map(lambda r e c : ( r e c . t y p e , 1 ) )
.reduceByKey(lambda x , y : x + y )
. f i l t e r ( lambda ( t y p e , count): count > 10)
```
- RDDs track **lineage** info to rebuild lost data
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260419155646.png]]
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260419155658.png]]
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260419155710.png]]
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260419155714.png]]

### Spark Architecture
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260419155735.png]]


### Spark Applications Architecture
- A Spark application consists of:
  - a driver **process** 
  - a set of **executor** processes
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260419155808.png|500]]


### Spark Driver
- The **driver** process is
  - the *heart* of a Spark application
  - runs *in a node* of the cluster
  - runs the *main()* function

- It is responsible for three things:
	1. *Maintaining information* about the Spark application
	2. *Interacting* with the user
	3. *Analyzing, distributing and scheduling* work across the executors


### Spark Executors
- Responsible for two things:
	1. *Executing code* assigned to it by the driver
	2. *Reporting the state* of the computation on that executor back to the driver



### Spark Context
- The driver process is composed by:
  - A spark **context**
  - A **user code**
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260419160058.png]]


- The **SparkContext** object represents a connection with the cluster system
- In the *pyspark* shell
  - a SparkContext is created automatically on start
  - It is accessible through the variable s c
  - In a Python script including a Spark application you need to create it as soon as necessary
``` python
# import spark
from pyspark import SparkConf, SparkContext
# initialize SparkConf
conf = SparkConf()
# s e t t h e a p p l i c a t i o n n a m e
conf.setAppName("My Spark App")
# i n i t i a l i z e a new SparkContext with Spark configuration
s c = SparkContext(conf=conf)
```

##### Submit and Master flag on Spark
- You submit Spark jobs using *spark-submit*
- Use the *--master flag* to the spark-submit command to specify the execution mode for the Spark application (driver + executors)

- The master flag can assume different values, e.g.:
  - **local**: run in local mode as a single JVM process, using a single core
  - **local\[N\]**: run in local mode with N cores
  - **local\[\*\]**: run in local mode and use as many cores as the machine has (this is conceptually similar to “uber” mode in Hadoop)
  - **yarn**: use the whole cluster through YARN


##### Submit and Deploy mode flag on Spark
- Use the **--deploy-mode** flag to the spark-submit command to specify how the Spark Driver should run
- The deploy-mode flag can assume different values, e.g.:
  - **client**: the Spark Driver runs as part of the spark- submit process. The *default* and mainly used for testing. If the user terminates the spark-submit command or the machine fails, the Driver and the whole Spark application fails. 
  - **cluster**: the Spark Driver runs as a separate process, within the Application Master container if YARN is used.


### Creating an RDD
- Use the parallelize method on a SparkContext object s c
- Turns a single node collection into a parallel collection.
- You can also explicitly *suggest* the number of partitions.
```python
numbers = [ 1 , 2 , 3 , 4 , 5 ]
rdd_numbers = s c . p a r a l l e l i z e (numbers)
print(rdd_numbers)
words = ‘’I love S pa r k ‘ ’.s pl i t( ‘ ’ ‘’)
rdd_words = s c . p a ra l l e l i ze ( w o r d s , 2)
print(rdd_words)
```


- RDDs can be created from *external storage
- Usually, if the file is taken from HDFS, Spark creates as many partitions as the number of blocks in HDFS
- Text file RDDs can be created using the t e x t F i l e ( ) method
```python
r d d = s c . t e x t F i l e ( " / u s e r / h a d o o p / f i l e . t x t " )
rdd = sc.textFile("file.txt ’’, 2)
rdd = sc.textFile(“/user/hadoop/*il*.txt ’’)
rdd = sc.textFile(“/user/hadoop/’’)
```


### Spark Programming Model
- The **Spark Programming Model** is based on *parallelizable operators*, i.e., *higher-order functions* that execute *user-defined functions* in *parallel*

- Data flow is composed of any number of data sources, operators, and data sinks by connecting their inputs and outputs
- Job description based on **directed acyclic graph** (DAG)
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260419161506.png]]


### RDD Operations
- RDDs support two types of operations:
	1. **Transformations**: allow us to build the logical plan
	2. **Actions**: allow us to trigger the computation

- *Transformations* create a new RDD from an existing RDD:
  - Not compute their results right away (*lazy*)
  - They are only computed when an action requires a result to be returned to the driver program.

- *Actions* trigger the computation.
  - Instruct Spark to compute a result from a series of transformations.
  - There are three kinds of actions:
	- Actions to *view data* in the console
	- Actions to *collect data* to native objects in the respective language
	- Actions to *write to output* data sinks


### RDD Actions
- **collect()**  
  Returns all the elements of the RDD as an array at the driver.

- **first()**  
  Returns the first value in the RDD.

- **take(n)**  
  Returns an array with the first *n* elements of the RDD.  
  - Variants:
    - **takeOrdered(n)**  
    - **takeSample(...)**

- **count()**  
  Returns the number of elements in the dataset.

- **max() / min()**  
  Return the maximum and minimum values, respectively.

- **reduce(func)**  
  Aggregates the elements of the dataset using a given function.  
  - The function must be **commutative** and **associative** to ensure correct parallel computation.

- **saveAsTextFile(path)**  
  Writes the elements of an RDD as one or more `part-xxxxx` text files (one per partition).  
  - Requires a **directory path** as argument.  
  - Supported file systems:
    - Local filesystem  
    - HDFS  
    - Any Hadoop-supported filesystem


- Example 1:
```python
numbers = s c . p a r a l l e l i z e ( [ 1 , 2 , 2 , 2 , 1 , 1 , 4 , 3 , 3 , 5 , 5 ] )
numbers.collect() # t r i g g e r s execution on ALL elements, takes time
# l i s t [ 1 , 2 , 2 , 2 , 1 , 1 , 4 , 3 , 3 , 5 , 5 ]
numbers.first ( )
# i n t 1
numbers.take(4) # t r i g g e r s execution on 4 elements, good f o r debug
# l i s t [ 1 , 2 , 2 , 2 ]
numbers.takeOrdered(4)
# l i s t [ 1 , 1 , 1 , 2 ]
withReplacement= True
numberToTake = 4
randomSeed = 123456
numbers.takeSample(withReplacement, numberToTake, randomSeed)
# l i s t [ 1 , 5 , 2 , 5 ]
```

- Example 2
```python
numbers = s c . p a r a l l e l i z e ( [ 1, 2, 2, 2, 1, 1, 4, 3, 3, 5, 5] )
numbers.count()
# i n t 11 numbers.countByValue()
# d i c t { 1 : 3 , 2 : 3 , 4 : 1 , 3 : 2 , 5 : 2 }
numbers.max()
# i n t 5 numbers.min()
# i n t 1
numbers.reduce(lambda x , y : x + y )
# i n t 29
numbers.saveAsTextFile("numbers")
# t h e n , y o u m a y check contents of f i l e s 'numbers/part-xxxxx'
```


### Generic RDD Transformations
- **distinct** removes duplicates from the RDD
- **filter** returns the RDD records that match some **predicate function**
```python
numbers = s c . p a r a l l e l i z e ( [ 1 , 2 , 2 , 2 , 3 , 3 , 4 , 5 , 5 , 5 , 5 ] )
distinct_numbers = numbers.distinct()
p r i n t ( d i s t i n c t _ n u m b e r s . c o l l e c t ( ) ) # t h i s i s an action
[ 2 , 4 , 1 , 3 , 5 ]
even_numbers = d i s t i n c t _ n u m b e r s .f i l te r ( lambda x : x % 2 == 0)
print(even_numbers.collect()) # t h i s i s an action
[ 2 , 4 ]
```


- **map** and **flatMap** apply a given function to each RDD element independently
	- *map* transforms an RDD of length n into another RDD of length n.
	- *flatMap* allows returning 0, 1 or more elements from map function.
```python
data = s c . p a r a l l e l i z e ( r a n g e ( 1 0 ) )
squared_data = data.map(lambda x : x * x )
p r i n t ( s q u a re d _ d ata . c o l l e c t ( ) ) # t h i s i s an action
[ 0 , 1 , 4 , 9 , 16, 25, 36, 49, 64, 81]
squared_cubed_data_1 = data.map(lambda x : ( x * x , x * x * x ) )
print(squared_cubed_data_1.collect()) # t h i s i s an action
[ ( 0 , 0 ) , ( 1 , 1 ) , ( 4 , 8 ) , ( 9 , 2 7 ) , ( 1 6 , 6 4 ) , ( 2 5 , 1 2 5 ) , ( 3 6 , 2 1 6 ) , ( 4 9 , 3 4 3 ) ,
( 6 4 , 5 1 2 ) , ( 8 1 , 729)]
squared_cubed_data_2 = data.flatMap(lambda x : ( x * x , x * x * x ) )
print(squared_cubed_data_2.collect()) # t h i s i s an action
[ 0 , 0 , 1 , 1 , 4 , 8 , 9 , 27, 16, 64, 25, 125, 36, 216, 49, 343, 64, 512, 81,
729]
```


- **sortBy** sorts an RDD
- **union** performs the merging of RDDs
- **intersection** performs the set intersection of RDD
```python
words = s c . p a r a l l e l i z e ( "nel mezzo del cammin d i nostra vita". s p l i t ( " ") )
sorted_words = words.sortBy(lambda w: le n( w))
p r i nt ( s o r te d _ wo rd s . c o l l e c t ( ) ) # t h i s i s an action
[ ' d i ' , ' n e l ' , ' d e l ' , ' v i t a ' , ' mez zo ' , 'cammin', ' n o s t r a ' ]
data1 = s c . p a r a l l e l i z e ( r a n g e ( 0 , 7 ) )
data2 = s c . p a ra l l e l i z e ( ra n g e ( 3 , 1 0 ) )
union = data1.union(data2)
p r i n t ( u n i o n . c o l l e c t ( ) ) # t h i s i s an action
[ 0 , 1 , 2 , 3 , 4 , 5 , 6 , 3 , 4 , 5 , 6 , 7 , 8 , 9 ]
i nte rs e c t i o n = data1. inte rse ction(data2)
p r i n t ( i n t e r s e c t i o n . c o l l e c t ( ) ) # t h i s i s an action
[ 3 , 4 , 5 , 6 ]
```

### Key-Value RDD Transformations
- In a $( k , v )$ pair, $k$ is the key, and $v$ is the value
- To create a key-value RDD:
	- *map* over your current RDD to a basic key-value structure.
	- Use the *keyBy* to create a key from the current value.
	- Use the *zip* to zip together two RDDs of the same length.
```python
words = s c . p a r a l l e l i z e ( "nel mezzo del cammin d i nostra vita". s p l i t ( " " ) )
keywords1 = words.map(lambda w: (w, 1 ) ) p r i nt ( key wo rd s 1 . c o l l e c t ( ) )
[ ( ‘ n e l ’, 1 ) , ('mezzo’, 1 ) , ( ' d e l ’, 1 ) , ('cammin’, 1 ) , ( ‘ d i ’, 1 ) , ('nostra’, 1 ) , ( ' v i t a ’, 1 ) ]
keywords2 = words.keyBy(lambda w: w[0] . u p p e r ( ) )
p r i nt ( key wo rd s 2 . c o l l e c t ( ) ) # t h i s i s an action
[ ( ‘ N ’, ‘ n e l ' ) , ( ' M ' , ' m e z zo ' ) , ( ' D ' , ' d e l ' ) , ( ' C ' , 'cammin'), ( ' D ' , ' d i ' ) , ( ' N ' , ' n o s t r a ' ) ,
( ' V ' , ' v i t a ' ) ]
numbers = s c . p a ra l l e l i z e ( ra n g e ( 7) )
keywords3 = words.zip(numbers)
p r i nt ( key wo rd s 3 . co l l e c t ( ) ) # t h i s i s an action
[ ( ‘ N e l ' , 0 ) , ( ' m ez zo ' , 1 ) , ( ' d e l ' , 2 ) , ('cammin', 3 ) , ( ' d i ' , 4 ) , ( ' n o s t r a ' , 5 ) , ( ' v i t a ' , 6 ) ]
```

- **keys** and **values** extract keys and values from the RDD, respectively
```python
words = s c . p a r a l l e l i z e ( "nel mezzo del cammin d i nostra vita". s p l i t ( " " ) )
keywords = words.keyBy(lambda w: w[0])
# [ ( ' n ' , ‘ n e l ' ) , ( ' m ' , ' m ez zo ' ) , ( ' d ' , ' d e l ' ) , ( ' c ' , 'cammin'), ( ' d ' , ' d i ' ) , ( ' n ' ,
' n o s t r a ' ) , ( ' v ' , ' v i t a ' ) ]
k = keywords.keys()
# [ ' n ' , ' m ' , ' d ' , ' c ' , ' d ' , ' n ' , ' v ' ]
v = keywords.values()
# [ ' n e l ' , 'mezzo', ' d e l ' , 'cammin', ' d i ' , ' n o s t r a ' , ' v i t a ' ]
```

- **reduceByKey** combines values with the same key
- Takes a function as input and uses it to combine values of the same key
- **sortByKey** returns an RDD sorted by the key
```python
words = s c . p a r a l l e l i ze ( " f a r e o non fa re non e s i s t e provare".split( " " ) )
wordcount = words.map(lambda w: (w, 1)).reduceByKey(lambda x , y : x + y )
p r i nt ( wo rd co u nt . co l le c t ( ) ) # t h i s i s an action
[ ( ' p r o v a r e ' , 1 ) , ( ' f a r e ' , 2 ) , ( ' n o n ' , 2 ) , ( ' e s i s t e ' , 1 ) , ( ' o ' , 1 ) ]
sorted_wordcount = wordcount.sortByKey()
p r i n t (sorted_wordcount.collect()) # t h i s i s an action
[ ( ' e s i s t e ' , 1 ) , ( ' f a r e ' , 2 ) , ( ' n o n ' , 2 ) , ( ' o ' , 1 ) , ( ' p r o v a r e ' , 1 ) ]
```

- **join** performs an inner-join on the key
- Other types of join:
	- fullOuterJoin
	- leftOuterJoin
	- rightOuterJoin
	- cartesian

```python
ca rs = s c . p a r a l l e l i z e ( [ " F e r r a r i " , "Porsche", "Mercedes"])
co l o rs = s c . p a ra l l e l i z e ( [ "r e d " , "black", "pink"])
joined = cars.cartesian(colors)
p r i n t ( j o i n e d . c o l l e c t ( ) )
[ ( ' F e r r a r i ' , ' r e d ' ) , ( ' F e r r a r i ' , ' b l a c k ' ) , ( ' F e r r a r i ' , ‘ p i n k ' ) , ( ' P o r s c h e ' ,
‘ r e d ' ) , ( ' P o r s c h e ' , ' b l a c k ’ ) , ( ' P o r s c h e ' , ' p i n k ' ) , ('Mercedes ', ' r e d ' ) ,
('Mercedes ', ' b l a c k ' ) , ('Mercedes ', ' p i n k ' ) ]
ca rs = s c . p a r a l l e l i z e ( [ ( 1, "Ferrari") , ( 1, "Porsche") , ( 2, "Mercedes") ] )
c o l o rs = s c . p a r a l l e l i z e ( [ ( 1 , "red"), ( 2 , "black"), ( 3 , "pink")])
joined = c a r s . j o i n ( c o l o r s )
p r i n t ( j o i n e d . c o l l e c t ( ) )
[ ( 1 , ( ' F e r r a r i ' , ' r e d ' ) ) , ( 1 , ( ' P o r s c h e ' , ' r e d ' ) ) , ( 2 , ('Mercedes ', ' b l a c k ' ) ) ]
```

### Anatomy of a Spark Job
- A **Spark application** doesn’t “do anything” until the driver program calls an action (lazy evaluation)
- Each *action* is called by the driver program of a Spark application
- Each *Spark job* corresponds to one action

![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260419161819.png|400]]

### Spark Stage
- Each *job* breaks down into a series of **stages**
- A stage in Spark represents a *group of tasks* that can be executed together
- *Wide transformations* define the breakdown of jobs into stages
- Wide transformations are those requiring data shuffling, namely more RDD partitions as input (e.g., reduceByKey())
- *Narrow transformations* instead work on a single RDD partition (e.g., map())

### Spark Task
- A *stage* consists of **tasks**, which are the smallest execution unit
- Each task represents *one local computation*
- All of the tasks in one stage execute the *same code* but on *different partitions of the data*
- Basically, a task is the execution of all the narrow transformations of that stage over a specific piece of data

### RDD Persistence 
- By default, each transformed RDD may be *recomputed* each time an action is run on it 
- Spark also supports the **persistence** (or *caching*) of RDDs in memory across operations for rapid reuse 
	- When RDD is persisted, each node stores any partitions of it that it computes in memory and reuses them in other actions on that dataset (or datasets derived from it) 
	- This allows future actions to be much faster (even 100x) 
	- To persist RDD, use *persist( )* or *cache()* methods on it 
	- Spark’s cache is **fault-tolerant**: a lost RDD partition is automatically recomputed using the transformations that originally created it 
- Key tool for *iterative algorithms*

- Using persist( ) you can specify the storage level for persisting an RDD (MEMORY_ONLY, MEMORY_AND_DISK, DISK_ONLY) 
- Calling *cache()* is the same as calling persist( ) with the default storage level (MEMORY_ONLY)



# 06 MapReduce Design Pattern
### Caveat
- The great power of MapReduce lays in its simplicity
- The programmer only needs to prepare input data, configuration information, implement mapper and reducer and, optionally, setup, cleanup, combiner and partitioner
- All other aspects are handled by the framework

- This simplicity has some pros and cons
    - **Pros**: It provides clear boundaries for what you can do and cannot do
    - **Cons**: The programmer has to express any algorithm in terms of a small number of rigidly defined components that must fit together in very specific ways

 - How to *recast/reshape* an algorithm into this programming model, i.e., as a sequence of one or more MapReduce jobs?

- **MapReduce design patterns**: principles/guidelines to build better software, they are not specific to a domain (e.g., text processing). Instead, it is a general approach to solve a problem


### Design Patterns
- Main design Patterns:
   - In-mapper Combining
   - Pairs and stripes
   - Patterns for relational algebra operators
   - Patterns for matrix-vector and matrix-matrix multiplication

## In-mapper Combining 
- *Intermediate data* (i.e., mappers outputs) are:
  - Written locally
  - Transferred from mappers to reducers over cluster network

- *Issues*:
  - **Bottleneck**: Writing to disk and transferring over the network are relatively «expensive» operations
  - Reducing intermediate data translates into increasing algorithmic efficiency

- *Solution*: Local aggregation
  - Use combiners
  - Use In-Mapper Combining


Pseudo-code of the basic word-count algorithm
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260419164815.png]]

Pseudo-code of stateless in-mapper combining
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260419164808.png]]

Pseudo-code of stateful in-mapper combining (the true in-mapper combining)
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260419164801.png]]


- **Advantages**: 
  - Combiners are provided as an optimization to the execution framework, which has the option of using it or not at all. On the other hand, *in-mapper combining* provides complete control on local aggregation process (how and when) 
  - Combiners only reduce the amount of intermediate data that is transferred across the network but do not reduce intermediate data emitted by mappers in the first place and stored on local disk. In-mapper combining provides further control by avoiding unnecessary object creation as output to the mapper

- **Disadvantages**: 
- Memory management is more complex, no automatic spilling is performed as it happens with an external combiner. Therefore, the internal associative array may no longer fit in memory. Solved by: 
    - Either emitting intermediate data after processing every n (how big?) input records rather than all of them 
    - Or monitoring memory footprint and emit intermediate data once memory usage has exceeded a certain (how big?) threshold

### Matrix Generation
- Common problem: Given an input of size $N$, generate a squared output of size $N x N$
- Example: word co-occurrence matrix
	- Given a document collection, emit the bigram counts
	- Where $N$ is the number of unique words
	- Cell $m_{ij}$ contains the number of times word $w_i$ co-occurs with word $w_j$
	- Used for example in statistical natural language processing

- Two solutions:
	-  Pairs
	-  Stripes


### Pairs
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260419164741.png]]


### Stripes
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260419164737.png]]

### Relational Algebra Operators
- **SELECTION**: Select from relation R tuples satisfying condition c(t)
- **PROJECTION**: For each tuple in relation R, select only certain attributes Ai
- **UNION**, **INTERSECTION**, **DIFFERENCE**: Set operations on two relations with same schema
- **NATURAL JOIN**
- **GROUPING** and **AGGREGATION**
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260419164727.png]]

### Selection and projection
- **Selection**:
	- *Map*: each tuple $t \in R$, if the condition $c(t)$ is satisfied, emit the pair $(t, \bot)$
	- *Reduce*: for each pair $(t, \bot, \bot, \dots)$ in input return $(t, \bot)$ as output

- **Projection**:
	- *Map*: for each tuple $t \in R$, construct a new tuple $t'$ (keeping only selected attributes) and return the pair $(t', \bot)$
	- *Reduce*: for each pair $(t', \bot, \bot, \dots)$, return in output $(t', \bot)$

### Union, intersection and difference
- **Union**:
	- *Map*: for each tuple $t$ in $R$ and $S$, emit the pair $(t, \bot)$
	- *Reduce*: for each key $t$, there will be one or two values equal to $\bot$; coalesce them into a single output $(t, \bot)$

- **Intersection**:
	- *Map*: for each tuple $t$ in $R$ and $S$, emit the pair $(t, \bot)$
	- *Reduce*: for each key $t$, there will be one or two values equal to $\bot$; if there are two values, output $(t, \bot)$, otherwise do nothing

- **Difference ($R - S$)**:
	- *Map*: for each tuple $t$ in $R$, emit $(t, R)$; for each tuple $t$ in $S$, emit $(t, S)$
	- *Reduce*: for each key $t$, if there is only one value equal to $(t, R)$, output $(t, \bot)$; otherwise do nothing

### Natural Join
- For simplicity, assume we have two relations R(A,B) and S(B,C). Find tuples that agree on the B attribute values and output them

- **Natural join**
  - *Map*: for each tuple (a, b) from R, output (b, (R, a)) and for each tuple (b, c) from S, produce (b, (S, c))
  - *Reduce*: For each input key b, there will be a list of values of the form (R, a) or (S, c). Construct all pairs and output them together with b. Emit ((a, b, c),⊥)

### Grouping and aggregation
- For simplicity, assume we have the relation R(A,B,C) and we want to group-by A and aggregate on B, disregarding C


- **Grouping and aggregation**
  - *Map*: for each tuple (a, b, c) from R, output (a, b). Each key a represents a group
  - *Reduce*: apply the aggregation operator to the list of b values associated with group keyed by a, producing x. Then output (a, x)

### Stage Chaining
- As map reduce calculations get more complex, it’s useful to break them down into stages, with the output of one stage serving as input to the next


## Matrix-Vector Multiplication
- The matrix does not fit in memory (huge m), and
	1. The vector v does fit in a machine's memory (small n)
	2. The vector v does not fit in machine's memory (huge n)
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260419164613.png]]


### A graphical and simple example of Matrix Vector Multiplication
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260419164651.png]]


### Vector does fit
- The matrix is stored in HDFS as a list of $(i, j, m_{ij})$ tuples
  - The elements $vj$ of $v$ are available to all mappers
  - *Map*: $(( i, j ), m_{ij})$ pair $→ (i, m_{ij}v_j)$ pair
  - *Reduce*: $(i, [m_{i1}v_1, m_{i2}v_2, ..., m_{in}v_n])$ pair $→ (i, m_{i1}v_1 + m_{i2}v_2 + ... + m_{in}v_n)$ pair


![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260419164613.png]]
### Vector does not fit
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260419164613.png]]
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260419164609.png]]
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260419164605.png]]
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260419164558.png]]
- Divide the vector in equal-sized subvectors that can fit in memory
- According to that, divide the matrix in stripes
- Stripe i and subvector i are independent from other stripes/subvectors
- Use the previous algorithm for each stripe/subvector pair

### Matrix-Matrix Multiplication
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260419164544.png]]
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260419164540.png]]

- A matrix can be seen as a 4-attributes relation/table:
    - (**Matrix name, row index, column index, value**) tuples
    - $M → (M, i, j, m_{ij}), N → (N, j, k, n_{jk})$
- As large matrices are often sparse ($0$'s) we omit such tuples
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260419164420.png]]
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260419164413.png]]
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260419164409.png]]
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260419164403.png]]
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260419164357.png]]



---

- the default value of scheme is hdfs
- autority is by default as the current node
- the name of the user in the vm is hadoop

- copyFromLocal to copy a file from the local to hadoop 
- copyToLocal to copy a file from hadoop to local 









-  start-all.sh activate all daemon
- at the page hadoop-namenode-9870 it is possible to see an overview

- Each memory block can reach at most 128MB but they can use less space
- If you have a dataset of 100 file of 2kb, so 100 blocks, so 100 input splits, so 100 map tasks running in parallel and a toy cluster could crash, it is better to have few bigger file than  a lot of small one

- from the Utility session it is possible to browse the file system graphically 
- every directory write in the output directory there is a file \_SUCCESS that means that the application ran without errors
- the output will have a scheme like part-r-00000, part-r-00001 up to 99999 that are the output of the parallel tasks 

- *hadoop jar pat* is used to run an application, you also need to specify the directory of the inputs and the output 

- Try to never cancel a directory and always call them in a different way (for immutability)

- record: a single line in a text tile

- at the port 8089 we can access hdfs
- at the port 8088 we can access yarn, you can see information like the nodes, state, address


- exercise in Java, with multiple file
- we have maven that is like a make file, POM













