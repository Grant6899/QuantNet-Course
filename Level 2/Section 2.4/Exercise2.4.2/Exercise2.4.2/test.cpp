//===============================================================
// Level 2 Section 2.4 Exercise 2.4.2
// Author: Grant Liu
// Create Date: 1/13/2017
// Description: main file
//===============================================================
#include<iostream>
#include<memory>
#include"Base.h"

class C1{
private:
    std::shared_ptr<double> d;
public:
    C1(std::shared_ptr<double> value) : d(value) {}
    virtual ~C1() { std::cout <<"C1 destructor\n";}
    void print() const { std::cout <<"Value "<<*d; }
};

class C2{
private:
    std::shared_ptr<double> d;
public:
    C2(std::shared_ptr<double> value) : d(value) {}
    virtual ~C2() { std::cout <<"C2 destructor\n";}
    void print() const { std::cout <<"Value "<<*d; }
};

int main(){

    // b)
    std::shared_ptr<double> d_ptr (new double(0.0));
    {
        std::cout<<"d_ptr.use_count(): "<<d_ptr.use_count()<<std::endl; //1

        C1 c1_1(d_ptr);
        std::cout<<"d_ptr.use_count(): "<<d_ptr.use_count()<<std::endl; //2

        std::shared_ptr<C1> c1_ptr1 (new C1(d_ptr));
        std::cout<<"d_ptr.use_count(): "<<d_ptr.use_count()<<std::endl; //3

    }
    std::cout<<"d_ptr.use_count(): "<<d_ptr.use_count()<<"\n"; //1 (c1_1, c1_ptr1 destroyed)

    std::shared_ptr<double> d1_ptr (new double(1.0));
    //swap base_ptr and base_ptr4 back:
    swap(d_ptr, d1_ptr);
    std::cout<<"*d_ptr: "<<*d_ptr<<std::endl;//1
    std::cout<<"*d1_ptr: "<<*d1_ptr<<"\n";//0

    std::cout<<std::boolalpha<<"Is d_ptr unique? "<<d_ptr.unique()<<std::endl;//1
    std::cout<<"Is d1_ptr unique? "<<d1_ptr.unique()<<"\n";//0

    // Give up ownership and reinitialize as empty
    d_ptr.reset();
    if (d_ptr)
        std::cout << "d_ptr points to " << *d_ptr << '\n';
    else
        std::cout << "d_ptr is empty\n\n";

    // c)
    std::shared_ptr<Base> base_ptr (new Base);
    {
        std::cout<<"base_ptr.use_count(): "<<base_ptr.use_count()<<std::endl;//1

        Base b1(*base_ptr);
        std::cout<<"base_ptr.use_count(): "<<base_ptr.use_count()<<std::endl;//1, b1 gets a new storage whose value is same as *base_ptr.

        std::shared_ptr<Base> base_ptr1(base_ptr);
        std::cout<<"base_ptr.use_count(): "<<base_ptr.use_count()<<std::endl;//2

        std::shared_ptr<Base> base_ptr2 = base_ptr; // copy ctor called
        std::cout<<"base_ptr.use_count(): "<<base_ptr.use_count()<<std::endl;//3
        std::cout<<"base_ptr2.use_count(): "<<base_ptr2.use_count()<<std::endl;//3
        // a copy of a pointer is like an alias, the have same use_count()

        std::shared_ptr<Base> base_ptr3;
        base_ptr3 = base_ptr; // assignment called
        std::cout<<"base_ptr.use_count(): "<<base_ptr.use_count()<<std::endl;//4
        std::cout<<"base_ptr3.use_count(): "<<base_ptr3.use_count()<<std::endl;//4
        // similar function as copy ctor

    }
    std::cout<<"base_ptr.use_count(): "<<base_ptr.use_count()<<std::endl; //1, base_ptr1, base_ptr2, base_ptr3 destroyed

    std::shared_ptr<Base> base_ptr4(std::move(base_ptr)); // transfer ownership
    std::cout<<"base_ptr.use_count(): "<<base_ptr.use_count()<<std::endl;//0, moved
    std::cout<<"base_ptr4.use_count(): "<<base_ptr4.use_count()<<std::endl;//1, get use count from ptr.


    // d) added above.


    return 0;
}
