#include <Arduino.h>
#include "Humidifier.h"

Humidifier::Humidifier(float *temperature, float *humidity, float HumidThreshold)  {
  this->temperature = temperature;
  this->humidity = humidity;
  this->HumidThreshold = HumidThreshold;
  HumidTimeCount=0;
}

void Humidifier::Red78()  {
  digitalWrite(10,HIGH);
  digitalWrite(17,HIGH);
}
void Humidifier::Yellow78()   {
  digitalWrite(10,LOW);
  digitalWrite(17,HIGH);
}
void Humidifier::Green78()  {
  digitalWrite(10,HIGH);
  digitalWrite(17,LOW);
}

void Humidifier::Off78()  {
  digitalWrite(10,LOW);
  digitalWrite(17,LOW);
}

void Humidifier::Humidifier_run()   {
  if (HumidTimeCount == 0)  {
    if (*humidity<=HumidThreshold)   {
      Green78();
      HumidTimeCount++;
    }
    else  {
      Off78();
    }
  }
  else {
    if (HumidTimeCount <= 4)  {
      Green78();
      HumidTimeCount++;
    }
    else if (HumidTimeCount <= 7)    {
      Yellow78();
      HumidTimeCount++;
    }
    else if (HumidTimeCount <=9)  {
      Red78();
      HumidTimeCount++;
    }
    else  {
      HumidTimeCount=0;
      Off78();
    }
  }
}