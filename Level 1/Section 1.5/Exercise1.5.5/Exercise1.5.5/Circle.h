//===============================================================
// Level 1 Section 1.5 Exercise 1.5.5
// Author: Grant Liu
// Create Date: 1/8/2017
// Description: circle class - h file
//===============================================================
#ifndef CIRCLE_H
#define CIRCLE_H

#include"Shape.h"
#include"Point.h"
#include<cmath>

class Circle: public Shape{
 private:
  double m_radius; // Radius
  Point Center;// Center of the circle
 public:
  Circle(); // Default constructor
  Circle(double r, const Point& p); // Constructor
  Circle(const Circle& c); // Copy constructor
  ~Circle(); // Destructor
  Circle& operator=(const Circle& c); // Assignment operator
  friend ostream& operator<<(ostream& os, const Circle& c); // ostream<< operator

  Point CentrePoint() const; // Return centrepoint
  void CentrePoint(Point p); // Set centrepoint
  double Radius() const; // Return radius
  void Radius(double r); // Set radius
  double Diameter() const; // Return diameter
  double Area() const; // Return area of the circle
  double Circumference() const; // Return circumference of the circle
  string ToString() const; // Return string description of the circle

  void display(IODevice& ioDevice) const override; //Use specified ioDevice to display this object

};
#endif
