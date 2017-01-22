//===============================================================
// Level 2 Section 2.4 Exercise 2.4.1
// Author: Grant Liu
// Create Date: 1/13/2017
// Description: main file
//===============================================================
#include<iostream>
#include<memory>
#include"Point.h"

int main() {

    // a) code below will introduce a memory leak since the memory is not cleand up before an exception is thrown.

    /*try {
        double* d = new double (1.0);
        Point* pt = new Point(1.0, 2.0); // Two-d Point class
        throw -1;
    } catch (const std::exception& e) {
        std::cout<<e.what()<<std::endl;
        }*/



    // b) std::unique_ptr version
    {
    using DoubleUniquePointer = std::unique_ptr<double>;
    using PointUniquePointer = std::unique_ptr<Point>;

    DoubleUniquePointer d(new double (1.0));
    PointUniquePointer pt(new Point(1.0, 2.0)); // Two-d Point class

    // Dereference and call member functions
    *d = 2.0;
    (*pt).X(3.0);       // Modify x coordinate
    (*pt).Y(3.0);       // Modify y coordinate

    // Can use operators for pointer operations
    pt->X(3.0);         // Modify x coordinate
    pt->Y(3.0);         // Modify y coordinate

    // There will be no memory leak if unique_ptr is used. The reason is unique_ptr is a smart pointer, unique_ptr objects automatically delete the object they manage (using a deleter) as soon as they themselves are destroyed, or as soon as their value changes either by an assignment operation or by an explicit call to unique_ptr::reset.
    }

    // c) Experiment with unique_ptr
    {
        using DoubleUniquePointer = std::unique_ptr<double>;

        double* d_ptr = new double(1.0);
        DoubleUniquePointer d_ptr1(d_ptr);
        //DoubleUniquePointer d_ptr2(d_ptr); // This will cause a run time error, because both d_ptr1 and d_ptr2 pointing to the same storage space, after d_ptr1 is destoryed, d_ptr2 will be left pointing to an invalid location.

        DoubleUniquePointer d_ptr3, d_ptr4;

        //d_ptr3 = d_ptr1; // It will not compile because copy assignment (lvalue) is marked deleted.

        d_ptr3 = DoubleUniquePointer(new double (0.0)); // This will compile because RHS is a literal type.
        d_ptr4 = std::move(d_ptr3);

        std::cout<<std::boolalpha << "After transferring: Is d_ptr3 null? "<< (d_ptr3 == nullptr) << ", *d_ptr4 = "<< *d_ptr4<<std::endl;
        }


    return 0;
}
