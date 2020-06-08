#include "hardwareDefinitions.h"
extern "C"
{
  #include "relay.h"
  #include "waterSwitch.h"
}

relay_t mister {Mister_Relay_Pin};
relay_t solenoid {Solenoid_Relay_Pin};
relay_t fan {Fan_Relay_Pin};

waterSwitch_t waterSwitch {WaterSwitch_Pin};

void setup()
{  
 initRelay(&mister);

 initRelay(&solenoid);

 initRelay(&fan);
 
 initWaterSwitch(&waterSwitch);

 Serial.begin(115200);
}

void loop()
{
  
}
