#include <QCoreApplication>
#include "simplefactorypatterndemo.h"
#include "observerpatterndemo.h"
#include <QDebug>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

//    //Simple Factory pattern demo
//    Factory *productFactory = new Factory();
//    Product *pObjA = productFactory->createProduct(PRODUCTA);
//    pObjA->show();

//    Product *pObjB = productFactory->createProduct(PRODUCTB);
//    pObjB->show();

    //Observer pattern demo
    ConcreteSubject *pSubject = new ConcreteSubject;
    Observer *ob1 = new ConcreteObserver(pSubject);
    Observer *ob2 = new ConcreteObserverB(pSubject);

    pSubject->setState(3);
    pSubject->Attach(ob1);
    pSubject->Attach(ob2);
    pSubject->Notify();


    qDebug() <<"--------------------------";
    pSubject->setState(5);
//    pSubject->Attach(ob1);
//    pSubject->Attach(ob2);
    pSubject->Notify();


    qDebug() <<"--------------------------";
    pSubject->Detach(ob1);
    pSubject->Notify();



    return a.exec();
}
