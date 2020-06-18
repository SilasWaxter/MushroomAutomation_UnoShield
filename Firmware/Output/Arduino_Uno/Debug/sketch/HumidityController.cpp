#include "HumidityController.h"

void updateHumidity(humidityController_t* humidityController_obj, bool enDebug)
{	
	int sumHumidity = 0;
	
	for (int i = 0; i < 4; i++)
	{
		humidityController_obj->sensorHumidity[i] = humidityController_obj->dht[i]->readHumidity();				//Read sensor
		sumHumidity += humidityController_obj->sensorHumidity[i];
	}
	
	humidityController_obj->averageHumidity = (sumHumidity / 4);	
	
	if (enDebug)
	{
		for (int i = 0; i < 4; i++)
		{
			Serial.print(String(humidityController_obj->sensorHumidity[i]) + ", ");
		}
		Serial.println("Average: " + String(humidityController_obj->averageHumidity) + "\n");
	}
}