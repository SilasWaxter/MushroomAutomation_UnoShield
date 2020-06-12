#ifndef TASKSCHEDULER_H
#define TASKSCHEDULER_H

#include "Arduino.h"

typedef struct
{
  void* taskPointer;                //function of task
  long minRepeatTime;               //sets the minimum time between repetition of task
  long lastExecTime;                //timestamp of last execution of task
} task_t;

static inline void execTask(task_t* task_obj, void* task());
bool isAllowedExec(task_t* task_obj);           //returns whether task is ready
long getTimeToAllowedExec(task_t* task_obj);    //gets the minimum time till repitition of task

#endif //TASKSCHEDULER_H
