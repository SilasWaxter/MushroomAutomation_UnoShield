# 1 "W:\\MushroomAutomation\\Firmware\\sketches\\MushroomAutomationUnoShield.ino"
# 1 "W:\\MushroomAutomation\\Firmware\\sketches\\MushroomAutomationUnoShield.ino"
# 2 "W:\\MushroomAutomation\\Firmware\\sketches\\MushroomAutomationUnoShield.ino" 2
# 3 "W:\\MushroomAutomation\\Firmware\\sketches\\MushroomAutomationUnoShield.ino" 2
# 4 "W:\\MushroomAutomation\\Firmware\\sketches\\MushroomAutomationUnoShield.ino" 2
# 5 "W:\\MushroomAutomation\\Firmware\\sketches\\MushroomAutomationUnoShield.ino" 2
extern "C"
{

# 9 "W:\\MushroomAutomation\\Firmware\\sketches\\MushroomAutomationUnoShield.ino" 2

# 11 "W:\\MushroomAutomation\\Firmware\\sketches\\MushroomAutomationUnoShield.ino" 2
}

//AirFlow Object


digTimerSwitch_t timerSwitch_AirFlow {5000, 1000};

airFlowController_t airFlowController;

//Waterlevel Object
waterLevelController_t waterLevelController;



digTimerSwitch_t timerSwitch_WaterLevel {1000, 0};

//Hardware Objects
relay_t mister {2};
relay_t inflowSolenoid {3};
relay_t fan {4};

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

 //Init Abstractions
 initTimerSwitch(&timerSwitch_WaterLevel);
 waterLevelController.heightSwitch = &waterHeightSwitch;
 waterLevelController.inflowSolenoid = &inflowSolenoid;
 waterLevelController.timerSwitch = &timerSwitch_WaterLevel;

 initTimerSwitch(&timerSwitch_AirFlow);
 airFlowController.airFlapServo = &airFlapServo;
 airFlowController.inflowFan = &fan;
 airFlowController.timerSwitch = &timerSwitch_AirFlow;

//	dht1.begin();
//	dht2.begin();
//	dht3.begin();
//	dht4.begin();
}

void loop()
{
 //maintainWaterLevel(&waterLevelController);

 //updateAirFlow(&airFlowController);




//	float h1, h2, h3, h4;
//	h1 = dht1.readHumidity();
//	h2 = dht2.readHumidity();
//	h3 = dht3.readHumidity();
//	h4 = dht4.readHumidity();
//  
//	Serial.println(String(h1) + ", " + String(h2) + ", " +  String(h3) + ", " +  String(h4));
//	delay(1000);
}
