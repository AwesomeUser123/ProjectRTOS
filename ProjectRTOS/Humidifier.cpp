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
  switch (HumidTimeCount) {
      case 0:
        if (*humidity<=HumidThreshold)   {
           Green78();
           HumidTimeCount++;
        }
        else  {
           Off78();
        }
        break;
      case 1:
      case 2:
      case 3:
      case 4:
        Green78();
        HumidTimeCount++;
        break;
      case 5:
      case 6:
      case 7:
        Yellow78();
        HumidTimeCount++;
        break;
      case 8:
      case 9:
        Red78();
        HumidTimeCount++;
        break;
      default:
        HumidTimeCount=0;
        Off78();
  }
}
