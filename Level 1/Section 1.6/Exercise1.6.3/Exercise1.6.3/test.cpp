//===============================================================
// Level 1 Section 1.6 Exercise 1.6.3
// Author: Grant Liu
// Create Date: 1/8/2017
// Description: main file
//===============================================================
#include<iostream>
#include"B.h"


int main(){
  //B b1 = 1;         // (a) will not compile, use initilization below or (b) instead
  B b1 = B(1);        // call explicit B(int) and copy constructor
  B b2(3);            // (b) calls explicit B(int)
  B b3{ 7,3 };        // (c) uses uniform initilization, essentially call explict B(int, int)
  B b4 = (B)42;       // (d) calls explicit B(int), equal to B(42), then assign it to b4.

  return 0;
}
