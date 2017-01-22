//===============================================================
// Level 2 Section 2.1 Exercise 2.1.4
// Author: Grant Liu
// Create Date: 1/12/2017
// Description: point2 class - cpp file
//===============================================================
#include"Point2.h"
#include<sstream>
#include<cmath>
#include<iostream>

Point2::Point2():m_x(0),m_y(0), Shape(){}

Point2::Point2(const Point2& other):m_x(other.m_x), m_y(other.m_y), Shape(other){}

Point2::Point2(double x, double y):Shape(){
  m_x = x;
  m_y = y;
}

Point2& Point2::operator=(const Point2& other){
  if (&other != this){
    Shape::operator=(other);
    m_x = other.m_x;
    m_y = other.m_y;
    return *this;
  }
  else return *this;
}

Point2::~Point2(){}

double Point2::GetX() const{
  return m_x;
}

double Point2::GetY() const{
  return m_y;
}

void Point2::SetX(double x){
  m_x = x;
}

void Point2::SetY(double y){
  m_y = y;
}

std::string Point2::ToString() const{

  std::ostringstream strs, strs1;
  strs << GetX();
  std::string str_x = strs.str();

  strs1 << GetY();
  std::string str_y = strs1.str();
  std::string temp = "Point2(" + str_x + ", " + str_y + ")";
  return temp;
}

double Point2::DistanceOrigin() const{
  double temp = sqrt(m_x * m_x + m_y * m_y);
  return temp;
}

double Point2::Distance(Point2 p) const{
  double x_dif = m_x - p.m_x;
  double y_dif = m_y - p.m_y;
  double temp = sqrt(x_dif * x_dif + y_dif * y_dif);
  return temp;
}

Point2 Point2::operator - () const{
  return Point2(-m_x, -m_y);
}

Point2 Point2::operator * (double factor) const{
  return Point2(m_x * factor, m_y * factor);
}

Point2 Point2::operator + (const Point2& other) const{
  return Point2(m_x + other.m_x,m_y+other.m_y);
}

bool Point2::operator == (const Point2& other) const{
  return (m_x == other.m_x && m_y == other.m_y);
}

Point2& Point2::operator *= (double factor){
  m_x*= factor;
  m_y*= factor;
  return *this;
}

std::ostream& operator<<(std::ostream& os, const Point2& p){
 os<<"["<<p.m_x<<","<<p.m_y<<"]";
 return os;
}
