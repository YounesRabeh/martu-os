#ifndef _PROGRAMS_h
#define _PROGRAMS_h

#include "Pins.h"
#include "Communication.h"
#include "Scheduler.h"
#include "Timer.h"


class _PROGRAMS {
public:
    DigitalPin pins;
    Communication com;
    //Timer timer;
    _PROGRAMS();
    void ledOn();
    void ledOff();
    void whiteLedOn();
    void whiteLedOff();
    void ledLoading();

};



#endif