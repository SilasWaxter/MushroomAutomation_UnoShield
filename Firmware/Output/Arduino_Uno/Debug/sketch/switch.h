#ifndef SWITCH_H
#define SWITCH_H

#include "Arduino.h"

typedef struct
{
  const int pinNumber;
  bool state;    //on = true.  off = false.
} switch_t;

void initSwitch(switch_t* switch_obj);
bool getSwitchState(switch_t* switch_obj);

#endif //SWITCH_H
