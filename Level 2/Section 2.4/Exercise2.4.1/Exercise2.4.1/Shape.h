//==============================================================
// Level 2 Section 2.1 Exercise 2.1.3
// Author: Grant Liu
// Create Date: 1/12/2017
// Description: shape class - h file
//===============================================================
#ifndef SHAPE_H
#define SHAPE_H

#include<string>

class Shape{
 private:
  int m_id; //ID for the shape

 public:

  Shape();// Default constructor
  Shape(const Shape& rhs);// Copy constructor
  const Shape& operator=(const Shape& rhs);// Assignment constructor
  ~Shape();// Destructor

  virtual std::string ToString() const; //String description for the shape
  virtual void rotate(double d) = 0; //Pure virtual function for overloading
  virtual void draw() = 0; // Pure virtual function for overloading
  int ID() const;// Return ID for the shape
};
#endif
