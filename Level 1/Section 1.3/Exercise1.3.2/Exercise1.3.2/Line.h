//===============================================================
// Level 1 Section 1.3 Exercise 1.3.2
// Author: Grant Liu
// Create Date: 1/6/2017
// Description: line class - h file
//===============================================================
#ifndef LINE_H
#define LINE_H

#include"Shape.h"
#include"Point.h"
#include<string>

class Line:public Shape{
 private:
  Point st, ed; //Start and end point
 public:
  Line();// Default constructor
  Line(const Point& s, const Point& e);// Constructor
  Line(const Line& l);// Copy constructor
  Line& operator=(const Line& l);// Assignment operator

  Point St() const; // Return start point
  Point Ed() const; // Return end point
  void St(const Point& s); // Set start point
  void Ed(const Point& e); // Set end point
  string ToString(); // Return string description
  double Length(); // Return the length of the Line

  friend ostream& operator <<(ostream& os, const Line& l); //ostream<< operator
  void rotate(double d) override;


};


#endif
