#ifndef HUMIDITYCONTROLLER_H
#define HUMIDITYCONTROLLER_H

#include "Arduino.h"
#include "DHT.h"

extern "C"
{
#include "relay.h"
#include "DigitalTimerSwitch.h"
}

typedef struct
{
	digTimerSwitch_t* timerSwitch_Mister;
	
	float sensorHumidity[4] {0, 0, 0, 0};
	float averageHumidity {0};

	//Hardware
	DHT* dht[4];
	relay_t* mister;	
} humidityController_t;

void getHumidity(humidityController_t* humidityController_obj, bool enDebug);

void maintainHumidity(humidityController_t* humidityController_obj, float tgtHumidity);

#endif //HUMIDITYCONTROLLER_H