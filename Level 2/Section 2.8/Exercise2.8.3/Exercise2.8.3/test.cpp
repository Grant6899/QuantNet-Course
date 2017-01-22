//===============================================================
// Level 2 Section 2.8 Exercise 2.8.3
// Author: Grant Liu
// Create Date: 1/14/2017
// Description: main file
//===============================================================
#include<iostream>
#include<climits>
#include"boost/dynamic_bitset.hpp"

int main(){

    // a)
    // create dynamic bitsets
    boost::dynamic_bitset<> bs1(10, 7);
    std::cout<<bs1<<'\n';

    boost::dynamic_bitset<> bs2(10,20);

    std::cout<<"bs1: "<<bs1<<'\n';
    std::cout<<"bs2: "<<bs2<<'\n';

    // set, reset test:
    bs1.set();
    std::cout<<"after bs1.set(), bs1: "<<bs1<<'\n';
    bs1.reset();
    std::cout<<"after bs1.reset(), bs1: "<<bs1<<'\n';

    // flip test:
    bs2.flip();
    std::cout<<"after bs2.flip(), bs2: "<<bs2<<'\n';

    // all, any, none test
    std::cout<<std::boolalpha;
    std::cout<<"bs1.all(): "<<bs1.all()<<'\n';
    std::cout<<"bs1.any(): "<<bs1.any()<<'\n';
    std::cout<<"bs1.none(): "<<bs1.none()<<'\n';

    std::cout<<"bs2.all(): "<<bs2.all()<<'\n';
    std::cout<<"bs2.any(): "<<bs2.any()<<'\n';
    std::cout<<"bs2.none(): "<<bs2.none()<<'\n';

    // access element
    std::cout<<"bs2[2]: "<<bs2[2]<<'\n';

    // count test:
    std::cout<<"bs2.count(): "<<bs2.count()<<'\n';


    // conversion from bitset to string
    std::string str_bs2;
    to_string(bs2, str_bs2);

    // comparison
    boost::dynamic_bitset<> bs3(bs2);

    std::cout<<"bs2: "<<bs2<<'\n';
    std::cout<<"bs3: "<<bs3<<'\n';

    std::cout<<"Is bs2 equal to bs3? "<<(bs2 == bs3)<<'\n';

    bs2.flip();
    std::cout<<"Is bs2 equal to bs3 after fliped? "<<(bs2 == bs3)<<"\n\n";

    // toggle all bits of bs1 and bs2
    std::cout<<"bs1: "<<bs1<<std::endl;
    std::cout<<"bs2: "<<bs2<<std::endl;

    std::cout<<"~bs1: "<<~bs1<<std::endl;
    std::cout<<"~bs2: "<<~bs2<<std::endl;

    // bitwise XOR, OR and AND operation
    std::cout<<"bs1 ^ bs2: "<<(bs1 ^ bs2)<<std::endl;
    std::cout<<"bs1 | bs2: "<<(bs1 | bs2)<<std::endl;
    std::cout<<"bs1 & bs2: "<<(bs1 & bs2)<<std::endl;

    // right and left shift operation
    std::cout<<"bs1<<3: "<<(bs1<<3)<<std::endl;
    std::cout<<"bs2>>2: "<<(bs2>>2)<<"\n\n";


    // b) resize, append, clear, push_back, pop_back test:
    bs1.resize(1);
    std::cout<<"After bs1.resize(1), bs1 = " << bs1 << '\n';

    bs1.append(100);
    std::cout<<"After bs1.append(), bs1 = " << bs1 << '\n';

    bs1.clear();
    std::cout<<"After bs1.clear(), bs1 = " << bs1 << '\n';

    bs1.push_back(1);
    bs1.push_back(1);
    bs1.push_back(0);
    bs1.push_back(1);
    std::cout<<"After bs1.push_back(), bs1 = " << bs1 << '\n';

    bs1.pop_back();
    std::cout<<"After bs1.pop_back(), bs1 = " << bs1 << "\n\n";

    // c) is_sub_of test:
    std::cout<<"Is bs1 subset of bs1? "<<bs1.is_subset_of(bs1)<<"\n\n";

    // d) find_first() and find_next() test:
    std::cout<<"bs2: "<<bs2<<std::endl;
    std::cout<<"bs2.find_first(): " << bs2.find_first() << '\n';
    std::cout<<"bs2.find_next(3): " << bs2.find_next(3) << '\n';

    return 0;
}
