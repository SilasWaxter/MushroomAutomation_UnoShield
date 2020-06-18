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
	float sensorHumidity[4] {0, 0, 0, 0};
	float averageHumidity {0};

	//Hardware
	DHT* dht[4];
	relay_t* mister;	
} humidityController_t;

void updateHumidity(humidityController_t* humidityController_obj, bool enDebug);

#endif //HUMIDITYCONTROLLER_H