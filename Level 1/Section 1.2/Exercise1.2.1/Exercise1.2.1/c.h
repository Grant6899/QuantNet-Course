//===============================================================
// Level 1 Section 1.2 Exercise 1.2.1
// Author: Grant Liu
// Create Date: 1/5/2017
// Description: class template c - h file
//===============================================================
#ifndef C_H
#define C_H


#include<vector>
#include<iostream>

using std::vector;
using std::endl;
using std::cout;

// class C's definition
template<typename T>
class C{
 private:
  vector<T> m_vec; //vector data member

  C(const C<T>&) = delete; // Copy constructor marked as deleted
  C& operator=(const C<T>&) = delete; // Assignment operator marked as deleted
 public:
  C() = default; // Default constructor explicitly marked as default
  constexpr explicit C(const vector<T>& vec) { // explicit constexpr constructor, with vector as input argument
	  m_vec = vec;
  }
  ~C(); // Destructor

  void print() noexcept; // Print member function, will not throw exception

};

template<typename T>
C<T>::~C(){
    cout<<"Destructor called"<<endl;
  }

template<typename T>
void C<T>::print() noexcept{
  for(auto it = m_vec.begin();it<m_vec.end();++it)
    cout<<*it<<" ";
  cout<<endl;
}

#endif // !C_H
