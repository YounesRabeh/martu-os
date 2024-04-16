#include "Memory.h"


FlashMemory::FlashMemory() {
    // Constructor implementation (if needed)
}

void FlashMemory::storeInFlash(Function_PTR function) {
    Function_PTR func;
    memcpy_P(&func, &function, sizeof(Function_PTR));
    
}

