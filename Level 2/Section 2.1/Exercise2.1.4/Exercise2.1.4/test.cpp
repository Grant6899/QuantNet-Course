//==============================================================
// Level 2 Section 2.1 Exercise 2.1.3
// Author: Grant Liu
// Create Date: 1/12/2017
// Description: shape class - cpp file
//===============================================================

#include<iostream>
#include<type_traits>
#include"Shape.h"
#include"Point.h"
#include"Point1.h"
#include"Point2.h"

int main(){

  std::cout<<std::boolalpha;
  // a) Virtual destructor test:
  std::cout<< "Does Point have a virtual destructor? "<<std::has_virtual_destructor<Point>::value<<"\n\n";

  // Original version:
  std::cout<<"Origianl version output:\n";
  // b) Constructor test:
  std::cout<< "Does Point have a default constructor? "<<std::is_default_constructible<Point>::value<<'\n';
  std::cout<< "Does Point have a copy constructor? "<<std::is_copy_constructible<Point>::value<<'\n';
  std::cout<< "Does Point have a move constructor? "<<std::is_move_constructible<Point>::value<<'\n';

  // c) Assignablity test:
  std::cout<< "Is Point copy assignable? "<<std::is_copy_assignable<Point>::value<<'\n';
  std::cout<< "Is Point move assignable? "<<std::is_move_assignable<Point>::value<<"\n\n";

  // Second version:
  std::cout<<"Second version(Point1) output:\n";
  // b) Constructor test:
  std::cout<< "Does Point1 have a default constructor? "<<std::is_default_constructible<Point1>::value<<'\n';
  std::cout<< "Does Point1 have a copy constructor? "<<std::is_copy_constructible<Point1>::value<<'\n';
  std::cout<< "Does Point1 have a move constructor? "<<std::is_move_constructible<Point1>::value<<'\n';

  // c) Assignablity test:
  std::cout<< "Is Point1 copy assignable? "<<std::is_copy_assignable<Point1>::value<<'\n';
  std::cout<< "Is Point1 move assignable? "<<std::is_move_assignable<Point1>::value<<"\n\n";

  // Third version:
  std::cout<<"Third version(Point2) output:\n";
  // b) Constructor test:
  std::cout<< "Does Point2 have a default constructor? "<<std::is_default_constructible<Point2>::value<<'\n';
  std::cout<< "Does Point2 have a copy constructor? "<<std::is_copy_constructible<Point2>::value<<'\n';
  std::cout<< "Does Point2 have a move constructor? "<<std::is_move_constructible<Point2>::value<<'\n';

  // c) Assignablity test:
  std::cout<< "Is Point2 copy assignable? "<<std::is_copy_assignable<Point2>::value<<'\n';
  std::cout<< "Is Point2 move assignable? "<<std::is_move_assignable<Point2>::value<<'\n';


  return 0;
}
