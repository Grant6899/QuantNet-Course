//===============================================================
// Level 2 Section 2.1 Exercise 2.1.3
// Author: Grant Liu
// Create Date: 1/12/2017
// Description: point class - h file
//===============================================================
#ifndef POINT_H
#define POINT_H

#include"Shape.h"
#include<iostream>

class Point : public Shape{
 private:
  double m_x, m_y;
 public:

  Point();
  Point(const Point& other);
  Point(double x, double y);
  Point& operator=(const Point& other);

  ~Point();

  double GetX() const;
  double GetY() const;
  void SetX(double x);
  void SetY(double y);

  std::string ToString() const override;
  double DistanceOrigin() const;
  double Distance(Point p) const;
  virtual void draw() override {}

  Point operator - () const; // Negate the coordinates.
  Point operator * (double factor) const; // Scale the coordinates.
  Point operator + (const Point& p) const; // Add coordinates.
  bool operator == (const Point& p) const; // Equally compare operator.ppp
  Point& operator *= (double factor); // Scale the coordinates & assign
  friend std::ostream& operator << (std::ostream& os, const Point& p); //ostream<< operator

  void rotate(double d) override { std::cout<<"p\n"; };

};
#endif
