Contiki-NG – Java application

Write a Java program that sends a message (typed at command line) to an

UDP application and then print the response

Use as example:

- https://systembash.com/a-simple-java-udp-server-and-udp-client/

 build a network with two nodes

- a border router

- a server node

Develop a udp-server-node.c code that allows the node to

- receive UDP packets

- and reply with a message

 Open a terminal –> cd <path_to_the_java_file> -> javac javafile.java -> java javafile

### Esempi java
#### UDPServer.java:

``` java
import java.io.*;
import java.net.*;

class UDPServer
{
   public static void main(String args[]) throws Exception
      {
         DatagramSocket serverSocket = new DatagramSocket(9876);
            byte[] receiveData = new byte[1024];
            byte[] sendData = new byte[1024];
            while(true)
               {
                  DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);
                  serverSocket.receive(receivePacket);
                  String sentence = new String( receivePacket.getData());
                  System.out.println("RECEIVED: " + sentence);
                  InetAddress IPAddress = receivePacket.getAddress();
                  int port = receivePacket.getPort();
                  String capitalizedSentence = sentence.toUpperCase();
                  sendData = capitalizedSentence.getBytes();
                  DatagramPacket sendPacket =
                  new DatagramPacket(sendData, sendData.length, IPAddress, port);
                  serverSocket.send(sendPacket);
               }
      }
}
```

#### UDPClient.java:

``` java
import java.io.*;
import java.net.*;

class UDPClient
{
   public static void main(String args[]) throws Exception
   {
      BufferedReader inFromUser =
         new BufferedReader(new InputStreamReader(System.in));
      DatagramSocket clientSocket = new DatagramSocket();
      InetAddress IPAddress = InetAddress.getByName("localhost");
      byte[] sendData = new byte[1024];
      byte[] receiveData = new byte[1024];
      String sentence = inFromUser.readLine();
      sendData = sentence.getBytes();
      DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, IPAddress, 9876);
      clientSocket.send(sendPacket);
      DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);
      clientSocket.receive(receivePacket);
      String modifiedSentence = new String(receivePacket.getData());
      System.out.println("FROM SERVER:" + modifiedSentence);
      clientSocket.close();
   }
}
```



## Risoluzione

il file [[INTERNET OF THINGS/esercizi/java application/udpclient.java|udpclient.java]] contiene la logica che manda il messaggio attraverso la porta 5678 al [[udp-server-node.c]] che la inoltra alla mote esempio di cooja, [[README|rpl-border-router]] lo riceve

**Fase A: Sviluppo del Nodo Contiki-NG (Server)** Creare una directory dedicata per il codice embedded.

1. **Sorgente C:** Sviluppare [[udp-server-node.c]] per ricevere pacchetti UDP e rispondere.
2. **Makefile:** [[INTERNET OF THINGS/esercizi/java application/udp server node/Makefile|Creare il file di configurazione]] per il compilatore nella stessa directory.


**Fase B: Avvio e Configurazione del Simulatore (Cooja)** Preparare l'ambiente di rete prima di avviare le connessioni esterne.

1. [[Comandi#Cooja|Avviare]] Cooja.    
2. [[Comandi#Motes|Aggiungere]] il **Nodo 1 (Border Router)**: Selezionare il firmware da `<CONTIKI_ROOT>/examples/rpl-border-router/border-router.c`.
3. Aggiungere il **Nodo 2 (Server UDP)**: Selezionare il tuo firmware `udp-server-node.c`. _Nota: Assicurarsi che questo sia il nodo con ID 2 per far corrispondere l'IP standard (fd00::202:2:2:2)._
4. Cooja Workflow: Assicurarsi di ricaricare i nodi (Tasto destro -> _Reload_) se il codice C viene modificato.
5. **Avviare la simulazione** (Premere _Start_).


**Fase C: Attivazione del Bridge di Rete (tunslip6)** Stabilire il canale di comunicazione tra il sistema Host (Linux/WSL) e la rete di Cooja.
1. [[Comandi#Comunicazione|Aggiungere]] il socket 60001 al border router
2. Aggiungere il socket 5678 al server udp
3. Aprire un nuovo terminale nell'Host.
4. Navigare nella directory del Border Router:
	```Bash
    cd <CONTIKI_ROOT>/examples/rpl-border-router
    ```
5. Avviare il processo di tunneling:
    ```Bash
    make TARGET=cooja connect-router-cooja
    ```
	_Questo terminale deve rimanere aperto e in esecuzione._
 

**Fase D: Test di Connettività (Ping)** Prima di introdurre il codice Java, verificare rigorosamente che il routing IP sia funzionante a livello di sistema operativo.

1. Aprire un nuovo terminale.
2. Eseguire il ping verso l'indirizzo IPv6 del Nodo 2:
    ```Bash
   ping6 fd00::202:2:2:2
    ```
    _Procedere alla Fase E solo se i pacchetti ICMPv6 ricevono risposta._


**Fase E: Compilazione ed Esecuzione dell'App Client (Java)** Ora che la rete è stabile, gestire l'applicativo Host.

1. Navigare nel terminale verso la directory contenente `UDPClient.java`.
2. Compilare il codice sorgente:
    ``` Bash
    javac UDPClient.java
    ```
3. Eseguire l'applicazione:
    ```Bash
    java UDPClient
    ```
    L'applicativo Java è ora in grado di instradare i pacchetti UDP attraverso l'interfaccia `tun0` creata nella Fase C, raggiungendo il server simulato in Cooja.



–––File inclusi nella directory–––
[[udpclient.java]]
in rpb-border-router:  
- webserver: [[webserver.c]] [[httpd-simple.h]] [[httpd-simple.h]]
- [[border-router.c]]
- [[INTERNET OF THINGS/esercizi/java application/rpl-border-router/Makefile|Makefile]]
- [[INTERNET OF THINGS/esercizi/java application/rpl-border-router/project-conf.h|project-conf]]
- [[README]]
in udp server node: 
- [[INTERNET OF THINGS/esercizi/java application/udp server node/Makefile|Makefile]]
- [[udp-server-node.c]]


