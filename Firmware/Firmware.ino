#include "hardwareDefinitions.h"
#include "airFlap.h"
#include "DHT.h"
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

DHT dht1(DHT1_Pin, 11);
DHT dht2(DHT2_Pin, 11);
DHT dht3(DHT3_Pin, 11);
DHT dht4(DHT4_Pin, 11);

void setup()
{  
 initRelay(&mister);

 initRelay(&solenoid);

 initRelay(&fan);
 
 initWaterSwitch(&waterSwitch);

 initAirFlap(&airFlap);

 dht1.begin();
 dht2.begin();
 dht3.begin();
 dht4.begin();
 
 Serial.begin(115200);
}

void loop()
{
  float h1, h2, h3, h4;
  h1 = dht1.readHumidity();
  h2 = dht2.readHumidity();
  h3 = dht3.readHumidity();
  h4 = dht4.readHumidity();

  Serial.println(String(h1) + ", " + String(h2) + ", " +  String(h3) + ", " +  String(h4));
  delay(1000);
}
