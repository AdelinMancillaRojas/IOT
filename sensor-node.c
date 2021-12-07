#include "contiki.h"
#include "net/netstack.h"
#include "net/routing/routing.h"
#include "net/ipv6/simple-udp.h"
#include "sys/log.h"
#define LOG_MODULE "Sink Node App"
#define LOG_LEVEL LOG_LEVE_INFO
static struct simple_udp_connection connection;

PROCESS(sensor_node,"sensor Node"); expected a ';'
AUTOSTART_PROCESSES(&sensor_node); expected a type specifier

PROCESS_THREAD(sensor_node,ev,data)
{
    static struct etimer periodic_time;
    static unsigned counter;
    static char buffer [32]; 
    uip_ipaddr_t server _adress;

    PROCESS_BEGIN();
    simple_udp_register(& connection,CLIENT_PORT,NULL,SERVER_PORT,NULL);
    etimer_set(&periodic_timer, SEND_INTERVAL);
    while(1){
    PROCESS_WAIT_EVENT_UNTIL(etimer_expired(&periodic_timer));
    
    uint8_t is_node_reachable = NETSTACK_ROUTING.is_node_reachable(); 
    uint8_t got_server_address = NETSTACK_ROUTING.get_root_ipaddr(&server_address); 
   if(id_node_reachable&& got_server_address){

   
    LOG_INFO("Sending request %u to ",counter);
    LOG_INFO_6ADDR(sever_address);
    LOG_INFO_("\n");
    snprintf(buffer),"PAcket No. %d",counter ++);
}
    PROCESS_END();
}