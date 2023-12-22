#ifndef HTTP_TCPSERVER_LINUX
#define HTTP_TCPSERVER_LINUX
#include <string>

namespace http
{
    class TcpServer
    {
    public:
        TcpServer(std::string ip_address, int port);  // Constructor
        ~TcpServer(); // Destructor (Called when class is destroyed)

        int startServer();
    private:
        sockaddr_in m_socketAddress;
        in_addr m_addr;

        std::string m_ip_address;
        int m_port;
        int m_socket;
    };
}

#endif