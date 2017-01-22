//===============================================================
// Level 1 Section 1.3 Exercise 1.3.2
// Author: Grant Liu
// Create Date: 1/6/2017
// Description: shape class - h file
//===============================================================
#ifndef SHAPE_H
#define SHAPE_H

#include<string>

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
  virtual void rotate(double d) = 0; //Pure virtual funnction for overloading
  int ID() const;// Return ID for the shape
};
#endif
