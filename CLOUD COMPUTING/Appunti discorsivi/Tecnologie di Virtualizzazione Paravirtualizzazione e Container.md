
Finora abbiamo visto come la _Full Virtualization_ (senza supporto hardware) <font color="#f79646">causi un enorme overhead</font>, poiché il Guest OS non sa di essere virtualizzato. Le istruzioni privilegiate generano continui [[Tecnologie di Virtualizzazione (Senza Supporto Hardware)#Full Virtualization Modello "Trap and Emulate"|trap]], context switch ed emulazioni da parte dell'hypervisor. Per risolvere questo problema prima dell'avvento del supporto hardware, è nata una soluzione alternativa: la **Paravirtualizzazione**.

## 1. Paravirtualizzazione (Paravirtualization)

L'idea alla base della [[Virtualizzazione#Paradigmi di Virtualizzazione|paravirtualizzazione]] è semplice ma radicale: **modificare il sistema operativo Guest** (specificamente il suo kernel) in modo che sia _consapevole_ di essere eseguito all'interno di una Macchina Virtuale. <font color="#4bacc6">Le applicazioni utente</font>, invece, <font color="#4bacc6">rimangono invariate e non si accorgono di nulla</font>.

Questo approccio <font color="#f79646">rompe il principio di </font>"<font color="#f79646">isolamento perfetto</font>" <font color="#f79646">e di</font> "<font color="#f79646">OS intatto</font>", ma <font color="#9bbb59">porta enormi vantaggi prestazionali</font>. Il Virtual Machine Monitor (VMM) espone un livello di interfaccia speciale (Virtualization Layer) composto da API.

### Le Hypercalls

Invece di tentare di eseguire istruzioni privilegiate (generando un costoso trap), <font color="#c0504d">il kernel del Guest OS modificato utilizza queste API chiamate</font> **Hypercalls**. Le [[Cloud Computing ITA#Paravirtualization – Implementation|hypercalls]] sono chiamate dirette al [[Virtualizzazione#Architettura Server e Ruolo dell'Hypervisor|VMM]], eseguite in modalità privilegiata. In pratica, il Guest OS "delega" volontariamente le operazioni critiche all'[[Virtualizzazione#Architettura Server e Ruolo dell'Hypervisor|hypervisor]], eliminando la necessità di intercettare gli errori ed emularli.

**Pro e Contro:**

- **Vantaggi:** <font color="#9bbb59">Prestazioni nettamente superiori rispetto alla full virtualization software e nessun bisogno di supporto hardware specifico</font>.
    
- **Svantaggi:**<font color="#f79646"> Richiede la modifica del codice sorgente del sistema operativo</font> (facile per Linux, q<font color="#ff0000">uasi impossibile per sistemi closed-source come Windows</font>)<font color="#f79646"> ed è meno flessibile</font>.
    

_Nota:_ Oggi questa tecnica è molto meno utilizzata, poiché soppiantata dalla virtualizzazione assistita via hardware (HVM).

### L'esempio di Xen

**Xen** è un famoso hypervisor (<font color="#4bacc6">basato su kernel Linux</font>) nato proprio per la paravirtualizzazione. <font color="#4bacc6">È un hypervisor minimale che si installa direttamente sull'hardware</font>. In Xen, le macchine virtuali sono chiamate **Domain**. Esiste un dominio speciale, il **Dom0**, che ha il compito di gestire la creazione, il controllo e l'amministrazione di tutti gli altri domini (VM). <font color="#548dd4">Xen oggi supporta sia la paravirtualizzazione che la full virtualization</font> (se c'è supporto hardware).

---

## 2. Virtualizzazione Leggera (Lightweight Virtualization)

Le Macchine Virtuali classiche offrono un isolamento eccellente, ma <font color="#f79646">portano con sé un overhead notevole in termini di memoria e performance</font>,<font color="#c0504d"> poiché ogni VM deve caricare un intero sistema operativo</font> (kernel compreso). <font color="#4bacc6">Cosa succede se vogliamo solo isolare delle applicazioni senza portarci dietro il peso di decine di sistemi operativi duplicati</font>? La risposta è la **Lightweight Virtualization**, ovvero la **Virtualizzazione a livello di Sistema Operativo**.

### Operating System Virtualization (Container)

L'idea è eliminare del tutto l'hypervisor e i kernel duplicati. Si utilizza **un solo kernel condiviso** (quello della macchina host), modificato per supportare ambienti isolati in _User Space_. <font color="#4bacc6">Questi ambienti non sono vere macchine virtuali</font>, ma **Container**.

![[Pasted image 20260405160842.png]]

Ad esempio, possiamo avviare 100 ambienti isolati che usano Linux senza dover avviare 100 kernel Linux separati. Ogni processo all'interno del container crede di essere l'unico in esecuzione e di avere il sistema tutto per sé.

**Pro e Contro dei Container:**

- **Vantaggi:**<font color="#9bbb59"> Overhead quasi nullo, avvio istantaneo, prestazioni praticamente native e un'altissima densità</font> (se ne possono far girare moltissimi sulla stessa macchina).
    
- **Svantaggi:** <font color="#f79646">Condividendo tutti lo stesso kernel, un bug critico nel kernel compromette tutti i container</font>. Inoltre, c'è <font color="#f79646">meno flessibilità </font>(su un kernel Linux puoi far girare solo container Linux).
    

---

## 3. I pilastri dei Linux Container

I container su Linux funzionano grazie alla combinazione di due funzionalità fondamentali del kernel che assicurano che un ambiente possa accedere _solo_ <font color="#c0504d">alle risorse che gli sono state assegnate</font>.

### Namespaces 

I <font color="#c0504d">Namespaces si occupano di isolare</font> la **vista** delle risorse. Sono un'evoluzione del vecchio comando `chroot` e <font color="#c0504d">garantiscono un isolamento completo</font> per processi, rete e file system. Tuttavia, i namespaces <font color="#4bacc6">limitano</font> solo _<font color="#4bacc6">cosa</font>_ <font color="#4bacc6">il processo può vedere</font> (es. gli faccio vedere una sola CPU), ma <font color="#9bbb59">non limitano</font> _quanto_ <font color="#9bbb59">può consumare di quella risorsa</font> (es. non controllano quanto tempo CPU consuma).

### Control Groups 

I control groups o <font color="#c0504d">cgroups</font> <font color="#c0504d">si occupano di</font> **limitare le risorse fisiche**. <font color="#4bacc6">Vengono usati per imporre dei tetti massimi al consumo di CPU</font>, <font color="#4bacc6">RAM e banda di I/O</font>. Insieme, _Namespaces_ (isolamento visivo) e _cgroups_ (controllo delle risorse) formano il cuore della tecnologia dei container.

---

## 4. Docker e il Serverless Computing

[[Docker]] è la piattaforma che ha reso i container uno standard mondiale per lo sviluppo e la distribuzione del software. I <font color="#9bbb59">vantaggi di Docker sono legati al fatto che impacchetta l'applicazione insieme a tutte le sue dipendenze</font> (librerie, configurazioni) <font color="#9bbb59">in un ambiente completo e pronto all'uso</font>. Addio al famoso problema _"sul mio computer funzionava"_.

- Si parte da un'**Immagine** (il pacchetto statico) scaricata da un repository chiamato **Docker Registry**.
    
- Il **Docker Engine** prende questa immagine e la esegue, creando un'istanza viva, ovvero il Container.
    
![[Pasted image 20260405161118.png]]
### L'evoluzione: Serverless Computing

I container hanno spianato la strada a nuove architetture, come i <font color="#c0504d">microservices</font> e il **Serverless Computing**. <font color="#c0504d">In questo modello</font>, invece di fare il deploy di intere macchine virtuali, <font color="#c0504d">gli sviluppatori caricano piccoli servizi</font> (spesso incapsulati in container) <font color="#c0504d">con dipendenze già configurate</font>, <font color="#c0504d">pronti a scattare solo quando vengono richiamati, ottimizzando al massimo l'uso delle risorse</font>.