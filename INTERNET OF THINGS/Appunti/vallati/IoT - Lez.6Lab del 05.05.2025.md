# 6. TinyML / Embedded ML
==Riascolta primi 5 minuti ASSOLUTAMENTE (sono arrivata tardi)==

## ML on embedded systems
Integration of Machine Learning (ML) solutions on embedded systems allows to implement autonomous decision making on IoT devices

Some applications that are already popular: _(use cases, esempi di AI nel mondo IoT)_
- Predictive maintenance: identify signs of failure before breakdowns occur in data
- Anomaly detection: detect abnormal readings
- Autonomous decision: automation of processes or personalization of services
- Predictive analytics: forecast data to optimize systems
- Computer vision: analyze visual data from cameras
- Keyword spotting: detect a keyword to enable functions _(ha un testo e quando è individuata una chiave fa qualcosa)_

Se esegui il modello sul cloud o su un dispositivo edge (esterno, non il dispositivo stesso) la latenza è molta, poi c'è a single point of failure. Quindi è conveniente usare il modello AI o ML.

## Challenges
Running ML models on IoT devices results in a set of challenges:
- Limited memory and storage: Many IoT devices have only a few MB of RAM and storage. This restricts the complexity of models that can be deployed. _(Molti dispositivi IoT hanno poca memoria e poco storage)_
- Constrained processing power: Many IoT devices rely on low-power microcontrollers with limited CPU capacity, making it difficult to run computationally intensive ML models. _(In genere dispositivi iot hanno poca potenza quindi non posso eseguirci compiti complessi)_
- Power consumption: ML models with high computational demands drain battery-powered devices quickly. Energy efficiency is critical. _(diversa faccia della stessa medaglia)_

## _Esempio di_ keyward spotting
![[Pasted image 20250505090009.png|500]]
_Vogliamo analizzare il suono solo dopo la keyword, non tutto. Quindi abbiamo un piccolo (tiny) modello ML che fa keyward spotting, riconosce solo la parola che aziona il meccanismo._
_Questo era il workflow per keyward spotting, vediamo il workflow per iot devices._

## ML on IoT devices workflow
- General workflow for ML _(per ottenere il modello, che il 99% delle volte è troppo grande per essere eseguito su un dispositivo iot)_
	- Collect some historical data
	- Design and Train the model on a computer
	- Assess the model
- That’s new! _(parte in più per adattare il modello ad un dispositivo iot)_
	- Convert the model and deploy it on the embedded system
	- Make inference at runtime

![[Pasted image 20250505090334.png|500]]

_Vediamo come fare questi ultimi due punti (non entreremo nel dettaglio!!)._

### Model conversion
You cannot run the model after training as it is on constrained devices as their size is usually larger than the RAMavailable on the IoT device
The model needs to be converted to reduce its complexity and overhead, e.g., via quantization, pruning, etc
Tradeoff: complexity vs accuracy

_Il vincolo qui è la dimensione della RAM (limitata). Quindi approccio per conversione è ridurre la dimensione (e quindi la complessità) del modello. Si può fare con quantization o con tuning (rimuovi informazioni dalla rete, quindi sarà meno accurata, ma è un compromesso che bisogna fare). Se non ti va bene sacrificare l'accuratezza meglio che smetti di lavorarci..._

![[Pasted image 20250505090722.png|350]]

## emlearn
_emlearn = framework che permette di ridurre la dimensione del modello._
Machine learning for microcontroller and embedded systems. Train in Python, then do inference on any device with a C99 compiler.
Supports a wide range of ML models including:
- Classification
- Regression
- Anomaly/Outlier detection
- Feature extraction

GitHub page: https://github.com/emlearn/emlearn
It is one of the many available.

_Quello che faremo oggi è mettere in pratica (non ci importa la teoria) con l'esempio successivo:_

## Example –Weather Forecast
- Create a simple model for weather forecast
- Deploy it on an embedded device
- Use data from the Istanbul Weather Forecast:
  https://www.kaggle.com/datasets/vonline9/weather-istanbul-data-20092019
- Adapted from this example:
  https://github.com/BaptisteZloch/MakeIT-How-to-forecast-weather-with-Arduino-Nano-33?tab=readme-ov-file

### Workflow
- Performed on Google Colab
  https://colab.research.google.com
- Load the ‘IoTExample-WeatherForecasting.ipynb’ notebook
- Execute the steps from the notebook that implements the whole workflow for training the model, testing the model and converting the model for embedded systems.

#### Integrate the model
- The outcome of the previous phase is a .h file that contains all the weights of the model _(risultato del modello ML)_.
- This must be integrated into the program that will run on the IoT device

![[Pasted image 20250505091352.png|250]]

#### Install emlearnon the container
_installiamo emlearn framework e librerie per sviluppare il modello (workflow è automatico?)_
![[Pasted image 20250505091543.png]]
_ATTENZIONE!! Probabilmente non abbiamo contiker quindi parti direttamente da pip install emlearn_

#### Forecast using the model
importare il file
// emlearngenerated model
`#include "weather_forecast.h“`

#### Add emlearn lib in the Makefile
Make file should look like this:
```
CONTIKI_PROJECT = ml-example
all: $(CONTIKI_PROJECT)
MODULES_REL += /home/user/.local/lib/python3.10/site-packages/emlearn
TARGET_LIBFILES += -lm
INC += /home/user/.local/lib/python3.10/site-packages/emlearn
CONTIKI = ../..
include $(CONTIKI)/Makefile.include
```
_ATTENZIONE! Questi path probabilmente saranno diverse!!_
#### Forecast using the model
Prepare input and output:
```
// temp, humidity, atmospheric pressure
float features[] = { 30, 90, 1060 };
// output vector (probabilities for each weather state)
float outputs[5] = {0, 0, 0, 0, 0};
printf("%p\n",
eml_net_activation_function_strs);
// This is needed to avoid compiler error (warnings == errors)
```

_==min28DR== mesa che nell'immagine c'è qualcosa di sbagliato_
![[Pasted image 20250505091838.png|150]]
_Output vector riporta la probabilità per ciascuna di queste condizioni. Sceglie quella con probabilità maggiore._

#### Invoke predictor
Invoke predictor and print probabilities:
```
eml_net_predict_proba(&weather_forecast, features, 3, outputs, 5);
printf("%i, %i, %i, %i, %i\n", (int) ((float) outputs[0]*100), (int) ((float) outputs[1]*100), (int) ((float)outputs[2]*100), (int)((float)outputs[3]*100), (int)((float)outputs[4]*100));
```

#### Upload code
Invoke predictor and print probabilities:
`make TARGET=nrf52840 BOARD=dongle ml-example.dfu-upload PORT=/dev/ttyACM0`
![[Pasted image 20250505092133.png]]
_ATTENZIONE: potresti avere un errore riguardante una variabile che non usi. In realtà è solo un warning (ma contiki lo segnala come errore, anche se non lo è). Come risolvere: aggiungi un printf, vedi slide 15 in basso._