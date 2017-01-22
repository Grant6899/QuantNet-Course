//===============================================================
// Level 1 Section 1.4 Exercise 1.4.4
// Author: Grant Liu
// Create Date: 1/7/2017
// Description: circle class - h file
//===============================================================
#ifndef CIRCLE_H
#define CIRCLE_H

#include"Shape.h"
#include"Point.h"
#include<cmath>

using VoidFunctionType = std::function<void (double)>;

class Circle: public Shape{
 private:
  double m_radius; // Radius
  Point Center;// Center of the circle

 public:
  Circle(); // Default constructor
  Circle(double r, const Point& p); // Constructor
  Circle(const Circle& c); // Copy constructor
  Circle(const VoidFunctionType& fun); // Constructor with voidfunction
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
  string ToString() ; // Return string description of the circle

  void rotate(double d) override; // Rotate function overriding


};
#endif
