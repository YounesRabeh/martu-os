#ifndef TaskManager_h
#define TaskManager_h

#include <stdint.h>
#include "Queue.h"
#include "Tasks.h"

/** 
 * @brief Class to manage and schedule tasks
 * Handles the execution and management of tasks in a priority queue.
 */
class TaskManager{ 
public:
    Queue<Task*> tasksPriorityPtrQueue;
    TaskManager();
    void run();
    
private:
    void kill();
};
#endif