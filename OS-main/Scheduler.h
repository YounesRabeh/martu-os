#ifndef Scheduler_h
#define Scheduler_h

#include "TaskManager.h"
#include "LookupTable.h"
#include "Memory.h"
#include "Timer.h"


class Scheduler{
public:
    Scheduler();
    static LookupTable timedEventsTable;
    static void timedEvent(uint32_t time, Program_PTR event);
    static void exe(Function_PTR func);

private:


};




#endif