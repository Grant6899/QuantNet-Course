//===============================================================
// Level 1 Section 1.4 Exercise 1.4.5
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
  VoidFunctionType f_rotate; // function wrapper member

 public:
  Shape();// Default constructor
  Shape(const Shape& rhs);// Copy constructor
  Shape(const VoidFunctionType& fun); // Constructor with voidfunction
  Shape& operator=(const Shape& rhs);// Assignment constructor
  ~Shape();// Destructor

  string ToString() const; //String description for the shape
  void rotate(double d); // call the protected function member
  void setRotateFun(const VoidFunctionType& fun); // Set the protected function member
  int ID() const;// Return ID for the shape

};
#endif
