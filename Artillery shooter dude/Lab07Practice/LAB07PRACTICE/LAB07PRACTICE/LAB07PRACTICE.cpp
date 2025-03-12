// LAB07PRACTICE.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#define DRAGCO 0.3
#define AIRDENSITY 0.6

using namespace std;

// Calculates the total velocity based off of a vertical and horizontal component
double totalVelocity(double dx, double dy)
{
   double v = dx * dx + dy * dy;
   v = sqrt(v);
   return v;
}

// Converts a double of degrees into a double of radians
double degreesToRadians(double degrees)
{
   double radians = (degrees / 360) * (2 * M_PI);
   return radians;
}

double dragForce(double velocity)
{
   return -(0.5 * DRAGCO * AIRDENSITY * velocity * velocity * ((0.15489/2.0) * (0.15489 / 2.0) * M_PI));
}

double linearInterpolation(double d, const vector<pair<double, double>>& table)
{
   double dI;
   double dF;
   double rI;
   double rF;

   // Edge cases: If x is outside the known range, return closest known value
   if (d <= table.front().first) return table.front().second;
   if (d >= table.back().first) return table.back().second;

   // Find the two closest points
   for (int i = 0; i < table.size() - 1; ++i)
   {
      dI = table[i].first;
      dF = table[i + 1].first;
      rI = table[i].second;
      rF = table[i + 1].second;

      if (d >= dI && d <= dF)  // Found correct interval
         return  ((d - dI) * ((rF - rI) / (dF - dI)) + rI);
   }
   return -1;
}

double computeGravity(double y)
{
   vector<pair<double, double>> gravityTable = {
        {0, 9.807}, {1000, 9.804}, {2000, 9.801}, {3000, 9.797}, {4000, 9.794},
        {5000, 9.791}, {6000, 9.788}, {7000, 9.785}, {8000, 9.782}, {9000, 9.779},
        {10000, 9.776}, {15000, 9.761}, {20000, 9.745}, {25000, 9.730}, {30000, 9.715},
        {40000, 9.684}, {50000, 9.654}, {60000, 9.624}, {70000, 9.594}, {80000, 9.564}
   };

   double gravity = linearInterpolation(y, gravityTable);
   return gravity;
}

void inertia(double startDistance)
{
   double angle = 75.0;
   double radians = degreesToRadians(angle);
   double initialSpeed = 827.0;
   double dx = initialSpeed * cos(radians);
   double dy = initialSpeed * sin(radians);
   double ddx = 0.0;
   double ddy = 0.0;
   double time = 0.01;
   double x = 0.0;
   double y = 0.0;
   double hangTime = 0.0;      
   double gravity = computeGravity(y);
   cout << "Gravity: " << gravity << endl;
   double totalSpeed = totalVelocity(dx, dy);

   while(y >= 0.0)
   {
      gravity = computeGravity(y);

      x += dx * time + 0.5 * (ddx) * time * time;
      y += dy * time - 0.5 * (ddy + gravity) * time * time;

      dx += ddx * time;
      dy += (ddy - gravity) * time;

      hangTime += time;
   }

   cout << "Distance: " << x << "m Altitude: " << y << "m Hang Time: " << hangTime;
}

int main()
{
   double startDistance = 0.0;
   cout << "Hello World!\n";
   inertia(startDistance);
}

