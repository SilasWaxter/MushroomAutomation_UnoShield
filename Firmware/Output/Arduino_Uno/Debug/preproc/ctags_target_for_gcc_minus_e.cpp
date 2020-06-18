# 1 "W:\\MushroomAutomation\\Firmware\\sketches\\MushroomAutomationUnoShield.ino"
# 1 "W:\\MushroomAutomation\\Firmware\\sketches\\MushroomAutomationUnoShield.ino"
# 2 "W:\\MushroomAutomation\\Firmware\\sketches\\MushroomAutomationUnoShield.ino" 2
# 3 "W:\\MushroomAutomation\\Firmware\\sketches\\MushroomAutomationUnoShield.ino" 2
# 4 "W:\\MushroomAutomation\\Firmware\\sketches\\MushroomAutomationUnoShield.ino" 2
# 5 "W:\\MushroomAutomation\\Firmware\\sketches\\MushroomAutomationUnoShield.ino" 2
# 6 "W:\\MushroomAutomation\\Firmware\\sketches\\MushroomAutomationUnoShield.ino" 2
extern "C"
{

# 10 "W:\\MushroomAutomation\\Firmware\\sketches\\MushroomAutomationUnoShield.ino" 2

# 12 "W:\\MushroomAutomation\\Firmware\\sketches\\MushroomAutomationUnoShield.ino" 2
}




//Humidity Object


digTimerSwitch_t timerSwitch_Mister {5000, 0}
;
humidityController_t humidityController;

//AirFlow Object


digTimerSwitch_t timerSwitch_AirFlow {60000 /*time in mins*/, 90000 /*time in mins*/};

airFlowController_t airFlowController;


//Waterlevel Object
waterLevelController_t waterLevelController;



digTimerSwitch_t timerSwitch_WaterLevel {15000, 0};


//Hardware Objects
relay_t mister {2};
relay_t inflowSolenoid {3};
relay_t fan {4 /*400 Litres of Air/Min		|	Container is 56.7812 litres*/};

switch_t waterHeightSwitch {13 /*PCB definition*/};

servoSwitch_t airFlapServo {11, 160, 30};

DHT dht1(A0, 11);
DHT dht2(A1, 11);
DHT dht3(A2, 11);
DHT dht4(A3, 11);

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
 airFlowController.timerSwitch = &timerSwitch_AirFlow;
 airFlowController.airFlapServo = &airFlapServo;
 airFlowController.inflowFan = &fan;

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
}

void loop()
{
 updateAirFlow(&airFlowController);

 maintainWaterLevel(&waterLevelController);

 getHumidity(&humidityController, true);

 maintainHumidity(&humidityController, 100);
}
