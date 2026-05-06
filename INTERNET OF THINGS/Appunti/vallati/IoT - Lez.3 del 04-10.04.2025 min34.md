# 3. Constrained Application Protocol (CoAP)
## Applicazioni IoT
Protocollo per Applicazioni Constrained (CoAP)
Progettato dal IETF CoRE Working Group – RFC 7252 (June 2014)
![[Pasted image 20250404123933.png|400]]

## CoAP = Constrained Application Protocol
CoAP = **Protocollo web** generico per le esigenze speciali degli **ambienti limitati** (LLNs), in particolare considerando le applicazioni **Machine-to-Machine (M2M)**.
Obiettivo: realizzare un protocollo applicativo per i servizi web (comune con HTTP) ma **ottimizzato per le applicazioni M2M** (Non una versione compressa di HTTP).

### Caratteristiche di CoAP ==min44DR==
- Binding al protocollo di trasporto **UDP**.
- Modello di comunicazione **request/response**, con supporto per scambi di messaggi **asincroni**.
- **Basso sovraccarico** (overhead) dell'intestazione e bassa complessità di **parsing**.
- Semplici capacità di **proxy** e **caching**.
- Mappatura **stateless** con HTTP.
- Supporto per la comunicazione **multicast**.
- Supporto per la **scoperta** delle risorse.

### Modello di interazione CoAP
_Il livello CoAP è solitamente diviso in due sottolivelli:_
- **Request/Response** _(gestisce la consegna e il parsing dei messaggi)_, sopra un livello di
- **Messaggi asincroni** (con affidabilità opzionale) ==min53DR== _(si occupa della gestione delle ritrasmissioni)_
    - Confirmable (CON)
    - Non-confirmable (NON)
    - Acknowledgement (ACK)
    - Reset (RST)

![[Pasted image 20250404124615.png|150]]

#### Request/Response
Stesso modello di HTTP (client/server).
- **Richiesta** $\to$ _caratterizzata da:_
    - Metodo _(GET/POST/PUT/DELETE)_
    - URI della richiesta _per identificare la risorsa sulla quale il metodo è invocato (esempio: CoAP://sensor.com/temp)_
    - Payload e meta-dati opzionali (opzioni CoAP)
- **Risposta** $\to$ _include:_
    - Codice di risposta (esempi: 200 = tutto ok, 404 = non hai i permessi)
    - Payload e meta-dati opzionali

##### Metodi di richiesta ==min60==
_Il protocollo request/response usa anche gli stessi metodi di HTTP (get, post, put, delete)._
_Sicuro (safe) = il risultato non cambia lo stato interno del sistema._
_Idempotente = il risultato non cambia anche se invoco la funzione più volte._
- **GET**: recupera una rappresentazione dello stato della risorsa (**sicuro e idempotente**).
- **POST**: richiede che la rappresentazione inclusa venga elaborata (**né sicuro né idempotente**).
  Di solito comporta la creazione di una **nuova risorsa** o l'aggiornamento della risorsa target. _Può essere utilizzato per scopi di configurazione._
- **DELETE**: richiede che la risorsa venga eliminata (non sicuro ma idempotente).
- **PUT**: richiede che la risorsa venga aggiornata con la rappresentazione inclusa (non sicuro ma idempotente).

##### Codici di risposta
Divisi in tre classi:
- **Successo (2.xx)** $\to$ La richiesta del client è stata ricevuta, compresa e accettata con successo.
- **Errore del client (4.xx)** $\to$ Il client sembra aver commesso un errore.
- **Errore del server (5.xx)** $\to$ Il server è consapevole di aver commesso un errore o è incapace di eseguire la richiesta.

**Esempi**
![[Pasted image 20250404125201.png|300]]       ![[Pasted image 20250404125236.png|300]]

##### Trasporto Request/Response
- CoAP è legato a un trasporto non affidabile (cioè, UDP)
- È necessario un meccanismo di affidabilità leggero
    - **Stop&Wait** per la ritrasmissione con back-off esponenziale
    - **Rilevamento dei duplicati**
- Le richieste e le risposte sono trasportate da messaggi asincroni CoAP, che implementano l'affidabilità opzionale


==------------------------------------------------------------------------------==07.04.2025 ==finoaslide11==

Recap:
==slide 2-3==
protocollo che supporta dispositivi vincolati (ovvero dispositivi con poca ram, poca memoria,... , connettività low power). All'inizio hanno usato HTTP, ma quando le persone hanno iniziato a usare più dispositivi vincolati ha iniziato a non funzionare più bene. Inoltre HTTP è complicato r il dispositivo perde molto tempo a fare comparazioni. CoAP è una rivisitazione di HTTP, basato su UDP. Pacchetti encoded come binary packets.
==slide4==: Request-responses, c'è la possibilità di mettere proxy, low parsity complexity
==slide5==: 4 tipi di messaggi (ripreso a ==min32==)
==slide6==: ...==min5==
==slide7-8==: metodi e codes sono gli stessi di HTTP. (esempi slide 9-10, incluso se hai errore 404)
==slide10==: esempio di un attuatore (smartbulb, lampadina che cambia colore o intensità), input luce accesa e colore. esempio2 (sotto): incrementa l'intensità della lampadina. PUT e POST in questo caso sono simili. POST in genere manda dati al dispositivo che devono essere processati (in genere per decrementare una risorsa). Il client ha una reference alla configuration.

### Trasporto Request/Response (Richiesta/Risposta)
**CoAP** è associato a un trasporto **non affidabile** (cioè, UDP).
_UDP è più semplice di TCP, quindi trasmissione può essere fatta su vari dispositivi. Ci sono alcuni dispositivi che richiedono comunicazioni affidabili (senza gap sui dati collected), quindi bisogna implementare reliable data transfer on application layer. Questo è quello che fa CoAP, introducendo un meccanismo per il trasporto affidabile, che ovviamente è opzionale (puoi disabilitarlo). Inoltre CoAP introduce un meccanismo di detection delle duplicazioni, in questo modo se trova un duplicato può eliminarlo._

È necessario un meccanismo di affidabilità **leggero**, che includa:  
- **Ritrasmissione** Stop&Wait con back-off esponenziale
  _Approccio stop and wait: manda messaggio e aspetta una risposta ack. Se non riceve risposta ritrasmette il messaggio. Altrimenti, senza ack non può mandare altri messaggi._
- **Rilevamento dei duplicati**
  _Il meccanismo reliable ha bisogno anche di un meccanismo di back-off (==min15DR== spiegazione di back-off) (la ritrasmissione aggiunge un delay esponenziale (prima 0-2, poi 0-4, poi 0-8, ...), per riconoscere che è una ritrasmissione). Abbiamo bisogno di questo perché in low power and lossy network ci sono spesso congestioni e quindi packet losses._

Le richieste e le risposte sono trasportate tramite **messaggi asincroni** CoAP, che implementano un'affidabilità opzionale.
_Richieste e risposte sono carried da CoAP. Lo scambio di messaggi può avvenire opzionalmente in modo asincrono. Lo vedremo sugli esempi._

### Trasmissione affidabile (Reliable transmission)
La trasmissione affidabile viene avviata inviando un **messaggio CON**.

_Abbiamo 2 livelli in un messaggio:_
- _request and responses_
- _in quali messaggi request and responses sono inclusi (embedded) - CON messages_

_Il client (sender) decide se vuole interazione affidabile o no con il server, quando manda il CON message. ==min20DR==_

- Il destinatario deve:  
    - Confermare la ricezione con un **messaggio ACK**, oppure  
    - Rifiutarlo (inviando un **messaggio RST** corrispondente o ignorandolo del tutto)
- Il mittente: Ritrasmette il messaggio CON a intervalli crescenti esponenzialmente (timeout iniziale predefinito: 2 secondi), fino a quando:  
    - riceve un messaggio ACK o RST, oppure  
    - esaurisce il numero di tentativi (predefinito: 4)
    - _Il sender ritrasmette il CON message a intervalli che crescono esponenzialmente fino a 4 tentativi. In caso di errore viene mandato un RST message._

I messaggi CON e ACK vengono associati tramite lo stesso **Message ID a 16 bit**.
_CON e ACK sono legati da un messageID incluso nel messaggio._
_CON-ACK implementati per trasmissione request/response._

### Trasmissione non affidabile (Unreliable transmission)
![[Pasted image 20250414163430.png|200]]
La trasmissione non affidabile viene avviata inviando un **messaggio NON** (ad esempio, letture ripetute regolarmente da un sensore).  
Il destinatario NON deve confermare la ricezione del messaggio _(con un ACK)_.
A livello CoAP, non esiste alcun modo per il mittente di sapere se un messaggio NON è stato ricevuto oppure no!  
Per **rilevare duplicati**, viene comunque incluso anche il Message ID. _Lo scopo del messageID in questo caso ha scopo diverso: individuare se ci sono messaggi duplicati e in caso scartarli._
_In questo caso vengono mandate solo una request o solo una response._

### Request/Response
==min27DR==
- Le richieste sono trasportate in messaggi **CON** o **NON**.
- Un **Token** associa le risposte alle richieste. _CoAP aggiunge un campo al messaggio: il token, che collega request e response_
- Non c'è relazione tra Token e Message ID. _(diverso da messageID, Lo vedremo nell'esempio)_
- _Se la richiesta (request) è fatta in un tipo di trasmissione (reliable o unreliable), la response deve essere fatta allo stesso modo._
	- Se la richiesta è in un messaggio CON:
		_In caso di reliable transmission sono definiti due modi per operare (per capire come è portata avanti la risposta) (decisione del server):_
	    - La risposta può essere inclusa nel messaggio ACK risultante (piggy-backed),
	      _**piggy-backed mode** (==min29==) $\to$ la risposta è mandata come payload dell'ack. $\to$ metodo più efficiente (con un solo messaggio risolvi due problemi), riduce overhead._
	      oppure
	    - Inviata in un nuovo messaggio CON (separato).
	      _**separate mode** $\to$ manda un ACK senza payload immediatamente e poi manda la risposta in un CON message separato (poi il client manda un ACK della risposta)._
	- Se la richiesta è in un messaggio NON: La risposta viene inviata in un nuovo messaggio NON.

**Esempio**: Richieste GET con risposte piggy-backed
![[Pasted image 20250416093652.png|170]]            ![[Pasted image 20250416093701.png|170]]
_**Image sx** $\to$ sinchronous data exchange: client manda una request con il CON message (id e token), server manda una response con stesso id e token (in questo caso uguale). In questa immagine manca una parte: l'ack che il client manda al server alla fine._
_**Image dx** $\to$ uguale ma ho error message (comunque il client alla fine manda ACK (manca nell'immagine))._

**Esempio**: Richiesta GET con risposta separata _(asynchronous data exchange)_
![[Pasted image 20250416093618.png|170]]
_Quando il server decide tra sincrono o asincrono deve settare il tempo. Se il sensore richiede molto tempo a produrre la risposta, allora la modalità asincrona (separate) è l'unica opzione (manda ack vuoto per non avere ritrasmissioni nel frattempo) (altra modalità avrebbe avuto ritrasmissioni del messaggio)._
_Riassumendo: ==min38==_
_Spiegazione immagine: il client manda CON message, server manda ACK e dopo un po' genera il payload e manda la response (con la misurazione della temperatura) (il token è diverso dall'ack mandato poco prima), client manda ACK con stesso token della response._

**Esempio**: Richiesta e risposta NON
![[Pasted image 20250416093747.png|170]]
_In caso di trasmissione unreliable, lo scambio di messaggi è più semplice (comunque c'è id e token). In questo caso gli id sono diversi perché i messaggi sono indipendenti, l'id serve solo per individuare i duplicati._

**Richieste/Risposte e messaggi CoAP**
- _CoAP permette anche di mandare messaggi (CON o NON) vuoti (empty) al server, per controllare che il server esista e sia online._
- Un **messaggio vuoto** (_Empty message_) non è né una richiesta né una risposta (identificato da un codice speciale).
	![[Pasted image 20250416094343.png|250]]
- Un **messaggio vuoto** all'interno di un **CON** viene usato per sollecitare un **RST** (detto anche _"CoAP ping"_).

### Formato del messaggio
![[Pasted image 20250416095721.png|400]]
I messaggi hanno un formato binario _(motivo: ==min48DR==)_
Header di quattro byte a dimensione fissa.
_I messaggi hanno una dimensione fissa, quindi è più facile crearli e gestirli. Usi bitmap per isolare i campi (bit) di cui hai bisogno. Campi:_
- **Versione**: attualmente 1
- **Tipo (T)**: tipo di messaggio (CON (0), NON (1), ACK (2), RST (3))
- **Token Length (TKL)**: al massimo 8 byte
- **Codice (Code)**: suddiviso in 3 bit di classe e 5 bit di dettaglio (c.dd)
	- Classe: richiesta (0) (==min51DR==) _(se inizia con 0, allora i bit dopo servono a encode the method of the request)_, risposta di successo (2), errore lato client (4), errore lato server (5)
	- Dettaglio: specifica il metodo (es. 0.01 è una GET) o il codice di risposta (es. 2.04 è 'Created')
	- Il codice speciale 0.00 indica un messaggio vuoto (Empty message)
- _message ID_
- _token_
- _set di opzioni  (unica parte che può avere lunghezza variabile)_
- _payload (length not fixed, hai un massimo ma non un minimo)_

#### Definizione delle opzioni ==min57==
`coap-URI = "coap:" "//" host [ ":" port ] path [ "?" query ]`
![[Pasted image 20250416100640.png|450]]
L'URI della richiesta è suddiviso nelle opzioni Uri-Host, Uri-Port, Uri-Path e Uri-Query.
_Tabella possibili opzioni. Non andremo nei dettagli, ne vedremo solo alcune:_
- _Max-Age (No.14) = expiration time of the information (usata dal client) ==min58/==, per esempio: questa informazione rimane vera per i seguenti tot secondi, poi non è detto. (ripreso a ==min72==)_
- _Proxy-Uri e Proxy-Scheme (spiegato dopo: ==min70==)_

### Proxying (terminologia)
_Proxy era stato implementato anche su HTTP. Terminologia:_
- **Endpoint**: _un nodo CoAP che partecipa alla comunicazione._
- **Sender/Recipient**: _mittente e destinatario di un messaggio._
- **Client/Server**: _ruoli ricoperti dagli endpoint nella comunicazione._
  _Client e server sono endpoint (ovvero nodi che implementa CoAP)._
- **Origin server**: _il server finale che detiene la risorsa richiesta = server che produce l'informazione (in questo caso il sensore)._
- **Intermediary**: un endpoint CoAP che agisce sia come server verso il client, sia come client verso l’origin server.
  _Proxy = nodo che fa da intermediario tra client e origin server (vedi image a destra). Ruolo: si comporta come un server dal punto di vista del client e si comporta come client rispetto all'origin server, per implementare alcune funzioni che argument the conversation ... ==min63DR==. Intercetta tutte request e responses per implementare ulteriori funzionalità._

![[Pasted image 20250416101344.png]]            ![[Pasted image 20250416101400.png]]            ![[Pasted image 20250416101415.png]]

#### Proxy CoAP
Un intermediario si occupa principalmente di:
- **inoltrare** le richieste e **ritrasmettere** le risposte
- eventualmente eseguire **caching**, traduzione degli spazi dei nomi (namespace translation), traduzione del protocollo (protocol translation)


![[Pasted image 20250416102024.png|300]]
_Le frecce da proxy verso il server sono opzionali, visto che c'è la cache._

_Perché introduciamo un proxy? Più motivazioni:_
- _migliori performances e minor overhead (proxy può implementare cache funtionalities) (minore congestione sul server)_
- _namespace translation (? ==min67==)_
- _security (in genere proxy implementato su powerful node) (per bloccare comunicazioni pericolose)_

#### Forward Proxy e Reverse Proxy
CoAP standard implementa due tipi di proxy. Differenza: quanto è trasparente il proxy al client.

##### Forward Proxy
_Il forward proxy non è trasparente al client. Il client è cosciente dell'esistenza del proxy, quindi deve trigger il proxy quando manda messaggi. Può farlo usando le opzioni Proxy-Uri e Proxy-Scheme. Proxy può implementare varie funzionalità (==min71==). Caso d'uso principale: cache._
Esegue le richieste per conto del client:
- Il punto finale è selezionato dal client
- Esegue tutte le traduzioni necessarie

![[Pasted image 20250416102639.png|350]]
L'opzione Proxy-Uri viene utilizzata per specificare il proxy.  
La destinazione rimane il server, **NON è trasparente**.

##### Reverse Proxy
_Il reverse proxy è completamente trasparente dal punto di vista del client. Proxy è installato all'edge della rete IoT. Scopo principale: security, scopre dispositivi che vogliono interagire, espone (esposes) le risorse del dispositivo IoT come fossero le proprie. ==min74==. La prossima volta vedremo come fa questa discovery._
Il Reverse Proxy soddisfa le richieste per conto di uno o più server:
- È trasparente per il client
- Esegue tutte le traduzioni necessarie

![[Pasted image 20250416102936.png|350]]

#### Proxy di traduzione (Proxy translation)
_Altro caso d'uso dei proxy: Protocol translation. Proxy trasforma request da HTTP a CoAP e viceversa._
Proxy cross-protocol (Cross-Proxy): un proxy che esegue la traduzione tra protocolli diversi
- Proxy CoAP-to-HTTP
- Proxy HTTP-to-CoAP

_Esempio: sensore IoT che vuole informazioni da Internet (?): vedi immagine sotto. ==min77==_
![[Pasted image 20250416103146.png|250]]

_Esempio2: HTTP client vuole informazioni da server CoAP._

==-------------------------------------------------------------------------== nexttime (finoaslide27)

_Coap include security features (anche se non le vedremo)._

## CoAP: Osservazione delle risorse
### Osservazione delle risorse CoAP
_Resource observing è una delle prime feature su CoAP che non sono su HTTP, fatte apposta per il caso IoT. ==min4==_
E se un client fosse interessato a ricevere aggiornamenti continui sullo stato di una risorsa?
- Polling continuo: Quale periodo usare? Qual è il sovraccarico? 😞 _Inefficiente_
- **Observer pattern**: Somiglia a un’interazione tipo PUB/SUB (pubblica/sottoscrivi). ☺ _Più efficiente ed elegante_

![[Pasted image 20250416121350.png|300]]

_**Esempio**: sensore temperatura. Hai attuatore che vuole che quando temperatura sale/scende troppo fa qualcosa (attiva riscaldamento o raffreddamento). Come farlo?_
_L'unica cosa che puoi fare è **polling**: monitorare periodicamente la temperatura. Questo può essere fatto ma non è efficiente, in quanto: l'attuatore deve svegliarsi, fare request, ottenere response che a volte ha lo stesso valore (temperatura non cambia molto in pochi secondi). E' anche inefficiente dal punto di vista del sensore. Quindi continuous polling porta a overhead._
_Per migliorare l'efficienza di questo tipo di operazioni è stato introdotto un nuovo pattern / meccanismo (non disponibile in HTTP): **resource observing**, una optional dedicated solution per questo tipo di problemi._
_Idea di base del resource observing: prendere ispirazione dal publish subscribe methodology (un design pattern). Ricevere update ogni volta che c'è un cambiamento. Ho due sensori: uno manda update e uno riceve notifica quando lo stato della risorsa cambia. Il broker inoltra l'update ogni volta che un update è generato._
_Come lo implemento? Questo observing mechanism è opzionale (risorsa non sempre è osservabile). Richiesta con il GET per iniziare the relationship, response data con etichetta (la vedremo), basata su dei criteri. Client non deve mandare un'altra richiesta se è subscribed, quando ci sono cambiamenti sensore manda una notifica. Per interrompere le notifiche il client deve mandare uno specifico messaggio (recept? ==min14==)._

### Panoramica del protocollo
_Basato sul design pattern dell'observer._
**Observer** design pattern: Il provider gestisce una lista di osservatori per ogni soggetto monitorato.

**Con CoAP**  
- Soggetto = Una risorsa su un server CoAP.
- Osservatore = Un client CoAP.
- Registrazione = Una **richiesta GET estesa**.
- Notifica = Una risposta CoAP aggiuntiva inviata ai client registrati ogni volta che lo stato della risorsa cambia.

![[Pasted image 20250416121644.png|150]]
_ Si fa la registration e dopo il server riceve una notifica con lo stato della risorsa ogni volta che è soddisfatto un certo criterio._

**Esempio**
![[Pasted image 20250416121802.png|400]]
- Registrazione e notifiche sono identificate dalla presenza dell’opzione "Observe"
- L’opzione "Observe" include un numero di sequenza per rilevare eventuali riordini dei messaggi
- Registrazioni e notifiche sono correlate tramite il token

_Immagine: esempio di scambio di messaggi. Primo è un GET della risorsa con opzione empty (in quanto deve esserci sempre nel messaggio)._
_Sensore risponde. Stabilita la relazione ==min16DR==_
_Ogni messaggio è praticamente una risposta al primo messaggio (quindi sempre stesso token)._
_Notification sono mandate da server a client depending on a certain policy che decide il programmatore (dipende dall'applicazione)._

#### Observe option
![[Pasted image 20250416122246.png|450]]
![[Pasted image 20250416122256.png|450]]

### Risorse osservabili ==min19==
_Quando va mandata la notifica? Ogni volta che lo stato della risorsa cambia (primo caso della slide). Tuttavia in alcuni casi questo potrebbe risultare troppo, per esempio se ho un sensore molto preciso riceveremmo molte notifiche._
Spetta al server decidere quali risorse esporre come osservabili, ovvero che **cambiano stato** in modo utile per il contesto applicativo.
- `coap://server/temperature`  
	Cambia stato ogni secondo in base alla lettura corrente del sensore di temperatura.
	_In genere si applica questo caso._
- `coap://server/temperature/felt`  
    - Cambia stato in "cold" quando la temperatura scende sotto una soglia preconfigurata.
    - Cambia in "warm" quando la temperatura supera una seconda soglia, leggermente più alta.
    - _Approccio meno scientifico. La soglia è preconfigurata dal server, mentre nel caso successivo la soglia è specificata dal client._
- `coap://server/temperature/critical?above=45`  
	_Il server può implementare un meccanismo per cui per esempio se la temperatura supera una certa soglia._
    - Cambia stato ogni secondo in base alla lettura corrente se la temperatura supera la soglia specificata dal client.
    - Cambia in "OK" quando la temperatura scende sotto la soglia _(specificata dal client)_.

### Coerenza (consistency)
_Consistency:==min29DR==_
Fino a che punto la vista del client è sincronizzata con lo stato della risorsa?
Latenza, notifiche perse e/o riordinate, cancellazione errata della registrazione. _La notifica potrebbe perdersi o essere reordered._

Approccio **Best effort**  
- Il prima possibile  
- Quanti più stati possibili

Limitare la durata del tempo fuori sincronia con un **massimo di età** allegato alle notifiche $\to$ _max age option: massima durata di validità dell'informazione._

(==manca una slide==, cancellabile) ==min32==
_L'ordine delle notifiche potrebbe non essere giusto._

### Intermediari
_Intermediario in questo caso è il proxy._
_Per ogni client il server deve avere una struttura dati in cui conservare i dati. Se il server ha molti client (e quindi observer) e poca RAM potrebbe esserci un problema. Soluzione sono intermediari (complessità passa agli intermediari)._
Non esiste un concetto di osservazione end-to-end quando il server di origine è raggiunto attraverso una catena di intermediari.
Le implementazioni del proxy potrebbero sfruttare tale flessibilità.

![[Pasted image 20250416125657.png|200]]
_Esempio immagine: reverse proxy, riceve la request, reply e dopo stabilisce 1 relationship service con l'observer. Quando riceve notifica manda più notifiche, una ad ogni observer. In questo modo il sensore deve interagire solo con gli intermediari e poi il proxy interagisce con i client._
_(Parole mie: praticamente se il sensore ha risorse limitate (CPU, energia, banda, RAM) e non può gestire molte connessioni contemporaneamente, passa le notifiche agli intermediari che invece hanno risorse migliori.)_

## CoAP discovery
_Discovery è l'ultima componente di CoAP che vedremo (ce ne sono altre ma non le vedremo, per esempio: block wise transfer = per trasmettere dati più grandi, come immagini)._
_C'erano delle feature simili su HTTP, ma non molto usate._
_Discovery = capacità di scoprire sensori, attuatori, o dispositivi iot che hanno determinate caratteristiche, capire i loro ruoli e funzionalità senza intervento umano (credo). ==min39==_
_Se non hai questo meccanismo hai bisogno di operatore umano._

_Applicazione trova in automatico tutti i dispositivi._
_Due distinti processi/step:_
- _tu come applicazione devi scoprire tutti dispositivi disponibili (in lista)_
- _per ogni dispositivo devi trovare lista di risorse e funzionalità o dati che possono provide_

_In questo modo hai una completa discovery._

### Scoperta dei servizi
_Service discovery: per trovare tutti i coap services in una certa area locale._
Come scoprire i server CoAP?
- Multicast CoAP + indirizzo multicast "All CoAP Nodes" ==min42DRA==
    La scoperta è limitata allo scopo link-local!
- Numero di porta predefinito ben noto: 5683

_Questi nodi sono required to respond._
_Applicazione manda multicast request, tutti i nodi con coap ricevono la request e rispondono con una risposta dicendo che hanno implementato coap._
_Limiti: multicast message can be sent only locally (same LAN), altrimenti hai un problema._
_Se application is running outside, devi usare un approccio diverso. In  questo ultimo caso devi usare un resource directory (una sorta di broker)._
_Resource directory = ==min45DR==._

### Scoperta delle risorse
_Per il secondo passo (hai la list of service), manda resource discovery e nel payload della response ricevi anche una lista delle risorse disponibili di ogni server. ==min47DR==._
Come scoprire quali risorse sono ospitate dal servizio?
- URI
- Formato e interfaccia  

URI relativo ben noto `/.well-known/core` = Punto di ingresso predefinito per richiedere l'elenco dei collegamenti alle risorse ospitate da un server. 
_/.well-known/core è mandatory, deve essere exposed da ogni risorsa. Usata per resource discovery. ==min49DRA==_

CoRE Link Format per descrivere i collegamenti (risorse) ospitati dal server

#### CoRE Link Format
Formato dei Link: formato simile ai valori degli header HTTP
Esempio: `</sensors/temp>;if="sensor"`
_... Hai sequenza di attributi con informazioni su tipo di risorsa, formato dei dati,..._

- Collezione di link (separati da virgole)  
- Ogni link è descritto da:  
    - Un URI relativo  
    - Un numero di attributi

### Attributi del Link
- **Tipo di Risorsa ('rt')** = Stringa opaca utilizzata per assegnare un tipo semantico specifico dell'applicazione a una risorsa.
- **Descrizione dell'Interfaccia ('if')** = Stringa opaca utilizzata per fornire una definizione specifica dell'interfaccia utilizzata per interagire con la risorsa target.
  _Interface Description specifica interface definition, general demain of device._
  Es.: l'URI di un Web Application Description Language.
- **Stima della Dimensione Massima ('sz')** = Un'indicazione della dimensione massima della rappresentazione della risorsa.
- **Formato del Contenuto ('ct')** = Fornisce un suggerimento sui Formati di Contenuto che questa risorsa restituisce _(JSON, XML, ...)_.
- **Osservabile ('obs')** = Un suggerimento che indica che la destinazione di un link è utile per l'osservazione _(dice se risorsa è observable)_.

### Filtraggio delle query
_Opportunità di includere dei parametri (es. name=value)._
- La risorsa `/.well-known/core` è destinata a essere utilizzata per restituire link ai punti di ingresso delle interfacce delle risorse su un server
- Il filtraggio può essere eseguito
    - GET /.well-known/core?name=value
    - Nome: 'href' (risorsa target) o nome dell'attributo
- Esempi: ==min52==
    - `?href=/foo`
    - `?href=/foo*`
    - `?rt=temperature-c`

_Immagine esempio di richieste (get, response di sensori di temeprsturs e luce, content type, ...) per avere una idea._
![[Pasted image 20250416131239.png|500]]