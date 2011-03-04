/* LedFactory.h
   Josh Kasten 
   1-23-11 
   Controls brightness of LED's with anyone of the 14 digital output pins on the
   Arduino. Does sorting to make sure brightness and the runtime of the execute
   method remain the same no matter the number of output's set. 
*/

#include "WProgram.h"

#ifndef LEDFACTORY_H
#define LEDFACTORY_H

#define DEFAULT_LED_STEPS 500
#define TOTAL_OUTPUT_PINS 14

#define OUT_PIN 0
#define ON_TIME 1

class LedFactory {
protected:
   word brightnessSteps;
   word leds[2][TOTAL_OUTPUT_PINS];
   
   void BubbleSort();

public:
   LedFactory();
   ~LedFactory();
   
   word getBrightnessSteps();
   void setBrightnessSteps(word inBrightnessSteps);

   void setLedBrightness(byte pinNum, word brightness);
   void UpdateBuffer(word *inBuf);
   boolean Execute();
};
 
#endif
