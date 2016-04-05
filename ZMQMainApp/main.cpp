#include <QCoreApplication>
#include <zmq.h>
#include <string>
#include <iostream>
#ifndef _WIN32
#include <unistd.h>
#else
#include <Windows.h>
#define sleep(n) Sleep(n)
#endif
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    void *context = zmq_ctx_new();
    std::cout <<context << std::endl;
    void *socket = zmq_socket(context, ZMQ_REP);
    std::cout << socket << std::endl;
    int rc = zmq_bind(socket, "tcp://127.0.0.1:5555");
    std::cout << rc << std::endl;





    return a.exec();
}
