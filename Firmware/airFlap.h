#ifndef AIRFLAP_H
#define AIRFLAP_H

#include "Arduino.h"
#include <Servo.h>

typedef struct
{
  Servo airFlapServo;
  
  int pinNumber;
  bool openState;    //on = true.  off = false.
} airFlap_t;

void initAirFlap(airFlap_t* airFlap_obj);
void enAirFlap(airFlap_t* airFlap_obj);      //open air flap
void disAirFlap(airFlap_t* airFlap_obj);     //close air flap

static void setAirFlap(airFlap_t* airFlap_obj);    //open or close air flap

#endif //AIRFLAP_H
