#include "contiki.h"

#include "sys/etimer.h"

#include <stdio.h> 

PROCESS(timers-demo, "Timers Demo");
AUTOSTART_PROCESSES(&timers-demo);

static struct etimer timer; 

PROCESS_THREAD(timers-demo, ev, data)

{
     PROCESS_BEGIN();

    etimer_set(&timer, 5 * CLOCK_SECOND);
     while (1) {
      PROCESS_WAIT_EVENT_UNTIL(etimer_expired(&timer));
     printf("Temperaure reading: 20 C\n");
     printf("Humidityreading 40 %% \n");
      break;
}


        PROCESS_END();
}
