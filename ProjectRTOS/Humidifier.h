#ifndef HUMIDIFIER_H
#define HUMIDIFIER_H

class Humidifier  {
  public:
    Humidifier(float *temperature, float *humidity, float HumidThreshold);
    void Red78();
    void Yellow78();
    void Green78();
    void Off78();
    void Humidifier_run();
  private:
    int HumidTimeCount;
    float HumidThreshold;
    float *temperature;
    float *humidity; 
};

#endif