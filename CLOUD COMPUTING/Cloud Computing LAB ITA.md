# 01 Big Data Processing

- I Big Data non provengono solo dal web: altre fonti includono acceleratori di particelle, osservatori, sequenziamento del DNA, finanza, smart city e Internet of Things  
- La quantità di dati è cresciuta esponenzialmente negli ultimi anni e continuerà a crescere  

- *Edge computing*: è una forma di cloud computing più vicina all’utente finale  
  → i dati vengono inviati a data center più piccoli e vicini, invece che a grandi data center lontani  

## Divide the Computation 

- Se i dati sono molto grandi, non è possibile elaborarli in modo sequenziale  
- Un’applicazione tipica:
  → riceve un input  
  → esegue una computazione  
  → restituisce un output  

![[Pasted image 20260309154424.png|200]]

- Se i dati sono gestibili ma la computazione è molto complessa, si può decomporre l’applicazione in componenti più piccoli chiamati **task** (o funzioni)

![[Pasted image 20260309154500.png|500]]

- I task possono essere eseguiti:
  - in modo sequenziale  
  - in parallelo  
  - oppure con un approccio ibrido  

- Per eseguire task in parallelo, devono essere **indipendenti**

- In questo approccio NON si dividono i dati di input  
  → ogni task riceve tutto l’input  
  → si divide solo la logica computazionale (*controlled decomposition*)

![[Pasted image 20260309154642.png|500]]

- Problemi principali:
  - come dividere il codice in task paralleli (capire le dipendenze)
  - come distribuire i task su più macchine
  - come coordinarli (alcuni task devono aspettarne altri)

---

### Parallel Architectures

- Le diverse parti del codice devono comunicare tra loro:
  - **memoria condivisa** (es. thread)
  - **message passing** (es. processi)

![[Pasted image 20260309154814.png]]

- Processo tipico:
  - identificare le parti eseguibili in parallelo  
  - assegnarle a processori indipendenti  
  - distribuire input/output/dati  
  - coordinare accesso ai dati condivisi  

- Trade-off:
  - memoria condivisa → non serve distribuire i dati  
  - message passing → non serve gestire conflitti su memoria condivisa  

---

### Task Dependency Graph

- Un problema può essere rappresentato tramite un **Task Dependency Graph**

- Proprietà:
  - grafo diretto (archi orientati)
  - aciclico
  - nodi = task
  - archi = **dipendenze di controllo** (ordine di esecuzione, non necessariamente scambio dati)

![[Pasted image 20260406115219.png|500]]

- I nodi possono avere un peso:
  - tempo di esecuzione  
  - complessità  
  - numero di operazioni  

---

### Esempio 1: Moltiplicazione matrice-vettore

![[Pasted image 20260309155304.png|500]]

- Obiettivo: moltiplicare una matrice A per un vettore b → risultato c  

- Approccio sequenziale → lento  
- Approccio parallelo:
  - ogni riga della matrice è indipendente  
  - ogni riga → un task  

- I task sono **indipendenti**:
  → nessuno deve aspettare gli altri  

---

### Esempio 2: Query su tabella

![[Pasted image 20260309155503.png|500]]

- Una query può essere:
  - eseguita sequenzialmente  
  - oppure divisa in sotto-task  

- Esempio:
  - filtrare per diversi attributi in parallelo  
  - combinare i risultati (AND / OR)  
  - unire il risultato finale  

- Vantaggio:
  → si lavora su sottoinsiemi di dati → più efficiente  

![[Pasted image 20260309155555.png|500]]

---

### Decomposizione dei problemi

- Uno stesso problema può essere decomposto in molti modi diversi  
- Non esiste una decomposizione sempre migliore  

- Dipende da:
  - indipendenza tra task  
  - possibilità di riordinare operazioni  
  - risorse disponibili (CPU, macchine)  

![[Pasted image 20260309155623.png|500]]

- Esempio:
  - una riga per task  
  - più righe per task  
  - ogni operazione elementare su macchine diverse  

![[Pasted image 20260309155724.png|500]]

---

### Metriche per confrontare decomposizioni

Per valutare una decomposizione si usano tre metriche:

- **Granularity**
- **Degree of concurrency**
- **Critical path length**

---

##### Task Granularity

- **Granularità** = quanto è fine la suddivisione in task  
  → molti task piccoli = granularità fine  
  → pochi task grandi = granularità grossolana  

---

##### Degree of Concurrency

- Numero di task eseguibili in parallelo

- Due definizioni:
  - **massimo**: massimo numero di task in uno stesso livello del grafo  
  - **medio**: media dei task paralleli su tutti i livelli  

![[Pasted image 20260309160053.png]]

- Osservazione:
  → una buona decomposizione ha media ≈ massimo  
  → indica uso efficiente del parallelismo  

---

##### Critical Path

- Un **path** è una sequenza di task che devono essere eseguiti in ordine  

- Il **Critical Path** è il percorso più lungo nel grafo  

![[Pasted image 20260309160316.png|300]]

- Rappresenta:
  → il limite inferiore del tempo di esecuzione  

- Se i nodi hanno peso:
  → si sommano i pesi  

- Interpretazione:
  - anche con parallelismo infinito  
  - non si può andare più veloci del critical path  

- Nota importante:
  → per raggiungere questo tempo minimo servono abbastanza CPU  
  → se le CPU sono poche → esecuzione più lenta  

- Intuizione:
  → anche se alcune parti sono veloci, bisogna comunque aspettare i task dipendenti più lunghi  


### Parallel Performance Limitations 

- Esistono **limiti** alla decomposizione di un problema:
  - dipendono dalla natura del problema  
    (es. nella moltiplicazione di matrici si può arrivare fino a $n^2$ task)  
  - dipendono anche dall’hardware disponibile  

- Una suddivisione troppo fine (task molto piccoli):
  → aumenta l’overhead dovuto alla comunicazione tra task  

---

### Tasks Interaction Graph

- Il **Task Dependency Graph** rappresenta il *flusso di controllo*  
- Il **Tasks Interaction Graph** rappresenta invece il *flusso dei dati* tra task  

- Caratteristiche:
  - nodi = task  
  - archi = scambio di dati  
  - i nodi possono avere un peso (costo computazionale)  
  - gli archi possono avere un peso (quantità di dati scambiati)  

![[Pasted image 20260406121420.png|500]]

---

## MapReduce

- Esiste un’altra classe di problemi:
  → computazione semplice  
  → enorme quantità di dati  

- In questo caso:
  → si divide il **dato** (data decomposition), non la computazione  

![[Pasted image 20260309160839.png|300]]

- Si utilizza il paradigma **divide and conquer**:
  - dividere il problema in sotto-problemi  
  - risolverli separatamente  
  - combinare i risultati  

![[Pasted image 20260309160917.png|500]]

- Idea chiave:
  - stesso codice  
  - dati diversi (partizionati)  
  - risultati aggregati alla fine  

---

### Master-Slave Approach

- Una possibile implementazione:
  - partizionamento statico dei dati  
  - creazione dinamica di worker (slave)  
  - ogni worker elabora una porzione di dati  

- Limite:
  → non funziona bene con carichi sbilanciati  

![[Pasted image 20260309161103.png]]

---

### Pipeline tipica Big Data

1. iterazione su grandi quantità di dati  
2. estrazione di informazioni rilevanti  
3. shuffle e sort dei risultati intermedi  
4. aggregazione finale  

---

### Problemi nella data decomposition

- come dividere i dati?  
- come distribuirli tra le macchine?  
- come aggregare i risultati intermedi?  

---

### MapReduce (modello)

- Il **MapReduce programming model** fornisce una soluzione a questi problemi  

- È:
  - un **modello concettuale** (come strutturare il problema)  
  - un **framework** (infrastruttura che esegue il codice)  

---

### I tre pilastri di MapReduce

#### 1. Right Level of Abstraction
- Il framework gestisce molte complessità  
- Lo sviluppatore deve rispettare alcune regole  
- Limitazioni:
  → non tutti i tipi di applicazioni sono facilmente esprimibili  
  → codice generalmente semplice e compatto  

---

#### 2. Scale Out (non Scale Up)

- Due strategie:
  - poche macchine molto potenti  
  - molte macchine economiche (commodity hardware)  

- Approccio preferito:
  → **scale out** (molte macchine economiche)

- Conseguenza:
  → aumento dei guasti  

- Soluzione:
  → **fault tolerance** gestita dal framework  

---

#### 3. Moving Computation to Data

- Conviene:
  → spostare il codice dove si trovano i dati  

- Non conviene:
  → spostare grandi quantità di dati verso il codice  

---

## Principi di Programmazione Funzionale (MapReduce)

- MapReduce si basa su concetti della **programmazione funzionale**

- Tre principi fondamentali:
  - **Purity**
  - **Immutability**
  - **Higher-order functions**

---

##### Purity

- Una funzione è **pura** se:
  → dato lo stesso input → produce sempre lo stesso output  

- Proprietà:
  → comportamento deterministico (*idempotenza*)  

- Esempi:
  - somma → pura  
  - funzione che restituisce l’ora → non pura  

![[Pasted image 20260309161851.png]]

---

##### Immutability

- Non esistono vere variabili modificabili  
  → i dati sono trattati come **costanti**

- Modifica dei dati:
  → si crea una copia e si lavora su quella  

- Vantaggi:
  - riduzione delle dipendenze tra task  
  - eliminazione di conflitti concorrenti  
  - tracciabilità completa dei dati (history preservation)  

- Motivazione pratica:
  - mantenere dati originali  
  - poter rieseguire computazioni in caso di errore  

![[Pasted image 20260309162101.png]]

---

##### Higher-order Functions

- **Funzioni di ordine superiore**:
  → prendono funzioni come input  
  → oppure restituiscono funzioni come output

- Utilità in MapReduce:
  - maggiore espressività  
  - codice più modulare  
  - maggiore chiarezza  


# 02 MapReduce Programming Model

- MapReduce è un **modello di programmazione**  
  → definisce come lo sviluppatore deve strutturare il codice per risolvere problemi Big Data  

- Il programmatore deve definire **due funzioni**:

  - **Mapper**  
    → input: coppie [key, value]  
    → output: zero o più coppie [key, value]  

  - **Reducer**  
    → input: [key, lista di valori]  
    → output: zero o più coppie [key, value]  

- Entrambe le funzioni sono **stateless**  
  → ogni esecuzione è indipendente  
  → non viene mantenuto alcuno stato tra invocazioni  

---

### MapReduce Application

- Processo generale:
  1. input grande → suddiviso in blocchi  
  2. ogni blocco → processato da un mapper  
  3. output mapper → fase di *shuffle & sort*  
  4. dati → inviati ai reducer  
  5. output reducer → aggregato finale  

![[Pasted image 20260406123252.png]]

---

### More on Mappers

- I mapper dovrebbero essere eseguiti **sui nodi che contengono i dati**  
  → riduzione del traffico di rete  

- Più mapper lavorano in parallelo  
  → ciascuno su una porzione dei dati  

- Il mapper:
  - spesso ignora la key di input  
  - lavora principalmente sul value  

  Nota:
  - a volte la key è irrilevante (es. offset del testo)  
  - altre volte è utile  

---

### More on Reducers

- I reducer iniziano **solo quando tutti i mapper hanno finito**

- Possono esserci:
  - uno o più reducer  

- Proprietà fondamentale:
  → tutti i valori associati a una stessa key vengono inviati allo **stesso reducer**

- Le key non sono uniche:
  → più mapper possono produrre la stessa key  

- Output:
  → coppie finali [key, value]  
  → salvate nel file system distribuito  

---

### WordCount Example

![[Pasted image 20260406123810.png|500]]

![[Pasted image 20260406123836.png|400]]

- Input: grande testo  

- Processo:
  1. suddivisione in blocchi  
  2. ogni blocco → mapper  
  3. mapper emette:
     - key = parola  
     - value = numero di occorrenze nel blocco  

  4. **Shuffle**:
     → raggruppa per key → [key, lista valori]  

  5. **Reducer**:
     → somma i valori per ogni key  

  6. aggregazione finale  

---

### Shuffle, Sort, Partition

- **Shuffling**  
  → raggruppa i dati per key  

- **Sorting**  
  → ordina le key (es. ordine alfabetico)  
  → garantisce comportamento deterministico  

- **Partitioning**  
  → assegna le key ai reducer  

---

##### Cascade Tasks

- È possibile concatenare più job MapReduce  

- Esempio:
  - primo job → numero totale di parole  
  - secondo job → frequenza relativa  

---

### Image Data Example

![[Pasted image 20260406124532.png]]

- Problema:
  → immagini della stessa area (Pisa) con:
  - formati diversi  
  - risoluzioni diverse  
  - timestamp diversi  

- Strategia:
  - suddividere l’area in **tile**  
  - ogni immagine → divisa nei tile corrispondenti  
  - per ogni tile:
    → scegliere immagine migliore (es. più recente o alta risoluzione)  

![[Pasted image 20260406124631.png]]

- Comportamento del mapper:
  - processa una porzione di dati (es. 100 immagini)  
  - applica la funzione map a ogni elemento  

- Analogamente:
  → nel word count → una riga alla volta  

---

### Partitioners

- **Partitioning**:
  → suddividere lo spazio delle key tra i reducer  

- Esiste un **partitioner di default**:
  - usa solo la key  
  - ignora i valori  

- Problema:
  → possibile squilibrio (alcune key con molti valori)

- Soluzione:
  → partitioner custom che considera anche i valori  

![[Pasted image 20260406124815.png]]

---

### Combiners

- Il **combiner** è opzionale  
  → ottimizzazione  

- Problema:
  → output mapper può essere molto grande  

- Soluzione:
  → aggregazione locale prima dello shuffle  

- Proprietà:
  - simile a un reducer  
  - lavora solo sull’output di un singolo mapper  

- Vantaggio:
  → meno dati trasferiti in rete  

![[Pasted image 20260406124901.png]]

---

### MapReduce Application (Schema completo)

![[Pasted image 20260406124934.png]]

- Origine:
  - MapReduce → Google  
  - Hadoop → implementazione open source (Yahoo)  
  - Spark → evoluzione con paradigma simile  

---

## Hadoop 

### Hadoop Terminology

- Un **MapReduce job** è composto da:
  - dati di input  
  - programma MapReduce  
  - configurazione  

- Hadoop esegue il job suddividendolo in:
  - **map tasks**
  - **reduce tasks**

- Scheduling:
  → gestito da **YARN (Yet Another Resource Negotiator)**  

- Fault tolerance:
  → task falliti vengono rieseguiti automaticamente  

- Input:
  → diviso in **input split** (blocchi di dati)  

- Ogni split:
  → associato a un map task  

---

### Hadoop Program Execution

- Debug:
  → non avviene tipicamente su IDE  
  → ma sull’ambiente Hadoop  

- Esecuzione:
  - compilazione  
  - packaging in JAR  
  - invio al cluster  

- È necessario specificare:
  - posizione di **HDFS**  
  - posizione dei **daemon Hadoop**  

---

### Modalità di esecuzione

- **Local mode (standalone)**  
  - singolo processo Java  
  - no daemon  
  - usa file system locale  
  - 1 mapper + 1 reducer  
  - utile per debug  

- **Pseudo-distributed mode**  
  - più JVM su una singola macchina  
  - simula un cluster  
  - usa HDFS  
  - più mapper e reducer  

- **Fully-distributed mode**  
  - cluster reale  
  - daemon distribuiti  
  - pieno utilizzo HDFS  
  - scalabilità completa  

---

### WordCount in Hadoop (concetto)

- Componenti necessari:
  - mapper  
  - reducer  
  - configurazione  

- Logica:
  - mapper → produce (parola, 1)  
  - reducer → somma i valori per parola  

- Nota:
  → il codice implementa esattamente il modello MapReduce visto teoricamente  

### Hadoop Types

![[Pasted image 20260406142926.png]]

- Se viene usato un **combiner**:
  → deve avere la stessa forma del reducer  
  → è una versione locale del reducer  

- Tipi:
  - input mapper → (K1, V1)  
  - output mapper / input reducer → (K2, V2)  
  - output reducer → (K3, V3)  

- Caso comune:
  → combiner = reducer  
  → quindi K3 = K2 e V3 = V2  

- **Partition function**:
  - lavora su (K2, V2)  
  - restituisce l’indice della partizione  
  - in pratica usa solo la **key** (ignora il value)  

---

### Hadoop Configuration

- Il **configuration file** (driver code) è il file principale dell’applicazione  

- Funzioni:
  - crea un oggetto `Configuration`  
  - parsifica gli argomenti (input, output, parametri)  
  - li salva in `otherArgs`  

- Permette di specificare:
  - path di input  
  - path di output  
  - numero di reducer  
  - classi di mapper, reducer, combiner  

- Il driver può essere separato dall’eseguibile principale  
  → in questo caso bisogna specificare esplicitamente le classi  

---

#### Uso del Combiner

- Non sempre utilizzabile  

- Condizione necessaria:
  → operazione **associativa e commutativa**  

- Motivo:
  → il combiner esegue una pre-aggregazione locale  

- Se la proprietà non vale:
  → aggregazione solo nel reducer  

---

#### Tipi

- Devono essere specificati:
  - tipi di output del reducer (K3, V3)  
  - eventualmente tipi intermedi del mapper (K2, V2)  

- Se si usano:
  - custom sort  
  - custom partition  
  - custom shuffle  
  → devono essere dichiarati nella configurazione  

---

#### Input / Output Path

- Input:
  - più path possibili  
  - possono essere:
    - file  
    - directory  
    - pattern (regex)  

- Output:
  - un solo path  
  - deve essere una directory  
  - contiene un file per ogni reducer  

- Vincolo importante:
  → la directory di output **non deve esistere**

- Strategie:
  - cancellare directory → ❌ (viola immutabilità)  
  - creare directory con suffisso incrementale → ✔️  

---

#### Esecuzione

- L’ultima istruzione:
  → avvia il job  
  → attende il completamento  

- Possibilità:
  → output verbose o meno  

---

### Hadoop Job Configuration (Tipi)

![[Pasted image 20260406143249.png]]

- I tipi tra input, mapper e reducer possono:
  - coincidere  
  - oppure essere diversi  

- I tipi di input sono definiti dalla **InputFormat**

- Esempio:
  → `TextInputFormat` per file di testo  

---

#### Numero di Task

- Reducer:
  → configurabile  

- Mapper:
  → NON configurabile direttamente  
  → dipende dagli **input split**  

---

### Serialization (Writable)

- **Serialization**:
  → conversione di oggetti in sequenze di byte  

- Serve per:
  - scrittura su disco  
  - trasferimento in rete  

- Hadoop usa un formato proprio:
  → **Writable**

- Writable:
  - `write`  
  - `readFields`  
  - `WritableComparable` (per confronto)  

- Esistono wrapper:
  → per tutti i tipi primitivi Java  

---

### InputSplit

- **InputSplit**:
  → porzione logica dei dati  

- Proprietà:
  - NON è una partizione fisica  
  - può attraversare file diversi  

- È:
  → un riferimento ai dati (tipo puntatore)  
  → contiene:
    - posizione iniziale  
    - lunghezza  

- Strategia:
  → split più grandi assegnati prima  
  → per bilanciare i tempi di esecuzione  

---

### Funzioni interne Hadoop

- `getSplit`  
  → determina il numero di split  

- `createRecordReader`  
  → crea un iteratore sui dati  
  → usato dal mapper per leggere input (es. riga per riga)  

- Queste funzioni:
  → sono gestite automaticamente da Hadoop  

---

### Lifecycle Mapper

- `setup`  
  → eseguito prima della prima chiamata a `map`  
  → inizializzazione parametri  

- `cleanup`  
  → eseguito dopo l’ultima chiamata  
  → rilascio risorse / output finale  

---

### Tipi e Configurazione

- Input types:
  → definiti dall’InputFormat  

- Altri tipi:
  → definiti esplicitamente nel job  

- Default:
  - key → `LongWritable`  
  - value → `Text`  

- Se non specificati:
  → tipi intermedi = tipi finali  

---

#### Ottimizzazioni

- Se:
  - K2 = K3 → non serve `setMapOutputKeyClass()`  
  - V2 = V3 → basta `setOutputValueClass()`  

- Attenzione:
  → errori di tipo NON rilevati a compile time  

---

### Context

- **context**:
  → oggetto usato dal mapper (e reducer)  

- Serve per:
  → emettere coppie (key, value)  

---

### Hadoop Configuration Defaults

- Configurazione minima:
  → input path + output path  

- Default:

  - InputFormat → `TextInputFormat`  
  - Input:
    - key → `LongWritable`  
    - value → `Text`  

  - Mapper:
    → identità (passa input → output invariato)  

  - Reducer:
    → identità (scrive input senza modificarlo)  

  - Partitioner:
    → `HashPartitioner`  
    → usa hash della key  

- Partizioni:
  → una per reducer  

- Default:
  → 1 reducer → 1 partizione  

- Numero mapper:
  → uguale al numero di input split  
  → dipende da:
    - dimensione dati  
    - block size HDFS  


# 03 Hadoop

### Serialization in Hadoop

- **Serialization**: processo di conversione di oggetti in uno stream di byte  
- **Deserialization**: processo inverso (byte → oggetti)  

- Utilizzi:
  - comunicazione tra processi  
  - memorizzazione persistente  

- In Hadoop:
  - la comunicazione tra nodi avviene tramite **RPC (Remote Procedure Calls)**  
  - RPC utilizza serialization/deserialization  

- Hadoop usa un formato proprio:
  → **Writables**
  - compatto  
  - veloce  
  - meno flessibile (soprattutto fuori da Java)  

- Altri formati supportati:
  - Avro  
  - Thrift  
  - Protocol Buffers  

---

### Writable Interfaces

    public interface Writable {
        void write(DataOutput out) throws IOException;
        void readFields(DataInput in) throws IOException;
    }

    public interface WritableComparable<T> 
            extends Writable, Comparable<T> {
    }

- **Writable**:
  → definisce serializzazione/deserializzazione  

- **WritableComparable**:
  → aggiunge confronto (necessario per sort/shuffle)  

---

### IntWritable (idea)

- Wrapper per `int`  

- Implementa:
  - read/write  
  - equals  
  - hashCode  
  - compareTo  

- Serve perché Hadoop non usa tipi primitivi Java  

---

### Writable Wrappers

![[Pasted image 20260417174046.png]]

---

### Writable Class Hierarchy

![[Pasted image 20260417174135.png]]

---

## Hadoop Input (I)

- **InputSplit**:
  → porzione di input per un mapper  

- Ogni split:
  - contiene record  
  - ogni record = (key, value)  

---

### Splits e Records

- Sono **logici**:
  - non necessariamente file reali  
  - possono rappresentare:
    - righe DB  
    - porzioni file  

- Proprietà:
  - lunghezza  
  - posizione (nodi)  

---

### Importante

- Lo split:
  → NON contiene dati  
  → è un riferimento  

- Serve per:
  - località dei dati  
  - ottimizzazione  

---

### InputFormat

    public abstract class InputFormat<K, V> {
        public abstract List<InputSplit> getSplits(JobContext context);
        public abstract RecordReader<K, V> 
            createRecordReader(InputSplit split, TaskAttemptContext context);
    }

- `getSplits()` → crea split  
- `createRecordReader()` → crea reader  

---

### RecordReader

- Iteratore su (key, value)  
- Usato dal mapper per leggere input  

---

### Scheduling

- Split → Application Master  
- Task assegnati vicino ai dati  

---

### InputFormat Class Hierarchy

![[Pasted image 20260417174817.png|300]]

---

### OutputFormat Class Hierarchy

![[Pasted image 20260417174838.png|300]]

---

### setup() e cleanup()

- **setup()**:
  → prima di map/reduce  

    public void setup(Context context)

- **cleanup()**:
  → dopo l’ultima esecuzione  

    public void cleanup(Context context)

---

### Passing Parameters
	
	    Configuration conf = new Configuration();
	    conf.setInt("paramname", value);

- Lettura nel mapper:

	    Configuration conf = context.getConfiguration();
	    int myParam = conf.getInt("paramname", 0);

---


## Hadoop Distributed File System

### Requirements / Features for a DFS
- È un **file system distribuito**  
- Gestisce lo storage su una rete di macchine (cluster)  
- Progettato per hardware economico (commodity hardware)  
- **Alta tolleranza ai guasti**  

---

### Organization of a DFS

- I file sono divisi in **blocchi (chunks)**:
  → tipicamente 64 / 128 MB  

- I blocchi:
  → sono **replicati** su più nodi (≈ 3 copie o piu')  

- Le repliche:
  → distribuite su rack diversi (ridondanza fisica)  

- Configurabile:
  - dimensione blocchi  
  - grado di replica  

- Nodo speciale:
  → **master (NameNode)**  
  → mantiene posizione dei blocchi  

- Il master stesso:
  → può essere replicato  

---

### Blocks

- **File system tradizionale**:
  - blocchi piccoli (KB)  
  - blocchi disco ≈ 512 byte  

- **DFS (HDFS)**:
  - blocchi grandi (64/128 MB)  
  → riduce overhead di seek  

- Proprietà:
  - file piccoli NON occupano tutto il blocco  
  - file possono superare dimensione disco singolo  

- Il blocco:
  → unità base di astrazione  

---

### Namenodes & Datanodes

- Architettura **master/slave**

#### Namenode (master)

- Gestisce:
  - struttura filesystem  
  - metadati  
  - mapping file → blocchi  
  - posizione blocchi  
  - permessi  

- “Conosce tutto” sullo storage  

---

#### Datanodes (slave)

- Memorizzano i dati reali  

- Funzioni:
  - lettura/scrittura  
  - creazione/eliminazione blocchi  
  - replica blocchi  

- Comunicazione:
  → inviano **heartbeat** al Namenode  

---

- Problema:
  → fallimento del Namenode = sistema inutilizzabile  

- Soluzione:
  → meccanismi di fault tolerance  

---

### HDFS Architecture (scrittura)

- Processo:

1. Client → richiesta al Namenode  
2. Namenode → verifica permessi  
3. Namenode → decide posizione blocchi  
4. Client → scrive sui Datanode  
5. Replica automatica tra Datanode  

- Nota:
  → la replica NON è gestita dal Namenode  

---

### Esempio scrittura

![[Pasted image 20260417175753.png|300]]![[Pasted image 20260417175759.png|300]]
![[Pasted image 20260417175804.png|300]]
![[Pasted image 20260417175809.png|300]]
![[Pasted image 20260417175814.png|300]]
![[Pasted image 20260417175819.png]]
![[Pasted image 20260417175824.png]]
![[Pasted image 20260417175829.png]]

---

### Anatomy of a Read

- Processo di lettura:

1. Client → richiesta apertura file  
2. DFS → chiede al Namenode la posizione dei blocchi  
3. Namenode → restituisce lista ordinata (per prossimità)  
4. DFS → passa info al client  
5. Client → legge tramite stream (astrazione, non vede i blocchi)  
6. DFS → legge dai Datanode più vicini  
7. Client → chiude stream  

- Tutto questo è **automatico in HDFS**  

![[Pasted image 20260417175921.png]]

---

### Network Topology and Hadoop

- Hadoop modella la rete come un **albero**

- Distanza tra nodi:
  → numero di archi nel percorso verso antenato comune  

- Livelli:
  - stesso nodo  
  - stesso rack  
  - stesso datacenter  
  - datacenter diverso  

- Obiettivo:
  → minimizzare traffico di rete  

![[Pasted image 20260417175956.png]]

---

### Anatomy of a Write

- Processo:

1. Client → richiesta creazione file  
2. DFS → inoltra al Namenode  
3. Namenode → decide blocchi e replica (es. 3 copie)  
4. Client → invia dati al primo Datanode  
5. Datanode → replica a catena (pipeline)  
6. Operazione ripetuta per ogni blocco  
7. Fine → conferma al Namenode  

![[Pasted image 20260417180009.png]]

---

### Replication Strategy

- Scelta dei Datanode:

1. Prima replica:
   → stesso nodo del client  

2. Seconda replica:
   → rack diverso  

3. Terza replica:
   → stesso rack della seconda, nodo diverso  

4. Repliche aggiuntive:
   → nodi casuali  

- Obiettivo:
  → evitare concentrazione su stesso nodo/rack  

---



## Hadoop Distributed Resource Management

### Resource management in Hadoop versions

- In un cluster abbiamo molte macchine con:
  → CPU  
  → memoria  

- Problema:
  → come allocare queste risorse per eseguire task MapReduce  

- Hadoop 1:
  → gestione risorse integrata nel framework MapReduce  
  → molti problemi (scalabilità, bottleneck)  

- Hadoop moderno:
  → introduzione di **YARN** per la gestione delle risorse  

![[Pasted image 20260417180053.png]]

---

### Hadoop 1.0

- **Job**  
  → lavoro completo richiesto dal client  

- **Task**  
  → unità eseguibile (map o reduce)  

- **Slot**  
  → unità di risorsa per task  

  Problemi degli slot:
  - dimensione fissa (non adattiva)  
  - possono essere troppo grandi o troppo piccoli  
  - separati per tipo:
    - slot map  
    - slot reduce  
  → non intercambiabili (inefficienza)  

---

### Componenti

- **JobTracker (master)**  
  - riceve job  
  - crea task  
  - assegna task ai nodi  
  - monitora esecuzione  
  - gestisce fault  

- **TaskTracker (slave)**  
  - esegue task  
  - gestisce output intermedi  
  - invia stato al JobTracker  

---

### Problema principale

- Il JobTracker:
  → gestisce tutto (allocazione + monitoraggio)  

- Conseguenza:
  → **bottleneck**  
  → sistema non scalabile  

![[Pasted image 20260417180115.png]]

---

### Hadoop 1.0 Limitations

- **Scalabilità**
  - limite ≈ 4.000 nodi / 40.000 task  
  - tutto gestito dal JobTracker  

- **Availability**
  - JobTracker = single point of failure  
  - fallimento → tutti i job persi  

- **Resource Utilization**
  - slot rigidi → spreco risorse  
  - impossibilità di riutilizzare slot inutilizzati  

- Nota importante:
  → il problema principale è il **bottleneck**, non il failure  

---

### YARN Components

- YARN separa le responsabilità  

---

#### Resource Manager

- Uno per cluster  
- Funzione:
  → allocazione globale risorse  

- È il “master”  

---

#### Node Manager

- Uno per nodo  
- Funzioni:
  - esegue task  
  - monitora risorse  
  - invia statistiche  

- È il “slave”  

---

### Container

- Un **container**:
  → unità di risorse (CPU + memoria)  

- Caratteristiche:
  - dimensione dinamica  
  - NON legato a map/reduce  
  - riutilizzabile per diversi task  

---

### Resource Request

- Una richiesta di risorse specifica:
  - quantità di CPU/memoria  
  - vincoli di località  

- Locality:
  → eseguire il task vicino ai dati  

- Se non soddisfatta:
  - attesa  
  - oppure rilassamento vincolo  
    (es. stesso rack invece stesso nodo)  

---

### Differenze chiave con Hadoop 1

- Niente più slot rigidi  
- Risorse dinamiche (container)  
- Separazione:
  - Resource Manager → allocazione  
  - Application Master → monitoraggio  

---

### Vantaggi YARN

- Migliore utilizzo risorse  
- Maggiore scalabilità  
- Riduzione bottleneck  
- Maggiore flessibilità  

- Sistema:
  → più modulare e più efficiente  


# 04 YARN

### YARN Scheduling

- **Scheduling**:
  → decide dove eseguire i task  

- Problema:
  → risorse limitate nel cluster  

- Non esiste una politica “migliore” universale  

- **YARN** offre diversi scheduler:
  → ciascuno basato su politiche diverse  

---

### FIFO Scheduler

- Un’unica coda  
- Esecuzione:
  → ordine di arrivo (*First In First Out*)  

- Funzionamento:
  - prima applicazione → usa tutte le risorse  
  - solo dopo → passa alla successiva  

- Vantaggi:
  - semplice  
  - nessuna configurazione  

- Svantaggi:
  - non adatto a cluster condivisi  
  - job grandi bloccano tutti gli altri  
  → **starvation**  

![[Pasted image 20260418163217.png|300]]

---

### Capacity Scheduler

- Più **code separate**  
- Ogni coda:
  → associata a un’organizzazione  

- Ogni coda:
  → ha una quota di risorse garantita  

- All’interno della coda:
  → scheduling FIFO  

- Svantaggi:
  - possibile **underutilization**  
  → risorse inutilizzate in una coda non sono facilmente riutilizzabili  

![[Pasted image 20260418163337.png|300]]

---

### Fair Scheduler

- Distribuzione dinamica delle risorse  

- Proprietà:
  - nessuna quota fissa  
  - bilanciamento automatico tra job  

- Esempio:
  - 1 job → usa tutto  
  - 2 job → 50% ciascuno  
  - 3 job → ~33% ciascuno  

- *La pianificazione equa è per utente*: se l'utente A invia due lavori e l'utente B solo uno, allora il lavoro di A riceve il 25% delle risorse mentre il lavoro di B riceve il 50%.
![[Pasted image 20260418163455.png|300]]

---

### Delay Scheduling

- Non è uno scheduler separato  
- È una **strategia** usata da:
  - Capacity Scheduler  
  - Fair Scheduler  

---

#### Problema

- Si vuole eseguire il task:
  → sul nodo dove risiedono i dati  

- Ma:
  → il nodo può essere occupato  

---

#### Soluzione

- Attendere un breve tempo  
  → aumenta probabilità di locality  

- Questo approccio:
  → migliora efficienza  

---

#### Meccanismo

- I NodeManager inviano **heartbeat** al ResourceManager  
  → indicano:
  - risorse disponibili  
  - stato dei container  

- Ogni heartbeat:
  → opportunità di scheduling  

- Delay scheduling:
  → non usa subito la prima opportunità  
  → aspetta alcune opportunità prima di rilassare il vincolo  

---

### Anatomy of a MapReduce Application Run
---

#### Flusso di esecuzione

1. Avvio programma (main)  
2. Invio job al cluster  
3. ResourceManager assegna un ID  a ogni job
4. Il job salva informazioni su HDFS  
5. Invio applicazione al ResourceManager  
6. Il RM fa il deployment su nodo → Application Master  
7. Application Master:
   - richiede dati da HDFS  
   - monitora esecuzione  
   - coordina ResourceManager e node manager

8. ResourceManager:
   → assegna risorse  

9. NodeManager:
   → esegue task  

10. Avvio JVM → esecuzione Map/Reduce  

- Componenti:
  - **Hadoop (blu)** → infrastruttura  
  - **Developer (arancione)** → codice  

![[Pasted image 20260418163704.png|300]] 

---

#### Nota (Uber mode)

- Alcuni job possono essere eseguiti interamente nell’Application Master  

- Questo è chiamato:
  → **Uber mode**  

- Usato solo per job piccoli  
- Non è comportamento standard  

### Fault Tolerance

- Nei sistemi distribuiti:
  → molti componenti possono fallire in qualsiasi momento  

---

### Task Failure

- Possibili cause:

#### 1. Eccezione nel codice (map/reduce)
- La JVM del task:
  → segnala errore all’Application Master  
- L’Application Master:
  - marca il task come fallito  
  - libera il container  

---

#### 2. Terminazione improvvisa JVM
- Il NodeManager:
  → notifica l’Application Master  

- L’Application Master:
  - marca il task come fallito  
  - libera il container  

---

#### 3. Task bloccati (hanging)
- L’Application Master:
  → non riceve progress update  

- Dopo timeout (~10 min):
  → task terminato automaticamente  

- L’Application Master:
  → marca il task come fallito  

---

### Recovery

- Dopo un fallimento:
  → il task viene **rieseguito**  

- Strategia:
  → evitare nodi dove è già fallito  

---

### Application Master Failure

- L’Application Master:
  → invia heartbeat al Resource Manager  

- Se fallisce:
  - Resource Manager rileva il problema  
  - avvia un nuovo Application Master  
  - il client ottiene il nuovo indirizzo  

- Trasparente per l’utente  

- Limite:
  → se fallisce 2 volte → job fallisce  

---

### Node Manager Failure

- NodeManager:
  → invia heartbeat al Resource Manager  

- Se assente (~10 min):
  → considerato fallito  

- Azioni:
  - rimosso dal pool  
  - task su quel nodo → falliti  
  - recovery tramite ri-esecuzione  

- Possibile:
  → **blacklisting** (evitare nodo problematico)  
  → deciso dall’Application Master  

---

### Resource Manager Failure

- Caso più critico  

- Senza Resource Manager:
  → impossibile avviare job o task  

- Default:
  → single point of failure  

---

#### Soluzione: High Availability

- Due Resource Manager:
  - **active**
  - **standby**

- Stato:
  → salvato in storage altamente disponibile  

- Failover:
  - standby diventa active  
  - gestito da failover controller  

- Meccanismo:
  → leader election (un solo attivo)  

- Client/NodeManager:
  → provano connessione a RM multipli (round-robin)  

---

## Speculative Execution

- Problema:
  → **stragglers** (task molto lenti)  

- Cause:
  - hardware lento  
  - problemi software  

---

### Soluzione

- **Speculative execution**:

- L’Application Master:
  - monitora progresso task  
  - individua quelli lenti  

- Azione:
  → lancia copie speculative  

- Risultato:
  - task che finisce prima → valido  
  - altro → terminato  

---

- Costo:
  → leggero aumento uso risorse  

---

## Shuffle and Sort

- Processo intermedio tra map e reduce  

---

### Lato Mapper

- Output mapper:
  → buffer in memoria  

- Quando buffer ≈ 80%:
  → scrittura su disco locale  
  → file chiamato **spill file**  

- Ogni spill file:
  - partizionato (per reducer)  
  - ordinato per key  
  - possibile combinazione (combiner)  

---

- Spill multipli:
  → vengono **mergiati**  

---

### Lato Reducer

- I reducer:
  → ricevono dati dai mapper  

- Trigger:
  → tramite heartbeat  

- I dati:
  → copiati in locale (memoria + disco)  

- Operazioni:
  - merge dati da mapper diversi  
  - ordinamento finale  

---

### Output finale

- Reducer:
  → produce risultato  

- Output:
  → salvato su **HDFS**  

---

![[Pasted image 20260418163728.png]]

# 05 Spark

### Hadoop vs Spark

![[Pasted image 20260418174317.png]]

---

### Limitations of MapReduce

- MapReduce è molto efficiente per:
  → computazioni **one-pass**  

- Limiti:

  - inefficiente per algoritmi **multi-pass**  
  - nessun supporto efficiente per **data sharing**  

- Problema dello stato:
  - tra step → salvato su HDFS  
  - durante shuffle → salvato su disco locale  

- Bottleneck principale:
  → **I/O e comunicazione**  

---

### Spark Stack

![[Pasted image 20260419155244.png]]

---

## Spark Core

- **Spark Core** fornisce:
  - scheduler **DAG**  
  - interazione con HDFS e YARN  
  - gestione memoria (cache, shuffle)  
  - supporto a **RDD**  

---

### RDD (Resilient Distributed Dataset)

- Collezione distribuita:
  → dati su più nodi  

- Proprietà:
  - elaborazione parallela  
  - resilienza ai guasti  
  - **immutabile**  

- È una **astrazione in memoria**  

![[Pasted image 20260419155544.png]]

---

### Partitions

- Un RDD è diviso in **partizioni**  
  → unità atomiche di dati  

- Le partizioni:
  → distribuite su nodi diversi  

![[Pasted image 20260419155553.png]]

---

### Lineage

- Gli RDD tracciano il **lineage**  
  → sequenza di operazioni  

- Serve per:
  → ricostruire dati persi  

![[Pasted image 20260419155646.png]]
![[Pasted image 20260419155658.png]]
![[Pasted image 20260419155710.png]]
![[Pasted image 20260419155714.png]]

---

## Spark Architecture

![[Pasted image 20260419155735.png]]

---

### Spark Applications Architecture

- Un’applicazione Spark è composta da:
  - Un **Driver process**  
  - Un insieme di **Executor processes**  

![[Pasted image 20260419155808.png|500]]

---

### Spark Driver

- È il **cuore** dell’applicazione  

- Funzioni:
	1. *Mantenere le informazioni* sull'applicazione Spark
	2. *Interagire* con l'utente
	3. *Analizzare, distribuire e pianificare* il lavoro tra gli executor

---

### Spark Executors

- Funzioni:
  1. eseguire codice assegnatogli dal driver
  2. riportare stato della computazione al driver  

---

### Spark Context

- Il driver contiene:
  - **SparkContext**  
  - codice utente  

![[Pasted image 20260419160058.png]]

- **SparkContext**:
  → connessione al cluster  

- In PySpark:
  - creato automaticamente  
  - accessibile come `sc`  

---

### Submit e modalità di esecuzione

- Uso di **spark-submit** (usato per eseguire Spark Jobs), supporta le seguenti modalita' di esecuzione

- Flag `--master`:
  - `local` → 1 core  
  - `local[N]` → N core  
  - `local[*]` → tutti i core  
  - `yarn` → cluster  

---

### Deploy Mode

- Flag `--deploy-mode`, specifica come lo spark driver dovrebbe essere eseguito: 

- **client**
  - driver locale  
  - se termina → job fallisce  

- **cluster**
  - driver nel cluster  
  - più robusto  

---

## Creazione RDD

- Da collezioni locali:
  → `parallelize()`  

- Da storage esterno:
  → `textFile()`  

- Numero partizioni:
  → può essere suggerito  

---

## Spark Programming Model

- Basato su:
  → **operatori parallelizzabili**  

- Usa:
  → funzioni di ordine superiore che eseguono funzioni definiti dall'utente in parallelo

- Struttura rappresentabile da:
  → **DAG (Directed Acyclic Graph)**  

![[Pasted image 20260419161506.png]]

---

## RDD Operations

### 1. Transformations

- Creano nuovi RDD  

- Proprietà:
  → **lazy evaluation** (non vengono eseguiti subito) 
  → sono eseguiti solo quando un risultato deve essere inviato al programma driver

---

### 2. Actions

- Attivano la computazione  

- Istruisce Spark a calcolare un risultato da una serie di trasformazioni.
- Esistono tre tipi di azioni:
	- Azioni per *visualizzare i dati* nella console
	- Azioni per *raccogliere i dati* in oggetti nativi nel rispettivo linguaggio
	- Azioni per *scrivere nei sink di dati di output*
---

## RDD Actions principali

- **collect()**
  → restituisce tutti gli elementi del RDD come un array al driver 

- **first()**
  → restituisce il primo elemento del RDD

- **take(n)**
  → primi n elementi del RDD

- **count()**
  → numero elementi  

- **max() / min()**
  → valore massimo / minimo  

- **reduce(func)**
  → aggregazione degli elementi usando una funzione data
  → per avere una computazione parallela la funzione deve essere:
    - associativa  
    - commutativa  

- **saveAsTextFile(path)**
  → scrittura su file (uno per partizione)  

---

### Nota importante

- A differenza di MapReduce:
  → Spark lavora principalmente **in memoria**  

- Conseguenza:
  → molto più veloce per:
  - iterazioni  
  - algoritmi complessi  


### Generic RDD Transformations

- **distinct()**  
  → rimuove duplicati da RDD

- **filter(f)**  
  → mantiene solo elementi che soddisfano una funzione predicato  

---

- **map(f)**  
  → applica funzione a ogni elemento  
  → output: stesso numero di elementi  

- **flatMap(f)**  
  → può restituire 0, 1 o più elementi per elemento
  → output: dimensione variabile  

- Differenza chiave:
  - map → 1 input → 1 output  
  - flatMap → 1 input → N output  

---

- **sortBy(f)**  
  → ordina RDD secondo funzione  

- **union()**  
  → unione (non elimina duplicati)  

- **intersection()**  
  → intersezione insiemistica  

---

### Key-Value RDD Transformations

- Struttura:
  → $(k, v)$  

- Metodi di reazione di un key-value RDD:

  - tramite **map**  
    → trasformazione esplicita  

  - tramite **keyBy(f)**  
    → genera key da value  

  - tramite **zip()**  
    → unisce due RDD (stessa lunghezza)  

---

- **keys() / values()**  
  → estraggono rispettivamente chiavi e valori  

---

- **reduceByKey(f)**  
  → aggrega valori con stessa chiave  

  - funzione deve essere:
    → associativa  
    → commutativa  

---

- **sortByKey()**  
  → ordina per chiave  

---

- **join()**  
  → inner join su chiavi  

- Varianti:
  - fullOuterJoin  
  - leftOuterJoin  
  - rightOuterJoin  
  - cartesian  

---

## Anatomy of a Spark Job

- Spark usa **lazy evaluation**  

- Un’applicazione:
  → non esegue nulla finché non viene chiamata una **action**  

- Ogni action:
  → genera un **job**  

![[Pasted image 20260419161819.png|400]]

---

## Spark Stage

- Un job è diviso in **stages**  

- Uno stage:
  → gruppo di task eseguibili insieme  

---

### Tipi di trasformazioni

- **Narrow transformations**
  → operano su singola partizione  
  → NO shuffle  

  Esempi:
  - map  
  - filter  

---

- **Wide transformations**
  → richiedono shuffle  
  → dipendono da più partizioni  

  Esempi:
  - reduceByKey  
  - join  

- Le wide transformations:
  → determinano i confini tra stage  

---

## Spark Task

- Uno stage è composto da **task**  

- Un task:
  → unità minima di esecuzione  

- Tutte le attività in una fase eseguono lo *stesso codice* ma su *partizioni diverse dei dati*.
- In sostanza, un'attività consiste nell'esecuzione di tutte le trasformazioni specifiche di quella fase su una porzione di dati specifica.

---

## RDD Persistence (Caching)

- Default:
  → ogni azione ricalcola tutto  

---

### Soluzione: Persistenza

- **persist() / cache()**  

- Effetto:
  → dati mantenuti in memoria  

---

### Vantaggi

- riuso rapido  
- grande speedup (anche 100x)  
- fondamentale per:
  → algoritmi iterativi  

---

### Fault Tolerance

- Se una partizione viene persa:
  → ricostruita tramite **lineage**  

---

### Storage Levels

- MEMORY_ONLY  
- MEMORY_AND_DISK  
- DISK_ONLY  

- **cache()**:
  → equivalente a MEMORY_ONLY  

# 06 MapReduce Design Pattern

### Caveat

- La forza di MapReduce:
  → **semplicità** (data dall'astrazione)

- Il programmatore deve solo:
  - preparare i dati  
  - informazioni per la configurazione 
  - implementare:
    - mapper  
    - reducer  
    - opzionali: combiner, partitioner, setup, cleanup  

- Il framework gestisce tutto il resto  

---

### Pro e Contro

- **Pro**
  → confini chiari su cosa è possibile fare  

- **Contro**
  → bisogna adattare ogni algoritmo  
  → a pochi componenti rigidi  

---

### Problema centrale

- Come trasformare un algoritmo:
  → in uno o più job MapReduce  

---

### MapReduce Design Patterns

- Sono:
  → linee guida generali
  → per trasformare una classe di problemi
  → in un task map reduce usando pattern conosciuti

- NON sono:
  → specifici di un dominio  

---

### Principali pattern

- In-mapper combining (con molti dati intermedi)
- Pairs e Stripes (generare matrici)
- Operatori di algebra relazionale (database relazionali)
- Moltiplicazione tra matrici

---

## In-mapper Combining

### Problema

- Dati intermedi (output mapper):
  - scritti su disco  
  - trasferiti via rete  

- Costi elevati:
  → I/O + comunicazione  

---

### Soluzione

- Ridurre i dati intermedi tramite **Aggregazione locale**

- Due approcci:
  - combiner  
  - in-mapper combining (versione migliorata del combiner)

---

### Tipi

- Stateless (simile a combiner)  
- Stateful (vero in-mapper combining)  

---

### Pseudocodice

- In mapper combining significa includere la logica del combiner dentro il mapper

- Mapper e reducer basici
![[Pasted image 20260419164815.png|300]]

- In-Mapper combiner stateless
    si emette il count del numero di termini trovati per ogni linea del testo
    a ogni nuova linea si inizializza un nuovo **array associativo**
![[Pasted image 20260419164808.png|300]]

- In-Mapper combiner stateful
    qui si inizializza l'**array associativo** all'inizio nel metodo setup 
    ogni invocazione ricorderà lo stato della scorsa invocazione 
    nel map si aggiorna l'array 
    l'emissione avviene una sola volta una volta finite tutte le invocazioni della funzione map
![[Pasted image 20260419164801.png|300]]

- In questo esempio il comportamento (l'output) è lo stesso di un classico combiner

---

### Vantaggi

- Hadoop potrebbe rifiutarsi di eseguire la logica del combiner, perche' esso è opzionale, quindi se non ha abbastanza risorse potrebbe non usarlo, mentre l'in-mapper combiner visto che è inserito dentro il mapper è costretto a eseguirlo
- il combiner permette solo di ridurre il numero di dati trasmessi in rete, ma stai scrivendo molti dati in memoria e sul disco comunque

- Maggior controllo sull’aggregazione  
- Riduzione dati intermedi:
  - meno scritture su disco  
  - meno traffico di rete  

- Evita creazione inutile di oggetti  

---

### Svantaggi

- Gestione memoria complessa 
  si ha un array associativo condiviso tra le invocazioni che cresce in maniera continua

- Problema:
  → struttura dati può crescere troppo  

---

### Soluzioni

- Emissione periodica:
  → ogni N record (e dopo essi svuoti l'array)
  → se N è troppo grande continui ad avere problemi di memoria
  → se è troppo piccolo fai troppe emissioni
  → un alternativa è monitorare il consumo di memoria

- Oppure:
  → monitorare memoria e flush  

---

NOTA: non usare un combiner se stai gia usando un in-mapper combiner, è solo uno spreco di risorse 

## Matrix Generation (Pairs and Stripes)

- Problema:
  → input dimensione $N$  
  → output $N \times N$  

---

### Esempio

- Matrice di co-occorrenza parole  

- Dove:
  - $m_{ij}$ = numero co-occorrenze tra $w_i$ e $w_j$  

---

### Soluzioni

- **Pairs** $N^2$ output di dimensione $1$
- **Stripes** $N$ output di dimensione $N$

---

### Pairs
- Funziona come l'esempio di wordcount, ma emette una key che non è un singolo termine ma una coppia (**pair**) di valori, ad esempio la coppia di parole (cane, guinzaglio) che appaiono insieme
- ogni output di un reducer sarà una singola cella della matrice
![[Pasted image 20260419164741.png]]

---

### Stripes

- Abbiamo un array associativo per ogni termine di una linea di testo, si emette come chiave il termine e come valore la lista di N valori di tutti i termini che appaiono insieme ad esso con il count di quante volte appaiono 
![[Pasted image 20260419164737.png]]

---

- Pairs è l'approccio piu semplice, e non si hanno array associativi quindi si consuma meno memoria
- Stripes emette molti meno dati sulla rete

---
 
## Relational Algebra Operators

- Operazioni supportate:

  - Selection  
  - Projection  
  - Union  
  - Intersection  
  - Difference  
  - Natural Join  
  - Grouping & Aggregation  

- Nei search engine si ha un componente chiamato crawler che deve trovare URL, capirli e organizzarli per poter restituire i risultati di una ricerca nel corretto ordine
- Esso ha una lista iniziale di URL ed esso apre ogni pagina, le scarica e memorizza informazioni in modo strutturato e fa cio in modo ricorsivo per ogni URL presente in quelle pagine fino ad arrivare a trilioni di pagine analizzate 

- Dobbiamo trasformare le tipiche operazioni dei DB in task map reduce
![[Pasted image 20260419164727.png]]

---

### Selection

- Con c una condizione da rispettare, t una riga del database, e un valore qualsiasi $\bot$ (solitamente null)

- **Map**:
  → emette $(t, \bot)$ se $c(t)$ è vera  

- **Reduce**:
  → ritorna $(t, \bot)$  

---

### Projection

- **Map**:
  → crea $t'$ con attributi selezionati  

- **Reduce**:
  → elimina duplicati  

---

### Union

- **Map**:
  → emette $(t, \bot)$ da R e S  

- **Reduce**:
  → unifica duplicati emettendo tutte le tuple di tutte le tabelle

---

### Intersection

- **Map**:
  → emette $(t, \bot)$  

- **Reduce**:
  → output solo se presente in entrambi

---

### Difference ($R - S$)

- Qui bisogna sapere anche da che tabella proviene ogni riga

- **Map**:
  - $(t, R)$ per R  
  - $(t, S)$ per S  

- **Reduce**:
  → output solo $(t, R)$ non presenti in S  

---

### Natural Join

- Schema:
  - R(A,B)  
  - S(B,C)  


---

- la chiave sarà l'attibuto condiviso tra le tabelle, il resto delle informazioni saranno i valori, bisogna anche sapere da che tabella provengono i dati per non fare il join di una tabella con se stessa

- **Map**:
  - $(b, (R, a))$  
  - $(b, (S, c))$  

- **Reduce**:
  → combina coppie compatibili → $(A, B, C)$

---

## Grouping and Aggregation

- Obiettivo:
  → group-by + aggregazione  

- abbiamo una tabella con gli attributi a, b, c, vogliamo aggregare i valori B, in base al valore di A, scartando C

---

- **Map**:
  → $(a, b)$  

- **Reduce**:
  → aggrega valori di b creando una lista

---

## Stage Chaining

- Per problemi complessi:
  → usare più job MapReduce  

- Output di uno:
  → input del successivo  

## Matrix-Vector Multiplication

- Caso generale:
  → matrice troppo grande per stare in memoria 
  → ($m$ (numero righe della matrice) grande)



- Due scenari:

  1. vettore $v$ **piccolo** → entra in memoria (di ogni memoria, di ogni macchina localmente)
  2. vettore $v$ **grande** → non entra in memoria (si deve memorizzare su HDFS)

![[Pasted image 20260419164613.png]]

---

### Esempio intuitivo

![[Pasted image 20260419164651.png|200]]

---

## Caso 1: vettore entra in memoria

- Rappresentazione matrice:
  → lista di tuple $(i, j, m_{ij})$  (questa è una singola linea di testo)

- Il vettore $v$:
  → disponibile a tutti i mapper  

---

### Map

- Input:
  → $(i, j, m_{ij})$ (il value dell'input, la key sarà l'offset che è ignorato)

- Output:
  → $(i, m_{ij} \cdot v_j)$  

---

### Reduce

- Input:
  → $(i, [m_{i1}v_1, m_{i2}v_2, ..., m_{in}v_n])$  

- Output:
  → $(i, \sum_j m_{ij} v_j)$  

---

## Caso 2: vettore NON in memoria

- Dobbiamo dividere il problema in problemi piu piccoli
![[Pasted image 20260419164613.png|200]]

- Ogni valore nella striscia blu della matrice, verranno moltiplicati solo per la parte blu del vettore, e la moltiplicazione è indipendente dalle altre
![[Pasted image 20260419164609.png|200]]

e cosi via
![[Pasted image 20260419164605.png|200]]

- Quindi con grandi problemi si divide il vettore in stripes che possono essere totalmente memorizzati in memoria e moltiplicati in parallelo e indipendente nella matrice, e si ritorna per ogni sotto problema al caso in cui si è risolto per il caso precedente, cioè moltiplicazione tra matrici e vettori che entrano in memoria
![[Pasted image 20260419164558.png|200]]

---

### Strategia

- Dividere il vettore:
  → sottovettori che entrano in memoria  

- Dividere la matrice:
  → **stripes** coerenti con i sottovettori  

---

### Proprietà

- Stripe $i$ e sottovettore $i$:
  → indipendenti  

---

### Approccio

- Applicare algoritmo precedente:
  → per ogni coppia stripe–subvector  

---

## Matrix-Matrix Multiplication

![[Pasted image 20260419164544.png]]
![[Pasted image 20260419164540.png]]

---

### Rappresentazione

- Matrici viste come relazioni:


(**Matrix name, row index, column index, value**) tuples
  - $M \rightarrow (M, i, j, m_{ij})$  
  - $N \rightarrow (N, j, k, n_{jk})$  

---

### Ottimizzazione

- Matrici spesso sparse:
  → si ignorano valori $0$  

---

### Idea

- Join su indice condiviso $j$  
- Aggregazione sui prodotti  

---

![[Pasted image 20260419164420.png]]
![[Pasted image 20260419164413.png]]
![[Pasted image 20260419164409.png]]
![[Pasted image 20260419164403.png]]
![[Pasted image 20260419164357.png]]

---

# Note pratiche Hadoop (importanti per esame)

### File system

- Schema default:
  → **hdfs**  

- Authority:
  → nodo corrente  

- Utente VM:
  → `hadoop`  

---

### Comandi utili

- `copyFromLocal`
  → copia da locale → HDFS  

- `copyToLocal`
  → copia da HDFS → locale  

---

### Avvio sistema

- `start-all.sh`
  → avvia tutti i daemon  

---

### Interfacce web

- NameNode:
  → porta **9870**  

- YARN:
  → porta **8088**  

---

### Gestione file

- Output job:
  - directory obbligatoria  
  - contiene:
    - `_SUCCESS` → job completato  
    - `part-r-xxxxx` → output reducer  

---

### Best practice

- NON sovrascrivere output  
  → creare nuove directory  

- Evitare molti file piccoli:
  → generano troppi:
    - blocchi  
    - split  
    - mapper  

→ possibile crash su cluster piccoli  

---

### Concetti chiave

- **Record**
  → una riga di input  

- Numero mapper:
  → dipende dagli input split  

---

### Esecuzione job

- comando:
  → `hadoop jar <path>`  

- parametri:
  - input  
  - output  

---

### Tool

- File system browsabile via UI  

---

### Sviluppo

- Linguaggio:
  → Java  

- Build:
  → Maven (POM)  