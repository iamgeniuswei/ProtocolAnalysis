#ifndef SUBJECT_H
#define SUBJECT_H
#include <QVector>
class Observer;
class Subject
{
public:
    virtual ~Subject();
    virtual void Attach(Observer*);
    virtual void Detach(Observer*);
    virtual void Notify();
protected:
    Subject();
private:
    QVector<Observer*> _observers;
};

#endif // SUBJECT_H
