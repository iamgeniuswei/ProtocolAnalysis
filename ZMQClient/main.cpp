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
    std::cout << "Connecting to hello server" <<std::endl;

    void *socket = zmq_socket(context, ZMQ_REQ);
    std::cout << socket << std::endl;
    int rc = zmq_connect(socket, "tcp://192.168.1.117:5555");
    std::cout << rc << std::endl;


    int request_nbr;
    for(request_nbr = 0; request_nbr != 100; request_nbr++)
    {
        zmq_msg_t request;
        zmq_msg_init_size(&request, 5);
        memcpy(zmq_msg_data(&request), "Hello", 5);
        std::cout << "Sending Hello %d...\n" << request_nbr;
        int rc = zmq_msg_send(&request, socket, 0);
        std::cout << rc << std::endl;
        zmq_close(&request);

        zmq_msg_t reply;
        zmq_msg_init(&reply);
        zmq_msg_recv(&reply, socket, 0);
        std::cout << "Received World %d\n" << request_nbr;
        zmq_msg_close(&reply);
    }

    sleep (2);
    zmq_close (socket);
    zmq_ctx_destroy (context);

    return a.exec();
}
