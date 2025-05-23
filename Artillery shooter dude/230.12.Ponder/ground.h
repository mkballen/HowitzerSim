/***

Header File:
GROUND
Author:
Br. Helfrich
Summary:
Represents the ground in the artillery simulation**/

#pragma once

#include "position.h"   // for Point
#include "uiDraw.h"

// forward declaration for the Ground unit tests
class TestGround;

/***

GROUND
The ground class
***/
class Ground
{
   // unit test access
   friend ::TestGround;

public:
   // the constructor generates the ground
   Ground(const Position& posUpperRight);
   Ground() : ground(nullptr), iHowitzer(0), iTarget(0) {}

   // reset the game
   void reset(Position& posHowitzer);

   // draw the ground on the screen
   void draw(ogstream& gout) const;

   // determine how high the Point is off the ground
   double getElevationMeters(const Position& pos) const;

   // where the the target located?
   Position getTarget() const;

private:
   double* ground;               // elevation of the ground, in pixels 
   int iTarget;                   // the location of the target, in pixels
   int iHowitzer;                 // the location of the howitzer
   Position posUpperRight;        // size of the screen
};

