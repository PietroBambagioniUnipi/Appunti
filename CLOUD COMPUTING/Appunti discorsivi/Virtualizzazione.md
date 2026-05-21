### Fondamenti della Virtualizzazione

<font color="#c0504d">La virtualizzazione consiste nella rappresentazione logica di risorse computazionali fisiche attraverso un livello di astrazione software</font>, definito _virtualization layer_. Il meccanismo fondamentale prevede la sovrapposizione di questo strato alla macchina fisica, con il compito esclusivo di generare e amministrare le risorse virtuali. <font color="#4bacc6">L'effetto architetturale primario è il disaccoppiamento totale</font> (decoupling) <font color="#4bacc6">tra l'hardware fisico e l'utente finale</font>. Nel contesto cloud, l'infrastruttura virtuale viene fruita come se fosse fisica, precludendo all'utente qualsiasi accesso diretto all'hardware sottostante.

<font color="#9bbb59">Le risorse sottoposte a questo processo si dividono in due categorie</font>. <font color="#c0504d">Le risorse di calcolo base</font> (CPU, RAM, storage) <font color="#c0504d">sono imprescindibili e necessitano sempre di una controparte hardware fisica da cui attingere</font>. <font color="#9bbb59">Le risorse opzionali</font> (interfacce di rete, periferiche di input/output) <font color="#9bbb59">possono invece interfacciarsi con hardware reale oppure essere simulate integralmente via software</font>. È essenziale notare che la risorsa virtuale non è vincolata a replicare le esatte specifiche di quella fisica: è possibile, ad esempio, instradare processi a 32-bit su CPU a 64-bit o frazionare un singolo processore fisico in molteplici vCPU.

### Architettura Server e Ruolo dell'Hypervisor

La [[Cloud Computing ITA#Machine / Server Virtualization|virtualizzazione in ambito server]] si traduce nella <font color="#c0504d">creazione di Macchine Virtuali</font> (VM) <font color="#c0504d">al di sopra di un sistema host</font>. L'infrastruttura fisica assume il ruolo di _Host system_, mentre le singole VM costituiscono i _Guest system_. Questa architettura consente l'esecuzione simultanea di molteplici VM sul medesimo host, imponendo un isolamento rigoroso: <font color="#c0504d">ogni VM opera con un proprio sistema operativo indipendente</font> (Guest OS) <font color="#c0504d">e non possiede alcuna visibilità o diritto di accesso agli spazi di memoria e storage assegnati alle altre istanze</font>. Il monitoraggio centralizzato rimane prerogativa esclusiva dell'host.

Il componente software che orchestra questo ecosistema è l'[[Cloud Computing ITA#Hypervisor|Hypervisor]], o Virtual Machine Monitor (VMM). Le sue funzioni critiche includono la creazione delle VM, l'allocazione tassativa delle risorse e il controllo dell'esecuzione dei processi.

L'implementazione dell'Hypervisor segue [[Cloud Computing ITA#Hypervisor types|due approcci distinti]]:

- **Type 1 (Bare Metal):** L'<font color="#c0504d">hypervisor è installato direttamente sull'hardware fisico</font>. L'assenza di un sistema operativo intermedio minimizza l'[[Overhead|overhead]] e massimizza l'efficienza computazionale. Data la sua superiorità prestazionale, costituisce lo standard de facto adottato dai cloud provider, nonostante <font color="#c0504d">richieda una gestione complessa e presenti limiti di compatibilità hardware.</font>
    
- Type 2 **(Hosted):** L'<font color="#c0504d">hypervisor opera come applicazione al di sopra di un sistema operativo host preesistente</font> (es. VirtualBox). <font color="#9bbb59">Sfrutta i driver dell'OS sottostante</font>, <font color="#9bbb59">garantendo un'installazione semplificata e un'elevata compatibilità</font>. Tuttavia, <font color="#f79646">impone un overhead significativo</font>, poiché una frazione delle risorse viene consumata dall'OS host, riducendo l'efficienza complessiva.
    

### Paradigmi di Virtualizzazione

Le interazioni tra Guest OS e hardware definiscono specifici paradigmi:

- [[Cloud Computing ITA#Full Virtualization|Full Virtualization]]:<font color="#c0504d"> L'hypervisor simula l'hardware in modo totale</font>. Il Guest OS opera in completa inconsapevolezza del livello di astrazione e non richiede modifiche.<font color="#9bbb59"> Garantisce isolamento e compatibilità assoluti</font>, a fronte di un <font color="#f79646">overhead computazionale critico dovuto all'emulazione di ogni singola chiamata hardware</font>. (In dettaglio [[Tecnologie di Virtualizzazione (Senza Supporto Hardware)|qui]])
    
- [[Cloud Computing ITA#Para Virtualization|Paravirtualization]]: Architettura progettata per abbattere l'overhead. <font color="#c0504d">Richiede la modifica del Guest OS</font> (porting) <font color="#c0504d">affinché riconosca l'ambiente virtuale e collabori attivamente con l'hypervisor</font>. <font color="#9bbb59">L'efficienza aumenta a scapito dell'isolamento</font>,<font color="#9bbb59"> della sicurezza e della flessibilità di deploymen</font>t, vincolando l'utente a sistemi operativi specificamente modificati. (In dettaglio [[Tecnologie di Virtualizzazione Paravirtualizzazione e Container#1. Paravirtualizzazione (Paravirtualization)|qui]])
    
- [[Cloud Computing ITA#Hardware Assisted Virtualization|Hardware-Assisted Virtualization]]:<font color="#c0504d"> Costituisce un'evoluzione del modello Full Virtualization</font>. <font color="#9bbb59">Demanda le operazioni critiche direttamente a estensioni hardware specifiche integrate nella CPU</font>. Elimina i colli di bottiglia software accelerando l'esecuzione, a patto di disporre di processori fisici compatibili. (In dettaglio [[Tecnologie di Virtualizzazione (Hardware Assisted Virtualization)|qui]])
    
- [[Cloud Computing ITA#Operating System Level Virtualization|Operating System Level Virtualization]]: Modello che <font color="#c0504d">prescinde dall'hypervisor</font>. È il <font color="#c0504d">kernel del sistema operativo host a isolare gli ambienti</font>,<font color="#c0504d"> generando container</font> (es. [[Docker]]) <font color="#c0504d">anziché VM</font>. Condividendo il medesimo OS, <font color="#9bbb59">l'overhead è prossimo allo zero e i container risultano estremamente leggeri</font>. Il compromesso architetturale è un isolamento inferiore: le vulnerabilità a livello di kernel host compromettono l'intera struttura. (In dettaglio [[Tecnologie di Virtualizzazione Paravirtualizzazione e Container#Operating System Virtualization (Container)|qui]])
    

Esistono inoltre applicazioni di questo principio a domini operativi specifici, quali la **Network Virtualization** (astrazione logica delle reti fisiche) e la **Storage Virtualization** (aggregazione di molteplici supporti fisici in pool virtuali centralizzati).

### Demarcazione tra Virtualizzazione ed Emulazione

Nella **Virtualizzazione**, l'<font color="#c0504d">architettura e l'instruction set della macchina fisica corrispondono rigorosamente a quelli virtuali</font>. Le istruzioni del Guest vengono eseguite quasi interamente in via diretta sulla CPU host. Questa <font color="#9bbb59">assenza di traduzione garantisce performance di altissimo livello</font>. Il sistema virtuale è una replica logica, non una simulazione. Nell'**Emulazione**, si ha a che fare con <font color="#c0504d">architetture e set di istruzioni divergenti e incompatibili tra loro</font>. Ogni istruzione binaria deve essere <font color="#c0504d">tradotta</font> (Binary Translation) o <font color="#c0504d">interpretata</font> a runtime prima dell'esecuzione. Questo processo comporta la simulazione totale del comportamento hardware alieno, risultando computazionalmente oneroso e drasticamente più lento.

### Analisi Costi-Benefici

Il consolidamento dei server (Server Consolidation) è il principale vettore di ritorno sull'investimento: concentrare molteplici VM su un singolo nodo fisico massimizza l'impiego delle risorse e abbatte i costi infrastrutturali. A livello operativo, la gestione risulta semplificata dalla netta separazione tra ambiente logico e fisico, consentendo deployment immediati tramite la clonazione di istanze preconfigurate. L'architettura garantisce Fault Tolerance, permettendo la migrazione di VM tra server, e confini di sicurezza rigidi grazie al confinamento logico.

I deficit infrastrutturali richiedono un'attenta pianificazione. L'host fisico costituisce un _Single Point of Failure_: il collasso del nodo implica l'interruzione simultanea di tutti i Guest residenti. Infine, l'elaborazione mediata dallo stack di astrazione genera un ineliminabile overhead fisiologico, attestando le performance reali attorno all'85-90% della capacità bare metal nativa. L'analisi fredda e calcolata di queste metriche è un imperativo categorico per il corretto dimensionamento di qualsiasi infrastruttura IT moderna.

## I Requisiti Fondamentali della Virtualizzazione

Perché un sistema di virtualizzazione possa considerarsi valido, deve rispettare tre [[Cloud Computing ITA#Virtualization Requirements|requisiti]] cardine:

- **Equivalence (Equivalenza):** <font color="#c0504d">Una Macchina Virtuale (VM) deve comportarsi esattamente come la sua controparte fisica</font>. Il software che vi viene eseguito non deve accorgersi di essere in un ambiente virtualizzato.
    
- **Resource Control (Controllo delle Risorse):** <font color="#c0504d">L'hypervisor</font> (o Virtual Machine Monitor, VMM) <font color="#c0504d">deve avere il controllo esclusivo e assoluto sulle risorse fisiche sottostanti</font>. Il Guest OS, al contrario, gestisce esclusivamente le risorse virtuali che gli vengono assegnate.
    
- **Efficiency (Efficienza):** <font color="#c0504d">Per garantire prestazioni accettabili, la stragrande maggioranza delle istruzioni deve essere eseguita direttamente dalla CPU fisica</font>, riducendo al minimo l'intervento del VMM.
    