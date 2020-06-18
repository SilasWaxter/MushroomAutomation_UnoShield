#ifndef RELAY_H
#define RELAY_H

#include "Arduino.h"

typedef struct
{
  const int pinNumber;
  bool enabledState;    //on = true.  off = false.
} relay_t;

void initRelay(relay_t* relay_obj);
void enRelay(relay_t* relay_obj);
void disRelay(relay_t* relay_obj);

static void setRelay(relay_t* relay_obj);

#endif //RELAY_H
