#ifndef HTTP_TCPSERVER_LINUX
#define HTTP_TCPSERVER_LINUX

namespace http
{
    class TcpServer
    {
    public:
        TcpServer();  // Constructor
        ~TcpServer(); // Destructor (Called when class is destroyed)

        int startServer();
    private:
        int m_socket;
    };
}

#endif