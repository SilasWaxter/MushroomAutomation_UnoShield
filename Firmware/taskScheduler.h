#ifndef TASKSCHEDULER_H
#define TASKSCHEDULER_H

#include "Arduino.h"

typedef struct
{
  void* taskPointer;                //function of task
  long minRepeatTime;               //sets the minimum time between repetition of task
  long lastExecTime;                //timestamp of last execution of task
} task_t;


void execTaskIfReady(task_t* task_obj);
long getTimeToAllowedExec(task_t* task_obj);    //gets the minimum time till repitition of task

static inline void __execTask(void* task());
bool __isAllowedExec(task_t* task_obj);           //returns whether task is ready

#endif //TASKSCHEDULER_H
