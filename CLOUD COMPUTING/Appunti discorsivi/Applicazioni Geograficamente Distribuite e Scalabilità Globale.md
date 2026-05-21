Nello studio dei sistemi distribuiti, spesso si parte da una situazione ideale: tutte le macchine virtuali (VM) si trovano nello stesso datacenter, collegate da una rete locale affidabile e priva di partizioni di rete (_network partition_, ovvero interruzioni nelle comunicazioni tra i nodi).

Quando però un'applicazione diventa su **scala globale** per servire milioni di utenti in tutto il mondo, questa impostazione non regge più. Anche concentrando una potenza di calcolo enorme in un unico punto, il vero collo di bottiglia diventa **Internet** stessa, a causa dei tempi di trasmissione dei dati su lunghe distanze. La soluzione obbligata è una sola: **distribuire i datacenter in diverse regioni del pianeta**.

Per implementare questa architettura globale si adottano tre strategie principali:

- **Utilizzo di più provider Internet:** per garantire ridondanza e non dipendere da un unico operatore.
    
- **Datacenter distribuiti per regione:** posizionando i server fisicamente vicini ai mercati chiave.
    
- **Instradamento intelligente:** le richieste degli utenti vengono inviate al datacenter geograficamente più vicino.
    

Questo approccio offre due enormi vantaggi: una **bassa latenza** (risposte molto più rapide per l'utente finale) e una forte **tolleranza ai guasti** (se un datacenter si isola o si spegne, gli altri continuano a funzionare).

## Il Bilanciamento del Carico (Load Balancing)

L'obiettivo fondamentale del _Load Balancing_ è controllare e decidere esattamente dove inviare il traffico degli utenti. Nei sistemi geografici si utilizza un'architettura strutturata su **due livelli**:

1. **Global Load Balancing (Globale):** si occupa del quadro generale, decidendo a _quale datacenter_ specifico nel mondo destinare la richiesta.
    
2. **Local Load Balancing (Locale):** opera all'interno del singolo datacenter scelto, smistando il traffico tra le varie _macchine virtuali_ disponibili.
    

Le politiche di scheduling (ovvero le regole di smistamento) cambiano radicalmente tra i due livelli. A livello **locale**, l'obiettivo principale è la scalabilità pura, cioè il bilanciamento uniforme del carico per non sovraccaricare i server. A livello **globale**, invece, la politica dipende strettamente dal tipo di applicazione: un motore di ricerca privilegerà la **bassa latenza** per dare risposte immediate, mentre una piattaforma di streaming video o un social network punteranno tutto sulla **larghezza di banda** disponibile.

Dal punto di vista pratico, il load balancing può essere implementato sia tramite **software** (usando strumenti celebri come _HAProxy_) sia attraverso **hardware dedicato**.

### Dal DNS geolocalizzato al Virtual IP (VIP)

Prima che una richiesta parta, il dispositivo dell'utente (client) deve interrogare il **DNS** per tradurre il nome del sito in un indirizzo IP. Per garantire ridondanza, i servizi globali associano al proprio nome più record DNS (sia di tipo A che AAAA).

L'approccio base prevede che il DNS restituisca semplicemente una lista di indirizzi IP e il client ne scelga uno, spesso in modo casuale. Si tratta di un sistema molto semplice, ma che offre **pochissimo controllo**: non c'è alcuna reale informazione sulla distanza geografica e l'aggiornamento dei record DNS è estremamente lento (può richiedere ore).

Un primo passo avanti è il **DNS geolocalizzato**, che restituisce IP diversi in base alla posizione di chi interroga, ma il controllo rimane comunque troppo approssimativo. La vera soluzione avanzata consiste nell'utilizzo dei **Virtual IP (VIP)**.

Un Virtual IP non è legato a una singola scheda di rete fisica, ma è **condiviso tra più dispositivi**. Per l'utente finale si comporta come un IP normalissimo, ma dietro le quinte l'organizzazione è complessa:

- Vengono creati più VIP per un singolo servizio, e ogni VIP viene associato a una specifica **regione**.
    
- All'interno di ogni regione ci sono più datacenter dedicati.
    
- I fornitori di servizi Internet (ISP) si occupano di instradare il traffico dell'utente verso il load balancer più vicino che gestisce quel VIP.
    

L'architettura definitiva vede quindi il DNS regionale che restituisce il Virtual IP corretto, e il _Global Load Balancer_ che riceve il traffico su quell'IP e lo indirizza al datacenter ideale.

### Packet Encapsulation e GRE

Per trasferire i dati in modo efficiente, il load balancer riceve la richiesta del client e adotta la tecnica del **Packet Encapsulation** (incapsulamento dei pacchetti): prende il pacchetto originale e lo inserisce all'interno di un nuovo pacchetto di rete per spedirlo al datacenter di destinazione. Quando il datacenter lo riceve, esegue l'operazione inversa (**decapsulamento**) e processa la richiesta esattamente come se l'avesse ricevuta direttamente dall'utente.

La tecnologia standard per fare questo è il protocollo **GRE (Generic Routing Encapsulation)**, che permette di inserire un pacchetto IP dentro un altro pacchetto IP. In questo schema, il pacchetto esterno (_Outer packet_) contiene l'indirizzo di destinazione del datacenter specifico.

## Modelli di Consistenza: ACID vs. CAP vs. BASE

Lavorare su sistemi geograficamente distribuiti significa scontrarsi con due problemi strutturali pesantissimi: la **banda limitata** (che rende la sincronizzazione tra datacenter molto lenta) e la **bassa affidabilità della rete** (che causa frequenti partizioni). Di conseguenza, i metodi di gestione dei dati tradizionali smettono di funzionare.

### Il modello ACID e il Teorema di CAP

I sistemi tradizionali, come i database relazionali, si fondano sulle proprietà **ACID** (_Atomicity, Consistency, Isolation, Durability_). Questo modello mette la **consistenza** al primo posto: i dati devono essere identici ovunque e in qualsiasi momento. Se per colpa di un guasto di rete non è possibile garantire questa consistenza perfetta, i sistemi ACID scelgono di bloccare le richieste, rendendo il sistema **non disponibile**.

Nelle applicazioni globali, questo approccio è impraticabile a causa del **Teorema di CAP**. Il teorema dimostra che in un sistema distribuito è impossibile garantire contemporaneamente tre proprietà:

- **C**onsistency (Consistenza: tutti i nodi vedono gli stessi dati nello stesso momento).
    
- **A**vailability (Disponibilità: ogni richiesta riceve una risposta non di errore).
    
- **P**artition tolerance (Tolleranza alla partizione: il sistema continua a funzionare anche se la rete si spacca e i nodi non si parlano).
    

Dato che in una rete geografica la tolleranza alle partizioni (**P**) è una realtà fisica inevitabile che dobbiamo accettare, siamo costretti a fare una scelta di trade-off, potendo ottenere al massimo **2 proprietà su 3**. Nella pratica, questo significa dover scegliere tra Consistenza e Disponibilità. È importante sottolineare che il teorema non implica la totale scomparsa della terza proprietà, ma stabilisce che essa non potrà mai essere perfetta durante una partizione.

### L'approccio BASE

Per slegarsi dai vincoli stringenti di ACID, i sistemi globali adottano spesso un modello alternativo chiamato **BASE**, un acronimo che descrive una filosofia radicalmente opposta:

- **B**asically **A**vailable (Sostanzialmente disponibile): il sistema dà sempre una risposta.
    
- **Soft State** (Stato sfocato/variabile): lo stato dei dati può cambiare nel tempo anche senza nuovi input, a causa delle sincronizzazioni in corso.
    
- **E**ventual Consistency (Consistenza finale): i dati non sono subito identici ovunque, ma lo diventeranno se non vengono fatti ulteriori aggiornamenti.
    

L'idea cardine di BASE è privilegiare la disponibilità e la tolleranza alle partizioni (**A + P**), accettando di compromettere temporaneamente la consistenza (**C**).

|Caratteristica|Modello ACID|Modello BASE|
|---|---|---|
|**Aggiornamenti**|Sincroni (bloccanti, tutti i nodi devono allinearsi subito)|Asincroni (in background tramite _anti-entropy protocol_)|
|**Disponibilità**|Rifiuta le query se c'è il rischio di dati inconsistenti|Sempre disponibile, risponde sempre in base allo _stato locale_ del nodo|
|**Effetti collaterali**|Forte latenza su reti geografiche, rischio di blocco totale|Inconsistenza temporanea e rischio di **conflitti** tra modifiche concorrenti|

Per risolvere i conflitti che inevitabilmente si creano nel modello BASE (ad esempio, se due datacenter diversi modificano lo stesso dato nello stesso momento), si usano politiche automatiche come la regola _"l'ultimo timestamp vince"_ (_Last Write Wins_).

## Il Caso di Studio: Bayou

**Bayou** è una celebre architettura di sistema progettata specificamente per essere _eventually consistent_. Il suo scopo fondamentale è garantire la massima disponibilità possibile accettando una consistenza debole (nello specifico, una _consistenza sequenziale_).

Nel mondo di Bayou, i vari nodi che gestiscono i dati (chiamati _replica manager_) si scambiano continuamente gli aggiornamenti in background sfruttando i protocolli di **anti-entropy**, e integrano nativamente sofisticati meccanismi di rilevamento e risoluzione dei conflitti.

### Gestione delle operazioni: Tentative vs. Committed

In Bayou, le operazioni di modifica dei dati (_Update_) attraversano due stati ben distinti:

1. **Tentative (Tentativo):** Quando un utente esegue una modifica, questa viene applicata immediatamente sul nodo locale per non farlo aspettare. L'operazione viene però contrassegnata come _tentative_. L'ordine di queste operazioni a livello locale è stabilito dal timestamp del nodo.
    
2. **Committed (Definitivo):** Quando l'operazione viene validata ufficialmente, diventa _committed_. Da questo momento in poi è definitiva, immutabile e segue un ordine globale univoco e condiviso da tutte le repliche.
    

### Il protocollo Primary Commit Scheme

Per decidere quando e come una modifica "tentativa" può diventare "definitiva", Bayou utilizza un sistema chiamato **Primary Commit Scheme**. In questa architettura viene designato un nodo specifico che assume il ruolo di **Primary**.

- Il nodo _Primary_ è l'unico che ha l'autorità di decidere quando trasformare un aggiornamento da tentativo a definitivo (_commit_).
    
- Se il nodo _Primary_ va offline (**down**), il meccanismo di commit si blocca momentaneamente: non si possono confermare nuove operazioni in modo definitivo.
    
- Tuttavia — ed è qui che si vede il vantaggio di BASE — il sistema **continua a funzionare regolarmente**: gli utenti possono ancora connettersi agli altri nodi e inviare aggiornamenti, che rimarranno semplicemente nello stato di _tentative_.
    
- Non appena il nodo _Primary_ torna online, riceve le modifiche accumulate, risolve eventuali problemi e converte gli update tentativi in _committed_.
    

### Rilevamento e Risoluzione dei Conflitti

Quando le modifiche viaggiano tra i nodi, Bayou effettua due passaggi chiave per gestire i pasticci dovuti alla scrittura simultanea:

- **Dependency Check:** È una vera e propria query di controllo che verifica se le condizioni di partenza della modifica sono ancora valide. Se le condizioni non corrispondono più allo stato attuale del dato, significa che c'è stato un conflitto.
    
- **Merge Procedure:** È la procedura software che si attiva per risolvere il conflitto rilevato.
    

Il requisito matematico e ingegneristico più importante per queste procedure di fusione dei dati è che **devono essere deterministiche**. Significa che, a parità di dati di partenza, l'algoritmo deve produrre lo stesso identico risultato su qualsiasi computer venga eseguito. Solo grazie al determinismo tutte le repliche sparse per il mondo, elaborando gli stessi aggiornamenti, riusciranno a convergere verso lo stesso identico stato finale.

### Il Trade-off delle Performance

Le prestazioni complessive di un sistema come Bayou sono legate a un bilanciamento strategico basato sulla frequenza con cui i nodi eseguono l'algoritmo di sincronizzazione (_anti-entropy_):

Frequenza Anti-Entropy Alta⟶Meno Inconsistenza+Piuˋ Overhead di Rete

Frequenza Anti-Entropy Bassa⟶Piuˋ Inconsistenza+Meno Overhead di Rete

Trovare il giusto equilibrio tra la freschezza dei dati e il consumo di risorse di rete rappresenta il compromesso fondamentale nella progettazione di qualunque applicazione su scala globale.