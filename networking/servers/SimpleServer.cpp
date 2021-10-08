#include "SimpleServer.hpp"

SS::SimpleServer::SimpleServer(int domain, int service, int protocol, int port, u_long interface, int bklg)
{
    socket = new ListeningSocket(domain, service, protocol, port, interface, bklg);
}

SS::ListeningSocket *SS::SimpleServer::get_socket()
{
    return socket;
}