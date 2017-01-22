//===============================================================
// Level 2 Section 2.8 Exercise 2.8.2
// Author: Grant Liu
// Create Date: 1/14/2017
// Description: main file
//===============================================================
#include<iostream>
#include<bitset>

int main(){

    // a) create two bitsets with same size
    std::bitset<5> bs1("10001"), bs2("11110");

    // b) toggle all bits of bs1 and bs2
    std::cout<<"~bs1: "<<~bs1<<std::endl;
    std::cout<<"~bs2: "<<~bs2<<std::endl;

    // c) bitwise XOR, OR and AND operation
    std::cout<<"bs1 ^ bs2: "<<(bs1 ^ bs2)<<std::endl;
    std::cout<<"bs1 | bs2: "<<(bs1 | bs2)<<std::endl;
    std::cout<<"bs1 & bs2: "<<(bs1 & bs2)<<std::endl;

    // d) right and left shift operation
    std::cout<<"bs1<<3: "<<(bs1<<3)<<std::endl;
    std::cout<<"bs2>>2: "<<(bs2>>2)<<std::endl;

    // e) std::hash test:
    std::hash<std::bitset<5>> bs_hash;

    std::cout<<"bs1_hash: "<<bs_hash(bs1)<<std::endl;
    std::cout<<"bs2_hash: "<<bs_hash(bs2)<<std::endl;

    return 0;
}
