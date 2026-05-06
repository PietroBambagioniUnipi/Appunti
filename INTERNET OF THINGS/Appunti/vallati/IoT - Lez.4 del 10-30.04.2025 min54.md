# 4. Data encoding (XML, JSON and EXI)
_(il numero delle slide che riporto è quello effettivo del pdf, non quello scritto sulle slide)_
## Servizi Web per IoT
Intro: abbiamo una idea di come i dati sono trasmessi (via CoAP, metodo standard).
CoAP tuttavia non dice come encode the informations. Ti dice solo metodo per mandare e ricevere messaggi (vedi immagine). Ma non dice nulla del payload (vedi ???? nell'immagine, in basso). CoAP ha struttura standardizzata, ma poi non specifica come encode i dati. Come fai senza uno standard (non avresti interoperabilità)? Usi encoding languages standardizzati, i più comuni sono XML e JSON (visto che hanno dei difetti hanno introdotto anche EXI, introdotto per IoT devices).

![[Pasted image 20250410084510.png|450]]

## XML
### XML document ==min60DR==
![[Pasted image 20250416131626.png|600]]
_Il documento XML ha una architettura gerarchica, gli elementi sono organizzati in modo gerarchico._

- Un documento XML è una sequenza di caratteri
- Un carattere è un'unità atomica di testo
    - Tabulazione _(Tab)_, Carriage Return, Line Feed
    - Caratteri legali di Unicode e ISO/IEC 10646
- Un documento consiste in dati di caratteri e markup mescolati insieme.
    - Il **markup** prende la forma di:
        - Elementi: `<tag>...</tag>`, `<empty_tag />` _encoding fatto usando tags_
        - Riferimenti di entità: `&entity_name;`
        - Commenti: `<!-- qualsiasi testo -->`
        - Istruzioni: `<?processing_instruction data ?>`
        - Sezioni CDATA: `<![CDATA[ ... ]]>`
    - **Dati di caratteri**: tutto il testo che non è markup


_danno idea al lettore di cosa stiamo parlando_
_markup fatti sottoforma di elementi..._

### Elementi
- Un elemento è costituito da:
    - Un tag di apertura: `<Nome>` _(ogni documento deve avere start tag)_
    - Un contenuto _information (meta information). Il contenuto può essere un insieme di elementi._
    - Un tag di chiusura: `</Nome>`
- `Nome` è il tipo di elemento:
    - Può avere qualsiasi lunghezza.
    - Deve iniziare con una lettera o un underscore (`_`).
- Ogni tag di apertura deve avere il corrispondente tag di chiusura.
- Il contenuto può essere:
    - Un insieme di elementi.
    - Vuoto (Sintassi speciale: `<anEmptyTag />`).
    - Misto: elementi più dati testuali (character data)

### Attributi
- _Ogni elemento può avere degli attributi (opzionale)._
- Coppia nome/valore associata a un elemento: _Ogni elemento ha una coppia name/value associata._
    - `att-name = "att-value"`
- Tutti gli attributi devono essere specificati nel tag di apertura.
- I valori devono sempre essere racchiusi tra virgolette (singole (`'`) o doppie (`"`)).
- I nomi degli attributi devono essere univoci.

_Non ci sono regole su come codificare (encode) l'informazione (dipende dallo sviluppatore): vedi immagine._
![[Pasted image 20250512090312.png|500]]

### Riferimenti a entità
- Un'entità è un frammento di documento XML ben noto a cui è stato assegnato un nome
  Es.: `"3.14"` con il nome `PiGreco`.
- Sintassi del riferimento a entità:
    - Il carattere ampersand (`&`)
    - Il nome dell'entità
    - Un punto e virgola (`;`)
- Esempio: `&PiGreco;`
- _Un riferimento può puntare ad altri punti del documento o a entità esterne._
- Entità di caratteri predefinite:
    - `&amp;` (carattere `&`)
    - `&lt;` (carattere `<`)
    - `&gt;` (carattere `>`)
    - `&apos;` (carattere `'`)
    - `&quot;` (carattere `"`)

### Sezioni CDATA _(Character Data, dati di caratteri)_
- _Un documento XML può contenere una sezione CDATA, contenente raw data: misurazioni, ..._
- _Obiettivo: permettere allo sviluppatore di mettere raw data che non sono XML data (ad esempio può essere codice), che non segue le regole di XML._
- Le sezioni CDATA servono per evitare che le regole di sintassi XML vengano applicate a una porzione di testo.
    - Le sezioni CDATA non possono essere annidate una dentro l'altra.
- Sintassi di una sezione CDATA:
    - Tag di apertura: `<![CDATA[`
    - Qualsiasi sequenza di caratteri, tranne la sequenza di chiusura (`]]>`)
    - Tag di chiusura: `]]>`

```xml
<sample>
	if ( this-&gt;getX() &lt; 5 &amp;&amp; v[0] != 3 )
	cerr &lt;&lt; this-&gt;displayError();
</sample>
<sample>
	<![CDATA[
		if ( this->getX() < 5 && v[0] != 3 )
		cerr << this->displayError();
	]]>
</sample>
```

### Documenti ben formati
- _E' necessaria una struttura dei documenti standard (well formed documents) per avere uno sviluppo sostenibile ed efficiente dei programmi. I documenti devono essere interpretati dalle macchine quindi bisogna seguire le regole (se manca un carattere tipo `;` potrebbe essere un problema)._
- La specifica XML è fondamentalmente un insieme di regole generali di sintassi _(come strutturato)_:
    - Deve esserci uno e un solo elemento radice _(root element)_ (detto anche elemento del documento).
    - Gli elementi devono essere correttamente annidati.
    - I nomi dei tag di chiusura devono corrispondere ai tag di apertura.
    - I nomi degli attributi devono essere univoci.
    - ...
- XML è **case sensitive** _(distingue tra maiuscole e minuscole)_!
- Un documento di testo che rispetta tutte queste regole si dice **ben formato** (well formed)!
  _XML è well formed = rispetta le regole, quindi può essere interpretabile dalle macchine._

_Esempio $(*)$ di well formed document (web service XML molto usato):_
![[Pasted image 20250512093158.png|600]]

_Esempio di un errore (sity al posto di city):_
![[Pasted image 20250512093303.png|600]]

### Conflitti di nomi
I documenti XML combinano spesso linguaggi diversi (applicazioni XML), di conseguenza potrebbero sorgere conflitti nei nomi delle entità.
``` xml
<product type="screw">
	<head>cross</head>
	<size><big /></size>
	<info>
		<head>
			<title>Description of product</title>
		</head>
		<body>
			<h1>Screw</h1>
			...
		</body>
	</info>
</product>
```

_Passi da fare:_
- _step 1: il documento è well-formed_
- _step 2: il documento ha senso_

==--------------------------------------------------------------------------== 30.04.2025(finoaslide13)

### Namespace (Spazi dei nomi)
- Uno spazio dei nomi:
    - Identifica in modo univoco una collezione di elementi (es.: lo spazio dei nomi XHTML)
    - È identificato da un URI associato
- Dichiarazione di uno spazio dei nomi:
    - Utilizza il prefisso ben noto `xmlns`, più
    - Un prefisso (alias) associato allo spazio dei nomi nel documento

![[Pasted image 20250512094653.png|300]]

- Il prefisso viene utilizzato per qualificare il nome dell'elemento o dell'attributo come appartenente allo spazio dei nomi associato.
- È possibile specificare anche uno spazio dei nomi predefinito, utilizzando un prefisso nullo (cioè senza prefisso).

![[Pasted image 20250512094815.png|400]]

### Estensibilità vs. validità
- La ben formatura non è sufficiente.
	![[Pasted image 20250512094921.png|500]]
- Entrambi i documenti sono ben formati, ma il secondo non dovrebbe essere "valido"!
- **Sono necessarie le regole grammaticali per caratterizzare i documenti validi.**

### Schema del documento XML
_Se un documento è well formed non è detto che abbia senso rispetto ad un certo caso d'uso ==min6==, ma solo che la macchina può interpretarlo._
_L'esempio $(*)$ è well formed (vedi sopra), se ci fossero due indirizzi sarebbe comunque well formed ma non avrebbe senso._
_Per avere un documento con senso dobbiamo avere un contesto, un caso d'uso, rispetto al quale valutare se ha senso._
_XML lo fa usando XML schema._
Uno schema è una specifica grammaticale per un documento XML.
_XML schema = insieme di meta-informazioni (regole) aggiuntive che possono essere associate a uno (o più) specifico documento XML e verificano che il documento abbia senso. Questo schema è legato ad uno use case (in altri use case potrebbe non avere senso)._
_Nell'esempio $(*)$, lo schema controlla se c'è un indirizzo e se è 1 e non più._

Il **processamento dello schema** viene eseguito da un **processore di schema** su un documento basato su uno schema:
- Verifica la ben formatura _(altrimenti scartato già)_.
- Verifica la validità (conformità allo schema) _(se ha senso, ha regole che verifica le basic information del documento)_.
- Se valido, normalizza il documento (ad esempio, inserendo attributi con valori predefiniti).
  _Le informazioni sono estrapolate e possono essere utilizzate in una struttura dati._

Il processore dello schema è generico!!!
Un **linguaggio di schema** è un linguaggio formale per specificare gli schemi: ==min13DR==
- DTD - Document Type Definition
- XML Schema
- ...

![[Pasted image 20250512095435.png|150]]

### XML Schema
_XML Schema $\to$ specifica come stabilire se documento ha senso. ==min13DR==_
- W3C XML Schema Definition Language (XSD)
    - Prima versione: 2001
    - Versione più recente: 2012
- Principi di progettazione:
    - Più espressivo rispetto a DTD
    - Basato su XML
    - Auto-descrittivo
    - Facile da implementare
- Requisiti tecnici:
    - Supporto per gli spazi dei nomi
    - Supporto per la definizione dei tipi di dato
    - Ereditarietà
    - ...

### Costrutti principali
- Definizioni:
    - **Tipo semplice**: definisce una famiglia di stringhe di testo Unicode.
    - **Tipo complesso**: definisce una raccolta di requisiti per attributi, sotto-elementi e dati testuali negli elementi a cui viene assegnato quel tipo.
- Dichiarazioni:
    - **Elemento**: associa un nome di elemento con un tipo semplice o complesso.
    - **Attributo**: associa un nome di attributo con un tipo semplice.
- Se tutti gli elementi nel documento di istanza sono validi, allora l'intero documento è valido.

### Schema XML - esempio
![[Pasted image 20250512101506.png|250]]
_C'è la definizione di un set di elementi (card, name, title, email, phone, logo), poi c'è la definizione di due complex type. Per ogni elemento puoi avere proprietà aggiuntive (esempio: minOccurs = attributo per riportare il minimo numero di occurrance che devono esserci, in questo caso sarebbe potuto essere omesso visto che è ="0")._

### Schema XML - altro esempio ==min16DR==
![[Pasted image 20250512101645.png|350]]
_Di solito è riportato l'URL dal quale lo schema può essere scaricato (downloaded). Il ricevente del documento scarica lo schema e lo usa._

- Lo schema per un documento è specificato dal valore dell'attributo `schemaLocation`.
  Inserendo questo attributo, l'autore afferma che il documento di istanza è destinato a essere valido rispetto allo schema.
- L'attributo può essere specificato in qualsiasi elemento, oltre all'elemento del documento.
- Possono essere inclusi più coppie `"namespaceURI schemaURI"`.
  In tal caso, gli schemi multipli vengono applicati simultaneamente



slide22-28
in un xml schema troviamo simple types (int,...), complex types, altre ppzioni (non entriamo in dettaglio).
Ogni type può avere vari attribute, importanti minoccurrs e maxoccurrs.

slide29
Bisogna controllare well formed e se ha senso rispetto ad uno schema. Vediamo esempio di un GET, la risposta è un documento XML. L'applicazione controlla la validità del documento e se ha senso rispetto ad un caso d'uso. Questo succede sia quando il messaggio va da applicazione a dispositivo iot ma anche viceversa.
Data encoding language è ridondante, se io sono il solo sviluppatore non ha senso fare così tanti controlli, ma se non sono il solo sviluppatore allora questi controlli aiutano l'interoperabilità.
Anche perché il dispositivo iot potrebbe subire modifiche nel tempo, quindi se fai questi controlli potrebbe essere più facile trovare possibili errori.
Senza controlli l'iot device non può svolgere bene i comandi.

slide32
La complessità di XML e la sua ridondanza hanno portato a JSON. Stiamo ancora parlando di data encoding languages che si sono sviluppati prima dei dispositivi iot.
Idea è trovare data encoding language con minimal syntax e redundancy. Idea è encode the information inside the document come:
- Collection of name value pairs
- Ordered list of values

slide33 ==min26DR==
la basic syntax è super facile: ho due oggetto (...) o array (...)

slide34
value può essere value oppure object oppure array.

slide35
esempi di oggetto (sx) e array (dx).
In caso di oggetto ho id con parentesi quadre.
in caso di array ho lista di key values

slide36
Punto di forza di json è semplicità, niente schema per verificare senso,...
Nell'immagine vediamo esempio equivalente a quello di prima ma con json.
(in realtà su JSON ci sono degli schemi ma sono stati introdotti più tardi, mentre XML li aveva già dall'inizio, non credo li vedremo)
Comparazione XML e JSON (==min31==): se ho grandi progetti (con tanti sviluppatori, interoperabilità) è meglio usare XML, se ho piccolo progetto con pochi sviluppatori è meglio usare JSON.

slide38
JSON ha dei difetti: ==min32DRA== documents encoded in text are complex to compare for tiny iot devices.
Ed è per questo che è stato introdotto un nuovo data encoding language: EXI. Questo usa binary rapresentation invece di text rapresentation.

slide39
Sono stati introdotti due standard EXI e CBOR. Sono standard per encode XML o JSON documents in binario, per essere interpretati in binario (più facile).
Questi due standard dicono al sistema come encode le informazioni in binario. Più efficienti (per LLN) e interpretati in modo migliore in dispositivi iot.

slide41
Questi due encoding languages sono molto usati, soprattutto quando ho iot systems con ... ==min36DR==.

==fino a min37 del 30.04.2025==