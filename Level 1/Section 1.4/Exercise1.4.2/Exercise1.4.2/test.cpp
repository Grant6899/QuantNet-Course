//===============================================================
// Level 1 Section 1.4 Exercise 1.4.2
// Author: Grant Liu
// Create Date: 1/7/2017
// Description: main file
//===============================================================
#include<functional>
#include<iostream>

using std::cout;
using std::endl;

//test function
double freeFunction3(double x, double y, double z){
  //The following prints are for convenience to check x, y, z's value
  cout<<"x :"<<x<<endl;
  cout<<"y :"<<y<<endl;
  cout<<"z :"<<z<<endl;
  return x + y + z;
}

int main(){

  using namespace std::placeholders;

  //Placeholders _1, _2, ... must be used one by one. 
  // In other words, you cannot use _3 without _1 and _2 have been used. 
  // And their order in std::bind's argument list also matters. The known 
  // aruguments occupies the place where it takes.

  auto f3 = std::bind(freeFunction3, _2, _3, _1);
  cout<<f3(1, 2, 3)<<endl;
  //In this case, we created a new functional entity f3, and passed actual value 1, 2 ,3 
  // into it. Here we modified the placeholders' order. In fact, it will return 2 + 3 + 1.

  auto f2 = std::bind(freeFunction3, _1, 30, _2);
  cout<<f2(1, 2)<<endl;
  //For the two arities case, we fixed the second original argument as 30 and 
  //passed 1 and 2 as first and third argument respectively, it will 
  // return 1 + 30(fixed) + 2.

  auto f1 = std::bind(freeFunction3, _1, 10, 20);
  cout<<f1(2)<<endl;
  //For one arity case, the last two arguments are fixed as 10 and 20. We pass 2 as 
  //its first argument, it will return 2 + 10 + 20.

  auto f2_v1 = std::bind(f3, 4, _1, _2);
  cout<<f2_v1(2, 3)<<endl;
  //To better understand std::bind, here is a case for nested binding. f3 is already 
  //binded from the original freeFunction3.
  //First, it will essensially call f3(4, 2, 3), which is actually freeFunction3(2, 3, 4). 
  //Thus, will return 2 + 3 + 4.

  return 0;
}
