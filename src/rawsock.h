/*
    raw sockets stuff
*/
#ifndef RAWSOCK_H
#define RAWSOCK_H
struct Adapter;
struct TcpPacket;

/**
 * @return
 *      1 on failure
 *      0 on success
 */
int rawsock_selftest();

void rawsock_init();

struct Adapter *rawsock_init_adapter(const char *adapter_name);

void rawsock_list_adapters();

void
rawsock_send_probe(
    struct Adapter *adapter,
    unsigned ip, unsigned port,
    struct TcpPacket *pkt);

unsigned rawsock_get_adapter_ip(const char *ifname);
int rawsock_get_adapter_mac(const char *ifname, unsigned char *mac);

int rawsock_get_default_gateway(const char *ifname, unsigned *ipv4);

const char *rawsock_win_name(const char *ifname);

int rawsock_is_adapter_names_equal(const char *lhs, const char *rhs);

#endif
