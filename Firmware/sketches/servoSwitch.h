/*  Manages two-state servos (open and closed)
*/
#ifndef SERVOSWITCH_H
#define SERVOSWITCH_H

#include "Arduino.h"
#include <Servo.h>

typedef struct
{
  const int pinNumber;
  const int openPos;
  const int closePos;
  Servo servo;
  bool openState;    //on = true.  off = false.
} servoSwitch_t;

void initServoSwitch(servoSwitch_t* servoSwitch_obj);
void openServoSwitch(servoSwitch_t* servoSwitch_obj);
void closeServoSwitch(servoSwitch_t* servoSwitch_obj);

static void setAirFlap(servoSwitch_t* servoSwitch_obj);    //open or close

#endif //SERVOSWITCH_H
