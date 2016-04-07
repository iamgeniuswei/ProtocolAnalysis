#ifndef OBSERVERPATTERNDEMO
#define OBSERVERPATTERNDEMO
#include <QDebug>
#include <QVector>
#include "designpattern_global.h"

class DESIGNPATTERNSHARED_EXPORT Observer
{
public:
    Observer() {}
    virtual void Update(int) = 0;
};

class DESIGNPATTERNSHARED_EXPORT Subject
{
public:
    Subject() {}
public:
    virtual void Attach(Observer*) = 0;
    virtual void Detach(Observer*) = 0;
    virtual void Notify() = 0;
};


class DESIGNPATTERNSHARED_EXPORT ConcreteObserver : public Observer
{
public:
    ConcreteObserver(Subject *pSubject)
        : m_subject(pSubject)
    {}
    void Update(int value)
    {
        qDebug() << "ConcreteObserver get the update. New State: " << value;
    }

private:
    Subject *m_subject;

};

class DESIGNPATTERNSHARED_EXPORT ConcreteObserverB :public Observer
{
public:
    ConcreteObserverB(Subject *pSubject)
        : m_subject(pSubject)
    {}
    void Update(int value)
    {
        qDebug() << "ConcreteObserverB get the update. New State: " << value;
    }
private:
    Subject *m_subject;
};

class DESIGNPATTERNSHARED_EXPORT ConcreteSubject : public Subject
{
public:
    ConcreteSubject() {}
    void Attach(Observer*);
    void Detach(Observer*);
    void Notify();
    void setState(int state)
    {
        m_iState = state;
    }

private:
    QVector<Observer*> observerList;
    int m_iState;
};

#endif // OBSERVERPATTERNDEMO

