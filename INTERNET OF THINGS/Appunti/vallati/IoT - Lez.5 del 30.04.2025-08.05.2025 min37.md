# 5. Sensor Data Representation
slide2
semantic and data rapresentation $\to$ ancora siamo nella visione di soluzioni orizzontali.
A sinistra vediamo struttura verticale, mentre a destra orizzontale (insieme di reti collegate insieme). Ogni volta che applicazione è installata su infrastruttura ==min38DR==. Cosa vuoi in questo ambiente è scoperto ...
dire all'applicazione che c'è un insieme di sensori (giroscopio, gps,...) e cambiare il comportamento in base a sensori e attuatori. Bisogna solo garantire accesso ai sensori (per sicurezza arriva notifica per chiedere i permessi).
Per raggiungere questi obiettivi ... ==min41DR==
Ci mancano due blocchi per questa visione. Il primo è data semantic: come organizzare i dati in modo che siano interoperabili.

slide3
Ricevere e interpretare i dati correttamente è una cosa, ma ... ==min42== ... Diverso livello è condividere un livello di understanding comune.
Esempio: ho lampadina intelligente, posso gestire l'accensione con documento xml o json. Ho stringa on/off o in binario o true/false.
xml dice solo come i dati sono organizzati, e il contesto, ma non dice come i dati dovrebbero essere interpretati dal recepient e come il recepient dovrebbe agire su quei dati. ==min44DRA==
Questo è la semantica. E questo è un grande problema.

slide4
Vogliamo ottenere che iot devices e applicazione abbiamo understanding condivisa ==min45== su come interpretare e come comportarsi con i dati, in modo che interpretino i comandi allo stesso modo. Data application trova i dispositivi disponibili e comunica. C'è automated discovery dei dispositivi (discovery CoAP), ma manca come interpretare correttamente i dati.
Due livelli:
- tecnical part di come trovare i dispositivi,
- data lista di funzionalità ... ==min47DR==

Interpretare in modo unico/interoperabile l'insieme di funzionalità l'insieme di funzionalità che il dispositivo iot offre. CoAP provide a tool, a language, ma quello che portano in pratica le funzionalità e come dovrebbero essere interpretato è un altro livello che porta al problema.

slide5
==min50== Questo è ancora un problema aperto.
Quello della lampadina è un esempio stupido
Abbiamo bisogno di una understanding condivisa.
Vedremo varie soluzioni in domini molto specifici.

slide6
SenML (Sensor Markup Language) è uno standard per dare un semantic common ==min52DR==.
è un documento che descrive come i dati dovrebbero essere interpretati nel caso di data reporting. Ci sono specificazioni che dicono al sistema come interpretare i dati. I dati possono essere encoded nel linguaggio che preferisci, organizzati in oggetti.

slide7
Ancora non siamo entrati nello specifico di un linguaggio di encoding, ma siamo nel generico.
Campi: vedi slide ==min54== (per data reporting)
- base name = stringa opzionale
- base time = basic time reference per tutte le misurazioni dell'oggetto (opzionale)
- base units = basic unit //
- version
- array of measurements

slide8
Per ogni misurazione abbiamo questi dati:
- name = reference al data generated
- units
- time $\to$ Se il tempo non è provided, è applicato il base time. Se ho tempo specificato allora il tempo sarà base time + tempo specificato.

Sono opzionali se un basic value is provided, ovvero se è valido per tutte le misurazioni dell'array.
==min57/==, a meno di una specifica misurazione (in quel caso è provided).
Per ogni value puoi mettere uno specifico valore (altrimenti quello base).

Poi abbiamo: ==min59==
- value
- sum
- update time = A time in seconds that represents the maximum time before this sensor will provide an updated reading for a measurement

Queste (SenML) specificano la struttura dei dati per common understanding. Come i dati sono encoded è dato dall'encoding language (JSON, XML). Per questi due linguaggi SenML provide delle regole per encoding nel linguaggio.

slide9
Regole per JSON.

slide11
Esempio JSON ==min62==.
Voltage (now) and current (now) and at each second for the previous 5 seconds.
Per ogni oggetto ho 5 misurazioni. Per ogni misurazione ho: nome (voltage, current), unità di misura (u, v), value ...
Alla fine dice come interpretare i dati. bt = dice il tempo (integer che rappresenta data e ora)
Nella prima riga non è specificato il tempo quindi prende il base time. Nella seconda riga invece il tempo è base-5 quindi in realtà è stata fatta prima. Nell'ultima misurazione lo "t":0 poteva essere omesso.

slide12
Esempio: sensore ambientale che riporta umidità.
Unità di misura è RH.
Longitudine e latitudine (coordinate).
Primo set di misurazioni sono le prime 3 righe.
Riga con EL = batteria riportata dal dispositivo.

slide13
altro esempio con più unità di misura (specificate).

slide14-15
Stesso esempio in XML.

==-------------------------------------------------------------------------== ==Fino a slide 15 compresa==

Recap:
Semantic è un problema ancora aperto.
data encoding = ==min2==
Sensor Markup Language è soluzione solo per una cosa ==min3==. è un esempio di cosa ci si aspetta da un linguaggio semantico.

slide16
Secondo problema è automated discovery (==min3==): permette di trovare lista di dispositivi e risorse vicine disponibili. Questo è ancora un problema aperto ma soluzione promettente è IPSO Smart Objects. ==min5==
COAP://IP_ADDRESS/RESOURCE
IPSO esplora la parte di RESOURCE.
Idea: Informazioni in 3 digits/numbers: Object ID, Instance ID, Resource ID (==min6DR==)
- Object ID: ID che identifica la famiglia o il tipo (categoria) di dispositivo ==min8==
- Instance ID: può essere usato per identificare sensori multipli che coesistono sullo stesso ==min10DRA==
- Resource ID: ogni dispositivo ospita un set di risorse (per esempio più sensori), quindi questo ID specifica a quale risorsa mi riferisco

slide17
Esempio di una lampadina smart: it has multiple resource id defined (accensione, oscuratore, colore,...)

slide18-20
slide per riassumere il concetto di semantica
Al momento ci sono sforzi di standardizzazione per definire come le informazioni dovrebbero essere encoded per ogni use case.

==(fino a min14)==