#include "HumidityController.h"

void getHumidity(humidityController_t* humidityController_obj, bool enDebug)
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

void maintainHumidity(humidityController_t* humidityController_obj, float tgtHumidity)
{
	if (isTimerSwitchSetReady(humidityController_obj->timerSwitch_Mister))
	{
		if (humidityController_obj->timerSwitch_Mister->currentStateEn)
		{
			disRelay(humidityController_obj->mister);
			disRelay(humidityController_obj->fan);
			disTimerSwitch(humidityController_obj->timerSwitch_Mister);
		}
		else
		{
			if (humidityController_obj->averageHumidity < tgtHumidity)
			{
				enRelay(humidityController_obj->mister);
				enRelay(humidityController_obj->fan);
				enTimerSwitch(humidityController_obj->timerSwitch_Mister);
			}
		}
	}
}