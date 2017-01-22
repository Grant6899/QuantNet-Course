//===============================================================
// Level 2 Section 2.1 Exercise 2.1.3
// Author: Grant Liu
// Create Date: 1/12/2017
// Description: point1 class - h file
//===============================================================
#ifndef POINT1_H
#define POINT1_H

#include"Shape.h"
#include<iostream>

class Point1 : public Shape{
 private:
  double m_x, m_y;
 public:

  Point1();
  Point1(const Point1& other) = delete;
  Point1(double x, double y);
  Point1& operator=(const Point1& other) = delete;

  ~Point1();

  double GetX() const;
  double GetY() const;
  void SetX(double x);
  void SetY(double y);

  std::string ToString() const override;
  double DistanceOrigin() const;
  double Distance(Point1 p) const;
  virtual void draw() override {}
  /*
  Point1 operator - () const; // Negate the coordinates.
  Point1 operator * (double factor) const; // Scale the coordinates.
  Point1 operator + (const Point1& p) const; // Add coordinates.
  bool operator == (const Point1& p) const; // Equally compare operator.ppp
  Point1& operator *= (double factor); // Scale the coordinates & assign
  */

  // Comment this out because they call copy ctor in implement

  friend std::ostream& operator << (std::ostream& os, const Point1& p); //ostream<< operator

  void rotate(double d) override { std::cout<<"p\n"; };

};
#endif
