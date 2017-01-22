//===============================================================
// Level 1 Section 1.3 Exercise 1.3.2
// Author: Grant Liu
// Create Date: 1/6/2017
// Description: valve class - h file
//===============================================================
#ifndef VALVE_H
#define VALVE_H

#include<string>
#include<iostream>

using namespace std;

class Valve{
 private:
  int i_data; //Int data for the valve

 public:

  Valve();// Default constructor
  Valve(const Valve& rhs);// Copy constructor
  const Valve& operator=(const Valve& rhs);// Assignment constructor
  ~Valve();// Destructor

  virtual string ToString() const; //String description for the valve
  void rotate(double d) { std::cout<<"v\n";}; //Non-virtual rotate function
  int getData() const;// Return data for the valve
};
#endif
