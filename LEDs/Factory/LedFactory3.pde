/* LedFactory3.pde
   Josh Kasten 
   1-27-11 
   Draws a dot that bounces back and forth on 14 LEDs in a line.
   As it crosses each LED it does it smoothly by contorlling its
   brightness with PWM.
   More MovingDots can be added and display by just creating a
   new MovingDot object and adding the out of it in the loop
   function.
*/

#include "LedFactory.h"
#include "MovingDot.h"

#define OUT_ARRAY_SIZE 14

LedFactory ledFactory;
MovingDot  movingDot(0, 500, 0.01);

word outputBuf[OUT_ARRAY_SIZE];

void setup() {
  // Serial.begin(115200); // debug
  noInterrupts();
}

void ClearBuf(word *outBuf) {
  for(byte i = 0; i < OUT_ARRAY_SIZE; i++)
     outputBuf[i] = 0;
}

void loop() {
  ClearBuf(outputBuf);
  
  movingDot.setSpeed((analogRead(A5) / 1024.0) * 0.1);
  movingDot.Output(outputBuf);
  
  ledFactory.UpdateBuffer(outputBuf);
  ledFactory.Execute();
}
