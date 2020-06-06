#include "HardwareDefinitions.h"

#include <dht.h>
#include <Servo.h>
#include <string.h>

#define minTimeForToggleHumidifierSys 45000   //1.5 mins between toggling humidifier system (WaterSolenoid + Mister)

Servo AirLockServo;

bool WaterSwitch_State = false;           //true = water not high enough   |  false = water high enough

bool WaterLevelReadyForMister = false;    //Abstracted water level
unsigned long TimestampAtLastExe = 0;

char CommandBuffer[50] = {0};

void setup() {
  //Init Serial
  Serial.begin(115200);
  Serial.println("Serial Com. Attached");

  //Init Output Pins
  pinMode(Mister_Relay_Pin, OUTPUT);
  pinMode(WaterSolenoid_Relay_Pin, OUTPUT);
  pinMode(Fan_Relay_Pin, OUTPUT);
  //pinMode(Heater_Relay_Pin, OUTPUT);

  //Init Input Pins
  pinMode(WaterSwitch_Pin, INPUT);
  pinMode(DHT1_Pin, INPUT);
  pinMode(DHT2_Pin, INPUT);
  pinMode(DHT3_Pin, INPUT);
  pinMode(DHT4_Pin, INPUT);

  AirLockServo.attach(AirLockServo_Pin);
}

void loop() {
  readWaterLevel();

  if((millis() - TimestampAtLastExe) > minTimeForToggleHumidifierSys)
  {
    TimestampAtLastExe = millis();
    if(WaterLevelReadyForMister)
    {
      disWaterSolenoid();
      enMister();
    }
    else
    {
      enWaterSolenoid();
      disMister(); 
    }
  }

  
  //Check for Serial Commands
  if(Serial.available())
  {
    delay(75);                          //wait for buffer to fill

    char CommandBuffer[50] = {0};       //clear memory
    int i = 0;
    while(Serial.available())
    {
      CommandBuffer[i] = Serial.read();
      i++;
    }
    Serial.println("\t-->" + String(CommandBuffer));  //echo command

    if(strstr(CommandBuffer,"enMister") != NULL)
    {
      enMister();
    }
    if(strstr(CommandBuffer,"disMister") != NULL)
    {
      disMister();
    }
    
    if(strstr(CommandBuffer,"enWaterSolenoid") != NULL)
    {
      enWaterSolenoid();
    }
    if(strstr(CommandBuffer,"disWaterSolenoid") != NULL)
    {
      disWaterSolenoid();
    }

    if(strstr(CommandBuffer,"printWaterLevel") != NULL)
    {
      readWaterLevel();
      Serial.println("WaterSwitch_State: " + String(WaterSwitch_State));
      Serial.println("WaterLevelReadyForMister: " + String(WaterLevelReadyForMister));
    }

    if(strstr(CommandBuffer,"printTimeToToggleHSys") != NULL)
    {
      Serial.println("TimeToToggleHumiditySystem: " + String(minTimeForToggleHumidifierSys - (millis() - TimestampAtLastExe)));
    }
  }
}

void enMister()
{
  digitalWrite(Mister_Relay_Pin, HIGH);
}

void disMister()
{
  digitalWrite(Mister_Relay_Pin, LOW);
}

void enWaterSolenoid()
{
  digitalWrite(WaterSolenoid_Relay_Pin, HIGH);
}

void disWaterSolenoid()
{
  digitalWrite(WaterSolenoid_Relay_Pin, LOW);
}

void readWaterLevel()
{
  WaterSwitch_State = digitalRead(WaterSwitch_Pin);
  WaterLevelReadyForMister = !WaterSwitch_State;      //Abstracted water level = opposite state of switch
}
