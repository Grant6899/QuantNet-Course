//===============================================================
// Level 1 Section 1.6 Exercise 1.6.2
// Author: Grant Liu
// Create Date: 1/8/2017
// Description: main file
//===============================================================
#include<vector>
#include<iostream>
#include<algorithm>
#include"TMPClass.h"

using std::cout;
using std::endl;

int main(){
  //An input device produces a hard-coded value
  auto i_fun = [](){ return 2;};

  //An output device where a range-based loop applied to the modified vector
  auto o_fun = [](const std::vector<double>& v){ 
	  for(double element : v)
		  cout<<element<<" "; 
	  cout<<endl;
  };

  TMPClass t(10, 3, i_fun, o_fun);

  return 0;
}
