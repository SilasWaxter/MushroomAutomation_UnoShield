#include "AirFlowController.h"

void updateAirFlow(airFlowController_t* airFlowController_obj)
{
	if (isTimerSwitchSetReady(airFlowController_obj->timerSwitch))
	{
		if (airFlowController_obj->timerSwitch->currentStateEn)
		{
			setAirFlow(airFlowController_obj, false);
			disTimerSwitch(airFlowController_obj->timerSwitch);
		}
		else
		{
			setAirFlow(airFlowController_obj, true);
			enTimerSwitch(airFlowController_obj->timerSwitch);
		}
	}
}

static void setAirFlow(airFlowController_t* airFlowController_obj, bool tgtState)
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