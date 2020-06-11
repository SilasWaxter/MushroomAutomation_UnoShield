#include "taskScheduler.h"

void execTaskIfReady(task_t* task_obj)
{
  if(__isAllowedExec(task_obj))
  {
    __execTask(task_obj->taskPointer);
    task_obj->lastExecTime = millis();
  }
}

long getTimeToAllowedExec(task_t* task_obj)    //gets the minimum time till repitition of task
{
  return task_obj->minRepeatTime - (millis() - task_obj->lastExecTime);
}

static inline void __execTask(void* task())    //callback function.  points to task
{
  (*task)();
}

inline bool __isAllowedExec(task_t* task_obj)            //returns whether task is ready
{
  return (millis() - task_obj->lastExecTime) >= task_obj->minRepeatTime;
}
