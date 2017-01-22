//===============================================================
// Level 1 Section 1.2 Exercise 1.2.1
// Author: Grant Liu
// Create Date: 1/5/2017
// Description: main file
//===============================================================
#include<iostream>
#include"c.h"

int main(){

  C<int> c1;
  // C<int> c2 = c1; //Will not compile because copy constructor explicitly marked deleted

  C<int> c3;
  //c3 = c1; //Will not compile because assignment operator explicitly marked deleted

  vector<int> v1 = {1, 2, 3};

  //C<int> c4 = v1; //This will compile if not deleting copy constructor and not declaring
  //C(const vector<T>&) 'explicit', but will not compile if not deleting copy constructor 
  //and declaring C(const vector<T>&) 'explicit' because it doesn't allow implicit conversion.

 
  C<int> c5(v1); // This compiles because it explictly initialzes a C object c5 with a vector.
                 // Also c5's data member will be known at compile time because it's constexpr
                 // constructor.

  c5.print(); // This print function will now throw any exception.

  vector<int> v2 = {4, 5, 6};

  c5.print();

  return 0;
}
