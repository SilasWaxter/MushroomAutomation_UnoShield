#include "definitionsMushAutoUnoShield.h"
#include "servoSwitch.h"
#include "DHT.h"
extern "C"
{
  #include "relay.h"
  #include "switch.h"
}

//Hardware Objects
relay_t mister {RELAY_MISTER_PIN};
relay_t inflowSolenoid {RELAY_INFLOWSOLENOID_PIN};
relay_t fan {RELAY_FAN_PIN};

switch_t waterSwitch {SWITCH_WATERHEIGHT_PIN};

servoSwitch_t airFlapServo {SERVO_AIRFLAP_PIN, SERVO_AIRFLAP_OPENPOS, SERVO_AIRFLAP_CLOSEPOS};

DHT dht1(DHT1_PIN, 11);
DHT dht2(DHT2_PIN, 11);
DHT dht3(DHT3_PIN, 11);
DHT dht4(DHT4_PIN, 11);

void setup()
{  
 Serial.begin(115200);
  /*
 initRelay(&mister);

 initRelay(&solenoid);

 initRelay(&fan);
 
 initFloatSwitch(&floatSwitch);

 initAirFlap(&airFlap);

 dht1.begin();
 dht2.begin();
 dht3.begin();
 dht4.begin();
 */
 
}

void loop()
{
  /*
  float h1, h2, h3, h4;
  h1 = dht1.readHumidity();
  h2 = dht2.readHumidity();
  h3 = dht3.readHumidity();
  h4 = dht4.readHumidity();

  Serial.println(String(h1) + ", " + String(h2) + ", " +  String(h3) + ", " +  String(h4));
  delay(1000);
  */
}
