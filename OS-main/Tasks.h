#ifndef Tasks_h
#define Tasks_h

#include <stdint.h>

// Function pointer type definition for program task
typedef void (*Program_PTR)();

// Base class for a Task
class Task {
public:
    uint8_t priority;
    Program_PTR _program_;
    bool __isDone;
    bool __isRepeatable;
    Task(Program_PTR _program_, bool ___isRepeatable);
    
private:
    
};


#endif