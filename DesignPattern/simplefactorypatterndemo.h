#ifndef SIMPLEFACTORYPATTERNDEMO
#define SIMPLEFACTORYPATTERNDEMO
#include "designpattern_global.h"
typedef enum ProductTypeTag{
    PRODUCTA,
    PRODUCTB
}PRODUCTTYPE;


class DESIGNPATTERNSHARED_EXPORT Product
{
public:
    Product(){}
    ~Product();

public:
    virtual void show() = 0;
};

class ProductA : public Product
{
public:
    ProductA() {}

    void show();
};

class ProductB : public Product
{
public:
    ProductB() {}
    void show();
};

class DESIGNPATTERNSHARED_EXPORT Factory
{
public:
    Factory() {}
    Product* createProduct(PRODUCTTYPE type);
};


#endif // SIMPLEFACTORYPATTERNDEMO

