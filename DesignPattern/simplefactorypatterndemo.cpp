#include "simplefactorypatterndemo.h"
#include <QDebug>


void ProductA::show()
{
    qDebug() <<"I'm Product A";
}


void ProductB::show()
{
    qDebug() << "I'm Product B";
}


Product::~Product()
{

}


Product *Factory::createProduct(PRODUCTTYPE type)
{
    switch (type) {
    case PRODUCTA:
        return new ProductA();
        break;
    case PRODUCTB:
        return new ProductB();
        break;
    default:
        return nullptr;
        break;
    }
}
