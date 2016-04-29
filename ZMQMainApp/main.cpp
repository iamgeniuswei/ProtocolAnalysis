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

    int major, minor, patch;
    zmq_version(&major, &minor, &patch);
    std::cout << major << "." << minor << "." << patch << std::endl;

    void *context = zmq_ctx_new();
    void *publisher = zmq_socket(context, ZMQ_PUB);
    int rc = zmq_bind(publisher, "tcp://*:5556");
    std::cout << rc << "\n";
    while (1) {
        int zipcode, temperature, relhumidity;
        zipcode = 100000;
        temperature = 215;
        relhumidity = 50;

        char update[20] = {0};
        sprintf(update, "%05d %d %d", zipcode, temperature, relhumidity);
        zmq_send(publisher, update, 20, 0);
        sleep(3000);
    }

//    void *context = zmq_ctx_new();
//    std::cout <<context << std::endl;
//    void *socket = zmq_socket(context, ZMQ_REP);
//    std::cout << socket << std::endl;
//    int rc = zmq_bind(socket, "tcp://*:5555");
//    std::cout << rc << std::endl;
//    std::cout << errno << std::endl;

//    while (1) {
//        //wait for next request from client
//        static int count = 0;

//        zmq_msg_t request;
//        zmq_msg_init(&request);
//        zmq_msg_recv(&request, socket, 0);
//        std::cout << count++;
//        std::cout<<"Received Hello\n";
//        zmq_msg_close(&request);

//        sleep(1);

//        zmq_msg_t reply;
//        zmq_msg_init_size(&reply, 5);
//        memcpy(zmq_msg_data(&reply), "World", 5);
//        zmq_msg_send(&reply, socket, 0);
//        zmq_msg_close(&reply);
//    }

    zmq_close(publisher);
    zmq_ctx_destroy(context);

    return a.exec();
}
