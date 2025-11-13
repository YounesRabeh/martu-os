#ifndef Memory_h
#define Memory_h

#include <avr/pgmspace.h>
#include "Queue.h"

typedef void (*Function_PTR)();


/**
 * @brief Class to handle Flash Memory operations
*/  
class FlashMemory{
public:
    /**
     * @brief Constructor for FlashMemory class
     */
    FlashMemory();
    /**
     * @brief Store a function pointer in flash memory
     * @param function The function pointer to store
     */
    void storeInFlash(Function_PTR function);
private:

};
#endif