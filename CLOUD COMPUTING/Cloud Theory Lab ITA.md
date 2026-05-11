# 0B4 Virtualizzazione

- **KVM (Kernel-based Virtual Machine)**: è il modulo di virtualizzazione del kernel Linux. Funziona come **hypervisor**, cioè come livello software che permette di eseguire macchine virtuali.
- **LibVirt**: è uno strumento/framework per gestire, creare e configurare macchine virtuali.

In sintesi:

- **KVM** permette l’esecuzione delle VM.
- **LibVirt** permette di gestirle.

Un metodo comune per installare una VM è **importare una VM già preinstallata**, invece di installare manualmente il sistema operativo da zero.

- **virsh**: toolkit da linea di comando per la gestione della virtualizzazione. È il comando principale per interagire con le VM gestite da LibVirt.

Alcuni comandi importanti:

- `virsh destroy`: ferma la macchina virtuale. È simile a uno spegnimento forzato.
- `virsh undefine`: elimina la definizione della VM, cioè le informazioni di configurazione associate alla VM.
- `virsh suspend`: sospende la VM, in modo simile alla chiusura di un laptop: i programmi rimangono nello stesso stato e possono riprendere successivamente.

- **CirrOS**: piccola VM minimale usata per testare ambienti virtualizzati.

---

## Networking nelle VM

- Un **Linux bridge** è un’interfaccia virtuale che collega tra loro diverse interfacce di un sistema Linux, sia reali sia virtuali.
- Il bridge opera a **livello 2** del modello ISO/OSI, quindi si comporta in modo simile a uno **switch**.

Ogni macchina virtuale è dotata di una **scheda di rete virtuale**, gestita dall’hypervisor, che si comporta come una scheda di rete reale.

Per ogni interfaccia virtuale, ad esempio `vnet0`:

- esiste una connessione tra la VM e il sistema operativo host;
- il traffico in uscita dalla VM passa attraverso la porta collegata a `vnet0` sul host;
- le risposte ricevute dal host vengono reinserite nella VM attraverso l’interfaccia virtuale corrispondente.

- **virtbr0** è un Linux bridge, cioè una scheda di rete virtuale usata per collegare più interfacce in una rete locale interna alla macchina host.
- Raccoglie il traffico proveniente dalle VM e lo reinstrada verso l’esterno.
- In questo modo:
  - le VM possono comunicare tra loro usando il bridge come rete comune;
  - le VM possono comunicare anche con la rete esterna.

---

##### Libvirt networking

- La scheda di rete virtuale di ogni VM creata dall’hypervisor ha una corrispondente interfaccia virtuale sul sistema host.
- Per creare una rete virtuale, tutte le interfacce virtuali possono essere aggiunte a un bridge.
- In questo modo i dati possono essere scambiati tra VM diverse.
- Il bridge può essere collegato a un’interfaccia fisica per permettere lo scambio dati con la rete esterna.

![[Pasted image 20260405164404.png|300]]

---

##### Default Network (NAT)

- Di default, le VM sono connesse a una rete interna e accedono a Internet tramite **NAT**.
- La creazione di una nuova rete è gestita da LibVirt tramite il comando `virsh net-define`.
- Le specifiche della nuova rete devono essere descritte in un file **XML**.
- Le reti disponibili possono essere controllate con `virsh net-list`.

---

##### Storage Pool

- Lo storage per gli hard disk delle VM è offerto tramite **storage pool**.
- Ogni storage pool permette di creare diversi **volumi**, cioè diversi hard disk virtuali che possono essere collegati alle VM.
- I pool possono essere creati usando:
  - un filesystem esistente;
  - un’intera partizione.

- **Root hard drive**: disco principale della VM, contenente il sistema operativo.
- Ogni hard disk virtuale viene creato all’interno dello storage pool.

In Linux, un hard disk virtuale viene creato sotto forma di file. Il sistema può quindi mantenere un riferimento a questi file come se fossero dischi.

Ogni hard disk è composto da partizioni:

- una **partizione** è una porzione del disco dedicata a una certa funzione;
- ad esempio, possono esistere partizioni per il sistema operativo, per i dati o per altre funzioni specifiche.

---

##### Snapshot

- Uno **snapshot** crea una copia dello stato corrente della VM.
- Lo snapshot può includere:
  - contenuto del disco;
  - contenuto della memoria.

Dopo aver creato uno snapshot, è possibile usarlo per ripristinare lo stato precedente della VM, in modo simile a un backup.

Gli snapshot sono utili per:

- ripristinare una VM dopo errori o modifiche indesiderate;
- clonare una VM;
- creare un template di partenza per nuove VM.

Limite importante:

- gli snapshot possono non supportare dischi secondari.

---

# 0B6 Container (Docker)

- **Docker**: applicazione che offre virtualizzazione a livello di sistema operativo, permettendo di distribuire software impacchettato in **container**.
- Un **container** permette di:
  - isolare il software;
  - gestire le dipendenze;
  - eseguire applicazioni in modo riproducibile.

Docker è open-source, ma è gestito da una società privata.

- Docker è una tecnologia container per Linux che permette agli sviluppatori di impacchettare un’applicazione insieme a tutte le componenti necessarie per eseguirla.
- I container sono creati a partire da **immagini disponibili localmente**.
- Le immagini possono essere create a partire da immagini standard scaricate da repository pubblici.
- Tutte le operazioni sono gestite dal **Docker daemon**.
- Quando si esegue un container e l’immagine non è disponibile localmente, Docker la scarica automaticamente.

![[Pasted image 20260405161118.png|500]]

---

## Docker Registry e immagini

- Docker usa un punto centralizzato chiamato **Docker Registry**.
- Un Docker Registry è un server che contiene immagini e pacchetti di ambienti containerizzati disponibili agli utenti.

Ogni host installa un servizio Docker che si occupa di scaricare e installare localmente le **Docker image**.

Una **image** è una rappresentazione del filesystem che Docker ricrea localmente. Contiene:

- file binari;
- configurazioni;
- dati;
- librerie;
- dipendenze già configurate.

Il container è quindi un’istanza in esecuzione di una image.

---

##### Definire un’immagine custom

- Una Docker image personalizzata può essere creata a partire da un’immagine esistente.
- Per farlo, bisogna creare un **Dockerfile**.
- Il Dockerfile descrive l’insieme delle personalizzazioni da applicare all’immagine base.

Esempio:

- partire da un’immagine Ubuntu;
- installare un interprete Python;
- eseguire un programma Python all’avvio.

---

## Differenza tra VM e container/image

Una VM Ubuntu esegue una macchina completa:

- sistema operativo completo;
- kernel proprio;
- ambiente virtualizzato simile a una macchina fisica.

Il sistema operativo all’interno della VM non è necessariamente consapevole di essere in un ambiente virtualizzato.

Un container Ubuntu, invece:

- contiene solo filesystem, strumenti e librerie;
- non possiede un kernel proprio;
- usa il kernel dell’host.

Quindi:

- le VM sono più pesanti ma più isolate;
- i container sono più leggeri e veloci, ma condividono il kernel dell’host.

---

## Note operative su Docker

- Alcuni repository Docker hanno un **rate limit**, cioè un numero massimo di accessi o download consentiti in un certo intervallo di tempo.

- Per eliminare un’immagine, bisogna prima eliminare tutti i container associati a quell’immagine.

- Per creare un’immagine custom, si crea un file chiamato `Dockerfile` dentro una cartella di progetto.

---

##### Docker Networking

- Il **virtual router** può essere creato in modo analogo a una rete privata virtuale.
- In un’architettura a più tier, almeno un tier deve essere esposto verso l’esterno.

Il **Docker engine** crea una **rete virtuale** per permettere la comunicazione tra container diversi.

Nel comportamento di default:

- per ogni container viene creata una scheda di rete virtuale;
- ogni interfaccia virtuale ha un indirizzo IPv4 privato;
- i container possono comunicare tramite:
  - routing;
  - forwarding di livello 2, se le interfacce sono collegate tramite bridge.

Un servizio in ascolto su una porta interna del container può essere pubblicato sulla rete esterna tramite **port forwarding**.

![[Pasted image 20260405165224.png]]

Esempio:

```bash
docker run -p 80:80 nginx-ubuntu
```

Con l’opzione `-p 80:80` si indica che:

- la porta `80` del container deve essere esposta;
- essa deve essere mappata sulla porta `80` dell’host.

Quindi le richieste verso la porta `80` dell’host vengono inoltrate alla porta `80` del container.

---

##### Docker Compose

- **Docker Compose** è uno strumento che permette di definire applicazioni e ambienti composti da più container eseguiti contemporaneamente.
- Si usa un file **YAML** per definire:
  - quali container creare;
  - quali immagini usare;
  - quali porte esporre;
  - quali volumi montare;
  - quali reti usare.

I container definiti nello stesso ambiente Compose condividono la stessa rete, quindi possono comunicare facilmente tra loro.

---

##### Volumi

- Un **volume** è uno storage condiviso tra il container e il sistema host.
- Serve per:
  - salvare dati persistenti;
  - condividere file tra host e container;
  - evitare che i dati vengano persi quando il container viene eliminato.

I container in esecuzione sullo stesso host possono comunicare usando i rispettivi indirizzi IP privati sulla rete virtuale dei container.

---

# 0C3 REST Interfaces (LAB)

### Design di un’interfaccia REST

- Non esistono linee guida ufficiali uniche per la definizione di API REST, ma esistono alcune regole comuni.

Termini di base:

- **Resource**: un oggetto o una rappresentazione di qualcosa.
  - Ha associati dati e metodi per operare su tali dati.
  - Esempio: un `Employee` di un’azienda, che può essere creato, modificato o eliminato.

- **Collection**: insieme di risorse.
  - Esempio: `Employees` è la collection delle risorse `Employee`.

- **URL (Uniform Resource Locator)**:
  - percorso corrispondente alla risorsa;
  - permette di accedere alla risorsa.

---

## Operazioni REST e CRUD

Ogni azione è mappata a una delle operazioni CRUD principali:

- **GET**
- **POST**
- **PUT**
- **DELETE**

Il nome degli endpoint non dovrebbe includere l’azione. L’azione deve essere specificata dal metodo HTTP usato nella richiesta.

Esempio:

- errato: `/getEmployee()`
- corretto: usare il metodo `GET` sull’endpoint `/employee` o `/employees/{id}`

Le quattro operazioni principali sono associate alle operazioni base sui database:

- **GET**: usato per richiedere dati senza produrre modifiche.
- **POST**: usato per creare una nuova risorsa.
- **PUT**: usato per aggiornare una risorsa, usando un payload.
- **DELETE**: usato per eliminare una risorsa.

Una collection è rappresentata con il suo nome, ad esempio:

```text
/employees
```

Una singola risorsa dentro la collection può essere rappresentata con un identificatore univoco:

```text
/employees/{id}
```

---

##### API Design

- **Swagger** può essere usato per:
  - creare la documentazione delle API;
  - generare uno skeleton dell’applicazione.

È possibile eseguire Swagger dentro un container Docker e aprirlo usando l’indirizzo IP della VM.

Swagger usa **YAML** per descrivere le API. In particolare, descrive:

- il base URL del sistema;
- i path dei metodi;
- il tipo di risposta;
- la struttura delle richieste;
- gli schemi delle risorse.

![[Pasted image 20260418171339.png]]

È possibile anche definire lo **schema delle risorse**, cioè la struttura dei dati gestiti dall’API.

![[Pasted image 20260418171353.png]]

La funzione **Generate Server** di Swagger permette di generare uno skeleton del codice API definito nel file YAML.

![[Pasted image 20260410101503.png]]

Altre note:

- è possibile passare variabili locali a Docker tramite `-e`;
- è possibile usare un database ospitato dentro un container da altri container;
- è possibile generare comandi `curl` da Swagger per testare le API.

![[Pasted image 20260501201633.png]]

---

### Apache Tomcat

- **Apache Tomcat** è un’implementazione open-source delle **Java Servlet**.
- Una Servlet è un componente software che estende le funzionalità di un web server, permettendo di eseguire codice Java in risposta a una richiesta HTTP.

Le Java Servlet sono l’equivalente Java di altre tecnologie per contenuti web dinamici, come:

- PHP;
- ASP.NET.

Tomcat crea un server HTTP per ricevere richieste dai client.

Il server può avere una o più Servlet istanziate.

Una **Servlet** è un oggetto che:

- riceve una richiesta;
- elabora la richiesta;
- genera una risposta.

Le Servlet vengono impacchettate in un file **WAR (Web Application Archive)**.

---

### Python Flask

- **Flask** è un framework leggero per applicazioni web in Python.
- È progettato per produrre applicazioni REST nel modo più semplice possibile.
- Il package prodotto da Swagger è pronto per essere eseguito dentro un container.

---

### HAProxy

- **HAProxy** può essere usato per bilanciare le richieste tra più VM o più container.

Esempio:

```bash
docker run --name=flask1 --network=labnet -p 8081:8080 -d rest-server
```

In questo esempio:

- `8081` è la porta usata per le richieste esterne;
- `8080` è la porta usata internamente dal servizio.

![[Pasted image 20260418172327.png]]

---

## Cosa aggiunge HAProxy a un’architettura multi-tier

- **Space uncoupling**:
  - il client invia richieste a un singolo endpoint stabile, ad esempio `:80`;
  - il client non sa quante istanze backend esistono;
  - il client è disaccoppiato dalla struttura interna del sistema.

- **Load balancing**:
  - le richieste sono distribuite tra repliche Flask;
  - il round-robin è una politica comune di default;
  - è possibile aggiungere più repliche senza modificare il client.

- **Health checks**:
  - HAProxy monitora i backend;
  - se un container o una VM fallisce, HAProxy smette automaticamente di instradare traffico verso quell’istanza.

---

# 0C5 Message Queue Systems (LAB)

### RabbitMQ

- **RabbitMQ** è un software open-source di tipo **message broker**.
- Implementa il protocollo **AMQP (Advanced Message Queuing Protocol)**.
- Esistono librerie per diversi linguaggi di programmazione che permettono di interfacciarsi con RabbitMQ.
- Tra queste c’è **PIKA**, una libreria Python.
- PIKA fornisce un’interfaccia per usare RabbitMQ da Python.

---

## Architettura base

L’architettura base include:

- una applicazione **Producer**;
- una applicazione **Consumer**;
- un **Broker**, cioè RabbitMQ.

Il funzionamento è:

- il Producer inserisce messaggi in coda;
- il Consumer preleva messaggi dalla coda;
- RabbitMQ si occupa di instradare i messaggi tra Producer e Consumer.

Questo paradigma può anche essere bidirezionale:

- il Producer produce una richiesta;
- il Consumer consuma la richiesta;
- il Consumer produce una risposta alla richiesta.

![[Pasted image 20260501202535.png]]

---

### RabbitMQ flow

RabbitMQ internamente è composto da:

- un insieme di **queue**, cioè code di messaggi;
- un insieme di **exchange**, che si occupano dell’instradamento dei messaggi.

Il routing avviene secondo un insieme di regole chiamate **binding**.

Flusso:

1. Il Producer pubblica un messaggio verso un exchange.
2. Quando viene creato un exchange, bisogna specificarne il tipo.
3. L’exchange riceve il messaggio ed è responsabile del suo instradamento.
4. L’exchange considera diversi attributi del messaggio, ad esempio la **routing key**, a seconda del tipo di exchange.
5. Vengono creati dei binding tra exchange e queue.
6. L’exchange instrada il messaggio verso una o più queue in base agli attributi del messaggio.
7. I messaggi rimangono nella queue finché non vengono gestiti da un consumer.
8. Il consumer riceve e gestisce il messaggio.

![[Pasted image 20260418173123.png|400]]

---

## Exchange, queue e binding

- L’**exchange** è un’entità che implementa una certa politica di messaggistica.
- Un broker può avere diversi exchange, ognuno con politiche diverse.
- L’exchange sceglie in quale queue inserire il messaggio.
- Il routing dipende da vari fattori, tra cui:
  - routing key;
  - tipo di exchange.
- Ogni exchange può avere associato un insieme di queue.
- Ogni queue è collegata all'exchange tramite un binding.

---

### Exchange types

Ogni queue può essere associata a una **routing key** o a una **binding key**.

Esistono tre tipi principali di exchange:

- **Direct**:
  - il messaggio viene instradato verso le queue la cui binding key corrisponde esattamente alla routing key del messaggio.

- **Fanout**:
  - l’exchange invia il messaggio a tutte le queue collegate ad esso.
  - È usato per il broadcast.

- **Topic**:
  - l’exchange effettua un match tramite wildcard tra la routing key e il pattern specificato nel binding.

![[Pasted image 20260418172814.png]]

---

## Note operative su RabbitMQ

- L’exchange sceglie il tipo di instradamento; il default è spesso il tipo **direct**.
- La **routing key** è un’etichetta assegnata al messaggio, usata dall’exchange per decidere dove instradarlo.
- Il **body** è il contenuto del messaggio.

---

## Consumer

Il consumer:

- resta attivo in attesa di messaggi da consumare;
- possiede una **callback function**, invocata automaticamente ogni volta che arriva un messaggio da una specifica queue;
- si iscrive a una queue tramite una primitiva di consumo;
- quando avvia il consumo, l’esecuzione del programma rimane bloccata in attesa dei messaggi.

Quindi il consumer si comporta come un componente **event-driven**: non esegue continuamente richieste manuali, ma reagisce all’arrivo dei messaggi.

---

### Work Queues

Le **Work Queues**, o **Task Queues**, permettono di distribuire task computazionalmente intensivi tra diversi worker.

Funzionamento:

- uno o più producer incapsulano un task dentro un messaggio;
- il messaggio viene inviato al sistema di message queue;
- un worker disponibile, appartenente a un pool di worker, riceve il task;
- il worker elabora il task.

Ogni worker:

- si sottoscrive alla queue;
- riceve messaggi da processare.

Questo schema è utile per distribuire il carico di lavoro e parallelizzare l’elaborazione.

---

### Message Routing

- Il **routing complesso** dei messaggi può essere realizzato creando più exchange e più binding.
- Un **binding** è una relazione tra un exchange e una queue.
- Il comportamento di routing dipende dal tipo di exchange.

Esempio con direct exchange:

- il messaggio viene inviato alle queue la cui binding key corrisponde esattamente alla routing key del messaggio.

---

### Message Broadcast

Nel caso precedente, i messaggi venivano distribuiti tra i consumer registrati alla stessa queue usando una politica simile al round-robin.

Se invece si vuole che i messaggi siano consegnati a tutti i subscriber, bisogna usare un exchange di tipo **fanout**.

Con **fanout**:

- il messaggio viene copiato verso tutte le queue collegate all’exchange;
- ogni subscriber riceve una copia del messaggio.

---

### Message Exchange by Topic

Il tipo **topic exchange** permette di instradare messaggi in base a una sequenza di parole, chiamate topic, separate da punti.

Esempio di routing key:

```text
<celerity>.<color>.<species>
```

Le definizioni dei topic possono usare wildcard:

- `*` sostituisce esattamente una parola;
- `#` sostituisce zero o più parole.

Questo permette di creare binding key flessibili, capaci di ricevere messaggi da producer diversi.

Esempio:

- con il pattern `<celerity>.<color>.<species>`;
- Q1 riceve tutti i messaggi relativi ad animali arancioni;
- Q2 riceve tutti i messaggi relativi a conigli o animali lenti.

![[Pasted image 20260418173721.png]]

---

# 0D2 OpenStack Installation (LAB)

### Concetti chiave

- **MicroStack**
  - deployment OpenStack single-node;
  - utile per laboratorio, test e apprendimento.

- **Snap**
  - package manager usato per l’installazione.

- **Initialization**
  - fase di inizializzazione;
  - configura automaticamente tutti i servizi OpenStack necessari.

- **Horizon**
  - interfaccia web di OpenStack;
  - permette di gestire VM, reti, immagini, volumi e altre risorse.

- **Keystone password**
  - password richiesta per l’autenticazione;
  - Keystone è il servizio di identità e autenticazione di OpenStack.

---

# 0D3 OpenStack Operations (LAB)

### Flavors

- Un **Flavor** definisce la configurazione hardware di una VM.

Include:

- CPU, cioè numero di vCPU;
- RAM;
- dimensione del disco.

Il flavor determina quante risorse vengono allocate alla VM al momento della creazione.

Punto importante:

- deve esistere almeno un flavor prima di poter creare VM.

Creazione di un flavor:

- Admin → Flavors → Create Flavor

![[Pasted image 20260501203650.png|333]]

---

### Pre-created Flavors

OpenStack può fornire flavor già creati, che rappresentano configurazioni standard di risorse.

![[Pasted image 20260501203731.png]]

---

### Images

Le VM vengono istanziate a partire da **Images**.

Una image è:

- un template di disco virtuale;
- contiene un sistema operativo già installato;
- viene usata come base per creare nuove istanze.

Requisito:

- deve essere disponibile almeno una image per creare VM.

Upload di un’immagine:

- Admin → Images → Create Image
- selezionare il file scaricato.

---

### Instantiate a VM

Per creare una VM si usa l’operazione di launch instance:

- Project → Compute → Instances → Launch Instance

Durante la creazione bisogna scegliere:

- image;
- flavor;
- rete da assegnare.

Il risultato è una **Instance**, cioè una VM in esecuzione.

---

### Inspect Running VM

Per visualizzare le VM in esecuzione:

- Admin → Compute → Instances

Ogni VM ha:

- un host, cioè il nodo fisico su cui viene eseguita;
- un indirizzo IP interno sulla rete privata.

---

### Console Access

OpenStack fornisce una **web console**.

La web console permette accesso diretto alla VM, come se fosse un terminale remoto.

È utile quando:

- non è ancora configurato SSH;
- la rete esterna non è raggiungibile;
- bisogna fare debugging della VM.

---

### Network Configuration

Di default OpenStack contiene:

- una rete interna privata;
- una rete esterna pubblica.

La rete privata collega le VM tra loro.

La rete esterna permette la comunicazione con l’esterno, tipicamente tramite router e NAT.

---

### Create a New Network

Percorso:

- Admin → Network → Networks → Create Network

Scopo:

- isolare gruppi di VM;
- creare topologie di rete personalizzate;
- separare componenti diversi dell’applicazione.

---

### Attach VM to Network

È possibile collegare una VM a una nuova rete tramite:

- Instances → Attach Interface

Una VM può avere più interfacce di rete.

Questo permette a una stessa VM di appartenere a reti diverse.

---

### Floating IPs

I **Floating IP** servono per esporre una VM verso Internet o verso la rete esterna.

Idea chiave:

- la VM ha un IP privato;
- il Floating IP è un IP pubblico o esterno;
- il Floating IP viene mappato all’IP privato tramite **NAT**.

Punto importante:

- il Floating IP non viene assegnato direttamente all’interfaccia della VM;
- viene associato alla VM tramite il sistema di rete di OpenStack.

Assegnazione:

- Instance → Associate Floating IP → Request new IP

---

### Security Groups (Firewall)

I **Security Groups** implementano regole firewall.

Di default:

- tutto il traffico in ingresso è bloccato.

Per abilitare traffico in ingresso:

- Network → Security Groups → Manage Rules → Add Rule

Esempi:

- permettere SSH sulla porta 22;
- permettere HTTP sulla porta 80.

Quindi, anche se la VM ha un Floating IP, senza regole di Security Group adeguate il traffico esterno può essere bloccato.

---

### Virtual Router

Un **router virtuale** è necessario per collegare:

```text
rete interna ↔ rete esterna
```

Creazione:

- Project → Network → Routers → Create Router

Il router:

- ha un’interfaccia sulla rete esterna;
- instrada traffico tra reti;
- esegue NAT.

---

### Connect Router to Internal Network

Per collegare il router alla rete interna:

- aprire la configurazione del router;
- andare nella tab Interfaces;
- aggiungere un’interfaccia verso la rete interna.

Senza questa configurazione:

- le VM non possono raggiungere la rete esterna;
- la rete interna resta isolata.

---

### Volumes

Un **Volume** è un disco virtuale aggiuntivo collegabile a una VM.

Caratteristiche:

- può essere collegato e scollegato dinamicamente;
- persiste indipendentemente dal ciclo di vita della VM;
- può contenere dati anche se la VM viene eliminata.

Creazione:

- Volumes → Create Volume

Nota:

- i volumi potrebbero non essere disponibili in alcune installazioni MicroStack.

---

### Concetti chiave OpenStack

- **Flavor** → definisce le risorse della VM.
- **Image** → template del sistema operativo.
- **Instance** → VM in esecuzione.
- **Floating IP** → accesso esterno tramite NAT.
- **Security Groups** → regole firewall.
- **Router** → connette rete privata e rete pubblica.
- **Volume** → storage persistente.
- **SDK / CLI** → strumenti di automazione.

---

# 0D5 Kubernetes Installation (LAB)

### Charmed Bundle (installazione basata su Juju)

- Un **Charmed Bundle** è un meccanismo di deployment automatizzato basato su **Juju**.
- Usa un file **YAML** per descrivere:
  - quali componenti installare, ad esempio control plane e worker;
  - dove installarli, cioè su quali macchine;
  - i parametri di configurazione di ciascun componente.

Idea chiave:

- permette un deployment Kubernetes automatizzato su più macchine;
- è più vicino a uno scenario reale o production-like rispetto a una singola macchina locale.

---

### Minikube (Kubernetes single-node)

- **Minikube** è un’installazione leggera di Kubernetes.
- Esegue Kubernetes su una singola macchina.
- È usato per:
  - testing;
  - sviluppo;
  - apprendimento.

Limite:

- non rappresenta un ambiente di produzione.

Minikube usa Docker, o altri container runtime, come motore di esecuzione dei container.

---

### Concetti chiave Kubernetes Installation

- **Juju / Charmed Bundle**
  - deployment multi-node più simile alla produzione.

- **Minikube**
  - ambiente locale di test.

- **Docker**
  - container runtime.

- **kubectl**
  - interfaccia da linea di comando per interagire con il cluster Kubernetes.

- **CNI plugins**
  - componenti che implementano il networking dei Pod.

- **MetalLB**
  - soluzione per fornire load balancing esterno in ambienti locali.

---

# 0D6 Kubernetes Operations (LAB)

### Define a Pod

Kubernetes usa un modello **dichiarativo**.

Questo significa che:

- l’utente descrive lo stato desiderato;
- Kubernetes cerca di mantenere il sistema coerente con quello stato.

Un **Pod** è:

- la più piccola unità deployabile in Kubernetes;
- può contenere uno o più container.

I container all’interno dello stesso Pod condividono:

- rete, cioè stesso indirizzo IP;
- storage;
- ciclo di vita.

La configurazione di un Pod è definita tramite un file **YAML**.

![[Pasted image 20260501204522.png]]

---

### Deployment with Replicas

I Pod da soli non offrono una gestione completa del ciclo di vita.

In particolare, un Pod isolato non gestisce automaticamente:

- riavvio;
- scaling;
- aggiornamenti controllati.

Un **Deployment** gestisce i Pod e garantisce:

- numero desiderato di repliche;
- riavvio automatico in caso di fallimento;
- self-healing;
- rolling updates.

Il Deployment controlla quindi che il numero di Pod attivi corrisponda allo stato desiderato.

![[Pasted image 20260501204634.png|300]]

---

### Service Exposure

I Pod non dovrebbero essere esposti direttamente.

Motivo:

- i Pod sono dinamici;
- possono essere eliminati e ricreati;
- il loro IP può cambiare.

Per questo serve un **Service**.

Un Service fornisce un punto di accesso stabile verso uno o più Pod.

---

#### Internal service (ClusterIP)

- **ClusterIP** è il tipo di Service usato per comunicazione interna al cluster.
- Fornisce un IP virtuale interno.
- È raggiungibile solo dall’interno del cluster.
- Viene usato per comunicazione service-to-service.

---

### Endpoints

Ogni Pod ha un IP interno sulla rete privata del cluster.

Problema:

- i Pod sono dinamici;
- quando vengono ricreati, possono ottenere un nuovo IP.

Soluzione:

- il Service fornisce un **IP virtuale stabile**;
- il Service mantiene il collegamento verso i Pod disponibili tramite gli endpoint.

---

### ClusterIP Behavior

Un Service di tipo ClusterIP espone un **Virtual IP**.

Le richieste inviate a questo IP vengono:

- ricevute dal Service;
- distribuite tra i Pod associati;
- bilanciate automaticamente.

Quindi il Service funziona come punto di accesso stabile e come meccanismo di load balancing interno.

---

### Expose the Service to External Systems

Per esporre un servizio fuori dal cluster Kubernetes si può usare **NodePort**.

Comportamento:

- Kubernetes apre una porta su ciascun nodo;
- la porta viene assegnata in un intervallo predefinito, di solito `30000–32767`;
- il traffico in ingresso sulla porta del nodo viene inoltrato al Service;
- il Service inoltra poi il traffico ai Pod.

Schema:

```text
client esterno → NodePort → Service → Pod
```

---

### LoadBalancer

La soluzione preferita in ambienti di produzione è usare un **LoadBalancer** esterno.

Caratteristiche:

- assegna un indirizzo IP pubblico;
- distribuisce il traffico tra più Pod;
- implementa automaticamente politiche di bilanciamento del carico.

Schema:

```text
client esterno → LoadBalancer → Service → Pod
```

In ambienti cloud reali, il tipo `LoadBalancer` viene integrato con il load balancer del cloud provider.

---

### Minikube Bug / Known Issue

Riferimento:

```text
https://github.com/kubernetes/minikube/issues/13898
```

Problema:

- in Minikube, LoadBalancer e networking possono non funzionare correttamente in alcuni casi;
- questo dipende dal fatto che Minikube è un ambiente locale single-node, non un vero ambiente cloud.

---

### Horizontal Autoscaling

Obiettivo:

- scalare automaticamente il numero di Pod in base al carico.

Il meccanismo principale è l’**Horizontal Pod Autoscaler (HPA)**.

Scenario tipico:

- creare un Deployment;
- simulare carico computazionale elevato;
- impostare limiti o richieste di CPU per Pod;
- Kubernetes osserva le metriche;
- se il carico aumenta, Kubernetes aumenta il numero di repliche;
- se il carico diminuisce, Kubernetes può ridurre il numero di repliche.

L’autoscaling rende l’applicazione più adattiva rispetto al carico.

---

### Concetti chiave Kubernetes Operations

- **Pod** → unità minima, gruppo di container.
- **Deployment** → gestisce ciclo di vita, repliche, restart e update.
- **Service** → punto di accesso stabile ai Pod.
- **ClusterIP** → comunicazione interna al cluster.
- **NodePort** → esposizione esterna tramite porta sui nodi.
- **LoadBalancer** → esposizione esterna tramite load balancer.
- **HPA** → scalabilità automatica in base alle metriche.





- nella installazione all in one si inserisce controller node e compute node nello stesso nodo, si usa di solito una configurazione del genere per fare testing
- si hanno diversi framework per poterlo installarlo, noi useremo Kolla-Ansible, è uno dei piu usati, e anche uno dei framework piu usati per gestire l'infrastruttura
- è un tool per automatizzare il deploy di un sistema distribuito in un infrastruttura distribuita
- implementa la **infrastructure as code** un trend che consiste nel riprogrammare un infrastruttura non a mano, ma semplicemente eseguendo del codice
- Ansible è un engine di automazione per il management della configurazione
- è un tool agentless quindi tutto è gestibile eseguendo comandi su shh 
- gli sviluppatori descrivono le azioni da eseguire semplicemente eseguendo degli editing ad un file YAML e ansible esegue gli step per eseguire quello stato

- In ansible ci sono due ruoli un nodo di controllo (un qualsiasi nodo linux con ansible), descrivi cosa vuoi fare
- managed node, che sono i target della roba che vuoi fare

- **Ansible playbook**: file di configurazione yaml di ansible, si ha all'interno il task, un po di sintassi ansible che dice che pacchetti installare, e task per controllare la corretta esecuzione del setup

- la volume functionality non funziona su ministack 

- gli utenti possono creare vm o hw virtualizzato, ma solo l'admin puo gestire la piattaforma
- la project tab è usata per creare e distruggere risorse
- le tab admin e identity e fanno visualizzare tutte le vm del sistema e creare nuovi utenti
- ogni utente è associato ad un progetto (una collezione di oggetti virtualizzati che appartengono a uno o piu utenti)


- flavor specifica il set di risorse che devi rendere disponibile nella tua VM con anche la quantità
- solo l'admin puo farlo, gli utenti normali no 
- solo l'admin puo creare image


- se il vm root hd deve essere creato come un volume istanziato sul local file system dell hv, è un file system che funziona tramite cloud storage, e coinvolge piu di una vm, quindi non funzionerebbe su una singola macchina, mettendo no lo istanzia come normale file locale
- ci sono alcuni step obbligatori, alcuni no (gli obbligatori sono details, source, flavors e networks)