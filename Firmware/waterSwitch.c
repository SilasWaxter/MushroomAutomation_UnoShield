#include "waterSwitch.h"

void initWaterSwitch(waterSwitch_t* waterSwitch_obj)
{
  pinMode(waterSwitch_obj->pinNumber, INPUT);
}

void readWaterSwitch(waterSwitch_t* waterSwitch_obj)
{
  waterSwitch_obj->enabledState = digitalRead(waterSwitch_obj->pinNumber);
}
