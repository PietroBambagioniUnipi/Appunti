#include "contiki.h"
#include "net/netstack.h"
#include "net/ipv6/simple-udp.h"
#include "sys/log.h"
#include <stdio.h>
#include <string.h>

#define LOG_MODULE "App"
#define LOG_LEVEL LOG_LEVEL_INFO

#include "contiki.h"
#include "net/netstack.h"
#include "net/ipv6/simple-udp.h"
#include "sys/log.h"
#include <stdio.h>
#include <string.h>


#define LOG_MODULE "App"
#define LOG_LEVEL LOG_LEVEL_INFO


#define UDP_CLIENT_PORT 8765
#define UDP_SERVER_PORT 5678

static struct simple_udp_connection udp_conn;


PROCESS(udp_server_process, "UDP Server Java Exercise");
AUTOSTART_PROCESSES(&udp_server_process);


static void
udp_rx_callback(struct simple_udp_connection *c,
                const uip_ipaddr_t *sender_addr,
                uint16_t sender_port,
                const uip_ipaddr_t *receiver_addr,
                uint16_t receiver_port,
                const uint8_t *data,
                uint16_t datalen)
{
  
  LOG_INFO("Ricevuto UDP: '%.*s' (lunghezza %u byte)\n", datalen, (char *)data, datalen);
  LOG_INFO("Mittente: ");
  LOG_INFO_6ADDR(sender_addr);
  LOG_INFO_("\n");


  char response[] = "ACK: Messaggio ricevuto correttamente dal nodo!";
  
  LOG_INFO("Invio risposta di conferma al PC...\n");
  

  simple_udp_sendto(&udp_conn, response, strlen(response) + 1, sender_addr);
}

PROCESS_THREAD(udp_server_process, ev, data)
{
  PROCESS_BEGIN();
  simple_udp_register(&udp_conn, UDP_SERVER_PORT, NULL,
                      UDP_CLIENT_PORT, udp_rx_callback);

  LOG_INFO("UDP Server pronto. In ascolto sulla porta %u\n", UDP_SERVER_PORT);

  while(1) {

    PROCESS_WAIT_EVENT();
  }

  PROCESS_END();
}
