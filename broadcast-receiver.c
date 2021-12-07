#include "contiki.h"
#include "net/netstack.h"
#include "net/nullnet/nullnet.h"
#include <strig.h>
#include "sys/log.h"
#define LOG_MODULE "Broadcast Sendig App"
#define LOG_LEVEL LOG_LEVE_INFO
#define WAIT_INTERVAL (8* CLOCK_SECOND)


PROCESS(broadcast_receiver,"Broadcast Received Example"); expected an __is_identifier
AUTOSTART_PROCESSES(&broadcast_receiver);
void input_callback(const void*data,
uint16_t len,
const linkaddr_t * source, const linksdr_t* destination)
if(len== sizeof(unsigned)){
    unsigned counter;
    memcpy(couter,data, sizeof(counter));
    LOG_INFO("Received %u from",counter);
    LOG_INFO_LLADDR(source);
    LOG_INFO_("\n");
}
PROCESS_THREAD(broadcast_receiver,ev,data)
{
    static struct etimer periodic timer; incomplete type is not allowed
    static unsigned couter = 0;

    PROCESS_BEGIN();
    nullnet_buf= (uint8_t *) &counter;
    nullnet_set = sizeof(counter);
    nullnet_set_input_callback(input_callback);
    etimer_set(&periodic_timer, WAIT_INTERVAL); identifier "CLOCK_SECOND" is undefind
    while(1){
        PROCESS_WAIT_EVENT_UNTIL(etimer_expired(periodic_timer));
        etimer_reset(&periodic_timer);
        
    }
    PROCESS_END();
}
