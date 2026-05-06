# Sistemi di telemetria: Gestione e Visualizzazione dei dati
## Sistemi di telemetria
_Telemetry system = sistema IoT dove i dispositivi IoT raccolgono i dati di un ambiente (una macchina, o una casa, ...) e li mandano a un altro dispositivo (cloud)._
_I sistemi di telemetria hanno la caratteristica principale che la maggiornanza del traffico è upward traffic (dal sensore al cloud), con sporadici dati che sono mandati dal cloud al dispositivo IoT (minoranza del traffico). I dati infine arrivano alla piattaforma cloud che dà delle funzionalità agli user (come l'amministratore)._

I sistemi di telemetria sono sistemi IoT in cui il traffico è principalmente "in uscita", ovvero traffico dai dispositivi IoT verso un "collettore", un sistema esterno (ad esempio un sistema cloud) dove i dati vengono raccolti e analizzati.
![[Pasted image 20250522110640.png|350]]

## Collettore
Il collettore è un modulo del sistema che raccoglie i dati dai dispositivi IoT.
I dati ricevuti vengono solitamente memorizzati in un database.
Sono disponibili molti database specifici per serie temporali (InfluxDB, Gnocchi, ecc.).

_Collettore = riceve dati dal dispositivo IoT. Non è il broker!_
_L'application protocol è tra collettore e IoT device (non è in controsenso con immagine che ci ha fatto vedere all'inizio della parte di Vallati)._
_Il collettore riceve i dati e li manda ad altri sensori (che dipendono dall'application task del telemetry system), in questo caso al database._
_In questo caso il **database** è specializzato per **time series** (influxDB è il più popolare), fatto apposta (ottimizzato, e con funzionalità aggiuntive per gestire grandi quantità di dati) per grandi quantità di dati organizzati in time-series (ovvero tanti dati, ognuno con timestamp)._
_Come fa un database di timeseries a gestire queste grandi quantità di dati? Li **aggrega** ==min7==, in modo da assicurare la scalabilità._
_Il database è collegato al modulo analytics, che analizza i dati e può dare allerts o suggestions._
_La web interface, collegata al database, serve a fare in modo che gli umani possano guardare i dati._
![[Pasted image 20250522111634.png|350]]

## Un semplice sistema di telemetria  
Svilupperemo un esempio di un semplice sistema di telemetria composto da: ==min8perprogetto==
- Un generatore di dati fittizi (uno script bash)
- Un database MySQL
- Un'interfaccia web Grafana

![[Pasted image 20250522111811.png|300]]

## Grafana
**Grafana** è una piattaforma web _(open source)_ di analisi che permette di analizzare dati (principalmente dati di telemetria) provenienti da diverse fonti _(che vengono da eterogenei database)_.
Consente di creare una dashboard in cui i dati vengono visualizzati in tempo reale.

## Installazione di MySQL
Segui le linee guida che puoi trovare qui: https://www.digitalocean.com/community/tutorials/how-to-install-mysql-on-ubuntu-18-04
In breve, i passi sono i seguenti:
```bash
sudo apt update
sudo apt install mysql-server
sudo mysql_secure_installation
```
_Io se non sbaglio per l'ultimo comando ho fatto: eseguito il comando, ctl-c, rieseguito, y, y, n, y._
Cambia la password del root:
```bash
sudo mysql -u root #in questo modo entri in mysql
ALTER USER 'root'@'localhost' IDENTIFIED WITH mysql_native_password BY 'PASSWORD';
#exit
systemctl restart mysql.service
```
_Attenzione alle virgolette e la password ('PASSWORD') va modificata perché non accettata (io ho modificato con: 'Password0!')_

## Creazione di un database
```bash
sudo mysql -u root -p #in questo modo entri in mysql
CREATE DATABASE sensors;
CREATE TABLE sensors.data ( id INT NOT NULL , timestamp TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP , value FLOAT NOT NULL );
#exit
```
_Facciamo il login in mysql, creiamo un database e una table (in questo caso con 3 valori: id, timestamp dato in automatico, value float)._

## Installazione di Grafana
slide8
Ci sono due metodi per installare Grafana:
- il più facile (un comando): `snap install grafana`
  _Attenzione: nella slide il comando è scritto male (grafana è con la g piccola), vedi immagine._
- uno più complesso, presente nelle slide8-9 _(io ho usato quello facile)_.
  Differenza: quello difficile è più aggiornato, ma non ci interessa.

## Login in Grafana
_Il prossimo passo è entrare nella dashboard di Grafana._
Fai il login da Browser (Chrome) _(Firefox nel mio caso)_ attraverso il seguente URL:
`http://127.0.0.1:3000`
Username e password sono admin e admin.
![[Pasted image 20250522113340.png|300]]

## Grafana
Segui i passi suggeriti dal workflow di benvenuto e aggiungi un datasource (di tipo MySQL) e crea un nuovo panel. Nel panel crea un grafico (graph).
![[Pasted image 20250522113547.png|500]]
Appunti:
- add data source $\to$ selezioni mysql, ip address 127.0.0.1 ==min16==
	host -> localhost: 127.0.0.1 _(io ho lasciato quello di default)_
	port default
	user -> root
	password -> quella che hai deciso _(Password0! nel mio caso)_
- new dashboard _(icona dei quattro quadrati sulla sinistra)_
- crei il primo graph con i dati che crei _(vedi prossimi passaggi)_

## Generazione di dati randomici
Script per generare alcuni dati randomici:
```
#!/bin/bash
i=1
while [ $i -le 100000000 ]
do
	idd=$((1 + $RANDOM % 10))
	value=$RANDOM
	mysql -uroot -pPASSWORD sensors -e "insert into sensors.data (id,value) values (${idd},${value});"
	i=$(($i+1))
	sleep 6
done
```
_al posto di -pPASSWORD scrivere la propria password (nel mio caso -pPassword0!)_

_Il codice bash è in una cartella nella cartella code>telemetry>gen.sh su Teams._
_Crei dei dati finti randomici con lo script e Grafana aggiorna i dati in tempo reale._
_Spiegazione codice: ad ogni iterazione crei un valore randomico e lo inserisci in tabella; dopo incrementi il counter e un nuovo campione è generato ogni 6 secondi._

_Apri il terminale, crei un file .sh, con il comando `nano inserisci_dati_grafana.sh` e ci incolli lo script, salvi e chiudi. Poi rendi eseguibile lo script con il comando `chmod +x inserisci_dati_grafana.sh` e lo esegui con il comando `./inserisci_dati_grafana.sh`._
_Lascia che il file venga eseguito in background e guarda Grafana._

## Creazione di una Dashboard
- Aggiungi un pannello vuoto
- Configura la query

_ATTENZIONE!!: Grafana è 6 ore indietro quindi il tempo (in alto a destra) va modificato._
![[Pasted image 20250522102834.png]]

_Avremo un dashboard che sembrerà quella nell'immagine._
![[Pasted image 20250522115205.png]]
_Il grafico è automaticamente aggiornato ad ogni campione inserito nel database._