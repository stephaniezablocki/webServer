#include "BindingSocket.hpp"

//Constructor
SS::BindingSocket::BindingSocket(int domain, int service, int protocol, int port, in_addr_t interface) : SimpleSocket(domain, service, protocol, port, interface)
{
    connect_to_network(get_sock(), get_address());
    test_connection(binding);
}

//Definition of connect_to_network virtual function
void SS::BindingSocket::connect_to_network(int sock, struct sockaddr_in address)
{
    binding = bind(sock, (struct sockaddr *)&address, sizeof(address));
}

int SS::BindingSocket::get_binding()
{
    return binding;
}