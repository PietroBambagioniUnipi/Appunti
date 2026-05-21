### Architettura e Fondamenti di Docker

Docker è una piattaforma open-source progettata per automatizzare il deployment, la scalabilità e la gestione delle applicazioni all'interno di ambienti isolati chiamati **container**. Rappresenta l'implementazione commerciale e standardizzata del paradigma di _Operating System Level Virtualization_.

L'obiettivo ingegneristico primario di Docker è risolvere la problematica delle dipendenze ambientali (il classico "sul mio computer funziona"), garantendo che il software venga eseguito in modo identico a prescindere dall'infrastruttura sottostante (sviluppo, test o produzione).

---

### Differenza Architetturale: Container vs Virtual Machine

Alla luce dei concetti di virtualizzazione, è imperativo tracciare una linea di demarcazione netta tra VM e Container Docker:

- **Virtual Machine (VM):** Virtualizza l'hardware tramite un Hypervisor. Ogni VM include un intero sistema operativo (Guest OS), le librerie e l'applicazione. Genera un overhead elevato in termini di RAM, CPU e spazio su disco. I tempi di avvio si misurano in minuti.
    
- **Docker Container:** Virtualizza il Sistema Operativo. Non esiste un Hypervisor né un Guest OS. I container condividono il kernel dell'OS della macchina host. Contengono esclusivamente l'applicazione e le sue dipendenze dirette (binari/librerie). L'overhead è prossimo allo zero e i tempi di avvio si misurano in millisecondi.
    

---

### Componenti Core (Gli Oggetti Docker)

L'ecosistema Docker si fonda su tre entità logiche fondamentali:

#### 1. Dockerfile

È il file sorgente, un documento di testo contenente la sequenza imperativa di istruzioni necessarie per assemblare un'immagine. Definisce l'ambiente di base, copia i file dell'applicazione, espone le porte di rete e specifica il comando di esecuzione.

#### 2. Image (Immagine)

È un template a sola lettura (read-only) generato dalla compilazione (build) di un Dockerfile. Contiene il codice sorgente, le librerie, le dipendenze, gli strumenti e i file necessari per far girare l'applicazione.

- **Analogia logica:** L'immagine è paragonabile a una "Classe" nella programmazione orientata agli oggetti, o a un disco di installazione immodificabile.
    

#### 3. Container (Contenitore)

È l'istanza in esecuzione (runnable instance) di un'immagine. Quando un'immagine viene avviata, Docker vi sovrappone un livello temporaneo in lettura/scrittura (R/W layer), creando il container.

- **Caratteristiche:** È effimero per natura. Se un container viene distrutto, i dati generati al suo interno e non salvati altrove vengono persi in modo irreversibile.
    
- **Analogia logica:** Il container è l'"Oggetto" istanziato a partire dalla "Classe" (Immagine).
    

---

### Architettura di Sistema (Client-Server)

Docker utilizza un'architettura client-server, dove i componenti comunicano tramite API REST, socket UNIX o interfacce di rete.

- **Docker Daemon (`dockerd`):** È il motore (server) in esecuzione sulla macchina host. Ascolta le richieste API e gestisce attivamente gli oggetti Docker (crea le immagini, avvia i container, alloca i volumi e le reti).
    
- **Docker Client (`docker`):** È l'interfaccia a riga di comando (CLI) utilizzata dall'utente. Quando si digita un comando (es. `docker run`), il client non esegue il lavoro fisicamente, ma inoltra la richiesta al Daemon.
    
- **Docker Registry:** È il sistema di archiviazione e distribuzione delle immagini (un repository).
    
    - **Docker Hub:** È il registry pubblico predefinito, dove chiunque può scaricare immagini ufficiali (es. Ubuntu, Nginx, PostgreSQL) o caricare le proprie. I registry possono essere anche privati (per uso aziendale interno).
        

---

### Gestione dei Dati e Rete

Poiché i container sono per definizione volatili, Docker implementa meccanismi specifici per la persistenza dei dati e la comunicazione.

- **Volumes (Volumi):** Sono directory allocate direttamente sull'host fisico, ma montate all'interno del file system del container. Sopravvivono al ciclo di vita del container. Costituiscono il metodo raccomandato (e più performante) per salvare i dati persistenti (es. i file di un database).
    
- **Networking:** Docker crea reti virtuali isolate per permettere ai container di comunicare tra loro o con il mondo esterno. Il network bridge di default isola i container dalla rete host, richiedendo il "port mapping" (esposizione esplicita delle porte logiche) per consentire l'accesso esterno all'applicazione.
    

---

### Flusso Operativo Standard

Per comprendere il ciclo vitale, questo è il flusso di lavoro operativo:

1. **Codifica:** Si scrive il codice dell'applicazione e si definisce l'ambiente nel **Dockerfile**.
    
2. **Build:** Si esegue `docker build` per compilare il Dockerfile e generare l'**Immagine**.
    
3. **Ship:** (Opzionale) Si usa `docker push` per inviare l'immagine a un **Registry** per la distribuzione.
    
4. **Run:** Sulla macchina di destinazione, si esegue `docker run` per scaricare l'immagine (se non presente) e istanziarla in un **Container** in esecuzione.

Altri comandi sono disponibili [[02-container#Docker Quick Reference|qui]]