#include <Arduino.h>
#include "Input.h"
#include "Output.h"
#include "Config.h"

void setup() {
  // put your setup code here, to run once:
  attachInterrupt(digitalPinToInterrupt(THROTTLE_SIGNAL_IN_PIN), ISRcalcInput, CHANGE);
  Signal.SETUP();
  Audio.SETUP();
}

void loop() {
  // put your main code here, to run repeatedly:
  Signal.currentSpeed();
  Audio.playAudio();
}

void ISRcalcInput()
{
  // if the pin is high, its the start of an interrupt
  if (digitalRead(THROTTLE_SIGNAL_IN_PIN) == HIGH)
  {
    // get the time using micros - when our code gets really busy this will become inaccurate, but for the current application its
    // easy to understand and works very well
    Signal.ulStartPeriod = micros();
  }
  else
  {
    // if the pin is low, its the falling edge of the pulse so now we can calculate the pulse duration by subtracting the
    // start time ulStartPeriod from the current time returned by micros()
    if (Signal.ulStartPeriod && (Signal.bNewThrottleSignal == false))
    {
      Signal.nThrottleIn_ISR = (int)(micros() - Signal.ulStartPeriod);
      Signal.ulStartPeriod = 0;

      // tell loop we have a new signal on the throttle channel
      // we will not update nThrottleIn until loop sets
      // bNewThrottleSignal back to false
      Signal.bNewThrottleSignal = true;
    }
  }
}
