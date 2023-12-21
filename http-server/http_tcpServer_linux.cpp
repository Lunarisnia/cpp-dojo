#include "http_tcpServer_linux.h"

#include <iostream>
#include "sys/socket.h"
#include "arpa/inet.h"
#include <unistd.h>
#include <string>

namespace log
{
    // We set the parameter as it's reference because we don't want to spend more memory than what we need
    // All we do is print this so just take the existing memory
    // We make it safer by setting this to constant
    void println(const std::string &message)
    {
        std::cout << message << std::endl;
    }

    void printAndExitWithError(const std::string &message)
    {
        std::cout << message << std::endl;
        exit(1);
    }
}
// TODO: Continue, keep this in mind https://chat.openai.com/c/907ea441-7576-4acd-85ca-ccbfd2cbdc8b
namespace http
{
    TcpServer::TcpServer()
    {
        std::cout << "TcpServer Created" << std::endl;
    }

    TcpServer::~TcpServer()
    {
        close(m_socket);
    }

    int TcpServer::startServer()
    {
        m_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (m_socket < 0)
        {
            log::printAndExitWithError("error creating socket");
        }
        return 0;
    }
}