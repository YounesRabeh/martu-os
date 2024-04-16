#ifndef TaskManager_h
#define TaskManager_h

#include <stdint.h>
#include "Queue.h"
#include "Tasks.h"

class TaskManager{ 
public:
    Queue<Task*> tasksPriorityPtrQueue;
    TaskManager();
    void run();
    void pause();
    
private:
    void kill();

};


#endif