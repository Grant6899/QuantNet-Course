//===============================================================
// Level 1 Section 1.6 Exercise 1.6.4
// Author: Grant Liu
// Create Date: 1/8/2017
// Description: main file
//===============================================================
#include<iostream>
#include"Client.h"

int main(){
  int n = 10,  val = 2;
  //Initialize a Client object with n =10 and val = 2
  Client<int> myClient(n, val);
  myClient.print();

  return 0;
}
