#ifndef HEATER_H
#define HEATER_H

class Heater {
public:
    Heater(float *temparature, float *humidity); // Constructor

    void Red34();
    void Yellow34();
    void Green34();
    void Heater_run();


private:
    float *temperature;
    float *humidity;
    float safeRangeUpper;
    float safeRangeLower;
    float RiskOrangeUpper;
    float RiskOrangeLower;
    float RiskRedUpper;
    float RiskRedLower;
};

#endif
