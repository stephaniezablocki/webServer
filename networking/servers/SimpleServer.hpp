#ifndef SimpleServer_hpp
#define SimpleServer_hpp

#include <stdio.h>
#include <unistd.h>
#include "../sslibc-networking.hpp"

namespace SS
{
    class SimpleServer
    {
    private:
        ListeningSocket *socket;
        virtual void accepter() = 0;
        virtual void handler() = 0;
        virtual void responder() = 0;

    public:
        SimpleServer(int domain, int service, int protocol, int port, u_long interface, int bklg);
        virtual void launch() = 0;
        ListeningSocket *get_socket();
    };
}

#endif