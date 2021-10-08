#ifndef TestClient_hpp
#define TestClient_hpp

#include <stdio.h>
#include "SimpleClient.hpp"

namespace SS
{
    class TestClient : public SimpleClient
    {
    private:
        int sock;
        char buffer[1024] = {0};
        void requester();
        void handler();

    public:
        TestClient();
        void launch();
    };
}

#endif