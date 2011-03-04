/* MovingDot.cpp
   Josh Kasten 
   1-23-11
*/

#include "MovingDot.h"

MovingDot::MovingDot(float startPos, float inIntensity, float inVelocity) {
   pos = startPos;
   intensity = inIntensity;
   velocity = inVelocity;
}

MovingDot::~MovingDot() {
}

void MovingDot::setVelocity(float inVelocity) {
   velocity = inVelocity;
}

void MovingDot::setSpeed(float inSpeed) {
   if (velocity > 0)
      setVelocity(inSpeed);
   else
      setVelocity(-inSpeed);
}

void MovingDot::Output(word *writeBuf) {
   float temp;
   byte uPos;
   
   uPos = byte(pos);
   temp = 1.0 - (pos - word(pos));
   
   writeBuf[uPos] += temp * float(intensity);
   uPos++;
   writeBuf[uPos] += (1.0 - temp) * float(intensity);
   
   pos += velocity;
      
   if (pos <= 0) {
      pos = 0;
      velocity = -velocity;
   }
   else if (pos >= (OUTPUT_SIZE - 1)) {
      pos = OUTPUT_SIZE - 1;
      velocity = -velocity;
   }
}
