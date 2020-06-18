#ifndef AIRFLOWCONTROLLER_H
#define AIRFLOWCONTROLLER_H

#include "Arduino.h"
#include "servoSwitch.h"

extern "C"
{
#include "DigitalTimerSwitch.h"
#include "relay.h"
}


typedef struct
{
	//abstractions
	bool flowEnabled;
	digTimerSwitch_t* timerSwitch;
	
	//hardware
	relay_t* inflowFan;
	servoSwitch_t* airFlapServo;
} airFlowController_t;

void updateAirFlow(airFlowController_t* airFlowController_obj);

static void setAirFlow(airFlowController_t* airFlowController_obj, bool tgtState);

#endif // !AIRFLOWCONTROLLER_H