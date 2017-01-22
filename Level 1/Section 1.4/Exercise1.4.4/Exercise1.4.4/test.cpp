//===============================================================
// Level 1 Section 1.4 Exercise 1.4.4
// Author: Grant Liu
// Create Date: 1/7/2017
// Description: main file
//===============================================================
#include"Shape.h"
#include"Point.h"
#include"Circle.h"
#include<iostream>
#include<functional>

using std::cout;
using std::endl;

//type alias
using VoidFunctionType = std::function<void (double)>;

int main(){

//Define two functions for function member in class
VoidFunctionType rotate_shape = [](double x){ cout<<"s\n";};
VoidFunctionType rotate_circle = [](double x){ cout<<"c\n";};

//Declare several object with functor constructors, and call function rotate. 
Shape s1(rotate_shape);
s1.rotate(1);

Circle c1(rotate_circle);
c1.rotate(2);

Shape* c2 = new Circle(rotate_circle);
c2->rotate(1.4);


return 0;
}
