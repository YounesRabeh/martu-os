#ifndef Memory_h
#define Memory_h

#include <avr/pgmspace.h>
#include "Queue.h"

typedef void (*Function_PTR)();


    
class FlashMemory{
public:
    FlashMemory();
    void storeInFlash(Function_PTR function);




private:



};








#endif