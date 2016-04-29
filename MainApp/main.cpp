#include <QCoreApplication>
#include "msgserver.h"
#include <iostream>
#include <QDebug>
#include <QThread>
#include "qplogsender.h"
#include <QFuture>
#include <QtConcurrent>
#include "stack.h"
#include "animal.h"
#include "testobject.h"
#include "testobject2.h"
#include "testobject3.h"
#include <QVariant>
#include <QPointer>

#define gLoger QPLogSender::getInstance()
bool doSomething()
{
    for(int i=0; i< 10; i++)
    {
        gLoger->sendMsg(QString::number(i));
        qDebug() << QThread::currentThread();

    }
    return true;
}

template<class T> void swapT(T &t1, T &t2)
{
    T tempT;
    tempT = t1;
    t1 = t2;
    t2 = tempT;
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //Test QPointer




//    qDebug() << sizeof(QObject);

//    TestObject obj;
//    obj.setObjectName("TestObjectName");
//    qDebug() << obj.objectName();
//    qDebug() << obj.metaObject()->className();
//    qDebug() << obj.inherits("QObject");
//    qDebug() << obj.inherits("QWidget");

//    const QMetaObject *meta = obj.metaObject();
//    qDebug() << meta->className() <<meta->CreateInstance;

    qDebug() << "-------------------------------------------------";

//    TestObject3 obj3;
//    const QMetaObject *meta3 = obj3.metaObject();
//    qDebug() << meta3->className();

//    QObject::connect(&obj, &TestObject::emitSignal, &obj3, &TestObject3::receiveSignal);

//    obj.emitS();


//    const QMetaObject *metaobject = obj3.metaObject();
//    int count = metaobject->propertyCount();
//    for (int i=0; i<count; ++i) {
//        QMetaProperty metaproperty = metaobject->property(i);
//        const char *name = metaproperty.name();
//        QVariant value = obj3.property(name);
//        qDebug() << name <<value;
//    }

//    Animal *ani = new Animal;
//    ani->jump();
//    Rabbit *rab = new Rabbit;
//    rab->jump();
//    Animal *rab2 = new Rabbit;
//    rab2->jump();
//    Animal *rab3 = dynamic_cast<Rabbit*>(rab);
//    rab3->jump();

//    qDebug() << typeid(rab2).name();

//    double num1 = 1.6;
//    double num2 = 3;
//    swapT<double>(num1,num2);
//    qDebug() << num1 << num2;


//    Stack<int> intStack;
//    intStack.push(1);
//    intStack.push(2);
//    intStack.push(3);

//    while(!intStack.isEmpty())
//        std::cout << intStack.pop() << std::endl;;

//    Stack<double> doubleStack;
//    doubleStack.push(5.03);
//    doubleStack.push(7.00);
//    doubleStack.push(3.02);

//    while(!doubleStack.isEmpty())
//        std::cout << doubleStack.pop() << std::endl;
//    doSomething();
//    QPLogSender *log;
//    QThread worker;
//    log->moveToThread(&worker);
//    worker.start();

//    /*QFuture<bool> future1 = */QtConcurrent::run(QThreadPool::globalInstance(),doSomething());
//    /*QFuture<bool> future2 = */QtConcurrent::run(QThreadPool::globalInstance(),doSomething());
//    qDebug() << future1.result();
//    qDebug() << future2.result();


//    MsgServer *msgServer = new MsgServer;

//    while(std::cin.get())
//        {
//        qDebug() << "exit";
//    }

    return a.exec();
}
