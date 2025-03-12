/***********************************************************************
 * Header File:
 *    ANGLE
 * Author:
 *    <your name here>
 * Summary:
 *    Everything we need to know about a direction
 ************************************************************************/

#pragma once

#define _USE_MATH_DEFINES
#include <math.h>   // for M_PI which is 3.14159

class TestPosition;
class TestVelocity;
class TestAcceleration;
class TestAngle;
class TestLander;

/************************************
 * ANGLE
 ************************************/
class Angle
{
public:
   friend TestAcceleration;
   friend TestVelocity;
   friend TestAngle;
   friend TestLander;

   // Constructors
   Angle() : radians(0.00), dX(0.0), dY(0.0) {}
   Angle(const Angle& rhs) : radians(rhs.radians), dX(rhs.dX), dY(rhs.dY){}
   Angle(double degrees) : radians(normalize(degrees* M_PI / 180)) {}

   // Getters
   double getDegrees() const { return radians * 180 / M_PI; }
   double getRadians() const { return normalize(radians); }
   double getDx() { return dX; }
   double getDy() { return dY; }
   

   // Setters
   void setDegrees(double degrees) { radians = normalize((degrees * M_PI) / 180.0); dX = sin(radians); dY = cos(radians);}
   void setRadians(double radians) { this->radians = normalize(radians);}
   void setUp() { setDegrees(0.0);}
   void setDown() { setDegrees(180.0);}
   void setRight() { setDegrees(90.0);}
   void setLeft() { setDegrees(270.0);}
   void setDxDy(double dx, double dy) { dX = dx; dY = dy; setRadians(atan2(dX, dY));}
   void reverse() { radians += M_PI; }
   Angle& add(double delta)
   {
      radians += delta;             
      radians = normalize(radians);
      return *this;
   }

   // Checkers
   bool isRight() {if (getRadians() < M_PI) { return true; } else { return false; }}
   bool isLeft()  {if (getRadians() > M_PI) { return true; } else { return false; }}

private:  
   double normalize(double radians) const;
   double radians;
   double dX;
   double dY;
};