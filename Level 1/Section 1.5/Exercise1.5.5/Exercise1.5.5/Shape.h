//===============================================================
// Level 1 Section 1.5 Exercise 1.5.5
// Author: Grant Liu
// Create Date: 1/8/2017
// Description: shape class - h file
//===============================================================
#ifndef SHAPE_H
#define SHAPE_H

#include<string>
#include"IODevice.h"


using namespace std;


class Shape{
 private:
  int m_id; //ID for the shape

 public:

  Shape();// Default constructor
  Shape(const Shape& rhs);// Copy constructor
  const Shape& operator=(const Shape& rhs);// Assignment constructor
  ~Shape();// Destructor

  virtual string ToString() const; //String description for the shape
  int ID() const;// Return ID for the shape

  virtual void display(IODevice& ioDevice) const = 0;
};
#endif
