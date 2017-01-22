//===============================================================
// Level 2 Section 2.1 Exercise 2.1.1
// Author: Grant Liu
// Create Date: 1/12/2017
// Description: main file
//===============================================================

#include<iostream>
#include<type_traits>
#include<memory>
#include"c.h"

using std::cout;
using std::endl;

//a) Function template that will tell the pointer type of passed argument t.
template<typename T>
void PointerTeller(const T& t){
    if (std::is_pointer<T>::value)
        cout<<"This is a pointer type argument."<<endl;
    else
        cout<<"_not_ a pointer type argument."<<endl;

    if (std::is_null_pointer<T>::value)
        cout<<"This is a nul pointer type argument."<<endl;
    else
        cout<<"_not_ a null pointer type argument."<<endl;
}

//b) Funtion template for type telling of member function and non-static member object pointer
template<typename T>
void TypeTeller(const T& t){
    if (std::is_member_function_pointer<T>::value)
        cout<<"This is a non-static member function pointer argument."<<endl;
    else
        cout<<"_not_ a non-static member function pointer type argument."<<endl;

    if (std::is_member_object_pointer<T>::value)
        cout<<"This is a non-static member object pointer argument."<<endl;
    else
        cout<<"_not_ a non-static member object pointer argument."<<endl;
}



int main(){

    // a) function tests:

    // Test a raw pointer:
    cout<<"Test a raw pointer:"<<endl;
    int* ptr1 = new int(1);// Int raw pointer creation
    PointerTeller(ptr1);
    delete ptr1;// Release memory
    cout<<endl;
    // Test a raw pointer equal to nullptr:
    cout<<"Test a null raw pointer:"<<endl;
    int* ptr2 = nullptr;// Int null raw pointer creation
    PointerTeller(ptr2);
    delete ptr2;// Release memory
    cout<<endl;
    // Test a null pointer:
    cout<<"Test a nullptr:"<<endl;
    PointerTeller(nullptr);
    cout<<endl;
    // Test a lvalue reference:
    // To avoid the type deducution, I put the reference judging out of the function template.
    cout<<"Test lvalue and rvalue references:"<<endl;
    int x = 3;// lvalue

    int& x1 = x;// lvalue reference
    if (std::is_lvalue_reference<decltype(x1)>::value)
        cout<<"This is a lvalue reference."<<endl;

    int&& x2 = std::move(x); // rvalue reference
    if (std::is_rvalue_reference<decltype(x2)>::value)
        cout<<"This is a rvalue reference."<<endl;
    // Question: here we also give this rvalue a name 'x2' and it still works. According what I was told on the fourm, it should already be a lvalue? The point is I cannot tell the difference between this case and template function case(with T&&) since they both have a value holder.

    cout<<endl;

    // b) tests:

    // The requirement of b should be:
    // Determine if a type is a non-static member function pointer or if it is a
    // pointer to a non-static member object.

    // Test a non-static member function:
    cout<<"Test a non-static member function:"<<endl;
    TypeTeller(&C::print);
    cout<<endl;

    // Test a static member function:
    cout<<"Test a static member function:"<<endl;
    TypeTeller(&C::sqr_calculator);
    cout<<endl;

    // Test a non-static member object:
    cout<<"Test a non-static member object:"<<endl;
    TypeTeller(&C::i_data);
    cout<<endl;

    // Test a static member function:
    cout<<"Test a static member function:"<<endl;
    TypeTeller(&C::s_data);
    cout<<endl;

    // c) tests:

    shared_ptr<int> s_ptr(new int(0));

    cout<<"Is a shared pointer a pointer type?"<<endl;
    cout<<std::boolalpha<<std::is_pointer<decltype(s_ptr)>::value<<endl;

    cout<<"Is it a pointer type when converted to a raw pointer?"<<endl;
    cout<<std::boolalpha<<std::is_pointer<decltype(s_ptr.get())>::value<<endl;

    return 0;
}
