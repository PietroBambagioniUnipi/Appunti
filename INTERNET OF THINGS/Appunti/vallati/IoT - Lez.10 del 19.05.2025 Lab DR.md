# CoAP Applications
_In questa lezione vediamo java, la prossima volta python._

## Java - Californium
_Per Java useremo la libreria open source Californium._

### Apache Maven - Concetto
_Maven è uno strumento per gestire il progetto: automatizza alcune task che il programmatore dovrebbe fare manualmente come le dependencies. Dipendenze sono progetti esterni che importiamo per non reinventare oggetti da zero. Prima era fatto manualmente ma era scomodo, quindi usiamo maven. Facile da usare: creiamo file pom.xml, poi lui gestisce le dependencies automaticamente (==min4==)._
- Strumento di gestione dei progetti software
- Basato sul modello a oggetti del progetto (POM)
- Il POM è l’unità fondamentale (file XML)
    - informazioni
    - configurazione
    - dipendenze
- Standard de facto per grandi progetti Java
- Libreria Java esportata nei repository Maven

### POM - Minimal
This is an example of a minimal pom.xml file. The file describe the metadata
associated with the application and the packaging.
```xml
<project>
	<modelVersion>4.0.0</modelVersion>
	<groupId>it.unipi.iot</groupId>
	<artifactId>iot-example</artifactId>
	<version>1.0</version>
	<packaging>jar</packaging>
</project>
```

### Ereditarietà del Progetto
```xml
<project>
	<modelVersion>4.0.0<modelVersion>
	<parent>
		<groupId>it.unipi.iot</groupId>
		<artifactId>iot-example</artifactId>
		<version>1.0</version>
	</parent>
	<groupId>it.unipi.iot</groupId>
	<artifactId>server</artifactId>
	<version>1.0</version>
	<packaging>jar</packaging>
</project>
```
|--/iot-example
| --/server
| -- pom.xml
|--pom.xml
A pom.xml can inherit the configuration from a parent project.

slide6
Puoi aggregare ma non lo faremo, quindi saltiamo.

slide7 ==min5DR==
Dependencies
importiamo una versione specifica.
importiamo da una repository specifica, ma è possibile specificarla (slide8).

slide9
build section

slide10
vedremo questo esempio

slide11-12
fa tutto lui... ==min7==

slide13
il programmatore deve solo eseguire il comando `mvn clean install` (se si usa una graphic interface metti solo esegui e fa tutto lui).
Per fare clean e installare il programma.
Dopo devi eseguire il programma con `mvn package` e `java -jar target/$ARTIFACTID-0.0.1-SNAPSHOT-jar-with-dependencies.jar`.

Abbiamo saltato perché è tutto automatico.

slide14
Libreria Californium.
Devi fare i due comandi solo se vuoi modificare la libreria.

slide15
Per vedere il codice o degli esempi (ottimo inizio).

slide16
in pratica questa libreria dà struemnti per basic funzionalities di coap. Ci sono varie classi:
- CoAPServer -> It is the base class for all custom Servers.
- CoAPClient -> It is the base class for all custom Clients.
- Requests -> Provides the functionality of a CoAP request. Clients instantiate such class to issue requests to Servers.
- Response ->Provides the functionality of a CoAP response. Servers instantiate such class in reply to requests
- Option -> A message can have several Options with different or same option numbers. Every option is associated with a value of implicit type.

slide17
un server ospita delle risorse. Le risorse possono essere create con il comando in slide

slide18
==min13==

slide19
come iniziamo a creare il nostro primo progetto java che usa californium?
installiamo eclipse sulla vm.
Poi creiamo un nuovo progetto maven su eclipse (vedi slide).

slide20
poi facciamo un basic skeleton. Se vogliamo usare californium prima cosa da fare è aprire il pom file e aggiungere le due sezioni in slide.

slide21
creiamo la main class (non è creata automaticamente).
public static void main (vedi immagine a destra), specificando la superclasse da cui eredita.
Ecco come dovrebbe apparire il main (vedi in basso).

slide22
per controllare se non ho creato la main class (o se comunque non è stata creata automaticamente). se aggiungo main manualmente allora devo aggiungere questa sezione nel plugin.

slide24-29
se non vuoi usare eclipse, ma visual studio va bene lo stesso, ci sono gli step sulle slide, stessi di eclipse.
==finoamin20==

slide30
creiamo un'altra classe che definisce la risorsa.
Superclasse è CoapResource, che contiene la definizione di nuova risorsa.
invochiamo il costruttore della superclasse, rendiamo la risorsa osservabile.
get, post, put, delete. implementiamo due di questi metodi, gli altri due non sono allowed.
Facciamo due funzioni. ==min22==
Vediamo le due implementazioni di get e post...
fatte ogni volta che il server deve fare un get o un post.

slide31
prossimo passo è creare il server, instazionamo il server della slide21.
...
vuole una stringa in input("hello" in questo caso).
... ==min25==

slide32
...

slide33
esercizio

==---------------------------------------------------------------------------== 21.05.2025 (finoaslide39)
## Python - CoAPThon
### CoAPThon
CoAPThon is a Python library implementing CoAP.
Two versions are available CoAPThon for Python2 and CoAPThon3 for Python3
- https://github.com/Tanganelli/CoAPthon
- https://github.com/Tanganelli/CoAPthon3

Its implementation is very easy to use (as it is the Python language) and allows rapid deployment of applications.

### CoAPThon installation
CoAPThon can be installed using PIP, the package manager for Python.
```
sudo apt-get install python-pip/python3-pip
sudo pip/pip3 install coapthon/coapthon3
```

### Create a server
A CoAP server and a resource is created in Python as classes.
Both server and resource must be derived from CoAP and Resoruce, respectively.
```python
from coapthon.server.coap import CoAP
from coapthon.resources.resource import Resource

class ResExample(Resource):
	def __init__(self, name="ResExample", coap_server=None):
		super(ResExample, self).__init__(name, coap_server,
			visible=True, observable=True, allow_children=True)
		self.payload = "Basic Resource"
		self.resource_type = "rt1"
		self.content_type = "text/plain"
		self.interface_type = "if1"
	def render_GET(self, request):
		self.payload = "Hello"
		return self

class CoAPServer(CoAP):
	def __init__(self, host, port):
		CoAP.__init__(self, (host, port), False)
		self.add_resource("hello/", ResExample())
```

Run the server.
```python
ip = "0.0.0.0"
port = 5683

server = CoAPServer(ip, port)

try:
	server.listen(10)
except KeyboardInterrupt:
	print("Server Shutdown")
	server.close()
	print("Exiting...")
```

_Esegui il server con `python3 server.py`._

### Create a client
A simple client can be created via the HelperClient class.
```python
from coapthon.client.helperclient import HelperClient
from coapthon.utils import parse_uri

host = "127.0.0.1"
port = 5683

path = "/hello"

client = HelperClient(server=(host, port))

response = client.get(path)
print(response.pretty_print())
client.stop()
```

### Exercise 5
Create a simple Python coap server and client.