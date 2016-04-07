#include <QCoreApplication>
#include "simplefactorypatterndemo.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Factory *productFactory = new Factory();
    Product *pObjA = productFactory->createProduct(PRODUCTA);
    pObjA->show();

    Product *pObjB = productFactory->createProduct(PRODUCTB);
    pObjB->show();

    return a.exec();
}
