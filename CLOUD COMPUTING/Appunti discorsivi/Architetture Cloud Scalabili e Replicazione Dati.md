## 1. Architettura delle Applicazioni Cloud e Disaccoppiamento

Le moderne **cloud applications** sono, a tutti gli effetti, dei sistemi distribuiti. <font color="#4bacc6">La loro logica</font> interna non risiede in un unico blocco, ma <font color="#4bacc6">è suddivisa in più funzionalità distribuite su diverse Macchine Virtuali</font> (VM). <font color="#9bbb59">Per gestire la complessità e garantire alta disponibilità e scalabilità, queste VM vengono organizzate in</font> **tiers (livelli)**: <font color="#c0504d">ogni livello contiene più macchine che replicano esattamente la stessa funzionalità</font>. Il flusso standard prevede che il client invii la sua richiesta al _frontend tier_, il quale si occupa poi di inoltrarla ai vari _backend tiers_.

A livello di design, si adotta una **Service-Oriented Architecture (SOA)**, dove <font color="#c0504d">ogni VM ospita uno o più servizi indipendenti che comunicano tra loro attraverso lo scambio di messaggi </font>(_message passing_). I due approcci storicamente più noti per questo scambio sono [[Design delle Applicazioni Cloud#Principi di Base di REST|REST]] e [[Design delle Applicazioni Cloud#SOAP (Simple Object Access Protocol)|SOAP]]. <font color="#c0504d">REST</font>, grazie alla sua semplicità, <font color="#c0504d">è lo standard predominante</font>, specialmente per le interazioni tra client e frontend. SOAP, sebbene sia ormai ampiamente in disuso, resiste ancora in contesti legacy per la comunicazione interna tra frontend e backend.

Tuttavia, sia SOAP che REST <font color="#4bacc6">si basano sul modello</font> **Request-Reply**, che <font color="#f79646">introduce due criticità fondamentali nei sistemi cloud</font>:

- **Il problema della comunicazione sincrona (Time Coupling):** <font color="#f79646">Il client invia una richiesta e rimane bloccato in attesa della risposta</font>. Questo forte legame temporale impedisce al sistema di progredire autonomamente.

- **Il problema della comunicazione diretta (Space Coupling):** <font color="#4bacc6">Client e Server comunicano direttamente senza intermediari</font>.<font color="#f79646"> In un ambiente cloud</font>, dove le VM vengono create, distrutte o replicate dinamicamente per far fronte al carico, <font color="#f79646">la comunicazione diretta fallisce</font>: non è possibile indirizzare una richiesta a una VM che potrebbe non essere ancora attiva o il cui indirizzo è appena cambiato.


<font color="#c0504d">Mentre il paradigma request-reply è accettabile tra client e frontend</font> (dove l'utente si aspetta una risposta diretta e la complessità del vincolo è tollerabile), esso diventa un collo di bottiglia tra frontend e backend. <font color="#ffff00">L'obiettivo diventa quindi</font> **disaccoppiare il sistema** <font color="#ffff00">introducendo un intermediario</font> (_man in the middle_), ottenendo due vantaggi cruciali:

1. **Space Uncoupling:** <font color="#9bbb59">Mittente e destinatario non hanno bisogno di conoscersi reciprocamente</font>. Una richiesta può essere presa in carico anche da una VM creata molto tempo dopo l'invio del messaggio.

2. **Time Uncoupling:** <font color="#9bbb59">Mittente e destinatario non devono essere attivi contemporaneamente</font>. Il mittente deposita il messaggio e continua la sua esecuzione senza subire blocchi.


## 2. Comunicazione Message-Oriented

<font color="#9bbb59">Il disaccoppiamento si realizza concretamente introducendo un'infrastruttura di comunicazione orientata ai messaggi</font>, nota come **Message Bus**. Questo middleware gestisce la consegna asincrona sfruttando due approcci principali: il **Message Broker** e la **Message Queue**.

### Message Broker (Modello Publish/Subscribe)

![[Pasted image 20260411140745.png|300]]

Si tratta di un sistema di dispatch basato su un modello _one-to-many_. <font color="#4bacc6">I nodi che producono informazioni</font> (_publisher_)<font color="#4bacc6"> inviano i messaggi al</font> [[Mosquitto|broker]] <font color="#4bacc6">senza conoscere i destinatari</font>; <font color="#9bbb59">i nodi interessati</font> (_subscriber_) <font color="#9bbb59">si iscrivono a specifici flussi per ricevere solo i messaggi di loro interesse</font>. Il filtro dei messaggi può avvenire secondo tre modalità:

- **Channel-based:** <font color="#c0504d">I nodi si iscrivono a un canale specifico e ricevono tutto ciò che vi transita</font>.

- **Topic-based:** <font color="#c0504d">Ogni messaggio è etichettato con un campo</font> "topic" <font color="#c0504d">esplicito</font>, <font color="#9bbb59">permettendo ai subscriber di filtrare i flussi in modo più granulare.</font>

- **Type-based:** <font color="#c0504d">Il filtro avviene a livello di codice</font>, basandosi sul tipo (o sottotipo) dell'evento generato.

![[cc message broker.png]]


### Message Queue (Modello Point-to-Point)

![[Pasted image 20260411141234.png|300]]

È l'[[04-message-queue-systems#RabbitMQ||approccio]] più diffuso nelle architetture cloud. L'idea di fondo prevede che <font color="#c0504d">i messaggi vengano depositati all'interno di code</font> (_queue_). Il _producer_ inserisce il messaggio nella coda e, <font color="#ffff00">se il</font> _consumer_<font color="#ffff00"> è pronto</font>, <font color="#ffff00">lo preleva</font> immediatamente; in caso contrario, il messaggio resta parcheggiato nella coda in attesa.

<font color="#c0504d">Le operazioni fondamentali di una coda sono la</font> `Send` (inserimento), <font color="#c0504d">la</font> `Blocking Receive` (<mark style="background:#fdbfff">il consumer si blocca finché non arriva un messaggio</mark>) e <font color="#c0504d">la</font> `Non-blocking Receive` o _polling_ (<mark style="background:#fdbfff">il consumer controlla la presenza di messaggi senza bloccarsi</mark>), oltre alla `Notify`, con cui il sistema avvisa direttamente il consumer della disponibilità di un nuovo elemento.

Un messaggio tipo è composto da tre parti:

1. **Destination:** L'<font color="#c0504d">identificatore della coda di destinazione</font>.

2. **Metadata:** <font color="#c0504d">Informazioni di controllo come la priorità e le modalità di consegna</font>.

3. **Body:** <font color="#c0504d">Il contenuto</font> informativo vero e proprio, che per il sistema di messaggistica è opaco (semplici dati binari o testo).

![[cc message queue.png]]


<font color="#00b050">I messaggi vengono solitamente gestiti con una politica</font> **FIFO (First In, First Out)**, <font color="#00b050">talvolta alterata da livelli di priorità</font>.<font color="#ffff00"> Per garantire l'affidabilità, i messaggi vengono salvati in modo persistente su disco</font>, assicurando che non vadano perduti in caso di crash prima di essere stati effettivamente consumati. Inoltre, <font color="#ffff00">il middleware può operare una</font> **Message Transformation**, modificando il formato o l'endianess dei dati <font color="#ffff00">per superare l'eterogeneità dei diversi sistemi connessi.</font>

A livello architetturale, <font color="#f79646">una singola coda rappresenta un evidente collo di bottiglia</font> (_bottleneck_) e un punto singolo di vulnerabilità (_single point of failure_). Per questo motivo, <font color="#c0504d">il layer di messaggistica viene implementato come un</font> **tier dedicato, replicato e distribuito**. Se un'implementazione _centralizzata_ (su singola VM) è semplice ma non scalabile, un'architettura _distribuita_ coordina più nodi offrendo resilienza e scalabilità elevata.<font color="#c0504d"> Un protocollo standard fondamentale e ampiamente utilizzato in questo ambito è</font> **AMQP** _(Advanced Message Queuing Protocol)_.

## 3. Data Replication e Modelli di Sistema

<font color="#9bbb59">Quando ogni tier replica i propri dati per garantire la continuità del servizio anche in caso di guasti</font> (garantendo che le repliche si comportino esattamente come l'originale), <font color="#f79646">la sincronizzazione standard basata sul solo scambio di messaggi diventa inefficiente all'aumentare delle dimensioni del dataset</font>. <font color="#c0504d">La soluzione architetturale consiste nell'introdurre un ulteriore livello</font>: un **database condiviso (un tier dedicato)**, <font color="#c0504d">riducendo l'uso dei messaggi al solo coordinamento logico</font>.

<font color="#ffff00">Qualsiasi sistema di replica dei dati deve soddisfare tre requisiti fondamentali</font>, assumendo (in questo modello teorico) l'assenza di partizionamenti di rete (_network partitions_):

- **Replication Transparency:** <font color="#4bacc6">Il processo di replica deve essere completamente invisibile all'utente finale</font>.

- **Consistency:** <font color="#4bacc6">Tutte le repliche devono restituire lo stesso risultato a parità di richiesta</font>.

- **Resiliency:** <font color="#4bacc6">Il sistema deve tollerare i guasti e i crash delle singole VM</font>.


Nel modello di sistema di riferimento,<font color="#c0504d"> l'applicazione gestisce</font> **oggetti logici** (file, record, ecc.) <font color="#c0504d">di cui esistono più copie</font>, chiamate **repliche**. <font color="#c0504d">Ogni replica è governata da un</font> **replica manager** (una VM dedicata).<font color="#c0504d"> Le repliche operano come </font>**macchine a stati**, <font color="#c0504d">il che significa che a essere replicato non è solo il dato statico, ma lo stato complessivo del sistema</font>. Ogni operazione di aggiornamento deve essere strutturata per essere **recoverable** (recuperabile) in seguito a un eventuale fallimento.
![[Pasted image 20260411145547.png|400]]
### Il ciclo di gestione delle richieste (Schema Generale)

La gestione di una richiesta attraversa tipicamente cinque fasi sequenziali:

1. **Request:** <font color="#c0504d">Il frontend inoltra la richiesta ai replica manager</font>. Le richieste si dividono in _Query_ (sola lettura) e _Update_(modifica dello stato).
2. **Coordination:**<font color="#c0504d"> I replica manager comunicano tra loro per decidere chi eseguirà l'operazione e se sia necessario attendere per garantire la consistenza</font>.    
3. **Execution:** <font color="#c0504d">L'operazione viene eseguita localmente</font>, spesso in modalità _tentativa_ (consentendo un eventuale rollback).
4. **Agreement:** <font color="#c0504d">Le repliche confrontano i propri risultati; se vi è coerenza e accordo</font>, si procede al _commit_ definitivo.    
5. **Response:**<font color="#c0504d"> La risposta finale viene inviata nuovamente al frontend</font>.


<mark style="background:#fdbfff">Questo flusso viene supportato dalla</mark> **Group o Multicast Communication**,<mark style="background:#fdbfff"> una modalità in cui un nodo comunica simultaneamente con un intero gruppo di nodi</mark>. Esistono diversi protocolli di multicast, dove a maggiori garanzie corrisponde inevitabilmente una maggiore complessità computazionale:

- **Reliable (Atomic) Multicast:** <font color="#9bbb59">Garantisce esclusivamente che il messaggio verrà consegnato a tutti i nodi</font>,<font color="#ffff00"> prima o poi</font>, ma non offre <font color="#f79646">alcuna certezza sull'ordine di ricezione o sui tempi</font>.

- **Total Order Multicast:** <font color="#9bbb59">Assicura che tutti i nodi ricevano i messaggi esattamente nello stesso ordine logico</font>. <font color="#f79646">Non garantisce la contemporaneità</font> (un nodo potrebbe essere più avanti di un altro), ma la sequenza resta coerente su tutto il sistema.

- **View-Synchronous Communication:** È il modello più complesso. <font color="#9bbb59">Garantisce sia l'ordine corretto sia che nessun nodo rimanga indietro rispetto agli altri</font>, pur <font color="#f79646">non potendo imporre un tempo massimo di consegna assoluto</font>.


## 4. Strategie di Replicazione: Modelli Attivi, Passivi e Architettura Gossip

<font color="#c0504d">I sistemi distribuiti classici utilizzano due approcci fondamentali per garantire l'alta disponibilità</font>: la replicazione passiva e quella attiva.

### Primary-Backup Replication (Modello Passivo)

<font color="#4bacc6">Progettato principalmente per la tolleranza ai guasti</font>, questo modello prevede <font color="#c0504d">un unico nodo</font> **Primary** <font color="#c0504d">e un insieme di Nodi di </font>**Backup**. <font color="#c0504d">Il frontend interagisce esclusivamente con il primary</font>. Durante la gestione delle richieste, la fase di _Request_ prevede un ID univoco per evitare duplicati. Nella fase di _Coordination_,<font color="#9bbb59"> il primary stabilisce l'ordine di esecuzione senza confrontarsi con gli altri nodi</font>. Nella fase di _Execution_, il primary esegue l'operazione e salva la risposta.

L'**Agreement** si differenzia in base alla richiesta: <font color="#9bbb59">se si tratta di una Query, il primary risponde subito</font>; s<font color="#ffc000">e si tratta di un Update, propaga le modifiche ai backup tramite multicast atomico e attende il loro ACK prima di passare alla</font> _Response_. <font color="#f79646">Il grande svantaggio di questo approccio è lo spreco di risorse,</font> poiché i backup rimangono inattivi e non contribuiscono a scaricare il lavoro dal primary.

### Active Replication (Modello Attivo)

In questo schema, <font color="#c0504d">tutti i replica manager sono attivi contemporaneamente</font>. <font color="#4bacc6">Il frontend invia la richiesta in multicast</font> (con un ID univoco) <font color="#4bacc6">a tutti i nodi</font>. La _Coordination_ <font color="#4bacc6">è implicita nel mezzo di trasmissione, poiché è strettamente richiesto un</font> **total order multicast**. Nella fase di _Execution_, <font color="#c0504d">tutte le repliche elaborano l'operazione in parallelo</font>. L'_Agreement_ <font color="#c0504d">non è necessario</font> e, per la _Response_, <font color="#c0504d">il frontend utilizza la prima risposta che riceve</font>, scartando le successive. Anche in questo caso si assiste a uno spreco di risorse, questa volta dovuto al calcolo ridondante eseguito da ogni singola macchina.

### Un Nuovo Approccio: La Gossip Architecture

Sia il modello attivo che quello passivo offrono alta disponibilità, ma <font color="#f79646">soffrono di una</font> **scarsa scalabilità** e di un utilizzo inefficiente dell'infrastruttura. <font color="#c0504d">Per ottenere contemporaneamente sia l'alta disponibilità che la scalabilità</font>, <font color="#4f81bd">si introduce una strategia in cui</font> **più replica manager gestiscono le richieste in parallelo**, parallelizzando il carico sia per le letture che per le scritture.

<font color="#ffff00">Ciò è reso possibile dal fatto che gli aggiornamenti</font> **non sono immediati**, ma <font color="#ffff00">vengono propagati in differita</font> (**lazy propagation**). Il client riceve una risposta immediata dal sistema prima ancora che la modifica sia stata distribuita a tutte le repliche. Questa filosofia è alla base della **Gossip Architecture**.

In questa architettura, <font color="#c0504d">i replica manager scambiano periodicamente tra loro dei </font>**gossip messages** i<font color="#c0504d">n background per allineare gli aggiornamenti accumulati</font> (spesso in modalità batch o periodica). I client vengono assegnati a specifici frontend per ottimizzare il bilanciamento del carico, mantenendo la possibilità di migrare su altri Front ends in caso di crash. Il sistema distingue nettamente tra le _Query_ (sola lettura) e gli _Update_ (modifiche strutturali che non leggono lo stato attuale).

Il compromesso di questa architettura risiede nelle garanzie di consistenza:

- **Consistenza per il client:** Strettissima. <font color="#9bbb59">Ogni singolo client ha la garanzia di vedere sempre una storia coerente con le proprie operazioni precedenti</font> (vista coerente nel tempo).
    
- **Consistenza tra le repliche:** Rilassata. <font color="#9bbb59">Le repliche possono divergere temporaneamente, aderendo al modello dell</font>a **Sequential Consistency** (client diversi potrebbero notare discrepanze temporanee tra i dati di nodi diversi).
    

<font color="#4bacc6">Nel flusso di gestione delle richieste Gossip</font>, la _Request_ <font color="#4bacc6">giunge a un solo replica manager</font>. Nella fase di _Coordination_, il manager **non esegue immediatamente l'operazione**: <font color="#4bacc6">verifica prima che la propria copia interna sia aggiornata almeno quanto la vista attuale del client</font>. <font color="#4bacc6">Se il nodo è rimasto indietro</font>, <font color="#c0504d">si mette in attesa dei messaggi di gossip dagli altri nodi</font>. Una volta verificata la coerenza, avvengono l'_Execution_ locale e la _Response_ (immediata per gli update, successiva all'esecuzione per le query). L'_Agreement_ avviene poi in modo asincrono (lazy) tramite lo scambio dei messaggi di gossip.

### Il ruolo dei Vector Timestamps

<font color="#c0504d">Per implementare il controllo nella fase di</font> _Coordination_, verificare la coerenza della vista del client e mantenere l'ordine delle richieste, <font color="#c0504d">si utilizzano i</font> **timestamps**. <font color="#c0504d">Il frontend mantiene un </font>**vector timestamp** <font color="#c0504d">che rappresenta quantitativamente il livello di aggiornamento della vista del client</font>. Il flusso dei timestamp si articola così:

1. Il FE invia al replica manager la richiesta includendo il timestamp `prev` (lo stato noto al client).

2. Il replica manager valuta la condizione: se il suo timestamp sui valori (`valueTS`) è minore di `prev` (valueTS<prev), significa che i dati locali del manager sono più vecchi di quelli già visti dal client. La richiesta (sia essa una Query o un Update che non soddisfi la condizione prev≤valueTS) viene **rimandata** in attesa di ricevere aggiornamenti tramite gossip.

3. Quando la condizione è soddisfatta, l'operazione viene elaborata. Se si tratta di un nuovo Update, il manager controlla i duplicati tramite l'ID richiesta, incrementa il valore di `prev` per generare un nuovo timestamp e lo salva nel og locale.

4. Il manager risponde al frontend inviando il timestamp aggiornato `new`.

5. Il frontend esegue il **merge** dei timestamp per aggiornare la vista del client.

![[Pasted image 20260411152939.png|300]]


_Nota di ottimizzazione:_ Se i canali di comunicazione e le assegnazioni tra client, FE e replica manager rimangono fissi e stabili nel tempo, il controllo esplicito sui timestamp può essere saltato, poiché l'ordine sequenziale è già implicitamente garantito dal canale stesso.

## 5. Caso di Studio: ZooKeeper

Un esempio concreto e fondamentale di servizio distribuito ad alta disponibilità è **Apache ZooKeeper**. Viene utilizzato come layer infrastrutturale per consentire lo scambio di dati cruciali e il coordinamento tra i servizi, occupandosi principalmente di compiti quali la gestione delle configurazioni, il naming delle risorse e il coordinamento generale del sistema.

Le sue proprietà operative riflettono i vincoli di consistenza e resilienza analizzati:

- È un sistema centralizzato di coordinamento ma fortemente replicato.
    
- Per poter funzionare e validare le operazioni, richiede strettamente che la **maggioranza dei nodi sia attiva** (sistema a quorum).
    
- I nodi soggetti a crash o isolati vengono rimossi ed esclusi in modo completamente automatico.
    

A livello di modello di replicazione, ZooKeeper non usa l'approccio decentralizzato Gossip, bensì un modello **Primary-Backup** altamente ottimizzato, la cui consistenza e propagazione atomica dei messaggi sono regolate da un protocollo proprietario chiamato **Zab** _(ZooKeeper Atomic Broadcast)_.