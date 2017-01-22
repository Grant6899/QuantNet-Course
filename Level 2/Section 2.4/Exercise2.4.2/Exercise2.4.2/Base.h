//===============================================================
// Level 2 Section 2.4 Exercise 2.4.2
// Author: Grant Liu
// Create Date: 1/13/2017
// Description: Shape class - h file
//===============================================================
#include<iostream>

class Base{
 private:
  int y;
 public:
  Base() {}
  void draw() {}
  ~Base() { std::cout<< "Base destructor" << std::endl;}
};
