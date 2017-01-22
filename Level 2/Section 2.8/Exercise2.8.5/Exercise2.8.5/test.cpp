//===============================================================
// Level 2 Section 2.8 Exercise 2.8.5
// Author: Grant Liu
// Create Date: 1/14/2017
// Description: main file
//===============================================================
#include<iostream>
#include"BitMatrix.h"

int main(){

    // ctor tests:
    BitMatrix<3,3> bm1 ("101"), bm2 ("100"), bm3;

    std::cout<<"bm1:\n";
    bm1.print();

    std::cout<<"bm2:\n";
    bm2.print();

    std::cout<<"bm3:\n";
    bm3.print();

    // set/reset, flip, none/any/all test:
    bm3.set();
    std::cout<<"after set, bm3:\n";
    bm3.print();

    bm2.reset(1);
    std::cout<<"after reset(1), bm2:\n";
    bm2.print();

    bm1.flip();
    std::cout<<"after flip, bm1:\n";
    bm1.print();

    std::cout<<std::boolalpha;
    std::cout<<"bm1.all() = "<< bm1.all() << '\n';
    std::cout<<"bm2.none(1) = "<< bm2.none(1) << '\n';
    std::cout<<"bm1.any(2) = "<< bm1.any(2) << '\n';

    // Access elements:
    std::cout<<"bm1[1] = "<<bm1[1]<<'\n';

    // count test:
    std::cout<<"bm2.count() = "<<bm2.count()<<'\n';

    // OR, XOR, AND operation
    std::cout<<"bm1 & bm2:\n";
    (bm1 & bm2).print();
    std::cout<<"bm1 | bm3:\n";
    (bm1 | bm3).print();
    std::cout<<"bm2 ^ bm3:\n";
    (bm2 ^ bm3).print();

    return 0;
}
