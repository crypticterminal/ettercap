
/* $Id: ec_inject.h,v 1.6 2003/10/14 21:20:47 lordnaga Exp $ */

#ifndef EC_INJECT_H
#define EC_INJECT_H

#include <ec_packet.h>

#define FUNC_INJECTOR_PTR(func) int (*func)(struct packet_object *, size_t *)
#define FUNC_INJECTOR(func) int func(struct packet_object *po, size_t *len)

#define LENGTH *len
#define LENGTH_PTR len

#define SESSION_PASSTHRU(x,y) do{   \
   x->prev_session = y->session;    \
   y->session = x;                  \
} while(0)


#define EXECUTE_INJECTOR(x,y) do{                     \
   FUNC_INJECTOR_PTR(prev_injector);                  \
   prev_injector = get_injector(x, y);                \
   if (prev_injector == NULL)                         \
      return -ENOTFOUND;                              \
   if (prev_injector(PACKET, LENGTH_PTR) != ESUCCESS) \
      return -ENOTHANDLED;                            \
} while(0)

extern int inject_buffer(struct packet_object *po);
extern void add_injector(u_int8 level, u_int32 type, FUNC_INJECTOR_PTR(injector));
extern void * get_injector(u_int8 level, u_int32 type);
extern void inject_split_data(struct packet_object *po);

#define CHAIN_ENTRY 1
#define CHAIN_LINKED 2

/* Used to trace inject from udp to ip */
#define STATELESS_IP_MAGIC 0x0304e77e

#endif

/* EOF */

// vim:ts=3:expandtab

