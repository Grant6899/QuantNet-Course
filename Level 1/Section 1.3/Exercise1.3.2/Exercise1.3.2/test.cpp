//===============================================================
// Level 1 Section 1.3 Exercise 1.3.2
// Author: Grant Liu
// Create Date: 1/6/2017
// Description: main file
//===============================================================
#include<iostream>
#include<array>
#include"Shape.h"
#include"Point.h"
#include"Line.h"
#include"Circle.h"
#include"Valve.h"

using std::array;
using std::cout;
using std::endl;

//terminating rotate function template
template<typename T>
void rotate(double factor_d, T obj){
  obj.rotate(factor_d);
}

//rotate function variadic template
template<typename T, typename... Args>
void rotate(double factor_d, T first, Args... rest){
  first.rotate(factor_d);
  rotate(factor_d, rest...);
}


int main(){

  // initialize objects
  Circle circle;
  Line line;
  Valve valve;

  double factor = 2.0;

  // We can in essence create compile-time aggregates/whole
  // part objects on the fly. We only need to write one function.

  rotate(factor, circle);
  rotate(factor, circle, line);
  rotate(factor, circle, valve);
  rotate(factor*2, circle, valve, line);

  cout<<endl;

  // An alternative way of doing it
  cout<<"Alternative test:"<<endl;
  array<Shape*, 5> shapeList = {&circle, &line, &circle, &circle, &line};

  double factor2 = 20.0;
  for (auto& elem : shapeList){
    elem->rotate(factor2);
  }

  // We cannot include valves in this array because when we decare the array as a 
  // shape pointer array. Since circle and line are both shape's derived classes, 
  // we can definately include them here. However, valve is an unrelated class to shape, 
  // there is no way we can put any valve objects into this array.

  // Varaidc approach is a different story. Essentially it's using a template function, 
  // which means it can accept any object regardless of its type.


  return 0;
}
