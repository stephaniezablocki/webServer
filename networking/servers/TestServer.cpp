#include "TestServer.hpp"

SS::TestServer::TestServer() : SimpleServer(AF_INET, SOCK_STREAM, 0, 8080, INADDR_ANY, 10)
{
    launch();
}
void SS::TestServer::accepter()
{
    struct sockaddr_in address = get_socket()->get_address();
    int addrlen = sizeof(address);
    new_socket = accept(get_socket()->get_sock(), (struct sockaddr *)&address, (socklen_t *)&addrlen);
    read(new_socket, buffer, 30000);
}
void SS::TestServer::handler()
{
    std::cout << buffer << std::endl;
}
void SS::TestServer::responder()
{
    std::ifstream html_file;
    html_file.open("./webpages/index.html");

    std::string html_text;

    std::string line;
    if (html_file.is_open())
    {
        while (getline(html_file, line))
        {
            html_text.append(line + "\n");
        }
    }
    html_file.close();

    int content_size = html_text.length();

    std::string http_string = std::string("HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: ") + std::to_string(content_size) + "\n\n" + html_text;
    char *http_chars = new char[content_size + 1];
    strcpy(http_chars, http_string.c_str());
    char *hello = http_chars;

    write(new_socket, hello, strlen(hello));
    close(new_socket);
}
void SS::TestServer::launch()
{
    while (true)
    {
        std::cout << "======== WAITING ========" << std::endl;
        accepter();
        handler();
        responder();
        std::cout << "===== DONE =====" << std::endl;
    }
}