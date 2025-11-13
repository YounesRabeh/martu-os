#ifndef Timer_h
#define Timer_h

#include <avr/io.h>
#include <avr/interrupt.h> 
#include <stdint.h>


/**
 * @brief Class to handle system timing operations
 * Provides methods for delays and retrieving system time.
 */
class Timer{  
public:
    Timer();
    static void customDelayMicroseconds(unsigned long us);
    uint32_t getTimeMilliSeconds();
    uint32_t getTimeSeconds();
    static uint32_t systemTime; 
    
private:

};
#endif

