//===============================================================
// Level 2 Section 2.1 Exercise 2.1.3
// Author: Grant Liu
// Create Date: 1/12/2017
// Description: point1 class - cpp file
//===============================================================
#include"Point1.h"
#include<sstream>
#include<cmath>
#include<iostream>

Point1::Point1():m_x(0),m_y(0), Shape(){}

Point1::Point1(double x, double y):Shape(){
  m_x = x;
  m_y = y;
}

Point1::~Point1(){}

double Point1::GetX() const{
  return m_x;
}

double Point1::GetY() const{
  return m_y;
}

void Point1::SetX(double x){
  m_x = x;
}

void Point1::SetY(double y){
  m_y = y;
}

std::string Point1::ToString() const{

  std::ostringstream strs, strs1;
  strs << GetX();
  std::string str_x = strs.str();

  strs1 << GetY();
  std::string str_y = strs1.str();
  std::string temp = "Point1(" + str_x + ", " + str_y + ")";
  return temp;
}

double Point1::DistanceOrigin() const{
  double temp = sqrt(m_x * m_x + m_y * m_y);
  return temp;
}

double Point1::Distance(Point1 p) const{
  double x_dif = m_x - p.m_x;
  double y_dif = m_y - p.m_y;
  double temp = sqrt(x_dif * x_dif + y_dif * y_dif);
  return temp;
}

/*
Point1 Point1::operator - () const{
  return Point1(-m_x, -m_y);
}

Point1 Point1::operator * (double factor) const{
  return Point1(m_x * factor, m_y * factor);
}

Point1 Point1::operator + (const Point1& other) const{
  return Point1(m_x + other.m_x,m_y+other.m_y);
}

bool Point1::operator == (const Point1& other) const{
  return (m_x == other.m_x && m_y == other.m_y);
}

Point1& Point1::operator *= (double factor){
  m_x*= factor;
  m_y*= factor;
  return *this;
}

*/
std::ostream& operator<<(std::ostream& os, const Point1& p){
 os<<"["<<p.m_x<<","<<p.m_y<<"]";
 return os;
}
