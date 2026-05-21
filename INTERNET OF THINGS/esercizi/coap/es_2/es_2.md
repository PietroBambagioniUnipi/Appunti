Write a CoAP server that activates one resource (res-myhouse) that implements

the GET/POST/PUT handlers

– coap_activate_resource(&res_myhouse, ”home");

■ Implement the res-myhouse with the following features

– It contains an array of char to identify rooms in the house

– the number of actual and maximum rooms must be defined

```c
RESOURCE(res_myhouse,

"title=\"MyHouse: ?room=0..\” POST/PUTname=<name>&value=<value>\";rt=\"Control\"",

res_get_handler,

res_post_handler,

res_put_handler,

NULL);

static char rooms_avl[6][15] = {

"kitchen, ",

"bedroom a, ",

"hall, ",

};
```



static int actual_rooms = 3;

static int max_rooms = 7;


coap-client -L 17 -t 47 -e 'name=bathroom' -m post 'coap://[fd00::202:2:2:2]/home'