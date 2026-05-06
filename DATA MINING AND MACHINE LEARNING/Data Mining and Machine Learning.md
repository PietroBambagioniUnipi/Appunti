# 01 Intro
- **Machine learning**: the capacity of a computer to learn from experience, e.g. to modify its processing on the basis of newly acquired information
- The main idea is to build model from data, in the other hand in traditional programming people have to write the code to resolve a project, in ML you write the algorithm that allow the system to learn from data

- **Data mining**: the practice of searching through large amounts of computerized data to find useful patterns or trends
- in data mining we don't extract data, we extract *knowledge from data*

##### What is Data Mining
- **Data mining**: consist in a process of *knowledge discovery* from data, so the extraction of interesting (non-trivial, implicit, previously unknown and potentially useful) patterns or knowledge from huge amount of data
- It is also called **Knowledge Discovery** (**KDD**) or *mining* in the database field

- We start from raw data, pre-process and integrate data, perform some data exploration, querying and some time some basic visualization, then we apply data mining to discover new info and pattern, we prepare some advance presentation and visualization and we can use them to make decisions
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250922204029.png|400]]


- In ML, the *Data mining phase i*s between pre and post processing, it is important to also evaluate, interpret and select the discovered pattern
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250922204247.png|600]]

- Data Mining is used in classical system like relational database and data warehouse, but also in newer tipe of database and in data stream and sensor

##### Data mining function: classification
- **Classification and label prediction**: 
   - Construct models (function) based on some training examples 
   - Describe and distinguish classes or concepts for future prediction 
   - Predict some unknown class labels

- **Typical classification method** are trees, SVM, NN, rule based, bayes, pattern based and logistic regression

##### Data mining function: cluster analysis
- **Unsupervised learning**: the class label is unknown, so we group data to form new categories (*cluster*), the two main concept are to:
   - maximize intra-class similarity
   - minimize interclass similarity

##### Data mining function: association and correlation analysis
- **Frequent pattern**: (or frequent itemset, e.g. items usually bought together)
- **Association, correlation and causality**: strongly *associated* item aren't always strongly *correlated*

 - **Support**: how many instance have interacted with the same pairs of item (es customer that have bought the same pair of product)
 - **Confidence**: how much the model is sure that there will be a certain pair of objects (e.g. the confidence of how is it likely to buy item2 if we bought item1)

##### Data mining function: outlier analysis
- **Outlier**: a data object that *does not comply with the general behavior of the data*, they can be caused by noise or be actual exception (so really important), they can be analyzed by:
  - product of clustering
  - regression analysis

- They are useful in fields like fraud detection, and rare events analysis

##### Time and Ordering: Sequential Pattern, Trend and Evolution Analysis
  - It is possible to predict trend and ordered data (e.g. people do the ordered actions of buying a sd memory after buying a digital camera)
  - It is also common to do analysis on *data stream*


##### Structure and Network Analysis
- **Graph mining**: finding frequent subgraph, trees and substructures (e.g. chemical compounds)
- **Information network analysis**: we can do *link mining* between graph nodes to extract new relationship 
- **Web mining**: the web is a big information network, there are a lot of different data mining techniques used on it like opinion mining and usage mining

##### Knowledge evaluation
- It is important to *evaluate the extracted pattern* with data mining, not al the extracted pattern are useful
- There are methods to extract directly only interesting knowledge

##### Data Mining: Confluence of Multiple Disciplines
- Data mining is a field related to statistic, because is used to summarize the data, the distribution and also for validate hypothesis 
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250928154639.png]]
- DM is a confluence of a multiple disciplines because it has to handle a big, complex amount of data, with high-dimensionality, that came from a lot of sources, they can be in sequence, from stream and sensor, structured, linked, heterogeneous, spatial, or specific

##### Major Issues in Data Mining 
- We have to mine various and new type of knowledge 
- The space of knowledge is multi-dimensional
- It is a process that incorporate various discipline 
- it is needed to handle noise, uncertainty and incomplete data 
- It is needed to evaluate the found pattern and guide the mining with constraints 

- Sometimes mining is an interactive process
- Sometimes we need to incorporate background knowledge 
- We need to present and visualize the mining results

- We need efficient and scalable algorithms
- We need to manage parallel and distributed stream, also with incremental mining methods

- We need to handle complex types of data
- Mining dynamic, networked, and global data repositories

- We need to consider the social impact of dm, preserve the privacy and be invisible and trustworthy

### Why Today
- Machine Learning and Data Mining are becoming more important because computer are getting more powerful and we are producing huge amount of data, moreover we have developed new advance learning algorithms




# 2 Data
### Main types of data sets
- Type of data set: record, graph, ordered, spatial, image, multimedia

- **Cross table**: matrix that display the multivariate *frequency distribution* of the variables
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250928200112.png]]


- important characteristics of structured data: 
  - *dimensionality*: **Curse of Dimensionality**: as dimensionality increases, data becomes sparse, distances become less meaningful, moreover higher dimensionality bring to increases complexity in storage, computation and analysis
  - *sparsity*: in many attributes most of the values can be zero or missing. **only presence counts**: in some application, the absence of a feature isn't informative, only the presence matter (e.g. recording that someone did buy an object is more useful than knowing that someone didn't buy an object)
  - *resolution*: is the level of granularity at which data is measured or represented, is important because different resolution may reveal different pattern (e.g. hourly or daily price of a stock)
  - *distribution*: is the way that data values are spread across possible outcomes, includes shape, central tendency and spread, it is important to know because knowing the distribution helps to choose appropriate models and statistical tests (e.g. centrality, dispersion, symmetry, distribution type)


- A **Data object** represent an entity, are described by *attributes* and made the dataset
- **Attribute** (or dimensions, features, variables): a data field, representing a characteristic or feature of a *data object* (so an instance)


- **Data types**:
  - **Nominal**: a category, states, or "names of things"
  - **Binary**: are nominal attributes with only two states, they can be:
    - *symmetrical*: both outcome are equally important (e.g. gender)
    - *asymmetrical*: outcome are not equally important (e.g. medical test)
  - **Ordinal**: value have a meaningful order (ranking), but the magnitude between successive value is not known (e.g. small, medium, large)
  - **Quantitative**: integer or real value number
  - **Interval**: measured on a scale of *equal-sized units*, values have order (e.g. calendar dates), they didn't have a true zero point (division make no sense)
  - **Ratio**: they have an *inherent zero point* (also called **natural zero**), e.g. temperature in Kelvin, length

- attributes can be discrete (has only a finite or countably infinite set of values) or continuous (has real number as attribute values)


## Basic statistical description of data 
- We describe the data with basic statistical description to understand better the data

- **Trimmed mean** is used to eliminate the outlier influence in the mean computation, it is the mean obtained by chopping out the 2% top and bottom of extreme values

- Median is a *holistic measure*, so must be computed on the entire dataset as a whole. It is the middle value if odd number, or average of the two values otherwise
- It can be computed by estimation by **interpolation** for grouped data

- To do this we assume that data are distributed uniformly in the interval of the median
- L1 is the starting value of the median group
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250928202223.png]]
- Median is equal to the lower limit of the inferior median class (L1) plus the number of total data divided by 2, minus the number of element before the median in the median class, divided by the frequency of the median class, multiplied by the width of the median class

- relation between median, mode and median: (**empirical formula**)
$$mean - mode = 3*(mean - median)$$
- with this 3 value we can se if the data distribution is symmetric or not


- **symmetric distribution**: mean, mode and median are at the same point at the center of the distribution
- **positively skewed**: mode are smaller than median, and median smaller than mean
- **negatively skewed**: mode are bigger than median, median bigger than mea n 
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250928205527.png]]



### Data visualization
- some statistical visualization:
  - boxplot: display 5 number summary
  - histogram: show values and their frequencies
  - quantile plot: show for each point, how much data are smaller than that point
  - quantile-quantile plot (q-q plot): confront the quantiles of 2 univariate distributions to see if their distribution is similar
  - scatter plot: plot 2 pairs of attributes

- the **k-th percentile** is a value bigger than k percent of data

##### Boxplot
- The **Boxplot** shows: minimum, Q1, median, Q3, maximum. It's a box where the end of the box are Q1 and Q3, the height IQR, the median is marked by a line within the box, **whiskers**: two line outside the box extended to minimum and maximum, **Outliers** are points beyond a specified threshold (usually 1.5\*IQR)
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250928210412.png]]

- **Distributive measure**: a measure that can be computed from subset of the complete data, and then combined without information loss (if you divide the dataset and compute these measures on the subsets, you can aggregate them to compute the measure for the entire dataset) (max, min, sum, count)
- **Algebraic measure**: a non distributive measure, but that can be computed as a finite number of distributive measure (mean, variance, sd)
- **Holistic measure**: measure that can't be computed starting only with a finite number of partial statistics, you need to have the entire dataset (median, mode, percentile)

![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250928211323.png]]


##### Histogram
- **Histogram**: display *tabulated frequencies* as bar, it shows what proportion of cases fall into each of several categories
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260411172904.png|300]]
- in **Bar char** with non uniform interval it is important to consider the area of the bars, not the height 
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250928211557.png|300]]


##### Quantile plot
- **Quantile plot** display how much values are lower than a certain quantile
- It show us if the distribution is or not *linear* (by confronting it with a straight line)
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250928211822.png]]


##### Quantile-Quantile plot
- **Quantile-quantile** plot allow to confront 2 distribution against the corresponding quantiles
- it is useful to compare 2 data distribution
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250928212001.png]]


- **Scatterplot** compare pairs of features, it can be used to see correlation, so can help to find redundant attributes, but it is also useful to find *cluster of points* and *outlier*
- in the third example data *can't* be deduced to be linearly correlated
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250928212120.png|600]]



## Data Visualization
- **Data Visualization** allow to gain *insight* into an information space by mapping data onto graphical primitives, provide qualitative overview of large data sets, and allow to search patterns, trends, structure, irregularities, and relationship among data

- Main visualization techniques:
  - **Pixel-oriented visualization** techniques
  - **Geometric projection visualization** techniques
  - **Icon-based visualization** techniques
  - **Hierarchical visualization** techniques
  - **Visualizing complex data and relations**

##### Pixel-oriented visualization
- **Pixel oriented visualization**: for a dataset with *m* attributes, we create *m* windows on the screen (one for each attributes) the *m* attributes values of a record are mapped to *m* pixel at the corresponding positions in the screen
- the colors of pixel correspond to a certain value
- low value are white, high are black. In the example the first instance we have a low income, credit limit and transaction, but an high age
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250928213047.png]]
- We can se that the first two attributes are correlated, the third have a quadratic distribution (but not correlated) and age is not correlated at all
- Each instance is a square


##### Geometric Projection Visualization Techniques
- Main methods of **geometric projection**:
  - Scatterplot / Scatterplot matrices
  - Parallel coordinates 
  - Icon based
  - *Projection pursuit technique*: help users find meaningful projections of multidimensional data


- It is possible to create a matrix of scatterplot with attributes in row and column and their scatterplot in the intersection (along diagonal the correlation is equal to 1 so it is a straight line)
- This is useful to find correlation and so superfluous attributes
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250928213312.png|300]]


##### Parallel coordinates
- **Parallel coordinates** use *an axes for each attributes*, each line is the representation of one instance (they have usually different color based on the instance class)  
- The axes are scaled to the min-max range of that attribute
- Every instance corresponds to a polygonal line which intersects each of the axes at the point which corresponds to the value for the attribute
- If there are a broad attribute distribution in one axis (with an high dispersion), it is probably not relevant to class classification (e.g. third axis)
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250928215541.png|300]]


##### Icon-Based Visualization Techniques
- **Icon based visualization**: we use the feature of some icons (usually shape, color and small icons) to represented some information 

- Typical visualization:
	- **Chernoff Faces**: use all the element in the face icon to represent attributes, in this example there are 10 attributes ![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250928220219.png]]
	- **Stick Figure**: a stick is a simple type of drawing made of lines and dots, often in human or animal form, angle and length of sticks are used to represent attributes, also the position of the stick in the axis is mapped to two attributes ![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260411174502.png]]


- **Tile bar**: used to represent the *content of a document*, it encode length an topics
  - Columns in rectangles correspond to document segments
  - A square corresponds to a specific term set in a specific text segment
  - The darkness of a square indicates the frequency of terms in the segment from the corresponding *TermSet*.
- a variant is to account also the context where the term is used (e.g. mouse of a computer is different from the animal)
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250928220529.png|300]]



##### Hierarchical Visualization Techniques
- **Hierarchical Visualization Techniques**: visualize the data using a *hierarchical partitioning into subspaces*

- Main methods:
  - Dimensional Stacking
  - Tree Map
  - Cone Trees
  - InfoCube 


- **Dimensional Stacking**: is a visualization technique that partitions an n-dimensional attribute space into nested 2D subspaces. The data space is recursively divided by discretizing attribute values into classes, producing a hierarchical structure of stacked regions.
- More important attributes are mapped to the outer levels (e.g., defining the main rows and columns), while less important attributes further subdivide the space within each cell. 
- The technique is suitable for datasets with ordinal attributes of low cardinality. However, it becomes difficult to interpret beyond roughly nine dimensions.
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250928221120.png]]
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250928221309.png|500]]


- **Tree map**: are a screen-filling visualization technique for hierarchical data, based on a recursive partitioning of the display into nested regions. Each region represents a node, with area proportional to an attribute value.
- The screen is subdivided by alternately splitting the x- and y-dimensions according to attribute values (or classes), producing a space-efficient layout of rectangles.
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250928221405.png|300]]
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260411175317.png|400]]

- **InfoCube**: is a 3D visualization where hierarchical information is displayed as nested semi-transparent cubes, the outermost cubes correspond to the top level data, the subnodes or the lower data are represented as smaller cubes inside the outermost cubes
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250928221706.png]]


##### Visualizing Complex Data and Relations
- **Tag Cloud** (*Word Cloud*): represent the frequency of word in a text 
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250928221743.png|200]]



## Measure data similarity and dissimilarity
- Similarity and dissimilarity are important for unsupervised learning, usually they are express in a range from 0 to 1 for similarity and variable for dissimilarity
- **Proximity** refers to a similarity or dissimilarity

- **Data matrix**: represent $n$ instances with $p$ attributes (dimensions). It has a row for each instance and a column for each attribute
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250928222025.png|200]]

- **Dissimilarity matrix**: at the point $i,j$ is stored the dissimilarity between instance $i$ and instance $j$, is a triangular matrix $nxn$
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250928222102.png|200]]

##### Proximity measure for nominal attributes
- The simpler methods to do a *proximity measure for nominal attributes* is to compute the number of variables, minus the number of matches between variables, divided by the number of variables (*this give a dissimilarity metrics*)
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250928222822.png|300]]

- Another methods is to create a large number of binary attributes, one for each of the M nominal states of the original one, and then calculate the **contingency table** for binary data

Attribute conversion
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250930090912.png]]

Contingency table
We have object on column and row, $q$ is the number of attributes where we have value $1$ in object $i$ and $j$, $r$ the number of attributes where the value is $1$ in $i$ and $0$ in $j$
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250928223009.png|300]]

- **Distance measure for symmetrical binary attributes**: the number of attributes where we have *no matches* divided by the total number of attributes
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250930091236.png|316]]

- **Distance measure for asymmetrical binary attributes**: we balance the different importance of attributes, here non-zero value are much more important
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250928223141.png|300]]

- **Jaccard coefficient** (for asymmetric binary variables)
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250928223236.png|300]]

- The Jaccard coefficient is the same as coherence
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250928223315.png]]

- Example: we apply the formula only for asymmetric attributes
- The general formula is:
  $$(r + s) / (q+r+s)$$
- with:
  - r: i = 1, j = 0
  - s: i = 0, j = 1
  - q: i = 1, j = 1
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250928224452.png|500]]



### Standardizing Numeric Data
- **Z-score**: used to normalize data, subtract to the data its mean and divide by the standard deviation, this transform variables in the same range and made easier to compare them
$$z = \frac{x-\mu}{\sigma}$$
- in alternative is it possible to use the **mean absolute deviation** to be more robust to outlier than standard deviation
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250928224759.png]]


- Example of data matrix and dissimilarity matrix:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250928224535.png|500]]


##### Distance on Numeric Data: Minkowski Distance
- Given two objects ( i ) and ( j ) in a ( p )-dimensional space, the **Minkowski distance** of order ( h ) is defined as:
$$
d(i,j) = \left( \sum_{k=1}^{p} |x_{ik} - x_{jk}|^h \right)^{\frac{1}{h}}  
$$
- where ($i = (x_{i1}, x_{i2}, \dots, x_{ip})$) and ($j = (x_{j1}, x_{j2}, \dots, x_{jp})$) are two ($p$)-dimensional data objects, and ($h$) is the order of the norm (also referred to as the ($L_h$) norm).

- properties (a distance that satisfies these properties is a *metric*):
  - d(i, j) > 0 if i ≠ j, and d(i, i) = 0 (Positive definiteness)
  - d(i, j) = d(j, i) (Symmetry)
  - d(i, j) <= d(i, k) + d(k, j) (Triangle Inequality)
 

- special cases of Minkowski distance:
	- ($h = 1$): **Manhattan distance** (city block, ($L_1$) norm)
	- ($h = 2$): **Euclidean distance** (($L_2$) norm)
	- ($h \to \infty$): **Supremum distance** (($L_{\infty}$) or ( L_{\max} ) norm)


- Example of minkowski distance, *different norm returns different distance*, but with preserved relation:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250928224257.png|600]]


##### Ordinal Variables
- **Ordinal variables** are categorical variables with an order, can be discrete or continuous
- The order is important, there are $f$ value, we map each categorical variables with a number from $1$ to $f$, we then calculate the new value doing the new mapped $value - 1$, divided by $f - 1$
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250928225132.png]]
- Then we can use methods for *interval-scaled variables*


##### Attributes of Mixed Type
- If a dataset have **mixed type** attributes, we can do a *weighted* formula of more metrics 
- we count the number of attributes and based on the number we multiply the similarity measure by a certain **weight**


##### Cosine Similarity
- **Cosine Similarity**: used to compare data object with a *large number of attributes* (e.g. gene features, words frequency in a document). It is used to compare two vector of feature d1 and d2$$cos(d1,d2) = d1 \bullet d2 / ||d1|| * ||d2|| $$
 - so the *dot product* of the two vector, divided by the product of their lengths (norms)

 - Example of cosine similarity:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250928223503.png]]
- For data with a lot of documents, it is better than Euclidean distance because value are much **sparser** 




# 03 Data Preprocessing
## Data Preprocessing: An Overview
- Data Preprocessing is important for: accuracy, completeness, consistency, timeliness (timely update), believability (how trustable is that the data are correct), interpretability (how easily the data can be understood)

### Major Tasks in Data Preprocessing
- **Data cleaning**: fill missing value, eliminate noise, remove outlier, resolve inconsistencies

- **Data integration**: integration of data from multiple sources, database and files
- The same attribute could have different name in different file
- There could be inconsistency between different files
- After data integration it is usually needed to remove redundancy 

- *Is there a way to reduce the size of the data without worsen the data mining results?*
- **Dimensionality reduction**: made by applying a *data encoding scheme* to obtain a compressed representation of the original data, (e.g. compression techniques, attribute subset selection, attribute construction)
- **Numerosity reduction**: create a smaller representation using parametric models (regression model like PCA) or non-parametric models (cluster sampling)


- Some example of **Data transformation and data discretization** are:
    - **Normalization**: scale an attribute to a smaller range 
    - **Concept hierarchy generation**: replace raw values with higher-level concepts (e.g. replace age with {youth, adult}). It is possible to do data mining at different abstraction level

- The preprocessing pipeline consist of 4 major steps:
  1. Data cleaning
  2. Data integration
  3. Data reduction
  4. Data transformation and discretization 

![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20250929221458.png|500]]

 
## Data Cleaning
 - Raw real-world data is **Dirty**:
 - *Incomplete*: there are a lot of incorrect data, some attributes can be missing, incomplete or available only in aggregate form
 - *Noisy*: data can also contain noise, errors, or outlier
 - *Inconsistency*: data can be inconsistent (age does not match the birth date, or data are formatted in different way when they comes from different sources, e.g. some rating from 1 to 5, other from 1 to 10)
 - *Intentional error*: e.g. set the first of January as the birth day for all missing value (and we don't know if it's a valid data or a placeholder)

##### Handle missing data 
- Data is not always available, many attribute may not be recorded for equipment malfunction, inconsistency deletion, misunderstanding, not registered history

- How can we handle missing data?
	- **Ignore the tuple** when is missing the class label or a large percentage of attributes 
	- **Fill manually the missing value**: a very difficult and time consuming operation, sometimes even impossible
	- **Fill automatically with**:
	  - *a global constant*, e.g. "unknown"
	  - *the attribute mean* (most used solution)
	  - *the attribute mean of its class*
	  - *the most probable value*, usually inferred with a Bayesian model or a decision tree


- Other data problem which require data cleaning:
  - duplicate records 
  - incomplete data 
  - inconsistent data


##### Noisy Data
- **Noise**: random error or variance in a measured variable, it can be caused by many factor, it can be seen as *quick, random jumps up and down that don’t reflect the real signal*

- **Smoothing**: is a technique used to reduce noise by averaging each data point based on its neighbors:
  - If one point is **much higher** than the ones around it, smoothing lowers it.
  - If one point is **much lower** than the ones around it, smoothing raises it.
  - The result is a **smoother curve** that better represents the real signal.


##### Rectangular or unweighted sliding-average smooth
- **Rectangular or unweighted sliding-average smooth**: is the simplest smoothing algorithm, it replace every point with the average of the *m* adjacent points, where m is a positive integer called the *smooth width*
- e.g. for m=3:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251004155658.png]]


- The first and last point are often skipped because they don’t have neighbors on both sides

- An higher $m$ will give a smoother result, but too large $m$ may remove real details
- When we reduce the noise we have to be careful not to reduce the information given by the data
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251004155729.png]]

- if the function is *constant* or is *changing linearly* with time (increasing or decreasing) then *no bias* is introduced into the result
- if the function has a *nonzero second derivative* (e.g. a local maximum) the smoothing reduce the function value, so *a bias is introduced*


##### Triangular smooth
- **Triangular smooth**: implements a *weighted* smoothing function
- e.g. for m=5:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251004160402.png]]
- This smooth is more effective at reducing *high frequency noise* than the rectangular smooth (the 5 point triangular smooth is equivalent of two passes of a 3 point rectangular smooth)
- The *width of the smooth* $m$ is an odd integer, and the *smooth coefficient* are symmetrically balanced around central point which preserves the x-axis position of peaks and other features in the signal

##### The Savitzky-Golay Smoothing Filters
- A classic simple sliding average smooths noise, but also flattens important features like sharp peaks, edges or curvatures because it assume that the true signal is *constant* within the smoothing window

- **The Savitzky-Golay Smoothing Filters** assume that the true signal can be approximated by a *polynomial* within that window of higher order (typically quadratic or quartic)
- For each point $Y_i$ you look at a window of points around it $(Yi−nL​​,…,Yi​,…,Yi+nR​​)$
- and then you **fit a polynomial of those points using a least squares**, then you replace $Yi$ with the value of the polynomial ($S_i$) at position $i$

- This method preserves shape, keeps height, width and position of peaks and valleys much more accurately
- the filter respect the slope and curvature of the data, but it cancel the random fluctuation

- fitting a least-squares polynomial for each point can require a lot of computation power, but it is possible to precompute a set of **filter coefficients** $c_n$ *once*
- the coefficients of a fitted polynomial are themselves linear in the values of the data
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251004171420.png]]
- where:
  - $nL$ is the number of points used to the left 
  - $nR$ is the number of point used to the right

- Then the smoothing process reduces to applying those coefficients to the data points in the windows

- Example:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251004171758.png]]
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251004171834.png]]


##### Smoothing Algorithms
- The larger the smooth width, the greatest the noise reduction, but also the greatest the possibility that the signal will be distorted by the smoothing operation
- The optimal smooth width depends upon the width and shape of the signal and the digitization interval

- For **peak type signal** the critical factor is the **smoothing ratio**, the ration between the smooth width and the number of points in the half-width of peak
- An increased smoothing ration improve the signal to noise ratio, but causes a reduction in amplitude of the peak
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251004172355.png]]

- usually if you want to keep the true peak height and width you need to have a smooth ratios below 0.2
- if the objective is to measure the *peak position* you can use larger ratio because it has no effects on the x-axis position


- Why smooth a signal:
  - *cosmetic reason*: it is more good looking for publication and presentations
  - *reduce influence of noise in algorithms*

- Why not smooth a signal:
  - smoothing will not significantly improve the accuracy of parameter measurement by least-squares measurement between separate independent signal sample
  - all smoothing algorithm are *lossy*, some info will be lost
  - it is harder to evaluate the fit by inspecting the residuals if the data are smoothed, because smoothed noise can be mistaken for an actual signal
  - smoothing the signal will seriously **underestimate the parameters errors** predicted by *propagation of error calculation* and the *bootstrap method* 
  - smoothing make difficult to find the outlier 


### How to Handle Noisy Data
- **Binning**: sort data and divide it in partition of equal frequency called *bins*, then we can apply various techniques like putting the mean value of the bin in each element of the bin or using the boundaries value
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251004175041.png]]

- **Regression**: it is possible to smooth the data by fitting the data in a *regression function* (it can be a linear or a multiple linear regression)

- **Clustering**: can be used to remove outliers
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251004175304.png]]

- **Combine computer and human inspection**: the computer detect suspicious values and them are checked by a human




## Data Integration
- **Data integration**: combines data from multiple sources into a coherent store, comprehend *schema integration* and *metadata integration*


- **Entity identification problem**: identify real word entities from multiple data sources (identify entity that are the same thing with different name)
- **Detecting and resolving data value conflicts**: for the same real word entity, attributes value from different sources may be different (possible reasons: different scale or representation)

### Handling Redundancy in Data Integration
- *Redundant data* occur often when integration of multiple databases

- **Object identification**: the same attribute or object may have different names in different databases
- **Derivable data**: one attribute may be a derived attribute in another table

- Redundant attributes can be detected with correlation analysis and covariance analysis
- A careful data integration from multiple sources can help to avoid or reduce redundancies and inconsistencies and improve mining speed and quality

##### Correlation analysis of nominal data
- $X^2$ **chi-square test**: is a procedure for testing if two *categorical* attributes A and B are related
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251004180552.png]]

- **Contingency table**:
  - on the rows there are the category of one variable
  - on the columns there are the category of another variable
  - the cells contains the frequencies of the observations that belongs simultaneously to that two category



- in the che-square test we assume that the *variables are independent*
- more *high* is the value, the more there is *correlation* an so the attributes are redundant
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251004180832.png]]

- the cells that contribute the most are those whose observed count is very different from the observed count
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251004181009.png]]

- example:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251004181035.png]]


### How can we determine independence?
 - **Parametric test**: hypothesis based on the assumption that observed data are *distributed according to some distributions of well-known form* (normal, Bernoulli, etc.) with an unknown parameter that we have to infere (e.g. mean, variance), e.g. t-test, ANOVA, z-test
 - **Nonparametric test**: hypothesis who don't make any assumption on the parametric form of the distribution

- choose the test to determine independence:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251004183353.png]]

- **Null hypothesis**(*H0*): hypothesis that says that there are no association between two cross-tabulated variables in the population and therefore the variables are independent
- **Alternative hypothesis**(*H1*): proposes that the two variables are related in the population

- *correlation does not imply causality*

- **Degrees of freedom**: the number of independent values that can vary in an analysis, given certain constraint. in this case is the number of cells in the two-way table of the *categorical* variable that can vary, it is equal to (number of row - 1) * (number of column - 1), because the totals are fixed, so not all cell frequencies can vary
- its the number of cell that can vary given the total (one row and column cannot vary because there are the others and the total)
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251004185926.png]]



### How can we determine independence
 - the $X^2$ distribution is a type of probability distribution, probability distribution provide the probability of every possible value that may occur
 - *cumulative probability distribution*: give the probability that a random variable is less than or equal to a particular value, to find that probability we need to find the area under the curve before the value, the area that's after the value is called p-value
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251004191008.png]]

- the $X^2$ distribution vary depending on the degrees of freedom, and are **asymmetric**, with a skewed right shape
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251004191056.png]]

- Many statistical analyses involve the use of the p-value, but it's more efficient to use the $X^2$ **table** than calculate the area under the curve
- In this table each row represent a different degree of freedom, and column represent different p-value (significancy level, is th level of confidence that we can to have in our decision)
- The more the p-value is high, the more the probability to reject our hypothesis 
- The null hypothesis is rejected when the probability of a larger value of $X^2$ is lower than the significance level $\alpha$
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251004191824.png]]
- we compute the degree of freedom, we decide the significancy level, we obtain the value from the table, we compare it with our computed chi square, if our chi-value are higher than the table value we decide that the variables are statistically correlated


### Correlation Analysis (Numeric Data)
- **Correlation coefficient** (also called *Pearson's product moment coefficient*): measure the correlation between 2 numeric variables A and B, and is computed as:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251004192103.png]]
where:
- n is the number of tuples
- $A^-$ and $B^-$ are the means of A and B
- $\sigma A ,\ \sigma B$ are the standard deviation of A and B
- and $\sum(aibi)$ is the sum of the AB cross product

- if the variable have the same trend, the difference between value and mean multiplied will give a positive value, if they are not correlated, it will give a small number, in they are negatively correlated when one increase the other decrease, so when one have a positive difference with the mean the other one have a positive one, and multiplied it gives a negative  number



- If $r_{A,B}$ is greater than zero, A and B are positively correlated, if is less than zero, they are negatively correlated, (the higher the value, the stronger the correlation), and if is equal to zero they are independent 

- the **Pearson's product momentum** only detect *linear relationships*
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251004192556.png]]

- **Correlation** measures the *linear relationship* between objects, to compute correlation we standardize data objects A and B and then take their dot product
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251004193624.png]]

- **covariance is similar to correlation**
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251004193644.png]]
where:
- $n$ is the number of tuples
- $A^-$ and $B^-$ are the means of A and B
- $\sigma A \ \sigma B$ are the standard deviation of A and B


- cov = 0 doesn't mean that they are independent, but independence imply a cov = 0
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251005104727.png]]

- compute covariance:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251005104802.png]]



## Data Reduction
 - **Data reduction**: obtain a reduced representation of the dataset that is smaller in volume, but produces the dame analytical results
 - It allow to use less space and computational power

- *Data Reduction Strategies*:
  - **Dimensionality reduction**: remove unimportant attributes
    - Wavelet transform
    - Principal component analysis (PCA)
    - Feature subset selection (and feature creation)
  - **Numerosity reduction**: reduce some tuple
    - Regression and log linear models
    - Histograms, clustering, sampling
    - Data cube aggregation
  - **Data compression**

### Dimensionality reduction
- Curse of dimensionality: when dimensionality increases, data becomes increasingly sparse
- Density and distance between points (critical in clustering), outlier analysis, becomes less meaningful
- The possible combination of subspaces will grow exponentially

- **Dimensionality reduction**: help to eliminate the curse of dimensionality, help eliminate irrelevant feature and reduce noise, reduce time and space required in data mining, allow easier visualization

- **Dimensionality reduction techniques**:
   - Wavelet transform
   - PCA
   - supervised and nonlinear techniques (e.g. feature selection)

##### Principal Component Analysis
- *Project* the data onto a smaller space, resulting in dimensionality reduction, we find the eigenvector of the covariance matrix, and these eigenvector define a new space
- The idea so is to find new dimension that divide better the objects and use less dimension to contrast the curse of dimensionality

- The *Projection error* is less than in the original dataset
- The new projected points are more widely spread out than in the original dataset (they have more variance)
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251005110339.png]]

##### PCA Steps
- Given $N$ data vector from $f$ dimensions, find a $k$ less or equal to $f$, *orthogonal vectors* (the principal components) that can be used to represent data
- First of all we need to **normalize input data**, each attribute have to fall in the same range
- Then **compute k orthonormal** unit vectors (the principale component)
- **Each input data (vector) is a linear combination** of the k principal components vector
- The k principal components are sorted in order of *decreasing significance* or strength
- Since the components are sorted, the size of the data can by reduced by **eliminate the weak components** (e.g. those with low variance)

- PCA can be used only with numeric data

- Normalize the data
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251005110909.png]]

- Calculate the covariance data, it is just needed to multiply the adjusted matrix by its transpose and divide by n-1
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251005110944.png]]

- example of computation of the covariance matrix:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251005111019.png]]

- You calculate the eigenvectors of the covariance matrix, and discard those who have very small values because they denote attribute with very low variability, so overlapping point in that direction that doesn't give much information for divide the points in different groups or classes
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251005111306.png]]
- If some eigenvalues are 0 or very small, we can essentially discard those eigenvalues and the corresponding eigenvectors, hence reducing the dimensionality of the new basis.

- Finally you transform the original data in to the new dimension by multiplying the transposed matrix of eigenvectors and multiply it by the original matrix, it is also possible to obtain the original data from the transformed ones, F will have a subset of the selected features
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251005111349.png]]


- This dimensionality reduction is performed in the transformed spaces, not in the original space, it is a unsupervised method, so we can apply this method for classification, but also for clustering problem
- We can have a very good dimensionality reduction, but we can't connect original features with transformed feature, and this can be a problem sometimes 


### Attribute Subset Selection
- **Redundant attributes**: Duplicate much or all the information contained in one or more other attributes (e.g. price and taxes paid)
- **Irrelevant attributes**: contain non useful information (e.g. id)

- We can select the attributes with a **forward selection**, a **backward elimination** or a **decision tree induction** (not a really attribute selection approach, but it select attributes inside him)
- To select the best or to eliminate the worse we need to define a metric to determine what are the best or worst attributes

- **Pure dataset**: the attributes completely divide the classes

- We need to select the feature that best divide the classes, but we don't want to select duplicates attributes, so we have to consider the already selected features, so we can't consider just the mutually information between the feature and the output

##### Heuristic Search in Attribute Selection
- There are $2^d$ *possible attribute combinations* of $d$ attributes
- **Greedy approaches**: make what looks like the best choice at the moment
- **Heuristic** attribute selection methods:
  - *Best single attribute*: choose the attributes using the significance test (under the assumption of attribute independence)
  - *Best step-wise feature selection*: choose the best single-attribute first, then choose the next best attribute conditioned with the first
  - *Step-wise attribute elimination*: eliminate repeatedly the worst attribute
  - *Best combined attribute selection and elimination*
  - *Optimal branch and bound*: use attribute elimination and backtracking

- Example of Heuristic Approach (**mutual information**): for each value x assumable by X in XX, and for each value y assumable by Y in YY, we sum the conjunct probability of x,y by the logarithm of the conjunct probability of x,y divided by probability of x by probability of y
- it has value zero when x and y are independent because the logarithm of 1 is zero
- we will have high value when x and y are correlated
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251005113237.png]]
 - quindi si hanno 2 variabili discrete X e Y che possono assumere valori dai set di valori XX e YY, conosciamo le loro probabilita' marginali p(x) e p(y) che sono le probabilita' che X assuma un certo valore e la probabilita' che Y assumi un certo valore, inoltre si conoscono le probabilita' marginali p(x,y), cioe' la probabilita' che X e Y assumano contemporaneamente una coppia di valori x e y

L’**informazione mutua** I(X,Y) è una misura di *quanto sapere il valore di X ci dice sul valore di Y (e viceversa)*

- Se X e Y sono **indipendenti** → sapere X non dice nulla su Y
  In questo caso p(x,y)=p(x)⋅p(y), e il log diventa zero → I(X,Y)=0
- Se X e Y sono **molto collegati** → conoscere uno riduce molto l’incertezza sull’altro →I(X,Y) è grande.

- We want to encode a sequence of symbols from the set {a,c,g,e} drawn randomly according to the following probability distribution D:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251005114044.png]]

- since there are 4 symbols, one possibility is to use 2 bits per symbol
- but there's a way to use only 1.75 bits
- if a message is very likely to be sent we should give it a short code, if the message is very unlikely we should give it a longer code
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251005114840.png]]
- **Information theory**: optimal length code assign $log2(1/p) = - log2(p)$ bits to a message having probability p, this give us the optimal bits

- the worst case is if the symbol have all the same probability

- **Entropy**(*H(D)*):  is a measure of the **average amount of information (in bits)** you get when drawing from a probability distribution D
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251005115012.png]]
- the more an outcome is likely, the more the information will be lower, when we have equally likely information (uniform distribution), then uncertainty is highest, and entropy is maximized




##### Example 2
- **MI** has two main properties:
  - measuring any kind of relationship between variables
  - its invariance under space transformation (translation, rotation, and any transformation that preserve the order of the original elements of the variables)
- feature selection based on MI are extremely sensitive to the estimation of the *pdfs* 

 - we are working directly with the original feature of the signal, it is better to extract as much feature as possible and then filter them

- **Problem**: given an initial set F with n feature, find a subset S of k feature that maximizes the *MI* I(C,S) between the class variable C and the subset of selected feature S

- compute the normalized MI:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251005143148.png]]


 - The normalization compensates for the MI bias toward multivalued features, and restricts its values to the range [0,1]
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251005143357.png]]


- the selection criterion used in NMIFS consists in selecting the feature that maximizes the measure G
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251005143237.png]]

- Adaptive redundancy penalization term, which corresponds to the average normalized MI between the candidate feature and the set of selected features
- this formula take in consideration the relevance of the feature, but it also consider the **redundancy** of the feature with the feature that we have already selected
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251005143442.png]]

- MI algorithm:
  1) initialize the set F with the original N feature and the set S that is initially empty
  2) Calculate the MI with respect to each classes, and calculate I(fi, C) for all the f in F
  3) Select the first feature, remove it from F and add it to S (with the highest mutual information with the output)
  4) Greedy selection: calculate the MI between features for all pairs, select the next feature that maximize **G** (so taking in account *feature redundancy*) and repeat until S has k element
  5) output the set S with the k element


- the heuristic approach is a supervised methods, it works on the original space (it select the original feature), we need to determine the best number of feature to select (we can test different value of k iteratively)
- it use both relevance of the feature and the redundancy of the feature


### Attribute Creation (Feature Generation)
- **Attribute Creation**: create new features that can capture the important information in a data set more effectively than the original ones
- Main methodology:
  - *Attribute extraction*: usually domain specific
  - *Mapping data to new space*: (data reduction)
  - *Attribute construction*: Combining features and data discretization


### Data reduction 2: Numerosity Reduction
- reduce data volume by choosing alternative smaller forms of data representation

- **Parametric methods**: assume the data fits some model, estimate the model parameters, store the parameters and discard the data except possible outliers (e.g. create a regression model and save only its parameter)
- **Non-parametric methods**: do not assume models, it is divided in:
  - histograms
  - clustering
  - sampling


##### Parametric data reduction
- **Linear Regression**: data are modeled to fit a straight line, it uses the *least-square* method to fit the line
- **Multiple Regression**: allow a response variable Y to be modeled as a linear function of multidimensional feature vector


- **Regression Analysis**: techniques for modeling and analyze numerical data consisting of value of a *dependent variable* (also called response variable or measurement) and one or more *independent variables* (also called explanatory variables or predictors)
- The parameters are estimated so as to give a **best fit** of the data, usually the best fit is evaluated using the least squares method

- *Linear Regression*: $y = w1x + w0$
- There are 2 regression coefficient w1 and w0 that have to be estimated
compute w1 and w0: ![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251005150336.png]]

- Example:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251005150408.png]]

![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251005150511.png]]

![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251005150503.png]]

- computation of w1: $w1 = 470/730 = 0.644$
- computation of w0: $0 = 77 - 0.644 ·78 = 26.768$
- linear regression equation:  $y = 0.644x + 26.768$

- multiple linear regression: $y= w0 + w1x1 + w2x2$
formula: $$W = (X^T X)^{-1} X^T Y$$


##### Non-linear Regression Analysis
- Polynomial regression: $y = w0 + w1x + w2x^2 + w3x^3$ 
- We can transform a polynomial equation in a linear equation by transforming x1 = x, x2 = x^2, x3 = x^3, the equation becomes: $y= w0 + w1x1 + w2x2 + w3x3$ and can be solved with methods for multiple regression analysis


### Histogram Analysis (non-parametric method)
 - Divide data into buckets and store average (sum) for each bucket
 - The bucket can be divided with:
   - equal width (range), same range for each bucket
   - equal frequency (depth), same number of instances for each bucket
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251005151245.png]]
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251005151253.png]]

### Clustering
- Partition data into cluster based on similarity and store only cluster representation (for instance the cluster centroid and diameter)
- can be ineffective if data are sparse
- it is possible to have a hierarchical clustering and store the data in a multi-dimensional index tree structures
 - it is possible to use many clustering definition and algorithms 

### Sampling
- **Sampling**: obtaining a small sample *s* to represent the whole dataset *N*
- key principle: choose a representative subset of the data
  - simple and random sampling have poor performance if data are asymmetrical (skew)
  - develop adaptive sampling methods (e.g. stratified sampling)

- sample may not reduce database i/o (e.g. page for second)

- Types of Sampling:
  - **Simple random sampling**: there is an equal probability of selecting any particular item
  - **Sampling without replacement**: once an object is selected, it is removed from the population
  - **Sampling with replacement**: a selected object is not removed from the population
  - **Stratified sampling**: *partition the data set* and draw samples proportionally from each partition (useful for skewed or asymmetrical data)
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251005152542.png]]
- in sample with replacement if you extract a large number of sample you will have the same distribution, in the sample without you perturbate the distribution of the data and you change the possibility of extract a certain class each time

- when we sample with replacement the two sample values are independent (what we get on the first doesn't affect what we get on the second), and the covariance is zero
- in sampling without replacement, the two extracted values aren't independent, and the covariance is equal to:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251005152512.png]]


### Data Cube Aggregation
- The lowest level of a data cube **base cuboid**
- **Multiple levels of aggregation in data cubes**: further reduce the size of data to deal with
- **Reference appropriate levels**: use the smallest representation which is enough to solve the task
- Queries regarding aggregated information should be answered using data cube
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251005152958.png]]

### Data Reduction 3: Data Compression
 - **String compression**: there's a lot of algorithms, typically lossless 
 - **Audio/video compression**: typically lossy
 - **Time sequence compression**: slow and short
 - Dimensionality and numerosity reduction can also considered a forms of data compression

![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251005153023.png]]




## Data Transformation
- **Data Transformation**: a function that maps the entire set of values of a given attribute to a new set of replacement values, such that each old value can be identified with one of the new values 

- **Methods**:
  - *Smoothing*: remove noise from data
  - *Attribute/feature construction*: new attributes constructed from the given ones
  - *Aggregation*: summarization, data cube construction
  - *Normalization*: scale attribute to make data fall into a smaller specified range (e.g. min-max normalization, z-score normalization, **decimal scaling**)
  - *Discretization*: concept hierarchy climbing

- min-max is more sensitive to outlier than z-score
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251005153919.png]]


- In the normalization by decimal scaling we divide the values by the smallest power of ten that is bigger than the max of the absolute values assumed by v
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251005153955.png]]

## Data Discretization
- **Discretization**: divide the range of a continuous attribute into interval
- interval labels can be used to replace actual data values
- reduce data size by discretization
- can be supervised or unsupervised
- can by done by *split* (top-down) or by *merge* (bottom-up)
- can be recursive
- discretization prepare data for subsequent phases like visualization and analysis

- Data Discretization Methods (that can be applied recursively):
  - ***Binning***: top-down split, unsupervised
  - **Histogram analysis**: top-down split, unsupervised
  - **Clustering analysis**: top-down split (or bottom up), unsupervised
  - **Decision-tree analysis**: top-down split, supervised 
  - **Correlation analysis**: bottom-up, supervised


### Simple Discretization: Binning
- **Equal-width (distance) partitioning**:
  - Divides the range into N intervals of equal size
  - if A and B are the lowest and highest values of the attribute, the width of intervals will be $W = (B-A)/N$
  - don't handle well *skewed data*

- **Equal depth (frequency) partitioning**:
  - Divides the range into N intervals, each containing approximately the same number of samples

- example:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251005155545.png]]

### Discretization by Classification & Correlation Analysis
- Classification (e.g., decision tree analysis)
    - Supervised: Given class labels, e.g., cancerous vs. benign
    - Using entropy to determine split point (discretization point)
    - Top-down, recursive split

- Correlation analysis (e.g., Chi-merge: χ2-based discretization)
    - Supervised: use class information
    - Bottom-up merge: find the best neighboring intervals (those having similar distributions of classes, i.e., low χ2 values) to merge
    - Merge performed recursively, until a predefined stopping condition


##### ChiMere Discretization
- Applies the *Chi Square method* to determine the probability of similarity of data between two intervals, with f=feature, k=class

- Sort and order the attributes that  you want to group (in this example attribute F) 
- start by having every unique value in the attribute be in its own interval
- independence: change in the value of the feature, same label for the class
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251005154507.png]]

- Begin calculating the Chi Square test on every interval
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251005154515.png]]



![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251005154536.png]]

- Calculate all the Chi square value for all intervals, and merge the intervals with the smallest chi values
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251005154556.png]]


- Repeat
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251005154603.png]]



![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251005154613.png]]



![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251005154623.png]]



- Until there are no more intervals that can satisfy the Chi square test
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251005154631.png]]


### Concept Hierarchy Generation
- **Concept Hierarchy** organizes concept (e.g. attribute values) hierarchically and is usually associated with each dimension in a data warehouse
- facilitate *drilling and rolling* in a data warehouse
- **Concept hierarchy formation**: recursively reduce the data by collecting and replacing low level concepts by high level concept (e.g. replace the numeric attribute age with {young, adult, old})

- Concept hierarchy can be explicitly specified by domain experts and or data warehouse designers
- Concept hierarchy can by automatically formed for both numeric and nominal data. For numeric data use discretization methods shown


##### Concept Hierarchy Generation for Nominal Data
- Specification of a partial/total ordering of attributes explicitly at the schema level by expert (e.g. city < state < country)
- Specification of a hierarchy for a set of values by explicit data grouping {Urbana, Champaign, Chicago} < Illinois
- Specification of only a partial set of attributes  (e.g. city < state, country not considered)
- **Automatic generation of hierarchies** by the analysis of the number of distinct values (e.g. for the set of attributes city, state, country). The attribute with the most distinct values is placed at the lowest level of the hierarchy
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251005160953.png]]



# 04 CLASSIFICATION 
## Classification: Basic Concepts

- **Classification**: predict a categorical class label (can be a discrete number of nominal), and classifies data based on the training set and class label, by the construction of a model that will classify new data using the values of their attributes
- **Numeric Prediction**: models continuous-valued functions to predicts unknown or missing values



- Classification is a *Two step process*
- The first step (training phase) is the **Model construction** (learning step or training phase), a classifier is built describing a set of predetermined classes or concepts by exploiting a set of tuples or samples.
- A tuple is a n-dimensional attribute vector (or feature vector) *X*
- Each tuple is assumed to belong to a predefined class as determined by the class label attribute
- The set of tuples used to construct the model is called *training set*

- The **Second Step** is the *Model Usage*, so classifying future or unknown object and *estimate the accuracy of the model* 
- **Accuracy rate**: the percentage of test sample correctly classified by the model (isn't a good metrics if classes are not balanced)
- The *Test set* must be independent from training set 

- Model construction of a **rule based model**:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251010152821.png]]

- Model Usage: 
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251010152845.png]]

- Rule based models are fast and require less data and memory


## Preparing Data for Classification
- **Data Cleaning**: preprocessing of data for remove or reduce noise and missing value
- **Relevance Analysis**: remove irrelevant attributes by exploiting a correlation analysis

- **Normalization**: scaling the values of a given attribute so that they fall within a small specified range
- **Reduction**: generalize attributes value into *higher level concepts* (e.g. wavelet transform, PCA, discretization techniques, clustering and histogram analysis)

- **Discretization**: transform continuous attributes in discrete ones
- some learning algorithms are applicable only to categorical attributes
- performing a discretization on a big amount of data can be computationally expensive

 * **The Fayyad and Irani approach** (1992): is a *discretization technique* which objective is to find an **optimal partition** (optimal for the classification problem) for each continuous-valued attribute A, Partitions are determined by a set of cut points
 * for the authors the optimal cut points for the metrics used, always lie *between two examples* of different classes in the sequence of sorted values of attribute A
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251012130723.png]]
- to be more precise: the **potential cut point T** is a *boundary point b*, if and only if, in the sequence of examples sorted by the value A, there exist two example e1 and e2, having different classes, such that the attribute A of e1 is less than T, and the attribute A of e2 is greater than T, and there exists no other example e', such that, the attribute A of e1 is less than the attribute A of e', and the attribute A of e2 is greater than the attribute A of e'
- Let us assume that *b* is the midpoint value between A(e1) and A(e2), then *$B_A$* is the set of all candidate points for attribute A
- the algorithm exploits the *entropy as quality measure*, so it analyze if we have pure or not pure partitions 

- Let *S* be the set of examples, let there be *k* classes *{C1, ...Ck}*, Let *P(Ci, S)* be the proportion of examples in S that have the class Ci, the **class entropy of a subset S** is defined as:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251012131354.png]]
- minus the sum of the probability of having the class Ci in S, by the logarithm of that probability
- when we have only one class the entropy is equal to zero, we can search the points that bring the entropy to zero for isolate class

- Let *T* be a cut point in *$B_A$*. Set *S* is partitioned in the subsets *S1* and *S2*, where S1 contains the subset of examples in S with the A-values not exceeding T, and S2 = S - S1, so S2 have the sample in S that exceed the value T

- the **Class information entropy** of the partition induced by T, is denoted as **EP(A,T;S)** and is defined as: the entropy of S1 by the cardinality of S1 divided by the number of samples, plus the entropy of S2 by the cardinality of S2 divided by the number of samples
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251012132243.png]]

- The cut point *TA* for with the *class information entropy* is **minimal** amongst all the candidate cut points is taken as the best cut point
- because it is likely that the two subset S1 and S2 are close to be pure
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251012132253.png]]

- after finding the first partition S in S1 and S2, the algorithm is executed again with S=S1 and S=S2, until the *stopping condition* is met
- The **Stopping condition** is defined as: 
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251012132530.png]]
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260414092630.png]]
- so we don't have to set parameters for this algorithm 
- this is a **supervised** approach that exploits a lot the classes



## Comparing Classification Methods
- **Metrics** to compare classification methods:
  - *Accuracy* (in predicting the class label)
  - *Speed* (we have to consider speed in inference and training)
  - *Robustness* (for noise and missing value)
  - *Scalability* (efficiency in disk-resident database)
  - *Interpretability* (understanding the insight provided by the model)
  - *Other measures* (e.g. goodness of rules or compactness of classification rules)

## Decision Tree Induction
 - *Decision tree induction*: learning of decision trees from class labeled training tuples
 - **Decision tree**: is a tree structure where each *internal node* denotes a test on an attribute value, each *branch* represents an outcome of the test, and each *leaf node* holds a class label

- Decision Tree are popular because:
  - you don't need domain knowledge, so you don't need experts 
  - they can manage high-dimensional data
  - their representation is intuitive and easy to assimilate

- example of *multi way decision tree* (each node can have more than 2 children), binary decision tree have only 2 children for node 
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251012133620.png]]


- Their basic algorithm is based on a *greedy approach*, so it makes the locally optimal choice at each stage with the hope of finding the global optimum
- The tree is constructed in a *top-down, recursive, divide and conquer* manner
- at start all the training samples are at the root
- **Attributes are all categorical** (continuous ones are discretized in advance)
- examples are partitioned recursively based on selected attributes
- test attributes are selected on the bases of heuristic or statistical measure (e.g. information gain)

- Condition for **Stopping partitioning**:
  - all samples for a given node belong to the *same class*
  - there are *no remaining attributes*, majority voting is employed for classifying the leaf
  - there are *no samples left*

- The objective is to create a partition **as pure as possible**, a partition is *pure* if all the tuples in it belong to the same class

### Attribute Selection Measure: Information Gain
- Let *D* be a training set of class-labeled tuples. suppose that the class label has *m* distinct value {C1, ...Cm}
- we select the attribute with the **highest information gain**
- let $p_i$ be the probability that an arbitrary tuple in D belongs to class Ci, estimated by the number of tuples with class Ci divided by the number of total tuple $p_i = \frac{|C_i|}{|D|}$ 
- **Expected information** (**entropy**) needed to classify a tuple in D: 
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251012135038.png]]
- The more the entropy is closer to zero, the more is pure


- when the probability of each classes is equal to 0.5 we have the highest value of entropy, so a lot of confusion and uncertainty 
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251012135117.png]]

- suppose that we split the training set D in *v partitions* {D1, ...Dv} on some attribute A having *v* distinct values *{a1, ...av}* 
- The information needed after using A to split D into c partition to classify D, is equal to:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251012135432.png]]
- we compute for each subset the entropy, multiply it by the cardinality of the partition Dj and divide by the total observation in D
- the worst case is that we aren't able to isolate pure partition
- we need to normalize to the partition dimension, to consider the dimension of the isolated set

- we can test all the attributes and select the attribute with the highest gain
- and the **information gained by branching on attribute A** is equal to the *expected information* minus the *information needed for A*:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251012135503.png]]

### Information Gain example
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260414094616.png]]
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260414094623.png]]


### Computing Information-Gain for Continuous-Valued Attributes 
- Let attribute A be a **continuos-valued** attribute
- we must determine the best split point for A:
  - sort the value A in increasing order
  - all the midpoint between each pair of adjacent values ($(ai+a(i+1))/2$) is considered as a possible split point
  - we test all possible midpoint
  - the point with the **minimum expected information requirement** for A is selected as the split point for A
- this is a good solution for really small dataset, so it's not so used 

- **Split**: D1 is the set of tuples in D that satisfying A <= split-point, and D2 is the set of tuples id D satisfying A > split-point 
- an alternative is to *discretize before applying the decision tree learning*


### Gain ratio for attribute selection
- **Information gain** measure is biased towards attribute with a *large number of values*, (e.g. unique identifier) the measure **C4.5** (a successor of **ID3**) uses *gain ratio* to overcome the problem

- Adopts a normalization to information gain using a **split information**
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251012143702.png]]
- The value represents the potential information generated by splitting the training data set D, into v partitions corresponding to the v outcomes of a test on attribute A
- v are the number of possible value of the analyzed attribute

- The value of the **Gain ratio** is equal to the gain on attribute A, divided by the split information on attribute A
- it consider the number of subset in which an attribute is divided
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251012143859.png]]
- each time you select not the attribute with the maximum gain, but the attribute with the maximum gain ratio as the *splitting attribute*

- **NOTE**: previous metrics are used for binary decision tree


### Gini Index (CART, IBM, IntelligentMiner)
- **Gini index**: is equal to one minus the sum of the *class relative frequency squared* (so the number of tuples in a class i divided by the number of sample in the training set)
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251012144233.png]]
 - the Gini index *considers a binary split for each attribute*
 - if A is a discrete variable with v values {a1, ...av}, **all possible subsets** that can be formed from A are examined to determine the optimal binary split
 - For example, considering three possible values {low, medium, high}, the possible subsets are: {low, medium}, {low, high}, {medium, high}, {low}, {medium} {high}

- comparison of metrics for a *2 class* problem: Gini have the same distribution, but lower value
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251012144453.png]]


 - if a dataset D is split on A into two subset D1 and D2, the **Gini index for A in D** is defined as: the weighted sum of the gini index of the subsets
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251012144716.png]]
- for discrete attribute each of the possible binary splits is considered
- for continuous attribute, each possible split-point is  considered

- **Reduction in Impurity** metrics: 
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251012144840.png]]
- the attribute that maximize the *reduction in impurity* is the one that has the minimum *Gini index*, and is selected as splitting attribute

##### Gini index computation Example
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251012145038.png]]
- The *Gini values for split* on the remain subset are:
  - Gini{low, high} = Gini{medium} 0.458
  - Gini{medium, high} = Gini{low} = 0.450. 

- we choose the value **Gini{low, medium} / Gini{high}** since it has the lowest Gini index

### Comparing Attribute Selection Measures
- The main attribute selection measures are:
  - **Information Gain**
  - **Gain Ratio**
  - **Gini Index**

- Information Gain is *biased towards multivalued attributes*

- Gain ratio *tends to prefer unbalanced splits in which one partition is much smaller than the others*

- Gini index:
  - is biased to multivalued attributes
  - has problem with a large class number
  - tends to prefer equal-sized partitions


### Decision Tree Scheme
- The algorithm take in input **D**, a set of training tuples with their associated class label, an attribute list, and a method to determine the best splitting methods (can contains a splitting attributes, a split-point and a splitting subset), in the end it return a decision tree

- **Algorithm**:
~~~ python
Create_a_Node_N()

if the tuples in D are all of the same class C, then:
   return N (as a leaf node labeled with the class C) 
  
if attribute list is empty:
   return N (as the leaf node labeled with the majority class in D)
   
apply Attribute_selection_method(D, attribute_list) to find the best splitting_criterion

label node N with splitting_criterion

# Create a NON RESTRICTED binary trees
if (splitting_attribute is discrete) and (multiway_splits is allowed):
   attribute_list = attribute_list - splitting_attribute

for each outcome j in splitting_criterion:
   let Dj be the set of data tuples in D that satisfy outcome j
   if Dj == null:
      attach a leaf labeeld with the majority class in D to node N
   else:
      attach the node returned by Generate_decision_tree(Dj, attribute_list) to node N
return N
~~~

### Other Attribute Selection Measures
- **CHAID**: a popular decision tree algorithm that exploit the $\chi^2$  independence test
- **C-SEP**: performs better than information gain and Gini index in *certain cases*
- **G-statistic**: has a close approximation to a $\chi^2$ distribution
- **MLD (Minimal Description Length) principle**: is chosen the *simples solution* (e.g. the solution that require the fewest number of bits to encode the tree and its exceptions)
- **Multivariate splits**: partition is based on multiple variable combination (e.g. CART exploit split based on linear combination of attributes)

- It doesn't exist a superior selection measure, all have some bias, however time complexity increases exponentially with tree height, so measures that produces *shallower trees* are preferred
- but shallow trees tend to have a large number of leaves and higher error rates


### Overfitting and Pruning
- **Overfitting**: an eccessive specialization on the training set, its caused usually by too many branches that lead to capture noises, outlier and anomalies, and bring to poor accuracy for unseen samples 
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251012153910.png]]

- we can detect that the tree is overfitted if the error rate on the training set is much less than the error rate on the test set
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251012154019.png]]

### Estimating Generalization Errors
- **Re-substitution errors**: error on training set ($e_{tr}$)
- **Generalization errors**: error on test set ($e_{ts}$)

- Methods for estimating the generalization errors:
  - *Optimistic approach*: $e_{ts}$ = $e_{tr}$
  - *Pessimistic approach*: for a node $e_{ts}$ = $e_{tr}$ + $0.5$, for the entire tree $e_{ts}$ = $e_{tr}$ + $0.5 * N$ (N = number of leaf)

- *Reduced error pruning* (**REP**): use a *pruning data set* to estimate the generalization error

- **Pruning set**: validation set
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251012154456.png]]

- **Occam's Razor**: given two models with similar generalization errors, it's prefer the *simpler model*
- for complex model there is a greater chance that it was overfitted
- so in the model evaluation it's important to consider the model complexity


### Overfitting and Pruning
- there is two way to reduce overfitting:
  - *Prepruning*
  - *Postpruning*

- **Prepruning**: halt the tree construction, typical stopping condition are:
  - Stop is all the instances belong to the same class
  - Stop if all the attribute values are the same
- More *restrictive conditions*:
  -  Stop if the number of instances is less than some user-specified threshold
  - Stop if class distribution of instances are independent of the available features (e.g., using Chi-square test)
  -  Stop if expanding the current node does not improve impurity measures (e.g., information gain or Gini index)

- it is difficult to choose the *thresholds*

- **Postpruning**: remove branches (*subtrees*) from a fully grown tree. each removed subtrees is replaced with a leaf labeled with the most frequent class among the replaced subtree. use a different set of data to decide which is the *best pruned tree*
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251012155212.png]]
- we can loose a bit of accuracy, but gain interpretability
### Reduced Error Pruning (REP)
- **Reduced Error Pruning** use pruning set to estimate the accuracy of sub-trees and the accuracy of individual nodes
- Let *T* be a sub-tree at node *v*
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251012160945.png]]

- the gain from pruning at v can be defined as the number of misclassifications in T, minus the number of misclassification at v
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251012161050.png]]
 - so how much misclassification we have if we prune a node vs if we don't prune the node

- prune at node with the largest gain and repeat until only negative gain nodes remain
- **Bottom-up restriction**: T can be pruned only if it does not contain a sub-tree with lower error than T

- the **cost complexity** of the *Postpruning* depend on the number of leaves in the tree and the **resubstitution error** of the tree 
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251012161346.png]]
- The *Resubstitution error* is the misclassification rate computed on the training set and $\beta$ is the penalty per additional terminal nodes




- REP example;
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251016085933.png]]
- E(v2) is the number of wrong classified instances obtained if we replace the node with a rule v2 with a leaf with the majority class


### Postpruning cost complexity
- Search for the **right-sized** tree:
  - *prune or collapse some of the branches of the largest tree*, from bottom up, using the cost complexity parameter and a cross-validation or an independent test sample to measure the predictive accuracy of the pruned tree
  - use the *resubstitution cost for ranking the subtrees and generating a tree sequence table* ordered from the most complex tree at the top to the less complex tree at the bottom 
  - we *identify the minimum-cost tree and pick an optimal tree* as the tree within one standard error of the minimum cost tree 
  - so we need to balance complexity and accuracy, this trade off is balanced with the hyperparameter $\beta$ 

- an **optimal tree** is the smallest tree among the tree with the same *standard error*


### Postpruning in C4.5
- **Pessimistic pruning**: is similar to the *cost complexity pruning*, but does not use a pruning set
- it adjust the error rate obtained from the training set **by adding a penalty** obtained with an *heuristic approach based on statistical theory*. if the error rate in the node is lower than the error rate in the subtree originated from the node, then the subtree is pruned

- the best approach is usually to use a pruning set


### Postpruning
- pruned tree are more compact than unpruned tree, but they still have:
  - **Repetition**: an attribute can be repeatedly tested along a given branch
  - **Replication**: duplicate subtrees can exist within the tree
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251012163046.png]]

- Repetition and Replication can worse accuracy and comprehensibility of a decision tree, but more off all those impact the transparency
- we can prevent these problems by using **multivariate split** (*split based on a combination of attributes*)
- another approach is to use a **different form of knowledge** such as *rules* instead of decision trees (e.g. rule-based classifier)


### Enhancements to basic decision tree induction
- **Allow continuous valued attributes**: dynamically define new discrete-valued attributes that partition the continuous one into a discrete set of intervals
- **Handle missing attribute values**: assign the most common value of the attribute, assign probability to each of the possible value
- **Attribute construction**: create new attributes based on existing ones (that are *sparsely represented*) to reduce fragmentation repetition and replication


### Classification in Large Databases
- decision tree are a popular method because they are fast, it's possible to convert them in a rule based method, its possible to use SQL queries to access database, they have a good accuracy
- their construction is inefficient if the training set doesn't fit in memory, in this case is needed a swapping of the training tuples

### Scalability Framework for RainForest
- **RainForest**: use a data structure called **AVC-set** (*Attribute, Value, Class_label*), it adapts to the amount of main memory available and applies to any decision tree induction algorithm
- the AVC-set is a projection of the training dataset onto the attribute X and class label where counts of individual class label are aggregated

- The dimension of the AVC-set depends on number of distinct values of A and the number of classes

![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251012164122.png]]


### BOAT (Bootstrapped Optimistic Algorithm for Tree Construction)
- **BOAT** use a *statistical technique* called **bootstrapping** to create several smaller samples (subset), which each fits in memory
- each subset is used to create a tree
- all these tree are examined and used to construct a new tree **T'** that is close to the tree that would be generated using the whole dataset together 
- it require only *two scan of the db*, one to create the subset for training, and one to compute the final splitting criteria
- *can be used for incremental updates*






## Bayes Classification Methods

- **Bayesian Model**: its a type of statistical classifier, that predict *class membership probabilities* given an instance attributes values 
- it's based on the bayes theorem, the naive bayes has performance similar to a tree
- it's *incremental* each training example can incrementally increase or decrease the probability that a hypothesis is correct, if we have new instances we don't need to rebuild the model from scratch (with other models, for instances with tree we have to)

- you have the vector of feature X called **evidence** 
- **H** is the hypothesis that X belongs to the class C
- the classification of a bayes model consists in determining the probability that an instance belongs to class C given its attributes X, and its called *posteriori probability*

- it can gives in output the probability to belongs to each class

- **P(H|X) (posteriori probability)**: the probability that the hypothesis H it's true given X
	- Let us suppose that H is the hypothesis that a customer will buy a computer and a customer is characterized by age and income.
	- Then, P(H|X) is the probability that X will buy a computer given his age and income. For instance, X is a 35-year-old customer with an income of $40,000
	
- **P(H) (prior probability of H)**: the probability for a generic instance to belongs to H
- **P(X) (prior probability of X)**: probability to have a certain observed feature value (e.g. an age of 35 and an income of 40.000)
- **P(X|H) (posteriori probability of X conditioned on H-likelihood)**: the probability of having a certain value of the attributes, knowing that the sample belongs to class C 


- *P(H), P(X) and P(X|H)* can be estimated from the given data
- *P(H|X)* can be computed by the Bayes’ theorem

- **Bayes theorem**: 
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251015143938.png]]
so the posteriori probability is equal to the likelihood by the prior probability divided by the evidence probability

- the bayes model predicts that X belong to the class with the **highest a posteriori probability**
- it require a lot of computational cost if we have a lot of attributes and possible value for our attributes


### Bayes naive classifier
- let D be a training set of tuples of n attributes with $m$ classes associated
- our objective is to determine the class with the highest posterior probability, so the class Ci with the max value **P(Ci|X)** given a certain X

- this value can be derived from the Bayes Theorem
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251015144534.png]]

- P(X) is *constant for all classes*, so it can be computed just one time
- P(Ci) can be computed as the number of instances that belongs to the class Ci in the dataset, divided by the number of instances in the dataset
- we have to *maximize* the quantity **P(X|Ci)\*P(Ci)**

- assuming that all the attributes are *conditionally independent*, then the probability P(X|Ci) is equal to the product for each n attributes x1, x2, ...xn of P(xk|Ci), with xk the value of the k-th attributes 
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251015145033.png]]

- in this way we only need to compute the class distribution 

- **for categorical attributes**: Ak is categorical, $P(x_k, Ci)$ is the number of tuple in Ci having value xk for the attribute Ak, divided by the number of tuples with class Ci in D

- **for continuous attribute**: Ak is a continuous valued attribute, $P(x_k, Ci)$ is computed with a Gaussian distribution with mean $\mu$ and st $\delta$ 
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251015150226.png]]
$\mu ci$ and st $\delta ci$ are the mean value and sd for the attribute Ak for tuple of class Ci 

##### Example
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251015150345.png]]
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251015150406.png]]



### Avoiding the Zero-Probability Problem
- Naive Bayes prediction require **that each conditional probability shouldn't be zero**, otherwise the predicted probability will be *zero* 
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251015150600.png]]
- e.g. suppose that a dataset have the attribute income, with 1000 tuples, with 900 of value low, 100 with value medium and 0 of value high.
- One solution can be to use the **Laplacian correction** (or Laplace estimator) that had *1* to the number of instances of each class, so:
  - P(income = low) = 901 / 1003
  - P(income = medium) = 101 / 1003
  - P(income = high) = 001 / 1003
- with the *corrected* probability that are close to their *uncorrected* counterparts


### Comment on the Naive Bayesian Classifier
- Advantages: it's easy to implement and return good results in most of cases
- Disadvantages: require *class conditional independence*, otherwise it lose accuracy, moreover it require *independence between attributes* which are rare

- We can resolve these problem with **Bayesian Belief Networks**


### Bayesian Belief Networks
- **Bayesian Belief Networks** (also called *bayesian network* of *probabilistic network*): allow the representation of dependencies among subsets of attributes (both discrete and continuous)
- we have a graphical representation of the dependency between the attributes using a graph, nodes are attributes, edge are dependency
- it is possible to have loop and cycle 
- nodes can be real attributes or *hidden variables* believe to form a relation but not really in the dataset

- in addition to the graphical representation, we have a **conditional probability table** (*CPT*), that represent the probability to have the value of an attribute given the value of the other attributes value (the *parents attributes*, so with arrows that point to it)
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251016111119.png]]
- for example the first cell is the probability of having the variable lung cancer equal true, knowing that family history and smoker are true, so we can predict the probability of an attribute given the value of the others
- it shows the *conditional probability* for each possible combination of the values of its parents
- when we have *fictitious nodes* you have to apply an optimization approach

- if we have a data tuple with n attributes, and each attribute is independent of its *nondescendants* in the network graph, then given its parents, a complete representation  of the existing joint probability distribution can be obtained by the product of having the value of a certain attribute given the value of the parent
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251016111609.png]]


- if we don't specify dependency explicitly, then all the variables are assumed to be dependent on each other, you need to specify the dependencies if you know them 
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251016111707.png]]

- usually the bayes model return the probability for each class, not only the most probable one


### Several Scenario in Training Bayesian Networks
- *Scenario 1*: we have both the network structure and all variables are observable, we compute only the CPT entries ,we have a complete scenario
- *Scenario 2*: The network structure is known, but some variables are hidden, we compute the CPT via optimization approach like hill climbing 
- *Scenario 3*: The network structure is unknown, and all variable are observable, we construct the network topology using the value that we have
- *Scenario 4*: The network structure is unknown, all the variable are hidden, we can't do nothing in this case

##### Scenario 2
- Let $w_{ijk}$ be a CPT entry for the variable $Y_i = y_{ij}$ having the parents $U_i = u_{ik}$, where  
    $w_{ijk} = P(Y_i = y_{ij} \mid U_i = u_{ik})$.
- If $w_{ijk}$ is the upper-leftmost CPT entry in the previous example, then  
    $Y_i$ is _LungCancer_, $y_{ij}$ is its value “yes”, $U_i$ lists the parent nodes of $Y_i$, namely ${ \text{FamilyHistory}, \text{Smoker} }$, and $u_{ik}$ lists the values of the parent nodes, namely ${\text{“yes”}, \text{“yes”}}$.
- A gradient descent strategy is used to search for the $w_{ijk}$ values that best model the data, based on the assumption that each possible setting of $w_{ijk}$ is equally likely.
- It searches for a solution along the negative of the gradient of a criterion function.
- We maximize the probability assigned by the network to the observed data when the CPT parameters are set to $w$.
- This can be done by following the gradient."

- The algorithm procede as follow:
	- Compute the gradients (for each training tuple $X^{(d)}$).
	- Take a small step in the direction of the gradient (where $\eta$ is the learning rate).
	- Renormalize the weights (all the weights must be between $0$ and $1$, being probabilities, and must sum to $1$ for all $i, k$)."




## Rule-Based Classification
- A **Rule-Based Model**: represent the knowledge in form of *if-then rules*
- Rules have an antecedent (precondition) and consequent (result)

- A classifier is a **set of rules**, given a tuple with a set of attributes we classify it by following the rules

- We assess the rules via coverage and accuracy
- **n covers** is the number of tuples covered by the rule, so that *enter the rule* R
- **n correct** is the number of tuples correctly classified by rule R (always lower than n covers)
- **coverage(R)** is the ratio between n covers of R and the number of tuple in the training set
- **accuracy(R)** is equal to n correct / n covers for a rule R, so the ratio of corrected classifier tuples by a rule


- If we trigger more than one rule (that return different outputs) we need a **conflict resolution** system 

##### Conflict resolution
- Conflict resolution strategies:
  - **Size ordering**: we assign highest priority to the rule that test the largest number of attributes (so the *toughest requirement*)
  - **Class-based ordering**: we give highest probability to the rule that predict the most frequent class, or the rule with the highest *misclassification cost per class*
  - **Rule-based ordering** (*decision list*): we give highest priority to the rule with the best accuracy or coverage or other measure e.g. given by expert in that field
  - each rule in a *decision list* imply the negation of the rules that come before it in the list (it is difficult to interpret)

### Rule extraction from a decision tree
- The easiest way to generate a rule based classifier is to extract the rule from a decision tree
- Another alternative is to use a *heuristic approach*

- Rules are easier to understand than some large tree
- **One rule** is created for each path form the root to a leaf, and each attribute-value pair along a path forms a *conjunction*, and obviously the leaf holds the *prediction*
- with tree that suffer from repetition and replication the extracted rule can be difficult to interpret
- example:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251016113757.png]]


### Prune the rule set
- Each condition which does not improve the estimated accuracy of the rule can be *pruned* 
- But after the pruning the rules will no longer be mutually exclusive and exhaustive

- if we perform a prepruning of a tree, the path are mutually exclusive so we shouldn't have conflict
- with post pruning of the tree we could have some conflict in our rules

- we can *prune the rule set* by eliminating the conflicting rule that are less important and have the lowest accuracy 
- If a tuple is not covered by any rule, it is assumed to a **default class** (the class which contains the highest number of tuples *not covered by any rule*)

### Rule induction: Sequential Covering Method
-  **Heuristic approaches**:
  - *Sequential covering algorithm*: extract rules directly from the training data (e.g. FOIL, AQ, CN2, RIPPER)
  - *Rules are learned sequentially*: each rule for a given class Ci will cover many tuples of Ci, but none or few tuples of other classes

  - Steps:
    - Rules are learned one at a time
    - Each time a rule is learned *the tuples covered by the rules are removed*
    - The process is repeated on the remaining tuples unless we hit a *termination condition*, e.g., we have no more training examples or when the quality of the rule returned is below a user-specified threshold

- The **Heuristic method** learn one rule at a time, instead the decision-tree induction method can leans a set of rules simultaneously

- Graphical representation of the heuristic method:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251016114908.png]]

- algorithm for the **Sequential Covering Algorithm**:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251016115146.png]]


- to generate a rule:
```PYTHON
while(true)
	find the best predicate p
	if foil-gain(p) > threshold: 
		add p to current rule
	else:
		break
```

### How to learn One Rule
- **Greedy depth-first strategy**: we start with the most general rule possible, and then we consider each possible attribute that may added to the rule

- e.g. we have a banking problem with attributes age, income, education level, residence, credit rating, term of loan.
- We start with a *empty condition*, so our basic rule is:
- if () then loan_decision = accept
- Then we consider all the possible condition to add to that rule (we build a tree with the empty condition as the root)
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251016115659.png]]

- We need to measure the rule quality, to do so we can use *accuracy* and *coverage*
- It is important to balance both accuracy and coverage, a rule can have a very high accuracy but it may cover a very small number of tuple and not generalize well
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251016115825.png]]


- Another possible metric that consider accuracy (given by the ratio) and coverage (coverage is given by *pos'*) is the *Foil Gain*
- **Foil gain** (*First Order Inductive Learner*) is define as:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251016120021.png]]

- where pos and neg are the number of positive and negative tuples covered by the current rule R
- and pos' and neg' are the number of positive and negative tuples covered by the current rule R'

- *Foil Gain* favor rules that have high accuracy and cover many *positive tuples*


##### Prune Rule on FOIL
- The methods **Learn_One_Rule** does not employ a test set when evaluating rule, so its evaluation is *optimistic*
- Rule pruning is based on an independent set of test tuples
- Pruning is carried out by removing a conjunction
- FOIL use a simple and effective method to prune rules
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251016120447.png]]
- if the value of FOIL Prune is higher for the pruned version of R, then R is pruned
- **RIPPER** by convention starts the pruning with the most recently added conjunction
- Conjunction are pruned one at a time, and the prune continue until the results lead to an improvement



## Classification by Using Frequent Patterns (Skip for now?)
- **Associative Classification**: *mine data to find strong association between frequent patterns (conjunction of attribute-value pairs) and class label*

- Association rules are generated  in the form:
  p1 and p2 and ... pn = Ci

- then organize the rules to form a rule-based classifier

- It is effective because it explores highly confident associations among multiple attributes, and may overcome some constraints introduced by a decision-tree induction, which consider only one attribute at a time
- This method is usually more accurate than other like C4.5

### Associative Classification Method
- **CBA** (*Classification Based on Association*): mine possible association rules in the form of (condition-set of attribute-value pairs)
- the classifier is build by *heuristic method* where the rules are organized according to decreasing precedence based on confidence and support
- if a set of rules has *the same antecedent* then the rule with the highest confidence is selected to represent the set

- to classify a new tuple we search for the first rule satisfied by the tuple (it is also present a default rule in case a tuple didn't satisfy any rule)



- **CMAR** (*Classification based on Multiple Association Rules*): to build the classifier we use a variant of **FP-growth algorithm** to find the complete set of rules satisfying the minimum confidence and minimum support thresholds
- When a rule is insert in the rule based we execute a rule pruning, if two rules have the same *antecedent*, we eliminate the less general rule
- we also prune rules for which the rule antecedent and class are not positively correlated, based on a chi-square test of statistical significance

- to classify a new tuple with the CMAR method: if the rules matching the tuple are not consistent in the class label, we divide the rules in groups according to the predicted class label, then we use a weighted chi-squared measure to find the strongest group (based on a statistical correlation of the rules), the new tuple will be assigned to the class label of the strongest group
- CMAR has  a slightly higher accuracy and use less memory than CBA



- **CPAR** (*Classification based on Predictive Association Rules*): to build the classifier we use a *rule generator algorithm* (similar to FOIL) rather than frequent itemset mining 
- in FOIL when a rule is generated, the samples that satisfy the rule are removed, in CPAR the tuples remain, but have a lower weight 
- to classify a new tuple, we divide rules into groups according to class labels, the best k rules (chosen based on expected accuracy) of each group are used to predict the class label 
- has an efficiency similar to CMAR



## Lazy Learners
- **Eager learning** (typical ML methods): given a set of training tuples, constructs a classification model before new data to classify

- **Lazy Learners**: (e.g. *instance based learning*): stores training data and waits until it is given a test tuple. we don't build the model, but we exploit the training set for classify new instances, has zero training time, but higher classification time

- Lazy learner use less time in training, but more time in prediction, they uses many local linear function to form an implicit global approximation to the target function 
- Eager learner must commit to a single hypothesis that covers the entire instance space

### Lazy learners: Instance-Based Methods
- **Instance-base learning**: store training examples and delay the processing until a new instances must be classified (e.g. K-nearest neighbor, Local weighted regression that construct a local approximation)
- **Case-based reasoning**: uses symbolic representations and knowledge-based inference

### K-nearest neighbor (KNN)
- All the instances correspond to points in a n-dimensional space
- The *nearest neighbor* are defined in terms of **euclidean distance** between the points of the instance $d(x_1,x_2)$ 
- target function could be discrete or real valued
- for the discrete-valued knn returns the most common value among the k training examples nearest to $x_q$
- it require a time of O(N) to compute all the distances, (you should also consider the number of feature), while you compute the distances you also need to store the smallest distances

- **Voronoi diagram**: the decision surface induced by 1-NN for a typical set of training examples (it's a visualization of the space division for k=1)
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260415150130.png]]


- For *categorical attributes*, we can't compute the Euclidian distance, an alternative is to check if the attribute values are identical
- For **missing values** on an attribute, we assume the *maximum possible difference* (usually this difference is 1)

- We determine a **good value of k*** experimentally, we try incrementally larger value and we choose the one with the higher accuracy, generally with more instances is require a larger value of k

- We can chose different *distances* (other than the euclidian one) and different distances can have different properties

- If we sort and arrange the tuples into search trees the number of comparison to find the neighbor could be reduced to O(log(|D|))

- we can have **parallel implementations**
- **Partial distance**: use only a subset of the n attributes, if the distance is higher than a given threshold then the computation of the distance is stopped


- one disadvantage of the knn is that we always need to store all the training set, and so we occupy a lot of memory, and the more it is big, the more time we use in the inference for a new instance, one solution to this problem are the *Editing methods*
- **Editing methods**: *remove training tuples that prove to be useless*


### Editing Methods
- **Wilson editing**: cleans interclass overlap regions, thereby leading to smoother  boundaries between classes 


- preprocessing process:
    - for each example oi 
    - label the example oi with the class associated with the largest number of k nearest neighbors
    - then delete all the samples that were misclassified in step 2
- then classify new example q using the KNN rule with the edited subset **Or** 
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251016141530.png]]
- This method delete probably noisy point, the result is a cleaner and slimmer dataset. Usually the reduction is 10%/15% of the size

### Editing methods: multi-edit 
- **Multi-edit**: repeatedly applies *wilson editing* to N>=3 random subsets of the original data until no more examples are removed. if the last iteration produce no editing keep the intersection of the remaining examples of the various subsets, otherwise return to step 1
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251016141814.png]]

### Citation Editing
- **Citation method**:
  - for each example oi in the dataset O:
    - find the k-nearest neighbors of oi in O
    - find the **C nearest citers** in O which count oi among their k-nearest neighbor
    - classify oi with the class of the majority of example in a group consisting of K nearest neighbors and C nearest citers
  - Discard all the example oi from O that were misclassified in the last step and create Or

- *Citers* are basically points that as oi as one of the neighbor 

- POI VANNO FATTI I PUNTI C, D, E DI SOPRA??? (DA RIVEDERE)
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260415150833.png]]

### Supervised clustering
- **Supervised clustering**: O is replaced by a subset Or which consists of cluster representatives that have been selected 

- Preprocessing: apply a supervised clustering algorithm to dataset O to produce a set clusters (each set have a single representative)
- edit dataset O by deleting all non-representative examples to produce subset Or
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251016144003.png]]


### Editing methods: experimental evaluation 
- we want to *compare* a number of datasets
- we can see that the compression rate of supervised clustering is almost 90%, wilson only 20% but an higher accuracy
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251016144109.png]]

- **Training set compression rate**: is equal to one minus (number of instances after editing the training set, divided, number of instances in the original training set) multiplied by 100
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251016144236.png]]

- visualization of the editing methods deletion:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251016144305.png]]


### KNN for prediction (regression)
- knn for **real value prediction** can be done by returning the mean values of the k nearest neighbors
- we can also consider the **weighted distance**, that weight the contribution of each of the k neighbors according to their distance to the query xq, this method *give greater weight to closer neighbors*
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251016144612.png]]

- this method is *robust to noisy data*
- but can be affected by the **curse of dimensionality**: distance between neighbors could be dominated by dominated by irrelevant attributes (to resolve this we can eliminate the least relevant attributes)


### Case-Based Reasoning (CBR)
- **Case-Based Reasoning (CBR)**: is the process of solving new problems based on the solutions of equal or similar past problems
- it follow the core assumption: *similar problems have similar solutions*
- it uses a database of problem solution to solve new problems
- it store symbolic description tuples or cases, not points in a euclidean space

- e.g. an engineer that copy nature to create a design, a lawyer who advocates a particular outcome in a trial based on legal precedents or a judge who creates case law.

- **Methodology**:
  - *Cases* are represented by rich symbolic descriptions 
  - we search for cases similar to the one that we have to solve (we can also combine multiple cases)
  - when a new (successful) solution to a problem is found a new **experience** is made, which can be stored in the *case-base* to increase its competence, thus implementing a *learning behavior*
  - there is a tight coupling between case retrieval, knowledge base reasoning and problem solving 
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251016145946.png]]

- **Retrieve**:
  - one or several cases from the case base are selected based on the modeled similarity
  - the retrieval task is defined as finding a small number of cases from the case-base with the highest similarity to the query
  - (this is basically a knn retrieval task with a specific similarity)
  - the more the *case base* grown, the less is the efficiency of retrieval (but there are methods to improve it)
 
- **Reuse**: 
  - *reusing* a retrieved solution can be simple if the solution is returned unchanged as the proposed solution for the new problem
  - *adaptation* for the new problem if it is required
  - there are several techniques for adaptation in CBR:
    - transformational adaptation 
    - generative adaptation
  - but practical CBR try to avoid extensive adaptation as much as possible

- **Revise**:
  - in this phase we have a feedback on the obtained solution 
  - the feedback can be a numeric value or a manually corrected revised case
  - the revised case or any feedback enter in the system and is used for subsequent retain phase

- **Retain**:
  - the retain phase is the learning phase of a CBR system
  - it consist in adding a revised case to the case base
  - there are explicit competence models to do a selective retention of cases (because of the continuous increase of the case-base)

###### Case-Based Reasoning example
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251016151954.png]]

- Note:
  - similarity is the most important concept in CBR
  - similarity may be assessed based on the similarity of each feature
  - sometimes the importance of a feature can be modified by a weight 
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251016152410.png]]
- we save case 3 in our knowledge base, case 3 is an adapted version of case 1

- the main challenges in the CBR is to *Find a good similarity metric*


## Model Evaluation and Selection
- It is important to test the accuracy on a test set disjointed with the training set

- Methods for estimating a classifier's accuracy:
  - *Holdout method, random subsampling*
  - *Cross validation*
  - *Bootstrap*

- Method to compare classifiers:
  - *Confidence intervals*
  - *Cost-benefit analysis and ROC Curves*

### Classifier Evaluation Metrics: Confusion Matrix
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251016153104.png]]
- given m classes, an entry CMij in a **confusion matrix** is the number of tuples in class i that were labeled by the classifier as class j
- it can have an extra row and column to provide total 

- **Accuracy** (*recognition rate*): percentage of test set tuples that are correctly classified
  Accuracy = TP + TN / N
- **Error Rate**: percentage of test set tuples that aren't correctly classified
  ER = FP + FN = 1 - Accuracy

- *accuracy* is not a good metrics when classes are not balanced, if 99% of tuple belongs to one class, we can build a classifier that always return the majority class (so the other class is never predicted) so have an high accuracy but very bad performance

- **Class imbalance problem**: one class can be rare
- **Sensitivity**: True positive recognition rate
  Sensitivity = TP / P
- **Specificity**: True negative recognition rate
  Specificity = TN / N

- **Precision** (*exactness*): fraction of predicted positive cases that are actually positive
  Precision = TP / TP + FP
- if the precision is 1, then all the tuples classified as class C belongs to class C (but we don't know the number of tuples of class C mislabeled as other classes)


- **Recall** (*completeness*): fraction of actual positive cases that are correctly predicted as positive. (equal to sensitivity)
  Recall = TP / P
- if the recall is 1 then all tuples in class C belongs to class C (but we don't know how much other tuple have been mislabeled as belonging to class C)


- **F measure** (or *F1* or *F score*): is the harmonic mean of precision and recall
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251016154611.png]]


  1) matrice di confusione: quantifica gli errori in base alla loro tipologia TP FP TN FN
  2) accuratezza = TN + TP / N usata quando le classi sono bilanciate e ugualmente importanti
  3) precisione = TP / FP + TP usata quando i falsi positivi sono importanti 
  4) richiamo = TP / FN + TP usata quando il falso negativo  è costoso (ad esempio, nel caso di rilevamento di malattie, è importante identificare tutti i casi positivi, anche se ciò comporta alcuni falsi positivi)
  5) f1 score = 2 * p * r / p + r quando fp e fn sono ugualmente importanti. È particolarmente utile quando si vuol bilanciare precisione e richiamo (nel rilevamento di frodi finanziarie garantisce un'accurata identificazione delle frodi senza generare un numero eccessivo di falsi positivi o falsi negativi)

- **FB** is the *weighted* measure of precision and recall, assign to the recall an importance to B times the precision
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251016154723.png]]
- usually we have B=2 or B=0.5

- Example of precision and recall:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251016154815.png]]
- we recognize less than 1/3 of cancer case, but since the classes are imbalanced, then the accuracy is very high

- with more than two classes, only one class at a time is consider positive and all the other one is considered negative, but we compute precision for each class considered as the positive one


### Holdout and cross validation 
- a **unique execution** of different classifier, cannot allow concluding that one classifier is better than another, we need to do more trials, however we have just one dataset 


- **Holdout method**: the data is randomly partitioned into two independent sets:
  - training set (e.g. 2/3)
  - test set (e.g. 1/3)

- **Random sampling**: repeat the *holdout method* for k times (each time with different train and test set) and calculate the average of the accuracies, but since it's a *distribution of accuracy*, we can also do **statistical test** on the mean difference of the two classifier to check if the two classifier has really different performance or the result it's given by luck
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251016155151.png]]


- **Cross validation**: we have *k-fold* (usually k=10)
  - we partition the dataset in k *mutually exclusive* subsets, each approximately of equal size
  - at the iteration i-th we use the subset i as the test set and the other as the training set
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251016155643.png]]

- **Leave one out**: variation of the cross validation where k = number of tuple in dataset, only a single tuple is left out as the test set (this method can be used only with small set of data)

- **Stratified cross validation**: folds are stratified so that class are distributed in each fold approximately the same as the in the initial data


### Bootstrap
- **Bootstrap**: samples the given training tuples uniformly with replacement (e.g. if a tuple is selected for the training set, it has equal probability to be re-selected and re-added to the training set)

- There are several Bootstrap methods, the most common is *Bootstrap .632*

- **Bootstrap .632**: a data set with d tuple is sampled d times *with replacement*, resulting in a training set of d samples. the training tuples that did not end up in the training set end up in the test set. approximately **63.2%** of the tuple end up in the bootstrap and *36.8%* in the test set
- repeating the sampling procedures k times the overall accuracy of the model is:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251016160238.png]]


### Estimating confidence intervals
- Suppose that we have two classifier M1 and M2, which one is better than the other?
- we can use a 10-fold cross validation to obtain the ER of m1 and m2, these are jut approximation of future errors on the population 
- there is a possibility that the difference in the er of the two models is given by chance, we can verify this using a *statistical significance test*, we obtain a confidence limits for out error estimates

- we need a test because it is possible that the er are characterized by an high variability
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251016160846.png]]

### Estimating Confidence Intervals: Null Hypothesis
- we perform 10-fold cross-validation, with the assumption that the samples are *normally distributed* within each group (so the output of each classifier is normally distributed), and the variance of the two populations are not *reliably different*

- we can use as the test the **Student's t-test** to evaluate the differences in the means between two groups. with the **Null Hypothesis** *that the two distribution of accuracy for M1 and M2 are the same*
- if we *reject* the null hypothesis, then the difference in the error rate between M1 and M2 are relevant and we can conclude that one model is better than the other (the one with the lower error rate)

### Parametric statistical tests: t-test 
- we use the same test set and train set of the 10-fold cross validation for both models in the i-th round
- we compute the average of the error rate for the two model
- and we compute the t-test with k (number of folds) degree of freedom
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251016161328.png]]

- if there is *two available test set* you can use the **non-paired t-test**:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251016161414.png]]
where k1 and k2 are the number of cross validation samples used for m1 and m2 respectively 

- we also need to chose a *significance level* **t**
- then we can find in the tables the **t-value** for a certain significance level and degree of freedom (the degree of freedom in this case is the **number of fold -1**)
- if **t > z** or **t < -z** then the t value lies in *rejection region* and we can **Reject the null hypothesis** so there is *Statistical significance* between the difference in the er of m1 and m2
- otherwise we conclude that any difference in the value of the two er is given by chance

- in *non paired version* (with different test set) the number of degrees of freedom used is taken as the minimum number of degrees of the two models
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251026150119.png]]

- The significance level is expressed by using probability, the significance level express what is the probability we are accepting to consider rejected the null hypothesis, if **t** is low the probability that H0 is true is higher (*da rivedere*)

- *if t computed is higher than table t, i reject the null hypothesis, so one of the classifier is better and i can choose the one with higher accuracy*
- to apply the t-test you have to be sure that distribution are **normal**


### Non parametric statistical tests: The Wilcoxon signed rank sum test
- The **Wilcoxon signed rank sum test** is an example of non-parametric or distribution free test
- **The ***null hypothesis H0*** **for this test is that the medians of two samples are equal**, so we are testing if two population have the same distribution with the same median
- It is generally used:
  - as a non-parametric alternative to the one-sample t test or paired t test
  - for ordered (*ranked*) categorical variables without a numerical scale

- There are *two assumption* that must hold:
  - the two samples are independent of one another
  - the two population have equal variance or spread

##### Wilcoxon signed rank sum test process
- **Process** for paired data:
  1) **Calculate each paired difference** $di = xi - yi$, where xi and yi are the pairs of observation (for each classifiers)
  2) **Rank difference di ignoring the signs**, e.g. assign rank 1 to the smallest $di$, rank 2 to the second smallest and so on... (Note: we are ignoring the sign)
  3) **Label each rank with its sign** according to the sign of $d_i$
  4) **Calculate W+**, W+ is the sum *of ranks* of the positive differences $d_i$, and **W-** the sum *of ranks* of the negative differences $d_i$, W+ + W- should be equal to $\frac{n(n+1)}{2}$ where *n* is the number of pairs of observations in the sample
  5) **Choose W=min(W+, W-)
  6) **Use tables of critical values for the Wilcoxon signed rank sum test to find the probability of observing a value of W of more extreme**. Most tables give both one-sided and two-sided *p-values*, if not, double the one-signed p-value to obtain the two-sided p-value

- under the null hypothesis we would expect the distribution of the differences to be approximately symmetric around zero, and the distribution of positives and negatives to be distributed at random among the ranks. Under this assumption, it is possible to work out the exact probability of every possible outcome of W


##### Normal approximation
- If the number of observation is large such that $\frac{n(n+1)}{2} > 20$, then we can normalize the test:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251026151826.png]]
- observation in the sample may be exactly equal to the median value M, ignore such observation and adjust **n** accordingly
- two or more observation may be equal, if so, average the ranks across the tied observations and reduce the variance by $\frac{t^3 - t}{48}$ for each group of **t tied rank**

##### Example of Wilcoxon test
- we have 12 cross validation
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251026152112.png]]

- we rank the differences (not considering the signs in the ranking):
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251026152127.png]]

- we compute W+ and W-, we don't sum up the differences, but the ranks:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251026152156.png]]

- we compute W and check if we can use a normal approximation: 
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251026152208.png]]

- since $\frac{n(n+1)}{2} > 20$ we can use a normal approximation, since we have *two tied ranks* we must reduce the variance by $\frac{2^3 - 2}{48} = 0.125$ 
- we compute the z-score (the z-score is the measure of how many sd below or above the population mean a raw score is):
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251026152416.png]]
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251026152422.png]]

- we look for this z-score in the **z-table\***, and we get an area of 0.9880, equal to a two-tailed p-value of 0.012, since the p-value is small the median are probably different



## Estimating Confidence Intervals: Statistical Significance
 - until now we have tested the *accuracy* of the classifiers, but that is a bad metric if the dataset is imbalanced, in this case we need to use:
   - F-measure
   - AUC (Area Under the ROC Curve)

### Model Selection: ROC Curves
- **ROC** (**Receiver Operating Characteristics**): curves for visual compare different classification model
- they shows the *trade-off* between *true positive rate and falso positive rate*

- Rank the test tuples in decreasing order, the one most likely to belong to the positive class appears at the top of the list

- in the vertical axis is represented the *true positive rate* = TP / P
- in the horizontal axis is represented the *false positive rate* = FP / N
- a perfect model will have an area of 1
- the closer to the diagonal line, the less accurate is the model
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251026153202.png]]
- we need to decide the best combination of parameters (parameters that you can change) to have the best value for the AUC (close to the (0,1) classifier)

- the cost of the error in the minority class is usually higher than the cost of the error in the majority class (it is more important to correctly classify the minority class, e.g. predict the presence of a cancer)

##### Example of a ROC curve
- **Convex hull**: minimal convex set containing the points of the ROC curve
- example of a  ROC Curve generation for a bayes classifier, we obtained the curve by using different parameters value (in this case the threshold used for the classification) for the same model: 
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251026153417.png]]

### Model Selection: Cost of a classifier
- The **Cost of a classifier** is the point with the (FPR, TPR)
- the *cost* is computed as:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251026153557.png]]

where:
- P(n) and P(p) are the *a-priori* probabilities of a negative example and positive example
- C(Y,n) and C(N,p) are the **false positive cost** and **false negative cost**, and they are the *cost* for wrong prediction, usually are given by experts in the field

- Once fixed the values of P(n), c(Y,n), P(p) and C(N,p), we can obtain a family of parallel lines (called **iso-cost lines**) with *slope*:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251026153736.png]]



- The points belonging to the same line have the same cost, and the cost decreases as we move parallel lines closer to the point (0,1)
- **Point that minimize the classification cost: tangent point between the ROC curve and the family of parallel lines** 
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251026154003.png]]
- with this we obtain the best parameters for a classifiers for the cost decided by us, the best point identified is the closest to the point (0,1)

##### How can we compare different classifiers with AUC (case imbalanced datasets)?
- Connect the point (FPR,TPR) corresponding to the classifier to point (0,1) and to point (1,1).
- Compute the AUC for each trial of a cross validation, thus generating a distribution of AUCs in place of a distribution of accuracies (for instance, in the cross-validation for each repetition with different folds)
- Perform a statistical test on the distributions of AUCs
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251026154144.png]]



## Techniques to Improve Classification Accuracy: Ensemble Methods
- **Ensemble Methods**: use a *combination of models* to increase accuracy, combine k learned model M1, M2, ...Mk with the aim of creating an improved model M* 

- Popular ensemble method:
  - **Bagging**: averaging the prediction over a collection of classifier
  - **Boosting**: weighted vote with a collection of classifier
  - **Ensemble**: combining a set of *heterogeneous* classifiers

- *Analogy*: Diagnosis based on multiple doctors’ majority vote

### Bagging: Boostrap Aggregation
- *Training*: given a set **D** of **d** tuples, at each iteration i, a training set **Di** of d tuples is sampled *with replacement* from D (e.g. *bootstrap*)
- A classifier model **Mi** is learned for each training set **Di**

- *Classification*: each classifier Mi returns its class prediction for an unknown sample X, the **bagged classifier M\*** counts the votes and assigns the class with the most votes to X
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251026160837.png]]

- The **bootstrap prediction** can be applied to *continuous values* by taking the average value of each prediction for a given test tuple
- Have higher accuracy and its more robust to noise

- example, the right decision boundary its the *straight line*, in the left we can see the decision boundary of a tree, on the right the one of a forest (much more similar to the actual one, so more robust to noise)
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251026161145.png]]


### Boosting
 - weights are assigned to each *training tuple*
 - we train k classifiers **iteratively**
 - we train classifier *Mi*, and update the weight of the training tuple to **pay more attention to the training tuples that were misclassified by Mi**, and use that training tuple to train *Mi+1*
 - the final M* combines the vote of each classifier with an associated weight, the weight of each classifier's vote is a function of its accuracy

- *Analogy*: Consult several doctors, based on a combination of weighted diagnoses—weight assigned based on the previous diagnosis accuracy

- so we create a series of classifier, and at each step the new classifier will pay more attention to the points misclassified by the previous one, and then we will combine all of them with a weighted vote

- (also this method can be extended for numeric prediction)
- it has greater accuracy than *bagging*, but an higher risk to *overfit*
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251026161719.png]]
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251026161724.png]]
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251026161731.png]]
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251026161738.png]]
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251026161746.png]]

![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251026161754.png]]


### Adaboost (Freund and Schapire, 1997)
- given a set of **d** *class labeled tuples* (x1, y1), ...(xd, yd) 
- initially all the weights of tuples are set to the same *1/d*
- generates *k* classifiers in k rounds
- at round *i*:
  - tuples from D are sampled with replacement to form a training set Di of *the same size*
  - each tuple's chance of being selected is based on its *weight*
  - a classification model Mi is derived from Di
  - its error rate is calculated using Di as a test set
  - classifier Mi error rate is the sum of the weights of the misclassified tuples
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251026163010.png]]
(where **err(Xj)** is the misclassification error of tuple **Xj**)

- If a tuple *(Xj, yj)*, is correctly classified, then the weight is updated as follows:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251026163100.png]]
- it decrease the weight for correct classified instanced, and wrong classified ones will have an higher error

- once the weight are updated for all the tuple, the weight are **normalized** so that their sum remains the same it was before
- the normalization is performed by multiplying a weight by the sum of the old weight and dividing it by the sum of the new weights

- **Boosting assign a weight to each classifier's vote** based on how well the classifier performed, the more accurate it is, the higher its weight will be
- the weight of classifier Mi's vote can be computed as:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251026163413.png]]

- we sum for each class the weighted vote of each classifier, the class with the higher sum is returned as the predicted class
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251026163519.png]]
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251026163535.png]]
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251026163548.png]]
- we don't save a model Mi if its error rate is over 0.5

### Boosting vs Bagging
- Both train many models on different version of the initial dataset and then aggregate the model

- Bagging:
  - resample the dataset
  - builds models in *parallel*
  - *reduce variance*, doesn't work well with *stumps*

- Adaboost:
  - resample or *reweight* the dataset 
  - builds model *sequentially*
  - *reduce variance and bias* and work *well* with stumps


### Random Forest (Breiman 2001)
- **Random Forest**: each classifier is a *decision tree* generated using a random selection of attributes at each node, each tree votes and the most popular class is returned 
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251026163640.png]]

- Let **N** and **M** be the number of *training instances* and *attributes*, let **m** be the number of attributes to be used for choosing the decision attribute at any node
  1. **choose a training set** by *randomly* extracting N samples with replacement from all the available training instances, and use the rest to estimate the error rate
  2. for each node **choose randomly m attributes** on which to base the decision at that node, calculate the best split based on these variables in the training set (this made possible to have different decision tree in our forest)
  3. each tree is **fully grown and not pruned**

- for the classification return simply the *most popular class*

- **Advantages**: it's one of the most accurate algorithms, it runs efficiently on large database, can handle thousands of input variables, gives an estimation of *what variables are important*, generates an unbiased estimate of the *generalization error*, can handle missing data

- **Disadvantages**: can overfit easily with noisy dataset, moreover it has a bias for categorical variables with a lot of different level, and it loose explainability compared to a classic tree


### Classification of Class-Imbalanced Data Sets
- *Class-imbalance problem*: rare positive example, but numerous negative ones (e.g. medical diagnosis, fraud)
- traditional method assume a balanced distribution of classes (not suitable for class-imbalance data), in a imbalanced data set the models would have a **bias** towards the majority class

- NOTE: we need to rebalance the training set, not the test set

- typical method for imbalance data in *2-class* classification:
  - **Oversampling**: re-sampling data from positive class
  - **Under-sampling**: randomly eliminate tuples from negative class
  - **Threshold-moving**: moves the decision threshold, *t* so that the rare class tuples are easier to classify, and hence less chance of having a false negative 
  - **Ensemble techniques**: ensemble multiple classifiers introduced above 

- it's more difficult for *multiclass task*


- **SMOTE**: Synthetic Minority Over-sampling Technique, is an example of *oversampling* in which the minority class is over-sampled by creating **synthetic examples**, rather than oversampling with replacement
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251026163631.png]]

- Synthetic samples are **generated in the following way**:
   - Take the difference between the feature vector (sample) under consideration and its nearest neighbor
   - Multiply this difference by a random number between 0 and 1, and add it to the feature vector under consideration.
   - This causes the selection of a random point along the line segment between two specific features. This approach effectively forces the decision region of the minority class to become more general
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251026163619.png]]

- when you want just to rebalance the dataset **you have to only rebalance the training set** *not the test set*
- in the k-fold validation, for each fold we select the training set and rebalance just the training set, you will rebalance a new training set in the next fold


# 6 Clustering
## Basic Concept of Cluster Analysis
- **Cluster**: a collection of data objects with the characteristic of being *similar* (or related) to objects in the same group and *dissimilar* (or unrelated) to objects in other groups

- **Cluster analysis** (or *clustering*, *data segmentation*): finding similarities between data according to the characteristics found in the data and grouping similar data objects into clusters

- **Unsupervised Learning**: dataset are not labeled

- Typical applications:
  - get insight into *data distribution* 
  - **preprocessing** step for other algorithms

### Clustering as a Preprocessing Tool
- Way to use clustering as a **Preprocessing Tool**:
  - *Summarization*: preprocessing for regression, PCA, classification and association analysis
  - *Compression*: use data quantization 
  - *Find the KNN*
  - *Outlier detection*: outlier are usually far away from any cluster

### How to define a good clustering 
- We don't know what we want to obtain, or verify the result of our clustering, because we don't have any label, the only way to evaluate the quality of a clustering algorithm is to check the:
  - **intra-class similarity**: how objects of the same clusters are similar to each other 
  - **inter-class similarity**: how objects of different clusters are similar to each other

- a *good clustering methods* have an high intra-class similarity and a low inter-class similarity
- it can depend on:
  - the similarity measure
  - the implementation 
  - the ability to discover hidden patterns


### Measure the Quality of Clustering
- **Similarity metric**: similarity it is expressed in term of a *distance function d(i,j)*
- the definition of that function can change with different type of attribute (bool, categorical, ordinal, vectorial)
- in some application *weights* are associated to different variables based on applications and data semantics

### Consideration on cluster analysis
- **Partitioning criteria**: it is possible to have *single level* vs *hierarchical* partitioning (so cluster that belongs to bigger cluster)
- **Separation of cluster**: it can be *exclusive* (an item can belongs only to a single cluster) or *non-exclusive* (an item can belongs to more than one class)
- **Similarity measure**: the main similarity measure are *distance based* (e.g. Euclidian) and *connectivity-based* (e.g. density or contiguity)
- **Clustering space**: can be a *full space* (we consider all the attributes, usually used when we have a low number of dimensions) or *subspace* (we consider just a subset of all the attributes)

- it is possible to have **constraints** on the clustering problems, e.g. a river in a city for cluster the position of a supermarket locations


### Requirements and Challenges
- **Scalability**: clustering all the data instead of a subsample
- **Ability to deal with different types of attributes**: numerical, binary, categorical, ordinal, *linked*, and a mixture of these
- **Constraint-based clustering**: it is possible that user give *input on constraints* (we should use domain knowledge to determine input parameters)
- **Interpretability and usability**

- Other problems:
  - discover cluster with an arbitrary shape 
  - ability to deal with noisy data
  - incremental clustering and insensitivity to input order
  - high dimensionality 


### Major Clustering Approaches
- **Partitioning approach**: construct various partitions and then evaluate them by some criterion, given the number $k$ of partitions to construct, the partitioning method uses an iterative relocation technique that attempts to improve the partitioning by moving objects from one group to another (e.g. k-means, k-medoids, CLARANS)

- **Hierarchical approach**: create a hierarchical decomposition of the set of data (or objects) using some criterion
- it is possible to use an agglomerative or a divisive approach
- once a step (of merge or split) is done it can never be undone (e.g. Diana, Agnes, BIRCH, CHAMELEON)



### Major Clustering Approaches 
- **Density-based approach** it is based on connectivity and density functions (e.g. DBSCAN, OPTICS, DenClue)
- density based approach doesn't use distance, but density measures


- **Grid-based approach**: it is based on a multiple-level granularity structure, all the clustering operations are performed on the grid structure
- grid help to speed up the clustering approach, but isn't so accurate (e.g. STING, WaveCluster, CLIQUE) 

- Approaches summary:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251029145206.png]]


- **Model-based**: a model is hypothesized for each of the clusters and tries to find the best fit of that model to each other
- **Frequent pattern-based** those model are based on the analysis of frequent patterns, typical methods are *p-Cluster*
- **User guided or constraint-based**: cluster by considering user-specified or application-specific constraints (e.g. COD, constrained clustering)
- **Link-based clustering**: object are often linked together in various ways

### Assessing Clustering Tendency
- Before applying any clustering method on your data, it's important to evaluate *whether the data sets contains meaningful clusters* (e.g. random structures)
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251029150247.png]]

### Assessing Clustering Tendency 
- **Clustering tendency assessment determines whether a given data set has a non-random structure**. which may lead to meaningful clusters

- How can we assess the clustering tendency of a dataset?
- **Hopkins statistic**: spatial statistic that test the *spatial randomness* of a variable as distributed in a space
- It is used to check the *clustering tendency of data set* by measuring the probability that a given data set is generated by a uniform data distribution 
- so **it test the spatial randomness of the data**

### Hopkins statistic 
- Sample n points from a population of N points, p1, p2, ...pn, uniformly from D
- for each point pi, find its nearest neighbor in D
- let xi the distance between pi and its nearest neighbor in D
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251029151342.png]]

- generate a simulated data set *randomD* drawn from a random uniform distribution with n points q1, q2, ...qn and the same variation as the original dataset D
- for each point qi find the nearest neighbor of qi in D
- let yi the distance between qi and its nearest neighbor in D
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251029151548.png]]

- example: in the first example we consider real data randomly extracted from D, in the second one we use synthetic data with a uniform distribution, we expect that the second one have a larger distance than the first one
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251029151609.png]]

- and then **Calculate the Hopkins Statistic**: the sum of the synthetic object distances, divided by the distance of the real objects plus the distance of the synthetic objects
- we expect that the distance of the synthetic object is larger if there are real cluster, so it should tend to 1 if the data are not uniformly distributed, 0.5 if there are not cluster (and so the data are uniformly distributed)
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251029151638.png]]

- if D were *uniformly distributed*, then the two terms at the denominator would be close to each other and therefore H would be about **0.5**
- in presence of *clustering tendency*, the first term at the denominator would be smaller than the second and then H will increase to **1**


##### Assessing the results of the Hopkins statistic
  - **Null hypothesis**: the data set D is uniformly distributed (so there are no meaningful cluster)
  - **Alternative hypothesis**: the data set D *is not uniformly distributed* (and so it contains meaningful cluster)

- We compute the **Hopkins statistic** for *several random selection*, we compute the average of these results and obtain **H**, if H is larger than 0.75 it *indicates cluster tendency at 90% confidence level*
  


## Partitioning Methods
- **Partitioning methods**: partition a database *D* of *n* objects into a set of *k* clusters, such that the sum of the squared distances is minimized, having **ci** the **centroid or medoid** of the cluster *Ci*, we want to minimize:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251030092233.png]]
- it's the sum from i equal to 1 to the number of cluster k, of the sum for each object p that belongs to the cluster Ci of the squared distance between the point p and the centroid of the class ci (it basically want to minimize the cohesion of the cluster)


 - given *k* we want to find a partition of k cluster that optimize the chosen partition criterion, methods:
   - **Global methods**: this method exhaustively enumerate *all partition*
   - **Heuristic methods**: *k-means* (each cluster is represented by the center of the cluster) and *k-medoids or PAM (Partition Around Medoids)* (each cluster is represented by one of the object in the cluster) 

### The k-means clustering method
- **Centroid**: the mean value of the points within the cluster
- it takes in input *k* the number of cluster, and *D* a dataset with *n* objects (so we have to chose the number of clusters) 
- it return in output a set of k cluster
- Methods:
  1) choose k random object from D as the initial cluster centroid
  2) repeat:
     - assign each object to the cluster which the object is more similar, based on the similarity with the object with the centroid
     - update the cluster centroid as the new mean value of the cluster object
3) until no object change cluster

- example:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251030093122.png]]

- by choosing random initial centroids we have the risk to obtain a *local minimum* and not the global one, to handle this problem we can execute more time the algorithm with different initial point, and choose at the end the one that gives the best result
- there are some advanced technique to choose the initial centroid
- another problem is the choose of the *similarity measure*, it is typically the Euclidian distance, but by using this measure of similarity we have a bias that bring us to create *spherical clusters*
- some person use a weighted distance (because some attributes are more important), but in this way you can only have elliptical cluster, or *convex cluster*

- **Advantages**: it is an efficient algorithm (O(tnk)), and usually it terminates with a local optimum, where:
	n is # objects
	k is # clusters
	t is # iterations
- **Disadvantages**: 
  - can be applied only to continuous attribute (instead k-medoid can be applied to a wide range of data)
  - you need to *specify k* the number of cluster
  - sensitive to *noise and outlier* (the outlier are always assigned to a cluster and influence a lot the centroid value)
  - not good for cluster with a *non-convex shape*
  

### Determining the Number of Clusters
- **Bad method**: we can execute several way the k-means, store for each k the error rate and choose the best error rate, BUT even with the optimal number of cluster, by increasing k the error continue to decrease (e.g. with k=n, so a cluster for each point, the error will be zero)

- **Elbow method**: increasing the number of clusters can help to reduce the sum of within-cluster variance of each cluster
- that effect may drop if *too many* cluster are formed
- use *the turning point* in the curve of the sum of within cluster variance

- Given a number k > 0, use k on a clustering algorithm, calculate the sum of within cluster variance **var(k)** and plot the curve of var with respect of k, at the end *choose te k as the first or more significant turning point of the curve* (that point is called the elbow)
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251030093949.png]]
- it is also possible that the elbow is outside the considered axis (so for an higher value of k)

### Variation of the K-means Method
- Most of the variant of **k-means** differ is:
  - selection of the initial k centroid
  - dissimilarity calculations
  - strategy to calculate the mean

- **k-models** to handle *categorical data*:
  - replacing means of clusters with **modes** (because you can't compute the mean for categorical data)
  - using different dissimilarity measures
  - using frequency-based method to update modes of cluster

- to deal with a mixture of categorical and numerical data we can use **k-prototype method**

### K-Medoids 
- the k-means is too much *sensitive to outliers*
- one possible solution is to use the **K-medoids**, so instead of using the mean value we can use the **Medoid** of the cluster (*the most centrally located object in a cluster*). it has to be **an object of the dataset**
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251030094454.png]]


- in K-medoids initial representatives are chosen randomly
- the iterative process of replacing representative object by no representative object continues as long as the quality of the clustering is improved

- For each representative Object **O**, for each non-representative object **R**, swap **O** and **R** 
- at the end choose the configuration with the lower cost
- the cost function is the difference in absolute error-value if a current representative object is replaced by a non-representative object
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251030094908.png]]


##### K-Medoids method example
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251030094943.png]]
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251030094957.png]]
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251030095023.png]]
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251030095035.png]]
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251030095046.png]]
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251030095100.png]]

- thing that can happen when a medoid change:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251030095135.png]]
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251030095152.png]]


- the **K-Medoids** clustering method **PAM** (Partitioning Around Medoids) takes in input *k* the number of cluster, and *D* a sed that contains *n* object 
- it return a set of *k* cluster
- **Method**:
  1) choose randomly k medoids from D
  2) Repeat:
     4) for each medoids **Oi**
     5) select randomly a non representative object **Oj**
     6) compute **S** the total cost of *swapping Oi with Oj* and if S < 0, then replace Oi with Oj
 - stop if nothing changes

- The original PAM algorithm proceeds in two steps:
  - **Build step**: construct the initial medoids by minimizing the distance of the medoids with all the points of the cluster
  - **Swap step**: consider all possible object, and swap the medoids if the error decreases, stop only if there isn't any changes

- PAM depends on a dissimilarity between objects, the original PAM is computationally very heavy, but is less influenced by outlier
- it works well for small datasets, but *doesn't scale very well*

### CLARA (Clustering Large Application)
- **CLARA**: 
  - *Draw a sub-sample of the dataset* and apply PAM on the sample in order to find the medoids
  - if the sample is representative, then the medoids of the sample should approximate the medoids of the entire dataset
  - **Medoids are chosen from the sample**, so the algorithm cannot find the best solution if one of the best medoids is not in the sample
  - we can apply the algorithm to multiple samples and choose the better one
  - the accuracy of the clustering is measured by the average dissimilarity of all object in the entire dataset
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251030100502.png]]

- **Method**, for i=1 to *R*, repeat the following steps:
  - draw a sample of object from D and use PAM to find the k-medoids of the sample
  - for each object determine which of the k-medoids the object is the most similar with
  - calculate the dissimilarity measure *on the entire dataset*, if this value is less than the current minimum, use this value as the current minimum and retain the k-medoids

- **Advantages**: scale better than PAM
- **Disadvantages**: its performance depend on the sample size, is biased on the chosen sample
  
### CLARANS (Randomized CLARA)
- **CLARANS**: the clustering process can be presented as searching a graph where every node is a potential solution, and each node it is represented by a set of k medoids
- two nodes in the graph are *neighbor*, if they differ by only *one medoid*
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251030101122.png]]

- each node is associated with a cost that is defined to be the total dissimilarity between every object and the medoid of its cluster
- the problem consists in find the minimum on the graph
- in each step we calculate the value of each neighbor of the current node and we choose as next solution the nodes with the *deepest descent*

- for large n and k it requires a lot of time, at each step draws sample of  k(n‐k) neighbor to examine
- at the start it draws a sample of possible beginning nodes
- when a local optimum is found, it search another local optimum (the number of searched local optimum is a parameter)
- it is more efficient and scalable than PAM and CLARA
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251030101651.png]]


- CLARA restrict the research to a specific area of te original data
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251030101746.png]]

- CLARANS do not confine the search to a localized area
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251030101830.png]]
- the number of neighbors is chosen by the user (another parameter)

- in conclusion the clustering process can be presented as a searching a graph where every node is a potential solution, that is a set of k medoids
- two nodes are neighbors in the graph if their sets differ by only one object
  - *PAM* examines *all the neighbor* of the current node
  - *CLARA* draws *a sample of node* at the beginning of a search
  - *CLARANS* dynamically *draws a random sample of neighbors* in each step of research


## Hierarchical Methods
- **Hierarchical Clustering**: use a *distance matrix* as a clustering criteria, it doesn't need a number of cluster *k* ,but it needs a *termination condition*
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251101194847.png]]

- it can be:
  - **Agglomerative** (*AGNES*): cluster c1 and c2 can be merged if an object in C1 and an object in C2 form the minimum euclidean distance between any two objects from different clusters
  - **Divisive** (*DIANA*): a cluster can be split according to some principle (e.g. maximum euclidian distance between the closest neighbor)

- Hierarchical cluster usually deals with the **matrix of distances** (dissimilarities) or similarity between training samples

- it is usually called **connectivity matrix**
- to merge or split subset of points rather than individual points, the distance between individual points has to be generalized to the *distance between subset*. this kind of measure is called **linkage metric** and is constructed *from elements of the connectivity matrix*
- the type of the linkage metric used significantly affects hierarchical algorithms 


- the dissimilarity measure it is usually computed for every pair of points in the two sets
- Main inter-cluster *linkage metrics*:
  - **single link**: take the minimum distance
  - **average link**: take the average distance
  - **complete link**: take the maximum distance


-  **Single link**: the distance between two cluster is determined by the distance of the two closest object in different cluster
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251101200110.png]]


- **complete link**: the distance between two cluster is determined by the greatest distance between any two objects in the different cluster
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251101200225.png]]

- single and complete link can give very different results
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251101200407.png]]


- **pair-group average link**: the distance between two cluster is calculated as the average distance between all pairs of object in the two clusters
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251101200337.png]]


### Dendogram
- **Dendogram**: a tree structure used to *represent the process of hierarchical clustering*
- a clustering of the data object is obtained by cutting the dendogram *at the desired level*, then each connect component forms a cluster

- in any case with the hierarchical approach we obtain **convex-shaped clusters**

- measure of distance between classes:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251101200630.png]]
- the Mean distance is the distance between the centroids of the cluster


- **Nearest-neighbor clustering algorithm** when an algorithm uses the minimum distance to measure the distance between clusters (if agglomerative, they are also called *minimal spanning tree algorithm*)
	- **Single-linkage algorithm**: the clustering process is terminated when the minimum distance between the nearest cluster exceeds a user-defined threshold 

- **Farthest-neighbor clustering algorithm**: when an algorithm uses the maximum distance to measure the distance between cluster
	- **Complete linkage algorithm**: the clustering is terminated when the maximum distance between nearest clusters exceeds a user-defined threshold

- different dendogram with single linkage and complete linkage 
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251101200701.png]]


### AGNES (Agglomerative Nesting)
- **AGNES** use the *single-link method* and the dissimilarity matrix, initially, place each object into a cluster
- then clusters are merged according to some criterion 
- the cluster merging process repeats until all the objects are eventually merged to form one cluster

- *Single-linkage approach*: each cluster is represented by all of the object in the cluster, and the similarity between two clusters is measured by the similarity of *the closest pair* of data points belongings to different clusters

- AGNES example:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251101201358.png]]

- each step the algorithm merge all the pair with the *lowest dissimilarity* in the dissimilarity matrix, e.g. in the first step it merge A and B that have dissimilarity 1, and C and D that have dissimilarity 1  
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251101201350.png]]



### DIANA (Divisive Analysis)
- **DIANA**: it's the inverse of AGNES, eventually each node forms a cluster on its own, at the start they are all in the same cluster
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251101201743.png]]

- it starts with one large cluster containing all n samples, then cluster are divided until each cluster contains only a single sample
- at each stage it's selected the cluster with the largest dissimilarity between any two of its sample
- we divide the cluster by searching for the *most disparate sample* (the largest average dissimilarity to the other observations of the selected cluster). This observation initiates the "splinter group". In subsequent steps, the algorithm reassigns observations that are closer to the "splinter group" than to the "old party". The result is a division of the selected cluster into two new clusters

- Algorithm:
  1) find the object with the *highest average dissimilarity* to all the other object (this object will initiates a new cluster)
  2) for each object *i* outside the **splinter group** compute **Di** as the average distance between the object *i* and all the object *j* outside the splinter group, minus the average distance between the object *i* and all the object *j* inside the splinter group, minus the average  ![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251102104650.png]]
  3) find the object **h** for which the value **Dh** is the largest (so the object on average is the most dissimilar from the objects in the group), if Dh is positive, then h is on average close to the splinter group 
  4) repeat step 2 and 3 until all the Dh are negative, then divide the data in 2 cluster
  5) select the cluster with the largest diameter, the diameter is the *largest dissimilarity* between any two of its object, then divide this cluster by following step 1 to 4
  6) repeat step 5 until all cluster contains only a single object

![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251102104943.png]]

- (we are calculating the average dissimilarity with each of other points), the largest one is X1 that will be put in a new cluster
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251102104953.png]]

- now we recompute the average dissimilarity, without considering x1 that is now in another cluster, the point with the maximum distance is X2, that have a smaller distance with X1 than the average of the original cluster, so we move X2 in the X1's cluster
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251102105016.png]]

- we continue this process and find that X3 and X4 are also more similar to the other cluster
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251102105023.png]]

- we continue until we cannot move any new point in the other cluster
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251102105028.png]]

- we check now which cluster has the *largest diameter*, in this case it's the second cluster, that cluster will be split, to do so we apply the previous process and check the most dissimilar point with the other, in this case it's X4
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251102105038.png]]

- we check if the point in the second cluster are more similar to X4 or in average with the original cluster, in this case X3 is more similar to X4 so we move him
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251102105044.png]]

- we can continue this approach until all the point are a cluster
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251102105054.png]]

![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251102105101.png]]

### Pros and Cons of Hierarchical clustering 
- **Cons**:
  - you can never *undo* what was done previously
  - do not scale well, it require an O(n^2) time

- **Pro**:
  - you get a hierarchy instead of a collection
  - don't need to specify k (but you can obtain k groups if you stop the algorithm at k-1 cut)
  - give in general better quality cluster than k-means like method

- there are some extension that solve some of the hierarchical clustering problem:
  - **BIRCH**: uses a CF-tree and incrementally adjust the quality of the sub-cluster
  - **CHAMELEON**: it's a hierarchical clustering that exploit dynamic modeling (**NON è DA FARE QUEST'ANNO**)


### BIRCH
- **BIRCH** (*Balanced Iterative Reducing and Clustering Using Hierarchies*): it's an **agglomerative clustering** designed for clustering a large amount of numerical data
- most algorithm does not consider that dataset may be too large to fit in main memory, and do not concentrate on minimizing the number of scan of the dataset
- it use a *streaming* approach, and has a complexity of O(n) (n = number of object in the ts) 

- for each object it choose a *diameter*, having a new object, if the new object it's inside the diameter of one of the previous object it it added to the other object, if it doesn't fall in any diameter we create a *new cluster*
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251102105825.png]]

- here object 2 didn't fall in object 1's diameter, so we create a new cluster
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251102105831.png]]

- same thing for object 3
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251102105838.png]]
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251102105857.png]]

- here object 4 fall in 2's diameter, so we add him to 2's cluster
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251102105906.png]]

- if a cluster becomes too big we create a new level 
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251102105916.png]]

- the level has a split for each cluster of the old clustering 
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251102105935.png]]

![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251102105943.png]]



### BIRCH Key Components 
- **Clustering Feature**: It is used to compute centroids and measure the compactness and distance of clusters $$CF = (N,LS,SS)$$
- where:
  - N: number of data points
  - LS: linear sum of N points
  - SS: square sum of N points
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251102110327.png]]

- Example of computation of *CF*: 
- CF1 and CF2 are the CF for the leaf, CF3 is the total CF for the clustering, and is obtained by summing the leaf's CF
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251102110340.png]]

- **CF** entry is a summary of statistics of the cluster and has sufficient information to calculate the *centroids*, radius, diameter and many other measure

- *Centroids*: the middle of a cluster
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251102110639.png]]

- *Radius*: square root of the average distance from any point of the cluster to its centroid
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251102110725.png]]

- *Diameter*: square root of average mean squared distance between all pairs of points in the cluster
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251102110739.png]]

### BIRCH key components
- **CF-Tree**: *is a height-balanced tree that stores the clustering features* CFs for a hierarchical clustering

- parameters:
  - **B = Branching factor** specifies the maximum number of children per non-leaf node.
  - **T = Threshold parameter** specifies the maximum diameter of subclusters stored at the leaf nodes of the tree

- **L = Max. number of entries in a leaf** 
- **CF entry in parent** = sum of CF entries of a child of that entry

- whit this structure, we can update all continuously, and we also need less comparison, because we exploit the centroid of the parents nodes to add a new instance, we compare only the new point with a certain path
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251102111214.png]]
- leaf nodes are connected via *prev* and *next* pointers

- A leaf node represents a cluster
- a sub-cluster in a leaf node must have diameter *no greater* than a given threshold T
- a point is inserted into the leaf node (cluster) to which is closer
- when one item is inserted into a cluster at the leaf node, the restriction T must be satisfied (otherwise we create a new cluster), and the corresponding CF must be updated
- if there is *no space* on the node, then the node is *split*

### BIRCH algorithm
- The objective of **BIRCH** is to incrementally construct a CF tree, a hierarchical data structure for multiphase clustering 

- **Phase 1**: scan the DB to build an initial *in-memory* CF-tree
- if the *threshold* condition is violated:
  - if there in room to insert: insert point as a single cluster 
  - if not: insert the point into the closest cluster
    - **Leaf node split**: take two farthest CFs and create two leaf nodes, and put the remaining CFs (including the new one) into the closest node
    - update CF for non-leaf, insert new non-leaf entry into parent node
    - we may have to split parent as well (if we split the root, we have to increases the tree height by one)

- **Phase 2**: use a clustering algorithm to cluster the leaf nodes of the CF‐tree

![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251102112451.png]]
- it is important to *tune the threshold*, we can do this without scanning all the data objects again because we already have the CFs computed  

- **Phase 1**: scan DB to build an initial in‐memory CF tree, first you choose an initial value for the threshold, insert the data points one by one into the tree as per the insertion algorithm, if the size of the CF tree exceed the size of the available memory, increase the threshold value, and convert the partially built tree into a new tree (you construct the new tree form the leaf node of the old one so you don't need to reread all the objects). Repeat the above steps untile the entire dataset is scanned and a full tree is built (usually it is applied some Outlier handling technique)

- **Phase 2**: Builds a smaller CF tree by increasing the threshold

- **Phase 3**: Apply global clustering algorithm to the sub-clusters given by leaf entries of the CF tree for improve clustering quality

- **Phase 4**: Scan the entire dataset to label the data points and apply Outlier handling

### Pros and Cons of BIRCH
- **Pro**:
  - find a good clustering with a single scan, and improves the quality with a few additional scan, it has complexity O(n)

- **Cons**:
  - *Handles only numerical data* (because of LS and SS that cannot be computed for categorical data)
  - *Sensitive to the insertion order of data points*
  - Since we fix the size of a leaf node, *cluster may not be so natural*
  - *Clusters tend to be spherical* given the radius and diameter measure (but we can apply another algorithm after the leaf generation)

- it is stil used because of its data streaming capability

## Density-Based Methods
### Density-Based Clustering Methods

- Major features:
  - *Discover clusters of arbitrary shape* (but the shape depend usually on the algorithm parameters)
  - *Handle noise*
  - *One scan*
  - *Need density parameters as termination condition*

- Main techniques:
  - **DBSCAN**
  - **OPTICS** (used to determine the parameter for DBSCAN, not a real approach)
  - **DENCLUE**
  - **CLIQUE**

### Basic Concepts
- **Eps**: Maximum radius of the neighborhood
- **MinPts**: Minimum number of points in an Eps-neighborhood of that point

- so we are fixing how much point we are expecting in a zone to consider the zone dense
- by changing them we change the *idea of density*

- if the **Eps-neighborhood** (so a neighborhood with radius Eps - NEps) of an object contains at least a minimum number, MinPts of object, then the object is called **core object** 
- the point that are not core object are called *border points*

- example with eps=1cm and MinPts=3 
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251102152229.png]]


### Density-Reachable
- an object *p* is **Directly density-reachable** from an object *q*, with an certain Eps and MinPts, if:
    - p belongs to the Eps-neighborhood of q
    - q is a core object

- an object *p* is **Density reachable** from an object *q*, with an certain Eps and MinPts, if there is a *chain of object* (p1, p2, ...pn), with p1=q, and pn=p, such that pi+1 is *directly density-reachable* from pi
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251102153627.png]]
- q is density-reachable from p because q is directly density-reachable from m and m is directly density-reachable from p
- p is not density-reachable from q because q is not a core object

### Density-connected
- an object *p* is **Density-connected** from an object *q*, with an certain Eps and MinPts, if there is an object *o* such that both p and q are *density-reachable* from o 
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251102153755.png]]
- p, q and m are all density-connected




- Object *q* is (indirectly) **density-reachable** from *p* because *q* is **directly density** reachable from *m* and *m* is **directly density-reachable** from *p*. However, *p* is not **density reachable** from *q* because *q* is not a core object. Similarly, *r* and *s* are **density-reachable** from *o* and *o* is **density- reachable** from *r*. Thus, *o*, *r*, and *s* are all **density-connected**
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251102153934.png]]


### DBSCAN: Density-Based Spatial Clustering of Applications with Noise
- **DBSCAN** relies on a density-based notion of cluster
- a *cluster* is defined as a *maximal set of density-connected points*
- DBSCAN discovers clusters of arbitrary shape in spatial databases with noise
- border point: point that are in the neighborhood of a core point, but are not a core object
- outlier: objects that are not core objects nor border objects
- it is sensible to the *hyperparameters* Eps and MinPts  
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251102154335.png]]
- it search for cluster by checking the Eps-neighborhood of each object in the database
- if the Eps-neighborhood of an object p contains more than MinPts points, a new cluster with a core object is created
- DBSCAN iteratively collect directly density reachable objects from these core objects, this may involve the merge of a few density reachable cluster
- the process terminated when no new point can be added to any cluster

- DBSCAN adopts the *closure of density-connectedness* to find connected dense regions as clusters, each closed set is a density-based cluster

- a subset C in D is a cluster if:
  - for any two object *o1*, *o2* in C, *o1* and *o2* are density connected, and
  - there does not exist an object *o* in C and another object *o'* in D-C (outside C) such that *o* and *o'* are density-connected

### DBSCAN Algorithm
- Complexity: $O(n^2)$

- it takes in input:
  - *D*: a dataset with *n* objects
  - $\epsilon$: the radius
  - *MinPts*: the neighborhood density threshold

- it return as output a set of *density-based cluster*

- Method:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251102155349.png]]


- example of results:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251102155502.png]]
- the results are good only with the *right parameters*

- DBSCAN is **Sensitive to Parameters**:
- in the second example all the point not enough dense are seen as *noise* 
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251102155603.png]]
- so **How can we determine Eps and MinPts?**
- one of the problems is that we have to use the same value of MinPts and Eps for all the space, you cannot have different value for different zones

- if we have different densities for different zones of space we cannot really determine an optimal value for the parameters 
- it has also problems with *high* dimensions 


## How to determine Eps and MinPts
### Heuristic approach
- **Heuristic approach**: for a given *k*, we define a function k-dist, *mapping each point to the distance from its k-th nearest neighbor*
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251102155749.png]]

- in this approach we **fix MinPts** and try to determine the best *Eps* 
- we sort the point in descending order of their k-dist value
- the graph of this function gives some hints about the density distribution
- if we choose an arbitrary point *p*, and set the parameter *Eps* to *k-dist(p)* and *MinPts* to *k*, then all the points with an equal or smaller k-dist value will be core points
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251102160046.png]]
- the *threshold point* in the first point in the first valley of the sorted k-dist graph 

### OPTICS: The reason
- *Problem*: the intrinsic cluster structure cannot be characterized by a **global density** parameters (different zones with different clusters can have different density)
- the *first alternative* is to use a **hierarchical clustering algorithm** (e.g. the single-link method), but we have the problem of the *single-link effect*, e.g. cluster which are connected by a line of few points having a small inter-object distance are not separated, moreover the results are *hard to understand* for more than a few hundred points
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251102160125.png]]

- the *second alternative* is to use a **density based partitioning algorithm** with different parameter settings
- Cons:
  - there are *an infinite number of possible parameter values*
  - even if we use a very large number of values it is still *difficult to analyze the results*

- **Solution**: run an algorithm which produces a *special order* of the database with respect to its density-based clustering structure containing the information about every clustering level of the data set, and is *easy to analyze*
- OPTICS is not really a clustering algorithm, it helps to understand the best parameters for the clustering algorithm

### OPTICS: A Cluster-Ordering Method
- **OPTICS** (*Ordering Points To Identify the Clustering Structure*): produces a special order of the database with respect to its density-based clustering structure

- This cluster-ordering contains info equivalent to the density-based clustering corresponding to a broad range of parameter settings
- Good for both automatic and interactive cluster analysis, including finding intrinsic clustering structure


- density based clusters are *monotonic* with respect to the neighborhood threshold
- DBSCAN, for a constant MinPts value create *density-based clusters with respect to a higher density* are completely contained in density connected sets obtained with respect to a lower density
- C1 and C2 are density-based cluster with respect to eps2 < eps1 and C is a density-based cluster with respect to eps1 completely containing the sets C1 and C2
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251102162842.png]]

- **IDEA**: *process a set of distance parameter values at the same time* 
- In practice, to **use DBSCAN for an infinite number of distance** parameters *eps(i)* which are smaller than a “generating distance eps”
- Unlike DBSCAN, *OPTICS does not assign cluster memberships*. Instead, *it stores the order in which the objects are processed* and the information which would be used by an extended DBSCAN algorithm to assign cluster memberships (if this were at all possible for an infinite number of parameters)
- This information consists of only two values for each object: the **core-distance** and a **reachability-distance**


- **Core-distance of an object p**: the smallest Eps value that makes p a *core object*, if p is not a core object, the core-distance will be undefined

- **Reachability-distance of an object q** from p is the minimum radius value that makes q *directly density-reachable* from p
- p has to be a core object and q must be in the neighborhood of p
- so the reachability-distance from p to q is the max between the *core distance of p* and the distance of (p,q), if p is not a core object then, the reachability distance is undefined
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251102163514.png]]


- To construct the different partitions simultaneously, **the objects have to be processed in a specific order**:
  - OPTICS begins with an arbitrary object from the input database as the current object, p. It retrieves the eps-neighborhood of p, determines the core-distance, and sets the reachability-distance to undefined.
  - *If p is not a core object*, OPTICS simply moves on to the next object in the OrderSeeds list (or the input database if OrderSeeds is empty).
  - *If p is a core object*, then for each object q in the eps-neighborhood of p, OPTICS updates its reachability-distance from p and inserts q into OrderSeeds if q has not yet been processed.


- **The objects contained in OrderSeeds are sorted by their reachability-distance** to the closest core object from which they have been directly density reachable. In each step of the WHILE- loop, an object currentObject having the smallest reachability- distance in the seed-list is selected by the method OrderSeeds:next().
- The eps-neighborhood of this object and its core-distance are determined. Then, the object is simply written to the file OrderedFile with its core distance and its current reachability-distance.
- The iteration continues until the input is fully consumed and OrderSeeds is empty.

- At the end of the execution of OPTICS, **we have the list of objects in the order in which the objects themselves are processed**. (and not a cluster)
- Complexity: in the worst case, O(n^2), where n is the number of objects to be clustered. 
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251102163824.png]] the valley are dense region, the peak are separating zones
- in OPTICS the initial Eps is like an upper bound for the search


![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251102163932.png]]

![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251102163924.png]]

![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251102163916.png]]

![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251102163906.png]]

![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251102163859.png]]

![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251102163847.png]]

![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251102163838.png]]
 ![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251102163831.png]]
 
 
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251102163818.png]]

### DENCLUE: Using Statistical Density Functions
- the main problem of DBSCAN and OPTICS is that density is calculated by counting the number of objects in a neighborhood defined by eps. Such density estimates can be *highly sensitive to the radius value used*

- **DENsity-based CLUstEring**: is a clustering method based on a set of density distribution function
- each observed object is treated as an *indicator of high-probability density in the surrounding region*
- the probability density at a point depends on the distances from this point to the observed objects 
- Let x1, x2, ...xn be an independent and identically distributed sample of a random variable f, the kernel density approximation of the probability density function is:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251103153445.png]]

- **Kernel K()** is a non-negative real-valued integrable function that should satisfy *two requirements* for all values of *u*: **non negative** and **symmetric** 
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251103153551.png]]

- example of a kernel function:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251103153604.png]]

- example of the density of a gaussian kernel :
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251103153638.png]]

- examples of overall density function:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251103153714.png]]
(it changes with different kernel)

- cluster can be determined mathematically by identifying **density attractors** (local maxima of the estimated density function)
- to avoid trivial local maximum points, DENCLUE uses a noise threshold $\epsilon$ and only consider those density attractors x* such that are greater than epsilon
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251103153913.png]]

- these attractors are the *centers of a cluster*, they can be found with an hill climbing of the function
- *objects are assigned to clusters through density attractors using a step-wise hill-climbing procedure*

##### DENCLUE Algorithm 
- Until there exist samples in the data set:
  - select a sample *x*, the *density attractor* of x is computed by using the *hill-climbing* procedure ![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251103154125.png]]
  - where $\delta$ is a parameter to control the speed of convergence, d is the space dimension and K the Gaussian:![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251103154303.png]]
  - the hill-climbing procedures stops at k>0 if  $f(x^{k+1}) < f(x^{k})$ and assign *x* to the *density attractor* $x^* = x^k$ 

- For efficiency reasons, the algorithm stores all points *x’* with $d(xj, x’)<=h/2$ (h is the standard deviation of the gaussian function) for any step $0 < j < k$ during the hill-climbing procedure and attaches these points to the cluster of x* as well. Using this heuristics, all points which are located close to the path from x to its density-attractor can be classified without applying the hill- climbing procedure to them.

- An object x is **an outlier or noise** if it converges in the hill-climbing procedure to a local maximum x* with a value of the probability density function smaller than xi:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251103154502.png]]


- example of density attractor:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251103154614.png]]

##### DENCLUE: Arbitrary shaped clusters
- **Arbitrary shaped cluster**: merge density attractors that are connected through paths of high density (with the density greater than the threshold)
- an *arbitrary shaped cluster* (with respect to two constant *h* and $\epsilon$) for the set of density attractors X, is a subset C (subset of D), where:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251103154825.png]]

- based on the fixed variance **h** we have a different interlapping between gaussian
- also $\xi$ is a critical parameter, it define what is or not an outlier
- Examples:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251103154836.png]]

##### DENCLUE Main Features
- **Major features**:
  - *solid mathematical foundation*
  - good for data sets with *large amount of noise*
  - allow a *compact mathematical description* of arbitrarily shaped clusters in high-dimensional data sets 
  - faster, and with a complexity of O(N log(N))

- **Main problem**: needs an *accurate choice of the parameters h and $\epsilon$*
  - *h* determines the influence of a point in its neighborhood
  - $\epsilon$ describes whether a density-attractor is significant, allowing a reduction of the number of density-attractors and helping to improve how the parameters should be chosen to obtain good results

##### DENCLUE: Choice of the parameters
- **Suggested choice for h**: consider different h and determine the largest interval between hmax and hmin where the number of density attractors m(h) *remains constant*, so the wider horizontal step
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251103155546.png]]

- **Suggested choice for $\epsilon$**: if the database is noise free, all density attractors of D are significant and $\epsilon$ should be chosen between zero and the smallest value of te function for the attractors points
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251103155541.png]]

##### DENCLUE: Implementation
- it is divided in **Two steps**:
  - Initial pre-clustering based on a grid to speed up the calculation of the density function
  - Actual clustering

-  **Step 1**:
  - The *minimal bounding (hyper-)rectangle of the data set is divided into d-dimensional hypercubes*, with an edge length of **2h** 
  - Only hypercubes which actually contain data points are determined
  - The hypercubes are numbered depending on their relative position from a given origin. The keys of the populated cubes can be efficiently stored in a randomized search-tree or a B+-tree
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251103155820.png]]
- **For each populated data cube c**, in addition to the key, the number of points *Nc* (number of points in a data cube c) witch belong to c, pointers to those points, and the linear sum of all the x that belong to C is stored
- this information is used in the clustering step for a fast calculation of the mean of a cube, *mean(c)*, since clusters can spread over more than one cube neighboring cubes which are also populated have to be accessed
- to speed up this access, *we connect neighboring populated cubes*, more formally two cubes c1 and c2 that belongs to Cp, are *connected* if $d(mean(c1), mean(c2)) < 4 \sigma$ (we use a Gaussian kernel function and therefore h=$\sigma$)



- **Step 2**: *the clustering step*
- only the  highly populated cubes **Csp** and cubes which are connected to a highly populated cube are considered in determining clusters
- *Csp* is a subset of Cp determined as:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251103161059.png]]
- for x that belong to c, and (c,c1) that belongs to *Cr* ,we set *near(x)* equal to the points x1 that belongs to c1 such that the mean of c1 and x, are less or equal than k by $\sigma$ and exists a connection between c1 and c
- the limit $k \sigma$ is chosen such that only marginal influences are neglected. a value $k=4$ is sufficient for practical purposes

- the resulting **local density function** is equal to:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251103161103.png]]

- the **density attractor for a point x** is computed as:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251103161109.png]]

- the computation **stops at k** that belongs to N if:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251103161114.png]]

- and takes as the **new density-attractor**:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251103163459.png]]


##### DENCLUE versus DBSCAN
- implementation: adopts an initial pre-clustering based on a grid to speed up the calculation of the density function and a local density function
- DENCLUE is much faster than DBSCAN
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251103161120.png]]


### Density-based clustering
- **NOTE**: all the density-based clustering methods *are not fully effective when clustering high dimensional data*
- Methods that rely on near or nearest neighbor information do not work well on high dimensional spaces.
- In high dimensional data sets, it is very unlikely that data points are nearer to each other than the average distance between data points because of sparsely filled space.
- As a result, as the dimensionality of the space increases, the difference between the distance to the nearest and the farthest neighbors of a data object goes to zero. 




## Grid-Based Methods
- **Grid-Based Methods** uses a *multi-resolution grid data structure*
- Main methods:
  - *STING*
  - *CLIQUE* (both grid-based and subspace clustering)

- In general *the spatial area is divided into rectangular cells*
- there are several levels of cells corresponding to different level of resolution
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251103161201.png]]


### The STING Clustering Method
- in the **STING** methods, each cell at a high level *is partitioned into a number of smaller cells* in the next lower level
- *statistical info of each cell is calculated and stored beforehand* and used to answer queries
- parameters of higher level cells can be easily calculated from parameters of lower level cell

- parameter include: 
  - count, mean, sd, min, max
  - type of distribution (normal, exponential, uniform, none), obtained by the user or by an hypothesis test
- it use a **top-down** approach to answer spatial data queries

- example of the hierarchical structure of the layers:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251103161220.png]]

- *Statistical information* regarding the attributes in each grid cell, for each layer  are *pre-computed and stored before hand*
- the statistical parameters for the cells in the lowest layer is computed directly from the values that are present in the table when data are loaded in the database
- the *statistical parameters for the cells in all the other levels are computed from their respective children cells* that are in the lower level

- **Query types**:
  - SQL-like language is used to describe queries
  - the two main types of queries are: find a region specifying some constraints, and take in a region a return some attribute of the region

- **Query Processing**:
  - we use a *top-down* approach to answer spatial data queries
  - we start from a pre-selected layer-typically with a small number of cells

- the pre-selected layer does not have to be the top most layer
- for each cell in the current layer, compute the confidence interval (or estimated range of probability) reflecting the cell's relevance to the given query
- the confidence interval is calculated by using the statistical parameters of each cell
- from the interval calculated, we label the cells as relevant or irrelevant for this query
- **Remove the irrelevant cells from further consideration**

- When finished with the current layer, proceed to the next lower level
- Processing of the next lower layer *examines only the remaining relevant cells*
- Repeat this process until the bottom layer is reached
- At this time if query specifications are met, the *regions of relevant cells that satisfy the query are returned*
- Otherwise, the data that fall into the relevant cells are retrieved and further processed until they meet the requirement of the query


- example of a typical query:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251103161229.png]]

- example of returned regions:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251103161236.png]]


##### Advantages and Disadvantages of the STING approach
- **Advantages**:
  - query-independent
  - easy to parallelize
  - incremental update
  - complexity of the clustering generation of O(n)
  - complexity of the query processing time of O(g), where g is the number of grid cells at the lowest level


- **Disadvantages**: all the cluster boundaries are either horizontal or vertical, *no diagonal boundary is detected*



- The regions returned by STING are an *approximation of the result by DBSCAN*. As the granularity approaches zero, the regions returned by STING approach the result of DBSCAN
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251103161311.png]]




### CLIQUE (Clustering In QUEst)
- **CLIQUE (Clustering In QUEst)**: automatically identifying subspaces of a high dimensional data space that allow better clustering than original space
- can be considered both a *density-based* and a *grid-based* approach
  - it partitions each dimension into the same number of equal length intervals
  - it partitions an m-dimensional data space into non-overlapping rectangular units
  - **A unit is dense if the fraction of total data points** contained in the unit exceeds the input model parameters
     ![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251103161320.png]]
  - a **cluster** is a maximal set of connected dense unit within a subspace
    ![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251103161339.png]]

##### CLIQUE Steps
- Partition the data space and find the number of points that lie inside each cell of the partition

- identify the subspaces that contains clusters *using the Apriori principle* 
	 - If a k-dimensional unit is dense, then so are its projections in (k-1)-dimensional space. Therefore, the candidate dense units in the kth-dimensional space are generated by the dense units found in (k-1)-dimensional space
  - so if we have a unit dense with k dimension, all its projection with k-1 dimension are dense as well (a lot of points in 3d if projected in 2d will still be a lot of points)

- Identify clusters
  - Determine dense units in all subspaces of interests
  - Determine connected dense units in all subspaces of interests 

- Generate minimal description for the clusters
  - Determine maximal regions that cover a cluster of connected dense units for each cluster
  - Determination of minimal cover for each cluster

### CLIQUE: The algorithm
- CLIQUE is divided in *two steps*

- **first step**: *partitions* the d-dimensional data space into nonoverlapping rectangular units, and *identifying* the dense units among these

- CLIQUE partitions every dimension into intervals, and identifies intervals containing at least *l* points, where *l* is the density threshold

- CLIQUE then iteratively joins two k-dimensional dense cells, c1 and c2, in subspaces (Di1 , … , Dik) and (Dj1 , … ,Djk), respectively, if Di1 = Dj1 , . . . , Dik-1=Djk-1, and c1 and c2 share the same intervals in those dimensions. The join operation generates a new (k+1)-dimensional candidate cell c in space (Di1 , … , Dik ,Djk)
- CLIQUE checks whether the number of points in c passes the density threshold. The iteration terminates when no candidates can be generated or no candidate cells are dense.



- **second step**: CLIQUE uses the dense cells in each subspace to assemble clusters, which can be of arbitrary shape.
- Minimum Description Length (MDL) principle: use the maximal regions to cover connected dense cells, where a maximal region is a hyperrectangle where every cell falling into this region is dense, and the region cannot be extended further in any dimension in the subspace.

- Finding the best description of a cluster in general is NP-Hard. Thus, CLIQUE adopts a simple greedy approach. It starts with an arbitrary dense cell, finds a maximal region covering the cell, and then works on the remaining dense cells that have not yet been covered.

- The greedy method terminates when all dense cells are covered

### CLIQUE Example 
- if we want to cluster a set of records that have attributes salary, vacation and age
- we will have a 3-dimensional data space
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251103161348.png]]


- After plotting the data objects, each dimension (i.e., salary, vacation and age) is split into intervals of equal length

- Then, we form a 3-dimensional grid on the space, each unit of which would be a 3-D rectangle
-  Now, our goal is to find the dense 3-D rectangular units
-  To do this, we find the dense units of the subspaces of this 3-d space
-  So, we find the dense units with respect to age for salary. This means that we look at the salary-age plane and find all the 2-D rectangular units that are dense
 
- We also find the dense 2-D rectangular units for the vacation-age plane
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251103161403.png]]


- Now let us try to visualize the dense units of the two planes on the
following 3-d figure:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251103161409.png]]

- We can extend the dense areas in the vacation-age plane inwards
- We can extend the dense areas in the salary-age plane upwards
- The intersection of these two spaces would give us as candidate search space in which 3-dimensional dense units exist
- We then find the dense units in the salary-vacation plane and we form an extension of the subspace that represents these dense units


- Now, we perform an intersection of the candidate search space with the extension of the dense units of the salary-vacation plane, in order to get all the 3-d dense units

- So, what was the main idea?
  - We used the dense units in subspace in order to find the dense units in the 3-dimensional space
  - After finding the dense units, it is very easy to find clusters



### Strength and Weakness of CLIQUE
- **Strength**:
  - automatically finds subspaces of the highest dimensionality such that high density clusters exist in those subspaces
  - insensitive to the order of records in input and does not presume some canonical data distribution
  - scales linearly with the size of input and has good scalability as the number of dimensions in the data increases


- **Weakness**:
   - Obtaining a meaningful clustering is dependent on proper tuning of the grid size and the density threshold
   - The accuracy of the clustering result may be degraded at the expense of simplicity of the method

- grid based are useful because they are really fast

## Evaluation of Clustering
- **Assessing clustering tendency**: clustering analysis on a data set is meaningful only when there is a *nonrandom structure in the data*

- it is important to *determine the number of cluster in a dataset*

- way to *measure clustering quality*:
  - measures to asses how well the clusters fit the dataset 
  - measures that score clustering and thus can compare two sets of clustering results on the same dataset


### Determining the Number of Clusters
##### Elbow method
- **Elbow method**: increasing the number of clusters can help to reduce the sum of within-cluster variance of each cluster
- the marginal effect of reducing the sum of within-cluster variances may drop if too many cluster are formed, because splitting a cohesive cluster into two gives only a small reduction

- use the **Turning point** in the curve to sum of within cluster variance 

- Methods: 
  - given a number of cluster k>0
  - form k cluster on the data set in questioning using a clustering algorithm like k-means
  - calculate the *sum of within-cluster variances* **var(k)**
  - plot the curve of var with respect to k
  - choose k as the first or *most significant* turning point of the curve
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251103161421.png]]

##### Cross validation method
- divide a given data set into *m* parts
- use m-1 parts to obtain a clustering model
- and the remain part ot test the quality of the clustering

- E.g., For each point in the test set, find the closest centroid, and use the sum of squared distance between all points in the test set and the closest centroids to measure how well the model fits the test set

- for any k>0 repeat it *m times*, compare the overall quality measure for the different k, and find the number of cluster *that fits the data the best*




### Measuring Clustering Quality
- To **measure the clustering quality** there are two methods:
  - **Extrinsic** (*supervised*): the real labels are available, compare the clustering against the real label using some clustering quality measure (e.g. BCubed precision and recall metrics), it is used to shows that a new clustering algorithm is good in paper
  - **Intrinsic** (*unsupervised*): the real labels are not available, it evaluate the goodness of a clustering by considering how well the clusters are separated and how compact they are (e.g. silhouette coefficient)

##### Extrinsic Methods
- Clustering quality measure: **Q(C, Cg)**, for a clustering *C* given the ground truth *Cg*
- **Q** is good if it satisfies the following 4 essential criteria:
  - *Cluster homogeneity*: the purer, the better
  - *Cluster completeness*: should assign objects belong to the same category in the ground truth to the same cluster
  - *Rag bag*: putting a heterogeneous object into a pure cluster should be penalized more than putting it into a rag bag (i.e., “miscellaneous” or “other” category)
  - *Small cluster preservation*: splitting a small category into pieces is more harmful than splitting a large category into pieces




- **BCubed precision and recall**:
  - Evaluates the precision and recall for every object in a clustering on a given data set according to ground truth.
  - The *precision* of an object indicates how many other objects in the same cluster belong to the same category as the object.
  - The *recall* of an object reflects how many objects of the same category are assigned to the same cluster
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251103161438.png]]

- **BCubed precision and recall**:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251103161446.png]]
- they are used to check for *conflict match*, they try to evaluate how much the clustering results match the domain knowledge, the clusters are not evaluated in term of separation
- they can be used only if you know the real label (ground truth)

##### Intrinsic Methods
- When the ground truth is not available, we have to use an *intrinsic method to assess the clustering quality*
-  Intrinsic methods evaluate a clustering by examining how well the clusters are **separated** and how **compact** the clusters are.

 - **Silhouette coefficient**:
   - For each object o in D:
    - *compute a(o)* as the average distance between o and all the other objects in the cluster to which o belongs to
    - *Compute b(o)* as the minimum average distance from o to all clusters to which o does not belong to, we take only the smaller distance from b and one of the other cluster (is not the average distance with all the cluster, just one, the nearest one, and we consider the sum of the distance from o to all the point of that cluster)
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251103161453.png]]



- Silhouette coefficient of **o**:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251103161458.png]]
- The value of the silhouette coefficient is between -1 and 1. *The smaller the value of a(o), the more compact the cluster*


-  When s(o) approaches 1, the cluster containing o is compact and o is far away from other clusters, which is the preferable case
- When the silhouette coefficient value is *negative* (i.e., b(o) < a(o)), this means that, in expectation, o is closer to the objects in another cluster than to the objects in the same cluster as o. This is a bad situation and should be avoided.

 - To measure a cluster’s fitness within a clustering, we can compute the average silhouette coefficient value of all objects in the cluster
- To measure the **quality** of a clustering, we can use the *average silhouette coefficient value of all objects in the data set*

- **NOTE**: it works well only with *convex cluster* (circular like), so it can be applied only to the output of some algorithms, it cannot applied to concave cluster, like the one created by DBSCAN

## Summary
- *Cluster analysis* groups objects based on their *similarity* and has wide applications
- Measure of similarity can be computed for **various types of data**
- Clustering algorithms can be **categorized** into *partitioning methods*, *hierarchical methods*, *density-based methods*, *grid-based methods*, and *model-based methods*
- **K-means** and **K-medoids** algorithms are popular *partitioning-based* clustering algorithms
- **Birch** and **Chameleon** are interesting *hierarchical clustering* algorithms, and there are also probabilistic hierarchical clustering algorithms
- **DBSCAN**, **OPTICS**, and **DENCLU** are interesting *density-based* algorithms
- **STING** and **CLIQUE** are *grid-based methods*, where CLIQUE is also a subspace clustering algorithm
- *Quality* of clustering results can be *evaluated* in various ways 





# 6 Mining Frequent Patterns, Association and Correlations: Basic Concepts and Methods
## Basic Concepts
### What Is Frequent Pattern Analysis?
- **Pattern**:
  - a *set of items* which appear together in a **transaction data set** (e.g. milk and bread) 
  - A *subsequence* (e.g. buy first a PC then a memory card)
  - A *substructure* refers to different structural forms (subgraphs, subtrees)

- **Frequent pattern**: a pattern that occurs frequently in a data set

- **Frequent Pattern Analysis**: find and analyze *Frequent pattern*


- **Motivation**: Finding regularities in data
  - What products were often purchased together?
  - What are the subsequent purchases after buying a PC?
  - What kinds of DNA are sensitive to this new drug?
  - Can we automatically classify web documents?
  (we do not consider the quantity of items in a transaction or the price of the items)

### Why Is Freq. Pattern Mining Important?
- **Itemset I**: A set of one or more items {I1, I2, …, Im}, in most of cases the order of items is not meaningful, but they are considered alphabetically ordered for computational reason (is a set of a set of item)

- **k-itemset X = {I1, I2, …, Ik}**, a set of k itemsets $Ij$ (is a set of k item)

- **(absolute) support, or, support count of X**: Frequency or occurrence of an itemset X, it's the number of transaction where X appears (e.g. beer appears in 3 rows)

- **(relative) support s**: fraction of transactions that contains X (i.e., the probability that a itemset contains X), it's the number of itemsets where X appears divided by the number of itemsets (e.g. beer appears in 60% of the rows)

- *An itemset X is frequent if X’s absolute support is no less than a minsup threshold*, it's the minimum time that X has to appear in the dataset to be considered frequent 

![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251112113022.png]]

- **Transaction T**: set of items subset of I (is one row of a transaction dataset)

- So the *Transaction* refers to the analyzed data, *Itemset* are general set used in algorithms

 - An **association rule** is an implication of the form X => Y, where
   - X is a subset of $I$ 
   - Y is a subset of $I$
   - X and Y have no common elements

- **Support of X => Y in the transaction database D**: percentage of transactions in D that contain $X U Y$ (the percentage of transaction that contains X and Y together)
- **Supp (X => Y)** = $P(X U Y)$ = probability that a transaction contains $X U Y$, it express the relevance of the rule
- **Conf (X => Y)** = $P(Y | X)$ = $\frac{supp(X U Y)} {supp(X)}$ = conditional probability that a transaction having X also contains Y, it's the probability to have the realization of the rule having the antecedent, is equal to the number of times that x and y appears together, divided by the times that x appears in the dataset 

- having a confidence equal to 1 doesn't mean that the items are correlated, e.g. in the case that Y appears everywhere 

 
 - Each item has a *boolean variable* representing the presence or absence of that item
 - Each basket can be represented by a **Boolean vector** of values assigned to these variables
 - Boolean vectors analyzed for buying patterns that reflect items that are frequently associated or purchased together

- **Example:
  - Computer =>antivirus
    [support=2%, confidence =60%]
	- *Support* -> reflects usefulness of the rule (in the 2% of all transactions, purchased together).
	- *Confidence* -> reflects certainty about the rule (60% of the customers who purchased a computer also bought the software)

- we want to find all the itemsets over a certain min_sup and min_conf 


### Why Is Freq. Pattern Mining Important?
- Find all the rules X => Y with minimum support and confidence
- Let **minsup** = 50%, **minconf** = 50%
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251112185800.png]]

- Freq. *itemsets*: Beer:3, Nuts:3, Diaper:4, Eggs:3, {Beer, Diaper}:3

- Association rules:
  - Beer => Diaper (60%, 100%)
  - Diaper => Beer (60%, 75%)

- the support is the same, the confidence can change
- so in the 60% of the transaction there are beer and diaper together, the 100% of time that in a transaction there is beer, a diaper will be buy, in the 75% of the transaction where there are a diaper, beer will be buy 


### Association rule, a two-step process
- association rule mining can be viewed as a two-step process:
  - Find all frequent itemsets: an itemset that appear at least minsup times
  - Generate association rules from the frequent itemsets, that satisfy minsup and minconf


### Association rule, some definition
- A **long itemset** contains a *combinatorial* number of sub-itemsets,
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251112190518.png]]
- we cannot consider so many sub-itemsets, but there are algorithms to improve this

- An itemset X is **closed** in a dataset D if X is frequent and there exists no *super-itemset* Y כ X, with the same support as X (e.g. if i have the itemset $I' = {i1,i2}$ with support 50%, and a second itemset $I'' =\{i1,i2,i3\}$ also with support 50%, then $I'$ is not closed, in the case that $I''$ have a lower support than $I'$, then they can be both closed, and *it is not possible* that $I''$ has an higher support than $I'$). 
- You have to **return only closed itemset**, all its subset will have the same support as it or greater
- An itemset X is a **max-itemset** in a dataset D, if X is frequent and there exists no frequent *super-itemset* Y כ X 

- a **closed itemset** it's a lossless compression of the frequent pattern that allow to reduce the number of patterns and rules



- Let $C$ be the set of *closed frequent itemsets* for a data set D satisfying a minimum support threshold, min_sup
- Let $M$ be the set of *maximal frequent itemsets* for D satisfying min_sup

- Suppose that we have the support count of each itemset in C and M
- Notice that C and its count information can be used to derive the whole set of frequent itemsets
- Thus, we say that C contains complete information regarding its corresponding frequent itemsets


### Exercize
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251112191033.png]]
- the set of closed frequent itemsets contains complete information regarding the frequent itemsets
- For instance, from C , we can derive {a2, a45 : 2} 
-  From D, we can only infer that {a2, a45 : 1} and we are losing information because we don't know that some itemset have support 2


### Computational Complexity of Frequent Itemset Mining
- The number of itemsets generated depends to the minsup threshold, the lower it is, the higher number of itemsets 
- In the worst case we can have $M^N$ itemset, with $M$ the number of distinct items, and $N$ the max length of a transaction 

- Itemsets with more objects have a lower probability to appears 

### Scalable Frequent Itemset Mining Methods
- **Apriori**: A Candidate Generation-and-Test Approach
- **FPGrowth**: a frequent pattern-growth approach
- **ECLAT**: frequent pattern analysis with *vertical data format* approach


### The Downward Closure Property and Scalable Mining Methods
- **Downward closure property**: any nonempty subset of a frequent itemset, must also be frequent (e.g. If {beer, diaper, nuts} is frequent, so is {beer, diaper}, because it is contained in the first)
- **antimonotonicity**: category of property in which if a set cannot pass a test, all its superset will fail the same test (so a property that is monotonic in failing a test)

### Apriori: A Candidate Generation & Test Approach
- **Apriori principle**: if there is any itemset which is infrequent, then its superset will be infrequent and so it shouldn't be generated or tested

- Method: 
  - initially scan the DB once and get the *frequent 1-itemset*
	  - generate the $k+1$ **candidate** itemset from the length $k$ frequent itemset (so generate *candidate* frequent itemset fo length k+1, from frequent itemset of length k)
	  - test the candidate and save the frequent itemset those who pass the test
	  - stop if you cannot generate any more frequent or candidate itemset, if you can increase k an return to step 2
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251112193252.png]]
- the order or the items in the transaction doesn't matter, for this reason we have the itemset {A, B} and we don't need to have {B, A}
- we don't even compute the support for the transaction {A, B, C} because one of its subset {A, B} isn't frequent, so the superset cannot be frequent
- we stop the algorithm because we have only one itemset so we cannot combine nothing

### Apriori Pseudo Code
- with:
  - $Ck$ = candidate itemset of size k
  - $Lk$ = frequent itemset of size k
```python
L(1) = frequent single items
for(k=1, L(k) != Null, k++):
   C(k+1) = candidates generated from L(k)
   Count the number of transaction in C(k+1) in the DB
   L(k+1) = candidates in C(k+1) greater than min_support
return L 
```



- **lexicographic order**: one item of the array is lower than the following items (l(i) < l(i+1))


- **join step**: to find the candidate Ck to be insert in Lk, we make Lk-1 **joining itself** where the first $k-2$ members are in common (so between item that differ only in the last element). we assume that item are in a *lexicographic order*
- so the first k-2 members are the same, and the last element of l1 is lower than the last element of l2 (this ensure to maintain a lexicographic order)
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251112194257.png]]
- result:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251112194449.png]]

- **prune step**: we remove all the non-frequent itemsets obtained from the combination at the previous step, so we check if its subset of less element are all frequent element as a initial filter, then we will check its real support scanning the graph
- if one of its subset is not frequent, it will be not frequent as well so we don't need to scan the database 


### Example of the priori algorithm 
- assume to have min_sup = 2

- transactions:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251112194638.png]]

- select all the single item that appear more than min_sup (=2) times:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251112194711.png]]

- genera i candidati facendo il cross product tra gli elementi, conta quante volte appaiono nel dataset e filtra quelli che appaiono meno di minsup volte:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251112194824.png]]

- min_sup is a given constant, it is not an hyper-parameter to tune, the higher it is the faster is the execution, but the less frequent itemset you will find

### The Apriori Algorithm
- find frequent itemset using an iterative approach based on candidate generation
- input: D (the database of transaction), min_sup (the minimum support)
- output: L (the frequent itemset in D)

- Code:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251112195034.png]]
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251112195120.png]]

### Generating Association Rules from Frequent Itemsets
- Generate **association rules** from *frequent itemset*:
  - for each itemset $I$, generate all nonempty subsets of $I$
  - for each subset of $I$, for each subset $s$ of $I$, give in output the rule $s => I-s$  if $$\frac{support\_count(I)}{support\_count(s)} >= min\_conf$$ and the confidence of this rule will be:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251112195704.png]]

- this kind of rule (association rule) is important because we will understand the relation between antecedent (a certain item) and consequent (some item that will be buy because i have bought the antecedent). the confidence tell us how strong is this relationship 

### Some consideration
- we usually fix also a minimum value for the confidence of a rule

- the disadvantage of the **support** is the *rare item problem*, so data that occurs infrequently are pruned even if they would produce good rules (this is important in imbalanced datasets)
- a problem with **confidence** is that is *sensitive* to the frequency of the *consequent* in the database, consequents with higher support will produce higher confidence even if there exists no association between the items. 
- for this reason the confidence is *not a correlation measure*
- we need new metrics to resolve this problem


## Improving the Efficiency of Apriori
- Any itemset that is potentially frequent in the DB will be frequent in at least **one of its partition**

- Idea:
  - partition the database and find *local* frequent patterns, combine then all the local frequent patterns to create a *candidate itemset*
  - consolidate *global* frequent patterns
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251112200314.png]]
### DHP: Reduce the Number of Candidates
- during the scanning to find the singles most frequent items (L1), we can generate also all the 2-itemsets Ck

- For each transaction, map the transaction in different buckets of a hash table structure and increase the corresponding bucket counts
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251112200720.png]]

- A k-itemset whose corresponding hashing bucket count is below the threshold cannot be frequent
- example:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251112201019.png]]

### Bottlenecks of the Apriori approach
- Apriori use a **breath-first search** that generate a huge amount of candidate sets, the generation of candidate itemsets is expensive in time and memory
- If there are $10^4$ frequent 1-itemsets, the Apriori algorithm will need to generate more than $10^7$ candidate 2-itemsets

- Moreover support counting is expensive, and need to perform multiple database scans


## Pattern-Growth Approach 
- the **Frequent Pattern-Growth Approach** mine frequent patterns *without candidate* generation
- It is composed by two steps:
  1. Build a compact data structure called the **FP-tree**
  2. Extracts frequent itemsets directly from the FP-tree

- It uses sa *Depth-first* search
- It has a *Major philosophy*: it grows long patterns from short ones using local frequent items only
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251123205430.png]]

### FP-Tree Construction (General info)
- First, it *compresses the database* representing frequent items into a frequent pattern tree (FP-Tree)
- Then it *divide* the compressed database into a set of *conditional database* (a projection), each associated with one frequent item of "pattern fragment", and mines each database separately 

- It examine only the data sets associated at each **pattern fragment**, this reduce the size of the data examined


### Step 1: FP-Tree Construction
- The FP-Tree construction is divided in two passes
- **Pass 1**: 
  - scan the data and find the support for each item
  - discard all the infrequent items
  - sort frequent items in decreasing order based on their support (save the order for Pass 2), in this way we can exploit common prefixes

- **Pass 2**:
  - Nodes in the tree correspond to items and have a *counter*
  - FP-Growth reads 1 transaction at a time and maps it to a path
  - The fixed order defined in Pass 1 is used, so paths can **overlap** when transaction *share items* (and in this case counters are incremented)
  - Pointers are maintained between nodes containing the same item, creating *singly linked lists* (**dotted lines**), the more paths overlap, the higher the compression
  - Frequent itemsets are extracted from the FP-Tree

- The item i can point with a dotted line to another element is in another path to its right, because item are order by their support, we increase the probability to have shared item and so to compress the Tree 
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251123210427.png]]

- The FP-Tree usually has a smaller size than uncompressed data because many transactions share items
- **Besta case scenario**: all transaction contain the same set of item, so there is just 1 path in the tree
- **Worst case scenario**: every transaction has a unique set of item (so they have no item in common), in this case the size of the tree is basically the same as the original data, but it require more storage because you need to store the pointers between nodes and counters

- The *size* of the FP-Tree depends on how the items are ordered, usually ordering by *decreasing support value* lead to a small tree, but not always the smallest
- but we are not interested in the smallest tree 
- whatever method ordering you use, you will find the same transaction, the only thing that changes is the tree size



### Step 2: Frequent Itemset Generation
- **FP-Grow** extract frequent itemsets form the FP-Tree
- It is a *bottom-up* algorithm (it starts from the leaves and goes to the root), and use a divide and conquer paradigm. so it start from the items with the lowest support (the leaf) and find all the transaction that ends with that item, and then climb the tree and find all the path that ends with the item of the path in the leaf
- First, **extract prefix path sub-trees** ending in an item (or itemset)

- **Prefix path sub-trees Example**:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251123210503.png]]
- e.g. we are seeing all the transaction that ends with a specific leaf and then the transaction that ends with the item in the leaf path


- Each **prefix path sub-tree** is processed *recursively* to extract the frequent itemsets, then all the solutions are merged
- E.g. the prefix path sub-tree for e will be used to extract frequent itemsets ending in e, then in de, ce, be and ae, then in ade, bde, cde, etc.
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251123213248.png]]



### Conditional FP-Tree
- **Conditional FP-Tree**: is an FP-Tree that would be build if we only consider the transactions containing a particular itemset, and then removing that itemset from all transaction
- in this case we consider all the transaction that contains the itemset {e}, so we eliminate all the transaction where e doesn't appear, we keep all the transaction where e appear, but we eliminate e, and with the remaining transaction we build an FP-Tree
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251123210549.png]]


##### Example:
- we set min_sup = 2 and extract all the itemsets containing e
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251123210558.png]]
- **Step 1**: we obtain all the prefix path sub-tree for *e* with min_sup = 2
- **Step 2**: we check if *e* if a frequent itemset by adding the counts along the liked list (dotted line), if it is extract it
  - Since count = 3, {e} is extracted as a frequent itemset
- **Step 3**: find all the frequent itemset ending in *e* (e.g. ae, be, ce, de)
- **Step 4**: use the *conditional FP-Tree* for *e* to find frequent itemsets ending in ae, ce, de (NOTE: be is not considered because b is not in the conditional FP-Tree for e)

- The support of a is not 8, but 2 because only two path lead to e
- b is present in just one transaction, so even if its support in the tree is two, its true support is 1, and it need to be eliminated 


- Example: e -> de -> ade ({d,e}, {a,d,e} are found to be frequent)
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251123210611.png]]

- Example: e -> ce ({c,e} is found to be frequent)
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251123210615.png]]
- here the real support of a is 1 because it is connected to a single path, so we don't have any path with a min_sup over 2 and we don't save nothing

-  **Result**: Frequent itemsets found (ordered by suffix and order in which they are found)
- here we can see all the frequent itemset found using a conditional tree that start with a given suffix
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251123210627.png]]


### Advantages and Disadvantages
- **Advantages of FP-Growth**:
  - only two passes over the dataset
  - compress the dataset  
  - no candidate generation
  - faster than Apriori method because we do not depend strongly on the value of min_sup


- **Disadvantages of FP-Growth**:
  - The FP-Tree may not fit in memory (nowadays is not a real problem)
  - The FP-Tree is expensive to build



### FP-tree: Another Example
- ...
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251123210649.png]]

### FP-tree: The Algorithm
- Objective: Mine frequent itemsets using an FP-Tree
- Input: the transaction database *D*, The minimum support count threshold *min_sup*
- Output: the complete set of frequent patterns

- FP-Tree construction: 
  - Scan the database and collect the frequent item F and their support counts
  - Sort F by support count descending order, and obtain L (the list of ordered frequent items)
  - create the root of the FP-Tree and label it as "null", then for each transaction in D do the following:
    - select and sort the frequent items in Trans according to the L ordering
    - let the sort item list in Trans be $[p|P]$, where $p$ is the first element, and $P$ is the remaining list, then call $insert_tree([p|P],T)$ which is performed as follow:
        - if T has a child N such that N.item-name = p.item-name, then increment N's count by 1, else create a new node N, and let its count be 1, its parent link be linked to T, and its node-link to the nodes with the same item-name via the node-link structure. If P is nonempty, then call $insert_tree([p|P],T)$ recursively  

- Mine the itemset in the FP-Tree with the function *FP-Growth*
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251123215234.png]]


### Benefits of the FP-tree Structure
- **Completeness**: preserve complete information for frequent pattern mining, and never break a long pattern of any transaction
- **Compactness**: reduce irrelevant info, order items in descending frequency order, use less space than the original database


### The Frequent Pattern Growth Mining Method
- When the database is large the FP-Tree cannot fit in memory

- a possible solution is to partition the database into a set of projected databases, and construct an FP-Tree and mine it for each projected database (it is possible to apply recursively this project to any projected database if its FP-Tree still cannot fit in main memory)
  
- **Performance of FPGrowth in Large Datasets**:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251123210737.png]]
- FP-Growth is better than Apriori for lower values of min_sup
- FP-Growth produce exactly the same result of Apriori, not just an approximation 


## ECLAT: Mining by Exploring Vertical Data Format
- **Vertical Data format**: an item or an itemset is represented by the set of transaction in which it appears
- **tid-list**: list of transaction containing an item

- e.g., we have the following *transactions*: 
  - T1: {A, B, C}   
  - T2: {A, D}  
  - T3: {B, C}

- the corresponding *vertical format* of {A, B, C, AB} will be:
  - t(A) = {T1, T2}  
  - t(B) = {T1, T3}  
  - t(C) = {T1, T3}  
  - t(AB) = t(A) ∩ t(B) = {T1}

- {T1, T2} is a the *tid-list* for A

- we can Derive frequent patterns based on vertical intersection:
  - if t(X) = t(Y) then X and Y always appears together
  - if t(X) is a subset of t(Y), then all the transaction that have X always have Y

- **diffset**: difference between *tids* (the non common elements in the transactions list)
- e.g., 
  - t(X) = {T1, T2, T3}, t(XY) = {T1, T3}
  - Diffset (XY, X) = {T2}


- an **Example**:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251123210815.png]]
- the i-th-itemset is the union of i TID-set of i itemset, with all the common transaction

- ECLAT takes advantage of the Apriori property to generate the (k+1)-itemset from frequent k-itemsets, and it *does not need to scan the database* to find the support of (k+1)-itemsets for k>1
- this because the TID set of each k-itemset have all the information required for counting such support
- but the TID set require a lot of memory and computation


## Which Patterns Are Interesting?—Pattern Evaluation Methods
### Mining Frequent Patterns, Association and Correlations
- 10000 customer transactions analyzed
  - 6000 include computer games
  - 7500 include videos
  - 4000 include computer games and video

- with these data we compute the support of the frequent pattern and the confidence, we obtain that in 40% of the transaction video and game appear together, and it's confidence is the support divided by the number of times that computer appear, and we obtain 66% 
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251123210852.png]]
- this rule seems good, but actually it is **misleading**, because the probability of purchasing videos is 75%, which is even larger than 66%, so video game and video are in reality not correlated, but *negatively correlated*,  the purchase of one of these items actually decreases the likelihood of purchasing the other
- if the consequent appear in every transaction, then the confidence will always be equal to 100%, and this is a **problem**

### Interestingness Measure: Correlations (Lift)
- **Lift**: *measure how many times more often X and Y occur together than expected* if they were statistically independent $$lift(A -> B) = lift(B -> A) = conf(A -> B)/supp(B) = conf(B ->
A)/supp(A) = P(A and B)/(P(A)P(B))$$
- the lift from A to B is equal to the confidence from A to B divided by the support of B
- the higher the lift, the higher the correlation between a and b



### Some consideration on interest measures for association rules
- *play basketball -> eat cereal* [40%, 66.7%] is misleading because the 75% of student eats cereal
- *play basketball -> not eat cereal* [20%, 33.3%] is more accurate, although with lower support and confidence, but it has an higher **Lift**
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251123210908.png]]




### Are lift and $\chi^2$ Good Measures of Correlation?
- “Buy walnuts -> buy milk [1%, 80%]” 
- is misleading if 85% of customers buy milk

- *Support* and *confidence* are not good to indicate **correlations**
- another way to measure correlation is using the $\chi^2$ metric 

- here there are some alternative measures:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251124204436.png]]



### Measures used for comparison
- some good metrics used for comparison:
  - All_confidence: is equal to the support between A and B divided by the maximum between the support of A and the support of B
 - Max_confidence: is the maximum of the probability of having A given B and the probability of having B given A
  - Kulczynski
  - Cosine
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251124204608.png]]

### Null-Invariant Measures
- to determine the best metrics we start from a contingency table and compute the metrics on different dataset considering all the **possible rule** and the possible **inverse rule**
- we can generate a lot of dataset from our contingency table with different number for the item in the rule

- Lift and $\chi^2$ are bad at distinguish pattern association relationships
- a **null transaction** is a transaction that does not contain any of the itemsets being examined 
- A measure is **null-invariant** if its value is free from the influence of null-transactions.
- *Null-invariance* is an important property for measuring association patterns in large transaction databases
- Among the six discussed measures, only *lift* and $\chi^2$ are not null-invariant measures


![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251123211021.png]]
- in the first row (first dataset) all metrics are according, everyone agree 
- in the second one we change only the column to the non milk, non coffe, count, here chi square and lift are very small value so they are saying that milk and coffee are not correlated, and the other metrics are instead are correlated. this because chi square and lift are affected by the null transaction (by the number of transaction where milk and coffee does not appear), instead the other metrics are null invariant, because they are not influenced by the null transaction

- **IR** (*Imbalance Ratio*): measure the imbalance of two itemsets A and B in rule implications, e.g.
	- D4 is balanced & neutral
	- D5 is imbalanced & neutral
	- D6 is very imbalanced & neutral
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251123211030.png]]
- when the imbalance is high, the Kulczynski metrics tend to 0.5 (so you cannot draw a conclusion on the correlation between the two variables), so it is useful to use this two metrics together 


# 07 Outlier Analysis
- Outlier detection is often used in fault detection 
- It is difficult to identify far object in a high-dimensional space

- **Digital twin**: a twin of the real system build only with software and sensors (e.g. it exists digital twin of cities to do analyze and take decision about roads, open parks and stuff like that)
- The problem is that creating a digital twin is expensive 
- You can monitor the normal behavior of the equipment, and execute the digital twin with the real monitored equipment, if the real system behave in a different way, then it is possible to have an error in the equipment, and in this case you can find outlier
- To create the twin you can recreate the physical equation that rule the equipment, another way is to collect a lot of data about the normal behavior of the equipment and create a model exploiting the ML 
- This model is *explainable by design*, and made a root analysis (you know which signal in input lead to a wrong result), it is important not only to detect the fault, but also to understand why you had a fault 

## Outlier and Outlier Analysis
- **Outlier**: A data object that deviates significantly from the normal objects as if it were generated by a different mechanism
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260304142725.png|300]]

- Outlier are different from *noise data*, noise is a random or variance in the measured variable
- Noise should be removed before outlier detection, for instance with smoothing algorithms 

- Outlier instead shouldn't be removed because they are interesting objects that violate the mechanism that generates the normal data 

- **Novelty**: a new behavior that along the time became a normal behavior (the first time that you find a novelty it is an outlier, but that keeps happens and becomes a normal data)

- *Types of outlier*:
  - **Global outlier**: an object that deviates significantly from the rest of the data, e.g. having a temperature of 600 degree. 
  - *Issues*: It is difficult to find an appropriate measurement of deviation 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260304143132.png]]

  - **Conditional outlier** (Contextual outlier): an object that deviates significantly from the others in a certain *context* (e.g. having a temperature of 35 degree in winter, in this case the contest is the season). 
  - *Issues*: sometimes it is difficult to model the contest, and then to model the behavior in regard of the context, you have a set of attributes that describes the context (*Contextual attributes*) and a set of attributes that describes the behavior of the object in the context (*Behavioral attributes*), and sometimes we need to separate them. It can be seen as a generalization of the local outlier whose density significantly deviates from its local area. When we have separate our context we can use the techniques for global outlier
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260304143144.png]]

  - **Collective outlier**: is a group of object that collectively deviates from the others, even if individual data may not be outlier.
  - To detect them you need specific outlier detection techniques (e.g. a couple of very hot days, or a set of pc that continuously send DoS messages). It consider not only the behavior of individual objects, but also that of groups of objects, to detect them you need background knowledge on the relationship among data objects
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260304143329.png]]

- One dataset can have multiple types of outlier
- One object can belongs to more than one type of outlier


### Challenges of Outlier Detection
- Challenges in outlier detection:
  - Model the normal behavior
  - Find the best algorithm and distance 
  - Handling noise
  - Understand why an object is an outlier


- It is difficult to **model all the normal behaviors** of an application, and sometimes the *border* between normal and outlier object is shaded not in black and white

- The best algorithm to apply, and the best distance measure are often **application dependent** and it is important to discover the best parameters for these algorithms (e.g. in medical data a small deviation could be an outlier, instead in marketing we would need a larger fluctuation)

- We need to **handle noise** that can make looks outlier like a normal point or make normal points looks like an outlier

- It is also important to understand **why** we are obtaining outlier (so we need to justify the detection) this is a transparency field action, we need to explain the likehood of an object to be an outlier (how much we are sure that an object is an outlier)



## Outlier Detection Methods
- we can detect outlier in two main ways:
  - Based on **user-labeled examples** of outlier:
    - supervised methods
    - unsupervised methods
    - semi-supervised methods
  - Based on the assumed **distribution of normal data** and outlier data:
    - statistical methods
    - proximity based methods
    - clustering based methods



### User-Labeled Methods 
- The **Supervised** methods, model outlier detection as a classification problem
- We can model normal object and report those not matching the model as outliers, or model the outliers and treat those not matching the model as normal
- This method has the problem of having a very unbalanced dataset (because outlier are rare), but we can apply *data augmentation*
- we want to catch as many outlier as possible, so *recall* is more important than accuracy


- Some **Unsupervised** methods use just some type of clustering, because outlier are expected to be far away from other group, but this method cannot detect *collective outlier*
- this technique is very computationally expensive, it cannot distinguish well outlier and noise, less accurate than supervised methods


- In the **Semi-supervised** methods, the number of label is small, we exploit the labeled object to train a model and assign a class to the other ones, and classify as outlier those who doesn't belong to any normal class 


### Distribution-Based methods
- In **Statistical techniques** (also known as *model-based methods*) we see how well an object can be described by a given distribution, usually first we fit all the distribution in a known one, then we will classify as outlier all the methods that dont follow the model
- In parametric approach we specify the type of distribution, in non-parametric we don't provide any initial distribution 
- *Issues*: it highly depend on whether the assumption of statistical model holds in the real data


- The **Proximity based techniques**, classify as outlier the points that have an high proximity distance with its nearest object or its n-nearest objects 
- It depends a lot on the used proximity measure 
- It can be difficult to find group of outlier that stay close to each other
- It is divided in *distance-based* and *density-based*


- In **Clustering based techniques** we assume that normal data belong to large and dense clusters, and outlier belong to small or sparse clusters or do not belong to any cluster at all
- *Issues*: clustering is costly and does not scale well with large dataset
- For example here all point not in R form a large cluster, the two point in R form a small cluster, so they are probably outlier
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260304143132.png]]


## Statistical Approaches
- *Statistical approaches* assume that the objects in a data set are generated by a stochastic process 
- The main idea is to learn a model that fit the normal data, and classify the objects in low-probability regions as outlier. They are divided into two methods:
  - **Parametric Methods**: we assume the type of distribution and we also want to find the parameters $\theta$ of that distribution, the smaller is the probability that an object belongs to a distribution the more likely is that they are outlier 
  - **Non-Parametric Distribution**: do not assume a-priori statistical model ad determine the model from the data, it is not totally parameter-free, but more flexible, e.g. histogram and kernel density estimation


### Detection Univariate Outliers Based on Normal Distribution
- **Univariate data**: data characterized by only one attribute
- We often assume that data are generated from a *normal distribution*, we learn the parameters and then we identify the point with low probability as outlier
- two methods are used to check if data are normally distributed:
  - **Shapiro-Wild Test**: test for verifying whether a random sample comes from a normal distribution
  - **QQ-Plot**  

##### QQ Plot
- The **QQ-Plot** (Quantile-Quantile plot) plots quantiles of two distribution against each other, to be more precise we plot the quantiles of the normal distribution against the quantiles of our data
- A quantile is a value such that a fraction of our distribution is less or equal to that value

- Steps:
  - Sort your values
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260304150322.png]]
  - Divide the normal distribution in n+1 segments with *equal area*, with $n$ the number of values
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260304150316.png]]
  - Find the *z-values* (the cut-off point for each segment), the z-value is the number of sd from the mean
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260304150306.png]]
  - Plot the sorted data against the z-value, if the line is linear, then we can assume that our data is normally distributed 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260304150259.png]]


##### Detect univariate outliers based on normal distribution (Parametric Methods)
- **Method 1**: model the normal distribution and consider the probability of the points to belong to this distribution
- We use the *maximum likehood method* to estimate $\mu$ and $\sigma$ 
- The probability that a point $x_i$ is generated by the model is:
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260304150448.png]]

- The likehood that $X$ is generated by the model is:
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260304150453.png]]


- The task of the generative model is to find the parameters such that the likelihood is maximized, and is equal to
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260304150532.png]]


- If we consider the derivatives with respect to $\mu$ and $\sigma^2$ we obtain the following maximum likelihood estimates:
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260304150629.png]]

- we can classify as outlier the point that are not contained in $\mu \pm 3 \sigma$, because 99.7% of data are contained in this range, $3$ in this case is a *parameter* that we are choosing arbitrarily 


### Grubb's test (Parametric Test)
- The **Grubb's Test** (also called maximum normed residual test) is a statistical method that works if data are normally distributed, it test if a maximum value or a minimum value is or not an outlier

- The test checks for outliers by looking for the maximum of the absolute differences between the values and the mean
- There are 4 Steps

- **Step 1**: We find the **G test statistics**, to do so we order the data points from smallest to largest, we find the mean $\bar{Y}$ and the standard deviation $s$, and calculate the G test statistic as the maximum difference between points and the mean, divided by the sd
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260304151138.png]]

- **Step 2**: We find the **G critical value**, to do so we use appropriate tables, the value changes based on $N$ and the confidence level $\alpha$, you can also calculate G manually with this formula:
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260304151316.png]]
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260304151321.png|300]]

- **Step 3***: We **compare** the test statistic with the G critical value, if the Test value is less than the Critical value the point is not an outlier, if it is grater it is classified as an outlier

- Example:
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260304151500.png]]


### Multivariate Approaches (Parametric Methods)
- It is more common that object are described by multiple attributes
- **Multivariate data**: a data set involving two or more attributes or variables

- Our idea is to transform a multivariate problem in a univariate problem 

##### Mahalanobis Distance
- The **Mahalanobis Distance**: is the distance *between a point and a distribution*, and not between distinct points, it is effectively a multivariate equivalent of the euclidean distance

- If we consider only how much a point is close to the center of the cluster with the euclidean distance to check how close a point is to the cluster can be very misleading 
- moreover all the feature are weighted in the same way
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260304151821.png]]


- The Mahalanobis Distance apply a transformation that transform correlated features into *uncorrelated feature* and scale them such that their variance becomes 1, in this way we can apply the euclidean distance 

- Let $\bar{o}$ be the mean vector for a multivariate data set, having S, the *covariance matrix*, the Mahalanobis distance for an object $o$ from $\bar{o}$ is defined as:
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260304152038.png]]

- To divide by the covariance matrix is equivalent to a z-transform $(x - mean) /sd$
- If the variable are correlated, the covariance will be high and the distance will be reduced a lot, otherwise, the covariance will be low and the distance will not be reduced


- so with the MD we can transform a multivariate outlier detection in a univariate outlier detection in the following way:
  1. Calculate the mean vector from the multivariate data set
  2. For each object $o$ calculate $MDist(o, \bar{o})$, the MD from $o$ to $\bar{o}$ 
  3. Detect outliers in the transformed univariate data set (for instance with the Grubb's test)
  4. if $MDist(o, \bar{o})$ is classified as outlier, $o$ is an outlier as well

- *issues*: it is computationally heavy and use a lot of memory to store the covariance matrix and its inverse

##### $\chi^2$ statistic (Parametric Methods)
- In the $\chi^2$ **Statistic** **method**, we assume that the population of $O$ follows a multivariate distribution with mean vector $\bar{o}$ and covariance matrix $S$
- We use a distance measure based on the $\chi^2$ test statistic
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260304155443.png]]

- Where $oi$ and $Ei$ are the **observed** and **expected** value, and $n$ the number of variables
- Using the average value as estimates of expectation we have: 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260304155713.png]]
(formula using the mean as the expected value)

- For the CLT for n>30 then $\chi^2$ follow a normal distribution, since it's normally distributed we can find outlier considering the point over $\bar{\chi^2} \pm 3 S_{X^2}$ 


### Detection Using Histogram (NON-Parametric Methods)
- In the **Detection Using Histogram** method, the model of data is learned from the input data without any a priori structure
- It requires fewer assumptions about the data and thus can be applied in more scenario
- We build a histogram putting observation in each bin, if an observation will drop in a very rare bin it will be classified as an outlier
- *Issues*: it is difficult to choose an appropriate bin size, with small bin size we can have false positive, with large bin size we have false negative, we can resolve this problem adopting a **kernel density estimation** (if  the estimated density function is high, the object is likely normal, otherwise, it is likely an outlier)
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260304160057.png]]

### Kernel Density Estimation (NON-Parametric Methods)
- The **Kernel Density Estimation** is an evolution of the histogram method
- In this Way we can compute the Kernel density, with $K$ the kernel (a function with area 1), and $h>0$ a smoothing parameter called bandwidth 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260304160113.png]]
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260304160108.png]]
- The only *parameter* is $h$ the standard deviation of the normal 


### Statistical Methods: Computational cost
- The computational cost of statistical method depends on the models
- Simple parametric models like a gaussian use a linear time
- More sophisticated models requires several interaction, and for kernel density estimation the model learning cost can be quadratic 

- However, once the model is learned, the outlier detection cost is often very small per object


## Proximity-Based Approaches
- **Proximity-Based Approaches** are based on the intuition that *object that are far away from the others are outlier* 
- The proximity of an outlier deviates significantly from that of most of the others in the dataset
- It can use:
  - **distance measure** (an object is an outlier if its neighborhood does not have enough points)
  - **density measure** (an object is an outlier if its density is relatively much lower than that of its neighbors)

### Distance-Based Outlier Detection
- For the **distance based technique** we check the number of neighbor in a Ball with ray $r$ and center an object $o$ and their distance 
- If at least $\pi\%$ of object are far from $o$ (so outside the ball), then $o$ is an outlier
- The biggest problem is to determine $r$ and $\pi$, but also that we are assuming that the values of $r$ and $\pi$ are valid for each zone, but we can have *different densities* in different zones 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260304161813.png]]
 
- Equivalently it is possible to check the distance of the k-th nearest neighbor of $o$, if its distance is greater than $r$, then $o$ is an outlier

- This approach is limited, we need to set two *parameters* $\pi$ and $r$, and we have some serious problem if the space in part dense, and in part sparse, because we have to fix a value for the parameter for the entire space, but if i have different density in the space the parameters will not work and there is no solution

- Steps:
  - for any object $o_i$ calculate its distance from other objects, and count the number of objects in the r-neighborhood
  - if $n*\pi$ objects are in the within distance $r$, terminate the inner loop, otherwise, if at the end of the loop there aren't $n*\pi$ object in the ball, then $o_i$ is an outlier
- It execute in linear time because non outlier finish early the inner loop


### Distance-Based Outlier Detection: A Grid-Based Method
- In the **Grid-based method (CELL)** the data space is partitioned into a *multi-D Grid*, each cell is a hyper cube with diagonal length $r/2$ (in 2D is a simple square), in this way we can work with groups of points instead of single points 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260304162808.png]]

- We prune it using level-1 and level-2 cell properties:
  - **Level-1**: are the adjacent cell, each point in the cell **C** and points in the **Level-1** have distance $\le r$, they can be near and have to be checked
  - **Level-2**: are cell at a distance of two space from **c**, they are more far than $r$, $dist \ge r$ so they can be ignored

- With this technique we do not compare all the point, but only near cells, so it is faster for larger dataset

- A point is classified as an outlier if it has less than $n * \pi$ neighbors within a distance $r$
- with:
  - $a$ the number of points in the cell **C**
  - $b_1$ the number of point in the Level 1 
  - $b_2$ the number of point in the Level-2

- **Rule 1**: if $a + b_1 > \pi n$ then *all* the points in **C** are not outliers because each point will have at least $\pi n$ neighbors, and we can discard the cell
- **Rule 2**: if $a + b_1 + b_2 < \pi n + 1$ then *all* the points in **C** are outlier
- In the other cases we need to check the real distance, and we need only to compare the distance of an object with its level-2 cells

### Local Distance-Based Outlier Detection
- We have problem with cluster of different densities
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260304163553.png]]
- They can be resolved considering the mean distance with all the neighbor (**outlierness** measure), we also don't need many specific parameters and this is a huge advantage, the only *parameter* are $k$, but it is not so much sensitive, and another parameter to decide the *threshold* for classify an object as an outlier 


### Local Distance-Based Outlier Detection
- Let $Nk(xi)$ be the k-nearest neighbors of xi
- Let $Dk(xi)$ be the average distance to k-nearest neighbors
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260304164510.png]]


- **Outlierness** is the ratio of $Dk(xi)$ to average $Dk(xi)$ for its neighbors $j$, if it is $>1$ is further away from neighbors than expected
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260304164549.png]]
- the **outlierness** solve the problem of the different density zone because we are adapting to the density that we have in the space
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260304164643.png|300]]



- But if clusters are *close*, outlierness gives unintuitive results near the boundary, if we have different cluster with different density near to each other this can create a lot of problem
- in this example $p$ has an higher outlierness than $q$ and $r$
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260304164722.png]]

- The *parameters* are $k$ and a $threshold$ to classify point into outlier based on the value of their outlierness




### Local Outlier Factor: LOF (Density-Based Outlier Detection)
- **Local outliers**: point considered outlier in respect of their neighbors, instead of the global data distribution
- for example here o1 and o2 are *local outlier*, and o4 no:
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260304165103.png|300]]

- The main idea is that the density around an outlier is significantly different from the density around its neighbors 
- **k-distance of an object o**, $distk(o)$: distance between o and its *k-th NN* (the k-th more far point)
- **k-distance neighborhood of o**, $Nk(o)$: is the set of point where the distance from $o$ is less or equal to the *k-distance* (they can be more than k if some points are distant exactly the k-distance)

- The **Reachability distance** between $o$ and $o'$ is the maximum between **dist_k(o)** and the distance between $o$ and $o'$  
- The **Local Reachability Density** (*LDR*) measure how dense is the area between $o$, it is equal to the number of neighbors divided by the sum of the distances
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260304170141.png]]


- The **Local Outlier Factor** (*LOF*) of an object $o$ is the average of the ratio of the local reachability of $o$ and those of $o$'s k-nearest neighbors
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260304170303.png]]
- The more LOF is high the more is likely that the point is an outlier 
- it remains the problem on close cluster with different density
- is similar to outlierness but use density instead of distance
- its *parameters* are k and the threshold

- Example of LOF computation:
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260304164856.png]]
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260304164850.png]]
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260304164844.png]]
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260304164839.png]]


## Clustering-Base Approaches
### Clustering-Based Outlier Detection
- Intuition: an object is an outlier if:
  1. it does not belong to any cluster
  2. there is a large distance between the object and its closest cluster
  3. it belongs to a small or sparse cluster

- **Case 1** (*Not belong to any cluster*): you can use density based clustering methods such as DBSCAN
- **Case 2** (*Far from its closes cluster*): you can consider the distance from its closest center divided by the average distance from that center of the element of the cluster
- **Case 3** (*Belong to small sparse cluster*): in a large dataset outlier may form a small cluster (e.g. cyber attack that use similar techniques)
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260304171346.png]]

- **CBLOF** (*Cluster-Based Local Outlier Factor*) is a measure associated to an object that tells the physical significance of the definition of an outlier
- It measures both the size of the cluster the object belongs to, and the distance between the object and its closest cluster

- First we divide data in clusters
- **LC** is the set of large clusters
- **SC** is the set of small clusters

- We ordinate them by the smaller to the bigger
- We define them with the boundary value **b** obtained by setting two parameters $\alpha$ and $\beta$ 

- (1) LC have to contain at least $\alpha\%$ of data, so the majority of point are non outlier
- (2) A big cluster is at least $\beta$ times bigger than a small cluster (this ensure that the difference between small and large cluster is significative) 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260304172305.png]]

- For each object $o$ we define *CBLOF* as:
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260304172427.png]]

- If $o$ belong to a SC and the point is far from a LC, it is probably an outlier
- If $o$ belong to a LC, but is far from the center it can still be an outlier
- we use as *parameters* alpha, beta, and the parameters that we need to execute the clustering algorithm 
- it is not easy to set the parameters, you should be careful 

### Clustering-Based Method: Strength and Weakness
- **Strength**:
  - detect outlier without requiring labels
  - work for many data types
  - fast after you obtained the clusters

- **Weakness**: 
  - depend on the clustering method used (that could be non-optimized for outlier detection)
  - some method can depend from parameters values 
  - high initial computational cost
- you can reduce the cost using *Fixed-width clustering*: a point is assigned to a cluster if the center of the cluster is within a pre-defined distance threshold from the point



## Classification Approaches
### Classification-Based Method I: One-Class Model
- The main idea is to train a classification model that can distinguish normal data from outliers
- The problem is that the training set is unbalanced because outlier are rare, you have to apply under-sampling or over-sampling, and you *cannot detect unseen anomaly*

![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260304172911.png]]


- **One class model**: a classifier build to describe only the normal class, it learn the boundary of the normal class, any sample that do not belong to the normal class is classified as an outlier

- The most popular approach is the **Support Vector Data Description** (*SVDD*): it build a hyper-sphere around the positive class data that encompasses almost all point in the dataset within the minimum radius, it classify a point as an outlier if it falls outside the hyper-sphere
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260304173445.png]]

- Another approach is the **Nearest Neighbor Description (NN-d)**: an object is consider normal if its local density is greater than or equal than the local density of its nearest neighbor in the training set

- The following formula represent the distance form object z to its nearest neighbor in the training set, $NN^{tr}(z)$ is compared to the distance from its nearest neighbor $NN^{tr}(z)$ to its nearest neighbor 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260412105651.png]]

### Classification-Based Method II: Semi-Supervised Learning
- **Semi supervised learning** combine classification based and clustering-based methods

- *Method*:
  - Find a large cluster, C, and a small cluster, C1
  - Since some objects in C carry the label “normal”, treat all objects in C as normal
  - Use the one-class model of this cluster to identify normal objects in outlier detection
  - Since some objects in cluster C1 carry the label “outlier”, declare all objects in C1 as outliers 
  - Any object that does not fall into the model for C is considered an outlier
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260304174120.png|300]]
- It detect outlier fast, but the accuracy depend on the quality of the training set





## Mining Contextual and Collective Outliers
### Mining Contextual Outliers I: Transform into Conventional Outlier Detection
- If you can find the context, then transform the problem into a conventional outlier detection
  1. identify the context of the object using the contextual attributes
  2. calculate the outlier score for the object in the context using a conventional outlier detection method


- Example:
    Detect outlier customers in the context of customer groups
  - Contextual attributes: age group, postal code
  - Behavioral attributes: # of trans/yr, annual total trans. amount

- Steps: 
  - locate c’s context
  - compare c with the other customers in the same group
  - use a conventional outlier detection method

- If the context contains *very few customers*, **generalize contexts**
- For instance, for a customer c, if the corresponding context contains very few or even no other customers, the evaluation of whether c is an outlier using the exact context is impossible

- Learn a mixture model $U$ on the contextual attributes, and another mixture model $V$ of the data on the behavior attributes
  - Learn a mapping $p(V_i|U_j)$: the probability that a data object $o$ belonging to cluster $U_j$ on the contextual attributes is generated by cluster $V_i$ on the behavior attributes
  - The outlier score will be:
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260412110222.png]]


### Mining Contextual Outliers II: Modeling Normal Behavior with Respect to Contexts
- In some applications one cannot clearly partition the data into contexts 
- Another method to find contextual outlier is to train a model that predicts the expected behavior attribute values with respects to the contextual attribute values
- An object will be an outlier if its behavior attribute values significantly deviate from the values predicted by the model on the specific context



### Mining Collective Outliers I: On the Set of “Structured Objects”
- **Collective outlier** are group of object that deviate significantly from the entire dataset
- To find them we need to examine the *structure of the data set*, for example the relationship between multiple data objects

- We analyze different *structure* for different *data type*:
  - segment of the time series for temporal data
  - local area for spatial data
  - subgraph for graph and network

- Structures are often non explicitly defined and have to be discovered as part of the outlier detection process
- We treat each **structure unit** (e.g. a subsequence or a subgraph) as a *data object* and extract its features, then we will apply the traditional outlier detection on the set of *structured object*

### Mining Collective Outliers II: Direct Modeling of the Expected Behavior of Structure Units
- It is also possible to **Model directly** the expected behavior of structure units, e.g. we can define as outlier sparse small subgraphs or dense large subgraphs, we classify as outliers structure units that deviate from the normal behavior 



## Outlier Detection in High Dimensional Data
### Challenges for Outlier Detection in High- Dimensional Data
- **Outlier are difficult to interpret**: it is not very useful to detect an outlier in a High-D space without saying why they are outlier, it is important to interpret them to understand what is the root cause that is creating them 
- **Data are sparse**: the distance between objects becomes heavily dominated by noise as the dimensionality increases

- To resolve those problem we use techniques that search for outlier only on **Data subspaces**, because an object could be an outlier on some dimensions, but the number of subspace *increase exponentially* with the number of dimensions

### Approach I: Extending Conventional Outlier Detection
- **Method 1**: The **HilOut Algorithm** perform an outlier detection on the full space
- We find distance-based outlier, but we use the *ranks of distances* instead of the *absolute distance* in outlier detection
- For each object $o$ we find its knn $nn_1(o)...nn_k(o)$, the **weight of the object** $o$ will be the sum of the distance between $o$ and its knn $$w(o) = \sum_{i=1}^k dist(o, nn_i(o))$$
- the Top $l$ object with the *highest weight* are output as outlier, *l* is the parameter

- **Method 2**: The **Dimensionality Reduction** works only in low dimensions, where normal instances can still be distinguished from outlier
- Use the **PCA**, maintain only the PC with low variance, and classify as outlier the object that deviates in those dimension with a low variability



### Approach II: Finding Outliers in Subspaces
- By finding outlier in a much lower dimensional subspace, it becomes easier to interpret **why an object is an outlier** and how much is an outlier
- You need to search for regions that are significantly sparse, you project data *onto various subspaces* to find area whose density is much lower than average
- then **discretize the data into a grip** with $\phi$ **equi depth** regions

- *equi depth*: contain the same number of object, the cell can have different dimension (with equal dimension it is called instead *equi width*)
- we search for region significantly sparse, we consider a k-dimensional cube with n objects, if objects are independently distributed, the expected number of objects in a k-dimensional region is $f^k*n$, with a standard deviation $\sqrt{f^k(1-f^k)n}$ 
- The **Sparsity coefficient** of cube C, is instead:  $S(C)=\frac{n(C)-f^kn}{\sqrt{f^k(1-f^k)n}}$ 


- if object are independently distributed then the number of object for cube should be the same
- If the sparsity coefficient is less than zero ($S(C) < 0$), then C contains less object than expected, the more negative, the sparser is C, the more likely the object in C are outliers
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260306204756.png]]
- the quality depend on grid resolution and position

- Algorithms: 
  - find **m grid cells** (projections) with the lowest sparsity coefficients
  - Brute-force algorithm in $O(\phi^k)$ 
  - evolutionary algorithm

### Approach III: Modeling High-Dimensional Outliers
- Another intuition is to develop new model only for high dimensional outlier
- We should avoid proximity and use an heuristic that *do not deteriorate in high-dimensional data*
- One possible heuristic are **Angles**, angles are more stable in high dimensional space
- Object $o$ is an outlier if most other objects are located in similar direction
- Object $o$ is not an outlier if many objects are located in varying direction
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260306205701.png]]

- We use the variance of angles for a point to determine outliers
- We can also weight the angle by the distance to obtain the angle variance, because normal object are in the middle of the distribution, outlier at the border
- For a point $p$, having the angle between $px$ and $py$ for any (x,y), then we can use the *broadness* of this spectrum as a score for the *outlierness* of the point
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260306210008.png]]

- We measure the **variance of the angle spectrum**, weighted by the **corresponding distance**, with this we can compute the Angle-based Outlier Factor (*ABOF*): 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260306210140.png]]

- If it is small, $o$ is an outlier
- If it is high, $o$ is not an outlier
- this method has a complexity $O(n^3)$ 




# 08 Advanced Frequent Pattern Analysis
## Pattern Mining: A Road Map
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251123211156.png]]

##### Recap
- The two main algorithms for pattern mining are:
  - Apriori Algorithm
  - FP-growth Algorithm

- They create the same result with a different procedure, The Apriori is simpler but slower, the FP-growth more complex but faster because Apriori require multiple scans, FP-growth only two 
- They uses as parameters the *min-support* (the number of transaction in which we have the frequent pattern, so in which the *itemset* is present), it affect a lot the result and the complexity of the problem, with a low minsup we generate a huge amount of frequent pattern and the problem become more complex 
- This threshold usually depend on the application domain

- *Confidence*: the probability that we have the consequent in a transaction in which appear the antecedent, (e.g. probability to have biscuit in a transaction in which appear milk)

## Pattern Mining in Multi-Level, Multi-Dimensional Space
### Mining Multi-Level Association
- Items often form **hierarchies** (it is possible to have item that are a specialization of other item, e.g. skim milk if a specialization of milk)

- You need a *Flexible support settings*, because items at the lower level are expected to have lower support, item at lower level can be variant of an item at an higher level, so maybe more rare
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251123211250.png]]

- In this example, we retain item that are contained in at least 5% of itemset at level 1 and 3% of itemset of level 2, if we would have a constant threshold we would have filtered the skim milk in the second level, but since we have a flexible support (so that the threshold change among levels) then we can maintain skim milk as a frequent itemset  

### Multi-level Association: Flexible Support and Redundancy filtering
- With a **flexible support** you can reduce the value of min_sup for element in lower level of hierarchy, or give a lower support to valuable items, e.g., {diamond, watch, camera}: 0.05%; {bread, milk}: 5%

- **Redundancy Filtering**: Some rules may be redundant due to “*ancestor*” relationships between items
	- milk -> bread [support = 8%, confidence = 70%]
	- 2% milk -> bread  [support = 2%, confidence = 72%]
- The first rule is ancestor to the second rule

- A rule is **Redundant** if its support and confidence are close to the "expected" value, based on the rule's ancestor
- So if the ratio of the support between rules is similar to the ratio of the support of the item with a hierarchical relation 


### Mining Multi-Dimensional Association
- **Single-dimensional rules**: consider just one *predicate*, a predicate is an action, like buys, looks, returns
  *buys*(X, “milk”) -> *buys*(X, “bread”)

- **Multi dimensional rules** consider more than one *predicates*, it can be:
  - **Inter dimensional** (no repeated predicates):
    (*age*(X,”19-25”) $and$ *occupation*(X,“student”)) -> *buys*(X, “coke”)
  - **hybrid dimensional** (repeated predicates):
    (*age*(X,”19-25”) $and$ *buys*(X, “popcorn”)) -> *buys*(X, “coke”)



### Mining Quantitative Association Rules
- **Categorical attributes**: finite number of possible value, no ordering among values. it is possible to exploits the *data cube approach*
- **Quantitative attributes**: numeric, implicit ordering among values, they can have *static discretization* (predefined concept hierarchies) and *dynamic discretization* (binning and clustering)

- **Data Cube**: a table with n dimension, assign to n dimension a value, for instance you can have a cube with dimensions: product, city, year, and keep in the cell value the number of sales

- You can categorize techniques by the way they *treat numerical attributes*:
  - **Static discretization**:  based on predefined concept hierarchies (like the data cube method)
  - **Dynamic discretization**: based on data distribution
  - **Clustering**: Distance-based association, used on single dimension
  - **Deviation**: Use statistical deviation from classical values, for instance i know that the average wage is 9\$, if i know that the sex of the worker is female, then i predict that the mean is 7\$


### Mining Rare Patterns and Negative Patterns
- **Rare patterns**: interesting pattern, but with a *very low support* (e.g. the purchases of a Rolex)
- Mining: set special support threshold for valuable items

- **Negative (correlated) pattern**: object that are likely never buy together, for instance a steak and a vegan burger  
- Infrequent Negative correlated pattern tend to be more interesting than those that are frequent


### Defining Negative Correlated Patterns
- **Definition 1** (**support base**): two itemset are negatively correlated, if they are both frequent, but rarely occur together
$$sup(X \cap Y) << sup(X) * sup(Y)$$ 
- *problem*: this definition is not null-variant, so the result depend on the total number of transaction (even the transaction in which A and  B does not appear)
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260311100431.png]]



- **Definition 2** (**Kulczynski (calziski) measure-based**): if two itemset x, y are both frequent, but the probability of having the first knowing that the second is in the transaction, plus the probability to having the second, knowing that the first is in the transaction, is less than a *negative pattern threshold $\epsilon$*, then they are negatively correlated 
$$\frac{P(X|Y) + P(Y|X)}{2} < \epsilon$$
- For the same needle package problem, when no matter there are 200 or 105 transactions, if min_sup = 0.01% and є = 0.02, we have:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251123211406.png]]
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251123211414.png]]
- this method in **not null variant** because it does not depend on the number of transaction



## Constraint-Based Frequent Pattern Mining
### Constraint-based (Query-Directed) Mining
- It is unrealistic to find automatically *all the patterns* in a database autonomously, because the patterns could be too many and *not focused* (not relevant to the application domain)
- For this reason data mining should be an **iterative process** where user *directs what to be mined* by using a **data mining query language** or a GUI

- **Constrained-based mining**:
  - *User flexibility*: users provides constraints on what to be mined
  - *Optimization*: we explores such constraints for an efficient mining

- we find all the answers that satisfy a constraint, we do not find answers in a heuristic search


### Constraints in Data Mining 
- **Knowledge type constraint**: We want to mine rules for classification 
- **Data constraint**: defined using an SQL-like query language (e.g. find product sold together at Pisa in 2022)
- **Dimension/level constraint**: constraint relevant for a certain attribute
- **Rule (or pattern) constraint**: (e.g. small sales that triggers big sales)
- **Interestingness constraint**: use *strong rule*, we use constraint about the interest of the pattern, e.g. min_support >= 3%, min_confidence >= 60%


### Meta-Rule Guided Mining 
- a **Meta Rule** forms a *hypothesis* regarding the relationships that the user is interested in probing or confirming (so it is a given rule that we want to verify)
- Meta rules can be in the rule form with *partially instantiated predicates and constants*

- Usually we have an uncompleted rule and we want to find the missing constant and predicates
	  P1(X, Y) ^ P2(X, W) => buys(X, “iPad”)
	
- Here we are interested to determine which kind of users buy an iPad, an example of result can be that student with profession student and age between 15 and 25 usually buy it
	  age(X, “15-25”) ^ profession(X, “student”) => buys(X, “iPad”)

In general rules are in the **form**:
	    P1 ^ P2 ^ … ^ Pl => Q1 ^ Q2 ^ … ^ Qr


### Constraint-Based Frequent Pattern Mining
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251123211436.png]]

- a naive solution can be use a classical approach and then filter all the rules that do not respects the given constraints, so we are applying a *post-processing*
- a more efficient solution is to reduce the itemset in which we apply the classical approach to reduce the search space, so apply a *pre-processing*, for instance limiting the analysis on only the transaction in which city=Chicago and years=2010 that are attributes of the transaction 

- We can find constrained patterns with two approach:
	- **Pruning pattern search space**: we prune already generated pattern (so it is a kind of post processing)
	- **Pruning data search space**: we eliminate from the dataset the data-piece that aren't able to contribute the rules for a pattern before starting the rule generation (so it is a kind of pre processing)


- *Pattern space pruning constraints*:
  - **Anti-monotonic**: if constraint c is violated, then its further mining can be terminated
  - **Monotonic**: if constraint c is satisfied, there is no ned to check c again
  - **Succinct**: c must be satisfied, so one can start with the data sets  satisfying c
  - **Convertible**: c is not monotonic nor anti-monotonic, but it can be converted into one of it if items in the transaction are properly ordered

- *Data space pruning constraint*:
  - **Data succinct**: data space can be pruned at the initial pattern mining process
  - **Data anti monotonic**: if a transaction t does not satisfy c, t can be pruned from its further mining


### Pattern Space Pruning with Anti-Monotonicity Constraints
- A constraint C is **anti-monotone** if when the *super pattern* satisfy C, then all its sub-patterns do it to
- So if one itemset *violates* a constraint, then all its supersets violate the constraint as well

- for example, "sum of the price of the elements are less than 15", if a superset have the sum of their price lower than 15, then all the subset will have the sum of the price lower than 15
- on the other hand the constraint "sum of the prices greater than 15" is not anti monotonic, if a superset do satisfy this, not all subset will do



### Pattern Space Pruning with Monotonicity Constraints
- A constraint C is **monotone** if the pattern satisfy C, we do not need to check c in *subsequent mining* (e.g. sum of the prices of some element greater than a value v, or the minimum of the price less or equal than v, because if an itemset ab satisfy those constraints, so will do every superset of ab)




### Pattern Space Pruning with Succinctness
- **Succinctness**: we can *enumerate* all and only those sets that are guaranteed to satisfy the constraint
- if a rule is succinte, we can generate precisely the sets that satisfy it even before support counting begins 
- e.g. "the minimum price is greater than v" is succinct, because we can remove all the item where an item price is lower than v
- because we can generate all the itemset that satisfy the constraint, we do not need to check the rule constraint

###### Example
- Given A1 the set of items satisfy a succinctness constraint C, then any set I satisfying C is based on A1 (I contains a subset belonging to A1)
- so without looking at the transaction database, whether an itemset I satisfies constraint C can be determined based on the selection of items


### The Apriori Algorithm - Example
- here we Have a database of transaction where we are applying the apriori algorithm, and we are using a minsup=2, so we are filtering itemset that appear less than 2 times across transactions  
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251123211627.png]]

- but if we had as constraint that the minimum price should be 3, then we could have filtered all the itemset of length 1 where the minimum price is greater than 3, in this way we are generating a lot less rules
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251123211640.png]]


### Convertible Constraints: Ordering Data in Transactions
- Sometimes we can convert some constraints into anti-monotone or monotone by **properly ordering the items**

- We have a constraint that is not monotone or anti monotone, but if i order item in value-descending order, then it becomes an anti-monotone rule
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251126143510.png]]


### Strongly Convertible Constraints
- A **strongly convertible constraint** is a constraint that is:
  - convertible anti-monotone w.r.t. an order $R$, and
  - convertible monotone w.r.t. the reverse order $R^{-1}$

- Example: $\text{avg}(X) \ge 25$

- *Anti-monotone (descending order)*  
  $R = \langle a, f, g, d, b, h, c, e \rangle$  
  If an itemset (e.g., $af$) violates $C$, then all its extensions (e.g., $afd$) also violate $C$

- *Monotone (ascending order)*  
  $R^{-1} = \langle e, c, h, b, d, g, f, a \rangle$  
  If an itemset (e.g., $d$) satisfies $C$, then all its extensions (e.g., $df$, $dfa$) also satisfy $C$

- Therefore, $\text{avg}(X) \ge 25$ is **strongly convertible**

 
### Can Apriori Handle Convertible Constraints?
- A convertible, not monotone nor anti-montone nor succinct constraint cannot be pushed deep into the Apriori mining algorithm
- but it can be pushed into frequent pattern growth framework

- so when we generate the FP-Tree we need to exploit some ordering to obtain the ordering that we want

### Handling Multiple Constraints
- Different constraints may require different or even *conflicting item-ordering*
- if there exists an order R such that both C1 and C2 are convertible in respect of R, then there is no conflict between the two convertible constraints

- if *there exists conflict* on order of items, try to satisfy one constraint first, and then using the order for the other constraint, try to mine frequent itemsets into the corresponding projected database

### What Constraints Are Convertible?
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251123211805.png]]

### Data Space Pruning with Data Anti-monotonicity
- A constraint is **data anti-monotone** if, when a transaction does not satisfy the constraint for a pattern p, then it cannot satisfy the constraint for any superset of p

- We can eliminate transactions that cannot satisfy the constraint for the current pattern or any of its supersets
- This pruning cannot be done at the beginning of the mining process because it depends on the current pattern being explored

###### Example
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260311104859.png]]

![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260311104928.png]]

![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260311105000.png]]

![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260311105046.png]]


### Constraint-Based Mining — A General Picture
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251123211826.png]]



### A Classification of Constraints
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251123211836.png]]




## Mining High-Dimensional Data and Colossal Patterns
### Mining Colossal Frequent Patterns
- With the algorithms seen since now we cannot mine colossal pattern of more than 50/100 elements for the **curse of the downward closure** of frequent pattern

- *closed pattern*: a pattern that do not have a super pattern with the same support
- *maximum pattern*: a pattern that do not have any super pattern 

- **Curse of the downward closure**: any sub-pattern of a frequent pattern is frequent
- e.g. If (a1, a2, …, a100) is frequent, then, (a1, a2), (a1, a3), …, (a1, a100), (a1, a2, a3), … are all frequent! There are about $2^{100}$ such frequent itemsets! *we have to examine too many patterns* and this lead to *explosion*
- in summary, if we have a colossal pattern, then all its sub-pattern will be frequent too, and for long subpattern there is an explosion in the number of subpattern

- **Colossal Patterns: A Motivating Example**: 
	- closed or maximal patterns may partially alleviate the problem, but it cannot really solve it
	- we often need to mine scattered large pattern

##### Example of scattered large pattern
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251123211902.png|300]]
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251126144646.png]]


### Colossal Pattern Set: Small but Interesting
- Usually only a small number of pattern are colossal
- usually they are more important than those with a smaller size
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251123211926.png|300]]

- **Motivation**: many real world task need to mine colossal pattern (e.g. in biological sequence)
- we cannot find them by using a *complete set* solution because of the explosive size of such set
- we need to ignore the mid-sized results and consider only the colossal one


### Alas, A Show of Colossal Pattern Mining!
- For this kind of problem classical algorithm fails to execute
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251126145118.png|200]]
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251126145056.png|300]]


### Methodology of Pattern-Fusion Strategy
- **Pattern fusion strategy** traverses the tree in a bounded-breadth way
- it always push down a frontier of a bounded size candidate pool 
- only a fixed number of patterns in the current candidate pool will be used as the starting nodes to go down in the pattern tree (this allow to avoid an *exponential search space*)

- Pattern fusion identifies "**Shortcut**" whenever is possible
- the pattern growth is not performed by a single-item addition, but by  **agglomeration of multiple patterns in the pool**
- these shortcuts will direct the search down the tree much more rapidly towards the colossal patterns
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251123212002.png|300]]



### Observation: Colossal Patterns and Core Patterns
- visual representation of the method:
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251123212015.png]]


### Robustness of Colossal Patterns
- **Core patterns**: for a frequent pattern $\alpha$, a sub-pattern $\beta$ is a **t-core** pattern of $\alpha$ is $\beta$ shares a similar *support set* with $\alpha$
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251123212026.png]]
where $|Dα|$ is the number of patterns containing $α$ and $τ$ is called the **core ratio**


![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260311110615.png]]

### Robustness of Colossal Patterns
- **Robustness of a Colossal Pattern**: a colossal pattern is robust tends to have much more core patterns than small patterns

- **(d,t)-robustness**: a pattern $\alpha$ is *(d,t)-robust* if **d** is the maximum number of items that can be removed from $\alpha$ for the resulting pattern to remain a **t-core** pattern of $\alpha$

- a (d,t)-robust pattern $\alpha$ has $O(2^d)$ core patterns

- **Pattern distance**: the pattern distance of pattern $\alpha$ and $\beta$ is defined as:  
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251126150254.png]]
- 1 minus the ration between the cardinality of their intersection and the cardinality of their union

- if two patterns $\alpha$ and $\beta$ are both core patterns of a same pattern, they would be bounded by a *ball* of a radius specified by their *core ration t* 
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251126150357.png]]

- once we identify one core pattern we will be able to find all the other core patterns by a bounding ball or radius **r(t)**


### Example: Core Patterns
- A colossal pattern has far more core patterns than a small-sized pattern
- A colossal pattern has far more core descendants of a smaller size c
- A random draw from a complete set of pattern of size c would more likely to pick a core descendant of a colossal pattern
- A colossal pattern can be generated by merging a set of core patterns
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251123212037.png]]

### Colossal Patterns Correspond to Dense Balls
- due to their robustness, colossal pattern correspond to dense ball with a $O(2^d)$ population 
- a *random draw* in the pattern space will hit somewhere in the ball with high probability
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251123212050.png]]


### Idea of Pattern-Fusion Algorithm
- generate a **complete set of frequent patterns up** to a small size (we create pattern up to a certain size)
- randomly pick a pattern $\beta$, and $\beta$ has a high probability to be a core-descendant of some colossal pattern $\alpha$
- identify all the $\alpha$'s descendants in this complete set, and merge all of them, this will generate a much larger core-descendant of $\alpha$
- then we select K patterns obtained in this way, this will be the candidate pool for the next iteration


### Pattern-Fusion: The Algorithm
- **Initialization (Initial pool)**: use an existing algorithm to mine frequent patterns up to a small size (e.g. 3)
- **Iteration (Iterative Pattern Fusion)**: at each iteration, K seed patterns are randomly picked form the current pattern pool 
- for each seed pattern picked in this way, find all the patterns within a bounding ball centered at the seed pattern
- all these patterns in a ball are fused together to generate a set of *super-pattern*. All the super pattern generated will form a new pool of pattern for the next iteration
- **Termination**: when the current pool contains no more than K patterns at the beginning of an iteration

![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251126151255.png]]


### Why Is Pattern-Fusion Efficient?
- It avoid explosion in mining all the mid-sized pattern and use a shortcut to obtain efficiently the colossal pattern 
- The larger the pattern, the greater the chance it will be generated
- The more distinct the pattern, the greater the chance it will be generated


### Experimental Setting
- most of times is impossible to use the classical approach
- we have already assumed that the obtained solutions are just approximation, we want to know how much they are approximation, then we need to prove that we can arrive to this approximation in a reasonable time, to do so we will perform experiment on tree dataset 
- from the experiments we observe that the runtime do not explode as n increase, and we obtain a subset of K colossal patterns from the set of all the colossal subpatterns
- we suffer when the number of items in the colossal pattern decreases 
- the computational time remain approximately constant even if we diminish the minsup

## Mining Compressed or Approximate Patterns
### Mining Compressed Patterns: δ-clustering
- The **Compressed Patterns** are a subset of frequent pattern that represent all the other frequent patterns without loosing information on the support
- They allow to reduce the number of saved pattern without loose information
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260311112650.png]]

- We can measure the distance between two patten with the **Jaccard distance**, with:
  - $T(P)$ the set of transaction that contain the pattern P
  - $T(P1​)∩T(P2​)$ the set of transaction that contain *both* P1 and P2
  - $T(P1​)∪T(P2​)$ the set of transaction that contain *at least* P1 or P2
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251123212236.png]]
- The *distance* between Pattern P1 and P2 is equal to: 1 minus the number of transactions that contain both pattern, divided by the number of transactions that contain at least one pattern


- $\delta$ $clustering$ find for each pattern P, all patterns S (included in P) which can be expressed by P and with their distance that are less than $\delta$ 

###### Example
- here we have 5 pattern, if we keep all of them we have no compression, P3 is the *max pattern*, but if we keep only him we loose some information (on the support of the subpattern), we would like as output P2, P3, P4 that is compressing information, but we are not loosing so much information 
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251123212240.png]]

### Redundancy-Award Top-k Patterns
- Mining the top-k most frequent patterns is a strategy for reducing the number of patterns returned during mining
- but often they **are not independent**, but clustered in small regions (e.g. the richest cities could come all from the same country)

- To resolve this problem we aim to keep the *redundancy-aware top-k* patterns. So pattern must have high significance and low redundancy 
- We find this kind of patterns using the measure **MMS** (**Maximal Marginal Significance**) 

- A *Significance* Measure $S$ is a function that map a pattern $p \in P$ to a real value, such that $S(p)$ is the degree of interestingness (or usefulness) of the pattern p
  - **Objective measure** depend only on the structure of the given pattern and the underlying data used in the discovery process
  - **Subjective measure** are based on user beliefs in the data, so they depend on the user that is examining the data

- The *Redundancy* ($R$) between two pattern is defined as the sum of the significance of the patterns, minus the significance of their union  $$R(p,q) = S(p)+S(q)-S(p,q)$$
- The ideal redundancy measure $R(p,q)$ is hard to find, but can be approximated using the distance between patterns
- The problem of finding redundancy-aware top-k patterns can thus be transformed into finding a k-pattern set that *maximizes the marginal significance*

![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251123212256.png]]

- pattern do not consider order
- in sequence instead order is relevant 



# 09 High-dimensional Clustering
- Classical Clustering algorithm suffer from the curse of dimensionality problem, so they are not appropriate for high dimensional data

- Clustering should not only consider dimensions but also attributes (DA RIVEDERE)

- There are two approach to work with high dimensional data:
  - **Feature transformation**: fuse attribute to create attribute in less dimension, e.g. PCA and SVD, those techniques are more effective if features are *correlated and redundant*
  - **Feature selection**: find a subspace where data have *nice clusters*


- **Problem** in high dimensional data clustering:
	- When we have a lot of dimension some of them can be irrelevant, and those irrelevant dimensions may mask the cluster
	- We could not have cluster in the overall space, but we could have it in subspace 
	- Distance measure become meaningless in high dimension
	

- **Subspace cluster**: search for clusters existing in subspaces of the given high dimensional data space (e.g. CLIQUE, ProClus, and bi-clustering approaches)
- **Dimensionality reduction approach**: construct a lower dimensional space and then apply classical clustering approach (e.g. Dimensionality reduction methods and spectral clustering)

### Curse of Dimensionality
 - **Curse of dimensionality**: adding more dimensions make points further apart, for this reason data becomes *sparse*, and *distance measure becomes meaningless*
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260314161041.png|300]]
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260314161046.png|300]]


### Why Subspace Clustering
- If we consider all the original dimensions is difficult to find cluster
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260312151246.png]]

- But in some *subspace* (considering one or more dimensions) the same data can be easily divided: 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260312151317.png]]
- sometimes instead of analyze the data in the original space, by projecting them into subspaces it is much easier to divide them in cluster

*but how can we determine those subspace?*

### Subspace Clustering Methods
- Methods to find subspaces:
  - **Bottom up approaches**: start from a low dimensional subspace and search for an higher dimensional subspace (e.g. CLIQUE)
  - **Top down approaches**: start from the full space and search smaller subspaces recursively (e.g. PROCLUS)

- We can find the subspaces using distance, density or correlation

- **Correlation method**: use PCA to derive a set of new uncorrelated dimension and then mine cluster in this new space or its subspaces

- **Bi-clustering methods**:
  - Optimization-based methods
  - Enumeration methods

### Bi-Clustering Methods
- **Bi-Clustering** are approach where we cluster both objects and attributes simultaneously, we are searching *both clusters and the subspace at the same time*

- there are **four requirements** to be respected for obtain a Bi-Cluster:
  1. Only a *small set of objects* participate in a cluster
  2. A cluster only involves a *small number of attributes*
  3. An object may *participate* in multiple clusters, or does not participate in any cluster at all
  4. An attribute may be *involved* in multiple cluster, or it is not involved in any cluster at all
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260314162336.png|300]]

##### Example
- Let A = {a1... an} be a set of genes
- Let B = {b1... bn} be a set of conditions
- Let $E = [e_{ij}]$ be a gene expression in the data matrix

 - A **Bi-Cluster** is a submatrix where genes and conditions follow some *consistent patterns*

- There are four basic cases called **ideal cases**:
  - **1** All the values are the same in the matrix $$e_{i,j} = c \quad \forall i,j \in I \text{x} J$$ ![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260314163224.png]]
  - **2** Constant values on the row, each row will have a constant value c plus the adjustment $a_i$ (it is possible to have also constant values of the columns with an adjustment on the columns) $$e_{i,j} = c + a_i$$ ![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260314163219.png]]
  
  - **3** We can have an adjustment on both rows and columns (here the difference between two consecutive element in a row or in a column is fixed) $$e_{i,j} = c + a_i + b_j$$ ![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260314163212.png]]
  
  - **4** Coherent evolutions on rows, we have the same trend of variation between element of the same rows (but not always the same difference) ![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260314163206.png]]


### Bi-Clustering Methods
- In reality data is *noisy*, so we don't try to identify Bi-cluster, but *an approximation of them*, to do so there are two approaches:
  - **Optimization method**: we want to find a submatrix at a time to achive the best significance as a bi-cluster, e.g. $\delta$*-cluster algorithm*
  - **Enumeration method**: we use a *tolerance threshold* to specify the allowed degree of noise to mine the bi-cluster, then we try to enumerate all submatrices as bi-cluster that satisfy the requirements, e.g. $\delta-p$*Cluster  algorithm* 


### Bi-Clustering for Micro-Array Data Analysis
- In the left figure we represent the data with all the attributes, and we cannot find any regularities in those three objects
- in the central and right figures we are isolating some of the attributes, and here we can easily find some pattern (they are bi-cluster with coherent values and with coherent evolution respectively) 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260314164148.png]]
- some object can appear in multiple clusters (so cluster may not be exclusive)

- *but how can we investigate if we really have bi-cluster?* try all the possible combination is computationally heavy, we need another approach... 

### δ-Bi-Cluster
- We accept to find **approximation** of Bi-Cluster because data can be noisy
- Considering a generic matrix $IxJ$, we have:
  - $e_{i,J}$ the mean of the i-th row
  - $e_{I,j}$ the mean of the j-th column
  - $e_{I,J}$ the mean of all elements of the matrix

- We can measure the **quality** of the sub matrix as a bi-cluster, with the **mean squared residue value** $$H(I \times J) = \frac{1}{|I||J|} \sum_{i, j}(e_{ij} - e_{iJ} - e_{Ij} + e_{IJ})^2$$
- The sub-matrix is a **delta bi cluster** if the means squared residue value is less than the threshold delta that is greater than zero ($H(I \times J) < \delta$ ), and if $\delta = 0$ then we have a **perfect bi-cluster**
- The bigger is the threshold delta, the bigger is the noise that we tollerate


### The δ-Cluster Algorithm
- **Maximal $\delta$-bi cluster**: is a $\delta$-bi-cluster $IxJ$ such that there does not exists another $\delta$-bi-cluster $I'xJ'$ which contains $IxJ$
- It is costly to compute, we use a greedy search to obtain local optimal clusters 

- There are two phase to obtain the Maximal $\delta$-bi cluster:
	- **Deletion phase**: we start from the whole matrix, then remove rows and columns  with the highest *mean squared residue*, while the mean squared residue is over delta 
	- **Addition phase**: we expand iteratively the matrix as long as the requirements are maintained, we consider all the rows/columns not involved in the current bi-cluster IxJ by calculating their mean squared residues, and add the row/column with the smallest mean squared residue


- With this approach we obtain just the maximum delta bi cluster (just one)
- If we want to obtain *different delta-bi-cluster* we can execute different times this algorithm, but if we execute it with the same condition we obtain the same bi cluster, we need to add randomness, to obtain different results, to do so we need to put some random number instead of some of the IxJ matrix element to destroy the old patterns, so the algorithm will be constrained to look for some patterns and will find new delta bi clusters

### δ-pCluster
- A submatrix $I \times J$ is a bi-cluster with perfect coherent values if and only if $$e_{i1,j1} - e_{i1,j2} = e_{i1,j2} - e_{i2,j2}$$ for any 2x2 matrix of $I \times J$, we can define the value of the **p-score** as:
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260314184238.png]]
so $$p-score = |(e_{i1,j1} - e_{i1,j2}) - (e_{i1,j2} - e_{i2,j2})|$$
- A submatrix is a $\delta$**-pCluster** if the p-score of *every* 2x2 submatrix is at most $\delta$

- The p-score controls the noise on every element in a bi-cluster, while the mean squared residue captures the average noise
- **Monotonicity**: tells that if you have a matrix that is a $\delta$-pCluster, then any of its submatrix will be it too

- A $\delta$-pCluster is **maximal** if you cannot add more rows or columns and remain a delta p cluster


### MaPle: Efficient Enumeration of δ-pClusters
- **MaPle** is based on the downward closure property
- For each condition combination $J$, find the maximal subsets of genes $I$ such that $I x J$ is a $δ$-pClusters
- If $IxJ$ is not a submatrix of another $\delta$-pCluster, then is a maxima $\delta$-pCluster
- It is similar to mining frequent closed itemsets



### Dimensionality-Reduction Methods
- The idea of dimensionality reduction is to eliminate some dimension in a smart way
- For instance, in this graph we cannot find any cluster if we project points along x or y axis, but if we project them in a obliquus axes, then we can reduce dimension and maintain clusters 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260314185012.png|300]]

- We need to find those axes that allow to reduce dimension and keep the cluster separated
- One method is **Spectral clustering**, that combine feature extraction and clustering, there are a lot of different spectral clustering methods, one of them is the *Ng-Jordan-Weiss algorithm*

### Spectral Clustering: The Ng-Jordan-Weiss (NJW) Algorithm
- Given a set of objects $o1, …, on$, and the distance between each pair of objects, $dist(o_i, o_j)$, it find the desired number $k$ of clusters
- Calculate an **affinity matrix** $W$, where $\sigma$ is a scaling parameter that controls how fast the affinity $W_{ij}$ decreases as $dist(o_i, o_j)$ increases
$$W_{ij} = e^-{\frac{dist(o_i, o_j)}{\sigma^2}}$$ 
and set $W{ii} = 0$ 


- Then derive a matrix $A = f(W)$, and $D$ a diagonal matrix such that $D_{ii}$ is the sum of th e i-th row of W???
$$D_{ii} = \sum_j W_{ij}$$

- Then A is equal to: $$A = D^{- \frac{1}{2}} W  D^{- \frac{1}{2}}$$
- Finds the $k$ leading eigenvectors of $A$
- A vector $v$ is an **eigenvector** of matrix $A$ if $Av = λv$, where $λ$ is the corresponding **eigen-value**

- Using the $k$ leading eigenvectors, project the original data into the new space defined by the $k$ leading eigenvectors, and run a clustering algorithm, such as k-means, to find k clusters

- Assign the original data points to clusters according to how the transformed points are assigned in the clusters obtained



- Complete process:
	- we start from the dataset
	- we compute the affinity matrix
	- we compute the k eigenvector of the affinity matrix
	- we construct the new space with the transformed dimension
	- we apply the cluster in the new space 
	- we project back the cluster in the original data space
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260314185237.png]]
- It is computationally expensive for large matrixes
- It can be combined with other clustering methods such as bi-clustering
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260314185412.png]]
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260314185419.png]]
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260314185424.png]]



# 010 Constrained Clustering
- *Example of Constrained Clustering*: locate the closest ATM machine
- If you don't account for the geographical obstacle like rivers, bridges, hills, you will end up in a clustering like the one on the right, that does not really take in account all constraints
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260403100508.png]]

- With classical clustering algorithm we cannot impose any constraint, the clusters are created only from the objects, and we would obtain wrong results

### Categorization of Constraints
- Main type of constraints:
  - Constraints on instances
  - Constraints on clusters
  - Constraint on similarity
  - Hard/Soft Constraints

- **Constraints on instances**: specify how a pair or a set of instances should be grouped in the cluster analysis. It is divided in:
  - *must-link(x, y)*: x and y should be grouped into one cluster
  - *cannot-link(x, y)*: x and y shouldn't be grouped into one cluster, for instance if $distance(x, y) > d$ 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260403101105.png|400]]

- **Constraints on clusters**: specify a requirement on the clusters, for instance:
  - specify the min number of objects in a cluster
  - the max diameter of a cluster
  - the shape of a cluster (e.g., a convex)
  - number of clusters (e.g., k)

- *δ-constraint (Minimum Separation)*: The δ-constraint enforces **inter-cluster separation**, ensuring that different clusters are sufficiently far apart
- For any two distinct clusters $S_i$ and $S_j$, every pair of points across the two clusters must satisfy: $D(s_p, s_q) \ge \delta$
  where $s_p \in S_i$, $s_q \in S_j$, and $D(\cdot,\cdot)$ is a distance function.
- So the distance between points of different cluster are at least $\delta$

- *ε-constraint*: The ε-constraint enforces **intra-cluster cohesion**, ensuring that points within the same cluster are sufficiently close.
- Each cluster must contain at least two elements: $|S_i| > 1$
  - For every point $s_p \in S_i$, there exists another point $s_q \in S_i$, with $s_p \neq s_q$, such that: $D(s_p, s_q) \le \varepsilon$
  - Every point must have at least one **neighbor within distance $\varepsilon$**.


- It is possible to convert constraint on clusters on constraint on instance:
  - *δ-constraint*: every point x must link only to points y with distance less than δ ![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260403102401.png|100]]
  - *ε-constraint*: every point x must link at least to one point y with distance less or equal to ε
  ![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260403102421.png|100]]


- **Constraints on similarity measurements**: specifies a requirement that the similarity calculation must respect, e.g. to compute the shortest distance between people in a plaza i cannot cross a wall with the trajectory

##### Hard vs. soft constraints
- A constraint is **Hard** if a clustering that violates the constraints is unacceptable
- A constraint is **Soft** if a clustering that violates the constraints is not preferable, but acceptable when no better solution cannot be found. they are also called *preferences*


### Clustering with Constraints
- **Clustering with constraints**: Partition unlabeled data into clusters and use constraints to aid and bias clustering
- *Goal*: put similar points in the same cluster, different point in different cluster, and respect all the constraint 
- *Enforcing Constraints*:
  - **Strict enforcement**: find best feasible clustering respecting all constraints
  - **Partial enforcement**: find best clustering maximally respecting constraints

- Example of clustering with constraint:
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260403103506.png|500]]
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260403103523.png|500]]s

### Categorization of Constraints
- **Conflicting or redundant constraints**: it is possible to have conflictual constraints (in case of hard one we will not have any solution), e.g.
	must-link(x, y) if dist(x, y) < 5
	cannot-link(x, y) if dist(x, y) > 3.
- If a dataset has two object with dist(x,y) = 4, then no clustering can satisfy both constraints simultaneously

 - *How can we measure the quality and the usefulness of a set of constraints?*

 - To do this we have two metrics:
   - **Informativeness**: the amount of information carried by the constraints that is beyond the clustering model. Given a data set, D, a clustering method, A, and a set of constraints, C, the informativeness of C with respect to A on D can be measured by the fraction of constraints in C that are unsatisfied by the clustering computed by A on D
   - **Coherence** of a set of constraints: the degree of agreement among the constraints themselves, which can be measured by the redundancy among the constraints


### The Effects of Constraints on Clustering Solutions
- Constraints divide the set of all plausible solutions into two sets:
  - $feasible$ and $infeasible$: $S = S_F ∪ S_I$


### Handling Hard Constraints
- Handling hard constraints: Strictly respect the constraints in cluster assignments
- The **COP-k-means algorithm**: 
  - merge all the points in a must-link constraints into a super-point equal to the mean of those point and with a weight that represent the number of point
  - modify the center-assignment process in k-means to a nearest feasible center that respect all the cannot-link constraints
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260403104432.png]]

### Example: COP-K Means
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260403105637.png|500]]
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260403105643.png|500]]
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260403105648.png|500]]

### Handling Soft Constraints
- Soft Constraints are treated as an *optimization problem*: when a clustering violates a soft constraint, a **penalty** is imposed on the clustering
- The objective is to minimize the constraint violation penalty, and this maximize the clustering quality



- for instance, **CVQE** (*Constrained Vector Quantization Error*) **algorithm**: conduct k-means clustering while enforcing constraint violation penalties

- The objective function is the sum of distance used in k-means, adjusted by the constraint violation penalties
  - *Penalty of a must-link violation*: if two object must be linked but they are assigned to two different cluster the distance of the centers they are assigned is added to the objective function
  - *Penalty of a cannot-link violation*: if two object cannot be linked but they are assigned to the same cluster with center c, we add the the objective function the penalty equal to the distance between the center c, and the closest center c' that can accomodate one of the two objects

### Speeding Up Constrained Clustering
- It is more costly to compute constrained clustering
- e.g. Clustering with obstacle objects: 
  - Cluster people as moving objects in a plaza.
  - Euclidean distance is used to measure the walking distance.

- However, constraint on similarity measurement is that the trajectory implementing the shortest distance cannot cross a wall.
- Distance has to be derived by geometric computations: the computational cost is high if a large number of objects and obstacles are involved.


##### Visibility
- A point $p$ is **visible** from another point $q$ if the straight line joining $p$ and $q$ does not intersect any obstacles.
- A **visibility graph** is the graph, $VG = (V,E)$, such that each vertex of the obstacles has a corresponding node in $V$ and two nodes, $v1$ and $v2$, in $V$ are joined by an edge in $E$ if and only if the corresponding vertices they represent are visible to each other.

- Let $VG’ = (V’,E’)$ be a visibility graph created from $VG$ by adding two additional points, $p$ and $q$, in $V’$ 
- $E’$ contains an edge joining two points in $V’$ if the two points are mutually visible.
- The shortest path between two points, $p$ and $q$, will be a sub-path of $VG’$
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260403110847.png]]


-  To reduce the cost of distance computation between any two pair  of objects or points, several pre-processing and optimization techniques can be used.
-  One method groups points that are close together into **microclusters**
- This can be done by first *triangulating* the region $R$ into triangles, and then grouping nearby points in the same triangle into microclusters, using a method similar to BIRCH or DBSCAN
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260403110943.png]]


-  By processing microclusters rather than individual points, the overall computation is reduced.
- After that, precomputation can be performed to build two kinds of join indices based on the computation of the shortest paths:
	- (1) **VV indices**, for any pair of obstacle vertices, and
	- (2) **MV indices**, for any pair of *microcluster* and obstacle vertex.
- Use of the indices helps further optimize the overall performance.


### An Example: Clustering With Obstacle Objects
- To create the constraints we start from a dataset with some labeled instances, instances with the same label will have the *must-link* constraint, object with different label will have the *cannot-link* constrain. so we have a semi-supervised approach
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260403110908.png]]



# 011 Graph and Network Clustering

### Graphs and Networks
- **Network**: a collection of entities interconnected with links (e.g. social media, biological, communication)
- Networks are important because they allow to understand the model of a complex system
- Studying singular entities gives only a partial view of the system, because everything is connected
- In mathematics networks are called **graph**, the entities are called nodes, and the link edges

### Network Nowadays
- Nowadays networks are huge, it is difficult to visualize, and process them
- They are the result of our ability to collect more, better, and more complex data, and by the willingness of users to contribute data

- Current problems related to network:
  - Ranking the *importance of a node* (e.g. rank the importance of a webpage in a search on the web using links between pages)
  - How *information propagate* in social and information network? What items become viral? Who are the influencers and trend-setters?


- **Linking prediction**: given a snapshot of a network at time t we want to predict the *edges that will be added* to the network from time t to a given future time t'.
  - this allow to identify suspect relationships, and accelerate the growth of a social network

- **Network Content**: we can perform a lot of analysis on the network to infere the preferences of the user

- **Social Media**: they are nowadays the main vehicle to spread news and information, from them we can also perform sentiment mining (so we can easily understand the sentiment of people related to a topic) and track the evolution of an event 

- A **Community** is a cohesive subgroup of actors among whom there are relatively strong, direct, intense and positive ties 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260403113143.png]]


- *Homophily*: “Birds of a feather flock together”
- **Community Evolution**: 
  - *social influence*: people become similar to those they interact with
  - *selection*: people seek out similar people to interact with
- Both processes contribute to homophily

- **Bi-partite graph**: a graph with two subgroups, a node of one subgroup have ties only with the nodes of the other subgraph 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260403113400.png|300]]

- The **network** is, in general, a **weighted graph** because an edge between two nodes can carry a weight representing the strength of the ties

### Basic Network Notation
- **Objects**: nodes, vertices, $N$
- **Interactions**: link, edges $E$
- **System**: network, graph $G(N,E)$

- A *Network* often refers to real system (language: network, node, link)
- A *graph* is a mathematical representation of a network (language: graph, vertex, edge)

- To build a graph you need to define which are the nodes and witch are edges, sometimes there is a unique unambiguous representation, in other case you can have different possibilities, that changes the feasible uses of the graph

### Clustering Algorithm on Graph
- *How can we perform a clustering algorithm on a graph?*
- There are two different approach:
  - We can use standard clustering algorithms, using a new distance metrics (e.g. Geodesic Distance, or SimRank)
  - We can use Specific Graph Clustering Methods 

### Geodesic Distance
- The **Geodesic distance**, define the distance between two vertices in a graph equal to the shortest path between the vertices, so the *number of edges*
-  Is equal to infinite if the two nodes are not connected

- **Eccentricity of v, eccen(v)**: The largest geodesic distance between $v$ and any other vertex $u ∈ V − \{v\}$, e.g. eccen(a) = eccen(b) = 2; eccen(c) = eccen(d) = eccen(e) = 3
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260411211529.png]]


- **Radius of graph G**: The minimum eccentricity of all vertices, i.e., the distance between the “most central point” and the “farthest border” $r = min v∈V eccen(v)$, e.g., radius (g) = 2     

- **Diameter of graph G**: The maximum eccentricity of all vertices, the largest distance between any pair of vertices in G $d = max v∈V eccen(v)$, e.g., diameter (g) = 3 

* A **Peripheral vertex** is a vertex that achieves the diameter. E.g., Vertices c, d, and e are peripheral vertices
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260403114925.png|300]]

- But not in all case two points are similar if they are connected by a small path, so this distance is not always so useful

### SimRank
- Some other notion of similarity in a social graph:
   - two nodes are similar if they have *similar neighbors*
   - two nodes are similar if performing a random walk from them, the probability of reaching the same nodes is high

- **SimRank** is based on the idea that two nodes are similar if they have similar neighbors

- Having a direct graph $G = (V,E)$
- in the **in-neighborhood** of v: there are all the nodes $u$ such that the pair $(u,v)$ *ends* with $v$
- in the **out-neighborhood** of v: there are all the nodes $w$ such that the pair $(v, w)$ *starts* with $v$

- Given a constant $C \in (0,1)$, SimRank defines the similarity between $u$ and $v$ as: $C$, multiplied by the **average similarity between all pairs of their in-neighbors**
$$  
s(u, v) = \frac{C}{|I(u)| \, |I(v)|} \sum_{x \in I(u)} \sum_{y \in I(v)} s(x, y)  
$$  
- where $I(u)$ and $I(v)$ are the in-neighbors of $u$ and $v$
- Two nodes are similar if their in-neighbors are themselves similar

-  If a vertex does not have any neighbor we define its similarity with any other vertex as zero ($s(u,v)=0$)


- SimRank uses the SimRank to be measured, how it is possible? we initialize its value, and then update its value for some iteration (usually 5)
  - Let n be the number of nodes in the graph G, for each iteration i we have $n^2$ iteration $s_i(*, *)$ where $s_i(u,v)$ gives the score between $u$ and $v$ at iteration $i$, and we initialize $s_0(*,*)$ where $s_0(u,v)$ is a *lower bound* on the actual value, where it is equal to zero if $u \ne v$ and 1 if $u=v$ 

- so, to compute $s_{i+1}(u,v)$ we use $s_i(*,*)$
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260403134550.png]]

- the $s_i(*,*)$ values are non decreasing as i increase
- the algorithm has a complexity of $O(Kn^2d_2)$, where $d_2$ is the average of $|I(u)||I(v)|$, and $K$ is the number of iterations

### Similarity based on random walk
- A **Strongly connected graph** is a graph where a path exists between every two nodes, the expected distance between u and v is equal to
$$  
d(u,v) = \sum_{t: u \rightsquigarrow v} P(t)\, l(t)  
$$
- we consider all the possible **tour** ($t$) from u to v, for each tour we have $P(t)$ the probability of choosing that tour by $l(t)$ the length of the tour
- a tour is a sequence $t=(w_1​,w_2​,…,w_k​)$ where $w_1 = u, w_k=v$ (and cannot appear in the middle), and its length is $l(t) = k-1$, the number of traversed vertex
- The probability of a tour is:  
$$  
P(t) = \prod_{i=1}^{k-1} \frac{1}{O(w_i)}  
$$  where $O(w_i)$ is the number of out-neighbors of $w_i$ 
- At each step choose a neighbor with probability $\frac{1}{O(w_i)}$, the total probability is the product of the local probability


- if $u=v$ then $d(u,v) = 0$ 
- It represent the mean length of a path form u to v using a random walk


- **Expected meeting distance** (*EMD*): the expected meeting distance $m(u,v)$ between u and v is the expected number of steps required before two surfers, one starting at u and the other at v, would meet if they walked (randomly) in lock-step
- The EMD is symmetric by definition
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260403135830.png|500]]

- $G^2$ represents the graph of **ordered pairs of nodes** from $G$

- A node $(a, b)$ in $G^2$ points to a node $(c, d)$ if, in $G$:
  - $a$ points to $c$, and  
  - $b$ points to $d$

- A tour in $G^2$ of length $n$ represents a pair of tours in $G$ also having length $n$

- **Example interpretation**:
  - Nodes represent pairs of Web pages:
    - $(\text{ProfA}, \text{ProfB})$
    - $(\text{StudentA}, \text{StudentB})$
    - $(\text{Univ}, \text{Univ})$
  - Edges in $G^2$ reflect **simultaneous links** in the original graph $G$

![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260403140042.png]]


## SimRank and Expected Meeting Distance
- The **expected meeting distance** (*EMD*) $m(u,v)$ is defined on the graph $G^2$:
  - It measures the expected distance from $(u,v)$ to a **singleton node** $(x,x) ∈ V^2$

  - A singleton node means both random walkers are at the **same node** $x$ 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260403140631.png]]

- the sum comprehend: 
  - all tours starting from $(u,v)$
  - that reach a singleton node **at the end, and only at the end**

- Even if $G$ is strongly connected, $G^2$ may not be it
- In this case:
  - there may be **no valid tours**
  - so $m(u,v) = \infty$

- This creates issues:
  - some paths may reach a meeting point
  - others may never meet


- **Solution** (*Expected-f Meeting distance*): Instead of using the raw distance, apply a function $f$
- The similarity $s'(u,v)$ is defined as:  
$$  
s'(u,v) = \sum_{t:(u,v)\rightsquigarrow(x,x)} P(t)\, C^{l(t)}, \quad C \in (0,1)  
$$
- where:  
- the sum is over all tours $t$ from $(u,v)$ to any meeting state $(x,x)$  
- $P(t)$ is the probability of the tour  
- $l(t)$ is the length of the tour  
- $C$ is a decay factor  


- **Interpretation**:  
- similarity is the total contribution of all possible meeting paths  
- shorter and more probable paths contribute more
  - $f$ must be:
    - non-negative
    - monotonic
    - bounded on the domain$[0, \infty]$ 

- So we compute:
  - the expected value of $f(l(t))$ instead of $l(t)$

- This maps distances into a **finite range**
- Produces a similarity score:

  - $s'(u,v) = 1$ → same node ($u = v$)
  - $s'(u,v) = 0$ → no meeting possible
  - $s'(u,v) \in [0,1]$ → general case

![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260403140947.png]]


- It has been proven that:$$
  s(u,v) = s'(u,v)
  $$

- Therefore, **SimRank = expected-$f$ meeting distance**
- So *SimRank is based on both structural context and random walk*


### Graph Clustering: Sparsest Cut
- A good clustering:
  - has **strong connections within clusters**
  - has **weak connections between clusters**

- A **cut** $C(S,T)$ splits the vertices $V$ into $S$ and $T$ that are disjoint, and united give $V$
  - $V = S \cup T$
  - $S \cap T = \emptyset$

- The **cut set** of a cut are the edges connecting $S$ to $T$ 
- The **cut size** is the number (or total weight) of the edges in the cut set

---

- A **Minimum cut** is a cut with minimum cut size
- Can be computed efficiently, may produce *unbalanced clusters*, e.g. isolating a single node
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260403142340.png|500]]

- A better cut is the **Sparsest cut**, a cut whose edges in the cut set are those connecting the two "natural cluster"
- *Intuition*: choose a cut where, for each vertex $u$ that is involved in an edge in the cut set, most of the edges connecting to $u$ belong to one cluster

- With T, the number of vertices, the **sparsity** of a cut $C = (S,T)$ is defined as: $$\phi = \frac{\text{cut size}}{min\{|S|,|T|\}}$$

### Graph Clustering: Sparsest Cut
- A cut is *sparsest* if its sparsity is not greater than that of any other cut
- It is better to prefer solution that are sparse (few edges crossing the cut) and balanced (closed to a bisection)
- The problem is NP-Hard

- For $k$ clusters, the **modularity of a clustering** assesses the *quality* of the clustering:

$$Q = \sum_{i=1}^k (\frac{l_i}{|E|}-(\frac{d_i}{2|E|})^2)$$
- with:
- $l_i$: number of edges between vertices in the i-th cluster
- $d_i$: the sum of the degrees of the vertices in the i-th cluster where degree of a vertex 
- $u$: number of edges connecting to u  
- $\frac{l_i}{|E|}$: probability that an edge is in cluster $i$
- $(\frac{d_i}{2|E|})$: probability that an edge would fall in cluster $i$

- The **Modularity** of a clustering of a graph is the difference between the fraction of all edges that fall into individual clusters and the fraction that would do so if the graph vertices were randomly connected
- The optimal clustering of graphs *maximizes* the modularity



- **Problem** in finding a good cut:
  - It require an high computational cost
  - Some graphs may involve weighted vertex and loops
  - Some graphs can be very big
  - Some graphs are sparse, and this create a sparse similarity matrix


## Graph Clustering Methods
- There exists two kinds of methods:
  1. **Clustering methods for high-dimensional data**: extract a similarity matrix from the graph and use a similarity measure, then it apply a classical clustering algorithm for high dimensional data
  2. **Clustering methods designed specifically for clustering graphs**: exploit the characteristics of graphs to perform the clustering tasks




### Density-based clustering of Networks
- **Clique**: now many of the same people, regardless of the size of the group
- **Hubs**: know many people in different groups but belong to no single group
- **Outlier**: are connected with few vertex, does not belong to any group
- The **Immediate neighbor** ($\Gamma (v)$) of a vertex is the list of vertex connected directly with him 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260403143733.png|500]]


### Structure Similarity 
- The **Structural Similarity** between the vertex $v$ and $w$ ($\sigma(v,w)$), is the cardinality of the intersection between the immediate neighbor of $v$ and $w$, divided by the root  of the cardinality of immediate neighbor of $v$ and the cardinality of the immediate neighbor of $w$
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260403144140.png|300]]
- Structural similarity is large for clique and small for hubs and outlier


### Structure Connectivity
- **SCAN** (*Structural Clustering Algorithm for Networks*) uses a similarity threshold $𝜀$ to define the cluster membership

- The $\epsilon$**-neighborhood** of a vertex $v$ are the neighbor directly connected with v, that has a similarity value with v of at least $\epsilon$
$$  
N_\varepsilon(v) = \{ w \in \Gamma(v) \mid \sigma(v,w) \ge \varepsilon \}  
$$

- A **core vertex** is a vertex whose cardinality of its $\epsilon$-neighborhood is greater or equal than mu, so it has at least $\mu$ neighbor similar to him
$$
CORE_{\varepsilon,\mu}(v) \iff |N_\varepsilon(v)| \ge \mu
$$

- Scan create clusters from core vertices, it use the rule: "if a vertex $v$ is in the $\epsilon$-neighborhood of $v$ then, $v$ belongs to the same cluster of $u$"
  1. it find all the core nodes
  2. expands the clusters adding similar neighbor 
  3. continue until there are no more node to add

- The main **disadvantage** is that we need to set a good value for the two parameters $\epsilon, \mu$ 


- A node w is **Directly Reachable** from a node v if:
  - $v$ is a core node 
  - $w$ is a similar neighbor of $v$ (in its $\epsilon$-neighborhood)
$$  
DirRECH_{\varepsilon,\mu}(v,w) \iff CORE_{\varepsilon,\mu}(v) \;\land\; w \in N_\varepsilon(v)  
$$

- A node $v$ is **Structure Reachable** from a node $u$ if there exist a chain of nodes $u→w1​→w2​→⋯→v$ where each step is a direct reachability  

- Two nodes $v$, $w$, are **Structure Connected** if there exist a node $u$, from who they are both structure reachable
$$  
CONNECT_{\varepsilon,\mu}(v,w) \iff \exists u \in V :  
RECH_{\varepsilon,\mu}(u,v) \land RECH_{\varepsilon,\mu}(u,w)  
$$

- All the nodes in a cluster are *structure connected* among them
- A cluster is **maximal** if a node is a reachable from a cluster node, then that nodes is included in the cluster

- Hub do not belong to any cluster, but connect different cluster
- Outliers do not belong to any cluster
- example:
	![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260403145120.png]]
	![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260403145124.png]]
	![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260403145131.png]]
	![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260403145139.png]]
	![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260403145145.png]]![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260403145150.png]]
	![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260403145157.png]]
	![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260403145202.png]]
	![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260403145207.png]]
	![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260403145212.png]]
	![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260403145218.png]]
	![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260403145223.png]]
	![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260403145227.png]]
	![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260403145232.png]]
	![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260403145237.png]]
	![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260403145246.png]]



# 012 Sequential Pattern Mining
### Introduction
- In classical pattern mining the *order* of items in a pattern was irrelevant 
- If you want instead to find *Frequent sequence* the order become relevant

- **Sequential pattern mining** discovers frequent subsequences as patterns in a sequence database
- A **sequence database** stores records, whose are sequences of *ordered events*, with or without notions of time

- For instance a sequence database is retail customer transactions or purchase sequences in a grocery store showing, for each customer, the collection of store items they purchased every week for one month
- it is possible to have as element list of event, we want to find pattern like (after event A usually it happen event B)

- Record are stored as follow: $\text{[Transaction/Customer ID, <Ordered Sequence Events>]}$
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260403155451.png]]

### Da saltare??? Un esempio???
- We consider for now as our data the user's web navigational patterns, so the ordered sequence of events are composed by single items and not sets of item, one item is a site visited by a user, here we can see data of 4 user, that access some sites  E = {a, b, c, d, e, f }
``` python
[T1, <abdac>];
[T2, <eaebcac>];
[T3, <babfaec>];
[T4, <abfac>].
```
- From here we can extract information like "90% of user that visit product a, after immediately visit product b"

- How can we collect those kind of data? (for instance how the user interact with the website)
	- if you register the access on *server side*, they can reflect the access of a web site by multiple users, is good for mining multiple users' behavior and web recommender system, but they could be unreliable due to caching (cached page views are not recorded in server log)
	- if you register the access on *client side* we eliminate the caching problem, but to operate this we need a remote agent or a modified browser
	- if you register the access on a *proxy server*, that can reflect the requests from multiple anonymous user to multiple web servers

- There are also other technique like cookie and sniffer, but they are not much reliable (because users can refuse cookie)
- Most of the time we assume that user web visit information are recorded completely in the web server log


### Sequential pattern mining
- An **itemset** is a set of items/events drawn from a universe $I$  
  - denoted as: $(i_1, i_2, \dots, i_k)$  
  
- We are given:  
  - A **sequential database** $D$ (set of sequences)  
  - A set of k unique items $I = \{i_1, i_2, \dots, i_k\}$  
  - A **minimum support threshold** (*min_sup*)  
  
- Goal:  
  - Find all **frequent sequences** $S$, in $D$ (a sequence is frequent if it appears more than min_sup times)
  
### Sequences Representation  
- A **sequence** is an ordered list of **elements**:  
$$  
S = \langle e_1, e_2, \dots, e_q \rangle  
$$  
- Each element $e_j$ is an **itemset**  
  - Example:  
    - $\langle a (be) c (ad) \rangle$  
    - $(be)$ is an itemset inside the sequence  
  
- A **k-sequence**:  
  - sequence with $k$ elements  
  
- Important:  
  - An item appears **only once per itemset**  
  - But can appear in **multiple itemsets** in the same sequence  
  
  
### Lexicographic Order (Itemsets)  
- Itemsets are **ordered lexicographically**  
  
- Given two itemsets:  
  - $t = \{i_1, \dots, i_k\}$  
  - $t' = \{j_1, \dots, j_l\}$  
  
- Then $t < t'$ if:  
  1. They differ at position $h$, and $i_h < j_h$ (the symbol $<$ means "occurs before")
     - e.g. $(abc) < (abec)$ 
  2. Or one is a prefix of the other and shorter:  
     - e.g. $(ab) < (abc)$  
  

- This ordering is used to:  
  - compare itemsets efficiently  
  - generate candidates systematically  
  
  
### Subsequences  
- A sequence $\alpha$ is a **subsequence** of $\beta$ (written $\alpha \preceq \beta$) if:  
  - we can map each element of $\alpha$ into $\beta$ preserving order  
  - each element of $\alpha$ is a subset of the corresponding element in $\beta$  
  
- Example:  
  - $\langle ad (ae) \rangle$ is a subsequence of $\langle a (bd) b c b (ade) \rangle$  
  ![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260403161747.png]]
  
### Sequential Patterns  
- A **sequential pattern**:  
  - a sequence that appears frequently in the database  
  
- A pattern is **maximal** if:  
  - it is not a subsequence of any other frequent sequence  
  
  
### Example of Sequence Database  
- A database contains sequences like:  
  
  - $\langle a (bd) b c b (ade) \rangle$  
  - $\langle (be) (ce) d \rangle$  
  - $\langle (ah) (bf) a b f \rangle$  
  - $\langle (bf) (ce) b (fg) \rangle$  
  - $\langle (bd) c b (ac) \rangle$  
  
- With:  
  - **min_sup = 2**  
  
- Example:  
  - $\langle (bd) c b \rangle$ is a frequent sequence  
  
  
### Support of a Sequence  
- **Absolute support (count)**:  
  - number of sequences in $D$ that contain $S$  
  
- **Relative support** (or *frequency*):  
$$
\sigma(S) = \frac{\text{\# sequences containing S}}{|D|}  
$$  
- A sequence is **frequent** if:  
$$\sigma(S) \ge \text{min\_sup}$$  
  
  
### Closed Sequential Patterns  
- A frequent sequence $S_\alpha$ is **closed** if:  
  - there is no super sequence $S_\beta$ with the same support, we indicate this as:
    - $S_\alpha \preceq S_\beta$  
    - $\sigma(S_\alpha) = \sigma(S_\beta)$  
  
- Otherwise:  
  - $S_\alpha$ is absorbed by $S_\beta$  
  
- Example:  
  - If:  
    - $S_\alpha = \langle bea \rangle$  
    - $S_\beta = \langle beadc \rangle$  
  - Then:  
    - if $\sigma(S_\alpha) = \sigma(S_\beta)$ → not closed  
    - if $\sigma(S_\alpha) > \sigma(S_\beta)$ → closed  
  
- Key idea:  
  - closed patterns remove redundant information  
  ![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260403162359.png]]
  
### Sequential Pattern Mining: Algorithm Structure  
- The process is divided into 5 phases:  
  - Sort Phase  
  - Litemset Phase  
  - Transformation Phase  
  - Sequence Phase  
  - Maximal Phase  
  
  
#### Sort Phase  
- Sort the database using:  
  - Customer ID as primary key  
  - Transaction time as secondary key  
  ![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260403162518.png|300]]
- Goal:  
  - convert transaction data into customer sequences  
  
  
#### Litemset Phase  
- A **litemset (large itemset)**:  
  - itemset with support ≥ min_sup  
  
- Important property:  
  - every itemset in a frequent sequence must be a litemset  
  ![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260403162647.png|300]]

- you have to consider all the subset of itemset and check if they are frequent or not, e.g. if you have in a transaction (40,50,60), you need to check if are frequent: (40,50,60), (40,50), (50,60), (40,60), (40), (50), (60)


- Optimization:  
  - map each litemset to an integer ID  
  - allows:  
    - constant-time comparisons  
    - faster subsequence checks  
  ![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260403162721.png|300]]


#### Transformation Phase  
- Goal:  
  - speed up subsequence checking  
  
- Steps:  
  - replace each transaction with all litemsets contained in it  
  
- Remove:  
  - transactions with no litemsets  
    - (still considered for support counting)  
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260403162808.png]]

  
#### Sequence Phase  
- Goal:  
  - find all frequent sequences  
  
- Approach:  
  - similar to Apriori  
  
- Steps:  
  - use a *seed set* to generate candidate sequences  
  - count support  
  - remove non-frequent candidates  

- To perform the sequence Phase there are two families of algorithms
  - Count-All
  - Count-Some
  
- **Count-all methods**  
  - generate all frequent sequences (including non-maximal), e.g. AprioriAll  
  - is similar to the classical Apriori
  
- **Count-some methods**  
  - try to avoid non-maximal sequences  
  - focus on longer sequences first, e.g. AprioriSome, DynamicSome  
  
  
#### Maximal Phase  
- Goal:  
  - extract maximal sequences from large sequence
  
- Procedure:  
  - start from longest sequences  
  - remove all their subsequences  
  
- Idea:  
  - keep only the most informative patterns  
  
  
### AprioriAll Algorithm  
- Definitions:  
  - $L_k$: frequent sequences of length $k$  
  - $C_k$: candidate sequences of length $k$  
  
- Algorithm:  
  - Initialize:  
    - $L_1$ = frequent 1-sequences  
  
  - For $k = 2,3,\dots$:  
    - generate candidates $C_k$ from $L_{k-1}$  
    - count support  
    - keep only frequent sequences:  
$$  
L_k = \{c \in C_k \mid \sigma(c) \ge \text{min\_sup}\}  
$$
    - if $L_k$ is empty on length 1
- Final result:  
$$  
\text{Answer} = \text{Maximal sequences in } \bigcup_k L_k  
$$

### Candidate Generation (AprioriAll)  
- **Step 1: Join**  
  - combine sequences in $L_{k-1}$ with common prefix  
  
  - Example:  
    - $L_3 = \{123, 234, 124, 134, 135\}$  
    - $C_4 = \{1234, 1345, 1354, 1243\}$  
  
- When we join Lk-1's elements, we need to consider the order of the 2 non common element, we should consider each of the two order

- **Step 2: Prune**  
  - remove candidates if any subsequence is not frequent (they are not frequent if some of their subsequence are not in $L_{k-1}$)

- Example:
    - $C4 = \{1 2 3 4\}$

- Key principle:  
  - Apriori property:  
    - if a sequence is frequent → all its subsequences are frequent  
  

### AprioriAll Example
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260403164625.png]]
- in the apriori example we are not generating also the opposite combination in the join, but we should (e.g. we join 1 and 2 we obtain 1,2 and 2,1, not only 1,2)
- when Lk have just one element we stop

- If the minsup value is small then we would have a  longer sequence of sequences and this algorithm require more time 


### Key Intuition  
- Sequential pattern mining extends frequent itemset mining by adding order between events  
  
- Main challenges:  
  - combinatorial explosion of candidates  
  - efficient subsequence checking  
  
- Core idea:  
  - exploit anti-monotonicity:  
    - if a sequence is not frequent → no supersequence can be frequent




## AprioriSome
- **AprioriSome** tries to avoid counting too many **non-maximal sequences**
- The idea is:
  - instead of counting every length as in AprioriAll
  - try to count **longer sequences first**
  - then recover the missing shorter frequent sequences later

- It is divided into **2 phases**:
  - **Forward Phase**
    - find large sequences only for some selected lengths
  - **Backward Phase**
    - recover the remaining large sequences for the skipped lengths

- Example:
  - in the forward phase we may count lengths:
    - $1, 2, 4, 6$
  - and in the backward phase count:
    - $3, 5$

- So compared to AprioriAll:
  - we may do fewer support-counting passes
  - and avoid wasting work on many non-maximal intermediate patterns


### Choosing Which Lengths to Count
- AprioriSome uses a function:
$$
next(k)
$$
- where $k$ is the last length that was actually counted

- This function tells us:
  - which sequence length should be counted next

- Example:
$$
next(k) = k+1
$$
- this gives the same behavior as **AprioriAll**
- so in this case no lengths are skipped

- More aggressive choices of $next(k)$:
  - skip some lengths in the forward phase
  - count only selected lengths

- Main tradeoff:
  - **If we count too many lengths**
    - we waste time counting non-maximal sequences
  - **If we skip too many lengths**
    - we may waste time generating and checking extensions of small candidates


### Hit Ratio
- The **hit ratio** can help us to determine the behavior of $next()$:
$$
hit_k = \frac{|L_k|}{|C_k|}
$$

- where:
  - $C_k$ = candidate sequences of length $k$
  - $L_k$ = large/frequent sequences of length $k$

![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260404084200.png|300]]

- It measures how many candidates actually survive, if a large percentage of them survive we can skip more steps

- Intuition:
  - when $hit_k$ is high:
    - many candidates are frequent
    - so little work is wasted in generating them
  - when $hit_k$ is low:
    - many candidates are useless
    - so counting them is expensive and wasteful

- Therefore:
  - as $hit_k$ increases, the cost of counting extensions of small candidates decreases


### AprioriSome: Forward Phase
- Initialization:
  - $L_1$ = set of large 1-sequences
  - $C_1 = L_1$
  - $last = 1$

- Then for increasing $k$:
  - generate candidates $C_k$
  - but count support **only if**:
$$
k = next(last)
$$

- So not every candidate level is counted

- Pseudocode idea:
  - if $L_{k-1}$ is known:
    - generate $C_k$ from $L_{k-1}$
  - otherwise:
    - generate $C_k$ from $C_{k-1}$

- Then:
  - if $k$ is the next length to count:
    - scan the transformed database
    - count support for all candidates in $C_k$
    - keep only those with min support
    - store them in $L_k$
    - set $last = k$


### Why Can We Generate from $C_{k-1}$ Instead of $L_{k-1}$?
- Sometimes $L_{k-1}$ is not available because that level was skipped (but **even if a level is skipped we generate the candidate for that level**, we are skipping only the support counting)
- In that case AprioriSome uses:
  - $C_{k-1}$ to generate $C_k$

- This is correct because:
$$
L_{k-1} \subseteq C_{k-1}
$$

- So:
  - even if $C_{k-1}$ contains extra non-frequent sequences
  - it still contains all frequent ones
  - therefore correctness is preserved

- The downside:
  - candidate generation may be less selective
  - because $C_{k-1}$ is larger than $L_{k-1}$


### AprioriSome: Backward Phase
- After the forward phase:
  - some lengths were counted
  - some were skipped

- In the **backward phase**:
  - process the skipped lengths in reverse order

- For each skipped level $k$:
  - first delete candidates in $C_k$ that are already contained in some longer large sequence $L_i$ with $i>k$
  - then count only the remaining candidates
  - keep those with minimum support as $L_k$

- For lengths already found in the forward phase:
  - we delete the sequences that are contained in some longer large sequence (because they are not maximal)

- Final answer:
$$
\bigcup_k L_k
$$

- So:
  - a separate maximal phase is **not needed**
  - because non-maximal patterns are removed during the backward pass


### Intuition of the Backward Phase
- The forward phase tries to find long frequent sequences early
- Once we know some long sequences are frequent:
  - many shorter candidates can be discarded immediately
  - because they are subsequences of already known larger patterns

- Therefore the backward phase:
  - avoids counting many non-maximal sequences
  - focuses only on shorter candidates that may still matter


### Example of AprioriSome
- In the slides, an example is shown with:
$$
next(k) = 2k
$$

- This means:
  - after counting length $1$, count length $2$
  - after counting length $2$, count length $4$
  - then count length $8$, and so on

- So the forward phase counts only lengths that grow exponentially
- The skipped lengths are recovered later in the backward phase

- This strategy can be good when:
  - long patterns are expected
  - and counting every intermediate level would be wasteful
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260404084602.png|500]]
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260404084653.png|500]]


## AprioriDynamicSome
- **AprioriDynamicSome** is similar to AprioriSome
- It also skips counting some candidate lengths in the forward phase
- But instead of using only the fixed function $next(k)$:
  - It uses a parameter called **step**

- The value of **step** determines:
  - which lengths are counted in the initialization phase
  - which lengths are counted in the forward phase


### AprioriDynamicSome: Initialization Phase
- In the initialization phase:
  - all candidate sequences up to length **step** are counted

- Example:
  - if:
$$
step = 3
$$
  - then initially we count lengths:
    - $1, 2, 3$

- Why is this needed?
  - because to generate longer candidates properly
  - we first need a basis of shorter large sequences


### AprioriDynamicSome: Forward Phase
- After initialization:
  - only lengths that are multiples of **step** are counted

- Example:
  - if $step = 3$
  - then the forward phase counts:
    - $6, 9, 12, \dots$

- Intuition:
  - sequences of length $6$ can be generated by joining sequences of length $3$
  - sequences of length $9$ can be generated by combining length $6$ and length $3$
  - and so on

- So:
  - initialization builds the base
  - forward phase jumps through the search space more aggressively


### Why the Initialization Phase is Necessary
- Suppose $step = 3$
- We want to count sequences of length $6$ by joining sequences of length $3$
- But to obtain valid sequences of length $3$, we still need:
  - length $1$
  - length $2$

- Therefore:
  - the initialization phase cannot be skipped
  - because it provides the building blocks for the later jumps


### AprioriDynamicSome: Backward Phase
- As in AprioriSome:
  - some lengths are skipped in the forward phase
  - and must be recovered later

- However there is an important difference:
  - in AprioriDynamicSome, those skipped candidate sets were **not generated** during the forward phase

- So before the backward phase we need an additional step:
  - the **Intermediate Phase**


### Intermediate Phase
- The **intermediate phase** generates the missing candidate sets for the skipped lengths

- Example:
  - suppose in the forward phase we counted:
    - $L_3$
    - $L_6$
  - and then $L_9$ turns out to be empty

- Then:
  - we generate:
    - $C_7$
    - $C_8$
  - in the intermediate phase

- After that:
  - the backward phase counts:
    - first $C_8$
    - then $C_7$
  - after deleting non-maximal sequences

- The same process is then repeated for:
  - $C_4$
  - $C_5$

- So the workflow is:
  1. initialization
  2. forward phase
  3. intermediate phase
  4. backward phase

![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260404084945.png|500]]

![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260404084952.png|500]]

![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260404084959.png|500]]

![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260404085019.png|500]]


### Main Idea of AprioriDynamicSome
- AprioriDynamicSome is more flexible than AprioriSome
- Instead of deciding individual levels through $next(k)$:
  - it jumps using a fixed **step**
- Then it reconstructs the missing levels only when needed

- This can reduce work because:
  - support counting is done only on selected levels
  - skipped levels are generated later only if they are still relevant


### Otf-generate Procedure
 **otf-generate** (*on-the-fly generate*) procedure is used in AprioriDynamicSome to generate candidates more efficiently

- Example:
  - joining sequences in $X_2$ with the condition:
$$
X_2.end < X_2.start
$$
  - produces the single sequence:
    - $1\ 2\ 3\ 4$

- So the idea is:
  - generate candidates dynamically from sequences that actually co-occur in the same customer sequence
  - rather than generating all candidates blindly


### Why Do We Need Otf-generate?
- In principle, the **apriori-generate** procedure used in AprioriSome could also be generalized
- It could generate $C_{k+j}$ from $L_k$
- But:
  - it may produce too many candidates
  - many of them may never appear in the database

- Otf-generate tries to avoid this

- Main intuition:
  - if $s_k \in L_k$ and $s_j \in L_j$ are both contained in the same customer sequence $c$
  - and they do not overlap inside $c$
  - then the concatenation:
$$
s_k \cdot s_j
$$
  - is a valid candidate of length $(k+j)$

- So instead of:
  - generating many hypothetical candidates first
- we:
  - exploit what is actually present in the data

- This may be faster, especially when:
  - $|L_k| + |L_{step}|$ is smaller than the size of the candidate set that AprioriSome would generate


### Comparison Between AprioriSome and AprioriDynamicSome
- **AprioriSome**
  - uses a function $next(k)$
  - decides which lengths to count in the forward phase
  - skipped levels are later handled in the backward phase

- **AprioriDynamicSome**
  - uses a parameter **step**
  - counts all levels up to **step** first
  - then counts only multiples of **step**
  - needs an intermediate phase to generate skipped candidate levels
  - can use **otf-generate** to reduce useless candidate generation

- So AprioriDynamicSome is:
  - more structured in how it skips levels
  - often more efficient in candidate generation


### AprioriDynamicSome Example
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260404085414.png|500]]

### Key Intuition to Remember
- **AprioriAll**
  - counts every level
  - simple, but can count many non-maximal sequences

- **AprioriSome**
  - skips some levels in the forward phase
  - uses the backward phase to recover missing large sequences
  - tries to reduce useless counting

- **AprioriDynamicSome**
  - skips levels in a more systematic way using **step**
  - adds an intermediate phase
  - can generate candidates on the fly
  - tries to reduce both:
    - counting cost
    - candidate generation cost


### Practical Interpretation
- These methods are all trying to balance two opposite costs:
  - **counting too many candidate sequences**
  - **generating too many extensions from small candidates**

- If we count every level:
  - we waste work on many non-maximal patterns

- If we skip too many levels:
  - we may generate too many speculative candidates later

- AprioriSome and AprioriDynamicSome are both strategies to find a better compromise

### Performance of Apriori-based Methods
- **DynamicSome** generates too many candidates
- **AprioriSome** performs a little better than **AprioriAll**
- The reason is that AprioriSome avoids counting many **non-maximal sequences**

- However, the advantage of AprioriSome is limited by 2 problems:
  - it generates more candidates than AprioriAll
  - the skipped candidates must still stay in memory, because they may be needed later

- So AprioriSome improves counting cost, but increases:
  - candidate generation cost
  - memory usage


### Bottlenecks of Apriori-like Methods
- Apriori-like methods have several important limitations:
	- **Huge number of candidates**
	- **Many scans of the database**
	- **Difficulty with long sequential patterns**
	- **Exponential explosion of short candidates**
- Example:
  - a sequential pattern of length 100 has:
$$
\sum_{i=1}^{100} \binom{100}{i} = 2^{100} - 1 \approx 10^{30}
$$
  - possible non-empty subsequences

- So:
  - even if the final interesting pattern is only one
  - Apriori-like methods may need to consider an enormous number of shorter candidates first


## FreeSpan
### FreeSpan: FP-growth for Sequential Pattern Mining
- **FP-growth** is a successful algorithm for mining frequent **unordered itemsets**
- A natural question is:
  - *can we extend FP-growth to sequential pattern mining?*

- A straightforward sequential-pattern tree does **not** work well
- Even a simple level-by-level projection is not efficient enough

- The key idea of **FreeSpan** is:
  - use **alternative-level projection**
  - project the sequence database recursively
  - mine only the promising projected parts


### Mapping into Projected Sequence Databases
- First step:
  - scan the database and find all **frequent items**

- Then sort them by descending support:
  - this ordered list is called **f_list** (so is the list of ordered frequent item)

- Example:
  - from the sequence database:
    - $\langle (bd)cb(ac)\rangle$
    - $\langle (bf)(ce)b(fg)\rangle$
    - $\langle (ah)(bf)abf\rangle$
    - $\langle (be)(ce)d\rangle$
    - $\langle a(bd)bcb(ade)\rangle$

- We get:
  - $f\_list = b:5,\ c:4,\ a:3,\ d:3,\ e:3,\ f:2$

- Using this order, all sequential patterns can be divided into **disjoint subsets** created from the leas to most frequent item
- In this example, the patterns are divided into 6 groups:
  - patterns containing **f**
  - patterns containing **e** but not $f$
  - patterns containing **d** but not $e$ or $f$
  - patterns containing **a** but not $d,e,f$
  - patterns containing **c** but not $a,d,e,f$
  - patterns containing only **b**

- So each division contain the item in position less or equal than i, but not item in position greater than i
- The complete set of sequential patterns containing item i but no items following i in f_list can be found in the **i-projected database**

- This division is useful because:
  - each group can be mined independently
  - there is no overlap between groups


### Database Projection
- The main idea of projection is:
  - choose a frequent item or prefix
  - keep only the relevant suffixes of sequences
  - mine patterns recursively inside that smaller database

- Example:
  - from the original database we can build:
    - **f-projected db**
    - **e-projected db**
    - **d-projected db**
    - **a-projected db**

- Projection reduces the search space because:
  - once we focus on a prefix, we only keep what can extend that prefix

- $si$ is a copy of $s$ by removing from s all the infrequent items and any frequent item j following i in f_list
- Example: 
- $<(ah)(bf)abf>$ is projected to
	- **f-projected** database as $<a(bf)abf>$ (we deleted h because it was not frequent)
	- **a-projected** database as $<abab>$ (we deleted h because it was not frequent and f because it bas after a)
	- **b-projected** database as $<bb>$

### Parallel vs Partition Projection
- In projection-based sequential pattern mining, there are 2 main ways to build the projected databases:
  - **Parallel projection**
  - **Partition projection**

- They differ in **when** and **how many times** each transaction is copied into projected databases


### Parallel Projection
- In **parallel projection**:
  - scan the database once
  - build **all projected databases at the same time**

- So, during one scan:
  - each sequence may contribute to many different projected databases

- Problem:
  - if a sequence contains many frequent items
  - then it may be copied many times
  - this creates a large overhead in memory and total projected size

- Suppose each transaction contains on average $l$ frequent items

- Then:
  - that transaction is projected into about:
$$
l-1
$$
  projected databases

- The total projected size generated by one transaction is:
$$
1 + 2 + \dots + (l-1) = \frac{l(l-1)}{2}
$$

- Therefore:
  - the total size of a single-item projected databases becomes about:
$$
\frac{l-1}{2}
$$
  times the size of the original database

- Intuition:
  - if $l$ is large, the same transaction is replicated many times
  - so parallel projection can become very expensive

- This is especially bad when:
  - sequences are long
  - and contain many frequent items


### Why Parallel Projection Can Be Expensive
- The problem is not the scan itself
- The problem is the **duplication of data**

- A single transaction may appear in many projected databases
- So we get:
  - more memory usage
  - larger projected databases
  - more work in later mining steps

  - to avoid such overhead, we can use **partition projection** 


### Partition Projection
- In **partition projection**:
  - each sequence is projected only to the projected database of the **last frequent item** appearing in it

- More precisely:
  - while scanning the database
  - a transaction $T$ is projected to the $a_i$-projected database only if:
    - $a_i$ is a frequent item in $T$
    - and there is **no other frequent item after $a_i$ in the frequent-item list** that also appears in $T$

- So each transaction is assigned to **only one projected database** during that scan

- This means:
  - after the scan, the database is effectively **partitioned**
  - instead of duplicated across many projections

- That is why it is called **partition projection**




### Main Advantage of Partition Projection
- In partition projection:
  - each transaction goes to only one projected database at a time

- So compared to parallel projection:
  - much less duplication
  - smaller memory overhead
  - smaller projected databases

- Intuition:
  - instead of copying the same sequence everywhere it may be useful
  - we send it only to the most relevant projected database for that step


### Partition Projection: Continued Processing
- Partition projection does not lose information
- When a projected database is later processed:
  - each transaction inside it can be projected again to another projected database

- More precisely:
  - when processing a projected database
  - each transaction is projected to the $a_j$-projected database
  - where $a_j$ is the item in the transaction such that:
    - there is no other item after $a_j$ in the frequent-item list
    - that also appears in the transaction

- So the projection is done **incrementally**
- The information is passed forward only when needed


  - it do not create all possible projected copies immediately
  - propagate a sequence to another projected database only when that projected database is actually being processed


### Parallel vs Partition Projection: Intuition
- **Parallel projection**
  - build all projected databases in one scan
  - simpler idea
  - but duplicates transactions many times
  - having l, the average number of frequent item per transaction, the total size of the single item-projected database is about (l-1)/2 times that of the original database

- **Partition projection**
  - send each transaction to only one projected database at a time
  - project again later only if needed
  - reduces overhead

- So partition projection is a strategy to make projection-based mining more scalable
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260404092135.png|500]]


### Mining Sequential Patterns by Database Projection
- Consider again the database:
  - $\langle (bd)cb(ac)\rangle$
  - $\langle (bf)(ce)b(fg)\rangle$
  - $\langle (ah)(bf)abf\rangle$
  - $\langle (be)(ce)d\rangle$
  - $\langle a(bd)bcb(ade)\rangle$

- Frequent items:
  - $b:5,\ c:4,\ a:3,\ d:3,\ e:3,\ f:2$

- Initial frequent sequential patterns:
  - $\langle b\rangle$
  - $\langle c\rangle$
  - $\langle a\rangle$
  - $\langle d\rangle$
  - $\langle e\rangle$
  - $\langle f\rangle$
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260404092331.png]]
- Example: **f-projected database**
  - $\langle (bf)(ce)bf\rangle$
  - $\langle a(bf)abf\rangle$

- Inside the **f-projected db**:
  - find local frequent items other than $f$
  - here the local frequent items are:
    - $b$
    - $f$

- Then generate sequential patterns involving them:
  - $\langle bf\rangle$
  - $\langle fb\rangle$
  - $\langle (bf)\rangle$
  - $\langle ff\rangle$
  - $\langle (bf)f\rangle$
  - $\langle fbf\rangle$

- One more scan of the **f-projected db** finds patterns containing:
  - two $b$'s and one $f$

- Example:
  - $\langle (bf)b\rangle$
  - $\langle bbf\rangle$
  - $\langle (bf)bf\rangle$

- So, once we project on $f$:
  - we only mine patterns that start from the context of $f$
  - the rest of the database becomes irrelevant

### Mining by Level-by-Level Projected Databases
- Algorithm:
  - scan the database once
  - find frequent items and build the **f_list**
  - recursively project the database level by level

- Benefits:
  - in each projected database we only need to find frequent items
  - we avoid explicit generation of many candidate sequences
  - the number of useful combinations is much smaller than all possible combinations

- Cost:
  - partitioning and projection of databases can be expensive

- This method works well especially on **sparse databases**


### Mining by Alternative-Level Projected Databases
- A more advanced idea is to **postpone** generation of projected databases
- Instead of projecting immediately at each level:
  - use a level-shared combined projected database

- Algorithm:
  - scan the database
  - find frequent items and the **f_list**
  - perform alternative-level projection mining
  - build a **frequent item matrix**
  - generate:
    - length-2 sequential patterns
    - annotations on repeating-item patterns
    - annotations on projected databases
  - scan the database again to generate:
    - repeating-item patterns
    - projected databases
  - recursively mine longer patterns if needed

- Main idea:
  - summarize useful pairwise information first
  - delay expensive projection work until it becomes necessary


### Frequent Item Matrix
- The **frequent item matrix** is a triangular matrix $F[j,k]$
- Suppose there are $m$ frequent items:
  - $1 \leq j \leq m$
  - $1 \leq k \leq j$

- Meaning:
  - $F[j,j]$ has one counter:
    - counts the appearance of $\langle jj\rangle$

  - $F[j,k]$ with $j \neq k$ has 3 counters:
    - **A**: number of times $k$ occurs after $j$
      - pattern $\langle jk\rangle$
    - **B**: number of times $k$ occurs before $j$
      - pattern $\langle kj\rangle$
    - **C**: number of times $j$ and $k$ occur together
      - pattern $\langle (jk)\rangle$

- Example:
  - in $\langle (bd)c b(ac)\rangle$
  - the pair $(b,c)$ contributes to:
    - $\langle bc\rangle$
    - $\langle cb\rangle$
  - but not to:
    - $\langle (bc)\rangle$

- So the first two counters of $F[b,c]$ increase by 1

- Intuition:
  - the frequent item matrix summarizes all relevant **length-2 relations**
  - without generating all candidates explicitly
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260404093118.png|500]]

### Generating Length-2 Sequential Patterns
- For each counter in the matrix:
  - if the counter value is at least **min_sup**
  - then output the corresponding length-2 sequential pattern

- Example, we consider a cell of the matrix, for instance with row a and column b: (3,2,0)
  - generate:
    - $\langle ba\rangle : 3$
    - $\langle ab\rangle : 2$
  as frequent patterns because their counter are bigger than the min support 2

- So the frequent item matrix is enough to derive all frequent sequential patterns of length 2
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260404093237.png|500]]

### Annotations on Item-Repeating Patterns
- The matrix is also used to determine where **item repetitions** may happen

- For row $j$:
  - if $F[j,j] \geq min\_sup$, generate:
    - $\langle jj+\rangle$

- This means:
  - repeated occurrences of $j$ may appear in longer patterns
  - such as:
    - $\langle jjj\rangle$
    - $\langle jjjj\rangle$

- For a column $i \neq j$:
  - if $F[i,i] \geq min\_sup$, generate $i+$
  - if $F[j,j] \geq min\_sup$, generate $j+$

- If only one among the 3 counters of $F[i,j]$ is frequent:
  - use the **sequence** as annotation

- Otherwise:
  - use the **set**

- Why?
  - because a sequence annotation is more selective

- Example:
  - annotation $\langle bf\rangle$ says that order matters
  - therefore $\langle fb\rangle$ can be filtered out
  - annotation $\{b,f\}$ is weaker, because it does not specify the order

- Example here b appear together with himself 4 times, e appear with himself just one time, and also appear after b just one time, so we can generate the possible item $b^+e$:
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260404093456.png|500]]


### Annotations on Projected Databases
- We also need to decide which projected databases are worth building

- For row $j$:
  - for each $i<j$, if:
    - $F[i,j]$
    - $F[k,j]$
    - $F[i,k]$ with $k<i$
  - are all frequent
  - then they may form a **pattern-generating triple**

- In that case:
  - $k$ is added to the projected column set of $i$

- If there is a choice between:
  - sequence
  - set
- then the **sequence** is preferred, because it is more selective

![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260404093640.png|500]]


### Length-2 Patterns and Annotations Together
- After processing the matrix, for each item we obtain:
  - length-2 sequential patterns
  - annotations on repeated items
  - annotations on projected databases
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260404093737.png|600]]



### One More Scan After the Annotations
- Once annotations are created, the database S is scanned one more time

- This generates:
  - repeating-item patterns
  - the projected databases that were marked as promising

- Example of repeating-item patterns:
  - $\langle bbf\rangle : 2$
  - $\langle fbf\rangle : 2$
  - $\langle (bf)b\rangle : 2$
  - $\langle (bf)f\rangle : 2$
  - $\langle (bf)bf\rangle : 2$
  - $\langle (bd)b\rangle : 2$
  - $\langle bba\rangle : 2$
  - $\langle aba\rangle : 2$
  - $\langle abb\rangle : 2$
  - $\langle bcb\rangle : 3$
  - $\langle bbc\rangle : 2$

- The projected databases generated are:
  - $\langle (ce)\rangle : \{b\}$
  - $\langle da\rangle : \{b,c\}$
  - $\{cd\} : \{b\}$
  - $\langle ca\rangle : \{b\}$

- If a projected-db annotation contains exactly 3 items:
  - the corresponding patterns can be mined with a simple scan of the project db

- If it contains more than 3 items:
  - build a new frequent item matrix for that projected database
  - recursively apply the same alternative-level projection method


### Examples of Longer Patterns from Projected Databases
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260404094017.png|500]]




### Experimental Results
  - **FreeSpan** is faster than:
    - GSP
    - Improved GSP
    - FreeSpan-1

-  The advantage of FreeSpan becomes stronger when:
  - transactions are denser
  - the search space becomes larger

- FreeSpan and Improved GSP are compared as the number of sequences increases
- Result:
  - both algorithms scale approximately **linearly**
  - but **FreeSpan is much faster**


### Why FreeSpan Outperforms Apriori-like Methods
- FreeSpan recursively projects a large sequence database into smaller projected databases
- Each projected database focuses only on the patterns that are still relevant

- This gives 2 main advantages:
  - the database becomes much smaller at each recursive step
  - the algorithm avoids generating many useless candidates

- In addition:
  - the **alternative-level projection** strategy reduces the cost of scanning many projected databases
  - it also exploits **Apriori-like 3-way candidate filtering**

- So the main reason FreeSpan is better is:
  - it explores only the promising part of the search space
  - while Apriori-like methods waste much more work on candidate generation and repeated scans


### Intuition to Remember
- **Apriori-like methods**
  - generate many candidates
  - scan the database many times
  - struggle when patterns are long

- **FreeSpan**
  - starts from frequent items
  - projects the database recursively
  - mines only what can really extend from the current projected database

- So FreeSpan is usually better because:
  - it is more focused
  - it reduces useless candidates
  - it reduces scans
  - it works particularly well on large and sparse sequence databases



- per l'orale serve solo sapere gli apriori, la matrice e i vantaggi e gli svantaggi


# 013 Time Series Traditional Approaches

### Time Series
- A **Time series** is a set of data point ordered in time, the data is equally spaced in time, for instance one point each hour, minute, second or month
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260411114440.png|300]]

- A **Decomposition** is a statistical task that separates a time series into its different components: *trend*, *seasonality*, and *residuals*
  - **Trend**: slow moving changes in a time series
  - **Seasonality**: seasonal pattern in the series
  - **Residuals**: behavior that cannot be explained by the trend and seasonality

![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260411114633.png|300]]


- **Forecasting** is predicting the future using historical data and knowledge of future events that might affect our forecasts
- is different form other regression tasks, because time series *have an order*, and it is possible to forecast time series *without the use of features*

##### Defining a baseline model
- Goal: we want to predict the quarterly earnings per share (EPS) of Johnson & Johnson
- *Baseline model*: a trivial solution to the forecasting model under consideration
- we want to compute the mean of the values over a certain period and assume that future values will be equal to that mean 

- Mean Absolute Percentage Error (MAPE):
  $$\text{MAPE} = \frac{1}{n}|\frac{A_i-F_i}{A_i}| \text{x}100$$
where:
- $Ai$ is the actual value at point i in time 
- $Fi$ is the forecast value at point i in time
- $n$ is the number of forecasts


- if we predict using the *last known value*, we do not take in consideration the seasonality
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260411115646.png]]



- Instead if we predict using a *naive seasonal forecast*, we take the last observed cycle and repeat it into the future seasonality has a significant impact since repeating the last season into the future yields fairly accurate forecasts
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260411115904.png|1000]]


### Random walk process

- A **random walk** is a process in which there is an equal chance of going up or down by a random number
- Let us assume that we would like to buy shares of a company. We would like to buy if the closing prices of the stock is expected to go up in the future 
- Long term trend is increasing but there exist abrupt changes 
- The daily closing price can be modeled using the random walk model
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260411120205.png|300]]

- Mathematically we can express the random walk as:$$y_t = C + \alpha_1 y_{t-1} + \epsilon_t$$
- The current value $y_t$ is a function of the value at the previous timestep $y_{t-1}$, a constant $C$, and a random number $\epsilon_t$ also called **white noise**
- Formally a *random walk* is a series whose first difference is stationary and uncorrelated, so the process moves completely at random

### Stationarity
- A **stationary time series** is one whose statistical properties do not change over time
- In other words, it has a constant mean, variance, and autocorrelation, and those properties are independent of time

- Many forecasting models assume stationarity, thus we need to find a ways to transform a given time series into a stationary time series
- The simplest *transformation* is **differencing**, which calculates the change from one timestep to another, thus stabilizing the mean $$y_t' =y_t-y_{t-1}$$
- It is possible to difference a time series many times to obtain a stationary series


- Differencing allows us to obtain a *constant mean* through time
- to obtain a *constant variance* we use logarithms, which help stabilize the variance

- NOTE: when we model a time series which has been transformed, we have to **untransform it** to return the results of the model to the original units of measurements.
- For instance, if you apply a log transformation to your data, make sure you raise your forecast values to the power of 10 in order to bring the values back to their original magnitude


### The augmented Dickey-Fuller test
- We recall that the time series can be expressed as: $$y_t = C + \alpha_1 y_{t-1} + \epsilon_t$$
- $\alpha_1$ is the **root** of the time series. 
- The time series will be stationary only if the root lies within the unit circle, therefore, its value must be between -1 and 1 (with 1 and -1 excluded), otherwise the series is non stationary

- The mean and variance of the stationary process becomes constant after the first few time steps 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260411121655.png|500]]


- The **augmented Dickey-Fuller** (**ADF**) test helps us determine if a time series is stationary by testing if is present a unit root. If a unit root is present, the time series is not stationary

- *Null Hypothesis*: a unit root is present the time series is not stationary
- If the test returns a p-value less than a certain significance level, typically 0.05 or 0.01, then we can reject the null hypothesis, meaning that there are no unit roots, and so the series is stationary.

- Once we have a stationary series, we must determine whether there is *autocorrelation* or not. Remember that a random walk is a series whose first difference is stationary and uncorrelated.

### Autocorrelation
- The **autocorrelation function** (*ACF*) measures the linear relationship between lagged values of a time series (the lag is the number of timesteps separating two values). In other words, it measures the correlation of the time series with itself

- For example, the autocorrelation coefficients $r1$, $r2$, $r3$, .. are computed between, respectively, $yt$ and $y_{t-1}$, $yt$ and $y_{t-2}$, $yt$ and $y_{t-3}$
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260411122411.png]]


-  In the presence of a trend, a plot of the ACF will show that the coefficients are **high for short lags**, and they will decrease linearly as the lag increases.
- If the data is *seasonal*, the ACF plot will also display *cyclical patterns*.




- Let us suppose to adopt the following random walk (with $\alpha \notin (0,1)$$) and to generate a series with T samples: $$y_t = y_{t-1} + \epsilon_t$$
- Once generated the series,  ADF statistics is equal to -0.97 with p-value = 0.77: we cannot reject the null hypothesis.

- the autocorrelation coefficients slowly decrease as the lag increases, which is a clear indicator that our random walk is not a stationary process (shaded area represents a confidence interval).
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260411133615.png|500]]
- The shaded area represents 95% confidence interval: If a point is within the shaded area, then it is not significantly different from 0.
- Otherwise, the autocorrelation coefficient is significant. Generally, the evaluation of the shaded area is based on the Bartlett's standard errors $$(1 + 2 \sum_{j=1}^{k-1}r_j^2)^{\frac{1}{2}}n^-{\frac{1}{2}}$$

- We need to apply a transformation
-  Since the series displays changes in trend without seasonal patterns, we apply a first-order differencing and recompute ADF statistics and autocorrelation
	- ADF statistic is –31.79 with a p-value of 0. *Null hypothesis is rejected*
	- Stationary process *completely random (white noise)*
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260411133903.png]]



### Forecasting a random walk on a long horizon
- In case of *random walk*, since the values change randomly, *no statistical learning model can be applied*
- We can only use naïve forecasting methods or baselines (historical mean, last known value and drift method)
- We split in training (white area) and test (grey area)
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260411133954.png|400]]


- **Drift Method**: the last value is equivalent to calculating the slope between the first and last value of the training set and simply extrapolating this straight line into the future.
$$pred = \frac{𝑦_𝑓−𝑦_𝑖}{
\#𝑡𝑖𝑚𝑒𝑠𝑡𝑒𝑝𝑠 −1} ∙ 𝑡𝑖𝑚𝑒𝑠𝑡𝑒𝑝$$
- where: $y_f$ and $y_i$ are the last and first values in the training set
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260421115056.png]]
- **Forecasting a random walk on a long horizon does not make sense**

### Forecasting the next step of a random walk
- Predict the last known value
- Very limited approach
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260421115151.png]]
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260421115226.png]]


### Moving Average Model
- **Moving average model** (**MA**): the current value depends linearly on the mean of the series, the current error term and past error terms
- we indicate it with $M(q)$, where $q$ is the order (past error terms)
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260421115326.png]]

- *How can you choose q?*
  - **order q** of the moving average model determines the number of past error terms that affect the present value
  - The larger q is, the more past error terms affect the present value

- To choose q, we observe the autocorrelation plot: the plot presents significant correlation coefficients up until lag q, after which all coefficients will be non-significant. If that is the case, then we have a moving average process of order q.
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260421115911.png]]


- 90% of the data for training set and 10% for the test set, meaning that we must forecast 50 timesteps into the future
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260421115939.png]]


### Rolling Forecasts
- When using an MA(q) model, forecasting beyond q steps into the future will simply return the mean, because there are no error terms to estimate beyond q steps. We can use rolling forecasts to predict up to q steps at a time in order avoid predicting only the mean of the series.

- We need to develop a function that will predict q timesteps or less at a time, until all predictions in the test sets are made We train on the first 449 timesteps and predict timesteps 450 and 451. Then, on the second pass, we will train on the first 451 timesteps, and predict timesteps 452 and 453…
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260421120241.png]]



- You do not need forecasts q steps ahead: you can forecast q-1, q-2, etc.
- You can use **SARIMAX** function from the *statsmodels* library.
- If we estimate the first-order difference, we need add the initial value y0 of the test set to the first differenced value to determine the first predicted value
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260421120401.png]]


### Autoregressive process
- We aim to forecast the average weekly foot traffic in a retail store so that the store manager can better manage the staff’s schedule.
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260421120517.png]]
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260421120530.png]]


- An **Autoregressive process** is a regression of a variable against itself. In a time series, this means that the present value is linearly dependent on its past values.
- The autoregressive process is denoted as $AR(p)$, where $p$ is the **order**. The general expression of an $AR(p)$ model is:
$$
y_t = C + \phi_1 y_{t-1} + \phi_2 y_{t-2} + \cdots + \phi_p y_{t-p} + \epsilon_t
$$
  
- Where:  
- $C$ is a **constant term** (also called intercept or drift), representing the baseline level of the series.  
- $\phi_1, \phi_2, \ldots, \phi_p$ are the **autoregressive coefficients**, which quantify the influence of past values on the current value.  
- $y_{t-1}, y_{t-2}, \ldots, y_{t-p}$ are the **lagged values** of the time series.  
- $\epsilon_t$ is the **white noise error term**, assumed to be independently and identically distributed (i.i.d.) with zero mean and constant variance


##### Example
- In the example, ADF = -1.18 with a p-value = 0.68. The null Hypothesis cannot be rejected.
- Differenced series: ADF = -5.27 with a p-value = 6.36· 10-6. The null hypothesis is rejected and therefore stationary.
- We compute the autocorrelation

- There is no lag at which the coefficients abruptly become nonsignificant.
- We do not have a moving average process and that we are likely studying an autoregressive process
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422133629.png]]



### Autoregressive process (2)
- *How can we determine the* **order** *$p$?*
 
 - **Partial Autocorrelation Function**: measures the correlation between lagged values in a time series when we remove the influence of correlated lagged values in between.
 - We can plot the partial autocorrelation function to determine the order of a stationary AR(p) process. The coefficients will be non-significant after lag p
 
 We note that there is no significant coefficient after lag 3, so the *autoregressive process* have order 3, it is denoted as AR(3)
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422133808.png]]

- We wish to measure how _$y_t$_ relates to $y_{t-2}$.
-  When we measure the autocorrelation between $y_t$ and $y_{t-2}$ we are not taking into account that $y_{t-1}$ has an influence on both $y_t$ and $y_{t-2}$. This means that we are not measuring the real impact of $y_{t-2}$ on $y_t$.



### Autoregressive moving average
- We aim to predict bandwidth usage for a large data center.
- Bandwidth is defined as the maximum rate of data that can be transferred. Its base unit is bits per second (bps)
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422134345.png|300]]

- First, we check whether the series is stationary. It is not.

- Second, we transform by using differences and verify whether the differenced series is stationary. It is.

- Third, we plot the ACF functions and find that there are significant autocorrelation coefficients after lag 0 and these coefficients slowly decay.

- Fourth, we plot the PACF function and will verify that they have a sinusoidal pattern. Thus, *it is not a purely moving average process and it is not a purely autoregressive process*



- **Autoregressive moving average process**: is a combination of the autoregressive process and the moving average process
- It is denoted as $ARMA(p,q)$, where $p$ is the order of the autoregressive process, and $q$ is the order of the moving average process. The general equation of the ARMA(p,q) model is:
  $y_t = C + \phi_1 y_{t-1} + \phi_2 y_{t-2} + \dots + \phi_p y_{t-p} + \epsilon_t + \theta_1 \epsilon_{t-1} + \theta_2 \epsilon_{t-2} + \dots + \theta_q \epsilon_{t-q}$
  
  
- An $ARMA(0,q)$ process is equivalent to an $MA(q)$ process, since the order $p = 0$ cancels the $AR(p)$ portion.
- An $ARMA(p,0)$ process is equivalent to an $AR(p)$ process, since the order $q = 0$ cancels the $MA(q)$ portion.


- *How can we determine p and q?*
- We need a new procedure! 
- With a list of possible values for p and q, we can fit every unique combination of $ARMA(p,q)$ and evaluate it by using the **Akaike Information criterion** (**AIC**)
- The model with the *lowest AIC* is selected 
- Then, we analyze the model’s residuals, which is the difference between the actual and predicted values of the model. If the residuals look like white noise, then they are uncorrelated and independently distributed and the model is ready for forecasting, otherwise, a different set of values for $p$ and $q$ has to be evaluated.


##### Akaike Information criterion (AIC) 
- The **AIC** is a function of the number of parameters $k$ in a model and the maximum value of the likelihood function: $$AIC = 2k - 2ln(\hat{L})$$


- The *lower the value* of the AIC, the *better the model*
- AIC allows us to keep a balance between the complexity of a model and its goodness of fit to the data
- In our case, $k=p + q$ 
- The likelihood function measures the goodness of fit of a model. In other words, it measures “How likely is it that my observed data is coming from an ARMA(1,1) model?”


- **Example**:
  - Let us assume that $p$ and $q$ vary from $0$ and $3$. Thus, we have $16$ possible combinations 
  - We iterate for each possible combination $(p,q)$, compute the corresponding $ARMA(p,q)$ model and evaluate the AIC with the available data 
  - We select the model with the lowest AIC.  
  - Consider the simulated model $ARMA(1,1) = y_t = 0.33y_{t-1} + 0.9\epsilon_{t-1} + \epsilon_t$
  - Let us suppose that we estimate the coefficients perfectly $$\hat{y}_t = 0.33y_{t-1} + 0.9\epsilon_{t-1}$$
  - Then: $$residuals = 0.33y_{t-1} + 0.9\epsilon_{t-1} + \epsilon_t - (0.33y_{t-1} + 0.9)$$ $$residuals = \epsilon_t$$

- *How can we analyze the residuals?*
  - Qualitative analysis: **QQ plot**. The QQ plot is constructed by plotting the quantiles of the residuals on the y-axis against the quantiles of a theoretical distribution, in this case the normal distribution, on the x- axis. 
  - If the model is a good fit, the residuals are similar to white noise Normal distribution Non-Normal distribution
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422135622.png|300]]

- An alternative to analyze residuals is: 
  - Quantitative analysis: **Ljung-Box test**. The *Ljung-Box test* is a statistical test that determines whether the autocorrelation of a group of data is significantly different from 0. 
  - Null hypothesis: the data is independently distributed, meaning that there is no autocorrelation. 
  - If the p-value is larger than 0.05, we cannot reject the null hypothesis, meaning that the residuals are independently distributed. Therefore, there is no autocorrelation, the residuals are similar to white noise, and the model can be used for forecasting. 
  - If the p-value is less than 0.05, we reject the null hypothesis, meaning that our residuals are not independently distributed and are correlated. The model cannot be used for forecasting.
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422135829.png]]




### Non-stationary time series
- We observed that the ARMA model is suitable only for stationary time series.
- For non-stationary time series we need to add a component, the **integration order**. 
- **Autoregressive Integrated Moving Average** (**ARIMA**): is the combination of the $AR(p)$ and $MA(q)$ processes, but in terms of the differenced series.
- is denoted as $ARIMA(p,d,q)$, where $p$ is the order of the $AR(p)$ process, $d$ is the *order of integration*, and $q$ is the order of the $MA(q)$ process.
-  Integration is the reverse of *differencing*, and the order of integration $d$ is equal to the number of times the series has been differenced to be rendered stationary.


- The general equation of the $ARIMA(p,d,q)$ process is: $$y'_t = C + \phi_1 y'_{t-1} + \dots + \phi_p y'_{t-p} + \theta_1 \epsilon_{t-1} + \dots + \theta_q \epsilon_{t-q} + \epsilon_t$$

- Note that $𝑦𝑡^′$ represents the *differenced series*, and it may have been differenced more than once. 
- Order $d$ is the order of integration, where integration is the reverse of differencing. 
- We have to find the order of integration, which corresponds to the minimum number of times a series must be differenced to become stationary


- We start again from the following series:
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422140556.png|300]]
 
 - After the application of the process, we determine that the best model is $ARIMA(3,2,3)$. Indeed, the **Ljung- Box test** on the first 10 lags of the model’s residuals returns a list of p-values that are all larger than 0.05
	![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422140709.png|300]]


### Non-stationary time series with seasonality
- We take into consideration the monthly total number of air passengers for an airline.

- **Naive seasonal method**: the first quarter of 1979 is used to forecast for the EPS of the first quarter of 1980; the EPS of the second quarter of 1979 is used as a forecast for the EPS of the second quarter of 1980, and so on.
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422140800.png]]
- The naive seasonal method has an higher MAPE (error) compared to ARIMA


 - **Seasonal autoregressive integrated moving average** (**SARIMA**) model: adds *seasonal parameters* to the $ARIMA(p,d,q)$ model. 
 - It is denoted as $SARIMA(p,d,q)(P,D,Q)_m$, where:
   - $P$ is the order of the seasonal $AR(P)$ process
   - $D$ is the seasonal order of integration
   - $Q$ is the order of the seasonal $MA(Q)$ process
   - $m$ is the frequency, or the number of observations per seasonal cycle. 
   - Note that a $SARIMA(p,d,q)(0,0,0)_m$ model is equivalent to an $ARIMA(p,d,q)$ model.

- **Appropriate frequency $m$** (some example)
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422143756.png]]


- *How can we choose P and Q?* 
  - Let us consider an example with $m=12$
  - If we are considering $P=2$, this means that we are including *two past values* of the series at a lag that is a multiple of $m$
  - Therefore, we include the values at $y_{t –12}$ and $y_{t –24}$
  - Similarly, if $D = 1$, this means that a seasonal difference makes the series stationary. With $m=12$, this corresponds to $y_t^′ = y_t - y_{t-12}$ 
  - If $Q = 2$, we include past error terms at lags that are a multiple of $m$. Therefore, we include the errors $ϵ_{t –12}$ and $ϵ_{t –24}$.

- *How can we identify seasonal patterns?* 
  - Visually by **plotting the series** 
  - Through **time series decomposition** (*STL* function from the statsmodels library), that is, the statistical task that *separates the time series into its three main components*: a trend component, a seasonal component, and the residuals. 
    - The *trend component* represents the long-term change in the time series. This component is responsible for time series that increase or decrease over time. 
    - The *seasonal component* is the periodic pattern in the time series. It represents repeated fluctuations that occur over a fixed period of time.
    - The *residuals*, or the noise, express any irregularity that cannot be explained by the trend or the seasonal component.


![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422144312.png]]
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422144306.png]]


- **New procedure**: We have to check for all the possible parameters
  - Two experiments
    - $SARIMA(p,d,q)(0,0,0)_m$ which corresponds to $ARIMA(p,d,q)$
    - $SARIMA(p,d,q)(P,D,Q)_m$



![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422144700.png]]
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422144706.png]]



- Comparing the different approaches: SARIMA reach a lower error compared to ARIMA
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422144556.png]]




### Non-stationary time series with seasonality and external variables
- Often, **external variables** are also predictive of time series 
- For instance, Gross Domestic Product (GDP) which is the total market value of all the finished goods and services produced within a country, is defined as the sum of consumption C, government spending G, investments I, and net exports NX. Each element is probably affected by external variables $$GDP = C + G + I + NX$$

- **SARIMAX model**, where $X$ denotes *exogenous variables*, adds simply *linear combination of exogenous variables to the SARIMA model*. This allows modelling the impact of external variables on the future value of a time series. 
- We can loosely define the SARIMAX model as follows: 
$y_t = SARIMA(p,d,q)(P,D,Q)_m + \sum_{i=1}^{n} \beta_i X_t^i$


- The SARIMAX model is the *most general model* for forecasting time series. You can see that if you have no seasonal patterns, it becomes an ARIMAX model. With no exogenous variables, it is a SARIMA model. With no seasonality or exogenous variables, it becomes an ARIMA model. 


- In the example, we take into consideration the following variables
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422145042.png|400]]


- *What if you wish to predict two timesteps into the future?* 
- While this is possible with a SARIMA model, the SARIMAX model requires us to forecast the exogenous variables too. 
- The only way to avoid that situation is to predict only one timestep into the future and wait to observe the exogenous variable before predicting the target for another timestep into the future. 
- On the other hand, if your exogenous variable is easy to predict, meaning that it follows a known function that can be accurately predicted, there is no harm in forecasting the exogenous variable and using these forecasts to predict the target.


- General procedure: No real changes with respect to SARIMA procedure, except for the use of SARIMAX as fitting model
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422145130.png]]






# 014 Time Series ML Approaches

### Machine Learning Approaches 
- *Statistical methods work particularly well when you have small datasets* (less than 10000 data points). Otherwise, they become very slow 
- **Machine learning** is used either when statistical models take too much time to fit or when they result in correlated residuals that do not approximate white noise. 
- Three models: 
  - **Single-step baseline**: outputs a single value representing the prediction for the next timestep. The input is one timestep and the output is the prediction of the next timestep  
  - **Multi-step model**: the output of the model is a sequence of values representing predictions for many timesteps into the future. For example, if the model predicts the next 6 hours, 24 hours, it is a multi-step model.
  - A **Multi-output model** generates predictions for more than one target. For example, if we forecast the temperature and wind speed, it is a multi-output model.

- How can we encode time expressed as **YYYY-MM-DD HH:MM:SS**?
   - Transform date in seconds
   - Apply a transformation to recover the cyclical behavior of time
   - First, we apply a sine transformation
   - day = 24 * 60 * 60
   - `df['day_sin'] = (np.sin(timestamp_s * (2*np.pi/day))).values`
   - Using this transformation, 12 p.m. is equivalent to 12 a.m.
   - Second, we apply a cosine transformation to avoid the problem
   - `df['day_cos'] = (np.cos(timestamp_s * (2*np.pi/day))).values`

![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422150051.png|500]]

- We us a 70:20:10 split for train, validation, and test, we scale all the values between 0 and 1
- **Data windowing process**: we define a sequence of data points on the time series and define which are inputs and which are labels (so we decide how long is the number of second in the past, and how long we want to forecast in the future, e.g. given the past 24 hours we want to predict the next 24 hours, dividing the training set in multiples of 24 hours)
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422150423.png]]

- We can exploit a moving windows with step 1 to waste less training data compared to the previous approach
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422150535.png]]



- Deep learning models are trained with **batches**. A batch is a collection of data windows that are fed to the model for training (update of the parameters after each batch). For example, the batch size is 32. 
- For a training set with 12285 rows, we have 384 batches. 
- Training the model on all the batches is called one epoch. 
- A lot of epochs are normally necessary to improve the accuracy of the predictions  Shuffling is used at the batch level
  

### Baseline models

- **Single-step baseline**:
  -  The input is one timestep and the output is the prediction of the next timestep
  - Window: input width 1, label width 1, shift 1.

- *Baseline*: the simplest prediction we can make is the last observed value. Basically, the prediction is simply the input data point
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422150928.png]]

- **Multi-step baseline**:  
  - For a multi-step of N, the input is N timesteps and the output is the prediction of   N timesteps (for instance, N = 24 hours)  
  - Window: input width N, label width N, shift N.  

- Two possible baselines  
	1. *Predict the last known value* for the next 24 timesteps.  
	2. *Predict the last 24 timesteps* for the next 24 timesteps.  

  
- Multi-step baseline (**predict the last known value**): Simply takes in the input and repeats the last value of the input sequence over N time-steps  
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422151103.png]]

- Multi-step baseline (**repeating the input sequence of N timesteps**): The prediction for the next N timesteps is simply the last known N timesteps of data 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422151142.png]]


- **Multi-output baseline** (*single-step model for predicting different outputs*): Let us assume that we have two outputs. We apply a single-step model for predicting both the outputs  
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422151219.png]]


### Deep Learning Models
- **Simple linear model**: Not actually a deep learning model: A simple multivariate linear regression  $\text{traffic volume}_{t+1} = w_1 x_{1,t} + w_2 x_{2,t} + w_3 x_{3,t} + w_4 x_{4,t} + w_5 x_{5,t}$ 
- Single Step Mode:
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422152436.png|400]]

- Multi-Step linear Model:
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422152525.png|400]]

- Multi-Output linear Model:
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422152534.png|400]]

### Deep Learning Models  
- **Deep neural network**:
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422152606.png|400]]

- **Activation function**: in each neuron of the hidden layers and responsible for generating the output. If a linear activation function is used, the model will only model linear relationships. Therefore, to model nonlinear relationships in the data, we must use a nonlinear activation function.  
- Example: *Rectified Linear Unit* (*RELU*): $$f(x) = max(0,x)$$
- Deep neural networks give good performance


### Recurrent Neural Networks  
- A **recurrent neural network** (**RNN**) is a deep learning architecture especially   adapted to processing sequences of data  
- It uses a hidden state that is *fed back* into the network so it can use past   information as an input when processing the next element of a sequence.  
- This is how it replicates the concept of memory.

- *RNNs* suffer from **short-term memory**, meaning that information from an early element in the sequence will stop having an impact further into the sequence.  
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422152914.png]]


### Long short-term memory  
- **Long short-term memory** (**LSTM**) is a deep learning architecture that is a subtype of RNN. LSTM addresses the problem of short-term memory by adding the *cell state*. This allows for past information to flow through the network for a longer period of time, meaning that the network still carries information from early values in the sequence.  

- The LSTM is made up of *three gates*:  
   - The **forget gate** determines what information from past steps is still relevant 
   - The **input gate** determines what information from the current step is relevant 
   - The **output gate** determines what information is passed on to the next  element of the sequence or as a result to the output layer
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422153106.png|500]]

##### Forget Gate
- The present element of a sequence, $x_t$, and past information, $h_{t–1}$, are first combined. They are duplicated, and one is sent to the input gate while the other goes through the sigmoid activation function.
- The sigmoid outputs a value between 0 and 1, and if the output is close to 0, this means that information must be forgotten. If it is close to 1, the information is kept. The output is then combined with the past cell state using pointwise multiplication, generating an updated cell state $C_{t-1}^{\prime}$.  

##### The input gate  
- The past hidden state and current element of the sequence are duplicated again and sent through a sigmoid activation function and a hyperbolic tangent (**tanh**) activation function. Again, the sigmoid determines what information is kept or discarded, while the tanh function regulates the network to keep it computationally efficient. tanh function  
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422153801.png]]

##### The output gate  
- The past hidden state and current element of a sequence $[h_{t–1} + x_t]$ are passed through the sigmoid function to determine if information will be kept or discarded. Then the cell state is passed through the tanh function and combined with the output of the sigmoid using pointwise multiplication. This is the step where past information is used to process the current element of a sequence. We then output a new hidden state $h_t$, which is passed to the next LSTM neuron or to the output layer. The cell state is also output.  



# 015 Data Stream 
## Introduction
- **Data stream**: a potentially *unbounded, ordered sequence of instances*. A data stream _$S$_ may be shown as $S = \{x_1, x_2, x_3, ..., x_N\}$, where $x_i$ is i-th data instance, which is a d-dimensional feature vector and _$N$_ goes to infinity
- unbounded: it continue to grow infinitely, we can store it at a time t, but it will continue to grow
- ordered: the order of the instances have a meaning 

- For instance data stream can arrive from sensors 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422155326.png|400]]

- We will consider that the number of classes remain constant 
- Some approaches also manage the case in which the number of classes changes in time


- We want to create model that evolve with the streaming of data that arrive 

##### Problems in Mining Data Streams
- *Traditional Data Mining techniques usually require*:
    - Entire dataset to be present
    - Multiple scans of the overall dataset
    - Random access to instances
    - Computationally heavy learning phases

- Challenges of stream mining
    - Impractical (and impossible) to store the whole dataset
    - Impractical (and impossible) to perform multiple scans of the overall dataset
    - Random access is expensive
    - Simple calculation per data due to time and space constraints

##### Motivation
- A growing number of applications generate streams of data:
    - Tweets on Twitter
    - ATM operations in banks
    - Sensor network data

- Application characteristics:
    - Massive volumes of data
    - Records arrive at a rapid rate

### Computational Model

- We try to create a sort of summary (*synopsis*) of the data in memory before apply the ML algorithm 

- Stream processing requirements:
    - **Single pass**: Each record is examined at most once
    - **Bounded storage**: Limited Memory (M) for storing synopsis
    - **Real-time**: Per record processing time (to maintain synopsis) must be low

- In this way we can process data very fast and maintain information
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422155612.png]]



##### Data Stream Mining Algorithms
- Generally, algorithms compute **approximate answers**, because is difficult to compute answers accurately with limited memory, and because we are working with the synopsis 
- The *error t is bounded* (it cannot go above a certain threshold of error)
- With probability at least _$1-δ$_, the computed answer is within a factor $ε$ of the actual answer
- Single-pass algorithms for processing streams are also applicable to massive amount of data


### Concept Drift
- **Concept drift**: unforeseen change in statistical properties of data stream instances over time
- There are four types of concept drift: 
  - sudden
  - gradual
  - incremental 
  - recurring

- **Sudden concept drift**: Between two consecutive instances, the change occurs at once, and after this time only instances of the new class are received
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422160107.png]]

- **Gradual concept drift**: The number of instances belonging to the previous class decreases gradually while the number of instances belonging to the new class increases over time. During a gradual concept drift, instances of both previous and new classes are visible.
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422160127.png]]


- **Incremental concept drift**: Data instances belonging to the previous class evolves to a new class step by step. After the concept drift is completed, the previous class disappears. The instances that arrive during the concept drift are of transitional forms and they do not have to belong to either of the classes
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422160207.png]]


- **Recurring concept drift**: The data instances change between two or more statistical characteristics several times. Neither of the classes disappears permanently but both of them arrive in turns
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422160214.png]]



### Data Structures
- *It is not possible to store and manage the whole input data*
- Only a synopsis of the input stream is stored: special data structures enable to incrementally *summarize* the input stream

 - Four commonly used data structures to implement the synopsis:
	1. **Feature vectors**: summary of the data instances
	2. **Prototype arrays**: keep only a number of representative instances that exemplify the data
	3. **Coreset trees**: keep the summary in a tree structure
	4. **Grids**: keep the data density in the feature space


### The Window Model
- It is more efficient to process recent data instead of the whole data.

- **Damped window model**:
	- Recent data have more weight than the older data: the importance of the instances decreases by time
	- Usually implemented using decay functions which scale down the weight of the instances, depending on the time passed since the instance is received $f(t) = 2^{-\lambda t}$ where $\lambda$ is the *decay rate*: Higher decay rate in the function means a more rapid decrease in the value
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422160520.png]]



- **Landmark window model**
    - *The whole data between two landmarks are included in the processing and all of the instances have equal weight*
    - Consecutive windows do not intersect and the new window just begins from the point the previous window ends
    - Let w be the window length. Then, data instances belonging to the m-th window are calculated using:
$$W_m = [x_{m*w}, \dots, x_{(m+1)*w-1}] \quad m = \Big\lfloor \frac{i}{w} \Big\rfloor$$

![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422160647.png]]


- **Sliding window model**:
   - The window swaps one instance at each step: The older instance moves out of the window, and the most recent instance moves in to the window by FIFO style.
   - All instances in the window have equal weight and consecutive windows mostly overlap
   - Let $w$ be the window length. Then, data instances belonging to the m-th window are calculated using
$$W_m = [x_m, \dots, x_{(m+w-1)}]$$
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422160741.png]]



## Clustering

- There are a lot of different clustering approach because the majority of data stream problems are clustering problems, it is rarer to have a classification problem, for instance **Birch** that we have already seen, and use *coreset trees* to summarize information  

### Data Stream Clustering
- In most cases, *true class labels are not available for stream instances* and there is no prior knowledge about the number of classes
-  Therefore, clustering, being unsupervised is one of the most suitable data mining and data analysis methods for data streams

### Adaptive Streaming k-Means
- with $l$ the number of instances accumulated in initialization phase, and $S$ the data streaming (nonostante it is a kmeans variant, we do not provide any k):
- it use an analysis of the distribution of data feature by feature, inferring automatically the value of k, and try all different value from k to $k_{max}$ 
- silhouette coefficient is used to evaluate the performance of a clustering algorithm
- once the centroid are computed during the initialization phase
- during the streaming the algorithm search continuously if there are some changes in data distribution, in this case the cluster computed in the old initialization phase are not valide anymore, and compute them again
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422160953.png]]


- **Initialization phase**
   - Function `determineCentroids()` finds $k$ and determines candidate centroids
	   - Estimate the probability density function (PDF) of the data for each feature
	   - Determine the directional changes of the PDF curves: each change identifies a new region. The region can be defined as the area between two consecutive directional changes of the PDF curve
	   - Number of regions is considered as a candidate $k$ and centers of these regions are considered as candidate initial centroids

- Function `determineCentroids()` in order to find k and determine candidate centroids:
  - Different features generally show different distributions and different centroids
  - For each value of k, the PDF curve are split into equiprobable areas. The boundaries of these areas are called **beta points**. Since we are interested in the center of these region, the middle points between two adjacent betas are computed and saved as initial centroids. 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422161252.png]]

- **Initialization phase**: the loop 2-5 is executed for these values of k and for candidate centroids
- Clustering results of different k values are compared according to silhouette coefficient and best k is selected with its corresponding centroids
- at the end we choose the value of k with the highest silhouette coefficient


- **Continuous clustering phase** call the function `changeDetected()`: here we try to find change in the distribution in data
   - Standard deviation and mean of the input data are stored during the execution
   - The algorithm tracks how these two values change over time and predicts a concept drift according to the change
   - When *a concept drift is predicted*, current cluster centroids are no longer valid. In such a case the concept drift is realized at line 9 and a re-initialization is triggered at line 10




##### Complexity Analysis
- Let $l$ be the length of the initial data sequence, and $d$ be the data dimension.

- The complexity of estimating $k$ for a single dimension is $O(l)$.

- Since this estimation is performed for all dimensions, the total $k$ estimation complexity becomes $O(d \cdot l)$.

- After determining the initial centroids, running $k$-means takes $O(l \cdot d \cdot k \cdot cs)$, since no iterations of the algorithm are needed, where $cs$ is the number of different centroid sets.

- Assigning a newly received data instance to the nearest cluster during the online phase has complexity $O(k)$.

- As a result, the total worst-case complexity of the algorithm is:
  - $O(k) + O(d \cdot l) + O(l \cdot d \cdot k \cdot cs)$
  - which simplifies to $O(d \cdot l) + O(l \cdot d \cdot k \cdot cs)$.




### MuDi-Stream

- **MuDi-Stream** is a hybrid algorithm based on both density based and grid based approaches

- Input data instances are clustered in a density-based approach and outliers are detected using grids
- For Data synopsis, core mini-clusters are used

- **Core mini-clusters** are specialized feature vectors which keep weight, center, radius and the maximum distance from an instance to the mean
- In the *online phase* core mini-clusters are created and kept up to date for each new data instance.
- In the *offline phase* final clustering is executed over the core mini-clusters.
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422163328.png]]
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422163339.png]]


- Inside a loop, an unvisited core mini-cluster is randomly chosen at line 3 and marked as visited at line 4
     - If this core mini-cluster has no neighbors, it is marked as noise at line 16
     - If it has neighbors, a new final cluster is created with this core mini-cluster and its neighbors, at lines 6-8.

- After that, each unvisited core mini-cluster in the new created final cluster is marked as visited and its neighbors are added to the same final cluster, at lines 9-14.
- This loop continues until all core mini-clusters are marked as visited.
- MUDI-stream is not suitable for high dimensional data, which makes the processing time longer, because of the grid structure.
- Clustering quality of MuDi-Stream strongly depends on input parameters density threshold, decay rate for damped window model and grid granularity.
- These parameters require an expert knowledge about the data.

##### Complexity Analysis.
- Complexity of this linear search on core mini-clusters for each new data instance is O(c) where c is the number of core mini-clusters

- Let G be total density grids for all dimensions, which is exponential to the number of dimensions. Space complexity of the grid is O(log(G)) because the scattered grid are pruned during the execution. Moreover, time complexity of mapping a data instance to the grid is O(log(log(G))) because the list of the grids is maintained as a tree.
- During the pruning, all core mini-clusters and grids are examined. This makes time complexity of pruning O(c) for core mini-clusters and O(log(G)) for grids.
- As a result, the overall time complexity of MuDi-Stream is O(c) + O(log(log(G))) + O(c) + O(log(G)), which equals to **O(c) + O(log(G))**

- Comparison:
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422163406.png]]



## Classification
### Classification: decision trees
- Classic decision tree learners assume all training data can be simultaneously stored in main memory
- **Disk-based decision tree** learners repeatedly read training data from disk sequentially (expensive when learning complex trees)
- *Goal*: design decision tree learners that read each example at most once, and use a small constant time to process it

##### Classification: Key Observation
- In order to find the best attribute at a node, it may be sufficient to consider only a small subset of the training examples that pass through that node.
- Given a stream of examples, use the first ones to choose the root attribute
- Once the root attribute is chosen, the successive examples are passed down to the corresponding leaves, and used to choose the attribute there, and so on recursively

- Use **Hoeffding bound** to decide how many examples are enough at each node 
- Warning: the approach analyzed in the subsequent phases has some theoretical problem, but you can find it implemented in several tools which manage data streams

### Hoeffding Bound
- Let X a random variable varying in a range R
- Let us assume that we have n observations of X
- Let $\bar{x}$ be the average value of the n observations
- The **Hoeffding bound** states that with probability $1-δ$, the mean $\bar{X}$ of X is at least $\bar{x} - \epsilon$ where $\varepsilon = \sqrt{\frac{R^2 \ln 1/\delta}{2n}}$


##### How do we use the Hoeffding Bound?
- Let $G(X_i)$ be the heuristic measure used to choose test attributes (e.g. Information Gain, Gini Index)
- $X_A$: the attribute with the highest attribute evaluation value after seeing $n$ examples.
- $X_B$: the attribute with the second highest split evaluation function value after seeing $n$ examples.
- Given a desired $\delta$: if $\Delta \bar{G} = \bar{G}(X_A) - \bar{G}(X_B) > \varepsilon$, with $\varepsilon = \sqrt{\frac{R^2 \ln 1/\delta}{2n}}$ and $R = \ln (c)$, where $c$ is the number of classes, after seeing $n$ examples at a node,
    - the Hoeffding bound guarantees the true $\Delta G \ge \Delta \bar{G} - \varepsilon > 0$, with probability $1- \delta$.
    - This node can be split using $X_A$ and the succeeding examples will be passed to the new leaves.


##### Which problem?
- Problem:
    - Split measures, like information gain and Gini index, cannot be expressed as a sum S of elements $Y_i$.

- Actually, correct formula
    $$\epsilon = C_{Gain}(K, N)\sqrt{\frac{\ln(1/\delta)}{2N}}$$
    where
    $$C_{Gain}(K, N) = 6(K \log_2 e N + \log_2 2N) + 2\log_2 K$$

##### Two considerations
- Pre-pruning is carried out by considering at each node a **“null” attribute $X_A$** that consists of not splitting the node. Thus a split will be performed if, with confidence $1- \delta$, the best split found is better according to G than not splitting.

- The most significant part of the time cost per example is recomputing G.
    - It is inefficient to recompute G for every new example, because it is unlikely that the decision to split will be made at that specific point
    - Thus, VFDT (Very Fast Decision Tree) learner allows the user to specify a minimum number of new examples $n_{min}$ that must be accumulated at a leaf before G is recomputed.


##### The Algorithm in Words

- Calculate the information gain for the attributes and determines the best two attributes
    - Pre-pruning: consider a “null” attribute that consists of not splitting the node
- At each node, check for the condition
    $$\Delta \bar{G} = \bar{G}(X_A) - \bar{G}(X_B) > \varepsilon$$
- If condition is satisfied, create child nodes based on the test at the node
- If not, stream in more examples and perform calculations till condition is satisfied


##### The Algorithm in pseudo-code
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422163537.png]]
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422163552.png]]
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422163600.png]]


##### Performance Analysis
- $p$: probability that an example passed through DT to level $i$ will fall into a leaf at that point
- The **expected disagreement** between the tree produced by Hoeffding tree algorithm and that produced using infinite examples at each node **is no greater than $\delta /p$**.

- Required memory: O(leaves \* attributes \* values \* classes)


### CVFDT

- CVFDT (Concept-adapting Very Fast Decision Tree learner)
    - Extend VFDT
    - Maintain VFDT’s speed and accuracy
    - Detect and respond to changes in the example-generating process
- Observations
    - With a **time-changing concept**, the current splitting attribute of some nodes may not be the best any more.
    - An outdated subtree may still be better than the best single leaf, particularly if it is near the root.
        - Grow an alternative subtree with the new best attribute at its root, when the old attribute seems out-of-date.
    - Periodically use a bunch of samples to evaluate qualities of trees.
        - Replace the old subtree when the alternate one becomes more accurate.

# 016 Federate Learning
- **Hexa-X** is an European project for develop 6G technology
- Europe require that AI should be:
  - *Transparent*: AI systems and their decisions should be explained in a manner adapted to the stakeholder concerned
  - *Respect privacy and data governance*: Need to collect data to train accurate AI models clashes with need to preserve privacy of data owners

- To respect those two point it was introduced **Federate Learning**

- Machine learning algorithm are data hungry, data are generally spread over different devices with different owners and under the protection of *privacy restriction*
- In practice, we cope with isolated *data island* and we cannot transfer data


- **Federated learning** is a machine learning setting where multiple entities (clients) collaborate in solving a Machine learning problem. 
- It try to exploit all the knowledge that we have without accessing directly to the raw data
- Each client’s raw data is *stored locally* and *not exchanged* or transferred, instead, focused updates intended for immediate aggregation are used to achieve the learning objective.

- Federate learning **aggregate updates** learned at the edge devices to update the model, and **broadcast the model** to allow the edge devices to continuously refine their individual versions
- from the *aggregated data* we cannot access the raw data

- Anyone can request to ai company to remove personal information from the knowledge of a model (e.g. if a person doesn't want to be public), this lead to the *unlearning problem*, but it is difficult to make a big model unlearn things
- If we want to build a model, and the data that we need are not stored all in one server, but distributed in different repository, and we do not have the right to move raw data because they are private

- Instead of transferring the data we transfer the model with the same architecture trained with the data of each source of data
- and then we aggregate those models to obtain our final model, this allow to exploit all the information without transferring any data, we will then transfer the new model to each client, they will train this new model 

## Six main characterizing aspects of FL
- **Data Partitioning**: data partitioning can be horizontal, vertical or hybrid
- It can be used with different DL or ML models
- It manage privacy with different approach
- The communication can be *centralized* or *non-centralized*
- The federation can be cross-silo or *cross-device*
- It is incentivate by government regulation
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422111747.png]]


### Data Partitioning
- Based on how data are distributed among parties, we can categorize FLSs in horizontal, vertical and hybrid

- In **Horizontal FL** the datasets of different parties share the *same feature space* but have little or *no intersection on the sample* space (e.g. CT scans reported in different hospitals)
- It is a natural data partitioning, especially in the cross-device setting

- In **Vertical FL** the datasets of different parties have the *same or similar sample space* but *differ in the feature space* (for instance, municipality registry and hospital data).

- In **Hybrid FL** partition of data among the parties may be a *hybrid* of horizontal partition and vertical partition.


### ML Models
- There have been many efforts in developing new models or reinventing current models to the federated setting. For the sake of brevity we briefly cite the widely-used models nowadays:
	- *Neural Networks*: there are many studies on federated stochastic gradient descent which can be used to train NNs.
	- *Decision tree* is another widely used model as it is highly efficient to train compared with NNs. (FLSs studies for Gradient Boosting decision trees - GBDTs have been proposed recently).
	- *SVM*: there exist a number of examples in which SVM is successfully trained exploiting a federated stochastic gradient descent algorithm.


### Privacy Mechanisms
- Model parameters exchanged during FL rounds may leak sensitive information about the data. Beyond attacks targeting user privacy, there are also other classes of attacks on federated learning (e.g. an adversary might attempt to bias the model to produce inferences that are preferable to the adversary and much else)

- There are many ways to implement privacy in FL:
  - **Differential Privacy**: Add properly tuned random noise to mask the influence of an individual instance on the output
  - **Secure Multi-Party Computation**: Enables two or more parties to compute an agreed-upon function of their private inputs in a way that only reveals the intended output to each of the parties, while keeping those inputs private. 
  - **Homomorphic Encryption**: Enables parties to perform mathematical operations directly on encrypted data without decrypting them. 
  - **Trusted Execution Environments**: TEEs provide the ability to trustably run code on a remote machine, even if you do not trust the machine’s owner. TEEs may provide confidentiality, integrity and remote attestation.


### Communication Architecture
- Communication can be *centralized* and *non-centralized*

- In the **centralized architecture** the data flow is *asymmetric*: the server aggregates the information (e.g. gradients or model parameters) from the clients and sends them back the updated global model. The process is executed iteratively until a *convergence criterion* is met.
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422113359.png|300]]


- In the **non-centralized architecture** the communications are performed *among the parties* and every party is able to update the global parameters directly. There is no need for a trusted central aggregating server. 
- In the non-centralized architecture the major challenge is that it is *hard to design a protocol* that treats every member almost fairly with reasonable communication overhead.
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422113403.png|300]]
- it is possible that members of the federation can change dynamically 

### Scale of Federation
- FLSs can be categorized into two typical types by the *scale* of federation: *cross-silo FLSs* and *cross-device FLSs*. The main differences between them lie on the number of parties and the amount of data stored in each party.

| Axis                   | ***Cross-silo***                                                                                                    | ***Cross-device***                                                                                                  |
| ---------------------- | ------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------- |
| **Primary Setting**    | Training on data distributed across organizations or geographically separated datacenters                           | Training on a very large number of mobile or IoT devices                                                            |
| **Data Availability**  | All clients are almost always available                                                                             | Only a fraction of clients are available at any given time (e.g., diurnal patterns)                                 |
| **Data Distribution**  | Data is generated locally and remains decentralized, Each client stores its own data and cannot access others' data | Data is generated locally and remains decentralized, Each client stores its own data and cannot access others' data |
| **Scale**              | Typically 2–100 clients                                                                                             | Up to 10^10 clients (massively parallel)                                                                            |
| **Client Reliability** | High reliability; few failures                                                                                      | Low reliability; ≥5% of clients may fail or drop out                                                                |
| **Primary Bottleneck** | Computation or communication                                                                                        | Communication (often over slow networks, e.g., Wi-Fi)                                                               |
| **Data Partition**     | Fixed: horizontal (by samples) or vertical (by features)                                                            | Fixed: horizontal (by samples)                                                                                      |

### Motivation of Federation

- In real-world applications of FL, individual parties need the **motivation to get involved** in the FLS
-  The motivation can be *regulations* or *incentives* (for instance having a better service if you share your data). The parties inside the system can be collaborators as well as competitors


### Popular approaches  (Federated Averaging)
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422115201.png]]

- The first paper about FL used neural networks
- In the learning phase we learn the weight of the network
- In FL each client receive a model and update the local neural network (with its local data it update the value of the weights)
- They will then be aggregated in the server computing the average of the weights
- The new aggregated model will then be sent to the clients 

- One version of this approach exploit a local learning
- The other transmit the gradient to the server and the server update the model 

- Since we cannot have the data on which the model was trained we don't have tre training set available, for each client we have only the local dataset, we are obliged to use that on post hoc techniques like shap, since those dataset are different we will have **different explanations** on different clients
- for solving this problem it is possible to use an approach based on a federate clustering algorithm
- apply a federate clustering on all the data we have without moving the data and then develop a prototypes of the clusters to send to each client, this approach is called *federated shap*

![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422115210.png|400]]
- 𝐶 = fraction of clients that participates in each federated round
- 𝐾 = total number of clients (indexed by k)
- 𝐸 = number of training passes each client makes over its local dataset on each round
-  𝐵 = local minibatch size used for the client updates (B = ∞ indicates that the full local dataset is treated as a single minibatch
- 𝑃𝑘 = set of indexes of data points on client k, with 𝑛𝑘 = |𝑃𝑘|

- In **FedAVG** (*Federated averaging*) each client locally takes one or multiple steps of gradient descent on the current model $𝑤𝑡$ using its local data, and the server then takes a weighted average of the resulting models.

- In **FedSGD** (*Federated Stochastic Gradient Descent*) each client k computes the gradient on its local data at the current model $𝑤𝑡$ and the central server aggregates these gradients and updates the global model.
- Note that FedSGD coincides to FedAvg with 𝐶 = 1, 𝐵 = ∞, 𝐸 = 1
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422115452.png|250]]

- so in the first one we obtain the new models and the server takes a weighted average of the models, in the FedSGD we compute the gradients and the server will aggregate those gradients with a weighted average to train the new model


### XAI models: why?
- Post-hoc techniques correspond to the most common ways human explain things by themselves:
  - Text explanation
  - Visual explanation
  - Local explanation
  - By example
  - By simplification
  - Feature relevance

- Transparent model have instead three levels of explainability:
  - **Simulatability**: the ability of a model of being simulated by a human
  - **Decomposability**: the ability to explain each of the parts of a model
  - **Algorithmic transparency**: the ability of the user to understand the process followed by the model to produce output from input


### XAI: interpretability versus performance
- Usually more complex model are more accurate
- The more a model is accurate the less is explainable
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422115911.png|400]]


///controlla se gli appunti sono nell'altro file

### Federated Decision trees
- in each client train a local decision tree with the local data, with n clients we will have n tree
- we transfer the decision tree to a server, we need to aggregate them 
- but when we try to merge decision tree we can have *conflicts in the rule* with the same antecedent and different classes 

- There are different way to resolve conflicts, the main problem is that the final decision tree is huge
- the main advantages is that we have very little exchange of data and loose a bit of performance
- the solution is changing a bit the approach into build the decision tree
- The solution is to *build iteratively* the decision tree in a cooperative way using the *variance*, moving only the sum or the squared sum of data without moving the data, in this way it is possible to generate the same decision tree, but without transferring information 


![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422120912.png|400]]


- If two rules share a condition, i.e., rule 2A, and rule 4B, the less restrictive condition is 0 selected
- The rule 1A has the condition x0 <= 32.5, while the rule 3B has the condition x0 > 39, making them incompatible
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422120955.png]]

- The metrics used for determining the variable to be used in the decision node is the *variance*
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422121022.png]]
- to learn regression three we cannot use the info gain, instead we need to select the attributes computing the variance of the attributes, our  output is not a label, but a real number
- we need to isolate the subspace in which the output values do not vary that much 
- the output will be the average of the values in the subspace

- in federate we are building a single decision three exploiting *aggregate data* 
- we compute the variance for each variance
- the selection is the same as having all the data, so I obtain the same regression three if i use all the data or all the aggregated data 


- the mean is equal to:
$$
\bar{y} = \frac{1}{n}\sum y_i
$$

- the var reduction is equal to:
$$
VarReduction = Var(S) - (\frac{n_L}{n} Var(S_L) + \frac{n_R}{n} Var(S_R))
$$


- the variance is equal to:
$$
Var(y) = \frac{1}{n}\sum (y_i - \bar{y})^2
$$

- The variance can be computed also as:
  $$Var(y) = \frac{1}{n}\sum y_i^2 - (\frac{1}{n}\sum y_i)^2
   $$ 
- For each variable, we compute the first and second sum in each node.
- Then, each node transmits the two sums to the server which compute the Var(y) and the VarReduction


### Horizontal federated c-means (LLF-CM)

![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422114433.png]]
- With this method we can apply the k-means algorithm to distributed data


- Let: $$
\mathbf{q}^{(t),m} = \left[ q_1^{(t),m}, \; q_2^{(t),m}, \; \ldots, \; q_{N_m}^{(t),m} \right], 
\quad q_j^{(t),m} \in \{1, \ldots, C\}
$$ be the vector that indicates the cluster for each object in dataset $P^m$
- Each data owner $P^m$ assigns each object in the local dataset to the cluster with the nearest center


- We are working with the horizontal federated kmeans, in horizontal partition we have different instances described by the same features 
- we have to fix at the beginning the number of clusters we want to obtain 
- we have a tolerance $\epsilon$ and a max number of round T
- client and server must cooperate 
- at each round T we send the vector of centroids  
- each client compute for each object local to the client a membership for the cluster
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422114423.png]]

- Once updated
- we transfer the new prototype to the client
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422114417.png]]
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422114408.png]]
At the end we obtain the same clustering obtained by apply the kmeans of the overall dataset
- this is true only if for some local dataset we have only one object that belong to only a cluster


### Vertical federated c-means (LLF-CM)
- In the vertical clustering we have different clients, each of them has the same instances, but described by different features
- Tu build the cluster in the ideal case we should apply the algorithm to the dataset with all the results


- here clients have only a subset of dimensions
- since the distance between an object and a cluster centroid, compute the distance using all the attributes, if we are able to transmit the distance, we should be able to recreate the original distance 
- by transmitting the distances computed on the clients we can obtain the same result as apply kmeans to all data 
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422114356.png]]
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422114336.png]]
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422114331.png]]
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422114324.png]]
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422114318.png]]
- in fuzzy kmeans an object can belong to different clusters with different values 


- In summary it is possible to use classical algorithm in a federate environment without moving raw data, but only aggregated one 
- we need to be careful that the aggregated data are not intercepted and modified by an attacker 

# 017 XAI Explainable AI 
- XAI is important for accountability, legal reason, and trust of user, it also help us understand better how the model function 
- Some model like tree are *interpretable by design*, others are more opaque, and in this case we can use *post-hoc technique*, in which we generate very complex model and we ask ourself how the system generate that output just later 

- **Explainability**: we are able to understand *how* from an input we obtained a specific output 
- **Transparency**: a more broad concept compared to explainability 

- (guarda meglio differenza tra explainability e transparency)

- Explainability and accuracy have conflicting objective 



### XAI Model 
- Is a research field born in 1958, initially it was related to requirements for a system able to learn
- The modern idea of *Explainability* is to **understand how a system works**, we want to explain given an input how and why an output is generated
- The term XAI comes from 2004 

### Why should I understand how a system works?
- In healthcare an AI that explain why it gave a certain diagnosis can improve the trust from the doctor
- AI system should support doctor, not replace them. The influence of the supporting system is relevant
- If we understand the internal behavior of ai we can also understand if the model has some bias (e.g. negate a load to people of certain ethnicity)



- We need to create an explanation that has to be stable and understandable from all users that us ai 

##### Some Examples
- In *drug discovery*, by understanding how an AI model arrive at a certain conclusion about a drug compound is vital for validation and optimizing research efforts

- In *credit scoring*, explainability ensure fairness and transparency in credit decision, allowing individual to understand why they were granted or denied credit

- *Banks* and financial institution use AI for risk assessment, explainability helps in comprehending the factor influencing these assessments

- Understanding the reasoning behind an autonomous vehicle decision making process is crucial for ensuring safety and building public trust in these technologies.

- Explainability is crucial in predictive policing and recidivism prediction models to ensure fairness and prevent biases in decisions related to law enforcement and sentencing.

- Transparent models enable the identification and **mitigation of biases**, promoting fairness and equity in various AI applications, such as hiring processes and resource allocation


### Why should I understand how my system works (in practice)?
- Reason to understand the behavior of a system:
  - Increase trustiness
  - Laws are respected
  - Ethics 
  - Bias fixing
  - Performance improvement
  - Bug fixing


- Even if AI system are modeled after human behavior they do not behave exactly like us (*Wittgenstein's Lion*)


### Trustworthy

- **Trustworthy ai**: there are two problem:
  - The bias are generated directly from the ML approaches, because if data have some bias the model will inherit those bias
  - In the application of ai we can regulate how to use them 

- Different country have very different regulation on the use of ai:
  - USA: commercial and right oriented, each state has different laws
  - EU: commercial and fundamental tights oriented, trying to be an example for legislation
  - China: commercial oriented, focus on data privacy

### Trustworthy AI in EU

- In EU there was a guideline in 2019 called *Ethic guidelines for trustworthy AI*, that states that ai should be:
  - **Lawful**: respecting all applicable laws and regulations
  - **Ethical**: respecting ethical principles and values
  - **Robust**: both from a technical and social perspective

- From the 2019 regulation was born the *AI Act*, which final version was written in 2024
- This year were written some guideline for generative ai, for example after what level of fine tuning the responsibility goes from the producer of the base model to who tuned it 

- There is an Italian regulation that is basically the same as the AI act, and there are some part that are more suggestion than law

- The final decision should be in the hand of humans 

- The transparency usually refers to understand how an output is produced from an input
- The transparency in ai act refers to the source of information (were the model have find a certain information)



### Trustworthy AI in EU: ethical aspects
- There are *seven* principles that should be continuously evaluated and addressed throughout the AI system's life cycle
  - Human agency and oversight
  - Technical robustness and safety
  - Privacy and data governance
  - Transparency
  - Diversity, non-discrimination and fairness
  - Societal and environmental wellbeing
  - Accountability

### Transparency: 3 aspects
- There are three aspect in transparency:
  - **Communication**: Humans have the right to be informed that they are interacting with an AI system.
  - **Traceability**: Data gathering/labelling and algorithms should be documented to the best possible standard
  - **Explainability**: Systems and decisions should be explained in a manner adapted to the stakeholder concerned. Different explainability levels for different kind of models

### Trustworthy AI in EU: ethical aspects
- Regarding Explainability, you assess:
  1. to what extent the decisions and hence the outcome made by the AI system can be understood?
  2. to what degree the system’s decision influences the organization’s  decision-making processes?
  3. why was this particular system deployed in this specific area?
  4. what the system’s business model is (for example, how does it create value for the organization)?





- black box: we don't know the internal behavior, so we cannot understand how the output is generated. They have high accuracy, low explainability (e.g. Neural network, deep learning model, ensemble)
- gray box: we can partially analyze the internal behavior of the model, but we have some fuzzy characteristics (e.g. fuzzy model, bayesian network, so we have rules that use fuzzy partitions)


### White Boxes 
- Those models that are easily interpretable for a human.
- Interpretability as: the ability to explain how decisions have been taken or to provide the meaning in a way that is understandable by a human. HOW a prediction has been taken

- Main models:
  - **Linear/logistic regression models** are intuitively understandable: the larger the coefficient, the larger the impact of that feature on the output
  - **Case based reasoning** like humans intuitively look in the past for similar input situations, and use past outputs for new inference, typical methods involve k-NN or defining *Prototypes* 
  - **Decision tree models** are similar to human reasoning as a sequence of simple decisions in the form “if-then” (logical models)

### Grey Boxes
- These model can be interpreted at some degree if they are carefully designed, e.g.  a fuzzy-rule based system
- in the **fuzzy set** we do not have a crisp separation between set, but we have a set of value that belong to some degree to multiple sets, so a gradual separation
- It is possible to activate multiple rules, so we have some problem in terms on interpretability 
- Linguistic rules and fuzziness help interpretability

- **Bayesian model** usually takes the form of a probabilistic directed acyclic graphical model whose links represent the conditional dependencies between a set of variables. For example, a Bayesian network could represent the probabilistic relationships between diseases and symptoms

### Focus on Decision Trees and FRBS
- Trees and Fuzzy Rule Based Systems are both in the category of the *logical model*, and both can be expressed by a set of "if-then" rules

*- How can we evaluate interpretability? *
  - The quantitative evaluation is based in the **number of rules**, antecedent and coefficient
  - The qualitative evaluation is based on **semantic**, If I use many fuzzy sets, I can end up with many linguistic labels such as "very very very hot", for me low temperature goes from 0 to 5 degree, but is like this for everyone?

### Black (opaque) boxes
- Those models that are not especially designed to be interpretable by humans (still, we want them to be explainable)
- **Explainability** as: given a certain audience, explainability refers to the details and reasons a model gives to make its functioning clear or easy to understand.

- For this reason we use a posteriori (post-hoc) method to understand why a given input return a certain output, we usually build another model to understand the behavior of our model
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260417221444.png]]


### XAI: Explainable AI
- **Post-hoc method**: technique for explain the predictions of black boxed methods, there are 4 point to consider:
  - We need to use methods that *resemble the human approach* (the explanation should be understandable by humans)
  - We can have different method depending on the *dataset*
  - We can have *Global/Local* methods
  - We can have Model *Agnostic* / Model *Specific* methods

### Another point of view
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260417221740.png]]



### Post-hoc methods resembling human approach
- Methods resembling human approach (that humans can understand)
	- Text explanations
	- Visual explanations
	- Local explanations
	- Explanations by example
	- Explanations by simplification -> surrogate models.
	- Feature relevance explanations

### Post-hoc methods by dataset
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260417222009.png]]

- in a time series we can highlight the part of the signal relevant, as a matrix of scores
- in a graph we highlight a score in each node that tell us the contribution on each node or edge
### Model agnostic/ model specific post-hoc methods

- **Model specific methods**: Meant to explain a specific AI model

- **Model agnostic methods**: not tied to any specific AI model, they have an high flexibility, but possibly an high computational effort

### Global and Local explainability and interpretability

- *Post-hoc explainability*:
	- **Local explanators**: explain individual predictions of the AI model
	- **Global explanators**: provide global insights into the entire model (often comes from aggregation of local explanations)

- *Inherently interpretable*:
	- **Local interpretability**: refers how the model is defined for a specific region	(e.g. for a Rule Based System, the activated regions and their rules)
	- **Global interpretability**: (schematically): it refers to the structure of the model -> complexity	notion (e.g. : number of rules for extracted from a decision tree)


### Post-hoc techniques intuition

- Given a dataset with j=1,…, J features and a learned model model f
- We compute a score metric (e.g. accuracy, MAE...) s of f To evaluate the importance of a single feature j, it is intuitive to see how the metric score changes while the feature value changes. If the score changes a lot, we can intuitively say that this feature is important Thus,
1. for each feature j we randomly shuffle K times (k=1,2,…, K) its value, and obtain a "corrupted version of the data"
2. we compute the score on corrupted data s(k,j)
3. Compute the importance of the specific feature I(j) as: $$ i(j) = s - \frac{1}{K}\sum_{k=1}^K s(k,j)$$

- Question: if your *feature $j$ is constant* (the values are all the same), what is the importance $I(j)$ of this feature? -> it would be = $0$ … no importance

### SHAP (Shapley Additive Explanations)  
- Is a post-hoc method to estimate the *shapley values*
- *shapley values* tells how much a feature contribute positively or negatively to a prediction 

 h SHAP is based on game theory and assigns each feature a contribution to a prediction by considering **all possible coalitions (subsets of features)**.  
For each coalition, it measures how the prediction changes when a feature is added, and then **averages this marginal contribution across all combinations**, ensuring a fair attribution.  
  
The prediction is decomposed as:  
$$  
\hat{y}_i = f(x_i) = \phi_0 + \sum_{j=1}^{F} \phi_j  
$$  
where:  
- $f(x_i)$: model prediction for instance $x_i$  
- $\phi_0$: **base value**, i.e., the average model prediction over a background (reference) dataset  
- $\phi_j$: **Shapley value** of feature $j$, representing its contribution  
- $F$: total number of features 

- **Background dataset**: perturbated dataset used to train the local explainer 

To evaluate each coalition:  
- selected features are kept from the instance  
- the others are replaced using values from a **background dataset**  
- this simulates the model prediction without access to certain features  
  
- SHAP provides a **local, additive, and theoretically grounded explanation** of model predictions.





### LIME: Local Interpretable model-agnostic exploration
- LIME provide a simpler model that try to mimic a model locally

- Steps:
1. We consider the model m (usually opaque) we want to explain and an input instance I
2. We create perturbed samples "close" to the instance I. On this sample (that is "synthetic"), we use the model "m" to get the predictions
3. We train a simpler model, interpretable by design, on the couple Synthetic inputs -> model "m" predictions (there is a weight based on the distance) from "i"
4. The simpler model (also called **surrogate model**), being interpretable by design (such as a linear model or a decision tree) is used to explain the model "m" locally
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260417222921.png|300]]
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260417222915.png|500]]



- Advantages: it is easy to understand
- Disadvantages:
  - It use a synthetic data generation, if not careful it can create not accurate local models
  - The chosen notion of distance can influence a lot the results
  - When evaluating the performance of the full strategy, you must take into account the double errors in the prediction -> the errors related to model "m" and the errors related to the surrogate model
  - LIME provides explanations that are valid only locally around a single instance, building a global explanation would require many local models, which is often computationally expensive, incomplete, and potentially inconsistent.



### Counterfactual explanation
- Given the output y0 and the corresponding input x0, what should be different in x0 to get another output y1? -> in general, I'm very interested in the SMALLEST change in x0


### SHAP and LIME for images
- A **Saliency Map** (*SM*) is an image in which a pixel’s brightness represents how salient (important) the pixel is for the model decision
- In a classification task, a positive value means that that pixel has contributed positively to the classification, while a negative one means that it has contributed negatively.

- **LIME** is a local post-hoc model- agnostic explainer, using *superpixels* (segments of the image)
- **SHAP**, in the version GRAD-shap, produces a Saliency map for each class in the input image can explain simultaneously different labels

![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260417222559.png]]


- In literature (and also in the public debate) you will find that the nomenclature is not yet fixed, so, terms such as interpretability, explainability, transparency are sometimes used as synonyms.







