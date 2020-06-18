#include "WaterLevelController.h"

void maintainWaterLevel(waterLevelController_t* waterLevelController_obj)
{
	if (isTimerSwitchSetReady(waterLevelController_obj->timerSwitch))
	{
		if (waterLevelController_obj->timerSwitch->currentStateEn)
		{
			disRelay(waterLevelController_obj->inflowSolenoid);
			disTimerSwitch(waterLevelController_obj->timerSwitch);
		}
		else
		{
			if (getSwitchState(waterLevelController_obj->heightSwitch))	//if waterLevelSwitch is low
			{
				enRelay(waterLevelController_obj->inflowSolenoid);
				enTimerSwitch(waterLevelController_obj->timerSwitch);
			}
		}
	}
}
