//===============================================================
// Level 2 Section 2.1 Exercise 2.1.4
// Author: Grant Liu
// Create Date: 1/12/2017
// Description: point2 class - h file
//===============================================================
#ifndef POINT2_H
#define POINT2_H

#include"Shape.h"
#include<iostream>

class Point2 : public Shape{
 private:
  double m_x, m_y;
 public:

  Point2();
  Point2(const Point2& other);
  Point2(const Point2&& other);
  Point2(double x, double y);
  Point2& operator=(const Point2& other);
  Point2& operator=(const Point2&& other);

  ~Point2();

  double GetX() const;
  double GetY() const;
  void SetX(double x);
  void SetY(double y);

  std::string ToString() const override;
  double DistanceOrigin() const;
  double Distance(Point2 p) const;
  virtual void draw() override {}

  Point2 operator - () const; // Negate the coordinates.
  Point2 operator * (double factor) const; // Scale the coordinates.
  Point2 operator + (const Point2& p) const; // Add coordinates.
  bool operator == (const Point2& p) const; // Equally compare operator.ppp
  Point2& operator *= (double factor); // Scale the coordinates & assign
  friend std::ostream& operator << (std::ostream& os, const Point2& p); //ostream<< operator

  void rotate(double d) override { std::cout<<"p\n"; };

};
#endif
