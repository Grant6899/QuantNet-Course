//===============================================================
// Level 2 Section 2.1 Exercise 2.1.1
// Author: Grant Liu
// Create Date: 1/12/2017
// Description: test class - h file
//===============================================================

#ifndef C_H
#define C_H

#include<iostream>

using namespace std;


class C{// A test class created for type traits testing.
 public:
    int i_data; // public int data member
    static int s_data; // public static data member

    // Here the reason to declare the data member as public is to access it in main
    // function directly. Usually they should be private for better hidden

    C() = default; // Default ctor
    C(int x) { i_data = x;} // Ctor with i_data as parameter
    C(const C& other) { i_data = other.i_data; cout<<"Copy ctor called."<<endl;} // Copy ctor
    C& operator=(const C& other) { i_data = other.i_data; return *this;} // Assignment operator
    ~C() = default; // Destructor

    static double sqr_calculator(double x) { return x * x;} // A static member function that can calculate square of a double
    void print() { cout<<"i_data: "<<i_data<<endl;} // A print function that prints the i_data member
};

int C::s_data = 0;

#endif
