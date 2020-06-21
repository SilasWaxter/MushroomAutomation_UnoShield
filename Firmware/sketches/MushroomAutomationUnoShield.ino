#include "definitionsMushAutoUnoShield.h"
#include "servoSwitch.h"
#include "DHT.h"
#include "AirFlowController.h"
#include "HumidityController.h"
extern "C"
{
#include "relay.h"
#include "switch.h"
#include "DigitalTimerSwitch.h"  
#include "WaterLevelController.h"
}

#define DEBUG_MODE true
#define TARGET_HUMIDITY 100

//Humidity Object
#define ENTIME_TIMERSWITCH_MISTER 5000
#define DISTIME_TIMERSWITCH_MISTER 0
digTimerSwitch_t timerSwitch_Mister {ENTIME_TIMERSWITCH_MISTER, DISTIME_TIMERSWITCH_MISTER}
;
humidityController_t humidityController;

//AirFlow Object
#define ENTIME_TIMERSWITCH_AIRFLOW 30000		//time in mins
#define DISTIME_TIMERSWITCH_AIRFLOW 120000		//time in mins
digTimerSwitch_t timerSwitch_AirFlow {ENTIME_TIMERSWITCH_AIRFLOW, DISTIME_TIMERSWITCH_AIRFLOW};

airFlowController_t airFlowController;


//Waterlevel Object
waterLevelController_t waterLevelController;

#define ENTIME_TIMERSWITCH_WATERLEVEL 3000
#define DISTIME_TIMERSWITCH_WATERLEVEL 0
digTimerSwitch_t timerSwitch_WaterLevel {ENTIME_TIMERSWITCH_WATERLEVEL, DISTIME_TIMERSWITCH_WATERLEVEL};


//Hardware Objects
relay_t mister {RELAY_MISTER_PIN};
relay_t inflowSolenoid {RELAY_INFLOWSOLENOID_PIN};
relay_t fan {RELAY_FAN_PIN};

switch_t waterHeightSwitch {SWITCH_WATERHEIGHT_PIN};

servoSwitch_t airFlapServo {SERVO_AIRFLAP_PIN, SERVO_AIRFLAP_OPENPOS, SERVO_AIRFLAP_CLOSEPOS};

DHT dht1(DHT1_PIN, 11);
DHT dht2(DHT2_PIN, 11);
DHT dht3(DHT3_PIN, 11);
DHT dht4(DHT4_PIN, 11);

void setup()
{ 
#pragma region Initilization Code
	Serial.begin(115200);
	
	//HARDWARE
	initRelay(&mister);
	initRelay(&inflowSolenoid);
	initRelay(&fan);
	initSwitch(&waterHeightSwitch);
	initServoSwitch(&airFlapServo);
	dht1.begin();
	dht2.begin();
	dht3.begin();
	dht4.begin();
  
	//ABSTRACTIONS
	//AirFlow
	initTimerSwitch(&timerSwitch_AirFlow);
	airFlowController.timerSwitch = &timerSwitch_AirFlow;
	airFlowController.airFlapServo = &airFlapServo;
	
	//WaterLevel
	initTimerSwitch(&timerSwitch_WaterLevel);
	waterLevelController.timerSwitch = &timerSwitch_WaterLevel;
	waterLevelController.heightSwitch = &waterHeightSwitch;
	waterLevelController.inflowSolenoid = &inflowSolenoid;
	
	//Humidity
	initTimerSwitch(&timerSwitch_Mister);
	humidityController.timerSwitch_Mister = &timerSwitch_Mister;
	humidityController.dht[0] = &dht1;
	humidityController.dht[1] = &dht2;
	humidityController.dht[2] = &dht3;
	humidityController.dht[3] = &dht4;
	humidityController.mister = &mister;		  
#pragma endregion

#pragma region Application Code
	//Fan is always on
	enRelay(&fan);
	
#pragma endregion	
}

void loop()
{
	//updateAirFlow(&airFlowController);
	
	maintainWaterLevel(&waterLevelController);
	
	getHumidity(&humidityController, DEBUG_MODE);
	
	maintainHumidity(&humidityController, TARGET_HUMIDITY);
}
