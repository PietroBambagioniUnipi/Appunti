# 01 Storia del Cloud Computing

- Il **Cloud Computing** è<font color="#ff0000"> un modello che permette accesso di rete sempre disponibile, conveniente</font> e *on-demand* <font color="#ff0000">a un insieme condiviso di risorse computazionali configurabili </font>(server, storage, rete, applicazioni), <font color="#ff0000">che possono essere allocate e rilasciate rapidamente con minimo sforzo gestionale.</font>

- Non è una tecnologia nata improvvisamente, ma il risultato di un’evoluzione durata diversi decenni.

- Il concetto nasce negli anni ’60 con John McCarthy:
  “la computazione può essere organizzata come un servizio pubblico”.

- Il Cloud è quindi la combinazione di più tecnologie fondamentali (pilastri).

---

##### The origin - Mainframes
- Anni ’70: utilizzo dei **mainframe**
  - grandi computer centralizzati e costosi,
  - utilizzati da più utenti contemporaneamente (*time-sharing*),
  - accesso tramite terminali “dumb” (solo input/output).

- Problema principale:
  - collo di bottiglia → utenti in coda.

- Fine anni ’70:
  - diffusione dei **personal computer**:
    - costi ridotti,
    - maggiore autonomia,
    - ma capacità limitate.

- Nello stesso periodo nasce il **networking**:
  - connessione tra computer,
  - possibilità di scambiarsi dati e coordinarsi per completare task complessi 
  - introduzione di LAN e WAN.

---

##### Distributed Application
- Due paradigmi principali:
  - *Client/Server*: il server fornisce servizi ai client.
  - *Peer-to-Peer*: ogni nodo può offrire o richiedere servizi.

![[Pasted image 20260304093847.png]]

- Anni ’80:
  - aumento della potenza computazionale,
  - ma si colpi un muro,
  - limite delle singole macchine → non scalano oltre un certo punto.

- Nasce il **parallel processing**:
  - più processori lavorano sullo stesso task.

- Evoluzione → **distributed computing systems**:
  - più macchine comunicano tra loro,
  - si scambiano dati,
  - cooperano per risolvere task complessi.

![[Pasted image 20260304094120.png]]

---

##### Cluster computing
- I sistemi distribuiti inizialmente sono organizzati in **cluster**:
  - gruppi di nodi collegati alla stessa LAN.

- Presenza di un **cluster head**:
  - riceve e assegna i task.

- Vantaggio:
  - esecuzione di task complessi.

- Problema:
  - **single point of failure**:
    - se il head fallisce → il cluster si blocca.

- Organizzazione dei task:
  - task → subtask → sub-subtask,
  - cluster esegue subtask,
  - nodi eseguono sub-subtask.

![[Pasted image 20260304094434.png]]

---

##### Grid Computing
- Evoluzione del cluster per evitare il single point of failure.

- **Grid computing**:
  - nessun nodo centrale,
  - gestione distribuita dei task.

- I nodi:
  - cooperano tra loro,
  - decidono dove eseguire i task in maniera coordinata.

![[Pasted image 20260304094559.png]]

- Differenza chiave:
  - cluster → hardware spesso specializzato,
  - grid → hardware non specializzato (più flessibile).

- Nei cluster la head aveva spesso hardware specializzato

- Limiti principali:
  - scalabilità lenta (non real-time), poiche' bisogna reinstallare i software sulle nuove macchine 
  - espansione lunga (giorni/settimane),
  - bassa fault tolerance, se un nodo fallisce, fallisce anche la task che stava girando sul nodo
  - hardware eterogeneo → codice meno portabile che puo richiedere aggiustamenti.

---

##### Hardware Virtualization
- Problema:
  - eterogeneità hardware → difficoltà nel portare il codice.

- **Hardware virtualization**:
  - introduce un livello di astrazione,
  - il software non dipende dall’hardware.

- È uno dei pilastri del Cloud.

---

##### Web Based Technologies
- Permettono accesso semplice alle applicazioni tramite rete (es. browser).

---

##### Service Oriented Architecture
- Le applicazioni sono divise in **componenti (servizi)**:
  - indipendenti,
  - comunicano tramite messaggi.

- Obiettivo:
  - suddividere sistemi complessi in moduli più semplici.

---

##### Utility Computing Model
- Le risorse vengono fornite come servizio:
  - *on-demand*
  - *pay-per-use*

- Analogia:
  - come elettricità.

---

##### Timeline
- Il Cloud Computing nasce dall’evoluzione di tecnologie dagli anni ’70 ai ’90.

- Primi servizi cloud:
  - Amazon → EC2.

- Oggi:
  - mercato molto ampio,
  - forte impatto positivo sulle aziende.

![[Pasted image 20260304095654.png]]


# 02 Introduction and Foundation Concepts

- Il **Cloud Computing** è un termine che indica sia:
  - le applicazioni fornite come servizi via Internet,
  - sia l’infrastruttura hardware e software (datacenter) che le supporta.

- **Cloud Computing**: ambiente IT progettato per fornire **risorse scalabili e misurabili**, accessibili da remoto tramite Internet.

- Esempi di risorse IT:
  - CPU, RAM, storage.

- Nota:
  - se le risorse **non sono scalabili e misurabili**, non si parla di cloud ma solo di server remoto.

![[Pasted image 20260304100320.png]]

---

##### Cloud Services
- **Cloud Infrastructure**:
  - ambiente remoto (datacenter) che fornisce le risorse.

- **Cloud Service**:
  - servizio/applicazione costruita sopra l’infrastruttura.

- Due modalità:
  - con interfaccia (accesso diretto via web, solitamente da parte di utenti),
  - via API (usato da altre applicazioni).

---

##### Everything as a Service - XaaS
- **XaaS (Everything as a Service)**:
  - trend: trasformare tutto in servizi erogati via cloud.

![[Pasted image 20260304100335.png]]

- Esempi:
  - **Cloud storage** → upload, download, condivisione file.
  - **Cloud ERP** → software aziendale accessibile via web o client.

![[Pasted image 20260304100507.png]]

---

##### Roles
- Esistono diversi ruoli nell’ecosistema cloud:
![[Pasted image 20260304101242.png]]

- Il **Cloud Provider** è l’organizzazione che fornisce risorse IT basate su cloud (es. computing, storage, networking). 
  In genere progetta, implementa e gestisce una propria piattaforma cloud (es. AWS), occupandosi dell’infrastruttura e della sua manutenzione.

- Il **Cloud Consumer** è l’organizzazione o individuo che utilizza le risorse offerte dal provider tramite un contratto. 
  Può usare direttamente le risorse oppure sfruttarle per creare servizi propri. 
  Non coincide necessariamente con l’utente finale: può infatti rivendere servizi ad altri utenti.

- Il **Cloud Service Owner** è il soggetto che sviluppa e gestisce un servizio cloud sfruttando le risorse del provider. 
  Il servizio è generalmente offerto a scopo di profitto, tipicamente tramite modello in abbonamento 

- Il **Cloud Resource Administrator** è responsabile della gestione operativa delle risorse cloud (configurazione, monitoraggio, manutenzione). 
  Può appartenere al cloud provider oppure al cloud consumer, a seconda di chi ha il controllo delle risorse.

- Il **Cloud Carrier** è il soggetto che fornisce la connettività tra utenti e cloud (es. Internet Service Provider come ILIAD). 
  Senza questo livello non sarebbe possibile accedere ai servizi cloud.

- Il **Cloud Auditor** è una terza parte indipendente che valuta il sistema cloud. 
  Si occupa principalmente di verificare sicurezza, performance e conformità.

- Il **Cloud Service User** è l’utente finale che utilizza concretamente il servizio cloud (es. utente di Google Drive).

- Nota:
  - **Cloud Provider** e **Cloud Service Owner** sono spesso entità diverse,
  - ma possono coincidere (es. Google sviluppa servizi che girano sulla propria infrastruttura).

---

##### Cloud Model
- Il cloud si basa su due proprietà chiave:

- **Scalable**:
  - risorse allocate dinamicamente e su richiesta,
  - provisioning rapido,
  - minimo intervento umano,
  - possibile gestione automatica via software.

- **Measured**:
  - modello *pay-per-use*,
  - utilizzo monitorato (CPU, RAM, banda),
  - fatturazione proporzionale al consumo.

---

##### Business Model
- Il **Business Model** del Cloud Computing funziona nel seguente modo:
  - I provider vendono risorse IT.
  - Le aziende le acquistano per:
   - uso interno,
   - creazione di servizi da rivendere.

---

##### Cloud Computing Infrastructure
- Infrastruttura basata su **datacenter**:
  - spazi dedicati con server e rete.

- Fornisce:
  - computing,
  - storage,
  - networking.

- Accesso:
  - via Internet,
  - condiviso tra più utenti.

---

##### Multi-tenancy
- Approccio tradizionale:
  - risorse limitate,
  - poca personalizzazione dell'ambiente.

- **Multi-tenancy**:
  - più utenti condividono la stessa infrastruttura,
  - ciascuno ha l’illusione di essere isolato.

- Analogia:
  - hotel (limitato) vs appartamento in affitto (personalizzabile).

---

##### Virtualization
- Permette di creare una versione virtuale delle risorse.

- Obiettivo:
  - dare isolamento e flessibilità.

![[Pasted image 20260304102745.png|300]]

- **Hardware virtualization**:
  - replica completa di un server,
  - può eseguire un OS senza modifiche,
  - più OS sulla stessa macchina fisica.

---

##### Hypervisor
- La virtualizzazione è gestita da una **virtualization layer**.

- Componente chiave: **Hypervisor (VM Manager)**:
  - crea e gestisce macchine virtuali.

- Terminologia:
  - **Host** → macchina fisica,
  - **Guest** → sistema virtuale.

- Tipi:
  - **Full virtualization**
  - **Paravirtualization**
  - **OS-level virtualization (Container)**

---

##### Cloud Virtualized Infrastructure
- Nei datacenter:
  - ogni server esegue un hypervisor,
  - vengono create VM su richiesta.

- Le VM:
  - comunicano tra loro,
  - comunicano con l’esterno.

![[Pasted image 20260304103255.png]]

---

##### Dynamic provisioning
- **Dynamic provisioning**: creazione/distruzione dinamica delle risorse.

- Due tipi:
  - **Horizontal scaling**:
    - aggiunta/rimozione VM.
  - **Vertical scaling**:
    - aumento/riduzione risorse della VM.

![[Pasted image 20260304103535.png|300]]
![[Pasted image 20260304103540.png|300]]

- Terminologia:
  - *scaling out* → aggiungere risorse,
  - *scaling down* → rimuovere risorse.

- Nota:
  - orizzontale più usato,
  - verticale più semplice ma limitato dall’hardware.

![[Pasted image 20260304103651.png]]

---

- **Metering**:
  - monitoraggio dell’uso delle risorse,
  - base per il modello pay-per-use,
  - molto più preciso rispetto ai sistemi tradizionali.



# 03 Advantages of Cloud Computing

- Il Cloud Computing introduce vantaggi significativi e nuovi modelli di business, cambiando il modo in cui i sistemi IT vengono progettati e utilizzati.

---

##### Cloud for Business
- Nel **modello tradizionale**:
  - l’azienda deve progettare e mantenere tutta l’infrastruttura IT internamente,
  - richiede:
    - alto investimento iniziale (hardware + personale),
    - costi fissi continui (manutenzione, aggiornamenti, gestione).

![[Pasted image 20260304103931.png]]
![[Pasted image 20260304103957.png]]

- Problema principale:
  - difficoltà di scalare:
    - crescita → servono nuovi investimenti,
    - riduzione → risorse inutilizzate (spreco).

---

##### Cloud computing benefits
- Con il cloud:
  - modello **utility-based (pay-per-use)**,
  - risorse disponibili *on-demand* (anche automaticamente via software),
  - **scalabilità dinamica**.

- Vantaggi principali:
  - riduzione costi iniziali,
  - eliminazione di molti costi fissi,
  - nessuna necessità di infrastruttura propria,
  - minore necessità di personale specializzato.

- Riduzione costi complessiva:
  - i provider operano su larga scala,
  - acquistano hardware in bulk → costo unitario minore,
  - costi condivisi tra più clienti.

---

##### Other indirect advantages
- **Minima gestione**:
  - sicurezza dei dati, disponibilità del servizio, manutenzione del sistema, e responsabilita' legali gestite dal provider,
  - uso di tecniche di replica e ridondanza.

- **Alta qualità del servizio**:
  - hardware e tecnologie avanzate.

- **Affidabilità**:
  - maggiore rispetto a infrastrutture interne.

- **Disponibilità continua**:
  - grazie a sistemi di ridondanza.

- **Gestione software semplificata**:
  - licenze e aggiornamenti gestiti dal provider.

- **Accesso da qualsiasi luogo**.

- **Focus sul business**:
  - le aziende si concentrano sulla logica applicativa, non sull’infrastruttura da gestire.

---

##### Cloudification
- **Cloudification**:
  - processo di migrazione di applicazioni e servizi non pensate per il cloud, verso il cloud.

![[Pasted image 20260304105027.png]]

- Esempi:
  - **grandi aziende**:
    - spostano servizi nel cloud per ridurre costi (es. Expedia).
  - **startup**:
    - lanciano servizi senza grandi investimenti iniziali (es. Airbnb su AWS).
  - **HPC temporaneo**:
    - uso di alta potenza computazionale solo quando necessario (es. Pixar).

---

##### Global scale services
- Con approccio tradizionale:
  - difficile gestire miliardi di utenti,
  - traffico concentrato in un singolo data center → colli di bottiglia della rete (anche lato ISP).

- Con il cloud:
  - più datacenter distribuiti,
  - stesso servizio replicato globalmente.

- Meccanismo:
  - richieste instradate al datacenter più vicino,
  - riduzione latenza,
  - distribuzione del carico.

- Esempio:
  - Google Search gestisce enormi quantità di dati.

- Strategia:
  - **divide et impera** (suddivisione dei dati e del carico).
  - le richieste sono instradate al datacenter piu vicino

---

##### Global-scale content distribution
- **Content Distribution**:
  - distribuzione efficiente di contenuti a molti utenti.

- Requisiti possibili (in base al tipo di contenuto):
  - bassa latenza,
  - gestione banda,
  - adattamento al dispositivo.

- Esempi:
  - streaming video (qualità adattiva),
  - giochi mobile con utenti distribuiti globalmente.

---

##### Challenges / Risks
- **Costi di rete**:
  - necessità di connessione continua.

- **Limiti di banda**:
  - possibile collo di bottiglia.

- **Disponibilità rete**:
  - senza connessione → nessun accesso.

- **Portabilità limitata**:
  - mancanza di standard,
  - dipendenza dal provider (vendor lock-in).

- **Problemi legali**:
  - dati memorizzati in paesi diversi,
  - normative differenti (privacy, compliance).

---

##### Data security
- I dati:
  - sono trasmessi su rete (potenzialmente insicura),
  - sono memorizzati su infrastrutture esterne.

- Rischi:
  - perdita di controllo diretto,
  - vulnerabilità durante la trasmissione.

- Soluzioni:
  - cifratura (encryption),
  - meccanismi di sicurezza avanzati.

![[Pasted image 20260304110349.png]]


# 04 Cloud NIST model, service types and deployment models

- La standardizzazione nel cloud è limitata:
  - tecnologia relativamente recente,
  - ogni provider usa soluzioni proprietarie.

- I primi sforzi di standardizzazione non riguardano API o tecnologie,
  ma **terminologia e definizioni comuni**.

- Nasce il modello del *NIST* (National Institute of Standards and Technology):
  - definisce cosa è il cloud computing,
  - identifica componenti e concetti fondamentali.

---

##### NIST Model
- Il modello NIST fornisce una base comune per:
  - definire il cloud,
  - descrivere servizi e componenti.


- Il NIST definisce tre elementi fondamentali per descrivere il Cloud Computing
- **Essential Characteristics**:
  - insieme delle proprietà obbligatorie che un sistema deve avere per essere considerato cloud.
- **Service Models**:
  - insieme delle tipologie di servizi che il provider offre ai consumer.
- **Deployment Models**:
  - insieme dei modelli architetturali che definiscono come l’infrastruttura cloud è organizzata ed esposta.

![[Pasted image 20260306212408.png]]

---

##### Essential characteristics
- Per essere considerato cloud, un sistema deve avere 5 caratteristiche:

- **Broad Network Access**:
  - accesso da qualsiasi luogo via rete.

- **Rapid Elasticity**:
  - risorse allocate/deallocate rapidamente.

- **Measured Service**:
  - utilizzo monitorato e fatturato in base all'uso.

- **On-Demand Self-Service**:
  - risorse richieste autonomamente dall’utente.

- **Resource Pooling**:
  - risorse condivise tra più utenti,
  - pool sufficientemente grande,
  - percezione di risorse “infinite”.

- Nota:
  - i datacenter richiedono pianificazione anticipata (anni per costruzione ~1-2, vita ~5–10 anni).

---

##### Service delivery and Deployment
- Il NIST definisce tre categorie di servizi in base a che tipo di servizio e' offerto all'utente e a come e' offerto

- **Service Models**:
  - IaaS
  - PaaS
  - SaaS

- **Deployment Models**:
  - Public
  - Private
  - Community
  - Hybrid

- Differiscono per:
  - livello di astrazione,
  - modalità di accesso e organizzazione.

---

##### NIST Reference Architecture
- La Reference Architecture Definisce:
  - componenti del cloud,
  - attori coinvolti (non l’implementazione).

![[Pasted image 20260306213201.png]]

- Attori:
  - Cloud Consumer
  - Cloud Provider
  - Cloud Auditor
  - Cloud Carrier
  - Cloud Broker

- **Cloud Broker**:
  - intermediario tra consumer e provider,
  - acquista risorse in bulk,
  - le rivende a prezzo inferiore,
  - genera profitto.

![[Pasted image 20260306213304.png]]

---

##### Deployment Models

- Definiscono come l’infrastruttura espone le sue risorse, come è organizzata e accessibile.

---

###### Public Cloud
- Infrastruttura offerta al pubblico:
  - accessibile a chiunque,
  - modello commerciale.

- Caratteristiche:
  - massima multi-tenancy,
  - costi ridotti,
  - alta scalabilità,
  - puo offrire un alta qualita' di personale e tecnologie grazie ai costi ridotti.

- Svantaggio:
  - dati off-premises.

---

###### Private Cloud
- Infrastruttura dedicata a una singola organizzazione.

- Caratteristiche:
  - accesso limitato,
  - massimo controllo,
  - maggiore sicurezza.

- Svantaggi:
  - costi elevati,
  - gestione complessa.

- Non tutte le compagnie sono in grado di permettersi questa soluzione, ma alcuni ne necessitano per motivi di privacy o controllo.

![[Pasted image 20260306213613.png]]

---

###### Public vs Private
- Public:
  - multi-tenancy alta,
  - costi bassi,
  - modello one-to-many.

- Private:
  - isolamento,
  - costi alti,
  - modello one-to-one.

![[Pasted image 20260306213821.png]]

---

###### Community Cloud
- Infrastruttura cloud condivisa tra più organizzazioni che hanno **esigenze comuni** 
  (es. sicurezza, compliance, settore di attività).

- Nasce come soluzione intermedia:
  - alternativa al private cloud (troppo costoso),
  - più controllata rispetto al public cloud.

- Esempio:
  - più aziende dello stesso settore (es. sanitario) collaborano per costruire un’infrastruttura condivisa accessibile solo ai membri.

- Caratteristiche:
  - accesso **limitato alla comunità** (non pubblico),
  - **costi condivisi** tra i membri,
  - livello di **multi-tenancy moderato**,
  - maggiore controllo rispetto al public cloud.

- Vantaggi:
  - riduzione dei costi rispetto al private cloud,
  - maggiore controllo su dati e infrastruttura,
  - possibilità di rispettare vincoli normativi comuni (compliance),
  - possibile uso di modelli *pay-per-use* interni alla comunità.

- Svantaggi:
  - meno scalabile rispetto al public cloud,
  - necessità di coordinamento tra le organizzazioni,
  - governance più complessa (decisioni condivise).

- Deployment:
  - può essere **on-premises** o **off-premises**,
  - può essere gestita:
    - dai membri della comunità,
    - oppure da un provider esterno.

- In sintesi:
  - compromesso tra **costo (public)** e **controllo (private)**.

---

###### Hybrid Cloud
- Combinazione di più modelli (tipicamente public + private).

- Uso tipico:
  - dati sensibili → private,
  - dati non critici → public.

- Vantaggio:
  - bilanciamento costo/sicurezza.

![[Pasted image 20260306214122.png]]

---

##### Selecting the model
- In generale:
  - public cloud → scelta più comune,
  - private → per requisiti specifici (sicurezza, latenza),
  - hybrid/community → compromessi.

---

##### Service Delivery Models
- Definiscono come i servizi vengono forniti:

- **IaaS**
- **PaaS**
- **SaaS**

- Differenza principale:
  - livello di astrazione,
  - responsabilità tra provider e consumer.

- Cambia quale e' il set di aspetti e funzioni che devono essere gestiti dal owner e dal customer.
![[Pasted image 20260306214524.png]]

---

##### Conventional computing model
- Nel modello tradizionale il consumer gestisce tutto:
  - hardware,
  - sistema operativo,
  - middleware,
  - applicazioni,
  - dati.

![[Pasted image 20260306214646.png]]

---

##### Infrastructure as a Service (IaaS)
- Livello di astrazione basso.
- Divide a meta' la responsabilita' di provider e owner

- Il provider fornisce:
  - infrastruttura virtualizzata.

- Il consumer gestisce:
  - OS,
  - runtime,
  - applicazioni,
  - dati.

- Vantaggio:
  - controllo elevato,
  - nessun costo hardware.

![[Pasted image 20260306214701.png]]
![[Pasted image 20260306214753.png]]

---

##### Platform as a Service (PaaS)
- Livello intermedio.

- Il provider gestisce:
  - infrastruttura,
  - ambiente di esecuzione.

- Il consumer gestisce:
  - logica applicativa,
  - dati.

- Svantaggio:
  - dipendenza dal provider (lock-in), l'applicazione cloud sviluppata per un ambiente potrebbe non funzionare su un ambiente di un diverso provider.

![[Pasted image 20260306215853.png]]

---

##### Software as a Service (SaaS)
- Livello massimo di astrazione.

- Il provider gestisce tutto:
  - hardware → software.

- Il consumer:
  - usa l’applicazione,
  - può fare piccole personalizzazioni.

![[Pasted image 20260306215720.png]]

---

##### Cloud / Pizza analogy
  - **Tradizionale**:
    - prepari la pizza da zero (impasto, ingredienti, cottura),
    - gestisci tutto → massimo controllo, massimo sforzo.

  - **IaaS**:
    - compri l’impasto già pronto,
    - aggiungi ingredienti e cuoci tu → controllo alto, meno lavoro sull’infrastruttura.

  - **PaaS**:
    - ricevi la pizza quasi pronta (già preparata),
    - devi solo occuparti del contesto (es. apparecchiare, bevande) → meno responsabilità tecnica.

  - **SaaS**:
    - vai al ristorante e consumi,
    - non gestisci nulla → minimo controllo, minimo sforzo.

![[Pasted image 20260306215638.png]]

---

##### Model Examples
![[Pasted image 20260306215613.png]]

---

##### PaaS / SaaS implementation
- PaaS e SaaS possono essere **implementati sopra** un'infrastruttura IaaS
- Un'infrastruttura IaaS può essere utilizzata per creare un'infrastruttura PaaS: vengono create macchine virtuali e su di esse viene installata una piattaforma software
- Un'infrastruttura PaaS può essere utilizzata per creare un sistema SaaS: una piattaforma PaaS viene utilizzata per creare un software che viene fornito come SaaS.

![[Pasted image 20260306215541.png]]

---

##### Other Cloud Services
- Altri modelli:

- **Storage as a Service**:
  - storage remoto (IaaS).

- **DBaaS**:
  - database gestito (PaaS).

- **BaaS**:
  - backup cloud.

- **Desktop as a Service**:
  - desktop remoto.

- **FaaS (Function as a Service)**:
  - logica applicativa divisa in una collezione di funzioni,
  - eseguite in risposta a eventi,
  - molto usato in IoT.


# 05 Virtualization

- **Virtualization** è la rappresentazione di risorse computazionali fisiche in forma virtuale tramite uno strato software.

- Idea base:
  - esiste una risorsa fisica,
  - viene creata una versione virtuale tramite software.

- Questo software è chiamato **virtualization layer**:
  - si installa sopra la macchina fisica,
  - crea e gestisce le risorse virtuali.

- Nel cloud:
  - l’utente utilizza risorse virtuali come se fossero reali.

- Effetto principale:
  - **decoupling** tra hardware fisico e utente,
  - l’utente non accede mai direttamente all’hardware.

![[Pasted image 20260311132152.png|300]]

---

- Tipi di risorse virtualizzabili:

  - **Basic computing resources**:
    - CPU, RAM, disco,
    - sempre necessarie.

  - **Optional resources**:
    - tastiera, stampante, rete.

- Regole:
  - le risorse base richiedono sempre una controparte fisica,
  - le risorse opzionali possono:
    - usare hardware reale,
    - oppure essere completamente simulate.

- Nota:
  - la versione virtuale può differire da quella fisica
    (es. CPU 64-bit → VM 32-bit, oppure suddivisione in più CPU virtuali).

---

##### Machine / Server Virtualization
- Consiste nel creare una **Virtual Machine (VM)** sopra una macchina fisica.

- Terminologia:
  - **Host system** → macchina fisica,
  - **Guest system** → macchina virtuale.

- Caratteristiche:
  - più VM sullo stesso host,
  - isolamento completo tra VM:
    - no accesso a memoria o storage di altre VM,
  - l'host può monitorare le VM.

- Ogni VM:
  - ha un proprio sistema operativo (**guest OS**).

![[Pasted image 20260311132620.png]]

---

##### Hypervisor
- Il virtualization layer è un set di programmi che creano l'ambiente dove gireranno le VM
- E' implementato tramite l’**Hypervisor** o **Virtual machine Monitor (VMM)**.

- Funzioni:
  - crea e gestisce VM,
  - assegna risorse (CPU, RAM, disco),
  - controlla esecuzione.

- Tipi principali di virtualizzazione:
  - Full virtualization
  - Para virtualization
  - Hardware-assisted virtualization
  - (oltre a OS-level virtualization)

---

##### Hypervisor types
- Due approcci:

- **Hosted (Type 2)**:
  - hypervisor sopra un sistema operativo,
  - es. VirtualBox,
  - più compatibile ma con overhead.

- **Bare Metal (Type 1)**:
  - hypervisor direttamente su hardware,
  - es. VMware ESX, Hyper-V,
  - meno overhead, più efficiente.

![[Pasted image 20260311133156.png|200]]

- Nota:
  - i cloud provider usano principalmente **bare metal**.

- **Pro e contro dei due approcci (Hosted vs Bare Metal):**

  - **Hosted (Type 2)**:
    - svantaggi:
      - maggiore overhead → parte delle risorse è consumata dall’OS host,
      - minore efficienza complessiva.
    - vantaggi:
      - maggiore compatibilità hardware,
      - più semplice da installare e usare,
      - sfrutta driver e supporto dell’OS host.

  - **Bare Metal (Type 1)**:
    - vantaggi:
      - minore overhead → accesso diretto all’hardware,
      - migliori performance.
    - svantaggi:
      - maggiore complessità di implementazione,
      - compatibilità hardware più limitata,
      - gestione più complessa.


---

##### Full Virtualization
- L’hypervisor simula completamente l’hardware.

- Il guest OS:
  - non sa di essere virtualizzato,
  - funziona senza modifiche.

- Vantaggi:
  - compatibilità totale,
  - isolamento completo.

- Svantaggio:
  - overhead elevato (emulazione completa).

---

##### Para Virtualization
- Riduce l’overhead della full virtualization.
- Riduce le assunzioni riguardo all'OS che deve essere *non modificato* e *unaware*

- Idea:
  - modificare il sistema operativo guest,
  - farlo collaborare con l’hypervisor.

- Caratteristiche:
  - alcune operazioni gestite dal guest OS,
  - maggiore efficienza.

- Svantaggi:
  - richiede OS modificati (**porting**),
  - minore isolamento e sicurezza,
  - meno compatibilità.

---

##### Hardware Assisted Virtualization
- Evoluzione della full virtualization.

- Idea:
  - usare supporto hardware (CPU) per alcune operazioni.

- Vantaggi:
  - meno overhead,
  - esecuzione più veloce.

- Limitazione:
  - richiede hardware compatibile.

---

##### Operating System Level Virtualization
- Non usa hypervisor.

- Tutto gestito dal kernel del sistema operativo.

- Non crea VM ma **container**:
  - ambienti isolati che condividono lo stesso OS.

- Esempi:
  - Docker, container Linux.

![[Pasted image 20260311135153.png]]

- Vantaggi:
  - molto leggero,
  - quasi zero overhead.

- Svantaggi:
  - tutti condividono lo stesso OS,
  - isolamento minore,
  - problemi di sicurezza.

---

##### Other types of virtualization
- **Network virtualization**:
  - creazione di reti virtuali sopra reti fisiche.

- **Storage virtualization**:
  - aggregazione di storage fisico in pool virtuali.

---

##### Emulation vs Virtualization
- **Virtualization**:
  - stessa architettura e instruction set della macchina fisica,
  - le istruzioni possono essere eseguite quasi direttamente sulla CPU,
  - minima o nessuna traduzione → **alte performance**,
  - si crea una replica logica dell’hardware, non una simulazione completa.

- **Emulation**:
  - architetture diverse (instruction set diverso),
  - ogni istruzione deve essere:
    - tradotta (*binary translation*), oppure
    - interpretata a runtime,
  - comportamento completamente simulato → **molto più lenta**.

- Differenza chiave:
  - virtualization → *replica* (stesso sistema),
  - emulation → *simulazione* (sistema diverso).

- Nota:
  - anche nella virtualizzazione alcune operazioni possono essere emulate
    (es. accesso a periferiche o istruzioni privilegiate non eseguibili direttamente).

---

##### Emulation
- **Emulation**:
  - creazione di un sistema che imita completamente un altro,
  - nessuna assunzione su hardware o *instruction set*.

- Tecniche principali:
  - **Binary translation**:
    - traduzione completa del codice binario,
    - più veloce dell’interpretazione ma complessa.
  - **Interpretation**:
    - esecuzione istruzione per istruzione,
    - più semplice ma più lenta.
---

##### Virtualization Advantages
- **Server consolidation**:
  - più VM su stesso hardware → migliore utilizzo.

- **Riduzione costi**.

- **Gestione semplificata**:
  - separazione ambiente fisico/virtuale.

- **Deploy veloce**:
  - clonazione VM.

- **Fault tolerance**:
  - VM migrabili tra server.

- **Sicurezza**:
  - isolamento tra VM.

---

##### Virtualization Downsides
- **Single point of failure**:
  - host fisico critico per molte VM.

- **Overhead**:
  - performance ~85–90% del reale,
  - ma in miglioramento con nuove tecnologie.

# 06 Virtualization Technologies (non-hw assisted)

- In questo capitolo consideriamo **full virtualization senza supporto hardware**.

---

##### Virtualization Requirements
- Tre requisiti fondamentali:

  - **Equivalence**:
    - una VM deve comportarsi come una macchina reale equivalente.

  - **Resource Control**:
    - l’hypervisor controlla le risorse fisiche,
    - il guest OS controlla solo quelle virtuali.

  - **Efficiency**:
    - la maggior parte delle istruzioni deve essere eseguita direttamente sulla CPU (senza intervento del VMM).

---

##### Multiprogramming
- La virtualizzazione si basa su concetti già presenti nel **multiprogramming** (un approccio implementato nei moderni OS per emulare una macchina con piu processori di quelli reali).

- Idea:
  - simulare più CPU usando una sola CPU fisica.

- Si introducono i **VCPU (Virtual CPU)**:
  - ogni processo ha una CPU virtuale,
  - i VCPU vengono eseguiti a turno sulla CPU reale. 

![[Pasted image 20260311140750.png|300]]

- Effetto:
  - ogni processo pensa di avere la CPU tutta per sé.

---

##### VCPU Execution
- Il VCPU è una struttura dati che contiene lo stato della CPU (registri).

- Esecuzione:
  - carico lo stato del VCPU nella CPU reale,
  - eseguo il processo,
  - salvo lo stato e passo a un altro VCPU.

![[Pasted image 20260311141227.png|200]]

---

##### Context Switch
- Cambio tra VCPU → **context switch**:
  - salva stato corrente,
  - carica nuovo stato.

- Trigger:
  - timer o interrupt,
  - spesso eseguite in hardware.

---

##### Multiprogramming support
- Supporto hardware necessario:

  - **Interrupt (timer)**:
    - per interrompere i processi.

  - **Salvataggio registri automatico**.

  - **Meccanismi di protezione**:
    - controllo accesso memoria e istruzioni.

---

- Il meccanismo di protezione puo essere implementato sfruttando diversi livelli di privilegio:

  - **Kernel mode (ring 0)**:
    - accesso completo a tutte le istruzioni.

  - **User mode (ring 3)**:
    - accesso limitato.

- Eseguire una kernel instruction allo user level attiva un *meccanismo di protezione*

![[Pasted image 20260311141613.png|300]]


##### Multiprogramming support (Protection)

- Il supporto di **protezione** è fondamentale per garantire isolamento e corretto funzionamento del multiprogramming.

- Componenti principali:

  - **sys register (mode flag)**:
    - indica se la CPU è in **user mode** o **kernel mode**,
    - impedisce l’esecuzione di istruzioni privilegiate in user mode.

  - **sys-mem register**:
    - contiene l’indirizzo iniziale della memoria privilegiata,
    - protegge strutture critiche (es. VCPU, kernel data).

  - **ret register**:
    - memorizza l’indirizzo a cui tornare dopo l’esecuzione in kernel mode,
    - usato per riprendere l’esecuzione del processo in user mode.

- Durante un **context switch** (triggerato da timer/interrupt), il sistema operativo:

  - salva lo stato della CPU corrente nella struttura del VCPU,
  - seleziona un nuovo VCPU da eseguire,
  - carica il suo stato nei registri della CPU,
  - esegue un’istruzione speciale:
    - ritorno a user mode,
    - salto all’indirizzo salvato in **ret**.

---

##### Virtual Memory
- Ogni processo vede una memoria **virtuale**:
  - continua,
  - isolata,
  - che parte da indirizzo 0.

- Ogni processo crede di avere tutta la memoria per se
![[Pasted image 20260314133249.png|300]]

---

##### Memory Management Unit (MMU)
- Traduzione indirizzi:
  - virtuale → fisico.

- Gestita da:
  - **MMU** (hardware),
  - controllata dal sistema operativo del host.

![[Pasted image 20260314133736.png|300]]

---

##### Page Table
- Struttura dati che mappa:
  - indirizzi virtuali → fisici.

- Usata dalla MMU.

- La CPU ha il registro *Page Table Base Registry (PTBR)* che punta all'indirizzo logico del primo byte della page table
- E' memorizzata in RAM e organizzata in una struttura multi livello dove e' necessario accedere a multiple directory per tradurre un indirizzo virtuale in fisico.

![[Pasted image 20260314134148.png]]
![[Pasted image 20260314134259.png]]

---

##### Segmentation / Paging
- Se la RAM non basta:
  - si usa memoria secondaria.

- **Page fault**:
  - pagina non in RAM → caricata da disco.

![[Pasted image 20260314134434.png]]

---

##### Interrupt / Exceptions
- Meccanismi per gestire eventi urgenti (che devono essere gestiti dalla CPU). 

- **Exception (trap)**:
  - interne,
  - sincrone (errore del programma).

- **Interrupt**:
  - esterne,
  - asincrone (hardware).

![[Pasted image 20260314134623.png|300]]

- Entrambe:
  - attivano handler nel kernel,
  - causano cambio da user → a kernel mode.

---

##### Interrupt Descriptor Table (IDT)
- Tabella che associa:
  - eventi (interrupts e exceptions) → handler (funzione nel kernel che esegue certe operazioni).

![[Pasted image 20260314135615.png|300]]

---

## Virtualization Technologies
(parliamo di **Full Virtualization senza supporto hardware**)

---

##### Virtualization – Full Virtualization
- Il multiprogramming introduce già concetti di virtualizzazione:
  - CPU virtuali (VCPU),
  - memoria virtuale.

- Obiettivo della full virtualization:
  - eseguire **un intero sistema operativo** come se fosse su hardware dedicato.

- Idea chiave:
  - ogni VM è un sistema completo,
  - contiene:
    - kernel,
    - applicazioni,
    - ambiente multiprogrammato interno.

- Relazione:
  - hypervisor ≈ kernel della macchina fisica,
  - VM ≈ processo avanzato (che esegue un OS invece di un semplice programma).

---

##### Hypervisor
- L’hypervisor sfrutta quanto più possibile i meccanismi già presenti nel multiprogramming:
  - gestione CPU,
  - gestione memoria,
  - gestione interrupt.

- Obiettivo:
  - riutilizzare funzionalità hardware → **maggiore efficienza**.

- Caso ideale:
  - stessa architettura tra host e guest:
    - esecuzione diretta delle istruzioni sulla CPU,
    - minimo uso di emulazione.

- Problema:
  - alcune istruzioni (privilegiate) non possono essere eseguite direttamente:
    - devono essere intercettate,
    - emulate dal VMM.

- Obiettivo generale:
  - **minimizzare l’emulazione** per ridurre overhead e migliorare performance.

---

##### Virtualizing CPU
- Metodo:
  - caricare stato VCPU,
  - eseguire codice direttamente.

- Se istruzione non valida:
  - trap → hypervisor,
  - emulazione,
  - ripresa esecuzione.

---

##### Guest OS Execution
- Il guest OS:
  - deve poter usare anche istruzioni privilegiate,
  - queste vengono intercettate ed emulate.

---

##### Trap and Emulate Model
- Privilegi:
  - ring 0 → hypervisor,
  - ring 1-3 → VM.

![[Pasted image 20260314145408.png|300]]

- Processo:
  - istruzione privilegiata (Trap code) → trap,
  - hypervisor emula,
  - ritorno alla VM.

![[Pasted image 20260314145616.png|300]]

- Problema:
  - overhead elevato → minimizzare trap.


---

- Esistono istruzioni **difficili da emulare**, in particolare quelle legate alle system call, come l’istruzione **INT**.

- Caso: una applicazione nel guest OS esegue una system call tramite **INT**:

  - (1) L’istruzione INT è **privilegiata**:
    - richiede esecuzione in **ring 0**,
    - ma la VM non può accedere al ring 0 (riservato all’hypervisor),
    - quindi viene generato un **trap** → context switch verso l’hypervisor.

  - (2) Problema del handler:
    - l’INT nel sistema host attiverebbe un handler diverso,
    - ma noi dobbiamo eseguire il **handler del guest OS**,
    - quindi l’hypervisor deve recuperare e usare quello corretto.

  - (3) Emulazione del handler:
    - il codice del handler contiene molte istruzioni privilegiate,
    - ogni istruzione non eseguibile direttamente:
      - genera un trap,
      - viene emulata dal VMM.

  - (4) Effetto a catena:
    - ogni istruzione del handler può causare:
      - context switch → emulazione → ritorno,
    - quindi si crea una sequenza di trap/emulazioni.

- Conseguenza:
  - **overhead molto elevato**,
  - questo è uno dei principali limiti della full virtualization senza supporto hardware.

![[Pasted image 20260314150352.png|300]]

---

- IDT:
  - ogni VM ha la sua,
  - ma solo quella dell’hypervisor è attiva sull’hardware.
  - quella del guest e' non direttamente connessa (floating)

![[Pasted image 20260314150456.png]]

---

##### Virtualizing Physical Memory
- Ogni VM:
  - ha una porzione di memoria fisica,
  - pensa di avere la memoria che parte da 0.

- Traduzione:
  - guest → host memory via MMU.

![[Pasted image 20260314150701.png|300]]
- con l'hypervisor possiamo tradurre direttamente da **indirizzo fisico guest** a **indirizzo fisico host**, quindi sono necessarie solo due traduzioni e non tre.


---

##### Virtual MMU
- Due mapping:
  - G: guest virtual → guest physical, 
  - H: guest physical → host physical.

- Traduzione totale:
  - G ∘ H.

![[Pasted image 20260314151322.png|300]]

---

##### Brute Force Method
- Combina le funzioni $G$ e $H$ senza il supporto dell'hw usando le **shadow page tables**, un ulteriore layer che implementano la funzione $H$, mentre $G$ e' implementata dalla page table dell'host
![[Pasted image 20260314152153.png|300]]

---

##### Shadow Tables
- Sono written protected:
  - ogni modifica da parte della VM → trap,
  - cio porta a protezione, ma anche ad un overhead.

- Il VMM aggiorna:
  - PTBR,
  - page table entries.

![[Pasted image 20260314154221.png|300]]
- Ogni volta che si verifica una modifica nella tabella delle pagine viene eseguita un'interruzione, il VMM prende il controllo e aggiorna (o aggiunge) una tabella shadow 


---

##### Virtualizing I/O Devices
- I/O è privilegiato → deve essere emulato.

- Il VMM:
  - crea dispositivi virtuali,
  - traduce operazioni in comandi reali.

- Accediamo all'I/O con un astrazione chiamata system calls, la VM ha l'illusione di essere in totale controllo dell'hw, ma in realta' accede ad un hw virtuale implementato da una serie di data structure in memoria
![[Pasted image 20260314155018.png|300]]
- La rappresentazione virtuale viene aggiornata dal VMM ogni volta che viene eseguita un'operazione di lettura/scrittura; il VMM traduce inoltre i comandi inviati alle periferiche virtualizzate in istruzioni per i dispositivi reali.

---


##### Interrupt Management
- Il **VMM** gestisce tutti gli **interrupt dai dispositivi fisici**, perché è l’unico ad accedere all’hardware.

- Mantiene una **IDT host**:
  - usata dalla CPU per gestire interrupt reali,
  - non accessibile alle VM.

- Gli interrupt servono per evitare il **busy waiting** (la CPU non resta in attesa attiva).

- Obiettivo:
  - dare al guest OS l’illusione di controllare le periferiche.

- Per questo:
  - il VMM **emula i dispositivi**,
  - ogni VM ha una propria **IDT virtuale**.

- Il VMM gestisce:
  - interrupt fisici,
  - interrupt virtuali generati per le VM.

![[Pasted image 20260314155322.png|300]]

---

##### Virtualizing Interrupts
- Quando il VMM deve **emulare un interrupt** per una VM:

  - consulta la **IDT del guest OS**,
  - esegue le operazioni necessarie per simulare l’interrupt.

- Passi:
  - salva lo stato corrente,
  - aggiorna l’**instruction pointer** con l’handler,
  - restituisce il controllo alla VM.

- Risultato:
  - il guest esegue l’handler come se l’interrupt fosse reale.

![[Pasted image 20260314155408.png|300]]

---

##### Hardware Interrupt
- Gli interrupt hardware arrivano sempre al VMM:
  - anche se una VM è in esecuzione.

- Flusso:
  - dispositivo → VMM,
  - il VMM gestisce l’interrupt,
  - poi può **emularlo** nella VM eseguendo il handler del guest OS.

![[Pasted image 20260314155339.png|300]]

---

##### QEMU
- **QEMU** è un emulatore open source che può fare anche virtualizzazione.

- Caratteristiche:
  - emula hardware completo,
  - supporta architetture diverse (binary translation).

- Modalità:
  - architetture diverse → emulazione (lenta),
  - stessa architettura → esecuzione parziale diretta (più veloce).



# 07 Virtualization Technologies (Hardware assisted virtualization)

---

##### NON-hw assisted virtualization
- La **full virtualization senza supporto hardware** introduce un overhead elevato:
  - il guest OS gira in **user mode**,
  - le istruzioni privilegiate non possono essere eseguite direttamente,
  - ogni operazione critica (I/O, interrupt, istruzioni privilegiate) richiede:
    - trap → context switch → emulazione,
    - in alcuni casi anche **catene di context switch**.

- In passato era accettabile per i vantaggi della virtualizzazione.

- Dal 2006 (**Intel, AMD**):
  - introduzione di **supporto hardware** per ridurre overhead,
  - alcune istruzioni privilegiate possono essere eseguite direttamente dalla VM.

- Intel introduce:
  - **VMX (Virtual Machine eXtension)**.

---

##### Root and non-root modes
- VMX introduce due nuovi **operating modes**:
  - **root mode** → hypervisor,
  - **non-root mode** → VM.

- Sono indipendenti da user/kernel mode → 4 combinazioni:
  - root/system
  - root/user
  - non-root/system
  - non-root/user

- Root:
  - esecuzione diretta su hardware,
  - hypervisor e host OS.

- Non-root:
  - codice della VM,
  - controllo fine su cosa può eseguire.

---

- Nuove istruzioni hardware:
  - **VMLAUNCH**, **VMRESUME** → gestione VM,
  - **VM Exit** → passaggio VM → hypervisor,
  - **VM Entry** → ritorno hypervisor → VM.

![[Pasted image 20260318170535.png]]

- Vantaggio:
  - meno emulazione,
  - meno context switch,
  - alcune istruzioni privilegiate eseguibili direttamente.

---

##### Interrupt management (hw assisted)
- Obiettivo:
  - delegare alcuni interrupt direttamente alla VM.

- Introduzione della **Interrupt Remapping Table (IRT)**:
  - struttura tra CPU e IDT,

- L'IRT si trova tra e collega l'IDT dell'host con l'IDT degli ospiti e collega le singole funzioni; ha una voce per ogni possibile richiesta di interrupt. Ogni voce mappa le richieste al vettore di interrupt di una VM o al vettore di interrupt del VMM.
![[Pasted image 20260318171158.png]]

- Prima di questo meccanismo INT e IRET richiedono l'emulazione completa, il cambio di contesto, la simulazione della chiamata di sistema e la restituzione del controllo al guest, ma con il supporto hardware l'esecuzione di questi due può essere delegata alla VM grazie al livello non root, inoltre l'IRT viene utilizzato per mappare la funzione
![[Pasted image 20260318171438.png]]

---

##### Virtual Machine Control Structure (VMCS)
- Struttura dati hardware per ogni VM.

- Contiene tutte le informazioni della VM:
  - stato CPU,
  - configurazione,
  - controlli.

- E' disponibile un set di istruzioni in-hardware per manipolare questa struttura dati
![[Pasted image 20260318171941.png]]

---

##### VMCS States
- 6 aree principali:
  
  - **Guest State**:  
    - contiene lo stato della VCPU della VM (registri, contesto),  
    - viene caricato durante il *VM entry* e salvato durante il *VM exit*.  
  
  - **Host State**:  
    - contiene lo stato della CPU dell’hypervisor,  
    - salvato quando si entra nella VM e ripristinato quando si esce.  
  
  - **VM Execution Control**:  
    - definisce quali istruzioni possono essere eseguite in non-root mode,  
    - le istruzioni non consentite causano un **VM exit**,  
    - include anche flag per gestione I/O e *peripheral passthrough*.  
  
  - **VM Entry Control**:  
    - controlla il comportamento durante il passaggio **root → non-root**,  
    - (es. cosa caricare o inizializzare nella VM).  
  
  - **VM Exit Control**:  
    - controlla il comportamento durante il passaggio **non-root → root**,  
    - (es. cosa salvare o aggiornare).  
  
  - **VM Exit Reason**:  
    - memorizza il motivo dell’ultimo VM exit,  
    - utile per capire perché il controllo è tornato all’hypervisor.

- Nota:
  - non esiste switch diretto VM→VM,
  - sempre:
    - VM → hypervisor → VM.

---

##### RAM MANAGEMENT
- Obiettivo:
  - ogni VM vede memoria:
    - isolata,
    - che parte da 0.
  - ogni VM crede di avere la memoria tutta per se 
![[Pasted image 20260318174443.png]]

---

##### Extended Page Tables (EPT)
- Supporto hardware per gestione memoria.

- Due mapping:
  - G: virtual guest → guest physical,
  - H: guest physical → host physical.

- L’**MMU estesa** esegue:
  - G ∘ H direttamente in hardware senza VM exits.

![[Pasted image 20260318180418.png|500]]

- Vantaggi:
  - niente VM exit per page table update,
  - più accessi memoria (mitigati da cache).

---

##### Hw passthrough
- Problema:
  - I/O è il principale collo di bottiglia nelle performance delle VM.

- Soluzione:
  - **passthrough**:
    - assegnare direttamente un dispositivo a una VM.

- Vantaggi:
  - prestazioni elevate.

- Svantaggi:
  - dispositivo non condivisibile,
  - perdita virtualizzazione su quel device,
  - necessita di un supporto hardware specifico.

---


##### Passed-through device
- Per implementare un **device in passthrough** servono due meccanismi:

  - **Direct mapping**:
    - lo spazio di memoria I/O del dispositivo fisico è mappato direttamente nello spazio della VM,
    - quindi il guest OS può accedere direttamente ai registri del dispositivo.

  - **Direct interrupt assignment**:
    - gli interrupt del dispositivo sono inviati direttamente alla VM,
    - il VMM continua a gestire gli altri interrupt.

![[Pasted image 20260318181323.png]]

---

##### I/O Mapping
- Obiettivo:
  - permettere accesso diretto ai dispositivi in passthrough,
  - intercettare gli altri accessi via VMM.

- Meccanismo:
  - **I/O bitmap** (in VMCS):
    - 1 bit per indirizzo I/O.

- Funzionamento:
  - bit = 1 → accesso diretto (no VM exit),
  - bit = 0 → VM exit → VMM gestisce.

- Per passthrough:
  - si settano a 1 gli indirizzi del dispositivo.

---

##### Interrupts (hw assisted)
- Due modalità di gestione degli interrupt in VMX:

  1. interrupt → **VM exit** → gestito dal VMM  
  2. interrupt → **direttamente alla VM**

- Nel passthrough:
  - si usa la seconda modalità,
  - l’hardware usa la **Interruption Vector Table (IVT) del guest OS** per eseguire l’handler.

- Problema:
  - la VM può ricevere interrupt anche quando non è in esecuzione.

---

##### VM States
- Stati della VM:

  - **Running** → in esecuzione su una delle CPU
  - **Ready** → pronta ma non in esecuzione 
  - **Halted** → inattiva ma disponibile (per esempio spenta)

![[Pasted image 20260318181657.png|300]]

- Transizioni:
  - running → halted: istruzione *hlt*,
  - halted → ready:
    - power on,
    - interrupt (es. da device passthrough).

---

##### Interrupts management (VM states)
- Come gestiamo gli interrupt in questi tre stati?

  - **Running**:
    - gestito subito (anche direttamente senza intervento del vmm).

  - **Ready**:
    - salvato e gestito quando la VM parte.

  - **Halted**:
    - salvato,
    - VM passa a Ready.


- Il **posted interrupt mechanism** è in grado di memorizzare l'interruzione e gestirla in seguito.
- Viene implementato grazie a una struttura dati aggiuntiva chiamata **Posted Interrupt Descriptor** (**PID**), un buffer che memorizza l'interruzione.
---

##### Posted Interrupts
- Consente di memorizzare i segnali di interrupt (post) per una successiva notifica alla VM, senza intervento del VMM

- Usa:
  - **PID (Posted Interrupt Descriptor)**.

![[Pasted image 20260318182906.png|300]]

- Integrazione:
  - nella **IRT**, un interrupt può puntare:
    - a un handler,
    - oppure a un PID.

![[Pasted image 20260318183120.png|200]]

---

##### Posted Interrupt Descriptor (PID)
- Contiene:

  - **PIR (Posted Interrupt Requests)**:
    - buffer degli interrupt (contiene gli interrupt).

  - **SN (Suppress Notification)**: una flag che dice se notificare subito o no la CPU della presenza dell'interrupt
    - 0 → notifica immediata,
    - 1 → interrupt accumulati.

  - **NV (Notification Vector)**:
    - vettore usato per notificare la VM.

---

##### Interrupt delivery
- Come viene consegnato un interrupt a una VM:

- Quando arriva un interrupt:
  - la CPU consulta la **IRT (Interrupt Remapping Table)**.

- Se l’interrupt è associato a un **device in passthrough**:
  - viene aggiornato il **PIR (Posted Interrupt Request)** nel PID della VM.

- A questo punto:

  - se **SN = 1 (suppress notification attivo)**:
    - l’interrupt viene solo memorizzato (non notificato subito).

  - se **SN = 0**:
    - se la VM è **running**:
      - l’interrupt viene inoltrato direttamente alla VM,
    - se la VM è **halted**:
      - l’interrupt provoca il **risveglio della VM** (→ stato Ready).

- In sintesi:
  - PIR memorizza,
  - SN decide se notificare,
  - lo stato della VM determina quando viene gestito.

---

##### PID update
- What happen every time the vm change its state?

- Aggiornamento PID in base allo stato:

  - **Running**:
    - SN = 0,
    - NV → Active Notification Vector (IDT VM).

  - **Ready**:
    - SN = 1.

  - **Halted**:
    - SN = 0,
    - NV → Wake-up vector.

- Quando la VM passa a Running:
  - il VMM inietta gli interrupt dal PIR.

---

##### DMA devices
- I dispositivi **DMA** sono dispositivi di I/O che leggono i dati direttamente dalla RAM
  - bisogna specificare inizio e fine della porzione della RAM che si vuole leggere

![[Pasted image 20260318183744.png|300]]

- **IOMMU**:
  - traduce indirizzi per I/O,
  - protegge memoria,
  - può generare page fault.

![[Pasted image 20260318184237.png|300]]

---

##### Nested Virtualization
- What if i want to run a vm inside a vm?

- Questo metodo è utilizzato abbastanza spesso e si chiama **virtualizzazione annidata**. Si tratta di un sistema in cui si dispone di un server fisico, un hv di livello 1 (host hv) in esecuzione sull'hardware, con il quale si crea una macchina virtuale (VM), e all'interno della VM è possibile installare un hv di livello 2 (guest hv) che creerà a sua volta altre VM. Questa virtualizzazione annidata può continuare all'infinito.
- Un caso d'uso è quello di installare una piattaforma all'interno di una VM in grado di creare altre VM.
![[Pasted image 20260318185158.png|400]]

- Limiti:
  - livello 2 spesso senza supporto hardware.

- Ottimizzazione:
  - hypervisor cooperativi:
    - HV2 delega esecuzione a HV1 (bisogna usare lo stesso hv, e serve specifico hw). 

![[Pasted image 20260318185415.png|300]]

---

##### KVM
- **KVM (Kernel-based Virtual Machine)**:
  - infrastruttura di virtualizzazione nel kernel Linux,
  - usa supporto hardware.

- Caratteristiche:
  - integrato nel kernel (non standalone),
  - VM eseguite in ambiente molto simile all’hardware reale.

![[Pasted image 20260318185638.png|300]]



# 08 Virtualization (Paravirtualization)

---

##### Paravirtualization
- Problema della full virtualization (senza HW support):
  - guest OS non modificato → molte istruzioni privilegiate non eseguibili,
  - → molti **context switch** e overhead.

- **Paravirtualization**:
  - si modifica il **guest OS** (tipicamente il kernel),
  - le applicazioni restano invariate e non sono consapevoli di questo cambiamento.

![[Pasted image 20260318191414.png|300]]

- Idea:
  - il VMM espone delle **API** (rompe le assunzioni di isolamento e “unchanged OS”),
  - il guest OS usa direttamente queste API tramite un interfaccia chiamata virtualization layer,
  - si evitano molti trap → meno overhead.

- L'hv e' ora visibile da dentro la VM che e' consapevole di essere tale

---

##### Paravirtualization – Implementation
- Le API sono chiamate **Hypercalls**:
  - chiamate dirette al VMM,
  - eseguite in **modalità privilegiata** (kernel mode).

- Effetto:
  - alcune funzioni del kernel guest vengono delegate all’hypervisor.

![[Pasted image 20260318191722.png|300]]

- Pro:
  - migliori performance,
  - nessun supporto hardware necessario.

- Contro:
  - richiede OS modificati,
  - difficile con OS closed-source,
  - meno flessibile.

- Nota:
  - oggi meno usata grazie alla virtualizzazione con supporto hardware.

---

##### Xen
- **Xen** è un hypervisor paravirtualizzato basato sul kernel linux.

- Struttura:
  - hypervisor minimale su hardware,
  - VM implementate tramite i **domains**.

- **Dom0**:
  - dominio speciale,
  - gestisce creazione e controllo degli altri domini.

- Supporta:
  - paravirtualization,
  - full virtualization (con HW support),
  - accesso diretto a dispositivi.

![[Pasted image 20260318192042.png|300]]

---

##### Virtualization Overhead
- Usare VM per isolare applicazioni:
  - buon isolamento,
  - ma **overhead elevato** (memoria + performance).

- Soluzione:
  - **lightweight virtualization**.

---

##### Lightweight Virtualization
- Obiettivo:
  - isolare applicazioni senza usare VM.

- Requisiti:
  - isolamento,
  - creazione/distruzione dinamica,
  - ambiente self-contained.

- Idea:
  - niente hypervisor,
  - niente kernel duplicato.

- Ad esempio istanziare 100 sistemi che usano linux senza dover istanziare 100 kernel linux

---

##### Operating System Virtualization
- L'**Operating System Virtualization** e' un approccio Lightweight:
  - si usa **un solo kernel condiviso**,
  - modificato per supportare ambienti isolati.

- Non sono vere VM:
  - sono ambienti isolati (user space separati).
  - e.g. Docker

![[Pasted image 20260405160842.png]]

- Pro:
  - basso overhead,
  - alta densità (molti ambienti su stessa macchina),
  - performance quasi native.

- Contro:
  - stesso kernel per tutti,
  - possibili problemi di sicurezza,
  - meno flessibile (OS limitati).

---

##### Container
- I **container** sono ambienti isolati per processi:
  - ogni applicazione è isolata,
  - non accede alle altre,
  - crede di essere l'unico in esecuzione sul sistema,
  - sono un esempio di OS virtualization.

- Caratteristiche:
  - nessun kernel separato,
  - overhead minimo,
  - limitazione risorse possibile.

![[Pasted image 20260405160900.png]]

---

##### Linux Container
- Basati su:
  - **namespaces**
  - **control groups (cgroups)**

- si assicurano che un ambiente isolato possa accedere solamente alle risorse assegnate al container
![[Pasted image 20260405161025.png]]

---

##### Namespaces
- Isolano la vista delle risorse:
  - processi,
  - rete,
  - file system.

- Evoluzione di **chroot**:
  - isolamento più completo.

- Ma non limitano la quantita' accessibile della risorsa che vedono, ad esempio posso far vedere al processo una sola CPU, ma non posso controllare quanto CPU time essa si prende

![[Pasted image 20260405161105.png]]

---

##### Control Groups (cgroups)
- Limitano le risorse:
  - CPU,
  - RAM,
  - I/O.

- Complementano i namespaces:
  - isolamento + controllo risorse.

---

##### Docker
- **Docker** usa container per distribuire software.

- Vantaggi:
  - ambiente completo (codice + librerie),
  - pronto all’uso,
  - niente problemi di dipendenze.


- È possibile creare un'istanza di un container da un'*immagine* scaricata dal **Docker Registry**; le immagini vengono scaricate ed eseguite con il **Docker Engine**.
![[Pasted image 20260405161118.png]]

---

##### Serverless Computing
- Evoluzione dei container:
  - **serverless / microservices**.

- Idea:
  - non deploy di VM complete,
  - ma piccoli servizi (container) pronti all’uso,
  - con dipendenze già configurate.




# 0C1 Application Architecture

---

##### Recap
![[Pasted image 20260405174059.png]]

---

##### Traditional application
- Architettura classica:
  - logica **monolitica** su un singolo server fisico,
  - dati salvati su disco locale.

- Client:
  - leggeri (GUI/web),
  - comunicano via LAN/WAN.

- Limite:
  - scalabilità e disponibilità ridotte.

---

### Cloudification
- **Cloudification**:
  - deploy dell’applicazione su VM **senza modificarla**.

- Caratteristiche:
  - stessa architettura monolitica,
  - accesso via rete.

- Limiti:
  - non sfrutta pienamente il cloud:
    - no vera scalabilità,
    - no alta disponibilità,
  - unico vantaggio: costo risorse più basso.

- → Serve **redesign** per sfruttare il cloud.

---

### Cloud Application Architecture
- **Cloud-native application**:
  - applicazione suddivisa in **moduli indipendenti**,
  - ogni modulo fornisce una funzionalità specifica.

- Deploy:
  - ogni modulo su VM diverse.

- Esempio:
  - 2-tier:
    - tier applicativo,
    - tier dati.

![[Pasted image 20260405174859.png|300]]

---

### Multi-tier Architecture
- I moduli sono organizzati in **tier**:
  - ogni tier = una funzionalità.

- Caratteristiche:
  - struttura a **catena** (l'output di un tier diventa l'input di un altro),
  - ogni tier può avere più VM (ridondanza, performance).

- Tipicamente:
  - primo tier → API / frontend (solitamente l'unico accessibile dall'esterno),
  - altri tier → logica, database, storage.

![[Pasted image 20260405174955.png|300]]

---

### Chain of interactions
- Le richieste seguono una **catena di interazioni** tra tier.

- Comunicazione:
  - via LAN nel datacenter,
  - tramite protocolli applicativi (middleware).

- Middleware:
  - componenti standard quindi non devi svilupparlo da zero (es. DBMS).

![[Pasted image 20260405175343.png|500]]

---

### Compute Cluster
- In un tier, le VM formano un **Compute Cluster**.

- Due modalità:
  - **replica**:
    - più VM fanno la stessa cosa (fault tolerance),
  - **collaborazione**:
    - VM cooperano su un task distribuito.

---

## Clusters Types
- Ci sono tre modi di organizzare i Compute Clusters:
  - High availability clusters
  - Load balancing clusters
  - Compute intensive clusters

---

### High Availability Clusters
- **High availability clusters**: sono cluster la cui funzionalità è cruciale per l'applicazione o per l'utente, le funzionalità dovrebbero essere disponibili in ogni momento


- Obiettivo: 
  - garantire disponibilità continua.

- Per raggiungere l'obietttivo creiamo delle *repliche* con la stessa logica

- Struttura:
  - **master** + **backup**.

- Funzionamento:
  - solo il master gestisce richieste,
  - backup inattivi → subentrano in caso di failure.

- Necessario:
  - replicare stato e dati.

![[Pasted image 20260405211031.png|500]]

---

### Load-Balancing Clusters
- **Load-Balancing Clusters**: l'obiettivo principale è supportare un carico che potrebbe aumentare in futuro, ottenere un elevato utilizzo del sistema e distribuire le richieste degli utenti.

- Obiettivo:
  - distribuire carico e scalare.

- Caratteristiche:
  - tutte le VM attive,
  - richieste distribuite (es. round robin).

- **Load balancer**:
  - assegna richieste alle VM,
  - può essere HW o SW.

- Se il carico aumenta si possono istanziare nuove VM 
- E' possibile creare un load balancer tier tra ogni tier del sistema

- Importante:
  - **sincronizzazione immediata** dei dati tra VM.

![[Pasted image 20260405211418.png|500]]

---

### Computing Intensive Clusters
- **Computing Intensive Clusters**: sono progettati per gestire ed elaborare grandi quantità di dati; i big data non possono essere contenuti in una singola macchina virtuale, per gestirli adottiamo un approccio *divide et impera*.
    - L'attività di analisi è suddivisa in sotto-attività più semplici (Job)
    - I dati vengono suddivisi in blocchi più piccoli, ognuno dei quali viene assegnato a un job
    - Un job e un blocco di dati vengono assegnati a un singolo server (un worker) per l'analisi
    - Il server esegue l'attività sui dati assegnati e restituisce il risultato a un collector
    - Il collector unisce i risultati

- Flusso:
  - worker → elaborano,
  - collector → aggrega risultati.

![[Pasted image 20260405211609.png|500]]

---

### Dynamic Adaptation
- Vantaggio chiave del cloud:
  - **scalabilità dinamica**.

- Strategia:
  - **horizontal scaling**:
    - aggiungere VM.

- Applicazione:
  - naturale in:
    - load balancing,
    - computing clusters,
  - in HA:
    - aumenta la ridondanza.


# 0C2 Application Design Methodology

---

### Cloud application design
- Le applicazioni cloud sono **sistemi distribuiti**:
  - composti da più componenti,
  - comunicano e scambiano dati.

- Problema:
  - sviluppo complesso,
  - soprattutto con molte funzionalità.

- Il modello tradizionale di sviluppo **non è adatto** → serve un nuovo approccio.

---

### Cloud application design requirements
- Requisiti fondamentali:

  - **Modularità**:
    - applicazione divisa in componenti.

  - **Interoperability**:
    - i componenti devono capirsi,
    - interfacce standard + formato dati condiviso.

  - **Scalability**:
    - aggiungere componenti facilmente e dinamicamente.

  - **Composability**:
    - componenti riusabili (e.g. interfaccia di login di Google),
    - self-contained con interfacce chiare. 

---

## Service-Oriented Architecture (SOA)

- **SOA**:
  - metodologia di design (non tecnologia),
  - applicazione = insieme di **servizi**.

- Servizi:
  - moduli indipendenti,
  - ciascuno con funzionalità specifiche.

- Caratteristiche delle applicazioni SOA:
  - altamente modulare,
  - distribuita,
  - indipendente da linguaggio/hardware.

- **Microservices**:
  - evoluzione di SOA,
  - servizi ancora più piccoli e indipendenti.

---

### SOA - Architecture
- Come si possono organizzare e mettere insieme i servizi?
- Si fanno comunicare con:
  - **message passing**.

- Messaggi:
  - formato ben definito (schema),
  - contengono dati o richieste.

- Vantaggio:
  - disaccoppiamento tecnologico,
  - basta rispettare lo schema.

- Ogni servizio ha:
  - descrizione (cosa fa),
  - interfaccia (input/output).

![[Pasted image 20260406105310.png|300]]

---

### SOA - Roles
- Due ruoli principali:

  - **Provider**:
    - offre funzionalità.

  - **Consumer**:
    - utilizza funzionalità.

- Un servizio può essere entrambi.

---

### SOA – Broker
- Problema:
  - il **consumer** inizialmente non conosce:
    - indirizzo,
    - interfaccia del provider.

- Soluzione:
  - introduzione del **Broker**:
    - intermediario tra servizi,
    - mantiene un **catalogo/registry dei servizi**.

- Funzionamento:
  - ogni servizio (provider) **si registra** nel broker:
    - pubblica funzionalità offerte,
    - espone descrizione (interfaccia + formato messaggi).

  - il consumer:
    - interroga il broker per una funzionalità,
    - ottiene:
      - indirizzo del provider,
      - descrizione del servizio (→ interoperabilità).

- Assunzione:
  - **indirizzo e schema del broker sono noti a tutti**.

- Dopo la discovery:
  - il consumer **comunica direttamente** con il provider (il broker non è più coinvolto).

![[Pasted image 20260406105858.png|400]]

- Possibili più broker:
  - evitare bottleneck e single point of failure.

---

### SOA - Advantages
- **Loose coupling**:
  - modifica interna di un servizio senza impatto sugli altri.

- **Composability**:
  - servizi combinabili (un sistema puo essere assemblato combinando servizi esistenti).

- **Stateless communication**:
  - ogni richiesta indipendente.

---

### SOA - Scalability
- Broker facilita la scalabilita':
  - aggiunta/rimozione servizi dal registro.

- Statelessness:
  - facilita scalabilità e distribuzione.

---

## Web Services

- Implementazione pratica di SOA via web. 

- **Web Services (WS)**:
  - servizi accessibili via rete,
  - interoperabili.

- *web technology*: tutta la tecnologia standardizzata dal W3C, che definisce i servizi come un sistema software per fornire un'interazione interoperabile tra macchine su una rete
![[Pasted image 20260406110757.png|300]]

---


### World Wide Web
- In origine il **WWW** era:
  - insieme di siti web + protocolli base.

- Evoluzione:
  - **Web 2.0** → sistemi più complessi,
  - supporto anche a comunicazione **machine-to-machine**.

- I **Web Services (WS)**:
  - sono l’applicazione del paradigma **SOA** sul Web.

---

### Uniform Resource Identifier (URI)
- Il Web si basa su 3 pilastri (standard W3C):

1. **URI / URL**
   - identificano una risorsa fisica o astratta tramite una stringa di caratteri compatta.
   - Struttura:
     - protocollo (es. HTTP),
     - host (IP o dominio),
     - porta (default se omessa),
     - path della risorsa.

![[Pasted image 20260406111002.png]]

---

2. **HTTP**
   - protocollo applicativo client-server,
   - modello **request/response**,
   - trasporta dati nel **payload**,
   - non definisce la struttura dei dati.

![[Pasted image 20260406111111.png|500]]

---

3. **Encoding dei dati**
   - serve per dare struttura ai messaggi cosi che siano chiari per entrambe le parti,
   - nel Web: HTML,
   - nei WS: **XML** (più adatto per dati strutturati).

---

### XML
- Un documento **XML** ha una struttura **gerarchica (ad albero)** composta da elementi.

- Un **elemento**:
  - è definito da:
    - **start-tag** `<tag>`
    - **end-tag** `</tag>`

- Il documento:
  - ha un **elemento radice (root)**,
  - può includere una **XML declaration** (info sul documento).

- Un **tag**:
  - è delimitato da `< >`,
  - può contenere **attributi** (coppie nome-valore).

![[Pasted image 20260406111353.png]]

---

- Vantaggi principali:

  - **Regole sintattiche**:
    - es. ogni tag aperto deve essere chiuso,
    - struttura ben formata (*well-formed*).

  - **XML Schema**:
    - definisce regole aggiuntive (tipi, vincoli, campi obbligatori),
    - permette di verificare la correttezza (*validazione*).

- Risultato:
  - documenti controllabili automaticamente,
  - maggiore **interoperabilità**,
  - formato adatto per definire **struttura dei messaggi**.

---


### WS Interaction
- Un **Web Service (WS)** ha un’interfaccia descritta tramite **Web Service Description Language** (*WSDL*):
  - formato machine-readable,
  - definisce operazioni e formato dei messaggi.


- **WSDL** è uno standard che specifica il formato dei messaggi tra il broker e il consumer e tra il broker e il producer  
- Il service consumer e il provider interagiscono invece utilizzando il **Simple Object Access Protocol (SOAP)**, che fornisce un formato standard per i messaggi

- Comunicazione:
  - **broker ↔ servizi** → WSDL (descrizione),
  - **consumer ↔ provider** → **SOAP** (messaggi).

![[Pasted image 20260406112301.png|400]]

---

### SOAP
- **SOAP**:
  - standard per scambio dati,
  - basato su **XML** + **HTTP**.

- Struttura messaggio:
  - **Envelope**:
    - **Header** → metadati, sicurezza,
    - **Body** → payload (informazioni da scambiarsi) + eventuali errori (*fault*).

![[Pasted image 20260406112526.png|300]]

---

### SOAP Message
- **Request**:
  - contiene:
    - risorsa richiesta,
    - parametri.

![[Pasted image 20260406112554.png]]

- **Response**:
  - contiene:
    - risultato,
    - oppure errore (*fault*).

![[Pasted image 20260406112625.png]]

---

### SOAP Binding
- SOAP usa HTTP:

  - **GET**:
    - request non SOAP,
    - response SOAP.

  - **POST**:
    - request e response SOAP.

---

### WSDL
- **WSDL** descrive l'interfaccia e l'insieme delle operazioni supportate da un servizio web in un formato standard.
- Consente agli utenti di comprendere cosa può fare un servizio, dove si trova e come può essere richiamato.

---

### WSDL – struttura
- Un messaggio **WSDL** è un documento XML diviso in due sezioni:

  - **Service Interface Definition**:
    - fornisce informazioni sul servizio in modo astratto,
    - include:
      - tipi di dati (*types*),
      - messaggi scambiati tra requestor e provider (*messages*),
      - operazioni disponibili (*portType*).

  - **Service Implementation Definition**:
    - definisce come invocare concretamente le operazioni tramite HTTP,
    - include:
      - modalità di trasferimento dei messaggi (*binding*),
      - modalità di accesso al servizio (*service*).

![[Pasted image 20260406113241.png|400]]

---

### WSDL - Componenti
- **WSDL Type** può essere utilizzato per definire il tipo di dati usati come parametri di un servizio specifico  
- **WSDL Messages** è usato per definire i messaggi scambiati tra il client e il Web Service  
- **WSDL PortType** può essere utilizzato per collegare messaggi di input e output in un’unica operazione logica  
- **WSDL Binding** è usato per specificare come i messaggi associati a una operazione (PortType) vengono scambiati  
- **WSDL Service** è usato per specificare come l’operazione viene invocata concretamente, cioè l’URI associato al servizio  

---

### REST
- L'archittettura SOAP e' complessa e non adatta a progetti di piccole e medie dimensioni.

- REST e' un alternativa a SOAP:
  - più semplice e leggera,
  - offre un set minimale di funzionalita'.

- Basata su HTTP:
  - usa direttamente i metodi standard (CRUD).

![[Pasted image 20260406113745.png|400]]

- Caratteristiche:
  - risorse identificate da URI,
  - operazioni tramite HTTP,
  - dati in JSON/XML.

---

##### REST Basics
- **CRUD via HTTP**:
  - `GET` → read  
  - `POST` → create  
  - `PUT` → update  
  - `DELETE` → delete  

- **Trasmissione dati**:
  - query parameters o body.

- **Proprietà**:
  - accesso uniforme via URI,
  - sistema leggero,
  - supporta diversi formati dei dati come JSON, XML o testo semplice,
  - meno complesso di SOAP.


![[Pasted image 20260406113858.png|500]]

---

### JSON
- Formato leggero per dati:
  - collezione di coppie **chiave-valore**,
  - liste ordinate, 
  - human readable.

- Più semplice e veloce di XML.

---

### CRUD
- Operazioni base dei database relazionali: 
  - Create, Read, Update, Delete.

- Mappate su:
  - SQL,
  - HTTP (REST).



# 0C4 Scalable Applications

### Recap: Architettura delle applicazioni Cloud
- Le **cloud applications** sono sistemi distribuiti:
  → l’applicazione è composta da più funzionalità distribuite su diverse VM

- Le VM sono organizzate in **tiers** (livelli):
  → ogni tier contiene più VM che replicano la stessa funzionalità  
  → obiettivo: **alta disponibilità + scalabilità**

- Flusso delle richieste:
  → il client invia richieste al **frontend tier**  
  → il frontend le inoltra ai **backend tiers**

![[Pasted image 20260411134418.png|300]]

---

### Recap: Metodologia di design
- Si adotta una **Service-Oriented Architecture (SOA)**:
  → ogni VM ospita uno o più **servizi indipendenti**
  → i servizi comunicano tramite **message passing**

- Due approcci principali per lo scambio di messaggi:
  - **SOAP**
  - **REST**

![[Pasted image 20260411135219.png|500]]

- **REST**:
  → più semplice  
  → usato principalmente tra **client e frontend**

- **SOAP**:
  → in disuso, ma ancora usato tra **frontend e backend**

---

### Comunicazione Request-Reply
- Sia SOAP che REST usano **request-reply**

#### Problema 1: comunicazione sincrona
- Il client:
  → invia richiesta  
  → **rimane bloccato** finché non arriva la risposta  

→ questo crea **time coupling**

✔ Vantaggio:
- affidabile  
- la risposta conferma la ricezione

#### Problema 2: comunicazione diretta
- Client ↔ Server comunicano direttamente (nessun intermediario)

→ problema nel cloud:
- le VM possono essere create/distrutte dinamicamente  
- potrei voler gestire una richiesta con una VM **che ancora non esiste**

![[Pasted image 20260411135416.png|300]]

---

### Space / Time Coupling

- Il paradigma request-response va bene per:
  → **client ↔ frontend**
  → perché è semplice e tollera coupling

- Non va bene per:
  → **frontend ↔ backend**
  → perché il numero di VM varia (scalabilità, replica)

---

### Obiettivo: disaccoppiare il sistema

Si introduce un intermediario (**man in the middle**) per ottenere:

#### 1. Space Uncoupling
- Mittente e destinatario:
  → **non devono conoscersi**
- Vantaggio:
  → una richiesta può essere gestita anche da una VM creata dopo

#### 2. Time Uncoupling
- Mittente e destinatario:
  → **non devono essere attivi nello stesso momento**
- Il sender:
  → invia e continua (non blocca)

---

### Come si ottiene

- **Space uncoupling**:
  → introducendo un intermediario (no comunicazione diretta)

- **Time uncoupling**:
  → usando comunicazione **asincrona**
  → il middleware si occupa della consegna

---

### Comunicazione Message-Oriented
- Si introduce un **Message Bus** (intermediario)

Due approcci principali:
- **Message Broker**
- **Message Queue**

![[Pasted image 20260411140319.png|300]]

---

## Message Broker
- Sistema di dispatch basato su **Publish/Subscribe**

- Funzionamento:
  → i **publisher** inviano messaggi  
  → i **subscriber** ricevono quelli di interesse  

- I messaggi sono associati a un **topic**

→ comunicazione: **one-to-many**

![[Pasted image 20260411140745.png|300]]

---

### Tipi di Subscription

- **Channel-based**
  → si sottoscrive un canale  
  → si ricevono tutti i messaggi del canale

- **Topic-based**
  → ogni messaggio ha un campo *topic*  
  → si filtra per topic  
  → simile al channel-based, ma più esplicito

- **Type-based**
  → basato sul tipo di evento (o sottotipo)

---

## Message Queue
- Approccio più usato

- Idea:
  → i messaggi vengono inseriti in **code (queue)**

- Funzionamento:
  → il producer inserisce un messaggio  
  → il consumer lo consuma quando disponibile  

- Se il consumer è pronto:
  → riceve subito  
- Altrimenti:
  → il messaggio resta in coda

![[Pasted image 20260411141234.png|300]]

---

### Operazioni principali

- **Send**
  → inserisce un messaggio nella coda

- **Blocking Receive**
  → il consumer aspetta finché arriva un messaggio

- **Non-blocking Receive (polling)**
  → controlla se c’è un messaggio

- **Notify**
  → il sistema notifica il consumer

---

### Messaggi
- Un messaggio contiene:
  - **destination** → identificatore della coda
  - **metadata** → priorità, modalità consegna, ecc.
  - **body** → contenuto (opaco)

- Ordine:
  → tipicamente **FIFO**  
  → a volte con priorità

- Persistenza:
  → salvati su disco  
  → non si perdono finché non consumati

---

### Message Transformation
- Possibile modificare i messaggi:
  → es. formato, endianess, rappresentazione

→ utile per gestire **eterogeneità**

---

### Scalabilità
- Problema:
  → una sola queue = **bottleneck + single point of failure**

- Soluzione:
  → implementazione **replicata / distribuita**
  → spesso la messaging layer è un **tier dedicato**

![[Pasted image 20260411144656.png|300]]

- Vantaggi:
  → supporta numero variabile di VM  
  → elimina il blocco request-response

---

### Implementazioni

- **Centralizzata**
  → singola VM  
  → semplice ma non scalabile (inoltre single point of failure)

- **Distribuita**
  → più nodi coordinati  
  → più complessa  
  → **scalabile + resiliente**

- Standard importante:
  → **AMQP (Advanced Message Queuing Protocol)**

---

## Data Replication

- Ogni tier replica i dati:
  → per garantire continuità in caso di failure

- Obiettivo:
  → le repliche devono comportarsi come l’originale

- La sincronizzazione avviene tramite:
  → **scambio di messaggi**

---

### Problema: dataset grandi
- Solo messaggi → inefficiente

Soluzione:
- usare un **database condiviso (nuovo tier)**  
- i messaggi restano per coordinamento

![[Pasted image 20260411145547.png|400]]

---

### Requisiti data replication

- **Replication Transparency**
  → invisibile all’utente

- **Consistency**
  → tutte le repliche danno lo stesso risultato

- **Resiliency**
  → tolleranza ai guasti delle VM  
  ⚠ si assume: niente network partition

---

### System Model

- Il sistema gestisce **oggetti logici** (file, record, ecc.)

- Ogni oggetto ha più copie:
  → chiamate **repliche**

- Ogni replica è gestita da un:
  → **replica manager** (tipicamente una VM)

- Le repliche sono:
  → **macchine a stati**
  → (si replica anche lo stato, non solo i dati)

- Gli aggiornamenti sono:
  → **recoverable** (recuperabili dopo failure)

![[Pasted image 20260411150031.png|300]]

---

### Gestione delle richieste (5 fasi)

1. **Request**
   - Tipi:
     - *Query* → solo lettura  
     - *Update* → modifica stato
   - Il frontend inoltra ai replica manager la richiesta

2. **Coordination**
   - I replica manager si coordinano
   - Decidono:
     → chi esegue  
     → se aspettare per consistenza

3. **Execution**
   - Esecuzione (spesso **tentativa** → rollback possibile)

4. **Agreement**
   - Confronto risultati tra repliche
   - Se coerenti → commit

5. **Response**
   - Invio risposta al frontend

---

→ Nota:
- Questo è uno schema generale  
- esistono varianti nei protocolli reali


### Group / Multicast Communication
- La comunicazione tra replica manager avviene tramite **multicast**:
  → un nodo comunica con un gruppo di nodi  
  → usato per implementare la **replicazione**

- Esistono diversi tipi:
  → differiscono per **garanzie** e **complessità**  
  → più garanzie ⇒ maggiore complessità

![[Pasted image 20260411150830.png|400]]

---

### Tipi principali di Multicast
- **Reliable Multicast**
- **Total Order Multicast**
- **View-Synchronous Communication**

---

##### Reliable (Atomic) Multicast
- Più semplice (meno garanzie)

- Garantisce:
  → il messaggio viene consegnato **prima o poi**

- NON garantisce:
  → ordine  
  → tempo di consegna  

---

##### Total Order Multicast
- Garantisce:
  → tutti i nodi ricevono i messaggi **nello stesso ordine**

- NON garantisce:
  → quando arrivano

→ possibile:
- nodo A ha più messaggi di nodo B  
- ma l’ordine è coerente

---

##### View-Synchronous Communication
- Più complesso

- Garantisce:
  → ordine  
  → nessun nodo rimane indietro

- NON garantisce:
  → tempo massimo di consegna

---

### Primary-Backup Replication
- Modello **passivo**
- Obiettivo: **fault tolerance**

- Struttura:
  → 1 **primary**  
  → N **backup**

- Il frontend comunica solo con il primary

- Il primary:
  → esegue richieste  
  → propaga aggiornamenti

- Se fallisce:
  → un backup diventa primary

![[Pasted image 20260411151641.png|300]]

⚠ Svantaggio:
- spreco risorse (backup inattivi che non fanno niente)

---

##### Primary-Backup: gestione richieste

1. **Request**
   - ID univoco (evita duplicati)

2. **Coordination**
   - il primary:
     → esegue in ordine  
     → controlla duplicati  
   - nessuna coordinazione

3. **Execution**
   - esecuzione + salvataggio risposta

4. **Agreement**
   - Query → risposta immediata  
   - Update → propagazione ai backup + ACK  
   - sufficiente: multicast atomico

5. **Response**
   - risposta dal primary

---

### Active Replication
- Altro possibile metodo per garantire availability 
- Tutti i replica manager sono attivi

- Il frontend:
  → multicast a tutti

- Ogni replica:
  → esegue e risponde

![[Pasted image 20260411151816.png|400]]

✔ Vantaggio:
- alta disponibilità

⚠ Svantaggio:
- spreco risorse (calcolo duplicato)

---

##### Active Replication: gestione richieste

1. **Request**
   - multicast con ID

2. **Coordination**
   - implicita nel multicast  
   - serve **total order multicast**

3. **Execution**
   - tutte le repliche eseguono

4. **Agreement**
   - non necessario

5. **Response**
   - tutte rispondono  
   - si usa la prima risposta

---

### Passive / Active Approaches
- Gli approcci **passive** e **active** puntano a garantire **alta disponibilità**

- **Passive (primary-backup)**:
  → solo il primary gestisce le richieste  
  → i backup NON partecipano  
  → tutto il carico è sul primary  

- **Active**:
  → tutte le repliche gestiscono le richieste  
  → elaborazione **ridondante**

---

### Limite
→ alta disponibilità ma **scarsa scalabilità / utilizzo inefficiente**

---

### Nuovo approccio
Obiettivo: **alta disponibilità + scalabilità**

- Idee chiave:
  → più replica manager gestiscono richieste **in parallelo** (non uno solo o tutti sulla stessa richiesta)  
  → gli aggiornamenti NON sono immediati  

- Aggiornamenti:
  → propagati **in ritardo (lazy)**  
  → il client riceve risposta **subito** (prima della propagazione)

→ questo modello è la **Gossip Architecture**

---

### Gossip Architecture
- I replica manager:
  → scambiano periodicamente **gossip messages** per inoltrare gli aggiornamenti che arrivano dai clients

- I client:
  → assegnati a specifici **frontend (FE)** per bilanciamento  
  → possono cambiare in caso di crash  

---

##### Aggiornamenti (lazy)
- Gli update:
  → NON vengono propagati subito  
  → vengono inviati in background

✔ Vantaggio:
- non si blocca il sistema

⚠ Problema:
- possibili inconsistenze temporanee

---

##### Tipi di operazioni
- **Query** → sola lettura  
- **Update** → modifica stato (non legge stato)

---

##### Garanzie del sistema

- **Consistenza per client**
  → ogni client vede sempre una storia coerente con le sue operazioni  

- **Consistenza tra repliche (rilassata)**
  → repliche possono divergere temporaneamente  

→ modello: **Sequential Consistency**

---

##### Intuizione
- stesso client:
  → vista coerente nel tempo  

- client diversi:
  → possibili differenze temporanee  

---

![[Pasted image 20260411152551.png|300]]

---

### Gossip: gestione richieste

1. **Request**
   - inviata a un solo replica manager

2. **Coordination**
   - il replica manager:
     → NON esegue subito  
     → verifica di essere aggiornato rispetto alla vista del client  
     → se necessario, attende gossip da altri nodi  

3. **Execution**
   - esecuzione locale

4. **Agreement**
   - aggiornamenti scambiati tramite gossip  
   - modalità **lazy** (batch o periodica)

5. **Response**
   - Query → risposta dopo esecuzione  
   - Update → risposta immediata  

---

✔ Vantaggi:
- meno overhead di comunicazione  
- nessun blocco per propagazione  

⚠ Svantaggi:
- inconsistenza temporanea  

---

### Timestamps
- Usati nella fase di **coordination**

- Servono per:
  → mantenere l’ordine delle richieste  
  → verificare la coerenza della vista del client  

---

##### Meccanismo

- Il FE mantiene un **vector timestamp**

- Invia al replica manager:
  → **prev** (stato visto dal client)

- Il replica manager risponde con:
  → **new** (stato aggiornato)

- Il FE:
  → fa il **merge** dei timestamp

---

##### Intuizione
- Il timestamp rappresenta:
  → “quanto è aggiornata la vista del client”

- Serve per controllare:
  → se il replica manager può servire la richiesta  

---

##### Ottimizzazione
- Se:
  → client ↔ FE ↔ replica manager sono **fissi**

→ non serve il controllo sui timestamp

---

![[Pasted image 20260411152939.png|300]]

---

### Processing Query
- Obiettivo:
  → restituire dati almeno aggiornati quanto **prev**

- Condizione:
  → se $valueTS < prev$ i valori che si hanno sono piu vecchi di quelli forniti nella query

→ la query viene **rimandata** fino a che non arrivano dai aggiornati

- Quando la condizione è soddisfatta:
  → esecuzione  
  → ritorno di $valueTS$

---

### Processing Update
- Step:

1. Controllo duplicati (ID richiesta)

2. Se nuova:
   → genera nuovo timestamp (incremento di prev)  
   → salva nel log locale  

3. Condizione:
   → $(prev \leq valueTS)$

- Se NON soddisfatta:
  → update rimandato  
  → rieseguito dopo gossip

---

### Replica Manager
![[Pasted image 20260411145349.png|600]]

---

### Esempio: ZooKeeper
- Servizio distribuito ad alta disponibilità usato per scambiare dati tramite i servizi

- Utilizzi:
  → configurazione  
  → naming  
  → coordinamento servizi  

- Proprietà:
  → sistema replicato  
  → richiede maggioranza attiva  
  → nodi crashati esclusi automaticamente  

- Modello:
  → primary-backup  

- Protocollo:
  → Zab (atomic broadcast)





# 0C6. Geographically Distributed Applications  

### Global-scale applications
- Nelle lezioni precedenti si assumeva:
  → niente **network partition**  
  → tutte le VM nello stesso datacenter (rete affidabile)

- Questo NON vale per applicazioni globali:
  → milioni di utenti  
  → necessità di più **datacenter distribuiti**

- Problema:
  → anche con molta potenza in un solo punto  
  → il collo di bottiglia diventa **Internet**

→ soluzione:
- distribuire datacenter nel mondo

---

##### Strategie
- più provider Internet → ridondanza  
- datacenter distribuiti per regione  
- richieste inviate al datacenter più vicino  

✔ vantaggio:
- bassa latenza  
- tolleranza ai guasti  

---

### Load Balancing
- Obiettivo:
  → controllare dove inviare le richieste

- Architettura a **due livelli**:

1. **Global Load Balancing**
   → sceglie il datacenter

2. **Local Load Balancing**
   → sceglie la VM nel datacenter

---

##### Politiche di scheduling
- **Locale**:
  → scalabilità (bilanciare carico)

- **Globale**:
  → dipende dall’applicazione  
  → es:
    - motore di ricerca → latenza  
    - social/video → banda  

---

##### Implementazione
- software (es. HAProxy)  
- hardware dedicato  

---

### Global Load Balancing via DNS
- Prima della richiesta:
  → il client usa il **DNS** per ottenere un IP

- Molti servizi:
  → hanno più IP (ridondanza)

---

##### Approccio base
- DNS restituisce più record (A / AAAA)
- il client sceglie uno

✔ semplice  
⚠ poco controllo  

---

##### Problemi
- scelta casuale  
- nessuna informazione su distanza  
- aggiornamenti DNS lenti (ore)

---

##### Miglioramento
- DNS geolocalizzato  
→ ma controllo ancora **grossolano**

---

##### Soluzione avanzata
→ uso di **Virtual IP (VIP)**

![[Pasted image 20260417140409.png|400]]

---

### Virtual IP
- Un **Virtual IP**:
  → non è associato a una singola macchina  
  → è condiviso tra più dispositivi  

- Per il client:
  → sembra un IP normale

---

##### Organizzazione
- più VIP per un servizio  
- ogni VIP associato a una **regione**

- in ogni regione:
  → più datacenter  

- ISP:
  → instrada verso il load balancer più vicino

---

##### Architettura
- DNS regionale → restituisce VIP  
- Global Load Balancer → riceve traffico  
- instrada verso datacenter  

---

### Packet Encapsulation
- Il load balancer:
  → incapsula la richiesta in un nuovo pacchetto e lo invia ad un datacenter

- Il datacenter:
  → decapsula e processa come se fosse stato ricevuto direttamente da un datacenter

---

##### Tecnica
- **GRE (Generic Routing Encapsulation)**:
  → incapsula un pacchetto IP dentro un altro pacchetto ip

- Outer packet:
  → contiene destinazione (datacenter)

![[Pasted image 20260417140903.png|500]]

---

### Sistemi geograficamente distribuiti
- Problemi principali:

1. **Banda limitata**
   → sincronizzazione lenta  

2. **Bassa affidabilità**
   → frequenti partition  

---

→ Conseguenza:
- i metodi tradizionali NON funzionano

---

### ACID
- Sistemi tradizionali (DB relazionali):
  → garantiscono sempre consistenza

- Proprietà:
  - Atomicity  
  - Consistency  
  - Isolation  
  - Durability  

→ se non c’è consistenza:
- il sistema NON è disponibile  

---

### CAP Theorem
- Non si possono avere contemporaneamente:

- **C** → Consistency  
- **A** → Availability  
- **P** → Partition tolerance  

→ massimo **2 su 3**

---

##### Interpretazione
- non significa che la terza proprietà sparisce  
- ma non può essere **perfetta**

---

![[Pasted image 20260417143303.png]]

---

### BASE
- Approccio alternativo ad ACID

- Significato:
  - **Basically Available**
  - **Soft State**
  - **Eventual Consistency**

---

##### Idea
- privilegia:
  → Availability + Partition tolerance  

- compromette:
  → Consistency  

---

##### Proprietà
- il sistema è sempre disponibile  
- può essere temporaneamente inconsistente  
- converge nel tempo (**eventual consistency**)

---

##### Aggiornamenti
- **ACID**:
  → sincroni (bloccanti)

- **BASE**:
  → asincroni (background)  
  → tramite **anti-entropy protocol**

---

##### Problemi
- inconsistenza temporanea  
- possibili **conflitti**

---

##### Risoluzione conflitti
- es:
  → ultimo timestamp vince  

---

##### Query
- in entrambi:
  → risposta basata su stato locale  

---

![[Pasted image 20260417092111.png]]

---

##### Vantaggi / Svantaggi
✔ gestisce partition  
✔ bassa latenza  

⚠ non adatto a sistemi che richiedono forte consistenza  

---

### Bayou
- Architettura **eventually consistent**

- Obiettivo:
  → alta disponibilità  
  → consistenza debole (sequenziale)

---

##### Meccanismo
- replica manager:
  → scambiano aggiornamenti (anti-entropy)

- uso di:
  → **conflict resolution**

---

### Bayou: operazioni

- Update:
  → applicato subito (locale)  
  → marcato come **tentative**

- Update committed:
  → definitivo  
  → non modificabile  

---

##### Ordinamento
- committed:
  → ordine globale  

- tentative:
  → ordine locale (timestamp)

---

![[Pasted image 20260417145219.png|400]]

---

### Primary Commit Scheme
- Un nodo (primary):
  → decide quando commitare

- Se il primary è down:
  → niente commit  
  → solo update **tentativi**

- Il sistema:
  → continua a funzionare  

- Quando torna:
  → converte update tentativi in committed  

---

### Conflict Detection & Resolution

- **Dependency Check**
  → query che verifica condizioni  
  → se fallisce → conflitto  

- **Merge Procedure**
  → risolve il conflitto  

---

✔ proprietà:
- devono essere **deterministiche**  
→ tutte le repliche convergono  

---

### Performance
- Dipende dalla frequenza di anti-entropy

- Più frequente:
  → meno inconsistenza  
  → più overhead  

- Meno frequente:
  → più inconsistenza  
  → meno overhead  

→ trade-off fondamentale




# 0D1. Cloud Platforms Technologies 


### Recap
- Il cloud (finora):
  → infrastruttura che permette di creare **VM**

- L’infrastruttura:
  → progettata e gestita dal **cloud provider**  
  → vende risorse virtualizzate  

- Sopra le VM:
  → girano le **cloud applications** (dei clienti)  
  → offrono servizi agli utenti finali  

---

##### Problema
- Come si costruisce una infrastruttura:
  → capace di gestire **molte VM su larga scala**?

- Gestione manuale:
  → NON fattibile  

→ serve:
- un sistema **automatico (self-managed)**

---

### Cloud Infrastructure
- Le tecnologie di virtualizzazione moderne:
  → permettono VM su hardware standard

- Una **Cloud Infrastructure** è:
  → un insieme di server  
  → ciascuno con un **hypervisor (HV)**  
  → connessi via LAN + Internet  
  → ospitati in un datacenter  

---

##### Proprietà
- usa **hardware non modificato**
- non richiede hardware speciale  

---

### Cloud Platform
- Una **Cloud Platform** è:
  → un sistema distribuito che controlla gli hypervisor  

- Funzioni:
  → crea/distrugge VM  
  → gestisce risorse  

- Espone:
  → interfaccia di gestione (per utenti o software)

→ abilita il modello **IaaS**

---

### Architettura generale
- Server connessi via LAN ad alta velocità (>10Gbps)

- Ogni server:
  → OS su bare metal  
  → hypervisor sopra (oppure bare-metal HV)

---

##### Componenti

- **Agent (su ogni server)**
  → controlla risorse locali (tramite HV)

- **Controller**
  → gestisce l’intero sistema  
  → comunica con gli agent  

![[Pasted image 20260417154323.png|500]]

---

### Implementazioni
- Proprietarie o open-source  

- Non esiste uno standard:
  → ma architetture simili  

→ esempio principale:
- **OpenStack**

---

## OpenStack
- Piattaforma open-source per **IaaS**

- Origine:
  → progetto NASA  
  → oggi supportato da molte aziende  

- Uso:
  → cloud privati  
  → multi-site  

![[Pasted image 20260417154548.png|300]]

---

### OpenStack: caratteristiche
- Funziona su:
  → hardware standard  
  → qualsiasi Linux os
  → diversi hypervisor  

- Gestisce:
  → VM  
  → rete virtuale  
  → storage virtuale  

---

### OpenStack Nodes
- Ogni server con OpenStack:
  → **OpenStack Node**

---

##### OpenStack Instance
- Insieme di nodi:
  → forma una **istanza OpenStack**

- Tipi di nodi:
  - **Controller**
    → coordina tutto  
  - **Compute nodes**
    → eseguono VM  

![[Pasted image 20260417155543.png|300]]

---

### OpenStack Architecture

- Interfacce per controllare le risorse virtualizzate:
  → Web dashboard  
  → CLI  
  → **REST API**

![[Pasted image 20260417155604.png]]

---

##### Modularità
- Architettura altamente **modulare**

- Ogni funzionalità:
  → è un **servizio indipendente**

- Ogni servizio:
  → espone REST API  
  → comunica via **message queue**

![[Pasted image 20260417155744.png]]

---

##### Struttura a layer
- Servizi divisi in 4 livelli:
  - livello basso → essenziali  
  - livello alto → opzionali  

![[Pasted image 20260417160335.png]]

---

##### Deploy
- installazione personalizzabile  
- servizi su:
  → controller  
  → compute nodes  

- servizi di supporto:
  → database  
  → message broker  

![[Pasted image 20260417160551.png|200]]

---

### Comunicazione tra servizi
- Tre modalità:

1. **Message broker**
   → comunicazione asincrona  

2. **REST API**
   → chiamate dirette  

3. **Database**
   → scambio via stato condiviso  

![[Pasted image 20260417160902.png|500]]

---
## Main Services

### Keystone

- Servizio di **identity management**

- Funzioni:
  → autenticazione  
  → autorizzazione  
![[Pasted image 20260417163043.png|300]]
---

##### Modello
- Risorse:
  → organizzate in **projects**

- Accesso:
  → per utente e progetto  

---

##### Token-based auth
1. login (user/password)
2. riceve **token**
3. usa token per servizi  

- ogni servizio:
  → valida il token  

![[Pasted image 20260417163148.png|500]]

---

### Nova
- Servizio di gestione **VM**

- NON implementa virtualizzazione:
  → usa hypervisor esistenti  

---

##### Componenti
- **Controller module** (nova controller): gestisce richieste dall'utente di creazione e distruzione di VM e invia i comandi ai compute node
- **Compute module** (nova agent): riceve i comandi dal nova controller e li traduce in istruzioni per l'hv

![[Pasted image 20260417163402.png]]

---

##### Controller (Nova) Subcomponents

- **Nova-API**  
→ espone le **REST API**  
→ utilizzata da utenti e altri servizi per inviare richieste  
  
- **Nova-Conductor**  
→ gestisce la **logica di controllo**  
→ coordina le operazioni tra i vari componenti  
  
- **Nova-Scheduler**  
→ decide **dove creare la VM**  
→ seleziona il compute node in base a:  
- risorse disponibili  
- stato dei nodi  
  
- **Nova-Network**  
→ fornisce funzionalità di rete base  
→ oppure interagisce con servizi di rete più avanzati (es. Neutron)  
  
- **Nova-Consoleauth** e **Nova-Novncproxy**  
→ permettono l’accesso remoto alle VM  
→ forniscono una **console web** per gli utenti  


- Tutti i componenti:  
→ comunicano tramite **message queue**

---

##### Compute (Nova)
- riceve comandi dal controller
- interagisce con hypervisor inoltrando i comandi tradotti

![[Pasted image 20260417163928.png|500]]

---

### Nova – VM Creation Workflow
- Workflow di creazione di una VM in OpenStack:

- Quando un utente richiede la creazione di una VM:

1. **Nova-API**
   → riceve la richiesta  
   → la inoltra a **Nova-Conductor**

2. **Nova-Conductor**
   → inoltra la richiesta al **Nova-Scheduler**

3. **Nova-Scheduler**
   → seleziona il compute node più adatto  
   → verifica:
     - risorse disponibili  
     - stato dei nodi  

4. **Configurazione rete**
   → Nova-Conductor contatta il servizio di rete  
   → viene configurata la rete della VM  

5. **Nova-Compute**
   → la richiesta viene inviata al compute node selezionato  
   → il modulo **Nova-Compute** esegue l’operazione  

6. **Hypervisor**
   → crea effettivamente la VM  

![[Pasted image 20260417163958.png|500]]

---

### Nova Scheduling Strategy & Overcommitment

##### Scheduling
- Il **Nova-Scheduler** è altamente configurabile

- Funzioni:
  → bilanciamento carico  
  → selezione nodi in base a policy  

---

##### Esempio policy
- minimizzare numero di server con VM Windows  
  → ridurre costi di licenza  

---

##### Processo
1. **Filtering**
   → elimina nodi non validi:
     - risorse insufficienti  
     - caratteristiche mancanti  

2. **Ranking**
   → ordina i nodi rimanenti  

![[Pasted image 20260417164350.png|300]]

---

##### Obiettivo provider
- massimizzare utilizzo risorse  
→ più VM su meno server  

---

##### Problema
- se tutte le VM usano risorse insieme:
  → **hotspot**  
  → degrado performance  

---

##### Overcommitment
- definizione:
  → rapporto tra risorse virtuali e fisiche  

---

##### Esempi
- CPU:
  → fino a ~16 vCPU per 1 CPU reale  

- Overcommitment = 1:
  → 1 vCPU per CPU reale  

---

##### RAM
- più limitato (~1.5)  
→ page fault molto costosi  

---

##### Trade-off
- più overcommit:
  → più profitto  
  → meno performance  

- meno overcommit:
  → migliore qualità  
  → meno utilizzo risorse  

---

→ necessario tuning accurato

---

### Glance
- Servizio di gestione **immagini VM**

---

##### Funzione
- Le VM:
  → create a partire da **immagini**

- Immagini:
  → OS preinstallato  
  → configurazioni già pronte  

---

##### Personalizzazione
- possibile includere:
  → software preinstallato (es. web server)

---

##### Ruolo
- gestisce:
  → repository immagini  
  → metadati  

---

### Glance: componenti

- **Glance**
  → espone REST API  
  → gestisce metadati (DB)

- **Glance Storage**
  → memorizza immagini  
  → supporta diversi backend  

![[Pasted image 20260417164542.png|300]]


### Neutron
- **Neutron** è il componente di **network management** di OpenStack

- Le VM:
  → necessitano di una **rete virtuale** per comunicare  

- Per garantire isolamento:
  → vengono create **Virtual Networks separate**  
  → VM appartenenti a tenant diversi **non possono comunicare**

---

##### Funzione principale
- Neutron:
  → gestisce l’intera **infrastruttura di rete virtuale**  
  → permette la creazione di Virtual Networks tra VM anche su **compute node diversi**

- La rete fisica locale:
  → viene usata come **infrastruttura sottostante (fabric)**  
  → sopra di essa vengono costruite le reti virtuali

---

##### Intuizione (corretta)
- VM appartenenti allo **stesso Virtual Network**:
  → possono comunicare tra loro  

- VM appartenenti a **Virtual Networks diversi**:
  → sono isolate (a meno di routing esplicito)

![[Pasted image 20260418102022.png]]

---

### Neutron: Subcomponents
- Componenti principali:
  - **Neutron-Server**
  - **Neutron-Agent**

---

##### Neutron-Server
- installato sul **controller node**

- Responsabilità:
  → gestione globale delle Virtual Networks  
  → coordinamento degli agent sui compute node  
  → esposizione delle **REST API** per utenti e servizi  

---

##### Neutron-Agent
- installato su ogni **compute node**

- Responsabilità:
  → gestione traffico delle VM locali  
  → inoltro traffico tra compute node  
  → implementazione dell’isolamento tra reti virtuali  

---

##### Comportamento del traffico
- traffico:
  → viaggia sulla rete fisica  
  → ma è **logicamente separato**

- distinzione:
  → pacchetti diversi (es. rosso / verde) → reti virtuali diverse  
  → pacchetti blu → traffico di controllo  

![[Pasted image 20260418102158.png]]

---

### Network Node
- Le Virtual Networks:
  → sono tipicamente **private**

- Per accesso a Internet:
  → serve un **Network Node**

---

##### Ruolo del Network Node
- nodo con doppia connessione:
  → rete interna OpenStack  
  → rete esterna (Internet)

---

##### Componenti principali

- **Neutron-L3-Agent**
  → gestisce routing Layer 3  
  → instrada traffico tra:
    - reti virtuali  
    - rete pubblica  

- **Virtual Routers**
  → implementano:
    - routing  
    - NAT (Network Address Translation)

---

- **Neutron-DHCP-Agent**
  → assegna configurazione di rete alle VM:
    - IP  
    - DNS  

---

![[Pasted image 20260418102350.png]]

---

##### Proprietà importanti
- ogni VM:
  → connessa ad almeno una Virtual Network  

- ogni Virtual Network:
  → connessa ad almeno un router  

---

##### Accesso pubblico
- possibile assegnare:
  → **Floating IP**

→ permette:
- accesso diretto da Internet  

![[Pasted image 20260418102448.png|500]]

---

### Physical Network Infrastructure

- Infrastruttura tipica: 3 reti fisiche

1. **Management Network**
   → traffico OpenStack (controllo)

2. **Internal VM Network**
   → traffico tra VM  

3. **External Network**
   → accesso a Internet  

---

##### Note architetturali
- management + internal:
  → possono condividere la stessa LAN  

- solo il **Network Node**:
  → è connesso alla rete esterna  

- controller:
  → può essere connesso solo alla management network  

---

##### Virtualizzazione
- la rete fisica:
  → viene suddivisa in più reti virtuali  

- tramite:
  → **tagging dei pacchetti** (identificazione rete)

---

![[Pasted image 20260418103020.png|400]]

---

### Neutron Agent

- Problema:
  → come isolare le reti virtuali sulla stessa rete fisica?

→ soluzione:
- gestione tramite **Neutron Agent**

---

##### Caratteristiche
- altamente configurabile  
- supporta diverse tecnologie di forwarding  

---

##### Implementazione moderna
- utilizza:
  → **OpenVSwitch (OVS)**

---

##### Ruolo operativo
- il Neutron Agent:
  → programma OVS  
  → definisce il comportamento della rete  

---

##### Funzioni
- routing dei pacchetti  
- forwarding tra nodi  
- applicazione regole di isolamento  

---

##### Nota importante
- il comportamento della rete:
  → NON è fisso  
  → è dinamicamente configurato  

---

![[Pasted image 20260418103035.png|400]]
---

### OpenVSwitch (OVS)
- **OVS**:
  → switch virtuale distribuito  

- progettato per:
  → ambienti virtualizzati  

---

##### Funzioni
- filtering  
- routing  
- switching  
- manipolazione pacchetti  

---

##### Architettura
- ogni nodo:
  → ha una istanza OVS  

- controllo:
  → centralizzato (**SDN**)

---

- È un componente che gestisce il traffico seguendo un insieme di regole ricevute da un controller, può implementare qualsiasi regola e funzionalità di rete
![[Pasted image 20260418103304.png|300]]

---


### Software Defined Networking (SDN)
- **OVS (OpenVSwitch)** adotta il paradigma **SDN**:
  → la logica di rete è separata dall’hardware  
  → le regole vengono definite da un **controller centrale**  

- Ogni nodo OVS mantiene una **flow table**:
  → contiene:
    - condizioni di matching (es. IP, MAC, porta)
    - azioni da eseguire (forward, drop, modify)

- Funzionamento:
  → arriva un pacchetto  
  → viene confrontato con la flow table  
  → se trova un match → esegue l’azione  

- Se NON trova un match:
  → OVS contatta il controller  
  → riceve una nuova regola  
  → aggiorna la tabella  

- Comunicazione controller–OVS chiamato:
  → protocollo **OpenFlow**

- Intuizione:
  → gli switch sono “esecutori”  
  → il controller decide il comportamento della rete  

---

### VM – OVS Communication
- Ogni VM ha una **vNIC** (scheda di rete virtuale)

- La vNIC è collegata a una **tap interface** nel sistema host:
  → es. tap0, tap1  

- La **tap**:
  → è un’interfaccia virtuale lato host  
  → permette lo scambio di traffico tra VM e OVS  

- Flusso:
  → VM → vNIC → tap → OVS → rete  

- OVS gestisce:
  → traffico dalle VM  
  → traffico dalle interfacce fisiche  

- Quindi ogni VM ha:
  → vNIC (lato VM)  
  → tap (lato host)  

![[Pasted image 20260418103622.png|300]]

---

### Network Node
- Le istanze OVS sui compute node:
  → inoltrano traffico tra VM locali o remote  

- Se il traffico è destinato all’esterno:
  → viene inviato al **Network Node**

- Il Network Node:
  → esegue anch’esso una istanza OVS  
  → implementa funzionalità **Layer 3 (routing)**  

- Funzione:
  → collega Virtual Networks alla rete esterna  

- Sintesi:
  → compute node → forwarding L2  
  → network node → routing L3  

- è colui che sceglie le regole da inoltrare allo switch, ma interconnette anche le reti virtuali con le reti esterne.
![[Pasted image 20260418103859.png|400]]

---

### Network Virtualization
- Obiettivo:
  → creare più reti logiche indipendenti sulla stessa infrastruttura fisica  

- Le Virtual Networks:
  → sono reti **Layer 2 (Ethernet)**  

- Requisiti:
  - comunicazione tra VM dello stesso network  
  - isolamento tra network diversi  
  - comunicazione tra network solo tramite router  

- In ambiente distribuito:
  → il traffico deve attraversare più compute node  
  → deve essere identificabile  

- Per questo:
  → ogni pacchetto viene associato a un **VN ID**

- Tecniche principali:
  → **packet tagging**  
  → **tunneling**

![[Pasted image 20260418104116.png|400]]

---

### Virtual LAN (VLAN)
- **VLAN** è una tecnica di virtualizzazione basata su **packet tagging**

- Standard:
  → **IEEE 802.1Q**

- Meccanismo:
  → aggiunge il campo **VID (VLAN ID)** all’header Ethernet  

- Il VID:
  → identifica la rete virtuale  

- Gli switch:
  → aggiungono il tag  
  → lo rimuovono a destinazione  
  → inoltrano solo verso host con lo stesso VID  

- Effetto:
  → isolamento tra Virtual Networks  
  → broadcast confinato  

- Intuizione:
  → ogni rete = “colore”  
  → solo stesso colore comunica  

---

### Neutron VLAN Operations
- Neutron può usare VLAN per implementare Virtual Networks  

- Processo:

1. Creazione VN
   → viene assegnato un **VID**

2. Configurazione
   → OVS viene configurato per usare quel VID  

3. Trasmissione
   → pacchetti taggati con VID  

4. Ricezione
   → tag rimosso  
   → consegna alle VM corrette  

- Se la rete è connessa a Internet:
  → anche il Network Node gestisce il tagging  

### GRE Tunneling
- Il **GRE (Generic Routing Encapsulation)** è una tecnica di virtualizzazione basata su **tunneling**, diversa dal VLAN (che usa tagging)

- Idea principale:
  → invece di aggiungere un tag (come VLAN)  
  → si **incapsula un intero pacchetto IP dentro un altro pacchetto IP**

---

- Meccanismo:
  → pacchetto originale (inner packet)  
  → viene inserito dentro un nuovo pacchetto (outer packet)  
  → viene aggiunto un **header GRE**

- Questo crea un **tunnel logico** tra due nodi

---

- Uso in OpenStack:
  → tra compute node che ospitano VM dello stesso Virtual Network  
  → tra compute node e network node  

- Ogni Virtual Network:
  → identificato da un **GRE ID**

---

- Intuizione:
  → la rete fisica trasporta pacchetti incapsulati  
  → solo i nodi che partecipano al tunnel:
    - decapsulano  
    - processano il traffico  

---

- Nota:
  → tutti i nodi che hanno VM nello stesso VN  
  → partecipano al tunnel  

![[Pasted image 20260418105308.png|400]]

---

### Neutron GRE Operations
- Per ogni Virtual Network:

1. viene assegnato un **GRE ID**  

2. OVS viene configurato:
   → crea una interfaccia virtuale (es. **gre-1**)  

3. Tra i nodi coinvolti:
   → viene creato un **tunnel GRE**  

4. Il traffico:
   → viene incapsulato all’uscita  
   → decapsulato all’arrivo  

---

- Ruolo dell’interfaccia GRE:
  → gestire tunnel  
  → incapsulare/decapsulare pacchetti  

---

- Risultato:
  → rete virtuale costruita sopra IP  
  → indipendente dalla topologia fisica  

![[Pasted image 20260418105356.png|500]]

---

### VXLAN
- **VXLAN (Virtual Extensible LAN)** è un’evoluzione di VLAN e GRE

---

- Problema VLAN:
  → VID = 12 bit  
  → massimo ≈ **4094 reti**

- In cloud grandi:
  → questo limite è insufficiente  

---

- Soluzione VXLAN:
  → identificatore a 24 bit  
  → fino a ≈ **16 milioni di Virtual Networks**

---

- Meccanismo:
  → simile a GRE (tunneling)  
  → ma usa **UDP encapsulation**

---

- Elementi chiave:
  - **VTE (Virtual Tunnel Endpoint)**:
    → endpoint del tunnel  

  - **VXLAN header**:
    → contiene l’ID del Virtual Network  

---

- Struttura:
  → frame Ethernet → incapsulato → UDP → IP  

---

- Vantaggio:
  → scalabilità molto maggiore rispetto a VLAN  

![[Pasted image 20260418105801.png|400]]

---

### Neutron VXLAN Operations
- Simile a GRE, ma con VXLAN

- Per ogni Virtual Network:

1. viene assegnato un **VXLAN ID**  

2. OVS viene configurato:
   → incapsulare traffico in VXLAN  

3. I nodi:
   → creano tunnel tra VTE  

4. Traffico:
   → incapsulato in UDP  
   → inoltrato  
   → decapsulato a destinazione  

---

- Risultato:
  → rete virtuale altamente scalabile  
  → indipendente dalla rete fisica  

![[Pasted image 20260418105910.png|400]]

---

### Cinder
- Servizio di **block storage** (componente che gestisce i volumi)

---

- Funzione:
  → gestione di **dischi virtuali**

- Ogni VM:
  → ha un disco di base (OS)  
  → può avere volumi aggiuntivi  

---

- I volumi:
  → appaiono come dischi reali per la VM  

---

- Implementazione:
  → i dischi sono:
    - file  
    - oggetti  
  → memorizzati nel filesystem o cloud storage  

---

- Accesso:
  → tramite **iSCSI**
    - protocollo IP  
    - accesso a blocchi  

---

![[Pasted image 20260418105952.png|400]]

---

### Cinder Architecture
- Componenti principali:
  - **Cinder-API**, che espone un’interfaccia REST ai client per controllare le operazioni di Cinder 
  - **Cinder-Volume**, che è responsabile di gestire direttamente le richieste provenienti dall’interfaccia REST  
  - **Cinder-Scheduler**, che è responsabile di selezionare lo storage più adatto per memorizzare nuovi volumi  
  - **Cinder-Backup**, che è responsabile della creazione dei backup dei volumi esistenti quando richiesto dagli utenti  

---

![[Pasted image 20260418110257.png|400]]

---

### Ceilometer
- Servizio di **monitoraggio (telemetry component)**

---

- Funzioni:
  → misura uso risorse per utente  
  → supporta **billing**  
  → raccoglie statistiche di sistema  

---

![[Pasted image 20260418110410.png|400]]

---

### Ceilometer Architecture
- Struttura centralizzata:

- **Ceilometer-Collector**
  → riceve dati  
  → li salva in DB (NoSQL)

- **Ceilometer-Agent**
  → su ogni nodo  
  → raccoglie metriche locali  
  → invia al collector  

---

- Accesso dati:
  → tramite REST API esposta dal collector  

![[Pasted image 20260418110425.png|400]]


### Horizon
- **Horizon** è l’interfaccia web di OpenStack

- Funzione:
  → espone le funzionalità della piattaforma agli utenti  

- Tipicamente:
  → eseguito sul **controller node**

---

- Permette di gestire:
  → VM (creazione, eliminazione, stato)  
  → rete  
  → storage  
  → configurazioni  

---

- In parallelo:
  → disponibili strumenti **CLI** per gestione avanzata/backend  

![[Pasted image 20260418110728.png|500]]

---

### Service APIs
- Ogni servizio OpenStack:
  → espone un insieme di **API**

- Tipo di comunicazione:
  → **REST**

---

- Ruoli principali delle API:
  → comunicazione tra servizi  
  → interazione con utenti  
  → integrazione con applicazioni esterne  

---

- Uso avanzato:
  → automazione (es. script, orchestrazione, integrazione CI/CD)

![[Pasted image 20260418110835.png|300]]

---

### Swift
- Servizio di **object storage**

---

- Funzione:
  → memorizza dati come **oggetti** (non blocchi o file system tradizionale)

- Utilizzato da:
  → utenti  
  → altri servizi (es. Cinder, Glance)

---

- Esempi:
  → backup volumi (Cinder)  
  → immagini VM (Glance)

---

- Caratteristiche:
  → altamente scalabile  
  → distribuito  
  → supporta cloud storage  

---

- Gestisce:
  → ricezione dati  
  → memorizzazione  
  → recupero  

---

### Architettura Swift
- Componenti principali:

- **Swift-Proxy**
  → espone REST API  
  → riceve richieste (upload/download)  
  → gestisce accesso  

- **Swift-Storage Nodes**
  → memorizzano fisicamente i dati  
  → distribuiti su più nodi  

---

![[Pasted image 20260418110957.png|300]]

---

### Heat
- Servizio di **orchestrazione**

---

- Funzione:
  → automatizza gestione infrastruttura  

- Permette:
  → creazione/distruzione VM  
  → configurazione automatica  
  → gestione lifecycle  

---

- Basato su:
  → **regole e condizioni**

→ es:
- autoscaling basato su metriche  

---

- Integrazione:
  → usa dati di **Ceilometer** per decisioni dinamiche  

---

### Architettura Heat
- Componenti:

- **Heat-API**
  → interfaccia utente  

- **Heat-Engine**
  → esegue le operazioni  
  → interpreta le regole  

---

![[Pasted image 20260418111006.png|400]]

---

### OpenStack: Interazione servizi
![[Pasted image 20260418110901.png]]

---

- In configurazione base:
  → ogni servizio ha **una sola istanza**

→ problema:
- **single point of failure**

---

### High Availability (HA)

- Architettura base:
  → una sola istanza per ogni servizio  
  → presenza di **single point of failure**

---

- Configurazione **High Availability**:
  → più istanze di ogni servizio  
  → maggiore:
    - disponibilità  
    - resilienza  

- Implementazione:
  → simile alle cloud applications  
  → servizi replicati in modo ridondante  

---

- Struttura:
  → più **controller nodes**  
  → ciascuno esegue gli stessi servizi  
  → tutti controllano lo stesso insieme di compute nodes  

---

### HA con nodo dedicato (HAProxy)

- Le API OpenStack:
  → NON esposte direttamente dai controller  
  → ma tramite un **HA proxy**

---

- Funzione del proxy:
  → riceve le richieste  
  → le inoltra a uno dei controller attivi  

---

- Il proxy deve:
  → rilevare failure dei controller  
  → rimuovere nodi non disponibili  

---

- Requisito fondamentale:
  → lo **stato deve essere replicato** tra i controller  

---

### HA con ridondanza semplice

- Le API:
  → esposte direttamente da un controller  

- Struttura:
  → un controller **attivo (master)**  
  → altri controller **inattivi (standby)**  

---

- Funzionamento:
  → il master serve le richieste  
  → gli altri monitorano lo stato  

---

- In caso di failure:
  → viene eletto un nuovo master  

---

- Coordinazione:
  → i controller collaborano per:
    - rilevare guasti  
    - effettuare failover  

---

- Anche qui:
  → lo stato deve essere replicato tra i nodi  



# 0D4. Lightweight IaaS DevOps  
### Software development IN THE PAST
- In passato, le applicazioni erano principalmente **monolitiche**:
  → un unico processo (o pochi processi)  
  → tutte le funzionalità integrate nello stesso sistema  

---

- Caratteristiche:
  → cicli di rilascio lenti  
  → aggiornamenti rari  
  → sviluppo complesso  

- Processo:
  → i developer sviluppano l’applicazione  
  → la consegnano al team **ops**  
  → il team ops gestisce deploy e infrastruttura  

---

- Problema principale:
  → forte accoppiamento tra componenti  

→ conseguenze:
- modifiche locali ⇒ richiedono redeploy completo  
- aumento complessità nel tempo  
- degrado qualità del sistema  

---

- Infrastruttura:
  → pochi server potenti  
  → architettura centralizzata  

![[Pasted image 20260418114301.png|100]]

---

### Legacy Systems
- I sistemi monolitici sono chiamati **legacy systems**

- Ancora oggi:
  → molti sono in uso  
  → spesso vengono **cloudificati**

---

- Cloudificazione:
  → server fisici → VM  

- Vantaggio:
  → semplifica gestione infrastruttura  

- Limite:
  → sviluppo e manutenzione restano complessi  

---

- Scalabilità:
  → tipicamente **verticale** (scale-up)  
  → si aggiungono risorse al server  

---

- Problema:
  → la scalabilità verticale ha limiti fisici  
  → non sempre è sostenibile  

---

### Software development NOW
- Con il cloud:
  → passaggio da monoliti a **microservizi**

---

- Applicazioni:
  → suddivise in **servizi indipendenti**

- Ogni servizio:
  → è autonomo  
  → può essere:
    - sviluppato  
    - deployato  
    - aggiornato  
    - scalato  
    indipendentemente  

---

- Comunicazione:
  → tramite interfacce ben definite  

![[Pasted image 20260418114320.png|200]]

---

### Service Independency
- I servizi sono:
  → **disaccoppiati (loosely coupled)**  

---

- Comunicazione:
  - sincrona:
    → REST, HTTP, SOAP  
  - asincrona:
    → message queue  

---

- Vantaggi:
  → sviluppo indipendente  
  → aggiornamenti locali  
  → niente redeploy globale  

---

- Nota:
  → purché l’interfaccia resti stabile  

---

### Application Development Process
- Cambia il processo di sviluppo e gestione

---

- In passato:
  - **Dev team**
    → design e sviluppo software  
  - **Ops team**
    → deploy + manutenzione  

---

- Motivazione:
  → competenze diverse  

---

### DevOps
- Nuovo approccio:
  → integrazione tra **development** e **operations**

---

- Lo stesso team:
  → sviluppa  
  → deploya  
  → mantiene l’applicazione  

---

- Vantaggi:
  → maggiore comprensione del sistema  
  → feedback più rapido  
  → rilasci più frequenti  

---

- Obiettivo:
  → pipeline continua (CI/CD)  

---

- Limite:
  → richiede conoscenza infrastrutturale avanzata  

---

### NoOps
- Evoluzione del DevOps

---

- Idea:
  → sviluppatori NON devono gestire infrastruttura  

---

- Obiettivo:
  → deployment completamente automatico  

---

- Ruolo ops:
  → non scompare  
  → gestisce infrastruttura sottostante  

---

- Dev:
  → si concentra solo sul software  

---

- Richiede:
  → forte automazione  

---

### Service Deployment and Management
- Problema:
  → molteplici servizi ⇒ complessità elevata  

---

- Con pochi servizi:
  → gestione semplice  

- Con molti servizi:
  → deployment complesso  
  → configurazione difficile  

---

- Manuale:
  → error-prone  
  → non scalabile  

---

→ necessità:
- **automazione del deployment e configurazione**

---

### Service Dependencies
- I servizi:
  → sviluppati indipendentemente  
  → usano librerie diverse  

---

- Problemi:
  → versioni diverse della stessa libreria  
  → dipendenze incrociate  

---

- Conseguenza:
  → deployment complesso  
  → conflitti tra ambienti  

---

![[Pasted image 20260418114620.png|400]]

---

### Consistent Application Environment
- Problema:
  → differenze tra ambienti (dev, test, produzione)

---

- Soluzione:
  → ambiente isolato e consistente  

---

- Approccio:
  → usare **virtualizzazione (VM)**  

---

- Vantaggi:
  → ambiente controllato  
  → librerie preinstallate  

---

- Svantaggi:
  → overhead elevato:
    - hypervisor  
    - guest OS  
    - configurazione  

---

→ limite:
- VM troppo pesanti per deployment rapido ed efficiente  


## Lightweight Virtualization
- Le tecniche di **virtualizzazione leggera** (es. container):
  → riducono l’overhead rispetto alla full virtualization

---

- I **container**:
  → includono:
    - applicazione  
    - librerie  
    - dipendenze  

→ creano un **ambiente isolato e consistente**

---

- Vantaggi:
  → più leggeri delle VM  
  → avvio rapido  
  → facilmente distribuibili  

---

- Distribuzione:
  → tramite immagini  
  → installabili su più macchine  

---

- Esempio:
  → Docker  

![[Pasted image 20260418114632.png|400]]

---

### Kubernetes
- Docker:
  → semplifica il deploy  
  → ma NON lo automatizza completamente  

---

- **Kubernetes**:
  → piattaforma per orchestrare container  
  → automatizza:
    - deploy  
    - gestione  
    - scaling  

---

- Applicazione containerizzata:
  → composta da più servizi  
  → ciascuno in un container  

---

- Obiettivo:
  → fornire una **infrastruttura IaaS leggera**  
  → semplificare deploy e gestione  

---

- Ruolo Ops:
  → gestisce infrastruttura Kubernetes  
- Ruolo Dev:
  → gestisce applicazione  

---

### Kubernetes: funzionamento
- Kubernetes è un sistema distribuito composto da:

- **Master node (control plane)**: espone un interfaccia ai developer con la quale possono richiedere di eseguire una certa applicazione
- **Worker nodes**: hosta il componente containerizzato 

---

- Installazione:
  → su hardware fisico  
  → oppure su VM (più comune)

---

- Il developer:
  → invia un **application descriptor**
    - file di configurazione  
    - descrive i componenti (lista, numero, pod)

---

- Il sistema:
  → deploya automaticamente i componenti  

---

![[Pasted image 20260418114644.png|600]]

---

### Pod e deployment
- I componenti:
  → possono essere raggruppati in **pod**

- Un **pod**:
  → insieme di container che devono:
    - girare insieme  
    - stare sullo stesso nodo  

---

- Altri componenti:
  → distribuiti tra i nodi  

---

- Il developer specifica:
  → numero desiderato di istanze  

---

- Kubernetes:
  → replica automaticamente i componenti  
  → bilancia il carico  

---

### Gestione automatica
- Kubernetes si occupa di:

- **Scaling**
  → crea/rimuove istanze  

- **Load balancing**
  → distribuisce traffico  

- **Fault tolerance**
  → rileva guasti  

- **Self-healing**
  → rimpiazza istanze fallite  

---

- Esempio:
  → nodo fallisce  
  → Kubernetes ricrea le istanze su altri nodi  

---

### Vantaggi
- Per i developer:
  → niente gestione infrastruttura  
  → focus sul codice  

---

- Per ops:
  → meno configurazione manuale  
  → meno interventi su failure  

---

- Per il sistema:
  → migliore utilizzo risorse  

---

### Cluster Architecture
- Il **master node** implementa il **control plane**

- Responsabilità:
  → gestione dell’intero cluster  

---

- I componenti del control plane:
  → possono:
    - essere su un nodo  
    - essere distribuiti  
    - essere replicati (HA)

---

![[Pasted image 20260418114655.png]]

---

### Componenti del Control Plane (Master Node)
- **API Server**
  → interfaccia per utenti e servizi  

- **Scheduler**
  → decide dove eseguire i container  

- **Controller Manager**
  → gestisce:
    - replica  
    - stato cluster  
    - recovery  

- **Etcd**
  → database distribuito  
  → memorizza stato del cluster  

---

### Worker Nodes
- Ogni worker node include:

- **Container runtime**
  → esegue i container (es. Docker)

- **Kublet**
  → comunica con API server  
  → gestisce container sul nodo

- **Kubernetes Service Proxy**
  → gestisce traffico di rete  
  → bilancia richieste tra componenti  

---


### Application Deployment
- Il developer fornisce un **application descriptor**:
  → descrive i container che compongono l’applicazione  

---

- I container:
  → vengono raggruppati in **pod**

- Un **pod**:
  → insieme di container che devono:
    - essere eseguiti insieme  
    - stare sullo stesso worker node  

→ può anche contenere **un solo container**

---

- Concetto chiave:
  → **tutto in Kubernetes è un pod**

---

- Per ogni pod il developer specifica:
  → immagine del container  
  → configurazione  
  → numero di **repliche**

---

- I worker node:
  → sono collegati tramite una rete virtuale  
  → permettono comunicazione tra componenti  

---

![[Pasted image 20260418114703.png]]

---

- Deployment:
  → il descriptor viene inviato al control plane  
  → lo **scheduler** assegna i pod ai worker node  

- I **kubelet**:
  → scaricano le immagini (pull)  
  → avviano i container  

---

### Management and Maintenance
- Kubernetes mantiene costantemente:
  → lo stato reale = stato desiderato  

---

- Se un’istanza fallisce:
  → viene automaticamente **riavviata**

---

- Se un nodo fallisce:
  → i pod vengono **ripianificati su altri nodi**

---

- Scalabilità dinamica:
  → il developer può:
    - aumentare/diminuire repliche  

---

- Autoscaling:
  → Kubernetes può decidere automaticamente  
  → basandosi su:
    - CPU  
    - memoria  
    - traffico  

---

### Container Migration
- Kubernetes:
  → gestisce automaticamente:
    - creazione container  
    - migrazione  

---

- Problema:
  → i container cambiano nodo/IP  

---

- Soluzione:
  → esposizione tramite **servizio stabile**

- Il sistema:
  → assegna un **IP pubblico unico**  
  → indipendente da:
    - numero container  
    - posizione  

---

- Il **kube-proxy**:
  → instrada il traffico verso i container corretti  
  → implementa **load balancing**

---

### Exposing Applications
- I pod:
  → hanno IP interni (privati)  
  → non accessibili dall’esterno  

---

- Per esporre un servizio:
  → si definisce un **Service object**

---

- Il Service:
  → associa:
    - IP pubblico  
    - porta  

---

- Funzione:
  → inoltra richieste esterne  
  → verso uno dei pod disponibili  

---

![[Pasted image 20260418114717.png]]

---

### Load Balancing
- Un Service può essere collegato a:
  → più istanze dello stesso pod  

---

- Funzione:
  → distribuisce il traffico tra le repliche  

---

- Kubernetes usa:
  → **replication controller**

→ garantisce:
- numero corretto di istanze  
- distribuzione del carico  

---

![[Pasted image 20260418114722.png]]

---

### Failure Handling
- Il replication controller:
  → monitora continuamente i pod  

---

- Se un pod fallisce:
  → viene creato automaticamente uno nuovo  

---

- Se un nodo fallisce:
  → i pod vengono ricreati altrove  

---

![[Pasted image 20260418114727.png]]

---

### Pod Design
- Regola generale:
  → usare **un pod per container**

---

- Eccezione:
  → più container nello stesso pod se:
    - devono comunicare velocemente  
    - hanno forte dipendenza  

---

- Esempio:
  → due servizi con requisiti di bassa latenza  

→ conviene metterli nello stesso pod  
→ evita comunicazione via rete  

---

![[Pasted image 20260418114733.png]]



# 0E1. Cloud Storage
### Storage Technology Evolution
- Negli ultimi anni:
  → forte crescita di:
    - capacità di storage  
    - velocità di accesso  

---

- Hard Disk:
  → da MB → TB  
  → riduzione significativa dei costi  

---

- Introduzione **SSD**:
  → eliminazione parti meccaniche  
  → accesso molto più veloce  

- Miglioramento:
  → da centinaia di ms → decine di ms  

---

### Block Storage e File System
- **Block storage**:
  → forma più semplice di storage  
  → dati salvati come:
    - blocchi continui  
    - non strutturati  

---

- Un **blocco**:
  → sequenza di byte  
  → memorizzato direttamente su disco  

---

- Limite:
  → difficile da usare direttamente  

---

- Soluzione:
  → **file system** sopra i blocchi  

---

- Il file system:
  → organizza dati in file  
  → gestisce metadata  
  → astrae il block storage  

---

- Uso:
  → sistemi operativi  
  → gestione file utente e sistema  

---

![[Pasted image 20260418115334.png]]

---

### Object Storage
- Nuovo paradigma:
  → **object storage**

---

- Un **oggetto**:
  → dati + metadata  

---

- Proprietà:
  → identificato da **ID univoco**  
  → accesso tramite ID  

---

- Metadata:
  → flessibili  
  → estendibili  

---

- Caratteristica chiave:
  → **immutabilità**

→ modifiche ⇒ nuovo oggetto  

---

- Vantaggi:
  → gestione semplice  
  → scalabilità elevata  
  → ideale per:
    - big data  
    - ML  

---

- Versioning:
  → ogni modifica = nuova versione  

---

### Confronto
![[Pasted image 20260418115340.png]]

---

### Single Server Storage Model
- Modello tradizionale:
  → dischi collegati a un singolo server  

---

- Problemi:
  → guasti hardware  
  → vita media ≈ 5 anni  

---

- Soluzione:
  → **RAID** per ridondanza  

---

- Limite:
  → capacità limitata dai bay fisici  

---

- Evoluzione:
  → uso di **Distributed File Systems**

---

![[Pasted image 20260418115348.png]]

---

### RAID
- **RAID (Redundant Array of Independent Disks)**:
  → combina più dischi fisici  

→ crea un disco logico  

---

- Obiettivi:
  → ridondanza  
  → performance  
  → entrambi  

---

- Implementazione:
  - hardware:
    → tramite RAID controller  
    → trasparente per OS  

  - software:
    → gestito dall’OS  

---

### RAID Schema
- Distribuzione dati dipende dallo schema

---

- **RAID 0 (striping)**:
  → dati distribuiti su più dischi  
  → alta performance  
  → nessuna ridondanza  

---

- **RAID 1 (mirroring)**:
  → dati duplicati  
  → massima sicurezza  
  → scrittura più lenta  

---

- **RAID 5**:
  → striping + parità  
  → compromesso performance/sicurezza  

- Meccanismo:
  → blocchi distribuiti  
  → aggiunta blocco di parità (XOR)  

---

- Requisito:
  → almeno 3 dischi  

---

- Tolleranza:
  → 1 disco può fallire  

---

- **RAID 6**:
  → doppia parità  
  → tollera 2 guasti  

---

![[Pasted image 20260418115353.png]]

---

### Distributed File System (DFS)
- Obiettivo:
  → superare limiti single server  

---

- **DFS**:
  → file system distribuito su più server  

---

- Vantaggi:
  → scalabilità  
  → maggiore capacità  
  → fault tolerance  

---

- Comunicazione:
  → tramite rete (LAN)  

---

- Uso:
  → aggregare storage di più server  
  → estendere capacità di un server  

---

- Esempio:
  → **NFS (Network File System)**  


### NFS
- **NFS (Network File System)** adotta un modello **client-server**

---

- Architettura:
  → un server centrale  
  → espone il proprio file system ai client  

---

- Accesso:
  → i client accedono ai file remoti  
  → come se fossero locali  

---

- Comunicazione:
  → tramite protocollo NFS  
  → **sincrona**  
  → garantisce:
    - consistenza  
    - semplicità  

---

- Implementazione:
  → integrata nel **kernel Linux**  
  → trasparente per le applicazioni  

---

![[Pasted image 20260418115400.png]]

---

### GlusterFS
- Limite NFS:
  → architettura centralizzata  
  → scarsa scalabilità  
  → punto singolo di failure  

---

- **GlusterFS**:
  → file system distribuito (DFS)  
  → aggrega storage di più nodi  

---

- Caratteristica chiave:
  → **nessuna distinzione client/server**

- Tutti i nodi:
  → contribuiscono con storage locale  

---

- Uso:
  → accesso simile a NFS  
  → ma distribuito  

---

![[Pasted image 20260418115405.png]]

---

### Modalità GlusterFS
- Altamente configurabile  

---

- Modalità base:


- **Distributed volumes**
  → dati distribuiti tra nodi  
  → alta capacità  

---

- **Replicated volumes**
  → dati replicati  
  → alta affidabilità  

---

- **Striped volumes**
  → dati suddivisi in blocchi  
  → alta performance  

---

![[Pasted image 20260418115419.png]]
![[Pasted image 20260418115416.png]]

---

- Modalità avanzate:
  → combinazioni dei modelli base  

- Esempi:
  → distributed replicated  
  → striped replicated  

---

![[Pasted image 20260418115425.png]]

---

### Cloud Storage
- Requisito principale:
  → **scalabilità**

---

- Deve scalare con:
  → numero di VM  
  → numero e dimensione dei volumi  
  → quantità di dati generati  

---

- Uso dischi locali:
  → possibile  
  → ma non scalabile  

---

- Limiti:
  → stessi vincoli del modello tradizionale  

---

### VM Live Migration
- **Live Migration**:
  → spostamento VM tra nodi  
  → senza spegnimento  

---

- Vantaggi:
  → downtime minimo  
  → maggiore flessibilità  

---

- Problema:
  → storage locale non condiviso  

---

- Soluzione:
  → **shared storage**

---

- Senza shared storage:
  → serve spegnere VM  
  → trasferire disco  
  → downtime elevato  

---

![[Pasted image 20260418115430.png]]

---

### Storage Area Network (SAN)
- **SAN**:
  → rete dedicata allo storage  

---

- Caratteristiche:
  → alta velocità  
  → dispositivi storage dedicati  

---

- I server:
  → accedono allo storage  
  → a livello di blocchi  

---

- Tecnologie:
  → Fiber Channel  
  → iSCSI  

---

- **iSCSI**:
  → trasporta comandi SCSI su TCP/IP  
  → accesso a blocchi via rete  

---

![[Pasted image 20260418115436.png]]

---

### Software Storage Solutions
- Problema SAN:
  → costosi  
  → complessi  

---

- Soluzione moderna:
  → storage distribuito software-based  

---

- Caratteristiche:
  → scalabile  
  → fault tolerant  
  → senza single point of failure  
  → basato su hardware commodity  

---

- Ispirazione:
  → Distributed File Systems  

---

- Esempio:
  → **Ceph**

### Ceph
- **Ceph** è un sistema di storage distribuito:
  → altamente affidabile  
  → scalabile  
  → basato su hardware commodity  

---

- Obiettivi principali:
  → scalabilità completa  
  → nessun single point of failure  
  → soluzione software open source  
  → auto-gestione  

---

- Caratteristica chiave:
  → Ceph gestisce automaticamente:
    - replica dei dati  
    - recovery  
    - fault tolerance  

→ non serve RAID  

---

### Ceph Services
- Ceph può essere installato su server standard:
  → crea un **cluster distribuito**

---

- Capacità:
  → aggrega lo storage di tutti i nodi  

---

- Tipi di storage supportati:
  - object storage  
  - block storage  
  - file system  

---

![[Pasted image 20260418115444.png]]

---

### Ceph Architecture
- Il cluster è composto da diversi servizi indipendenti  

---

- Core del sistema:
  → **RADOS (Reliable Autonomic Distributed Object Store)**  

---

- Concetto chiave:
  → tutto è memorizzato come **oggetti**

---

- RADOS:
  → gestisce:
    - replica  
    - consistenza  
    - fault detection  
    - recovery  
    - rebalancing  

---

- Accesso:
  → tramite **LIBRADOS**
    - libreria per interfacciarsi con RADOS  

---

![[Pasted image 20260418115450.png]]

---

### Storage sopra RADOS
- Altri servizi costruiti sopra RADOS:

---

- **RBD (Ceph Block Device)**
  → storage a blocchi  
  → usato per:
    - volumi  
    - dischi VM  

- Supporta:
  → snapshot  
  → thin provisioning  

---

- **CephFS**
  → file system distribuito  
  → compatibile POSIX  

- Usa:
  → **MDS (Metadata Server)**  
  → gestisce metadata e struttura file  

---

### Componenti principali
- RADOS è implementato tramite:

---

- **OSD (Object Storage Device)**
  → gestisce i dati reali  
  → ogni disco → un OSD  

- Funzione:
  → operazioni I/O  
  → storage fisico  

---

- **MON (Monitor)**
  → monitora stato cluster  
  → mantiene configurazione  

- Replica:
  → più MON per fault tolerance  

---

### Proprietà del sistema
- Ceph garantisce:
  → alta disponibilità  
  → assenza di single point of failure  
  → self-healing  

---

- Questo è ottenuto tramite:
  → distribuzione + replica  
  → algoritmi interni (es. CRUSH)

---

### Ceph Object
- Un oggetto Ceph:
  → dati + metadata  

---

- Proprietà:
  → identificatore univoco globale  

---

- Vantaggi:
  → nessun limite rigido di dimensione  
  → metadata flessibili  

---

- Storage:
  → salvati su OSD  
  → replicati automaticamente  

---

- Scrittura:
  → client invia dati  
  → Ceph li salva come oggetti  
  → OSD li scrive su disco  

---

![[Pasted image 20260418115500.png]]

### CRUSH Algorithm
- **CRUSH** è l’algoritmo utilizzato da Ceph per determinare:
  → dove sono salvati gli oggetti  

---

- Proprietà chiave:
  → client e OSD possono calcolare **indipendentemente** la posizione dei dati  

→ non serve una tabella centrale  

---

- Vantaggi:
  → elimina colli di bottiglia  
  → altamente scalabile  
  → distribuisce il lavoro tra tutti i nodi  

---

- Funzionamento:
  → usa lo stato corrente del cluster  
  → decide:
    - dove scrivere  
    - dove leggere  

---

- Replica:
  → gestita automaticamente  
  → ottimizzata per resilienza  

---

![[Pasted image 20260418115505.png]]

---

### Cluster Map
- Lo stato del cluster è rappresentato dalla **Cluster Map**

---

- Contiene:

- **Monitor Map**
  → informazioni sui monitor  
  → versione (epoch)  
  → timestamp aggiornamenti  

---

- **OSD Map**
  → lista OSD  
  → stato (up, down, in, out)  
  → pool e replica  

---

- **PG Map**
  → informazioni sui **placement groups**  
  → stato (es. active + clean)  

---

- **Cluster Map (topologia)**
  → struttura fisica:
    - disco  
    - host  
    - rack  
    - data center  

---

- Nota:
  → i **placement group (PG)** determinano dove salvare i dati  

---

### Data Placement
- Processo di scrittura:

1. Il client ottiene la **Cluster Map** dal monitor  

2. Calcola:
   → **hash(object ID)** → placement group  

3. Usa CRUSH:
   → mappa PG → lista di OSD  

---

- Risultato:
  → un **OSD primario**  
  → più OSD secondari (repliche)  

---

![[Pasted image 20260418115511.png]]

---

### Data Replication
- Scrittura dati:

1. Il client scrive sull’**OSD primario**  

2. L’OSD primario:
   → usa CRUSH  
   → identifica OSD secondari  

3. Replica i dati:
   → su OSD secondari/terziari  

---

- Conferma:
  → inviata al client solo dopo replica  

---

- Vantaggio:
  → client non gestisce replica  
  → alta affidabilità  

---

![[Pasted image 20260418115516.png]]

---

### Pools
- I **pool**:
  → partizioni logiche di storage  

---

- Funzione:
  → organizzare oggetti  
  → separare dati per applicazioni  

---

- Configurazioni:
  → diverse politiche:
    - replica  
    - performance  
    - utilizzo  

---

![[Pasted image 20260418115528.png]]

---

### MON Redundancy
- Un solo monitor:
  → single point of failure  

---

- Soluzione:
  → cluster di monitor  

---

- I monitor:
  → devono concordare sullo stato  

---

- Meccanismo:
  → algoritmo **Paxos**  

---

- Regola:
  → serve **maggioranza**  

→ es:
- 2 su 3  
- 3 su 5  

---

![[Pasted image 20260418115534.png]]

---

### Placement Groups Computation
- Ogni pool:
  → contiene più **placement groups**

---

- Processo:
  → oggetto → hash → PG  
  → PG → OSD (via CRUSH)

---

- Obiettivi:
  → bilanciamento dati  
  → fault tolerance  

---

- Mapping:
  → basato su:
    - dimensione dischi  
    - stato cluster  

---

- Failure domain:
  → può includere:
    - dischi  
    - server  
    - rack  
    - alimentazione  

---

![[Pasted image 20260418115539.png]]

---

### Recovering and Rebalancing
- I PG introducono un livello di **indirezione**  

---

- Vantaggi:
  → cluster può:
    - crescere  
    - ridursi  
    - adattarsi  

---

- Caso:
  → aggiunta nuovo OSD  

---

- Effetto:
  → aggiornamento cluster map  
  → ricalcolo mapping  
  → spostamento dati (**rebalancing**)  

---

- Obiettivo:
  → distribuzione uniforme  

---

![[Pasted image 20260418115543.png]]

---

### Ceph e OpenStack
- Ceph può essere integrato con OpenStack:

---

- **Cinder**
  → usa Ceph per volumi (block storage)

- **Swift**
  → usa Ceph per object storage  

- **Glance**
  → usa Ceph per immagini VM  

- **Nova**
  → usa Ceph per dischi VM  

- **Ceilometer**
  → usa Ceph per metriche  

---

![[Pasted image 20260418115549.png]]

---

### Storage as a Service (STaaS)
- Servizio cloud:
  → accesso allo storage via Internet  

---

- Modello:
  → spesso **object storage**  

---

- Interfaccia:
  → REST API  

---

- Uso:
  → backup  
  → archiviazione dati  

---

- Esempi:
  → Swift (OpenStack)  
  → AWS S3  
  → AWS Glacier  

---