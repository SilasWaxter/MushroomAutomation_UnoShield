#include "switch.h"

void initSwitch(switch_t* switch_obj)
{
  pinMode(switch_obj->pinNumber, INPUT);
  //attach
}

void readSwitch(switch_t* switch_obj)
{
  switch_obj->state = digitalRead(switch_obj->pinNumber);
}
