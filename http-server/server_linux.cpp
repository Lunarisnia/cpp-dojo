#include <iostream>
#include "http_tcpServer_linux.h"

int main() {
    http::TcpServer *server = new http::TcpServer();
    std::cout << "Hello, World" << std::endl;

    return 0;
}

// Continue https://osasazamegbe.medium.com/showing-building-an-http-server-from-scratch-in-c-2da7c0db6cb7

// g++ -c ./main.cpp -o ./bin/main.o
// g++ -c ./calculator.cpp -o ./bin/calculator.o
// g++ ./bin/main.o ./bin/calculator.o -o ./bin/program