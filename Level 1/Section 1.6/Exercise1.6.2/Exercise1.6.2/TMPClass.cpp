//===============================================================
// Level 1 Section 1.6 Exercise 1.6.2
// Author: Grant Liu
// Create Date: 1/8/2017
// Description: TMP class - cpp file
//===============================================================
#include"TMPClass.h"
#include<algorithm>

using InputFunction = std::function<double ()>;
using OutputFunction = std::function<void (const std::vector<double>&)>;

TMPClass::TMPClass(std::size_t n, double startValue, InputFunction iFunction, OutputFunction oFunction){
  // Initilize the vector with start value
  vec = std::vector<double>(n, startValue);
  // Modify the vector by multipliing input
  std::transform(vec.begin(), vec.end(), vec.begin(), [&](double& element){ return element * iFunction();});
  // Pass vector to output function
  oFunction(vec);
}
