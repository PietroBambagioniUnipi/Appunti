#include "contiki.h"
#include "dev/leds.h" /* Libreria per i LED */

PROCESS(leds_blink_process, "LED Blink Process (Dongle)");
AUTOSTART_PROCESSES(&leds_blink_process);
/*---------------------------------------------------------------------------*/
PROCESS_THREAD(leds_blink_process, ev, data)
{
  /* Dichiariamo il timer (deve essere 'static' per sopravvivere ai cicli del thread) */
  static struct etimer timer;

  PROCESS_BEGIN();

  /* Spegniamo preventivamente tutti i LED per partire da una situazione pulita */
  leds_off(LEDS_ALL);

  /*
   * Impostiamo il timer. 
   * "Periodo di 2 secondi" significa 1 secondo ACCESO e 1 secondo SPENTO.
   * Quindi impostiamo il timer a 1 secondo (CLOCK_SECOND).
   */
  etimer_set(&timer, CLOCK_SECOND * 1);

  while(1) {
    /* Mettiamo il processo in pausa finché il timer non scade */
    PROCESS_WAIT_EVENT_UNTIL(etimer_expired(&timer));

    /* * 'leds_toggle' è una funzione comodissima che inverte lo stato:
     * se il LED è acceso lo spegne, se è spento lo accende.
     */
    leds_toggle(LEDS_YELLOW | LEDS_BLUE);

    /* Riavvia il timer da zero per il prossimo ciclo */
    etimer_reset(&timer);
  }

  PROCESS_END();
}
