/***********************************************************************
 * Header File:
 *    POSITION
 * Author:
 *    <your name here>
 * Summary:
 *    Everything we need to know about a location on the screen.
 ************************************************************************/
#pragma once


class Velocity;        // for Position::add()
class Acceleration;    // for Position::add()
class TestPosition;    // for the unit tests
class TestLander;      // for the unit tests

/*********************************************
 * POSITION
 * A single position on the screen
 *********************************************/
class Position
{
   friend TestPosition;    // for the unit tests
   friend TestLander;      // for the unit tests

public:
   // constructors
   Position() : x(0.0), y(0.0) { }
   Position(const Position& pos) : x(pos.getX()), y(pos.getY()) { }
   Position(double x, double y);

   // getters
   double getX() const { return x; }
   double getY() const { return y; }
   bool operator == (const Position& rhs) const
   {
      if (rhs.getX() == this->getX() && rhs.getY() == this->getY())
      {
         return true;
      }
      else
      {
         return false;
      }
   }
   bool operator != (const Position& rhs) const
   {
      if (rhs.getX() != this->getX() || rhs.getY() != this->getY())
         return true;
      else
         return false;
   }
   double getZoom() { return metersFromPixels; };
   double getPixelsX() { return x / metersFromPixels; };
   double getPixelsY() { return y / metersFromPixels; };
   double getMetersX() { return x; };
   double getMetersY() { return y; };


   // setters
   void setX(double x) { this->x = x; }
   void setY(double y) { this->y = y; }
   void setZoom(double zoom) { this->metersFromPixels = zoom; };
   void setPixelsX(double pixels) { this->x = pixels * metersFromPixels; };
   void setPixelsY(double pixels) { this->y = pixels * metersFromPixels; };
   void setMetersX(double meters) { this->x = meters; };
   void setMetersY(double meters) { this->y = meters; };

   //adders
   void addX(double x) { this->x += x; }
   void addY(double y) { this->y += y; }
   void addMetersX(double meters) { this->x += meters; };
   void addMetersY(double meters) { this->y += meters; };
   void addPixelsX(double pixels) { this->x += pixels * metersFromPixels; };
   void addPixelsY(double pixels) { this->y += pixels * metersFromPixels; };
   void add(const Acceleration& a, const Velocity& v, double t);

   Position& operator = (const Position& rhs)
   {
      x = rhs.getX();
      y = rhs.getY();
      return *this;
   }

private:
   double x;           // horizontal position
   double y;           // vertical position
   static double metersFromPixels;
};
