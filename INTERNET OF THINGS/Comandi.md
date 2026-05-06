## Trovare i dongle connessi (macOS)
Identifica il punto di mount del dongle USB-Seriale.


``` Bash
ls /dev/tty.usbmodem*
```

_Nota: Il risultato sarà simile a `/dev/tty.usbmodem14101`. Sostituisci `<PORTA>` nei comandi successivi con l'output esatto._

## Compilazione e Caricamento (Flashing)
Il dongle deve essere in modalità bootloader (pulsante di reset premuto, LED rosso lampeggiante) prima di eseguire questo comando. Sostituire `nome_progetto` con il nome esatto del file C (senza l'estensione `.c`).


``` BAsh
make TARGET=nrf52840 BOARD=dongle PORT=<PORTA> nome_progetto.dfu-upload
```

## Monitoraggio Output Seriale (Login)
Per visualizzare le stampe (printf) e i log di sistema. Eseguire rigorosamente **dopo** che il flash è terminato e il dongle si è riavviato.


``` Bash
make TARGET=nrf52840 BOARD=dongle PORT=<PORTA> login
```

## Struttura del Makefile  
Ogni directory di un'applicazione richiede un file `Makefile` configurato per puntare alla root di Contiki.



``` makefile
CONTIKI_PROJECT = nome_del_progetto
all: $(CONTIKI_PROJECT)

# Forza l'uso di IPv6 (Opzionale in Contiki-NG, in quanto default)
MAKE_NET = MAKE_NET_IPV6

# Percorso relativo alla directory principale di Contiki-NG
CONTIKI = ../..

# Inclusione delle regole di compilazione (Nota: lo spazio dopo "include" è obbligatorio)
include $(CONTIKI)/Makefile.include
```

## Struttura del Progetto (Client/Server)
Separare logicamente e fisicamente i nodi con ruoli diversi.

- Creare una directory `server/` contenente `server.c` e il suo `Makefile`.
- Creare una directory `client/` contenente `client.c` e il suo `Makefile`.
- _Motivazione tecnica:_ Evita conflitti di compilazione tra file oggetto `.o` e semplifica la gestione dei target quando si flashano nodi multipli contemporaneamente.

# Cooja

#### Navigazione nella Directory del Simulatore
Spostarsi fisicamente nella directory di Cooja. Sostituire `<CONTIKI_ROOT>`con il percorso reale della repository (es. `~/contiki-ng`).


``` Bash
cd ~/contiki-ng/tools/cooja
```

#### Esecuzione tramite Gradle Wrapper
Avviare il simulatore. Assicurarsi di essere all'interno della directory `cooja` prima di lanciare questo comando.


``` Bash
./gradlew run
```

_Note Operative Aggiuntive:_

- **Primo Avvio:** L'esecuzione iniziale impiegherà svariati minuti poiché il wrapper scaricherà automaticamente la versione corretta di Gradle e tutte le dipendenze Java necessarie. Richiede connessione internet attiva.
- **Risoluzione Problemi (Permessi):** Se il terminale restituisce `Permission denied`, garantire i permessi di esecuzione allo script wrapper con: `chmod +x gradlew` prima di riprovare.</CONTIKI_ROOT>


### Motes
**1. Creazione del Prototipo (Mote Type)** È obbligatorio definire il binomio hardware/software prima di allocare le risorse nella simulazione.

- Dalla barra dei menu superiore, navigare in: `Motes` -> `Add motes` -> `Create new mote type`.
- Selezionare l'architettura target richiesta. Per la simulazione software standard in Contiki-NG, selezionare sempre **Cooja mote**.

**2. Configurazione e Building** Nella finestra di dialogo "Create Mote Type", eseguire i seguenti passaggi in sequenza rigorosa:

- **Description:** Assegnare un identificatore logico chiaro (es. "Border Router" o "UDP Client"). Non lasciare il nome di default.
- **Contiki process / Firmware:** Cliccare sul pulsante `Browse` e selezionare esclusivamente il file sorgente principale `.c`del progetto (es. `udp-server-node.c`).
- Cliccare sul pulsante **Compile**.
- _Verifica Critica:_ Analizzare l'output nel pannello inferiore nero. Procedere al passaggio successivo _solo_ se appare il messaggio di successo verde. La presenza di testo rosso indica un errore fatale nel codice C o nel Makefile che deve essere risolto esternamente.
- Cliccare su **Create**.

**3. Istanziazione e Topologia** Verrà mostrata la finestra di dialogo "Add motes". Qui si definisce la topologia di rete:

- **Number of new motes:** Inserire il numero esatto di istanze da generare basate sul Mote Type appena compilato.
- **Positioning:** Definire la distribuzione spaziale per la propagazione radio.
    - _Random Position:_ Adatto per stress test di reti mesh disordinate.
    - _Linear / Ellipse:_ Richiesto per test su topologie rigidamente controllate.
    - _Manual:_ Selezionare questa opzione per definire le coordinate (X,Y) nodo per nodo
- Cliccare su **Add motes**.

**4. Regole Post-Inserimento**
- I nodi generati appariranno istantaneamente nel pannello "Network" e verranno registrati nel "Simulation visualizer".
- Per alterare i range di trasmissione o ricezione radio, trascinare i nodi manualmente nel pannello "Network". L'area verde rappresenta l'intervallo di trasmissione utile, l'area grigia l'intervallo di interferenza.
- Per architetture Client-Server: Ripetere obbligatoriamente l'intero processo dal Punto 1 per creare un secondo "Mote Type", associandogli il file `.c` del secondo ruolo. Non mescolare ruoli sullo stesso Mote Type.
### Comunicazione

**1. Identificazione del Nodo**

- Avvia la simulazione in Cooja e assicurati che i nodi siano posizionati nel pannello _Network_.
- Individua visivamente il nodo che esegue il firmware del Border Router (es. Nodo 1).
 ![[cooja server socket 01.png]]

**2. Attivazione dello Strumento Seriale**

- Fai **clic destro** sul nodo Border Router nel pannello _Network_.
- Nel menu a tendina, seleziona: `Mote tools for [ID_Nodo]` -> `Serial Socket (SERVER)`.
![[cooja server socket 02.png]]


**3. Configurazione del Plugin UI** Si aprirà una nuova piccola finestra all'interno di Cooja intitolata "Serial Socket (SERVER)".

- **Listen port:** Verifica che la porta sia impostata su **60001** (è lo standard di default di Contiki-NG).
- Clicca sul pulsante **Start**.
- _Verifica dello Stato:_ Il testo nella finestra cambierà in "Listening on port 60001". Questo significa che Cooja ha aperto con successo una porta TCP locale sul tuo computer.
![[cooja server socket 03.png]]

**4. Connessione del Sistema Host (Terminal)** Ora che la UI di Cooja è in attesa ("Listening"), devi istruire il tuo sistema operativo (Linux/WSL) a connettersi a quella specifica porta aperta dalla GUI.

- Apri il terminale del tuo sistema host.
- Lancia il programma di tunneling puntando esplicitamente al server TCP appena avviato in Cooja:
    ```bash
    cd <CONTIKI_ROOT>/tools/serial-io
    ./tunslip6 -a 127.0.0.1 -p 60001 fd00::1/64
    ```

- _Esito Visivo:_ Nella finestra "Serial Socket" in Cooja, lo stato passerà istantaneamente da "Listening" a **"Client connected: /127.0.0.1"**.


**Regola di Sicurezza:** Non chiudere la finestra "Serial Socket (SERVER)" in Cooja durante la simulazione. Se la chiudi, il demone TCP viene terminato, `tunslip6` andrà in crash sul terminale dell'host, e tutti i pacchetti UDP da/per l'applicativo Java verranno droppati irrimediabilmente.