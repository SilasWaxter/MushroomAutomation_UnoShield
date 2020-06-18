#include "DigitalTimerSwitch.h"

void initTimerSwitch(digTimerSwitch_t* digTimerSwitch_obj)
{
	disTimerSwitch(digTimerSwitch_obj);
}

bool isTimerSwitchSetReady(digTimerSwitch_t* digTimerSwitch_obj)            //returns whether switch is ready to flip state (On->Off or Off->On)
{
	if (digTimerSwitch_obj->currentStateEn)    //compare against enTime
  {
	  return (getTimerSwitchTimeSinceSet(digTimerSwitch_obj) - digTimerSwitch_obj->enTime) >= 0;
  }
  else                                          //compare against disTime
  {
	  return (getTimerSwitchTimeSinceSet(digTimerSwitch_obj) - digTimerSwitch_obj->disTime) >= 0;
  }
}

void disTimerSwitch(digTimerSwitch_t* digTimerSwitch_obj)
{
	digTimerSwitch_obj->lastSwitchTimestamp = millis();
	digTimerSwitch_obj->currentStateEn = false;
}

void enTimerSwitch(digTimerSwitch_t* digTimerSwitch_obj)
{
	digTimerSwitch_obj->lastSwitchTimestamp = millis();
	digTimerSwitch_obj->currentStateEn = true;
}

static inline long getTimerSwitchTimeSinceSet(digTimerSwitch_t* digTimerSwitch_obj)
{
	return (millis() - digTimerSwitch_obj->lastSwitchTimestamp);
}
