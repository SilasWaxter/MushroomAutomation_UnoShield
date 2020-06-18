#ifndef DIGITALTIMERSWITCH_H
#define DIGITALTIMERSWITCH_H

#include "Arduino.h"

typedef struct
{ 
  const long enTime;
  const long disTime;
  long lastSwitchTimestamp;
  bool currentStateEn;          //true if current state is enabled
} digTimerSwitch_t;

void initTimerSwitch(digTimerSwitch_t* digTimerSwitch_obj);
bool isTimerSwitchSetReady(digTimerSwitch_t* digTimerSwitch_obj);           //returns whether switch is ready to flip state (On->Off or Off->On)
void disTimerSwitch(digTimerSwitch_t* digTimerSwitch_obj);
void enTimerSwitch(digTimerSwitch_t* digTimerSwitch_obj);

static inline long getTimerSwitchTimeSinceSet(digTimerSwitch_t* digTimerSwitch_obj);

#endif //DIGITALTIMERSWITCH_H
