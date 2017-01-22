//===============================================================
// Level 2 Section 2.8 Exercise 2.8.4
// Author: Grant Liu
// Create Date: 1/14/2017
// Description: main file
//===============================================================
#include<iostream>
#include<vector>
#include<bitset>

// b) Intersection function
std::vector<bool> intersect(const std::vector<bool>& lhs, const std::vector<bool>& rhs){
    std::vector<bool> result;

    for(auto it = lhs.begin(); it<lhs.end(); ++it)
        // if corresponding element are same, push true else push false
        if (*it == rhs.at(it-lhs.begin())) result.push_back(true);
        else result.push_back(false);

    return result;
}


int main(){

    // a) Comparison:
    // std::vector<bool> is a dynamic vector of boolean type data, it's easy to apply vector's attributes. It doesn't overload operator~，|, &, ^ and binary shift operators <<, >> to do bitset-specific operations. Besides oprators, std::vector<bool> doesn't have bitset-specific member functions such as flip(), count(). It lacks constructor from string, unsigned long, unsigned long long as well.

    // std::bitset is fixed size, it's not flexiable as std::vector<bool> or boost::dynamic_bitset<>. boost::dynamic_bitset<> is also dynamic, and it's pretty standard, it has almost all operator and functions overloaded from std::bitset.


    // b) Intersect function test:
    std::vector<bool> vb1 {1,0,0,1}, vb2 {1,0,1,1};

    std::vector<bool> intersection = intersect(vb1, vb2);

    for (auto it = intersection.begin(); it<intersection.end(); ++it)
        std::cout<<*it;
    std::cout<<'\n';

    return 0;
}
