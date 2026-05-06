##### Nomenclatura Generale
- Fai attenzione a dire hyper *parameters name* e hyper *parameter values*, se si dice hyperparameters lui intende il nome/tipo, ma non il valore che essi possono assumere 

- Il k/fold ha come **bias** il fatto che lo si sta eseguendo su certi iperparametri, si dovrebbe invece fare un ciclo dove si esegue la grid usando un kfold
- Con il random sampling si possono testare piu value di iperparametri rispetto alla grid

- Un possibile approccio e' fare prima una random search, trova le combinazioni che danno migliore accuratezza e poi su quei valori esegui una grid


---

# 1. Hyperparameter and parameter optimization
- **Parameters**: learned from data automatically (e.g. in a tree can be a split point in an internal node)
  - They have as objective to fit the train data (*inner optimization*)

- **Hyperparameters**: chosen before training (e.g. in a tree can be the maximum depth, splitting criterio, minimum sample per split)
  - They have as objective to optimize the generalization performance (*outer optimization*)

![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260418192917.png|300]]

- We can divide the learning of parameters, and hyperparameters in **inner loop** (fit model parameters on the training data), and **outer loop** (adjust hyperparameters to optimize a model selection criterion)
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260418193250.png]]


##### Hyperparameter tuning as a search problem
- From the scikit-learn documentation, a search consists of:
	- An **estimator**: the model that we want to tune
	- A **hyperparameter space** (**HS**): the hyperparameters that we want to tune with the range of hyperparameters value that they can assume
	- A **method for searching or sampling candidates**: is the strategy used to try different combination of hyperparameters (e.g. grid search or random search)
	- A **cross-validation scheme**
	- A **score function**: a function used to determine the best model, for instance accuracy or f1 score 


- **Grid search**: Exhaustively evaluate all combinations in a predefined grid
- **Random search**: Sample a fixed number of candidates from the parameter space according to a distribution

- Even with a limited budget (number of trial), random search already visits very competitive regions of the search space.
- usually the best solution is not a single point, but a broad plateau

##### Bergstra and Bengio’s main insight
- Hyperparameter optimization problems are often **much more sensitive to some dimensions** than to others
- If we already know the influential dimensions, we can design a very *good grid*
- If we do not know them in advance, *random search is usually faster and more efficient*


##### But why we can do better with the same budget?
- Suppose $x , y ∈ \{1, 2, 3\}$ are two hyperparameters. With 9 trials, random search covers more values along each axis. This is key when one dimension is much more important than the other.
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260419142832.png]]

##### A useful abstraction: low effective dimensionality
- Suppose that the validation performance can be written as follows:
  $f(x,y) = g(x) + \epsilon(y), \quad |\epsilon(y)| << |g(x)|$
- so the performance depend on both x and y, but x influence the value much more than y
- Then:
  - performance change strongly along x
  - performance change weakly along y
  - a budget of N random trials explores more distinct values of the important variable x than a $\sqrt{N}x\sqrt{N}$ grid
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260419142909.png|500]]

##### Other optimization strategies exist
- The notebook we will see briefly mentions more sophisticated methods, including:
  - **Bayesian optimization**
  - **Gradient Based** approaches

- Grid and Random search are excellent baselines, but they are not the only options

##### A practical rule of thumb
- Never tune blindly, a search algorithm can find good configurations, but it cannot replace model understanding. Always inspect the meaning, scale, and expected effect of the hyperparameters you tune


##### A practical workflow for hyperparameter optimization
$$\lambda^* = \text{arg max}_{\lambda \in \Delta} f(\lambda)$$ 
- where:
  - $\lambda \in \Delta \subseteq \mathbb{R}^d$ is a vector of hyperparameters
  - $\Delta$ is the **search space** (domain of hyperparameters configurations)
  - $f(\lambda)$ is the validation score (e.g. accuracy, F1-score, AUC, RMSE)

- we do not use a large grid because $f(\lambda)$ is a *black-box* function whose structure is unknown before search, and each evaluation is computationally expensive

- A better approach is:
  1. Start with a broad *random exploration*
  2. *Inspect* the results
  3. *Restrict* ranges and refine search
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260419144352.png]]


##### What should you remember about grid vs random search?
- Random search is *not universally better* than grid search. It is often a better default choice when we do **not know in advance** which hyperparameters are more influential
	- If all hyperparameters are equally important and the search space is tiny, grid search is fine.
	- If only a few hyperparameters dominate performance, random search is usually more efficient.
	- In real projects, we often use *random search first*, then a *more focused local search*



### Putting it all together: tuning complete pipelines
- Real workflows rarely contain just one estimator
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260419144558.png]]
- We may want to tune the whole pipeline jointly, not each step independently

##### Why tune the whole pipeline?
- Reasons to tune the whole pipeline:
	- Steps interact with each other: preprocessing and feature engineering affect what the model sees and its behavior. Optimizing each step separately may lead to **suboptimal combinations**
	- We want to **evaluate the full process**: the validation score should reflect the performance of the entire pipeline, not isolated components.
	- **Avoid data leakage**: preprocessing must only be fitted on training data within each split. A unified pipeline ensures this happens correctly during cross-validation

- **IMPORTANT**: Treat the pipeline as a single system and tune it end-to-end

- Example of pipeline tuning from the notebook:
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260419144853.png]]
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260419144942.png]]
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260419144951.png]]

- If we have too few component we decrease the accuracy
- To high or low regularization is hurting performance too
- Pipeline tuning lets preprocessing and classifier be *optimize together*

### Model selection vs. performance evaluation
- There are two core components of good ML practice:
  1. **Model selection**: choose algorithms and hyperparameters.
  2. **Performance evaluation**: estimate generalization capability
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260419145241.png|300]]
 - *How can we evaluate the model fairly and without bias?*

##### Question A: can we trust the best CV score from tuning?
- Using `GridSearch` or `RandomizedSearch` the score for the best setting **IS NOT** a good estimate for the generalization performance

##### Why a single CV level can be optimistic
- When we evaluate many hyperparameter settings
  - we keep adjusting the model until it performs best on the validation folds
  - information from those folds can effectively leak into the selection process (DA RIVEDERE)
  - the selected score becomes **optimistically biased**

- *Core Issue*: the same resampling procedure should not safely play both roles at once (selecting the model and evaluating its final generalization performance)


### Solution B: if a hold-out test set is available
- We can tune the data (parameters and hyperparameters) on the test set and using the test set only for the final evaluation
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260419150136.png]]


### Solution C: if no hold-out test set is available
- if we haven't any hold-out test set, we can apply the *Nested Cross-validation*
- **Nested cross-validation**: use one cross-validation loop for model selection and another, outer loop for performance evaluation

- *Inner CV*: choose hyperparameters
- *Outer CV*: estimate the generalization error of the whole selection procedure


##### Hyperparameter search space
- We consider the following search space, with only the hp max_depth and criterion for a classification tree
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260419150410.png|500]]


##### Nested Cross-Validation Algorithm
- Let $K^{OUT}$ be the number of *outer folds*, $K^{IN}$ the number of *inner folds*, and $H = \{h_j\}_{j=1}^H$ the *set of combination of hyperparameter values* previously selected 


- We perform the following steps for each outer folds $o = 1,...,K^{OUT}$
1. Let fold $o$ be the outer test set, and the other folds the outer training set
2. Divide the outer training set into $K^{IN}$ folds
3. For each combination of hyperparameter value $h_j \in H$ we perform a $K^{IN}$-fold cross validation, instantiating models based on $h_j$, then we calculate the average performance $p_{o,j}^{IN}$ on the $K^{IN}$ inner validation folds
4. Select the best hyperparameters, e.g. the combination $h_{o,j}^*$ on the entire outer training set
5. Evaluate the performance $p_{o,j}^{OUT}$ of the resulting model on the outer test set

- Each outer fold may produce a different best configuration, because each training subset is different
- After all this passage we can estimate the performance of the general model and its variance as:
$$  
\bar{p} = \frac{1}{K^{OUT}} \sum_{o=1}^{K^{OUT}} p^{OUT}_{o j^*}  
$$  
  
$$  
\sigma = \sqrt{ \frac{1}{K^{OUT} - 1} \sum_{o=1}^{K^{OUT}} \left( p^{OUT}_{o j^*} - \bar{p} \right)^2 }  
$$


![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260419150757.png]]
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260419150802.png]]


### Training the Final Model
- Nested CV estimates the performance of the model selection procedure
- After the Nested CV:
  - use the entire dataset
  - run hyperparameter search again
  - select the best configuration
  - train the final model

- This model can be used for future predictions

##### What should you remember about nested CV?
- **Non-nested CV** often looks slightly better because it reuse the same data for selection and evaluation
- **Nested CV** estimates the performance of the full model-selection procedure, not just one fitted model
- It is more *Computationally expensive*, but returns *realistic performance*

- The notebook also cites a 2021 paper arguing that nested CV may be overzealous in many practical settings.
- For algorithms with relatively few hyperparameters, a cheaper flat-CV procedure may often select a classifier of very similar practical quality.

![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260419153609.png]]


### Best practices
- Understand the model before tuning it.
- Start with a small, meaningful hyperparameter space.
- Use random search when the space is large or poorly understood.
- Tune whole pipelines when preprocessing affects the classifier.
- Separate model selection from final evaluation.
- Use nested CV when an unbiased estimate is essential and no hold-out test set exists.

##### Conclusions
- Parameters are learned, hyperparameters are chose
- Hyperparameter tuning is a *search problem*
- Grid search is exhaustive, but can be wasteful
- Random search is often more efficient
- Pipelines optimize preprocessing and classification jointly
- Nested CV reduces selection bias in performance evaluation

---



- in a **normal k-fold cross validation** we select first the hyperparameters, and then we train our model (ignoring the hp tuning), this lead to an optimistic view and to a bias
- the hyperparameter tuning is done in a different step
- it is a problem if you use the same data to choose the hyperparameters and then choose the parameters 

- in a **nested loop cross validation** instead we deal with two problem, the hyperparameters tuning and the model fitting, it does not find the best hp values, or the best model, it is used to return an *unbiased model*
- in this case the dataset is divided in inner part and outer part, and the different parts are used for tune par and hpar, each one is divided in fold

- after you have done the cv you can train your model from zero in the entire dataset

- the *outer loop* divide the ts into outer training set and outer test set
- the *inner loop* try a combination of hp for k fold, then you compute the average score in the k-fold and obtain the average score
- after that you choose the hp combination with the highest score value, train the model with the complete outer training set and compute its score with the outer test set 
- repeat the process for each of the outer fold 
- in the final part you plot the k score for each ML methods and compare different solutions, the best estimator will be chosen by this evaluation 
- if some technique overlap in their result (in the boxplot body) you can perform some statistical test (t-test)

- once you have decided the best method you have to find the best hp again using all data, and then train again your model 

- all the result you obtain depend on the partitioning of the folds 

- stratified cv: when dividing the dataset into fold you preserve the distribution of class in each folds
- also the number of folds can affect the results in your evaluation 
- if you have a small dataset using an higher number of k can give problem, because folds will be populated by fewer samples

# 2 Outlier detection
- An **outlier** (or anomaly) is an observation that significantly deviates from the others, arousing suspicion of being generated by a different mechanism

- Outliers arise from many sources:
	- measurement or recording *errors*;
	- rare but *genuine phenomena* (fraud, faults, novel events);
	- objects from a *different distribution*.

![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422102014.png|300]]

- Whether an outlier is noise to remove or signal to detect entirely depends on the application

- Approaches to find outlier:
  - **Statistical**: if we model the normal distribution of data, outlier are the low-probability points (e.g. z-score, Grubbs test)
  - **Distance**: outlier are far form their neighbor (e.g. knn)
  - **Density**: outlier live in low-density regions (e.g. DBSCAN, LOF)
  - **Model**: outlier are hard to reconstruct (e.g. isolation forest, autoencoders)

- We will consider 4 dense cluster, 1 sparse cluster (each composed by 200 samples), and 20 outlier
- in real application the **ground truth** is unknown, here we know the 20 outlier, so we can compare the different methods detection as a classification problem

##### DBSCAN: density-based clustering
- **DBCAN** identifies clusters as connected dense regions, and labels isolated points as noise, it uses two parameters:
  - $\epsilon$: the radius of the local neighborhood
  - $MinPts$: minimum number of points in your neighborhood to be considered a dense region

- Each point is classified as:
  - **Core point**: has at least MinPts points in its ε-neighborhood 
  - **Border point**: lies in the neighborhood of a core point, but does not satisfy the core condition
  - **Noise point**: does not belong to any dense region

![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422102853.png|300]]

- *Key idea*: DBSCAN grows a cluster by connecting nearby core points and then assigning border points to that cluster.
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422102941.png]]

- *Noise points* are DBSCAN's **natural outliers**, they do not belong to any cluster


- $\epsilon$ (**eps**): is the radius of the neighborhood, controls the spatial scale at which density is measured
  - if it is too **small** we have a *low precision*, and many noise points
  - if it is too **large** we have *low recall*, and many outliers are absorbed into clusters
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422103417.png]]

- **MinPts**: Minimum number of points inside the $ε$-neighborhood for a point to be a core point
  - Common heuristic: $MinPts ≥ D + 1$ (where $D$ = *number of features*)


- if we have some dense clusters and one sparse cluster, with a small **eps**, the point in the sparse cluster are not dense enough to form a cluster, so DBSCAN could mark them as noise
- DBSCAN uses a *global* density threshold, it struggles when data contains clusters of *varying levels of density*

###### How to choose ε: the k-dist plot
- The k-dist plot is a heuristic for estimating a good ε:
   - 1 Fix $k = MinPts$
   - 2 For each point, compute the distance to its k-th nearest neighbor
   - 3 Sort distances in ascending order and plot.
   - 4 Identify the “*elbow*”: the point of maximum curvature.
   - 5 Set $ε$ at the elbow value.
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422103900.png|300]]
- Points with a small k-distance are in dense regions (inliers). The elbow separates them from sparser, outlier-like points.
- If in the elbow diagram there are **two elbow**, the point before the first are in dense clusters, the point before the second are in sparse clusters, the points after the second elbow are outliers

- Usually when we have multiple elbow to identify the right one we use domain knowledge and experimentation 

##### Local Outlier Factor
- DBSCAN uses a global density threshold $ε$. This is problematic when:
  - clusters have different densities;
  - there is no single ε that works everywhere

- The **Local Outlier Factor** addresses this by comparing each point's local density to that of its neighbors
- A point is an outlier if its neighborhood is **significantly less dense** than the neighborhood of its neighbors
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422104329.png|200]]

- LOF: key definitions: Let $k$ be a fixed neighborhood size and $N_k(p)$ be the $k$ nearest neighbors of $p$

- **Reachability distance**: the maximum between the k-th fairest neighbor of o, and the distance between p and o 
$$  
\text{reach-dist}_k(p, o) = \max\big(k\text{-dist}(o), \, d(p, o)\big)  
$$

- **Local reachability density** (**LRD**): Inverse of the average reachability distance to p’s k neighbors
$$  
\mathrm{lrd}_k(p) = \left( \frac{\sum_{o \in N_k(p)} \text{reach-dist}_k(p, o)}{|N_k(p)|} \right)^{-1}  
$$


- **Local Outlier Factor** (**LOF**): average ratio of the neighbors' LRD and p's LRD
$$  
\mathrm{LOF}_k(p) = \frac{1}{|N_k(p)|} \sum_{o \in N_k(p)} \frac{\mathrm{lrd}_k(o)}{\mathrm{lrd}_k(p)}  
$$

- $LOF(p) ≈ 1$ ⇒ **inlier**: p has similar density as its neighbors. 
- $LOF(p) ≫ 1$ ⇒ **outlier**: p’s neighborhood is much less dense.
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422105035.png|300]]

- **contamination**: is the expected *fraction of outliers* in the data
- In LOF you anso need to set the *contamination* that controls the decision boundary, if you have some domain knowledge set it manually, otherwise choose "auto"
- the top $contamination*n$ of point with the highest LOF score will be labeled as outliers

- The LOF deals with clusters with different level of density, it compare the *area* of the point p with its k neighbor, and compare with the area with its neighbor 


- LOF produces a *continuous score*, not just a binary label. This allows finer-grained analysis, ranking, and threshold sensitivity analysis
- In scikit learn inliers has value close to $-1$, outliers have large negative values, if you try to visualize it, outliers have large red circles, inliers doesn't have any circle
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422105422.png|200]]

- Summary:
![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260422105539.png|400]]
- No method wins universally: choose based on data structure and the application.







































































