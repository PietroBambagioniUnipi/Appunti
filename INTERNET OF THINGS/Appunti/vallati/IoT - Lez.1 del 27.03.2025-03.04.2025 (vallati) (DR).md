# 1.
## Contenuti del corso – IoT ==finoamin7DR==
_**Appunti 2026**: Finora abbiamo visto come i dispositivi possono connettersi a internet, comunicare internamente o esternamente alla rete. La capacità di comunicare con dispositivo interno o host esterno crea un sistema IoT. i dispositivi producono dati e abbiamo bisogno di altri layers e strumenti per permettere la comunicazione di questi dati. Noi vedremo come possiamo fare large scale IoT systems dove abbiamo iot dispositivi (sensori) integrati in large scale applications. Quindi dopo aver visto le tecnologie di comunicazione (con Anastasi e Righetti) in questa parte del corso vedremo l'integrazione di queste con piattaforme del cloud computing._

- **Web of Things**
	- Protocolli application-layer
	- Rappresentazione dei Dati
	- Servizi Web
- **Piattaforme per applicazioni IoT** $\to$ oneM2M

![[Pasted image 20250327085120.png|400]]

**E' ancora solo una visione?** _No, l'idea di sistemi IoT in larga scala si stanno già diffondendo (lucchetti per bici senza chiave, sensori, ...). IoT non è una visione, ma è qualcosa di pratico._
_IoT non è più solo una visione, il mercato è pieno di prodotti smart, è qualcosa di consolidato. Prima i costi erano troppo alti ma ora il mercato si è consolidato._

## Galassia di sistemi "verticali"
_**Appunti 2026**: Tutti i prodotti smart hanno una peculiarità nel design: sono progettati e venduti come prodotti verticali, ovvero sono progettati in modo da lavorare in isolamento (non devono lavorare con altri). Può capitare di avere più dispositivi, ma ognuno di loro lavora in isolamento, anche se sono nello stesso ambiente. Ognuno di loro produce dati. Solo il dispositivo specifico può trattare i dati e comunicare con l'attuatore. Diversi dispositivi non cooperano. Tuttavia questo è inefficiente._
_Esempio: una casa potrebbe avere un termostato smart e un allarme smart. Questi potrebbero lavorare in isolamento, ma se condividessero le informazioni sarebbe meglio, il termostato potrebbe segnalare se ci sono persone nella stanza verificando il calore nella stanza. Funzionano bene anche isolati, ma sarebbe più efficiente farli cooperare._
_Potrebbe esservi un integratore (non ho ben capito, ==min13del290.04.26==???)_

- **Progettati** per servire un unico scopo.
- **Inefficienti**: ogni dispositivo è dedicato a una singola applicazione.
- Operano in **isolamento**: nessuna (o molto limitata) cooperazione.

![[Pasted image 20250327090252.png|200]]
_Dedicated devices as example smart termostato. These application implements business logic._

## Approccio orizzontale
![[Pasted image 20250327090635.png|200]]
_**Appunti 2026**: Nell'approccio orizzontale hai converged infrastructure, non silos verticali. L'idea dietro questa infrastruttura: da una parte hai una infrastruttura unificata (hai i sensori e gli attuatori già installati nel sistema, a prescindere dagli usi che ne fai), poi on top di questa infrastruttura vengono installate le applicazioni (prese dal market store), che dipendono dai sensori disponibili nell'ambiente. Idea è quella di trattare la piattaforma come uno smartphone (che ha dei sensori integrati): in base ai sensori che abbiamo installiamo le applicazioni. La prima cosa che fai quindi è verificare che sensori hai a disposizione._

- Infrastruttura **convergente**
- **Infrastruttura unificata di rilevamento e attuazione**
- Supporto per **molteplici applicazioni**

==finoamin29==
### Infrastruttura IoT convergente
_**Appunti 2026**: Come raggiungiamo questo approccio orizzontale? Con protocolli e procedure standard. Internet è un esempio di come con la standardizzazione possiamo ottenere l'approccio orizzontale._
_Applicazioni interagiscono con i sensori._
_IPv6 fa in modo che le applicazioni comunichino con i dispositivi (?)._

- **Web of Things** _(include dei protocolli di comunicazione, con interfaccia comune, lo vedremo più avanti)_ $\to$ MQTT, CoAP
- **IP(v6) per gli Smart Objects** $\to$ 6lo

![[Pasted image 20250327090953.png|200]]
**Protocolli standard**: Un insieme di soluzioni basate su IPv6 è stato definito dall'IETF (6LoWPAN, ROLL, COAP). Supportato dall'IPSO Alliance.

==min34-37DR==
## Integrazione **diretta** con il Cloud
_**Appunti 2026**: Iot usa cloud computing technologies. L'architettura è semplice: iot devices installati nell'ambiente, che sono in grado di comunicare con applicazioni in esecuzione nel cloud. Le applicazioni sono progettate per i sistemi iot. Vantaggi del cloud computing: provides scalabilità (è possibile richiedere risorse), è ubiquitous, è economico, il mercato è largo e in espansione. Tutti i cloud providers offrono iot support, hanno un prodotto per creare soluzioni iot. Iot product from a cloud provider: strumenti con i quali puoi creare l'applicazione iot, per immagazzinare dati o per interfaccia, o altro. L'idea è che il manifacturer non deve partire da zero, ma da delle componenti (iot package) con cui produrre soluzioni in meno tempo. Peculiarità è che sfruttano le stesse tecnologie, con architetture simili (?). L'iot orizzontale è già disponibile, perché tutti i iot providers offrono più e meno le stesse tecnologie (pacchetti). Ad esempio tutti offrono MQTT._

**L'IoT orizzontale è già disponibile.** _basato sulle stesse tecnologie (stesso contesto tecnologico) dal punto di vista computazionale e dell'architettura._
Quasi tutti i provider Cloud offrono supporto IoT, integrando i dispositivi nei loro servizi cloud: Amazon Web Services, Microsoft Azure, Google Cloud, IBM, ecc.
_Ogni pacchetto è in forma di: servizio, programmi scheletro, insieme di programmi implementabili sul dispositivo IoT (alternativamente)._
Ogni sistema supporta già molti sensori e hardware, **come?** Tutti adottano un protocollo comune e interoperabile che esiste da tempo: **MQTT**.

### MQTT (Message Queuing Telemetry Transport)
**MQTT è un protocollo di messaggistica publish/subscribe** progettato per comunicazioni M2M _(machine to machine)_ leggere.
_Il caso iniziale per cui MQTT è stato progettato era telemetry protocol for pipelines (==min27del29.04.2026==)._
**MQTT segue un modello client/server**, in cui ogni sensore è un client e si connette a un server, noto come **broker**, tramite **TCP**.
![[Pasted image 20250327093257.png|300]]           ![[Pasted image 20250327093315.png|350]]
_Il client produce o consuma dati/messaggi. Il broker è il dispatcher di questi dati._
_Ogni client che produce dati si dice che "pubblica" (publish) questi dati._
_I client interessati agli aggiornamenti del sensore (es. sensore di temperatura), si "sottoscrive" (subscribe) per ricevere notifiche._
_**Appunti 2026**: Come funziona MQTT: Lavora a livello alto, ha modello client-server. Ogni sensore è un client, che produce o riceve dati. Al centro abbiamo il broker (server), che riceve i dati dai producer e li manda a chi li consuma (consumers). Quindi il broker è il collegamento tra producers e consumers._

_Come i client taggano i messaggi?_
_**Appunti 2026**: Quando i dati sono prodotti, il broker fa operazione di "publish", ovvero li dispatcha ai consumers. I consumers, che sono interessati a ricevere i dati, ganno operazione di "subscribe". In MQTT i dati possono essere qualsiasi cosa. L'unica cosa che li caratterizza è un'etichetta (label) chiamata topic, stringa che dice che tipo di dati sono integrati nel messaggio. Questa è una cosa che viene aggiunta. quando un client vuole ricevere aggiornamenti sui dati fa subscription a un determinato topic. il broker tiene conto delle subscriptions. publish e subscribe possono alternanrsi, un client può anche fare entrambi per topic diversi, il ruolo non è fisso ma dipende dall'uso._

Ogni messaggio viene pubblicato su un indirizzo, noto come **topic**.
I client devono sottoscriversi ai topic di interesse e possono sottoscriversi a più topic se necessario.
Ogni client sottoscritto a un topic riceve tutti i messaggi pubblicati su quel topic.
Un client può pubblicare un messaggio su un determinato topic in qualsiasi momento.
_Esempi:_
![[Pasted image 20250327093649.png|300]]            ![[Pasted image 20250327093954.png|300]]
_Client può essere: sensore che produce dati, o sensore che vuole updates dal sensore, o applicazione che vuole updates dal sensore._

### Piattaforme Cloud basate su MQTT
_Come è usato MQTT?_
_==min49== ... istanzia un broker nella piattaforma cloud. broker usato dai sensori che pubblicano dati._
_Questo come fitta con i pacchetti offerti dai cloud manifacturer? Ogni manufacturer istanzia un broker per dispatchare i dati che vengono dai dispositivi. Quindi i client (iot devices) chiedono i dati e fanno subscription mandando messaggio a broker, e il broker gli manda i dati prodotti da altro dispositivo. Il cloud provider hosta l'applicazione e i servizi: database, un modulo analitico per analizzare i dati che riceve dai sensori, una interfaccia web per mostrare i dati agli utenti. Tutti questi moduli saranno progettati per subscribe ai dati. Questa è l'architettura del sistema._
![[Pasted image 20250327094426.png|350]]
_Frecce rosse = publish; freccia blu in basso a destra = subscribe._
==_Immagine ripresa nei primi minuti del 03.04.2025_==

- Un broker MQTT viene istanziato nel cloud.
- I sensori (client MQTT) pubblicano su topic predefiniti.
- Altri sensori o moduli della piattaforma cloud si iscrivono ai topic.
==min51-54==

### Come si connettono le cose
_**Appunti 2026**: Tuttavia il cloud provider fa anche altro: fornisce uno scheletro per l'applicazione (broker, db, interfaccia, analytics) (in modo da poterti concentrare solo sulla logica, senza dover partire da 0); poiché lo sviluppo veloce è il main goal, in genere fornisce anche un template per il program running on iot devices (quindi si parte da un prototipo da cui iniziare per creare una custom board). Una prototype board è ad esempio il dongle nfr... che ci ha dato la Righetti. Al board ci attacchi altro. Quindi non devi partire da 0 anche in questo caso, ma da un prototipo._
![[Pasted image 20250327095031.png|400]]
L'obiettivo principale è la **rapida implementazione**.
_Strategia:_ I dispositivi si connettono tramite una **rete WiFi locale**, solitamente preesistente (non è necessario nuovo hardware di rete). _(buona soluzione wireless, senza dover aggiungere un gateway per i dispositivi IoT)._
Ogni provider cloud fornisce generalmente uno scheletro iniziale del codice per programmare i sensori su una serie di schede popolari.

_**Appunti 2026**: Altra caratteristica è l'uso del wifi. Il wifi non nasce per l'iot. Questo perché il wifi è energicamente inefficiente. Hai sensori che comunicano con il wifi, ma questa soluzione è inefficiente dal punto di vista energetico (dura meno di una settimana, quando in genere dovrebbe durare un anno o più senza dover cambiare la batteria)._

### Demo _(la vedremo la prossima volta, 03.04.2025)_
![[Pasted image 20250327095151.png|400]]
_**Appunti 2026**: Iot system con un sensore. Connesso a smartphone. Questo sensore è programmato con uno scheletro programmato da Azure (provider). I dati saranno generati randomicamente. I dati saranno trasmessi a un broker e poi ad una applicazione nel cloud. Il sensore pubblica i dati r il broker li inoltra all'applicazione._
_ESP32 è una delle piattaforme iot più popolari (costa poco e ricche specifiche che fornisce (vedi sotto)). E' anche in grado di lavorare attaccato ad una videocamera e le versioni più nuove supportano anche il machine learning. Supporta anche framework Arduino (piattaforma per fai da te informatico) o FreeRTOS._

_==min5del03.04.2025==_
_ESP32 (simil chiavetta a sinistra) (vedi sotto) pubblica i dati, e attraverso il broker arrivano alla real-time web interface._

#### ESP32
- ESP32 è una piattaforma IoT per prototipazione rapida.
- Costo ultra basso: Scheda 5 Euro, Chip 2 Euro.
- Specifiche tecniche: RAM 520 KByte, Microprocessore Dual Core _(non è cosa comune, vedi dongle di lab)_, Design a bassissimo consumo energetico, Hardware crittografico integrato, Wi-Fi 802.11 b/g/n, Bluetooth v4.2 BR/EDR e BLE.
- Supporta Arduino framework (programmazione semplice) o FreeRTOS (sistema operativo completo per sistemi embedded).
- Supportato da molte piattaforme cloud, come Azure, Amazon WS, etc.
  Molti prodotti commerciali già usano questa piattaforma.

==min57==

#### Azure
_Codice per lo svolgimento (sotto)._
- Lista di rapide soluzioni prototipo:
	https://learn.microsoft.com/en-us/azure/iot/concepts-iot-device-selection
- Applicazione Web
	https://learn.microsoft.com/en-us/azure/iot-hub/iot-hub-live-data-visualization-in-web-apps
- Sensore
	https://learn.microsoft.com/en-us/azure/iot/tutorial-devkit-espressif-esp32-freertos-iot-hub

![[Pasted image 20260429095200.png|450]]

#### Svolgimento ==min12-15del03.04.2025==
_Per creare questo esempio non serve molto, lo scheletro viene già fornito._
_Collega la chiavetta, iot-website-azurewebsites.net, va su vscode._
_Si possono vedere dati di temperatura e umidità in real-time._
_Ci vogliono una ventina di minuti, ma non è molto, considerando che fa molte cose._

### Analisi
![[Pasted image 20250327095853.png|400]]
**Vantaggi:**
- Distribuzione rapida e semplice _(vantaggio principale, grazie al supporto del cloud provider, piattaforma e scheletri già disponibili, ci si può concentrare sulla logica)_
- Non richiede l'installazione di una nuova infrastruttura _(usa quella del cloud provider) e non è necessario un nuovo gateway (dal punto di vista dell'utente), in quanto l'utente accede direttamente all'interfaccia nel cloud._
- Si adatta all'infrastruttura Cloud _(scalabile)_
- _Super economico_

**Svantaggi:** ==min60== ==min19del03.04.2025== _(principalmente latenza e reliability)_
- **Il cloud è sempre coinvolto**: _(i dati vanno sempre nel cloud, anche se posizionato lontano; anche se hai altro sensore che deve accedere ai dati)_
    - Le applicazioni a bassa latenza non sono supportate _(se hai applicazione che ha bisogno di ricevere dati da un sensore in poco tempo (tipo 20 secondi(, questo non è possibile)_
    - E' necessaria una connettività persistente _(se internet va down, il sistema iot non funziona, i dati vengono prodotti ma la connessione al broker non è disponibile. Se l'applicazione richiede reliability, questa non sempre è assicurata, dipendi dalla connessione)_
    - Interazioni Machine-to-Machine non possibili _(anche se sono nella stessa rete)_
- **Il WiFi non è stato progettato per l'IoT**:
    - Alto consumo energetico (niente dispositivi a batteria)
    - Copertura limitata al raggio dell'Access Point/Router _(se vuoi espandere la copertura, non puoi farlo)_

![[Pasted image 20250327100022.png|200]]
_Portare l'application logic sotto (vicino agli ESP32) risolve (non in modo perfetto ma meglio do niente) molti svantaggi._

### Casi d'uso _(dal settore industriale)_
#### Casi d'uso - Ispezione della produzione
_**Appunti 2026**: Hai un carrello autonomo che si muove tra più production lines. Questo carrello ha sensori e una videocamera. I dati sono mandati ad un broker che analizza i dati con machine learning, per ottimizzare i percorsi ad esempio. Il risultato viene mandato al dispositivo. I tempi tra sending e risposta (feedback) devono essere brevi, ma in realtà potrebbero essere troppo lunghi. Per questo la latenza è uno degli svantaggi più importanti._
![[Pasted image 20250327100342.png|250]]
Rilevamento dei difetti nei prodotti tramite analisi delle immagini.
Le telecamere sono installate direttamente sulla linea di produzione.
Le immagini vengono analizzate con tecniche di deep learning per individuare difetti o problemi.
Se viene identificato un difetto, l'articolo viene rimosso dalla produzione.
_==min75== IoT non vanno bene per dispositivi in cui non deve esserci latenza, ..._

#### Casi d'uso - Robot autonomo
_**Appunti 2026**: Immagina di avere production line. Qui installi videocamere smart. Immagini mandate a sistema di ML per individuare i difetti. Il servizio esterno analizza le immagini e manda feedback al dispositivo. Se prodotto non va bene viene rimosso dalla produzione. Anche in questo caso la latenza è importante (il prodotto potrebbe essere oltre la fase di ispezione)._
![[Pasted image 20250327100909.png|300]]
Logistica senza conducente, ad esempio caricare e consegnare carichi nel magazzino.
Gestire e supportare sistemi logistici autonomi, ad esempio droni o robot mobili.
Analizzare i dati in tempo reale e gestire i sistemi autonomi, ad esempio modificando il piano di volo dei droni.
I dati vengono analizzati tramite tecniche di IA e ML.

#### Casi d'uso - Realtà Aumentata
_**Appunti 2026**: Hai operatore che con il tablet fa video e mandato a sistema di analisi video. Il feed è mandato all'operatore. E' importante la latenza, potrebbe ricevere un video che lagga, non segue la realtà. Latenza e reliability sono un problema._
![[Pasted image 20250327101114.png|300]]
Realtà aumentata per supportare i lavoratori, ad esempio durante l'ispezione o i processi di produzione regolari.
Analizzare le immagini in tempo reale per arricchirle con informazioni di supporto.
Esempi:
- Arricchire le immagini in tempo reale.
- Realtà virtuale composta da una combinazione di immagini reali e virtuali e un feedback tattile per gli utenti.

### Applicazione locale
Sembra una buona idea tornare al vecchio approccio pre-cloud, dove i dati vengono raccolti e analizzati localmente.
![[Pasted image 20250327101245.png|400]]

_**Appunti 2026**: Quello che vorremmo fare per supportare questi sistemi è adottare una architettura diversa. In particolare vorremmo tornare alla pre-cloud era, dove la computazione era supportata localmente. Vorremmo installare un server locale per hostare i servizi menzionati prima. Le immagini non sono mandate, ma analizzate localmente, in rete locale. Rimossi i problemi di prima di latenza. Ma non possiamo solo buttare via il cloud. Il 90% dei casi d'uso trae beneficio dal cloud, quando non hai bisogno di bassa latenza o reliability. Quindi vorremmo estendere il cloud per offrire servizi locali alle applicazioni che ne hanno bisogno. Per farlo è stato introdotto un nuovo approccio: il fog computing._

==-------------------------------------------------------------------------== 03.04.2025damin15(slide20)
### Fog Computing ==min24==
_**Appunti 2026**: L'idea di estendere il cloud è chiamata **fog compunting** (o **edge computing**). L'estensione aggiunge un additional computing layer, per supportare bassa latenza e applicazioni con reliability alta. L'estensione viene fatta installando un additional layer of application, tra iot devices (user) e il datacenter, più vicino all'user, per supportare applicazioni piccole e semplici._
_Porta la computazione e/o la capacità di storage al bordo della rete, vicino all'utente o vicino al dispositivo iot. Questo per supportare le poche applicazioni "critiche" (che richiedono bassa latenza o alta reliability)._
_Nomenclatura: in questo corso noi useremo fog o edge intercambiabilmente; su internet potresti trovare una piccola differenza ma non ci interessa._

Queste limitazioni sono comuni a tutte le piattaforme Cloud. Per risolvere questi problemi, recentemente è stata adottata un'architettura Cloud estesa che introduce uno strato aggiuntivo, il **Fog Layer**. Composto da nodi installati in prossimità dei sensori, questo strato consente l'esecuzione di una logica applicativa locale e l'analisi dei dati.
_Fog o edge computing: strato che serve ad avvicinare i sensori ai nodi._
![[Pasted image 20250327101518.png|400]]

#### Vantaggi
![[Pasted image 20250403091232.png|250]]
_Il Fog computing risolve alcuni degli svantaggi visti prima._
_Non buttiamo via il cloud, ancora il 90% delle applicazioni ne ha bisogno, ma facciamo estensione (set minimo) per particolari applicazioni (low latency, che richiedono reliability alta o privacy)._
- Eseguire applicazioni e analizzare i dati in prossimità dei sistemi ciber-fisici garantisce:
	- **Bassa latenza** _(low-latency)_
	- **Resilienza alle interruzioni di rete**: il sistema continua a funzionare anche in caso di interruzioni della rete.
	- **Privacy**: i dati non vengono trasferiti a sistemi esterni. _(sotto il tuo controllo)_
- **I vantaggi del cloud computing sono preservati:**
	- I dati (o un set compresso/ridotto) possono comunque essere caricati sul cloud per l'analisi dei big data e la raccolta di dati storici.
	- Esempi: manutenzione predittiva.

===#################################################== 30.04.2026 (finoaslide23)
#### Edge AI / Edge Cloud
_Ci aspettiamo di trovare un ampio raggio di applicazioni. Sono server piccoli o sistemi embedded. Quindi ci aspettiamo applicazioni con logiche più semplici. Ma in realtà possiamo aspettarci anche AI o ML in questi server._
I sistemi fog sono caratterizzati da capacità di calcolo e archiviazione limitate, tuttavia, supportano l'implementazione di tecniche di Data Mining e AI per analizzare i dati in prossimità.
![[Pasted image 20250403091455.png|500]]

#### Fog Hardware
_In genere l'hardware dipende anche dalla posizione/locazione dei dispositivi. Esempi:_
- Sistemi di calcolo incorporato potenziati con capacità di elaborazione e archiviazione arricchite. _(figura 1)_
- I prodotti che supportano il fog computing (es. Cisco IOx _(larger manifacturer of network equipement)_) sono già disponibili sul mercato. _(risorse e capability sono limitati)_ _(figure 2-3)_
- Hardware arricchito con periferiche ad hoc per il calcolo parallelo, supporto grafico e supporto hardware per AI/ML. _(figura 4)_

![[Pasted image 20250403091604.png|150]]$\qquad\qquad$![[Pasted image 20250403091621.png|200]]![[Pasted image 20250403091629.png|100]]$\qquad\qquad$![[Pasted image 20250403091643.png|150]]

#### Tecnologie di Virtualizzazione
_Non vogliamo rimpiazzare il cloud, ma solo estenderlo per adattarlo a tutte le applicazioni._
_...L'applicazione può essere eseguita nell'ambiente virtualizzato, indipendentemente dall'hardware...(==min12del30.04.2026 DR==). in questi casi in genere si usano i container._
- I sistemi di fog computing adottano le stesse tecnologie utilizzate nei sistemi di cloud computing, ad esempio le tecniche di virtualizzazione.
- La virtualizzazione consente di sviluppare applicazioni che si astraggono dall'hardware e dai componenti specifici del sistema, garantendo così compatibilità e distribuzione rapida.
- I sistemi fog adottano tecnologie di virtualizzazione leggere per soddisfare le capacità ridotte. _Questi dispositivi in genere hanno meno risorse (CPU, memoria, ...)._

![[Pasted image 20250403091828.png|400]]

![[Pasted image 20250403091854.png|330]]

#### Gateway/Fog node
_Altro vantaggio di questa estensione: opportunità di implementare un gateway (dispositivi wireless, per implementare altri protocolli di comunicazione che non sono usati di solito ad oggi)._
Introduce un gateway/Fog node installato in prossimità del sistema fisico.
![[Pasted image 20250403093641.png|150]]

Può:
- Eseguire alcune semplici logiche applicative locali e analisi dei dati che richiedono bassa latenza.
- Implementare funzionalità di traduzione dei protocolli.

Permette l'adozione di una tecnologia wireless specificamente progettata per l'IoT, che può essere:
- A bassa potenza
- Con una vasta copertura tramite multi-hop

##### Funzioni del Gateway
- _(freccia da wireless)_ Il Gateway è il dispositivo responsabile di fornire connettività ai dispositivi locali. Se necessario, deve implementare funzioni di traduzione degli indirizzi di protocollo per trasmettere i dati ai dispositivi IoT.  
- _(freccia da gateway)_ Deve anche implementare funzionalità di sicurezza per regolare l'accesso dalle reti esterne.

![[Pasted image 20250403093819.png|300]]

### MQTT ==min41==
_Immagine dal punto di vista dell'infrastruttura._
MQTT non si adatta bene a questa architettura _(è un protocollo centralizzato)_. Dove posizioniamo il broker? Uno nel gateway e uno nel cloud? _No, dovremmo duplicare i dati, sprecando le risorse, infattibile._
Cosa succede se un sensore è di interesse per due applicazioni, una in esecuzione nel cloud e una nel gateway?
_E' inutile metterlo solo nel cloud perché aumenta la latenza._
_Altra opzione è metterlo nel cloud, risolvendo il problema della latenza, ma in genere il gateway è resource constrained device, quindi non è una buona opzione._
![[Pasted image 20250403094026.png|400]]

#### Web of Things
_**Appunti 2026:** MQTT non si adatta bene ad una architettura distribuita. Quindi abbiamo bisogno di un cambio di paradigma per i sistemi distribuiti e per altri problemi che vedremo dopo._
_Il cuore viene spostato dal broker al dispositivo iot. L'dea è quella di usare approccio usato dal web per i dispositivi iot, il cosiddetto web of things. I dispositivi iot dispatchano i dati da soli, senza l'intermediazione di un broker. I dispositivi espongono i dati tramite una interfaccia, come si fa sul web. Quindi è assolutamente necessaria la connettività IPv6, la connessione a internet, per essere raggiungibili dalle applicazioni._

_Soluzione:_ Un approccio Web of Things si adatta bene a questa architettura.
**Ogni sensore fornisce un'interfaccia per esporre i propri servizi** (ad esempio, informazioni o funzioni) alle applicazioni.
L'interfaccia esposta dai dispositivi viene invocata **direttamente** dalle applicazioni **quando necessario**. Le operazioni vengono eseguite allo stesso modo, sia dal gateway che dal cloud.
IPv6, con il suo ampio spazio di indirizzamento, permetterà ai dispositivi di essere raggiungibili direttamente.
![[Pasted image 20250403094230.png|400]]

##### Vantaggi
_Più applicazioni possono interagire con lo stesso dispositivo iot, in modo indipendente dalla posizione del dispositivo ... ==(min25del30.04.2026 DRA)==_
- **Semplice**: non è necessario un broker. _(la comunicazione è diretta)_
- **Efficiente dal punto di vista energetico**: i dati vengono trasferiti solo quando necessario (se nessuna applicazione consuma i dati, questi non vengono trasferiti). _(con il broker i dati in ogni caso dovevano essere mandati al broker, indipendentemente se consumati o meno)._
- **Interfaccia comune**: il recupero dei dati o l'invocazione di funzioni vengono eseguiti allo stesso modo su diversi host.
- **Migliore integrazione con il Web**.