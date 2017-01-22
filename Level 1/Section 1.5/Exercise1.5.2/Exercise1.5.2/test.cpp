//===============================================================
// Level 1 Section 1.5 Exercise 1.5.2
// Author: Grant Liu
// Create Date: 1/8/2017
// Description: main file
//===============================================================
#include<tuple>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
#include<complex>
#include"Calculator.h"

//Namespace declaration
using std::tuple;
using std::get;
using std::cout;
using std::endl;
using std::complex;



int main(){


  //Built-in type tests:

  cout<<"tuple<double, double, double> test:"<<endl<<"source = {6.0, 5.1, 6.9}"<<endl;

  tuple<double, double, double> tup1 {6.0, 5.1, 6.9};

  cout<<"Sum:"<<Calculator<double, decltype(tup1), 3>::Sum(tup1)<<endl;
  cout<<"Average:"<<Calculator<double, decltype(tup1), 3>::Average(tup1)<<endl;
  cout<<"Maximum:"<<Calculator<double, decltype(tup1), 3>::Maximum(tup1)<<endl;

  //Complex tests:
  cout<<"tuple<complex<int>, complex<int>, complex<int>> test:"<<endl;
  cout<<"source = {(2, 2), (-1, -3), (5, 1)}"<<endl;
  complex<int> c1(2, 2), c2(-1, -3), c3(5, 1);
  tuple<complex<int>, complex<int>, complex<int>> tup2 {c1, c2, c3};

  cout<<"Sum:"<<Calculator<complex<int>, decltype(tup2), 3>::Sum(tup2)<<endl;
  cout<<"Average:"<<Calculator<complex<int>, decltype(tup2), 3>::Average(tup2)<<endl;

  return 0;
}
