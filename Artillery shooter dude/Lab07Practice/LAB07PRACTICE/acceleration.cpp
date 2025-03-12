/***********************************************************************
   * Source File :
   *ACCELERATION
   * Author :
      *Br.Helfrich
      * Summary :
      *Everything we need to know about changing speed
   ************************************************************************/

#include "acceleration.h"
#include "angle.h"
#include <iostream>
#include <cmath>

   /*********************************************
    * ACCELERATION : ADD
    *  a += a
    *********************************************/
   void Acceleration::add(const Acceleration & acceleration)
{
   addDDX(acceleration.ddx);
   addDDY(acceleration.ddy);
}

/*********************************************
 * ACCELERATION : SET
 *  set from angle and direction
 *********************************************/
void Acceleration::set(const Angle& angle, double magnitude)
{
   ddx = magnitude * sin(angle.getRadians());
   ddy = magnitude * cos(angle.getRadians());
}