#include "hardwareDefinitions.h"
extern "C"
{
  #include "relay.h"
  #include "waterSwitch.h"
}

relay_t mister;
relay_t solenoid;
relay_t fan;

waterSwitch_t waterSwitch;

void setup()
{  
 mister.pinNumber = Mister_Relay_Pin; 
 initRelay(&mister);

 solenoid.pinNumber = Solenoid_Relay_Pin; 
 initRelay(&solenoid);

 fan.pinNumber = Fan_Relay_Pin; 
 initRelay(&fan);

 waterSwitch.pinNumber = WaterSwitch_Pin;
 initWaterSwitch(&waterSwitch);

 Serial.begin(115200);
}

void loop()
{
  
}
