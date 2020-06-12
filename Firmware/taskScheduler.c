#include "taskScheduler.h"

static inline void execTask(task_t* task_obj, void* task())    //callback function.  points to task
{
  (*task)();
  task_obj->lastExecTime = millis();
}

inline bool isAllowedExec(task_t* task_obj)            //returns whether task is ready
{
  return (millis() - task_obj->lastExecTime) >= task_obj->minRepeatTime;
}

long getTimeToAllowedExec(task_t* task_obj)    //gets the minimum time till repitition of task
{
  return task_obj->minRepeatTime - (millis() - task_obj->lastExecTime);
}
