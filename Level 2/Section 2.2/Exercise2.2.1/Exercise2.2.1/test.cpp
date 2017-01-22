//===============================================================
// Level 2 Section 2.2 Exercise 2.2.1
// Author: Grant Liu
// Create Date: 1/13/2017
// Description: main file
//===============================================================
#include<iostream>
#include<vector>
#include<array>
#include"operator.h"

int main(){
  // Double test:
  double d1 = 1, d2 = 2;
  std::cout<<"Addition of d1 and d2: ";
  Print(Addition(d1, d2));
  std::cout<<"Additive Inverse of d1: ";
  Print(Additive_Inv(d1));
  std::cout<<"Scalar Multiplication of -2.5 and d1: ";
  Print(Scalar_Multi(-2.5, d1));

  std::vector<int> v1 {1, 2, 3}, v2 {4, 5, 6};
  std::cout<<"Addition of v1 and v2: ";
  Print(Addition(v1, v2));
  std::cout<<"Additive Inverse of v1: ";
  Print(Additive_Inv(v1));
  std::cout<<"Scalar Multiplication of 2 and v1: ";
  Print(Scalar_Multi(2, v1));

  std::array<double, 4> a1 {1.1, 1.1, 1.1, 1.1}, a2 {2.2, 2.2, 2.2, 2.2} ;
  std::cout<<"Addition of a1 and a2: ";
  Print(Addition(a1, a2));
  std::cout<<"Additive Inverse of a1: ";
  Print(Additive_Inv(a1));
  std::cout<<"Scalar Multiplication of 0.5 and a1: ";
  Print(Scalar_Multi(0.5, a1));
  return 0;
}
