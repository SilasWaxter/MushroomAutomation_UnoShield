#include "hardwareDefinitions.h"
#include "airFlap.h"
extern "C"
{
  #include "relay.h"
  #include "waterSwitch.h"
}

relay_t mister {Mister_Relay_Pin};
relay_t solenoid {Solenoid_Relay_Pin};
relay_t fan {Fan_Relay_Pin};

waterSwitch_t waterSwitch {WaterSwitch_Pin};

airFlap_t airFlap {AirFlapServo_Pin, AirFlapServo_OpenPosition, AirFlapServo_ClosedPosition};

void setup()
{  
 initRelay(&mister);

 initRelay(&solenoid);

 initRelay(&fan);
 
 initWaterSwitch(&waterSwitch);

 initAirFlap(&airFlap);
 
 Serial.begin(115200);
}

void loop()
{
  enAirFlap(&airFlap);
  delay(1500);
  disAirFlap(&airFlap);
  delay(1500);
}
