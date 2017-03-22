#include <Arduino.h>
#include "Config.h"
#include "Input.h"

#ifdef DEBUG
  #include <SoftwareSerial.h>
#endif

volatile unsigned long ulStartPeriod = 0; // set in the interrupt
volatile boolean bNewThrottleSignal = false; // set in the interrupt and read in the loop
volatile int nThrottleIn_ISR = NEUTRAL_THROTTLE; // volatile, we set this in the Interrupt and read it in loop so it must be declared volatile

int nThrottleIn = 0; // store the throttle in main
int prevThrottle = 0; // previous throttle
int currThrottle = 0; // current throttle

inputClass::inputClass(){
}

void inputClass::SETUP(){
  // tell the Arduino we want the function calcInput to be called whenever INT0 (digital pin 2) changes from HIGH to LOW or LOW to HIGH
  // catching these changes will allow us to calculate how long the input pulse is
  #ifdef DEBUG
    Serial.begin(9600);
    Serial.println("Debugging active");
  #endif
}


int inputClass::currentSpeed(){
  if (bNewThrottleSignal)
  {
    //Stop interrupts while we update current Throttle value
    noInterrupts();
    nThrottleIn = nThrottleIn_ISR;
    interrupts();
    
    bNewThrottleSignal = false;
  }

  #ifdef AUTO_SPEEDS
    currThrottle = ((float)NUMBER_OF_SPEEDS+1)/(2000-980)*(nThrottleIn-980);
  #endif
  #ifdef DEBUG
    if (prevThrottle != currThrottle){
      Serial.println(currThrottle);
    }
  #endif

  if (prevThrottle != currThrottle){
      prevThrottle = currThrottle;
    }
    return currThrottle;
}

inputClass Signal = inputClass();
