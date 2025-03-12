/***********************************************************************
 * Header File:
 *    ANGLE
 * Author:
 *    Br. Helfrich
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
   Angle() : radians(0.00) {}
   Angle(const Angle& rhs) : radians(rhs.radians) {}
   Angle(double degrees) : radians(normalize(degrees* M_PI / 180)) {}

   // Getters
   double getDegrees() const { return radians * 180 / M_PI; }
   double getRadians() const { return normalize(radians); }

   // Setters
   void setDegrees(double degrees) { radians = normalize((degrees * M_PI) / 180); }
   void setRadians(double radians) { this->radians = normalize(radians); }
   void setUp() { setDegrees(0.0); }
   void setDown() { setDegrees(180.0); }
   void setRight() { setDegrees(90.0); }
   void setLeft() { setDegrees(270.0); }
   void reverse() { radians += M_PI; }
   Angle& add(double delta)
   {
      radians += delta;             // Add delta to the angle
      radians = normalize(radians); // Normalize the result
      return *this;
   }

private:
   double normalize(double radians) const;
   double radians;   // 360 degrees equals 2 PI radians
};