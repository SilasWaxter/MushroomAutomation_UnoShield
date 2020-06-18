#ifndef WATERLEVELCONTROLLER_H
#define WATERLEVELCONTROLLER_H

#include "Arduino.h"
#include "DigitalTimerSwitch.h"
#include "relay.h"
#include "switch.h"

typedef struct 
{
	//Abstract
	digTimerSwitch_t* timerSwitch;
	
	//Hardware
	relay_t* inflowSolenoid;
	switch_t* heightSwitch;
} waterLevelController_t;

void maintainWaterLevel(waterLevelController_t* waterLevelController_obj);

#endif //WATERLEVELCONTROLLER_H