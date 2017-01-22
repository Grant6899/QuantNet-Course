//===============================================================
// Level 1 Section 1.2 Exercise 1.2.2
// Author: Grant Liu
// Create Date: 1/5/2017
// Description: main file
//===============================================================
#include<string>
#include<vector>
#include<iostream>
#include<utility>
#include<algorithm>
#include<chrono>

using namespace std;

//Swap function in copy style
template<typename T>
void SwapCopyStyle(T& a, T& b){ // Swap a and b in copying way; temporary object needed
  T tmp(a);
  a = b;
  b = tmp;
}
// Within this SwapCopyStyle, the number of temporary objects depends on the signature of T's assignment oprator.
// For the most populor signature like, T& operator=(const T&), it will not create any tempororay obj because it's always
// passing references. However, if the signature requires coping, it will create more tempororay obj. 

//Swap function in move style
template<typename T>
void SwapMoveStype(T& a, T& b){
  T tmp = std::move(a);
  a = std::move(b);
  b = std::move(tmp);
}

int main(){

  //a) string test
  //Declare two strings
  string s1 = "String_1", s2;

  cout<<"before moving, s1 = \""<<s1<<"\"  s2 = \""<<s2<<"\""<<endl;

  s2 = std::move(s1);
  //check source and target string after moving
  cout<<"after moving, s1 = \""<<s1<<"\"  s2 = \""<<s2<<"\""<<endl<<endl;


  //b) vector test

  auto print = [](auto element){cout<<element<<" ";};

  //Declare two vectors
  vector<int> vec1 = {1, 2, 3}, vec2, vec3;
  cout<<"before moving, v1 = {";
  for_each(vec1.begin(), vec1.end(), print);
  cout<<"} v2 = {";
  for_each(vec2.begin(), vec2.end(), print);
  cout<<"}"<<endl;

  //Declare time-related varialbes to calculate time consumption
  std::chrono::time_point<std::chrono::system_clock> start_copy, end_copy, start_move, end_move;
  std::chrono::duration<double> copy_time, move_time;
  
  //Copy and move the vector, calculate the time they consumed respectively
  start_copy = std::chrono::system_clock::now();
  vec3 = vec1;
  end_copy = std::chrono::system_clock::now();

  start_move = std::chrono::system_clock::now();
  vec2 = std::move(vec1);
  end_move = std::chrono::system_clock::now();

  //Print the contents of vectors
  cout<<"after moving, v1 = {";
  for_each(vec1.begin(), vec1.end(), print);
  cout<<"} v2 = {";
  for_each(vec2.begin(), vec2.end(), print);
  cout<<"}"<<endl;

  //Print execution time for copy and move operations
  copy_time = end_copy - start_copy;
  move_time = end_move - start_move;
  cout<<"Copy execution time: "<<copy_time.count()<<"s"<<endl;
  cout<<"Move execution time: "<<move_time.count()<<"s"<<endl;

  //c) Swap test
  cout << "\nLarge vector swap test:" << endl;;

  //Declare large vectors
  for(int i=0;i<1000000;++i){
    vec1.push_back(i);
    vec2.push_back(1000000-i);
  }

 //Copy and move the vector, calculate the time they consumed respectively
 start_copy = std::chrono::system_clock::now();
 SwapCopyStyle(vec1, vec2);
 end_copy = std::chrono::system_clock::now();

 start_move = std::chrono::system_clock::now();
 SwapMoveStype(vec2, vec1);
 end_move = std::chrono::system_clock::now();

 //Print execution time for copy and move operations
 copy_time = end_copy - start_copy;
 move_time = end_move - start_move;
 cout << "Copy execution time: " << copy_time.count() << "s" << endl;
 cout << "Move execution time: " << move_time.count() << "s" << endl;
 
 return 0;

}
