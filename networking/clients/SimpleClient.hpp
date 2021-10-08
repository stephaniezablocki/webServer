#ifndef SimpleClient_hpp
#define SimpleClient_hpp

#include <stdio.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "../sslibc-networking.hpp"

namespace SS
{
    class SimpleClient
    {
    private:
        ConnectingSocket *socket;
        virtual void requester();
        virtual void handler();

    public:
        SimpleClient(int domain, int service, int protocol, int port, char *interface);
        virtual void launch() = 0;
        ConnectingSocket *get_socket();
    };
}

#endif