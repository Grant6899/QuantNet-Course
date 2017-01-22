#include"Line.h"
#include<iostream>

Line::Line():st(Point(0,0)),ed(Point(0,0)), Shape(){}

Line::Line(const Point& s, const Point& e): st(s), ed(e), Shape(){}

Line::Line(const Line& l):st(l.St()), ed(l.Ed()), Shape(l){}

Line& Line::operator=(const Line& l){
  if( &l != this){
    Shape::operator=(l);
    St(l.St());
    Ed(l.Ed());
    return *this;
  }
  else return *this;
}

Point Line::St() const{
  return st;
}

Point Line::Ed() const{
  return ed;
}

void Line::St(const Point& s){
  st = s;
}

void Line::Ed(const Point& e){
  ed = e;
}

string Line::ToString() const {
  string temp = "This is a line segment between " + st.ToString() + " and " + ed.ToString() + ".";
  return temp;
}

double Line::Length() const{
  return st.Distance(ed);
}

ostream& operator << (ostream& os, const Line& l) //ostream<< operator as friend
{
  os <<"["<<l.st<<","<<l.st<<"]"<<endl;
  return os;
}

void Line::display(IODevice& ioDevice) const {
	ioDevice << *this;
}