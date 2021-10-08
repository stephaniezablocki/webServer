#include "TestClient.hpp"

SS::TestClient::TestClient() : SimpleClient(AF_INET, SOCK_STREAM, 0, 8080, "127.0.0.1")
{
    launch();
}

void SS::TestClient::requester()
{
    char *hello = "Hello from client";
    send(get_socket()->get_sock(), hello, strlen(hello), 0);
}

void SS::TestClient::handler()
{
    read(new_socket, buffer, 1024);
    std::cout << buffer << std::endl;
}

void SS::TestClient::launch()
{
    std::cout << "=======SENDING========" << std::endl;
    requester();
    std::cout << "=======SENT========" << std::endl;

    handler();
    std::cout << "=======RECEIVED========" << std::endl;
}