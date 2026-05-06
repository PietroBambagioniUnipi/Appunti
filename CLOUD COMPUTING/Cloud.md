# 01 Storia del Cloud Computing

#### Cloud computing Definition

Il **Cloud Computing** <font color="#ff0000">è un modello che consente un accesso di rete sempre presente, conveniente e su richiesta a un pool condiviso di risorse informatiche configurabili, che possono essere fornite e rilasciate rapidamente con un impegno gestionale o interazioni con il fornitore di servizi minimi</font>.

Il Cloud computing non è un'innovazione improvvisa, ma è il risultato di una serie di sviluppi avvenuti negli ultimi decenni.

Il primo concetto di cloud computing risale al 1960, quando fu coniato da McCarthy ("l'elaborazione potrebbe un giorno essere organizzata come un servizio di pubblica utilità"). Tuttavia, ci sono voluti più di 40 anni affinché l'idea si sviluppasse e maturasse attraverso l'unione di una serie di tecnologie chiave.

Il cloud computing è quindi la composizione di diverse tecnologie chiave, ognuna delle quali rappresenta un pilastro essenziale.

#### **L'origine - Mainframe**

L'uso commerciale dell'informatica inizia nel 1970 con i mainframe, supercomputer grandi e costosi che occupavano un'intera stanza ed erano utilizzati simultaneamente da diversi utenti (solitamente con un utilizzo in time-sharing) da terminali multipli.

I terminali erano passivi (dumb), in grado solo di trasferire dati di input/output da/verso il mainframe; c'era un collo di bottiglia e gli utenti dovevano aspettare in coda.

Alla fine degli anni '70 hanno iniziato a diffondersi i personal computer, che hanno permesso di ridurre i costi consentendo a più persone di eseguire i propri calcoli e le proprie applicazioni, sebbene avessero capacità limitate.

Nello stesso periodo è nato il networking, connettendo i computer tra loro per scambiare dati e coordinarsi per eseguire compiti complessi; in questo periodo sono state introdotte per la prima volta le reti LAN e WAN.

#### **Applicazioni Distribuite**

Esistono due paradigmi diversi:

- Client/Server computing: il server offre servizi o informazioni a determinati client.
    
- Peer-to-peer computing: ogni computer può offrire o richiedere informazioni.
    

![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260304093847.png]]

Negli anni '80 c'è stata una svolta nella potenza di calcolo, ma a un certo punto ci si è scontrati con un limite fisico su quanta potenza potesse avere una singola macchina; questo ha portato al paradigma dell'elaborazione parallela, con più processori che lavorano insieme per risolvere un singolo compito.

I compiti paralleli si sono evoluti in sistemi di calcolo distribuito grazie ai progressi nelle velocità di trasferimento dei dati; ora si hanno macchine diverse che comunicano tra loro per completare compiti complessi e scambiare dati.

![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260304094120.png]]


#### **Cluster computing**

All'inizio, le macchine nei sistemi di calcolo distribuito erano organizzate in cluster, ovvero gruppi di nodi multipli connessi alla stessa LAN per eseguire compiti simili.

Il cluster è stato una rivoluzione perché permetteva di eseguire compiti complessi, ma ogni cluster rappresentava un singolo punto di guasto (single point of failure); ogni cluster ha un nodo principale (cluster head) responsabile della ricezione e dell'assegnazione dei compiti all'interno del cluster stesso, e se il nodo principale fallisce il cluster non può ricevere alcun compito.

Ci sono compiti che possono essere suddivisi in più sotto-compiti, ognuno dei quali può essere classificato in diverse categorie.

Ogni cluster può eseguire un sotto-compito, e ogni computer del cluster potrebbe eseguire un sotto-sotto-compito (è in questo modo che all'inizio erano organizzati i sistemi distribuiti).

![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260304094434.png]]

#### **Grid Computing**

Per risolvere il problema del singolo punto di guasto è stato introdotto il **grid computing**, dove i compiti venivano assegnati in modo distribuito senza un cluster head.

Ogni computer all'interno del cluster è coordinato con gli altri computer del cluster stesso per selezionare un altro computer per l'esecuzione del compito ricevuto dal cluster.

![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260304094559.png]]

Nei cluster era difficile eleggere un altro nodo principale perché solitamente quest'ultimo possiede un hardware specializzato, quindi non è possibile eleggerne uno nuovo facilmente.

Nel grid, al contrario di quanto avveniva in un cluster, l'hardware dei computer non era specializzato.

**Svantaggi del Grid computing:**

- È <font color="#ff0000">impossibile</font> avere una scalabilità in tempo reale perché è necessario reinstallare tutto il software.
- L'espansione poteva richiedere <font color="#ff0000">giorni o settimane</font>.
- Il sistema non era <font color="#ff0000">fault tolerant </font>(tollerante ai guasti); il guasto di un nodo comportava il fallimento di un compito.
- C'era un hardware eterogeneo e questo richiedeva un adattamento del codice.


#### **Virtualizzazione Hardware**
La natura eterogenea dei sistemi informatici rappresentava una sfida per la portabilità del codice (poiché era necessario adattare il codice ai diversi hardware). ==La virtualizzazione hardware è una tecnologia in grado di creare un ambiente in cui il software può essere eseguito su hardware differenti senza subire modifiche==. È un livello progettato per nascondere le specifiche hardware al software. È uno dei pilastri del cloud computing.

#### **Tecnologie Web-Based** 
La tecnologia web-based ha fornito un meccanismo semplice per consentire agli utenti l'accesso alle applicazioni o alle infrastrutture di cloud computing.

#### **Service Oriented Architecture** 
La Service Oriented Architecture è un metodo di sviluppo che crea applicazioni suddivise in componenti software che interagiscono tra loro; ogni componente è indipendente e comunica con gli altri tramite messaggi. Un'idea chiave è scomporre la logica complessa in moduli più piccoli e semplici.

#### **Modello Utility Computing**
Modello Utility Computing: fornitura di risorse informatiche come servizio di pubblica utilità, seguendo un modello pay-per-use (pagamento a consumo) e on-demand (su richiesta).

**Cronologia**
Il Cloud Computing è l'evoluzione di un insieme di tecnologie sviluppatesi in un lungo arco di tempo dagli anni '70 alla fine degli anni '90. Negli anni '90 abbiamo avuto il primo servizio di cloud computing, commercializzato da Amazon, chiamato EC2. Il cloud computing oggi è un mercato valutato circa 210 miliardi; l'80% delle aziende riscontra un impatto positivo dalla sua adozione.

![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260304095654.png]]

# **02 Introduzione e Concetti Fondamentali** 
Cloud Computing è un termine in voga che si riferisce sia alle applicazioni fornite come servizi tramite Internet, sia alle infrastrutture hardware e software nel datacenter che forniscono tali servizi. Cloud Computing: è un ambiente IT distinto, progettato allo scopo di fornire da remoto risorse IT scalabili e misurabili, accessibili tramite Internet. Un esempio di ambiente IT distinto è il Datacenter; alcuni esempi di risorse IT sono la memoria e la potenza di calcolo (RAM + CPU). Se le risorse non sono scalabili e misurabili, si ha semplicemente un server remoto che ospita una risorsa, e non si tratta di cloud computing.

![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260304100320.png]]

**Servizi Cloud** Infrastruttura Cloud: è l'ambiente IT remoto distinto che fornisce le risorse (ad esempio, il datacenter che ospita le risorse). Fornisce le risorse per implementare il servizio cloud. Servizio Cloud: è un'applicazione o un servizio fornito dall'infrastruttura. Nel primo caso, di solito fornisce un'interfaccia a cui gli utenti accedono direttamente tramite pagine web; nel secondo caso, espone un set di API e non un'interfaccia: in questo caso è solitamente accessibile da altre applicazioni e non direttamente dagli utenti.

**Everything as a Service - XaaS** Everything as a Service (XaaS) è la tendenza a far evolvere ogni cosa in servizi eseguiti da remoto sul cloud sotto forma di servizio cloud.

![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260304100335.png]]

Esempi di servizi cloud: servizio di cloud file storage: i file vengono caricati sul cloud, da dove è possibile scaricarli, condividerli e accedervi. servizio cloud ERP: l'ERP (software utilizzato dalle aziende per gestire i processi interni) è distribuito nel cloud (solitamente su un server all'interno della rete aziendale) e i dipendenti possono accedervi tramite un'interfaccia web o un client dedicato.

![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260304100507.png]]

**Ruoli** Ci sono sette ruoli principali in un'infrastruttura cloud.

![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260304101242.png]]

Il Cloud Provider è un'organizzazione che fornisce risorse IT basate sul cloud; solitamente progetta e gestisce una piattaforma cloud di proprietà (es. AWS). Il Cloud Consumer è un'organizzazione (o un individuo) che ha un contratto o un accordo formale con il Cloud Provider per l'utilizzo delle risorse IT. Può possedere un servizio cloud, tuttavia non deve necessariamente esserne l'utente (può venderlo ad altri clienti). Il Cloud Service Owner è la persona o l'organizzazione che crea un servizio cloud in esecuzione sulle risorse fornite dall'infrastruttura cloud. Crea il servizio cloud a scopo di lucro, quindi solitamente viene venduto come prodotto agli utenti del servizio cloud, i quali in genere pagano una tariffa mensile per accedervi. Il Cloud Resource Administrator è la persona o l'organizzazione responsabile dell'amministrazione delle risorse IT basate sul cloud. L'amministratore appartiene solitamente al cloud provider, ma può appartenere anche al cloud consumer. Il Cloud Carrier è la parte responsabile di fornire la connettività tra gli utenti e il cloud provider, ad esempio un Internet Service Provider (es. ILIAD). Il Cloud Auditor è un ruolo di terze parti che conduce valutazioni indipendenti dell'ambiente cloud. Il suo ruolo include tipicamente la valutazione della sicurezza e delle prestazioni. Il Cloud Service User è l'utente finale di un servizio cloud. Il service owner e il provider sono solitamente entità diverse, ma possono coincidere, ad es. i servizi Google girano sull'infrastruttura Google.

**Modello Cloud** Il modello cloud per la fornitura di risorse IT è scalabile e misurato, questo significa che: scalabile: le risorse possono essere fornite (assegnate) dinamicamente su richiesta; le risorse devono essere allocate o istanziate in un breve lasso di tempo, con il minimo sforzo e la minima necessità di intervento umano. Le risorse possono essere fornite non solo su richiesta di un essere umano, ma anche sotto l'orchestrazione di un software. misurato: il cloud provider adotta un modello basato sull'utility (servizio), quindi si paga per ciò che si consuma; l'utilizzo della risorsa viene misurato e, alla fine del mese, l'utente viene fatturato in proporzione a ciò che ha consumato (ad esempio in termini di memoria, larghezza di banda, potenza di calcolo).

**Modello di Business** Nel modello di business del cloud computing, i provider di cloud computing vendono risorse IT, e altre aziende acquistano tali risorse per creare servizi e applicazioni da utilizzare internamente o vendere ai propri clienti.

**Infrastruttura di Cloud Computing** L'infrastruttura di Cloud Computing è l'infrastruttura progettata per ospitare risorse; è implementata nei datacenter (uno spazio dedicato per alloggiare server e apparecchiature di rete). Tale hardware fornisce risorse IT come calcolo, archiviazione e rete, e queste risorse possono essere accessibili da più cloud consumer contemporaneamente tramite connessione Internet.

**Multi-tenancy** Nell'approccio tradizionale si ospita una risorsa in un datacenter ed è necessario configurare il datacenter, configurare la risorsa e connettere il datacenter per accedere alla risorsa; tuttavia, il cliente (service owner) è limitato ad accedere solo alle risorse offerte dall'amministratore del cloud e non può personalizzare affatto l'ambiente, essendo consapevole di distribuire la risorsa su un dispositivo condiviso senza possibilità di un'ampia personalizzazione. In un ambiente multi-tenant si può avere una personalizzazione molto più elevata (es. fare il check-in in un hotel rispetto ad affittare un appartamento: nel primo caso si è limitati in ciò che si può fare, nel secondo si possono fare più cose e personalizzare maggiormente, come dipingere i muri, comprare un nuovo materasso, ecc.). La Multi-Tenancy è la proprietà di un sistema fornito dal proprietario in cui l'utente ha l'impressione di essere l'unico utilizzatore nell'ambiente e può fare ciò che vuole. Ovviamente è solo un'impressione, perché in realtà il provider vende lo stesso server più volte, al maggior numero di proprietari possibile.

**Virtualizzazione** Per ottenere l'impressione di essere l'unico utente nell'ambiente sfruttiamo la virtualizzazione; la virtualizzazione permette di creare una rappresentazione virtuale di qualcosa (in questo caso stiamo virtualizzando le risorse o un intero server). 300 La tecnica di virtualizzazione più importante è la virtualizzazione hw, che permette di creare una rappresentazione virtuale completa di un server con tutti i suoi componenti. Assomiglia così tanto a un ambiente reale da poter eseguire un sistema operativo senza alcuna modifica. La virtualizzazione hardware permette a più sistemi operativi di essere eseguiti sullo stesso hw; essi accedono alla versione virtualizzata di una risorsa.

**Hypervisor** L'hardware virtuale è gestito e controllato dal livello di virtualizzazione (Virtualization layer). Un elemento centrale di tale livello è l'Hypervisor, chiamato anche VM manager, un sw che ricrea l'ambiente hw virtualizzato in cui viene eseguito il sistema operativo guest. La macchina reale su cui viene eseguito l'hypervisor è chiamata Host. La Full Virtualization (Virtualizzazione Completa) si riferisce alla virtualizzazione totale di un server con tutti i suoi componenti, ma esistono altre due tecniche che differiscono per il livello di astrazione che utilizzano: Para-virtualizzazione Virtualizzazione a livello di sistema operativo (Container)

**Infrastruttura Virtualizzata Cloud** In un datacenter ci sono più server interconnessi, e ognuno di essi esegue un hypervisor. Le VM possono essere create dinamicamente man mano che i cloud consumer richiedono nuove risorse per ospitare nuovi servizi cloud. Ogni VM può comunicare con host esterni (per esporre servizi) o con altre VM (per implementare servizi complessi).

![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260304103255.png]]

**Provisioning Dinamico** Il provisioning dinamico si riferisce alla creazione/distruzione di VM (scalabilità orizzontale), o all'aumento/diminuzione delle risorse delle VM esistenti (scalabilità verticale). 300 300 scaling out: vengono allocate nuove risorse. scaling down: le risorse vengono deallocate. La scalabilità orizzontale è l'approccio più diffuso; la scalabilità verticale è meno comune perché richiede più tempo per allocare e deallocare le risorse di un'intera VM, ma è conveniente in quanto non richiede modifiche tecniche all'applicazione, sebbene si sia limitati dalle risorse totali disponibili in un singolo server fisico.

![[_linked_images/02.5 Magistrale/01 First Year/Second Semester/immagini/Pasted image 20260304103651.png]]

Metering: la virtualizzazione consente l'effettiva misurazione delle risorse informatiche (misurare e monitorare l'utilizzo di una risorsa); nell'informatica tradizionale avevamo solo un set base di funzioni di misurazione che non erano adeguate.