#ifndef WebpageServer_hpp
#define WebpageServer_hpp

#include <stdio.h>
#include <fstream>
#include "SimpleServer.hpp"

namespace SS
{
    class WebpageServer : public SimpleServer
    {
    private:
        char buffer[30000] = {0};
        int new_socket;
        void accepter();
        void handler();
        void responder();

    public:
        WebpageServer();
        void launch();
    };
}

#endif