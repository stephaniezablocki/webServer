
//This class implements a call to the connect() function of sockets as a definition of the connect_to_network virtual funciton from SimpleSocket.

#ifndef ConnectingSocket_hpp
#define ConnectingSocket_hpp

#include <stdio.h>
#include "SimpleSocket.hpp"

namespace SS
{
    class ConnectingSocket : public SimpleSocket
    {
    public:
        //Constructor
        ConnectingSocket(int domain, int service, int protocol, int port, u_long interface);
        //Virtual function from parent
        int connect_to_network(int sock, struct sockaddr_in address);
    };
}

#endif