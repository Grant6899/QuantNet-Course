//===============================================================
// Level 1 Section 1.4 Exercise 1.4.5
// Author: Grant Liu
// Create Date: 1/7/2017
// Description: main file
//===============================================================
#include"Shape.h"
#include<iostream>
#include<functional>
#include<cmath>

using std::cout;
using std::endl;

using VoidFunctionType = std::function<void (double)>;

int main(){

  // Command-style function test:
  auto Rotate_Print = [](double d) {cout<<"This is a rotate function"<<endl; };
  auto Rotate_Sqrt_Calculator = [](double d) {cout<<"The sqrt of "<<d<<" is "<<std::sqrt(d)<<endl; };
  Shape s(Rotate_Print); // Declare a shape object with Rotate_Print as its rotate function
  s.rotate(1);

  // Change the rotate function into Rotate_Sqrt_Calculator
  s.setRotateFun(Rotate_Sqrt_Calculator);
  s.rotate(4);

  return 0;
}
