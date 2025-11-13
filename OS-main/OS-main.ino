#include "_PROGRAMS.h"
// Create global instances
_PROGRAMS _pr;
Timer sysTimer; 
TaskManager ts;
Communication sysCom;


int main(){
  ///////////////////////////////////////////////////////////////////////////////////////
  // Define tasks for the scheduler
  Task ledOn([]() { _pr.ledOn(); }, true);                                            
  Task ledOff([]() { _pr.ledOff(); }, true);                                         
  Task ledLoading([]() { _pr.ledLoading(); }, false);                                                       
                                                                                    
  // Enqueue the task pointer                                                        
  ts.tasksPriorityPtrQueue.enqueue(&ledOn);                                          
  ts.tasksPriorityPtrQueue.enqueue(&ledOff);                                         
  ts.tasksPriorityPtrQueue.enqueue(&ledLoading);                                       
  ///////////////////////////////////////////////////////////////////////////////////////
  
  // Start the scheduler                         
  while(!ts.tasksPriorityPtrQueue.isEmpty()){ ts.run();}
  while(1){asm volatile("");}

  return 0;
}

// Timer2 Compare Match Interrupt Service Routine
ISR(TIMER2_COMPA_vect){
  sysTimer.systemTime++; 
  if (!Scheduler::timedEventsTable.isEmpty()){
    Function_PTR func = Scheduler::timedEventsTable.getValue();
    uint32_t time = Scheduler::timedEventsTable.getKey();
    if (sysTimer.systemTime >= time){
      Scheduler::exe(func); 
    }
  }  
}