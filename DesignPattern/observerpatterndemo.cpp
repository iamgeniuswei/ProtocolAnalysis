#include "observerpatterndemo.h"


void ConcreteSubject::Attach(Observer *obj)
{
    observerList.append(obj);
}

void ConcreteSubject::Detach(Observer *obj)
{
    observerList.removeOne(obj);
}

void ConcreteSubject::Notify()
{
    for(int i =0; i<observerList.count(); i++)
        {
        Observer *obj = observerList.at(i);
        obj->Update(m_iState);
    }
}
