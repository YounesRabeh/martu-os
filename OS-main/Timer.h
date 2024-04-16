#ifndef Timer_h
#define Timer_h

#include <avr/io.h>
#include <avr/interrupt.h> 
#include <stdint.h>

class Timer{  
public:
    Timer();
    static void customDelayMicroseconds(unsigned long us);
    uint32_t getTimeMilliSeconds();
    uint32_t getTimeSeconds();
    static uint32_t systemTime; 
    
private:
   // the time of the system 
};



#endif

