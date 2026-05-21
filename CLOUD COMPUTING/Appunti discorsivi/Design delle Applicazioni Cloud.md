

<font color="#c0504d">Le applicazioni cloud moderne sono</font>, per loro natura, **sistemi distribuiti**. Questo significa che non sono un unico blocco monolitico, ma <font color="#c0504d">sono composte da molteplici componenti che comunicano e si scambiano dati tra loro</font>.

Questo approccio, seppur potente, <font color="#f79646">rende lo sviluppo particolarmente complesso</font>, specialmente all'aumentare delle funzionalità offerte. Il modello tradizionale di sviluppo software si rivela inadatto in questo contesto, rendendo necessario un nuovo approccio basato su requisiti architetturali specifici:

- **Modularità:** L'applicazione deve essere frammentata in componenti distinti.
    
- **Interoperabilità:** I componenti devono potersi "capire" a vicenda, utilizzando interfacce standard e formati di dati condivisi.
    
- **Scalabilità:** Il sistema deve permettere l'aggiunta di nuovi componenti in modo facile e dinamico.
    
- **Componibilità (Composability):** I componenti devono essere riutilizzabili (es. un modulo standard per il login) e "self-contained", con interfacce di comunicazione chiare e ben definite.
    

---

## Service-Oriented Architecture (SOA)

<font color="#4bacc6">Per soddisfare i requisiti del cloud design</font>, si adotta la **Service-Oriented Architecture (SOA)**. È importante sottolineare che la [[Cloud Computing ITA#Service-Oriented Architecture (SOA)|SOA]] <font color="#c0504d">non è una tecnologia</font>, ma una _metodologia di design_ in cui l'applicazione viene concepita come un insieme di **servizi**.

<font color="#c0504d">Ogni servizio è un modulo indipendente dedicato a una specifica funzionalità</font>. Le applicazioni SOA <font color="#9bbb59">sono quindi altamente modulari</font>, distribuite e totalmente indipendenti dall'hardware o dal linguaggio di programmazione utilizzato. L'evoluzione naturale e più granulare di questo concetto sono i **Microservizi**, ovvero servizi ancora più piccoli e ultra-indipendenti.

### Comunicazione e Ruoli

In un'architettura SOA, <font color="#9bbb59">i servizi comunicano tramite il</font> **message passing**.<font color="#c0504d"> I messaggi scambiati contengono dati o richieste e seguono un formato rigoroso e ben definito</font> (schema). Questo garantisce un forte **disaccoppiamento tecnologico**: non importa in che linguaggio sia scritto un servizio, l'importante è che rispetti lo schema del messaggio.

In questo ecosistema emergono due ruoli principali (un singolo servizio può ricoprirli entrambi):

- **Provider:** [[Cloud Computing ITA#Cloud Provider|Colui]] che offre una funzionalità.
    
- **Consumer:** [[Cloud Computing ITA#Cloud Consumer|Colui]] che utilizza una funzionalità.
    

### Il Ruolo del Broker

Un problema tipico nei sistemi distribuiti è la "scoperta" dei servizi: inizialmente, un consumer non conosce né l'indirizzo né l'interfaccia del provider di cui ha bisogno. <font color="#c0504d">La soluzione è l'introduzione di un</font> [[Cloud Computing ITA#SOA – Broker|Broker]], <font color="#c0504d">un intermediario che mantiene un catalogo</font> (registry) <font color="#c0504d">sempre aggiornato</font>.

![[Pasted image 20260406105858.png|400]]

**Ecco come funziona il processo di discovery:**

1. <font color="#4bacc6">Il provider si registra nel catalogo del Broker</font>, <font color="#4bacc6">pubblicando le proprie funzionalità</font>, l'interfaccia e il formato dei messaggi supportato.
    
2. <font color="#4bacc6">Il consumer interroga il Broker per cercare una specifica funzionalità</font>.
    
3. <font color="#4bacc6">Il Broker restituisce al consumer l'indirizzo del provider e la descrizione del servizio</font>.
    
4. <font color="#4bacc6">A questo punto, la fase di discovery si conclude</font>: il consumer inizia a comunicare **direttamente** con il provider, e il Broker esce di scena.
    

<font color="#c0504d">Per evitare che il Broker diventi un collo di bottiglia</font> o un _single point of failure_, <font color="#c0504d">è prassi comune istanziare più Broker all'interno del sistema</font>.

### Vantaggi e Scalabilità della SOA

- **Loose coupling (Basso accoppiamento):** È possibile modificare il codice interno di un servizio senza impattare gli altri.
    
- **Componibilità:** Un intero sistema può essere assemblato combinando servizi già esistenti.
    
- **Comunicazione Stateless:** Ogni richiesta è indipendente dalle altre e non conserva memoria degli stati precedenti, il che facilita enormemente la distribuzione del carico.
    
- **Scalabilità fluida:** Aggiungere o rimuovere servizi è facile, basta aggiornare il registro del Broker.
    

---

## Web Services e Tecnologie Web

I **Web Services (WS)** rappresentano l'implementazione pratica del paradigma SOA attraverso la rete, utilizzando le tecnologie standardizzate dal W3C per permettere l'interazione _machine-to-machine_. Questa evoluzione è il cuore del "Web 2.0".

Il Web moderno si regge su tre pilastri fondamentali:

- **URI / URL (Uniform Resource Identifier/Locator):** Stringhe compatte che identificano risorse fisiche o astratte. <font color="#c0504d">Sono composte da</font> __protocollo__ (es. HTTP), __host__ (dominio o IP), __porta__ e __path della risorsa__.
 ![[Pasted image 20260406111002.png]]
    
- **HTTP:** <font color="#c0504d">Il protocollo applicativo client-server per eccellenza</font>. Funziona con un modello _request/response_, <font color="#c0504d">trasportando i dati nel payload</font>, pur non definendone la struttura interna.
![[Pasted image 20260406111111.png|500]]
    
- **Encoding dei dati:** Necessario per dare una struttura logica ai messaggi. Se nel web classico si usa l'HTML per le pagine, nei Web Services si utilizza l'**XML** per strutturare i dati.
    

### XML (eXtensible Markup Language)
![[Pasted image 20260406111353.png]]

L'<font color="#c0504d">XML conferisce ai dati una struttura gerarchica ad albero</font>. È basato su elementi definiti da un tag di apertura (`<tag>`) e uno di chiusura (`</tag>`).

Vantaggi chiave dell'XML:

- Ha regole sintattiche rigide (documenti _well-formed_).
    
- Utilizza l'**XML Schema** per definire vincoli, campi obbligatori e tipi di dati, permettendo la validazione automatica.
    
- Garantisce massima interoperabilità per la struttura dei messaggi.
    

---

## Interazione nei Web Services: SOAP e WSDL

L'interazione classica nei Web Services si basa su due standard principali: WSDL (per descrivere) e SOAP (per comunicare).

### WSDL (Web Service Description Language)

Il WSDL è un documento XML (machine-readable) che descrive pubblicamente l'interfaccia del servizio web, spiegando cosa fa, dove si trova e come invocarlo.

|Componente WSDL|Descrizione e Funzione|
|---|---|
|**Type**|Definisce i tipi di dati utilizzati come parametri dal servizio.|
|**Messages**|Definisce la struttura dei messaggi scambiati tra client e Web Service.|
|**PortType**|Collega logicamente messaggi di input e output in un'unica operazione.|
|**Binding**|Specifica come i messaggi di una determinata operazione vengono trasferiti (es. via HTTP).|
|**Service**|Specifica l'URI concreto associato al servizio per l'invocazione effettiva.|

Esporta in Fogli

Il documento WSDL si divide concettualmente in due parti: l'interfaccia astratta (tipi, messaggi, portType) e l'implementazione concreta (binding, service).

### SOAP (Simple Object Access Protocol)

Mentre il <font color="#c0504d">WSDL si occupa della descrizione</font>, il **SOAP** è<font color="#c0504d"> lo standard per lo scambio effettivo dei messaggi tra consumer e provider</font>. È basato su XML e viaggia solitamente su HTTP (tramite richieste POST).

![[Pasted image 20260406112554.png]]

La struttura di un messaggio SOAP è definita da un **Envelope** (Busta), che contiene:

- **Header:** Per metadati e informazioni di sicurezza.
    
- **Body:** Il payload vero e proprio con i dati della richiesta/risposta o eventuali errori (_fault_).
    

---

## L'alternativa moderna: REST e JSON

L'<font color="#c0504d">architettura SOAP/WSD</font>L, per quanto robusta, <font color="#c0504d">è molto complessa e spesso sovradimensionata per progetti medio-piccoli</font>. <font color="#ffff00">Come alternativa più snella è nato il modello</font> **REST** (<font color="#4bacc6">Representational State Transfer</font>).

[[03-rest|REST]] non è un protocollo, ma uno stile architetturale più leggero che sfrutta direttamente e appieno le potenzialità del protocollo HTTP.

### Principi di Base di REST
![[Pasted image 20260406113858.png|500]]

- **Identificazione tramite URI:** <font color="#4bacc6">Ogni risorsa è raggiungibile tramite un URI univoco</font>.
    
- **Metodi HTTP:**<font color="#4bacc6"> Le operazioni sulle risorse sfruttano direttamente i metodi HTTP standard</font>.
    
- **Formati flessibili:** <font color="#4bacc6">A differenza di SOAP che impone l'XML, REST supporta XML, testo semplice e</font>, soprattutto, **JSON**.
    

### JSON (JavaScript Object Notation)

<font color="#4bacc6">JSON è diventato il formato principe per le API REST</font>. È estremamente leggero, facile da leggere per gli umani (_human readable_) ed è <font color="#4bacc6">strutturato come una semplice collezione di coppie chiave-valore e liste ordinate</font>. Risulta molto più veloce e meno verboso dell'XML.

### Il paradigma CRUD in REST

Le operazioni fondamentali di qualsiasi sistema (tipiche dei database relazionali) si chiamano **CRUD**. In un'architettura REST, queste si mappano perfettamente in maniera naturale sui verbi HTTP:

|Operazione CRUD|Metodo HTTP (REST)|Scopo|
|---|---|---|
|**Create** (Crea)|POST|Creare una nuova risorsa.|
|**Read** (Leggi)|GET|Leggere o recuperare una risorsa.|
|**Update** (Aggiorna)|PUT|Modificare o aggiornare una risorsa esistente.|
|**Delete** (Elimina)|DELETE|Rimuovere una risorsa.|