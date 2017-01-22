//===============================================================
// Level 2 Section 2.3 Exercise 2.3.1
// Author: Grant Liu
// Create Date: 1/13/2017
// Description: main file
//===============================================================
#include<iostream>

// a) Deprecated free global function
[[deprecated("Old Func")]]
void Func() {}

// b) Deprecated class A
class[[deprecated("Old A class")]] A{};

// b) Class B with deprecated member function void print()
class B{
public:
    [[deprecated]] void print() { std::cout<< "B Print"<<std::endl;}
};

// c) Deprecated global variable
[[deprecated]] int v = 0;

// d) Deprecated enum
enum [[deprecated]] Color { red, green, blue};

// d) Deprecated enum class
enum class[[deprecated]] Animal {dog, cat, bird};

// e) Deprecated template class

template<typename T>
class [[deprecated]] C{
private:
    T data;
public:
    C(const T& source) : data(source) {}
};

// f) Deprecated lambda function
[[deprecated]] auto lambda = [=]() {std::cout<<"Lambda test\n";};



int main(){
	
    // a) Free function test
    Func();
	
	
    // b) Class test
    A a;
    B b;

    b.print();

    // c) Enum test
    Color color = red;
    Animal animal = Animal::dog;

    // Template class test
    C<int> c(1);

    // Lambda test
    lambda();
	
	// Remark: if this file cannot compile because of these deprecated stuff, please do follow:
	// go to project properties -> Configuration Properties -> C/C++ -> General -> SDL checks -> No.
	
	// The reason is that projects may enable "SDK check" by default now, which treats these warnings as errors. 
    return 0;
}
