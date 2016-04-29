#ifndef ANIMAL_H
#define ANIMAL_H
#include <QDebug>

class Animal
{
public:
    Animal();

    virtual void jump(){
        qDebug() << "aminmal jump";
    }
};

class Rabbit : public Animal
{
public:
    Rabbit() {}
    virtual void jump()
    {
        qDebug() << "rabbit jump";
    }
};

#endif // ANIMAL_H
