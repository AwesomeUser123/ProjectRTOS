#ifndef COOLER_H
#define COOLER_H
class Cooler  {
  public:
    Cooler(float *temperature, float *humidity, float Threshold);
    void Green56();
    void Off56();
    void Cooler_run();
  private:
    float *temperature;
    float *humidity;
    float Threshold;
    int totalTimeCooled;
    bool NeedCool;
};
#endif