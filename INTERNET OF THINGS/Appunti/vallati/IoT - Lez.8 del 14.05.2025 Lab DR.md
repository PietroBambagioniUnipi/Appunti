# MQTT (Message Queuing Telemetry Transport)
_Application protocol to apply to the sensors._
_Vedremo come CoAP client può essere implementato sui sensori._
_Alla fine (ultimi lab) faremo breve introduzione su grafana (utile per il progetto)._
- MQTT is a publish-subscribe application protocol.
- Initially it was defined for industrial telemetry (monitor oil pipeline in the desert).
- It is adopted today to connect IoT devices into the Cloud, thanks to its lightweight structure and simplicity.
- It is based on TCP.
- Information is exchanged using topics, e.g. ‘temperature’, ‘sensor1/led’, etc

## Data Reporting
![[Pasted image 20250514085000.png|400]]
MQTT nasce per il data reporting.
Questo può essere utile per il progetto.
==min5== hai iot devices, che pubblicano dati al broker con publish. i dati vanno al broker. dall'altro lato c'è cloud application che vuole update. all'inizio si subscribe a sensor1. ogni volta che arriva una nuova misurazione viene girata all'applicazione.

### Actuator
![[Pasted image 20250514090053.png|400]]
c'è un attuatore ==min6==
c'è anche un remote telemetry application legata al cloud.
attuatore deve ricevere i dati, è subscribe to a topic ==min7==
smartbulb subscribe to a broker. the remote telemetry application send a publish message ... ==min8DR==
è il 99% dei casi che avremo nel progetto. altrimenti hai due dispositivi (uno subscribe e uno publishes).

## Mosquitto
- Nodes programmed to send periodic updates and to receive updates on a given topic
- We use an MQTT broker running locally implemented using Mosquitto, an open source MQTT broker
- To install Mosquitto: sudoapt-get install mosquitto _(installa un servizio, del broker)_
- It also has a set of command line tools:sudoapt-get install mosquitto-clients _(ha command line tools to test the mttq implementation)_

### Modify Mosquitto conf file
By default Mosquittorequires auth and listen only on IPv4 ==min11DRA==
Change /etc/mosquitto/mosquitto.conf _(lo apri con nano)_
```
listener 1883 0.0.0.0
listener 1883 ::
allow_anonymous true
```

_Dopo devi ristartare il servizio:_ `sudo systemctl restart mosquitto.service`

### Mosquitto command line tools
- Subscribe to a topic: `mosquitto_sub-h IP_BROKER -t TOPIC` _(su un terminale)_
- Publish on a topic: `mosquitto_pub -h IP_BROKER -t TOPIC -m MESSAGE` _(su altro terminale)_
- Check Mosquitto log: `less /var/log/mosquitto/mosquitto.log`

_Credo che per funzionare devo avere il border router fatto con righetti... e niente, ci si vede un'altra volta. Bye_

### Contiki MQTT client implementation
==min19-22DRA== _mi sono persa perché non mi funziona la parte prima..._
MQTT client is implemented with a state machine with 6 states:
- INIT: client being initialized
- NET_OK: device connected to net
- CONNECTING: device connecting to MQTT broker
- CONNECTED: device connected to broker
- SUBSCRIBED: device subscribed to some topic (if needed)
- DISCONNECTED: device is disconnected from the broker

![[Pasted image 20250514091653.png|250]]

### Implementation architecture
The MQTT client will have a **main loop** performing operations depending on the current state:
- Check that network connectivity is OK
- Connect to the broker
- Subscribe to a topic
- Publish something

It will also have an **event function** that will automatically be invoked by the system when a certain event is triggered, e.g.: ==min22==
- MQTT_EVENT_CONNECTED
- MQTT_EVENT_DISCONNECTED
- MQTT_EVENT_PUBLISH
- MQTT_EVENT_SUBACK
- MQTT_EVENT_UNSUBACK
- MQTT_EVENT_PUBACK

### Contiki-NG MQTT Support
MQTT support in Contiki is implemented in an event-based manner.
The client can invoke some operations on the MQTT connection, the operation is performed asynchronously, when completed an event is posted on a handler
In the Makefile add: `MODULES += $(CONTIKI_NG_APP_LAYER_DIR)/mqtt`

### Data structures
```c#
#include "mqtt-client.h"
// Data structure that stores the connection status
static struct mqtt_connectionconn;
/* MQTT broker address. */
#define MQTT_CLIENT_BROKER_IP_ADDR "fd00::1"
static const char *broker_ip= MQTT_CLIENT_BROKER_IP_ADDR;
// Default config values
#define DEFAULT_BROKER_PORT 1883
#define DEFAULT_PUBLISH_INTERVAL (30 * CLOCK_SECOND)
/* Maximum TCP segment size and length of IPv6 addresses */
#define MAX_TCP_SEGMENT_SIZE 32
#define CONFIG_IP_ADDR_STR_LEN 64
```

`fd00::1` _= ip address del nostro ..., di tutte le applicazioni in esecuzione sulla nostra VM ==min24==, Ripreso a ==min47==_
`(30 * CLOCK_SECOND)` _= lo useremo per i timer (per publish i dati periodicamente ogni 30s)_

The mqtt_message data structure can be used to decode a received message:
`static struct mqtt_message *msg_ptr = 0;`
_static struct mqtt_message_ `*msg_ptr = 0;`
_data structure that rapresent a mqtt ... ==min26==_
- `msg_ptr`$\to$`topic`, contains the topic
- `msg_ptr`$\to$`payload_chunk`, contains the payload
- `msg_ptr`$\to$`payload_length`, contains the length of the payload

### Buffers
```c#
// Buffers for Client ID and Topics.
#define BUFFER_SIZE 64
static char client_id[BUFFER_SIZE];
static char pub_topic[BUFFER_SIZE];
static char sub_topic[BUFFER_SIZE];
// Application level buffer
#define APP_BUFFER_SIZE 512
static char app_buffer[APP_BUFFER_SIZE];
```

### Timer
The application periodically checks the connection and updates the internal status (see the core of the application).
To this aim we define a timer:
```c#
// Periodic timer to check the state of the MQTT client
#define STATE_MACHINE_PERIODIC (CLOCK_SECOND >> 1)
static struct etimerperiodic_timer;
```

_timer che useremo per periodic operation of our program_

### Check connectivity
Before any MQTT operation, the network has to be initialized correctly.
This function could be used to check that the network is operational.
_Strumento di cui abbiamo bisogno all'inizio per controllare se il sensore è correntemente collegato a una rete o meno._
```c#
static bool
have_connectivity(void)
{
	if(uip_ds6_get_global(ADDR_PREFERRED) == NULL ||
	   uip_ds6_defrt_choose() == NULL) {
		return false;
	}
	return true;
}
```

### Status
_All'inizio dobbiamo anche definire la variabile stato per poter tenerlo sotto controllo._
_Abbiamo delle macro. ==min29==_
Different client statuses are defined to keep track of the status of the client.
```c#
/* Various states */
static uint8_t state;
#define STATE_INIT          0 // Initial state
#define STATE_NET_OK        1 // Network is initialized
#define STATE_CONNECTING    2 // Connecting to MQTT broker
#define STATE_CONNECTED     3 // Connection successful
#define STATE_SUBSCRIBED    4 // Topics of interest subscribed
#define STATE_DISCONNECTED  5 // Disconnected from MQTT broker
```
**Real device warning**: State variables must be placed as global variables. Contiki doesn’t ensure consistency over context switches for local variables.
_ATTENZIONE: le variabili di stato devono essere globali! Altrimenti saranno implementate nello stack e cancellate._

### MQTT event handler
```c#
static void
mqtt_event(struct mqtt_connection*m, mqtt_event_tevent, void *data)
{
	switch(event) {
		case MQTT_EVENT_CONNECTED: {
		// Connection completed
		…
		case MQTT_EVENT_DISCONNECTED: {
		// Disconnection occurred
		…
		case MQTT_EVENT_PUBLISH: {
		// Notification on a subscribed topic received
		// Data variable points to the MQTT message received
		…
		case MQTT_EVENT_SUBACK: {
		// Subscription successful
		…
		case MQTT_EVENT_UNSUBACK: {
		// Subscription canceled
		…
		case MQTT_EVENT_PUBACK: {
		// Publishing completed
		…
}
```
MQTT is event based, the core returns notifications to a handler every time an event occurs.
_Event function handle events quando avvengono._
`*m` _= pointer to mqtt connection data structure._
_==min32==_
_Devi gestire gli eventi ricevuti dalla libreria._

### Main thread -Initialization
_Main loop of the program. Anzi, in realtà questa è internal inizialization, il main loop deve ancora iniziare._
```c#
printf("MQTT Client Process\n");
// Initialize the ClientID as MAC address of the node
snprintf(client_id, BUFFER_SIZE, "%02x%02x%02x%02x%02x%02x",
	linkaddr_node_addr.u8[0], linkaddr_node_addr.u8[1],
	linkaddr_node_addr.u8[2], linkaddr_node_addr.u8[5],
	linkaddr_node_addr.u8[6], linkaddr_node_addr.u8[7]);

// Broker registration
mqtt_register(&conn, &mqtt_client_process, client_id, mqtt_event,
	MAX_TCP_SEGMENT_SIZE);
state=STATE_INIT;
```
`&conn` = The MQTT connection data structure.
`&mqtt_client_process` = The pointer to the main application process.
`mqtt_event` = The callback function.

_Inizializzi il client id usando il mac address del nodo._
_Prima operazione dopo il main loop è la broker registration (anche se il nome inganna, in realtà non fa attività di rete ma inizializza la struttura dati, procedura di inizializzazione)._

### Main thread-loop
main loop (infinito)
```c#
// Initialize periodic timer to check the status
etimer_set(&periodic_timer, STATE_MACHINE_PERIODIC);

/* Main loop */
while(1) {
	PROCESS_YIELD();
	if((ev == PROCESS_EVENT_TIMER && data == &periodic_timer)
	    || ev == PROCESS_EVENT_POLL){
		// Manage the states
		…
	}
}
```
`&periodic_timer` $\to$ Periodically the main process checks if the status of the application has changed.
_Se abbiamo una lista di stati ... ==min36==_

### Check Connectivity
When the network is initialized the client moves from `STATE_INIT` to `STATE_NET_OK`
```c#
if(state==STATE_INIT){
	if(have_connectivity()==true)
		state = STATE_NET_OK;
}
```
_primo stato ==min36==_

### Connect to the broker
A connection to broker is attempted, the status is updated to `STATE_CONNECTING`.
```c#
if(state == STATE_NET_OK){
	// Connect to MQTT server
	printf("Connecting!\n");
	
	memcpy(broker_address, broker_ip, strlen(broker_ip));
	
	mqtt_connect(&conn, broker_address, DEFAULT_BROKER_PORT,
		(DEFAULT_PUBLISH_INTERVAL * 3) /CLOCK_SECOND, MQTT_CLEAN_SESSION_ON);
	state = STATE_CONNECTING;
}
```
_secondo stato ==min37==_
_(evento indicato dal prof è MQTT_EVENT_CONNECTED, ==min38==)_

### Register subscriptions
Issue subscriptions, the status is updated to `STATE_SUBSCRIBED`.
```c#
if(state==STATE_CONNECTED){
	// Subscribe to a topic
	strcpy(sub_topic,"actuator");
	status = mqtt_subscribe(&conn, NULL, sub_topic, MQTT_QOS_LEVEL_0);
	printf("Subscribing!\n");
	if(status == MQTT_STATUS_OUT_QUEUE_FULL) {
		LOG_ERR("Tried to subscribe but command queue was full!\n");
		PROCESS_EXIT();
	}
	state = STATE_SUBSCRIBED;
}
```
Le funzioni `mqtt_subscribe` e `mqtt_connect` sono asincrone ==min39==, per questo event-based approach.

### Publish
_Dopo che sei connesso e subscribed, ad ogni iterazione puoi pubblicare un messaggio._
When everything is working, start publishing periodically a new value.
```c#
if(state == STATE_SUBSCRIBED){
	// Publish something
	sprintf(pub_topic, "%s", "status");
	sprintf(app_buffer, "report %d", value);
	value++;
	
	mqtt_publish(&conn, NULL, pub_topic, (uint8_t*) app_buffer,
		strlen(app_buffer), MQTT_QOS_LEVEL_0, MQTT_RETAIN_OFF);
}
```

Esercizio
_Suggerimento: apri il codice (in particolare mqtt-client.c) che ha caricato e cerca di capirlo._
- Create a MQTT client that connect to an MQTT broker running on the host (you need to deploy a border router to connect the sensor to the MQTT broker)
- The MQTT client must
	- Connect to the broker
	- Subscribe to the ‘actuator’ topic
	- Periodically send an incremental int value to the topic ‘status’
- In order tocheck that everything is working run:
	- `mosquitto_sub` to subscribe to the topic ‘status’
	- `mosquitto_pub` to publish a new value on the topic ‘actuator’


_Domanda: ==min47==_
![[Pasted image 20250514095647.png|250]]

_Altra domanda (per il progetto): CoAP vs MQTT $\to$ quando è meglio usare l'uno e quando l'altro ==min52DRAA==_