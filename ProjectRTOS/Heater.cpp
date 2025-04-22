#include "Heater.h"
#include <Arduino.h>

Heater::Heater(float *temperature, float *humidity) {
  this->temperature = temperature;
  this->humidity = humidity;
  safeRangeUpper=23.9;
  safeRangeLower=23.82;
  RiskOrangeUpper=23.95;
  RiskOrangeLower=23.8;
}
void Heater::Red34()  {
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
}
void Heater::Green34()  {
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
}
void Heater::Yellow34()   {
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
}

void Heater::Heater_run()  {
  if (*temperature>=safeRangeLower && *temperature<=safeRangeUpper)  {
    Green34();
  }
  //Orange range temp: 0 to 20  OR 35 to 40
  else if ((*temperature>=RiskOrangeLower && *temperature <=safeRangeLower) || (*temperature>=safeRangeUpper && *temperature<=RiskOrangeUpper))  {
    Yellow34();
  }
  else {
    Red34();
  }
}