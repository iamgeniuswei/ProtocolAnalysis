#include "subject.h"
#include "observer.h"
Subject::~Subject()
{

}

void Subject::Attach(Observer *o)
{
    _observers.append(o);
}

void Subject::Detach(Observer *o)
{
    _observers.removeAll(o);
}

void Subject::Notify()
{
    for(int i=0; i<_observers.size(); i++)
        {
        Observer* currentItem = _observers.at(i);
        currentItem->Update(this);
    }
}

Subject::Subject()
{

}

