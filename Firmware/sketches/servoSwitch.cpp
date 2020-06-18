#include "servoSwitch.h"

void initServoSwitch(servoSwitch_t* servoSwitch_obj)
{
  //Setup
  servoSwitch_obj->servo.attach(servoSwitch_obj->pinNumber);
  
  //Set intial state
  closeServoSwitch(servoSwitch_obj);
}

void openServoSwitch(servoSwitch_t* servoSwitch_obj)
{
  servoSwitch_obj->openState = true;
  setAirFlap(servoSwitch_obj);
}

void closeServoSwitch(servoSwitch_t* servoSwitch_obj)
{
  servoSwitch_obj->openState = false;
  setAirFlap(servoSwitch_obj);
}

static void setAirFlap(servoSwitch_t* servoSwitch_obj)
{
  if(servoSwitch_obj->openState)
  {
    servoSwitch_obj->servo.write(servoSwitch_obj->openPos);
  }
  else
  {
    servoSwitch_obj->servo.write(servoSwitch_obj->closePos);
  }
}
