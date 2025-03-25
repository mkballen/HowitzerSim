/***********************************************************************
 * Source File:
 *    PHYSICS
 * Author:
 *    TEAM JACKAL
 * Summary:
 *    Laws of motion, effects of gravity, wind resistence, etc.
 ************************************************************************/
  
#include "physics.h"  // for the prototypes
#include <cmath>

 
 /*********************************************************
 * LINEAR INTERPOLATION
 * From a list of domains and ranges, linear interpolate
 *********************************************************/
double linearInterpolation(const Mapping mapping[], int numMapping, double d)
{
   Mapping first;
   Mapping next;

   for (int i = 0; i <= numMapping; i++)
   {
      first = mapping[i];
      next = mapping[i+1];
      double d0 = first.domain;
      double d1 = next.domain;
      double r0 = first.range;
      double r1 = next.range;

      if (d >= d0 && d <= d1)
      {
         return r0 + (r1 - r0) * (d - d0) / (d1 - d0);
      }
   }

   if (d < mapping[0].domain)
   {
      return -1.0;
   }
   if (d > mapping[numMapping].domain)
   {
      return -2.0;
   }
   
}

/*********************************************************
 * GRAVITY FROM ALTITUDE
 * Determine gravity coefficient based on the altitude
 *********************************************************/
double gravityFromAltitude(double altitude)
{
   double bignum = (6378137.3141 / (6378137.3141 + altitude));
   double gravity = 9.80665 * (bignum * bignum);
   return gravity;
}

/*********************************************************
 * DENSITY FROM ALTITUDE
 * Determine the density of air based on the altitude
 *********************************************************/
double densityFromAltitude(double altitude)
{
   Mapping densityMap[] =
   {
   {0,	   1.2250000},
   {1000,	1.1120000},
   {2000,	1.0070000},
   {3000,	0.9093000},
   {4000,	0.8194000},
   {5000,	0.7364000},
   {6000,	0.6601000},
   {7000,	0.5900000},
   {8000,	0.5258000},
   {9000,	0.4671000},
   {10000,	0.4135000},
   {15000,	0.1948000},
   {20000,	0.0889100},
   {25000,	0.0400800},
   {30000,	0.0184100},
   {40000,	0.0039960},
   {50000,	0.0010270},
   {60000,	0.0003097},
   {70000,	0.0000828},
   {80000,	0.0000185} };

   double density = linearInterpolation(densityMap, 20, altitude);
   return density;
}

/*********************************************************
 * SPEED OF SOUND FROM ALTITUDE
 * determine the speed of sound for a given altitude.
 ********************************************************/
double speedSoundFromAltitude(double altitude)
{
   Mapping speedMap[] =
   {
      {0,	       340},
      {1000,	336},
      {2000,	332},
      {3000,	328},
      {4000,	324},
      {5000,	320},
      {6000,	316},
      {7000,	312},
      {8000,	308},
      {9000,	303},
      {10000,	299},
      {15000,	295},
      {20000,	295},
      {25000,	295},
      {30000,	305},
      {40000,	324},
      {50000,	337},
      {60000,	319},
      {70000,	289},
      {80000,	269} };

   double speed = linearInterpolation(speedMap, 20, altitude);
   return speed;
}


/*********************************************************
 * DRAG FROM MACH
 * Determine the drag coefficient for a M795 shell given speed in Mach
 *********************************************************/
double dragFromMach(double speedMach)
{
   Mapping dragMap[] =
   {
      {0.0,   0.0   },      
      {0.300, 0.1629},
      {0.500, 0.1659},
      {0.700, 0.2031},
      {0.890, 0.2597},
      {0.920, 0.3010},
      {0.960, 0.3287},
      {0.980, 0.4002},
      {1.000, 0.4258},
      {1.020, 0.4335},
      {1.060, 0.4483},
      {1.240, 0.4064},
      {1.530, 0.3663},
      {1.990, 0.2897},
      {2.870, 0.2297},
      {2.890, 0.2306},
      {5.000, 0.2656} };

   double drag = linearInterpolation(dragMap, 16, speedMach);
   return drag;
}

