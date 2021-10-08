
//This class implements a call to the bind() function of sockets as a definition of the connect_to_network virtual funciton from SimpleSocket.

#ifndef BindingSocket_hpp
#define BindingSocket_hpp

#include <stdio.h>
#include "SimpleSocket.hpp"

namespace SS
{
    class BindingSocket : public SimpleSocket
    {
    private:
        int binding;
        void connect_to_network(int sock, struct sockaddr_in address);

    public:
        //Constructor
        BindingSocket(int domain, int service, int protocol, int port, in_addr_t interface);
        //Virtual function from parent
        int get_binding();
    };
}

#endif