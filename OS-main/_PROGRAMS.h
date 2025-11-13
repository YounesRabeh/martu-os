#ifndef _PROGRAMS_h
#define _PROGRAMS_h

#include "Pins.h"
#include "Communication.h"
#include "Scheduler.h"
#include "Timer.h"


/**
 * @brief Class containing various program functions for the OS
 */
class _PROGRAMS {
public:
    /**
     * @brief Instance of DigitalPin for pin operations
     */
    DigitalPin pins;
    /**
     * @brief Instance of Communication for serial operations
     */
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