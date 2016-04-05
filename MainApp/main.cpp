#include <QCoreApplication>
#include "msgserver.h"
#include <iostream>
#include <QDebug>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MsgServer *msgServer = new MsgServer;

    while(std::cin.get())
        {
        qDebug() << "exit";
    }

    return a.exec();
}
