//===============================================================
// Level 1 Section 1.4 Exercise 1.4.3
// Author: Grant Liu
// Create Date: 1/7/2017
// Description: main file
//===============================================================
#include<functional>
#include"C.h"
#include<iostream>

using std::cout;
using std::endl;

// Type alias
template<typename T>
using FunctionType = std::function<T (const T& t)>;

template<typename T>
using FunctionType2 = std::function<T (const T& t1, const T& t2)>;

int main(){

  using namespace std::placeholders;

  //a) Bind the function wrapper to C's static member function.

  FunctionType<double> c_Square = std::bind(&C::Square, _1);

  //b) Bind the function wrapper to C's member function.

  C c(2);

  FunctionType<double> c_translate = std::bind(&C::translate, c, _1);
  FunctionType2<double> c_translate2 = std::bind(&C::translate2, c, _1, _2);

  //c) Test these functions

  cout<<"Static test: c_Square(3) = "<<c_Square(3)<<"\n\n";

  cout<<"Member function test:"<<endl;
  cout<<"c_translate(3) = "<<c_translate(3)<<endl;
  cout<<"c_translate2(4, 5) = "<<c_translate2(4, 5)<<endl;


  return 0;
}
