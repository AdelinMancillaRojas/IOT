#include "contiki.h"
#include "net/netstack.h"
#include "net/nullnet/nullnet.h"
#include <strig.h>
#include "sys/log.h"
#define LOG_MODULE "Broadcast Sendig App"
#define LOG_LEVEL LOG_LEVE_INFO
#define SEND_INTERVAL (8* CLOCK_SECOND)

PROCESS(broadcast_seder,"Broadcast Sender Example"); expected an __is_identifier
AUTOSTART_PROCESSES(&broadcast_sender);
PROCESS_THREAD(broadcast_sender,ev,data)
{
    static struct etimer periodic timer; incomplete type is not allowed
    static unsigned couter = 0;

    PROCESS_BEGIN();
    nullnet_buf= (uint8_t *) &counter;
    nullnet_set = sizeof(counter);
    etimer_set(&periodic_timer, SEND_INTERVAL); identifier "CLOCK_SECOND" is undefind
    while(1){
        PROCESS_WAIT_EVENT_UNTIL(etimer_expired(periodic_timer));
        LOG_INFO("Seding%u\n", counter);
        memcy(nullnet_buf, &couter, sizeof(counter));
        nullnet_len=sizeof(counter);
        NETSTACK_NETWORK.output(NULL);
        counter++;
        etimer_reset(&periodic_timer);
        
    }
    PROCESS_END();
}