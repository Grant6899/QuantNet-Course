#define _USE_MATH_DEFINES
#include"Circle.h"
#include<sstream>
#include<iostream>
#include<cmath>

using namespace std;

Circle::Circle():Center(Point(0,0)), m_radius(1), Shape(){}

Circle::Circle(double r, const Point& p):Center(p), m_radius(r), Shape(){}

Circle::Circle(const Circle& c):Center(c.CentrePoint()), m_radius(c.Radius()), Shape(){}

Circle::~Circle(){}

Circle& Circle::operator=(const Circle& c){
  if (&c != this){
    Shape::operator=(c);
    m_radius = c.Radius();
    Center = c.CentrePoint();
    return *this;
  }
  else return *this;
}

ostream& operator<<(ostream& os, const Circle& c){
  os<<"("<<c.CentrePoint()<<", "<<c.Radius()<<")"<<endl;
  return os;
}

Point Circle::CentrePoint() const{
  return Center;
}

void Circle::CentrePoint(Point p){
  Center = p;
}

double Circle::Radius() const{
  return m_radius;
}

double Circle::Diameter() const{
  return 2*m_radius;
}

double Circle::Area() const{
  return M_PI*m_radius*m_radius;
}

double Circle::Circumference() const{
  return M_PI * Diameter();
}

string Circle::ToString() const{
  ostringstream strs;
  strs << Radius();
  string str = strs.str();

  return "Center:" + Center.ToString() + "   Radius:" + str;
}

void Circle::display(IODevice& ioDevice) const {
	ioDevice << *this;
}