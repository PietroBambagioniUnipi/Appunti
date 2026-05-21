
In questo capitolo esploriamo il concetto di **Full Virtualization** (virtualizzazione completa) implementata in assenza di un supporto hardware dedicato. In questo scenario, l'obiettivo è far girare un intero sistema operativo (Guest OS) come se si trovasse su una macchina fisica dedicata, pur condividendo le risorse con altri sistemi.

## Il Multiprogramming e le Virtual CPU (VCPU)

La virtualizzazione prende in prestito molti concetti dal **multiprogramming**, un approccio implementato nei moderni sistemi operativi per emulare la presenza di più processori su una singola CPU fisica.

L'<font color="#c0504d">idea di base è simulare più processori </font>introducendo il concetto di **VCPU (Virtual CPU)**. <font color="#4bacc6">Ogni processo</font> (o, nel caso della virtualizzazione, ogni VM)<font color="#4bacc6"> possiede una propria CPU virtuale</font>. A livello pratico, <font color="#c0504d">la VCPU è una struttura dati che memorizza lo stato dei registri del processore</font>. **L'esecuzione avviene a turni**: <font color="#9bbb59">il sistema carica lo stato di una VCPU nell'hardware reale, fa avanzare il processo, poi salva lo stato attuale per fare spazio a un'altra VCPU</font>. Questo rapido scambio, noto come **Context Switch**, <font color="#c0504d">dà a ogni processo l'illusione di avere l'intera CPU a propria disposizione</font>. I context switch sono generalmente innescati da timer o interrupt hardware.

### Supporto e Protezione nel Multiprogramming

Per far funzionare questo meccanismo, <font color="#f79646">l'hardware deve supportare i timer per interrompere i processi e offrire meccanismi di protezione</font> (come il controllo degli accessi alla memoria). La protezione si basa sui livelli di privilegio:

- **Kernel Mode (Ring 0):** <font color="#c0504d">Permette l'accesso completo a tutte le istruzioni della CPU</font>.
    
- **User Mode (Ring 3):** <font color="#c0504d">Permette un accesso limitato</font>. <font color="#9bbb59">Se un programma tenta di eseguire un'istruzione privilegiata in User Mode, il sistema attiva un meccanismo di protezione</font>.
 
![[Pasted image 20260311141613.png|300]]
    

Questa separazione è gestita tramite registri specifici:

- **sys register (mode flag):** <font color="#c0504d">Segnala se la CPU si trova in User o Kernel mode</font>.
    
- **sys-mem register:** <font color="#c0504d">Custodisce l'indirizzo iniziale della memoria privilegiata</font>, mettendo al sicuro strutture critiche come i dati del kernel o le VCPU.
    
- **ret register:** <font color="#c0504d">Salva l'indirizzo a cui il programma deve ritornare una volta conclusa un'operazione in Kernel mode</font>.
    

Durante un context switch, il sistema operativo salva lo stato attuale nella VCPU, seleziona la VCPU successiva, carica i suoi dati nei registri reali e infine esegue un'istruzione speciale per tornare in User mode (saltando all'indirizzo salvato nel _ret register_).

## Gestione della Memoria e degli Eventi

Oltre alla CPU, <font color="#4bacc6">ogni processo è convinto di possedere un'intera</font> **Memoria Virtuale** <font color="#4bacc6">continua</font>, <font color="#4bacc6">isolata e che parte dall'indirizzo zero</font>.<font color="#c0504d"> La traduzione dagli indirizzi virtuali</font> (che vede il processo) agli indirizzi fisici (la RAM reale) <font color="#c0504d">è gestita a livello hardware dalla </font>**Memory Management Unit (MMU)**, supervisionata dal sistema operativo host.

La [[Cloud Computing ITA#Memory Management Unit (MMU)|MMU]] utilizza una **Page Table** (Tabella delle Pagine), <font color="#c0504d">una struttura dati multilivello salvata in RAM</font>. La CPU sa dove trovarla grazie al registro _PTBR (Page Table Base Register)_. Se la memoria RAM si esaurisce, si sfrutta la memoria secondaria (il disco) tramite tecniche di Paging o Segmentation. Se un processo richiede una pagina non presente in RAM, si verifica un **Page Fault**, e la pagina viene recuperata dal disco.

### Interrupt ed Eccezioni

Il <font color="#c0504d">sistema deve anche saper reagire a eventi urgenti</font>:

- **Exception (Trap):** Sono eventi <font color="#c0504d">interni</font> e _sincroni_, causati generalmente da un errore o da una specifica richiesta del programma.
    
- **Interrupt:** Sono eventi <font color="#c0504d">esterni</font> e _asincroni_, generati dall'hardware (es. pressione di un tasto o un segnale di rete).
    

Entrambi causano un passaggio forzato dalla User Mode alla Kernel Mode. La CPU capisce come reagire consultando la **Interrupt Descriptor Table (IDT)**, una tabella che associa ogni evento al suo specifico _handler_ (la funzione del kernel deputata a gestirlo).

## Full Virtualization:  Modello "Trap and Emulate"

Nella virtualizzazione completa, l'[[hypervisor]] agisce in modo molto simile al kernel di una macchina fisica, mentre la VM si comporta come un processo estremamente avanzato che fa girare un proprio sistema operativo completo di kernel, applicazioni e multiprogrammazione interna.

Per massimizzare l'efficienza, l'hypervisor cerca di far eseguire le istruzioni del Guest OS direttamente sulla CPU fisica. Tuttavia, poiché il Guest OS viene eseguito in un ambiente non privilegiato (es. Ring 1-3), non può lanciare istruzioni privilegiate, che sono invece riservate all'hypervisor (Ring 0).

Qui entra in gioco il **Trap and Emulate Model**. Quando il Guest OS tenta di eseguire un'istruzione privilegiata:

1. L'istruzione fallisce e genera un **Trap**.
    
2. Il controllo passa all'hypervisor.
    
3. L'hypervisor **emula** il comportamento di quell'istruzione per conto della VM.
    
4. L'hypervisor restituisce il controllo alla VM.
    

### Il problema dell'Overhead (Il caso delle System Call)

Questo modello presenta un limite enorme in termini di prestazioni, in particolare con istruzioni complesse come l'istruzione `INT` usata per le system call. Se un'app nel Guest OS fa una system call, genera un `INT`. Essendo privilegiata, causa un trap e passa all'hypervisor. Tuttavia, l'hypervisor non deve eseguire il proprio handler, ma deve recuperare e avviare l'handler del Guest OS. A sua volta, il codice dell'handler del Guest OS è pieno di istruzioni privilegiate. Questo innesca un grave **effetto a catena**: ogni singola istruzione privilegiata nell'handler genera un nuovo trap, un context switch, un'emulazione e un ritorno. Questo circolo vizioso genera un **overhead elevatissimo**, rappresentando il principale collo di bottiglia della virtualizzazione senza supporto hardware.

## Virtualizzazione della Memoria (Virtual MMU)

Il Guest OS pensa di avere a disposizione una memoria fisica che parte dall'indirizzo 0, ma in realtà quella è solo la memoria fisica _virtuale_. Serve quindi una doppia traduzione:

1. **Funzione G:** Da _Guest Virtual_ a _Guest Physical_ (gestita dal Guest OS).
    
2. **Funzione H:** Da _Guest Physical_ a _Host Physical_ (gestita dal VMM).
    

La traduzione finale che la CPU deve eseguire è la composizione di queste due (G ∘ H). Poiché l'hardware standard non supporta questa doppia traduzione, l'hypervisor utilizza il **Brute Force Method** tramite le **Shadow Page Tables**. Queste tabelle ombra uniscono direttamente le traduzioni, bypassando il passaggio intermedio. Sono tabelle _write-protected_: ogni volta che il Guest OS tenta di aggiornare la sua page table, si genera un trap. L'hypervisor intercetta l'eccezione, aggiorna la vera page table in memoria (la shadow table) e il registro PTBR, garantendo isolamento ma aggiungendo ulteriore overhead.

## Virtualizzazione dell'I/O e degli Interrupt

I dispositivi di Input/Output richiedono istruzioni privilegiate, dunque il loro accesso deve essere interamente emulato. Il [[Virtualizzazione#Architettura Server e Ruolo dell'Hypervisor|VMM]] crea delle periferiche virtuali tramite strutture dati in memoria. Quando il Guest OS crede di scrivere su un disco reale usando chiamate di sistema, in realtà sta interfacciandosi con questo hardware virtuale. Il [[Virtualizzazione#Architettura Server e Ruolo dell'Hypervisor|VMM]], in background, traduce queste operazioni in comandi per le periferiche fisiche.

Di conseguenza, **tutti gli interrupt hardware reali arrivano prima all'hypervisor**, che è l'unico proprietario della vera IDT dell'host. Per dare alla VM l'illusione del controllo (ed evitare fenomeni di _busy waiting_), il VMM mantiene una **IDT virtuale** ("floating", ovvero scollegata dall'hardware reale) per ogni Guest. Quando una periferica fisica invia un interrupt destinato a una VM, l'hypervisor lo cattura, consulta la IDT del Guest OS, prepara i registri e l'Instruction Pointer, e innesca un interrupt virtuale. In questo modo, la VM esegue il suo handler come se l'interrupt provenisse direttamente dall'hardware.

## QEMU: Un esempio pratico

Un eccellente esempio di queste tecnologie è **QEMU**, un emulatore open-source capace di fungere anche da virtualizzatore. QEMU emula l'intero hardware e offre due modalità principali:

- Se l'architettura Guest è diversa dall'Host (es. ARM su x86), usa la **binary translation** (emulazione completa, molto lenta ma estremamente flessibile).
    
- Se le architetture coincidono, permette l'**esecuzione parziale diretta** delle istruzioni sulla CPU, riducendo l'overhead e migliorando notevolmente le performance.