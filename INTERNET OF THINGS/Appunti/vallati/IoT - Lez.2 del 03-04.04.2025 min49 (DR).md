# 2. Web of Things
_Il web of things è solo l'ultimo step dell'evoluzione dei dispositivi iot (vista con Anastasi). Web of things è concetto semplice. CoAP è proprio l'ultimo passo._

### Recap: Approccio orizzontale IoT
- **Web of Things** $\to$ MQTT, CoAP
- **IP(v6) per gli Smart Objects** $\to$ 6lo

![[Pasted image 20250327090953.png|200]]
**Protocolli standard** (IP per oggetti smart): Un insieme di soluzioni basate su IPv6 è stato definito dall'IETF (6LoWPAN, ROLL, COAP). Supportato dall'IPSO Alliance.

### Web per IoT – Perché?
_Per avere paradigma più semplice. L'interazione deve essere semplice e può scalare (scale up)._
Come integrare i componenti delle applicazioni dei dispositivi in applicazioni IoT su larga scala?
![[Pasted image 20250403095042.png|400]]

_Questa idea del web viene da molto tempo fa. Noi vedremo l'evoluzione del web e all'architettura delle tecnologie web per vedere vantaggi e svantaggi nell'applicarle al mondo iot._

_...(2025) slide saltate..._

## Architetture orientate ai servizi
_Contesto: ==min55==_
- Sistemi distribuiti a stretta vs. larga connessione
    - Sistemi sotto la stessa autorità di controllo
    - Sistemi cooperanti di diverse organizzazioni autonome
- Concetto di **servizio** = Unità di base che racchiude una logica applicativa

![[Pasted image 20250403095455.png|300]]

- I servizi sono consapevoli l'uno dell'altro tramite l'uso di **descrizioni dei servizi**.
    - Nome del servizio e dati previsti (e restituiti)
- I servizi scambiano informazioni tramite **messaggi**.
    - Unità di comunicazione indipendente.
    - Sono consentiti più schemi di scambio.

![[Pasted image 20250403095628.png|300]]

![[Pasted image 20250403095654.png|350]]
==min58== ==ripreso a min4 del 04.04.2025==
_Service broker diverso da MQTT broker. Ha il ruolo di directory, ha una lista di tutti i consumers._

## World Wide Web
- **Origini** (1989, CERN, Tim Berners Lee)
    - Un sistema per condividere facilmente documenti di ricerca.
    - Tre componenti:
        - Un meccanismo per identificare i documenti
        - Un protocollo per scambiare i documenti
        - Un linguaggio per codificare i dati (permettendo l'accesso non sequenziale).
- **Il Web oggi**
    - Una piattaforma mondiale per lo scambio e la gestione di dati generici
        - Una vasta raccolta di dati multimediali
        - Un'interfaccia per accedere alle applicazioni in rete
        - **Una piattaforma che consente l'invocazione di servizi generici in sistemi di calcolo distribuiti (Web).**

_Vediamo le componenti (elementi/meccanismi/pilastri) del WWW: identificazione, scambio di dati, codifica dei dati._

### Le 3 componenti del WWW
#### Identificazione
- Un **Uniform Resource Identifier (URI)** è una stringa compatta di caratteri per identificare una risorsa astratta o fisica.
- **Identificatore** = Una stringa con una sintassi ristretta.
- **Risorsa** = Qualsiasi entità che ha un'identità (Un documento elettronico, un'immagine, un servizio, una raccolta di altre risorse).
- **Uniforme**
    - Diversi tipi di risorse identificate nello stesso contesto.
    - Convenzioni sintattiche comuni.
    - Flessibilità di estensione.

#### Scambio di dati
**Hypertext Transfer Protocol (HTTP)** è un protocollo a livello applicativo per sistemi di informazioni distribuiti, collaborativi e ipermediali.
![[Pasted image 20250403100533.png|300]]

#### Codifica dei dati ==min66DR==
HyperText Markup Language _to design information in hypertext document._
![[Pasted image 20250403100657.png|400]]

_Queste sono le tre componenti fondamentali._
_Se vuoi usare queste tre tecnologie come devi fare?_

### Evoluzione verso i Web Services
- URI è un meccanismo di identificazione naturalmente estensibile _(like it)_
- HTTP è un protocollo di comunicazione molto stabile _(like it)_
- Codifica dei dati
    - HTML va bene per la presentazione dei dati _(like it)_
    - Non va bene per la codifica dei dati applicativi _(dislike)_
- Serializzazione dei **dati applicativi**

![[Pasted image 20250403100943.png|200]]             ![[Pasted image 20250403101210.png|400]]
_A sinistra = consumer, freccia verso destra = REQ, freccia verso sinistra = resp, a destra = producer_

### XML
_XML = generalizzazione di HTML, per codificare ogni tipo di dati._
- Metalanguage di markup (W3C 1a ed. Dic. 2000).
- Codifica basata su testo.
- Regole per specificare linguaggi di markup (per **applicazioni XML**):
	- Sintassi comune
	- È possibile anche la specifica della grammatica.
- Perché estensibile? Il set di tag non è predefinito.

==---------------------------------------------------------------------------------------== ==04.04.2025==
### Servizi Web
- **SOAP** (Simple Object Access Protocol)
    - "Protocollo leggero destinato allo scambio di informazioni strutturate in un ambiente decentralizzato e distribuito"
    - Framework di messaggistica basato su XML    
		- I messaggi SOAP possono essere scambiati su qualsiasi protocollo (ad esempio, HTTP, SMTP)
		- I messaggi SOAP originano da un mittente SOAP iniziale e vengono inviati a un ricevitore SOAP finale tramite zero o più intermediari SOAP.
		  Sono supportati più schemi di scambio messaggi: unidirezionale, richiesta/risposta, peer to peer
- **WSDL** (Web Services Description Language)
    - "Grammatica XML per descrivere i servizi di rete come raccolte di endpoint di comunicazione in grado di scambiare messaggi"

I servizi sono consapevoli l’uno dell’altro tramite l’uso di descrizioni dei servizi (Nome del servizio e dati previsti (e restituiti)). $\to$ WSDL
I servizi scambiano informazioni tramite **messaggi**
- Unità di comunicazione indipendente
- Sono consentiti più schemi di scambio $\to$ SOAP

![[Pasted image 20250404120135.png|300]]

![[Pasted image 20250404120204.png|300]]

### Servizi Web per IoT
Espone le capacità di sensorizzazione e attuazione alle applicazioni client come servizi web IoT.
![[Pasted image 20250327085120.png|400]]

![[Pasted image 20250404120336.png|400]]

### Servizi Web RESTful ==min17==
Un ulteriore concetto: **REST (REpresentation State Transfer)**
- Architettura orientata alle risorse per sistemi distribuiti.
- Le applicazioni client **non invocano servizi**, ma **interagiscono con le risorse** per accedere ai servizi web RESTful.
- L'interazione avviene tramite **quattro azioni standard CRUD**:
    - **Create**: creare una nuova risorsa a partire dai dati della richiesta.
    - **Read**: leggere lo stato di una risorsa.
    - **Update**: aggiornare lo stato di una risorsa a partire dai dati della richiesta.
    - **Delete**: eliminare una risorsa.
- Una rappresentazione dello stato della risorsa viene recuperata come risultato dell’interazione.
- Approccio **centrato sul Web**.
- I metodi HTTP sono associati alle azioni:
    - **POST**: crea una nuova risorsa a partire dai dati della richiesta
    - **GET**: legge una risorsa
    - **PUT**: aggiorna una risorsa a partire dai dati della richiesta
    - **DELETE**: elimina una risorsa
- Gli URI forniscono un metodo per identificare le **risorse** cyber-fisiche:
    - `http://example.com/sensors`
    - `http://example.com/sensors/temp`

#### Google Maps API (GET)
![[Pasted image 20250403102301.png|450]]
_Quello in basso è un documento XML._
_Usando i $<$type$>$ abbiamo ridondanza ==min34==_

#### Esempio: lettura dei dati di un sensore (GET)
![[Pasted image 20250404121319.png|450]]

#### Esempio: accensione di una luce (PUT)
![[Pasted image 20250404121424.png|370]]

#### Esempio: aumentare l'intensità luminosa (POST)
![[Pasted image 20250404121548.png|370]]

## Web of things
I **servizi web RESTful** sono emersi come un approccio predominante per il **Web of Things**.
**Vantaggi**: Meno sovraccarico, minore complessità di parsing, integrazione più stretta con HTTP, stateless.
Tuttavia, le risorse IoT sono ospitate da dispositivi limitati connessi a reti limitate.
- **URI** è un sistema di identificazione estensibile :)
- **HTTP** (su TCP) è stabile, ma presenta un grande sovraccarico e complessità :( $\to$ **nuovo protocollo CoAP (Costrained Application Protocol)**
- **XML** è flessibile, ma comporta un grande sovraccarico e complessità :( $\to$ **codifica alternativa e rappresentazione dei dati**.

