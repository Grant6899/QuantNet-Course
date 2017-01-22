//===============================================================
// Level 1 Section 1.3 Exercise 1.3.1
// Author: Grant Liu
// Create Date: 1/6/2017
// Description: main file
//===============================================================
#include<iostream>
#include<bitset>

using std::cout;
using std::endl;

//b) Create the termination/tail function, that is the print function accepting a single input argument.
template<typename T>
void print(const T& last){
  cout<<"parameter: "<<last<<endl;
  cout<<"Last parameter printed"<<endl;
}

//a) Create the template variadic function with its parameter pack.
template<typename T, typename... Args>
void print(const T& first,const  Args&... rest){
  cout<<"parameter: "<<first<<endl;
  print(rest...);
}


int main(){
  //c) Test the funtion
  int j = 1; double d = 2.0;
  print(j); print(d);
  print(j, d); print(d, j);
  std::cout << "\n3 params \n";
  print(d, j, std::bitset<8>(233));

  //my own test
  print("aa", 3, 5.6);

  return 0;
}
