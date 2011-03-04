/* LedFactory.h
   Josh Kasten 
   1-27-11 
   A model object to control a dot moving back and forth as it
   reaches each end and to draw it to an LED array.
*/

#include "WProgram.h"

#ifndef MOVINGDOT_H
#define MOVINGDOT_H

#define OUTPUT_SIZE 14

class MovingDot {
protected:
   float pos;
   float intensity;
   float velocity;
   word outputSet[OUTPUT_SIZE];

public:
   MovingDot(float startPosX, float inIntensity, float inVelocity);
   ~MovingDot();
   
   void setVelocity(float inVelocity);
   void setSpeed(float inSpeed);
   void Output(word *writeBuf);
};
 
#endif

