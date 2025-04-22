#include "LedBlink.h"
#include <Arduino.h>

LedBlink::LedBlink(int *LedStatus)   {
  this->LedStatus=LedStatus;
}

void LedBlink::blink()  {
  if (*LedStatus == 0)   {
    digitalWrite(48,HIGH);
    *LedStatus = 1;
  }
  else {
    digitalWrite(48,LOW);
    *LedStatus = 0;
  }
}