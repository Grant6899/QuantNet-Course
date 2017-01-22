//===============================================================
// Level 2 Section 2.4 Exercise 2.4.3
// Author: Grant Liu
// Create Date: 1/14/2017
// Description: main file
//===============================================================
#include<iostream>
#include<memory>

int main(){

    // a) code below has run-time error because no two auto_ptr objects should own the same element, since both would try to destruct them at some point.

    /*
    using std::auto_ptr;
    // Define auto_ptr pointers instead of raw pointers
    std::auto_ptr <double> d(new double (1.0));

    // Dereference
    *d = 2.0;

    // Change ownership of auto_ptr
    // (after assignment, d is undefined)
    auto_ptr <double> d2 = d;
    //When an assignment operation takes place between two auto_ptr objects, ownership is transferred, which means that the object losing ownership is set to no longer point to the element (it is set to the null pointer).

    *d2 = 3.0;

    std::cout <<"Auto values: "<< *d.get() <<", "<< *d2.get();
    // Here d is already nullptr.
    */

    // b)
      using std::auto_ptr;
      // Define unique_ptr pointers instead of auto_ptr
      std::unique_ptr <double> d(new double (1.0));

      // Dereference
      *d = 2.0;

      // Change ownership of auto_ptr
      // (after assignment, d is undefined)
      std::unique_ptr <double> d2(new double); // lvalue assignment is deleted

      *d2 = 3.0;

      std::cout <<"Auto values: "<< *d.get() <<", "<< *d2.get() << '\n';
    return 0;
}
