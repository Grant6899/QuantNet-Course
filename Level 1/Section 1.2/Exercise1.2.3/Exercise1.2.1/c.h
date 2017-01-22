//===============================================================
// Level 1 Section 1.2 Exercise 1.2.3
// Author: Grant Liu
// Create Date: 1/6/2017
// Description: c template class- h file
//===============================================================
#ifndef C_H
#define C_H

#include<vector>
#include<iostream>

using std::vector;
using std::endl;
using std::cout;

//c class template
template<typename T>
class C{
 private:
  vector<T> m_vec;// vector data memeber

  C(const C<T>&) = delete; // Copy constructor marked as deleted
  C& operator=(const C<T>&) = delete; // Assignment operator marked as deleted
 public:
  C() = default; // Default constructor explicitly marked as default
  constexpr explicit C(const vector<T>& vec) { // Constructor with vector, marked as explicit
	  m_vec = vec;
  }
  C(C<T>&& other); // Move constructor
  C<T>& operator=(C<T>&& other); // Move assignment constructor
  ~C(); // Destructor

  void print() noexcept; //Print function, will not throw exception

};

template<typename T>
C<T>::~C(){
    cout<<"Destructor called"<<endl;
  }

template<typename T>
C<T>::C(C<T>&& other) {
	cout << "Move constructor called" << endl;
	m_vec = std::move(other.m_vec);
}


template<typename T>
C<T>& C<T>::operator=(C<T>&& other) {
	cout << "Move assignment operator called" << endl;
	if (&other != this) {
		m_vec = std::move(other.m_vec);
		return *this;
	}
	else return *this;
}


template<typename T>
void C<T>::print() noexcept{
  for(auto it = m_vec.begin();it<m_vec.end();++it)
    cout<<*it<<" ";
  cout<<endl;
}

#endif
