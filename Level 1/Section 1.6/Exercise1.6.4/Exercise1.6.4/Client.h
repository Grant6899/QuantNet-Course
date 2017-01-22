//===============================================================
// Level 1 Section 1.6 Exercise 1.6.3
// Author: Grant Liu
// Create Date: 1/8/2017
// Description: client class - h file
//===============================================================
#include<iostream>
#include<algorithm>
#include<list>

//using type alias
template<typename T>
using type = std::list<T, std::allocator<T>>;

template<typename T>
class Client{
 private:
  type<T> data;
 public:
  Client(int n, const T& val) : data(n, val){} //Constructor

  //print content of member data
  void print() const{ 
    std::for_each(data.begin(), data.end(), [](const T& n){
        std::cout<<n<<' ';});
    std::cout<<"\n";
  }

};
