#ifndef EC_RESOLV_H
#define EC_RESOLV_H

#include <ec_inet.h>


#define MAX_HOSTNAME_LEN   64

extern int host_iptoa(struct ip_addr *ip, char *name);

/* used by ec_dns to insert passively sniffed dns answers */
extern void resolv_cache_insert(struct ip_addr *ip, char *name);
   

   
#endif

/* EOF */

// vim:ts=3:expandtab

