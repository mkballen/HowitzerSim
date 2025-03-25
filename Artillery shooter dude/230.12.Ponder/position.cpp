/***********************************************************************
 * Source File:
 *    POSITION
 * Author:
 *    <your name here>
 * Summary:
 *    Everything we need to know about a location on the screen.
 ************************************************************************/

#include "position.h"
#include "velocity.h"
#include "acceleration.h"

 /******************************************
  * POINT : CONSTRUCTOR WITH X,Y
  * Initialize the point to the passed position
  *****************************************/
Position::Position(double x, double y) : x(x), y(y) { };

/******************************************
 * POINT : ADD
 * Update point based on the distance formula
 *   s = s_0 + vt + 1/2 a t^2
 *****************************************/
void Position::add(const Acceleration& a, const Velocity& v, double t)
{
   double vX = v.getDX();
   double vY = v.getDY();
   double aX = a.getDDX();
   double aY = a.getDDY();
   x = x + (vX * t) + 0.5 * aX * (t * t);
   y = y + (vY * t) + 0.5 * aY * (t * t);
}