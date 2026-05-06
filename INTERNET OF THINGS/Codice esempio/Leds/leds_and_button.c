/*
 * Copyright (c) 2006, Swedish Institute of Computer Science.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the Institute nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * This file is part of the Contiki operating system.
 *
 */

#include "contiki.h"
#include <stdio.h>
#include "os/dev/leds.h"
#include "os/dev/button-hal.h"

PROCESS(led_and_button, "Led and Button");
AUTOSTART_PROCESSES(&led_and_button);

PROCESS_THREAD(led_and_button, ev, data){
    button_hal_button_t *btn;
    PROCESS_BEGIN();
    btn = button_hal_get_by_index(0);
        while(1) {
             PROCESS_YIELD();
             if(ev == button_hal_press_event) {
                 leds_single_on(LEDS_YELLOW);
             }else if(ev == button_hal_release_event){
                 leds_on(LEDS_BLUE);
             }else if(ev == button_hal_periodic_event) {
                 btn = (button_hal_button_t *)data;
                 if(btn->press_duration_seconds > 3) {
                     leds_single_off(LEDS_YELLOW);
                     leds_off(LEDS_BLUE);
                   }
            }
    }
    PROCESS_END();
}
