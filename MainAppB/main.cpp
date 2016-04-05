#include <QCoreApplication>
#include "msgsender.h"
#include <iostream>
#include <QDebug>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MsgSender *msgSender = new MsgSender;

//        while(std::cin.get())
//            {
//            msgSender->sendMsg();
//        }
//    for(int i=0; i<10; i++)
//        {
//        msgSender->sendMsg();
//    }

    return a.exec();
}
