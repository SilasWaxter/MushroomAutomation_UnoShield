#include "airFlap.h"

void initAirFlap(airFlap_t* airFlap_obj)
{
  //Setup
  airFlap_obj->airFlapServo.attach(airFlap_obj->pinNumber);
  
  //Set intial state
  disAirFlap(airFlap_obj);
}

void enAirFlap(airFlap_t* airFlap_obj)       //open air flap
{
  airFlap_obj->openState = true;
  setAirFlap(airFlap_obj);
}

void disAirFlap(airFlap_t* airFlap_obj)      //close air flap
{
  airFlap_obj->openState = false;
  setAirFlap(airFlap_obj);
}

static void setAirFlap(airFlap_t* airFlap_obj)     //open or close air flap
{
  if(airFlap_obj->openState)
  {
    //airFlap_obj->airFlapServo.write(
  }
  else
  {
    
  }
}
