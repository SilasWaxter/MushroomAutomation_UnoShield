#include <Arduino.h>
#line 1 "W:\\MushroomAutomation\\Firmware\\sketches\\MushroomAutomationUnoShield.ino"
#line 1 "W:\\MushroomAutomation\\Firmware\\sketches\\MushroomAutomationUnoShield.ino"
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

//Humidity Object
humidityController_t humidityController;

//AirFlow Object
#define ENTIME_TIMERSWITCH_AIRFLOW 5000
#define DISTIME_TIMERSWITCH_AIRFLOW 5000
digTimerSwitch_t timerSwitch_AirFlow {ENTIME_TIMERSWITCH_AIRFLOW, DISTIME_TIMERSWITCH_AIRFLOW};

airFlowController_t airFlowController;


//Waterlevel Object
waterLevelController_t waterLevelController;

#define ENTIME_TIMERSWITCH_WATERLEVEL 1000
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

#line 49 "W:\\MushroomAutomation\\Firmware\\sketches\\MushroomAutomationUnoShield.ino"
void setup();
#line 85 "W:\\MushroomAutomation\\Firmware\\sketches\\MushroomAutomationUnoShield.ino"
void loop();
#line 49 "W:\\MushroomAutomation\\Firmware\\sketches\\MushroomAutomationUnoShield.ino"
void setup()
{ 
	Serial.begin(115200);
	
	//Init Hardware	
	initRelay(&mister);
	initRelay(&inflowSolenoid);
	initRelay(&fan);
	initSwitch(&waterHeightSwitch);
	initServoSwitch(&airFlapServo);
	dht1.begin();
	dht2.begin();
	dht3.begin();
	dht4.begin();
  
	//Init Abstractions
	//AirFlow
	initTimerSwitch(&timerSwitch_AirFlow);
	airFlowController.airFlapServo = &airFlapServo;
	airFlowController.inflowFan = &fan;
	airFlowController.timerSwitch = &timerSwitch_AirFlow;
	
	//WaterLevel
	initTimerSwitch(&timerSwitch_WaterLevel);
	waterLevelController.heightSwitch = &waterHeightSwitch;
	waterLevelController.inflowSolenoid = &inflowSolenoid;
	waterLevelController.timerSwitch = &timerSwitch_WaterLevel;
	
	//Humidity
	humidityController.dht[0] = &dht1;
	humidityController.dht[1] = &dht2;
	humidityController.dht[2] = &dht3;
	humidityController.dht[3] = &dht4;
	humidityController.mister = &mister;
}

void loop()
{
	//updateAirFlow(&airFlowController);
	
	//maintainWaterLevel(&waterLevelController);
	
	updateHumidity(&humidityController, DEBUG_MODE);
	
}

