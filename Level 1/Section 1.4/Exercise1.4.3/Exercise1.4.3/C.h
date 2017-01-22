//===============================================================
// Level 1 Section 1.4 Exercise 1.4.3
// Author: Grant Liu
// Create Date: 1/7/2017
// Description: c class - h file
//===============================================================
class C{ // Function object with extra member functions
 private:
  double _data; // double data member
 public:
  C(double data) : _data(data) {} // Constructor with double data
  
  double operator () (double factor){// () operator overloading
    return _data + factor;
  }

  double translate (double factor){// function translate, with one argument
    return _data + factor;
  }

  double translate2 (double factor1, double factor2){ // function translate2, with two arguments
    return _data + factor1 + factor2;
  }

  static double Square(double x) //Static functiom, square calculator
  {
    return x*x;
  }
};
