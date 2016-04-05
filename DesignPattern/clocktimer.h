#ifndef CLOCKTIMER_H
#define CLOCKTIMER_H

#include "subject.h"
class ClockTimer : public Subject
{
public:
    ClockTimer();
    virtual int GetHour();
};

#endif // CLOCKTIMER_H
