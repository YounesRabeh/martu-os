#include "Scheduler.h"

LookupTable Scheduler::timedEventsTable;



Scheduler::Scheduler(){

}

void Scheduler::timedEvent(uint32_t time, Program_PTR event) {
   Scheduler::timedEventsTable.addEntry(time, event);
}



void Scheduler::exe(Function_PTR func){
    func();
   Scheduler::timedEventsTable.removeEntry();

}



