//===============================================================
// Level 1 Section 1.4 Exercise 1.4.4
// Author: Grant Liu
// Create Date: 1/7/2017
// Description: shape class - h file
//===============================================================
#ifndef SHAPE_H
#define SHAPE_H

#include<string>
#include<functional>

using namespace std;

using VoidFunctionType = std::function<void (double)>;

class Shape{
 private:
  int m_id; //ID for the shape

 protected:
  VoidFunctionType f; // function wrapper member

 public:

  Shape();// Default constructor
  Shape(const Shape& rhs);// Copy constructor
  Shape(const VoidFunctionType& fun); // Constructor with voidfunction
  Shape& operator=(const Shape& rhs);// Assignment constructor
  ~Shape();// Destructor

  virtual string ToString() const; //String description for the shape
  virtual void rotate(double d); //Pure virtual funnction for overloading
  int ID() const;// Return ID for the shape
};
#endif
