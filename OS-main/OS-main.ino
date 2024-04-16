  #include "_PROGRAMS.h"

  _PROGRAMS _pr;
  Timer sysTimer; 
  TaskManager ts;
  Communication sysCom;


  int main(){
    ///////////////////////////////////////////////////////////////////////////////////////
    Task ledOn([]() { _pr.ledOn(); }, true);                                            
    Task ledOff([]() { _pr.ledOff(); }, true);                                         
    Task ledLoading([]() { _pr.ledLoading(); }, false);                                                       
                                                                                      
    // Enqueue the task pointer                                                        
    ts.tasksPriorityPtrQueue.enqueue(&ledOn);                                          
    ts.tasksPriorityPtrQueue.enqueue(&ledOff);                                         
    ts.tasksPriorityPtrQueue.enqueue(&ledLoading);                                       
    ///////////////////////////////////////////////////////////////////////////////////////
    
                              
    while(!ts.tasksPriorityPtrQueue.isEmpty()){ ts.run();}
    sysCom.printChar('D');
    sysCom.printChar('\n');

    while(1){asm volatile("");}

    return 0;
  }

  ISR(TIMER2_COMPA_vect){
    sysTimer.systemTime++; // Increment the millisecond counter
    if (!Scheduler::timedEventsTable.isEmpty()){
      Function_PTR func = Scheduler::timedEventsTable.getValue();
      uint32_t time = Scheduler::timedEventsTable.getKey();
      if (sysTimer.systemTime >= time){
        Scheduler::exe(func); 
      }
    }  
  }




