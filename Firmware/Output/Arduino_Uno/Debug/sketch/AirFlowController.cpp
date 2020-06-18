#include "AirFlowController.h"

void setAirFlow(airFlowController_t* airFlowController_obj, bool tgtState)
{
	if (tgtState)		//if call is to enable
	{
		openServoSwitch(airFlowController_obj->airFlapServo);
		enRelay(airFlowController_obj->inflowFan);
	}
	else
	{
		closeServoSwitch(airFlowController_obj->airFlapServo);
		disRelay(airFlowController_obj->inflowFan);
	}
}