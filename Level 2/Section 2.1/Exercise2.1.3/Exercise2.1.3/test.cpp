//===============================================================
// Level 2 Section 2.1 Exercise 2.1.3
// Author: Grant Liu
// Create Date: 1/12/2017
// Description: Shape class - h file
//===============================================================

#include<iostream>
#include<type_traits>
#include"Base.h"
#include"Shape.h"
#include"Point.h"

int main(){

  std::cout << std::boolalpha;
  // a)
  // Empty test:
  std::cout << "Is Base empty? "<<std::is_empty<Base>::value << '\n';
  std::cout << "Is Shape empty? "<<std::is_empty<Shape>::value << '\n';
  std::cout << "Is Point empty? "<<std::is_empty<Point>::value << "\n\n";

  // Polymorphic test:
  std::cout << "Is Base polymorphic? "<<std::is_polymorphic<Base>::value << '\n';
  std::cout << "Is Shape polymorphic? "<<std::is_polymorphic<Shape>::value << '\n';
  std::cout << "Is Point polymorphic? "<<std::is_polymorphic<Point>::value << "\n\n";

  // Abstract test:
  std::cout << "Is Base abstract? "<<std::is_abstract<Base>::value << '\n';
  std::cout << "Is Shape abstract? "<<std::is_abstract<Shape>::value << '\n';
  std::cout << "Is Point abstract? "<<std::is_abstract<Point>::value << "\n\n";

  // b) Same test:
  std::cout<< "Are Base and Shape same? "<<std::is_same<Base, Shape>::value<<'\n';
  std::cout<< "Are Base and Point same? "<<std::is_same<Base, Point>::value<<'\n';
  std::cout<< "Are Shape and Point same? "<<std::is_same<Shape, Point>::value<<"\n\n";
  // Any two of these three classes are not same.

  // c) Base/Derived test:
  std::cout<< "Is Shape base class of Point? "<<std::is_base_of<Shape, Point>::value<<'\n';
  std::cout<< "Is Point base class of Shape? "<<std::is_base_of<Point, Shape>::value<<'\n';
  std::cout<< "Is Base base class of Point? "<<std::is_base_of<Base, Point>::value<<"\n\n";


  // d) Convertable test:
  std::cout<< "Can Base be converted to Shape? "<<std::is_convertible<Base, Shape>::value<<'\n';
  std::cout<< "Can Shape be converted to Base? "<<std::is_convertible<Shape, Base>::value<<'\n';
  std::cout<< "Can Base be converted to Point? "<<std::is_convertible<Base, Point>::value<<'\n';
  std::cout<< "Can Point be converted to Base? "<<std::is_convertible<Point, Base>::value<<'\n';
  std::cout<< "Can Point be converted to Shape? "<<std::is_convertible<Point, Shape>::value<<'\n';
  std::cout<< "Can Shape be converted to Point? "<<std::is_convertible<Shape, Point>::value<<'\n';

  std::cout<< "Can Point* be converted to Shape*? "<<std::is_convertible<Point*, Shape*>::value<<'\n';

  return 0;
}
