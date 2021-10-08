#include "SimpleClient.hpp"

SS::SimpleClient::SimpleClient(int domain, int service, int protocol, int port, char *interface)
{
    in_addr_t addr = inet_addr("127.0.0.1");
    socket = new ConnectingSocket(domain, service, protocol, port, addr);
}
SS::ConnectingSocket *SS::SimpleClient::get_socket()
{
    return socket;
}