#ifndef LEDBLINK_H
#define LEDBLINK_H
class LedBlink  {
  public:
    LedBlink(int *LedStatus);
    void blink();
  private:
    int *LedStatus;
};
#endif