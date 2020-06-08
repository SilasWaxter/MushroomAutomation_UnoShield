#ifndef WaterSwitch_H
#define WaterSwitch_H

#include "Arduino.h"

typedef struct
{
  int pinNumber;
  bool enabledState;    //on = true.  off = false.
} waterSwitch_t;

void initWaterSwitch(waterSwitch_t* waterSwitch_obj);
void readWaterSwitch(waterSwitch_t* waterSwitch_obj);

#endif //WaterSwitch_H
