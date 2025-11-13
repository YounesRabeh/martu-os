#include "TaskManager.h"


TaskManager::TaskManager(){

}


void TaskManager::run() {
    if (!tasksPriorityPtrQueue.isEmpty()) {
        Task* nextTask = tasksPriorityPtrQueue.peek();
        if (nextTask != nullptr) {
            // Call the function pointer if it points to a function
            (*(nextTask->_program_))();
            if (nextTask->__isRepeatable) {
                // Re-enqueue the task for repetition
                tasksPriorityPtrQueue.enqueue(nextTask);
            }
            nextTask->__isDone = true;
        }
        tasksPriorityPtrQueue.dequeue();
    }
}

void TaskManager::kill(){
    tasksPriorityPtrQueue.dequeue();
}
