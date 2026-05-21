## What is Mosquitto
Per dubbi controllare il loro [sito](https://mosquitto.org)
**Eclipse Mosquitto** is an open source (EPL/EDL licensed) message broker that implements the MQTT protocol versions 5.0, 3.1.1 and 3.1. Mosquitto is lightweight and is suitable for use on all devices from low power single board computers to full servers.

The MQTT protocol provides a lightweight method of carrying out messaging using a publish/subscribe model. This makes it suitable for **Internet of Things** messaging such as with low power sensors or mobile devices such as phones, embedded computers or microcontrollers.

The Mosquitto project also provides a **C library** for implementing MQTT clients, and the very popular **mosquitto_pub** and **mosquitto_sub** command line MQTT clients.
## Comandi

``` bash
brew services stop mosquitto
```

``` bash
brew services start mosquitto
```

``` bash
mosquitto_sub -h 127.0.0.1 -t roba
```

## Usare Mosquitto con contiki
nel make file va aggiunto MODULES += $(CONTIKI_NG_APP_LAYER_DIR)/mqtt

```
``
## Setting up mosquitto.conf

``` bash
(base) pietrobambagioni@MacBook-Pro-di-Pietro ~ % cd /opt/homebrew 
(base) pietrobambagioni@MacBook-Pro-di-Pietro homebrew % brew list mosquitto
/opt/homebrew/Cellar/mosquitto/2.1.2/bin/mosquitto_ctrl
/opt/homebrew/Cellar/mosquitto/2.1.2/bin/mosquitto_db_dump
/opt/homebrew/Cellar/mosquitto/2.1.2/bin/mosquitto_passwd
/opt/homebrew/Cellar/mosquitto/2.1.2/bin/mosquitto_pub
/opt/homebrew/Cellar/mosquitto/2.1.2/bin/mosquitto_rr
/opt/homebrew/Cellar/mosquitto/2.1.2/bin/mosquitto_signal
/opt/homebrew/Cellar/mosquitto/2.1.2/bin/mosquitto_sub
/opt/homebrew/Cellar/mosquitto/2.1.2/etc/mosquitto/ (4 files)
/opt/homebrew/Cellar/mosquitto/2.1.2/homebrew.mosquitto.service
/opt/homebrew/Cellar/mosquitto/2.1.2/homebrew.mxcl.mosquitto.plist
/opt/homebrew/Cellar/mosquitto/2.1.2/include/mosquitto/ (33 files)
/opt/homebrew/Cellar/mosquitto/2.1.2/include/ (5 files)
/opt/homebrew/Cellar/mosquitto/2.1.2/lib/libmosquitto.2.1.2.dylib
/opt/homebrew/Cellar/mosquitto/2.1.2/lib/libmosquittopp.2.1.2.dylib
/opt/homebrew/Cellar/mosquitto/2.1.2/lib/pkgconfig/ (2 files)
/opt/homebrew/Cellar/mosquitto/2.1.2/lib/ (9 other files)
/opt/homebrew/Cellar/mosquitto/2.1.2/sbin/mosquitto
/opt/homebrew/Cellar/mosquitto/2.1.2/sbom.spdx.json
/opt/homebrew/Cellar/mosquitto/2.1.2/share/man/ (14 files)

(base) pietrobambagioni@MacBook-Pro-di-Pietro homebrew % find /opt/homebrew -name "mosquitto.conf" 2>/dev/null
(base) pietrobambagioni@MacBook-Pro-di-Pietro homebrew % mkdir -p /opt/homebrew/etc/mosquitto
(base) pietrobambagioni@MacBook-Pro-di-Pietro homebrew % nano /opt/homebrew/etc/mosquitto/mosquitto.conf
(base) pietrobambagioni@MacBook-Pro-di-Pietro homebrew % brew services stop mosquitto 
Stopping `mosquitto`... (might take a while)==> **Successfully stopped `mosquitto` (label: homebrew.mxcl.mosquitto)**

(base) pietrobambagioni@MacBook-Pro-di-Pietro homebrew % mosquitto -c /opt/homebrew/etc/mosquitto/mosquitto.conf

1778656245: Info: running mosquitto as user: pietrobambagioni.
1778656245: mosquitto version 2.1.2 starting
1778656245: Config loaded from /opt/homebrew/etc/mosquitto/mosquitto.conf.
1778656245: Bridge support available.
1778656245: Persistence support available.
1778656245: TLS support available.
1778656245: TLS-PSK support available.
1778656245: Websockets support available.
1778656245: Opening ipv6 listen socket on port 1883.
1778656245: Opening ipv4 listen socket on port 1883.
1778656245: mosquitto version 2.1.2 running
1778656310: New connection from 127.0.0.1:64551 on port 1883.
1778656310: New client connected from 127.0.0.1:64551 as auto-0A01C312-E430-684E-9C9D-5821F60A0F71 (p4, c1, k60).
1778656330: New connection from 127.0.0.1:64552 on port 1883.
1778656330: New client connected from 127.0.0.1:64552 as auto-965FDE0D-D16C-CE23-A633-DB79ED82EC10 (p4, c1, k60).
1778656330: Client auto-965FDE0D-D16C-CE23-A633-DB79ED82EC10 [127.0.0.1:64552] disconnected.
1778656330: Client auto-965FDE0D-D16C-CE23-A633-DB79ED82EC10 [127.0.0.1:64552] disconnected: connection closed by client.
```


Lo status non dovrebbe essere dichiarato come global
> **Real device warning**: State variables must be placed as global variables. Contiki doesn’t ensure consistency over context switches for local variables