#include "ConnectingSocket.hpp"

//Constructor
SS::ConnectingSocket::ConnectingSocket(int domain, int service, int protocol, int port, in_addr_t interface) : SimpleSocket(domain, service, protocol, port, interface)
{
    connect_to_network(get_sock(), get_address());
    test_connection(connection);
}

//Definition of connect_to_network virtual function
void SS::ConnectingSocket::connect_to_network(int sock, struct sockaddr_in address)
{
    connection = connect(sock, (struct sockaddr *)&address, sizeof(address));
}