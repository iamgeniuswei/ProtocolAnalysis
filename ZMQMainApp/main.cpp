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
    int rc = zmq_bind(socket, "tcp://*:5555");
    std::cout << rc << std::endl;

    while (1) {
        //wait for next request from client
        static int count = 0;

        zmq_msg_t request;
        zmq_msg_init(&request);
        zmq_msg_recv(&request, socket, 0);
        std::cout << count++;
        std::cout<<"Received Hello\n";
        zmq_msg_close(&request);

        sleep(1);

        zmq_msg_t reply;
        zmq_msg_init_size(&reply, 5);
        memcpy(zmq_msg_data(&reply), "World", 5);
        zmq_msg_send(&reply, socket, 0);
        zmq_msg_close(&reply);
    }

    zmq_close(socket);
    zmq_ctx_destroy(context);

    return a.exec();
}
