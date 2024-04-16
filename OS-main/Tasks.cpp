#include "Tasks.h"


Task::Task(Program_PTR _program_, bool ___isRepeatable){
    this->_program_ = _program_;
    this->__isDone = 0;
    this->__isRepeatable = ___isRepeatable;
}

