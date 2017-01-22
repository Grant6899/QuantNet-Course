//===============================================================
// Level 2 Section 2.1 Exercise 2.1.3
// Author: Grant Liu
// Create Date: 1/12/2017
// Description: point class - cpp file
//===============================================================
#include"Point.h"
#include<sstream>
#include<cmath>
#include<iostream>

Point::Point():m_x(0),m_y(0), Shape(){}

Point::Point(const Point& other):m_x(other.m_x), m_y(other.m_y), Shape(other){}

Point::Point(double x, double y):Shape(){
  m_x = x;
  m_y = y;
}

Point& Point::operator=(const Point& other){
  if (&other != this){
    Shape::operator=(other);
    m_x = other.m_x;
    m_y = other.m_y;
    return *this;
  }
  else return *this;
}

Point::~Point(){}

double Point::X() const{
  return m_x;
}

double Point::Y() const{
  return m_y;
}

void Point::X(double x){
  m_x = x;
}

void Point::Y(double y){
  m_y = y;
}

std::string Point::ToString() const{

  std::ostringstream strs, strs1;
  strs << X();
  std::string str_x = strs.str();

  strs1 << Y();
  std::string str_y = strs1.str();
  std::string temp = "Point(" + str_x + ", " + str_y + ")";
  return temp;
}

double Point::DistanceOrigin() const{
  double temp = sqrt(m_x * m_x + m_y * m_y);
  return temp;
}

double Point::Distance(Point p) const{
  double x_dif = m_x - p.m_x;
  double y_dif = m_y - p.m_y;
  double temp = sqrt(x_dif * x_dif + y_dif * y_dif);
  return temp;
}

Point Point::operator - () const{
  return Point(-m_x, -m_y);
}

Point Point::operator * (double factor) const{
  return Point(m_x * factor, m_y * factor);
}

Point Point::operator + (const Point& other) const{
  return Point(m_x + other.m_x,m_y+other.m_y);
}

bool Point::operator == (const Point& other) const{
  return (m_x == other.m_x && m_y == other.m_y);
}

Point& Point::operator *= (double factor){
  m_x*= factor;
  m_y*= factor;
  return *this;
}

std::ostream& operator<<(std::ostream& os, const Point& p){
 os<<"["<<p.m_x<<","<<p.m_y<<"]";
 return os;
}
