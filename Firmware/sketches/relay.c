#include "relay.h"

void initRelay(relay_t* relay_obj)
{
	//Setup
	pinMode(relay_obj->pinNumber, OUTPUT);

	//Set intial state
	disRelay(relay_obj);
}

void enRelay(relay_t* relay_obj)			//return if already set
{
	if (relay_obj->enabledState)
	{
		return;
	}
	relay_obj->enabledState = true;
	setRelay(relay_obj);
}

void disRelay(relay_t* relay_obj)
{
	if (!relay_obj->enabledState)			//return if already set
	{
		return;
	}
	relay_obj->enabledState = false;
	setRelay(relay_obj);
}

static void setRelay(relay_t* relay_obj)
{
	if (relay_obj->enabledState)
	{
		digitalWrite(relay_obj->pinNumber, HIGH);
	}
	else
	{
		digitalWrite(relay_obj->pinNumber, LOW);
	}
}
