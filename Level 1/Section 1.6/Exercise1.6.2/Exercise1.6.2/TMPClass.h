//===============================================================
// Level 1 Section 1.6 Exercise 1.6.2
// Author: Grant Liu
// Create Date: 1/8/2017
// Description: TMP class - h file
//===============================================================
#include<vector>
#include<iostream>
#include<functional>

using InputFunction = std::function<double ()>;
using OutputFunction = std::function<void (const std::vector<double>&)>;

class TMPClass{// A template method pattern class
 private:
  std::vector<double> vec;
  InputFunction input_fun; 
  OutputFunction output_fun;

 public:
  TMPClass(std::size_t n, double startValue, InputFunction iFunction, OutputFunction oFunction);
};
