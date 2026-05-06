# 7. IoT platforms
slide3
Ci mancava un pezzo: il collegamento tra applicazioni e service infrastructure (==min15==).
Manca il marketplace, dove gli sviluppatori possono scrivere l'applicazione che può essere eseguita in vari ambienti. L'applicazione è installata dallo sviluppatore sul cloud o su un edge device, senza preoccuparsi dell'hardware.
Ogni sviluppatore esegue il programma una volta e basta. Ma in genere in base al dispositivo sarebbero necessari degli aggiustamenti.
Manca un framework che supporta gli sviluppatori a usare l'app senza preoccuparsi ... (==min18DR==).

slide4
Ci sono molti sforzi per fare una piattaforma unificata.

slide7-8
Una delle più importanti è oneM2M. Non è un software, ma un set di specifications, specificate da ETSI (European Telecommunications Standards Institute, ==min20DRA==).
oneM2M ... ==min23DR==...
IoT manifactures prendono ...
Non entreremo nel dettaglio.

Prima cosa che la piattaforma definisce è l'architettura.
==min25DRA==
Ci sono 3 livelli:
- ground ==min27DRAA==
- fog/edge
- cloud

![[Pasted image 20250508092254.png|400]]

oneM2M generalizza l'idea di applicazione (non l'abbiamo fatta bene).
La logica dell'applicazione non è ristretta all'esecuzione sul cloud, ==min30==, ma anche ...
La parte dell'applicazione che userà l'utente sono i livelli fog/edge e cloud.
(==min31==) ... si occupa di collezionare e sample i dati.

slide9
Architettura funzionale = lista di funzionalità (offerta agli sviluppatori) che ogni dispositivo iot dovrebbe implementare.
Perché ne abbiamo bisogno? Gli sviluppatori non vogliono reinventare tutte le funzionalità da zero, vogliono semplificarsi la vita.
Ci sono tre livelli:
- network layer $\to$ è obbligatorio su tutti i dispositivi, da iot devices al cloud. implementato su ogni dispositivo, in un modulo chiamato NSE (Network Service Entity). 
- service layer $\to$ ==min37DRA== CSE, Mca ...
- application layer $\to$ implementa un insieme di funzionalità per ogni nodo.

==riascolta assolutamente fino a min45==

_ChatGPT:_
Questa immagine mostra l’**architettura funzionale** di una piattaforma **IoT (Internet of Things)**, organizzata in **tre livelli principali** (Network, Service e Application) e in diversi **nodi (device, gateway, server)**. Vediamola in modo semplice ma completo:
**Livelli dell'architettura:**
- **Network Layer (Livello di rete)**
	È lo strato più basso, responsabile della **connessione fisica e trasporto dei dati**. Comprende:
	- **NSE (Network Service Entity)**: gestisce la comunicazione tra i dispositivi tramite la rete sottostante (WiFi, 5G, ecc.).
- **Service Layer (Livello di servizio)**
	Qui risiedono le **funzioni logiche e di controllo dell’IoT**:
	- **CSE (Common Services Entity)**: offre servizi comuni a tutti, come sicurezza, gestione dei dispositivi, archiviazione dati, discovery, ecc.
- **Application Layer (Livello applicativo)**
	La parte visibile agli **utenti o alle applicazioni** finali:
	- **AE (Application Entity)**: rappresenta l'applicazione IoT vera e propria (ad esempio un'app per il monitoraggio ambientale).

**Entità**
- **AE (Application Entity)**: Le applicazioni che utilizzano i servizi IoT. 
- **CSE (Common Service Entity)**: Il cuore logico della piattaforma IoT.
- **NSE (Network Service Entity)**: Fornisce accesso alla rete.

**Punti di riferimento (Reference Points)**
Sono le **interfacce di comunicazione** tra le varie entità:
- **Mca**: tra AE e CSE (usata dalle app per accedere ai servizi).
- **Mcn**: tra CSE e NSE (usata per connettere i servizi alla rete). 
- **Mcc**: tra CSE di nodi diversi (cooperazione tra dispositivi/gateway/server).
- **Mcc'**: tra CSE e altri server di servizi esterni.

**Nodi della rete**
- **Device**: Un oggetto fisico con sensori/attuatori (es. un termometro intelligente). 
- **Gateway**: Collega più dispositivi alla rete e funge da punto intermedio.
- **Server**: Il "cervello" centrale dove vengono elaborati e archiviati i dati.
- **Other Service Providers Server**: Altri server esterni con cui collaborare (es. servizi cloud, AI, ecc.).

**In sintesi**: L’immagine rappresenta **come i dati viaggiano e vengono gestiti** all’interno di un sistema IoT, partendo dai dispositivi fisici fino ad arrivare alle applicazioni. Ogni livello ha un ruolo specifico e le comunicazioni tra componenti seguono interfacce standardizzate (Mca, Mcn, ecc.) per garantire interoperabilità e scalabilità.
_Fine ChatGPT_

slide10-11
oneM2M entità e punti di riferimento

slide50
==min46-47==

slide12
==min48-54 DR==
![[Pasted image 20250508100026.png|500]]
Tre livelli:
- infrastructure domain $\to$ cloud
- field domain $\to$ edge o iot devices
- IoT layer

Differenza tra ... ==min51==

slide14
(CSF = common service function =) Funzionalità definite in un CSE (common service entity).
- Registration
- Group Management
- Security
- Discovery
- Data Management & Repository
- Application & Service Management
- Device Management
- Subscription & Notification
- Communication Management
- Service Charging & Accounting
- Location
- Network Service Exposure

Vediamone alcune nel dettaglio

slide15
Registration is the process of delivering AE or CSE information to another CSE in order to use M 2 M Services.
Registrazione = processo di una applicazione che si registra in un sistema (autorizzata e date funzionalità dalle entità dell'applicazione). ==min57==
registrare la presenza di moduli ...

slide16 ==min59==
seconda funzionalità implementata dalla piattaforma: discovery.
==Ripreso a min66== è questa la parte che ci interessa

slide17
altro modulo è security (legge).
E' necessario in quanto ... ==min60==

slide18
... Subscription and notification è un servizio provided by the platform.

slide19
set di funzionalità è legata a Data Management & Repository.
==min63==

slide20
saltiamo la parte su resource management ==min64==