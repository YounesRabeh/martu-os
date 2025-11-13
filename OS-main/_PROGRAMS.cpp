#include "_PROGRAMS.h"


DigitalPin pins;
Communication com;

_PROGRAMS::_PROGRAMS(){
    
}

bool ledLed = 0;
void _fn1_(){
    pins.setPinState(2, ledLed);
    ledLed = !ledLed;
}

void _PROGRAMS::ledOn(){
    pins.setPinMode(2, 1);
    pins.setPinState(2, 1);
    Timer::customDelayMicroseconds(100000);
}

void _PROGRAMS::ledOff(){
    pins.setPinState(2, 0);
    Timer::customDelayMicroseconds(100000);
}

void _PROGRAMS::whiteLedOn(){
    pins.setPinMode(3, 1);
    pins.setPinState(3, 1);
}
void _PROGRAMS::whiteLedOff(){
    pins.setPinState(3, 0);
}

uint8_t index = 3;
void _fn2_(){
    //com.printChar('S');
    pins.setPinState(index++, 1);
}

uint8_t index2 = 5;
void _fn3_(){
    pins.setPinState(index2--, 0);
}


void _fn4_(){
    com.printChar('P');
}

void _PROGRAMS::ledLoading(){
    for (uint8_t i = 3; i < 8; i++){
        pins.setPinMode(i, 1);
        uint32_t a = (uint32_t) (i - 2); 
    }

    //_fn_();
    // This is just a demo sequence, you can modify the timing and order as needed.
    Scheduler::timedEvent(1000, _fn2_); //first led on
    Scheduler::timedEvent(10000, _fn3_); //3rd led off
    Scheduler::timedEvent(3000, _fn2_); //3nd led On 
    Scheduler::timedEvent(20000, _fn3_); //2nd led off
    Scheduler::timedEvent(2000, _fn2_); //2nd led On 
    Scheduler::timedEvent(5000, _fn3_); //first led off
    Scheduler::timedEvent(200, _fn4_); // print 'P'
    Scheduler::timedEvent(5000, _fn2_); //5nd led On 
    Scheduler::timedEvent(4000, _fn2_); //4nd led On 
    Scheduler::timedEvent(50, _fn4_);
}
