#include "Cooler.h"
#include <Arduino.h>

Cooler::Cooler(float *temperature, float *humidity, float Threshold)   {
  this->temperature = temperature;
  this->humidity = humidity;
  totalTimeCooled = 0;
  this->Threshold = Threshold;
  NeedCool = false;
}

void Cooler::Green56()  {
  digitalWrite(8,HIGH);
  digitalWrite(9,LOW);
}
void Cooler::Off56()  {
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
}

void Cooler::Cooler_run()   {
  if (*temperature >= Threshold && !NeedCool)  {
    NeedCool = true;
  }
  if (totalTimeCooled >= 5)   {
    totalTimeCooled = 0;
    if (*temperature < Threshold)   {
      NeedCool = false;
    }
  }
  if (NeedCool)   {
    Green56();
    totalTimeCooled++;
  }
  else  {
    Off56();
  }
}