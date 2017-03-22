#ifndef input_h
#define input_h

class inputClass
{
  public:
  inputClass();
  void SETUP();
  int currentSpeed();
  volatile unsigned long ulStartPeriod;
  volatile boolean bNewThrottleSignal;
  volatile int nThrottleIn_ISR;
  int prevThrottle;
  int currThrottle;
};

extern inputClass Signal;

#endif
