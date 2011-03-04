/* LedFactory.cpp
   Josh Kasten 
   1-23-11
*/

#include "LedFactory.h"

LedFactory::LedFactory() {
   brightnessSteps = DEFAULT_LED_STEPS;
   for(byte i = 0; i < TOTAL_OUTPUT_PINS; i++) {
      leds[OUT_PIN][i] = i;
   }
}

LedFactory::~LedFactory() {
}

word LedFactory::getBrightnessSteps() {
   return brightnessSteps;
}

void LedFactory::setBrightnessSteps(word inBrightnessSteps) {
   brightnessSteps = inBrightnessSteps;
}

void LedFactory::setLedBrightness(byte pinNum, word inBrightness) {
   word temp;
   if (inBrightness < brightnessSteps)
      temp = inBrightness;
   else
      temp = brightnessSteps - 1;
  
   pinMode(pinNum, OUTPUT);
   for(word i = 0; i < TOTAL_OUTPUT_PINS; i++) {
      if (leds[OUT_PIN][i] == pinNum)
         leds[ON_TIME][i] = temp;
   }
}

void LedFactory::UpdateBuffer(word *inBuf) {
  for(byte i = 0; i < TOTAL_OUTPUT_PINS; i++)
     setLedBrightness(i, inBuf[i]);
}

boolean LedFactory::Execute() {
  word a, temp;
  BubbleSort();
  
   for(a = 0; a < TOTAL_OUTPUT_PINS; a++) {
      if (leds[ON_TIME][a] != 0)
         digitalWrite(leds[OUT_PIN][a], HIGH);
   }
   
   for(a = 0; a < TOTAL_OUTPUT_PINS; a++) {
      if (leds[ON_TIME][a] != 0) {
         if (a > 0) {
            temp = leds[ON_TIME][a] - leds[ON_TIME][a - 1];
            if (temp > 0)
               delayMicroseconds(temp);
         }
         else
            delayMicroseconds(leds[ON_TIME][a]);
         
         digitalWrite(leds[OUT_PIN][a], LOW);
      }
   }

   return true;
}

void LedFactory::BubbleSort()
{
   word i, j;
   boolean flag = true;
   word temp;

   for(i = 1; (i <= TOTAL_OUTPUT_PINS) && flag; i++)
   {
      flag = false;
      for (j = 0; j < (TOTAL_OUTPUT_PINS - 1); j++)
      {
         if (leds[ON_TIME][j + 1] < leds[ON_TIME][j])
         { 
            temp = leds[OUT_PIN][j];
            leds[OUT_PIN][j]     = leds[OUT_PIN][j + 1];
            leds[OUT_PIN][j + 1] = temp;

            temp = leds[ON_TIME][j];
            leds[ON_TIME][j]     = leds[ON_TIME][j + 1];
            leds[ON_TIME][j + 1] = temp;

            flag = true;
         }
      }
   }
}
