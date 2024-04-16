#include "Timer.h"

uint32_t Timer::systemTime = 0;



Timer::Timer(){
// Set up Timer2 to generate a 1ms interrupt
    TCCR2A = 0;  // Timer2 control register A - set all bits to 0
    TCCR2B = 0;  // Timer2 control register B - set all bits to 0
    OCR2A = 128;  // Set compare match register to generate 1ms intervals for 
    TCCR2A |= (1 << WGM21);  // Timer Mode: CTC mode (Clear Timer on Compare Match)
    //TCCR2B |= (1 << CS22) | (1 << CS21) | (1 << CS20); //prescaler 1024
    TCCR2B = (1 << CS22) | (1 << CS20); // Prescaler 128
    TIMSK2 |= (1 << OCIE2A);  // Enable Timer2 interrupt
    sei();
    // Disable Timer2 interrupt [TIMSK2 &= ~(1 << OCIE2A);]
}

void Timer::customDelayMicroseconds(unsigned long us) {
  while (us--) {
    asm volatile ("nop"); // Execute a no-operation (one clock cycle delay)
  }
}

uint32_t Timer::getTimeMilliSeconds(){
    return Timer::systemTime;
}

uint32_t Timer::getTimeSeconds(){
    return Timer::systemTime / 1000;
}



