//===============================================================
// Level 2 Section 2.8 Exercise 2.8.1
// Author: Grant Liu
// Create Date: 1/14/2017
// Description: main file
//===============================================================
#include<iostream>
#include<bitset>
#include<climits>

int main(){

    // create bitsets from unsigned long and unsigned long long
    unsigned long n1 = 1001001001000011;
    std::bitset<16> bs1(n1);
    std::bitset<70> bs2(ULLONG_MAX);

    std::cout<<"bs1: "<<bs1<<'\n';
    std::cout<<"bs2: "<<bs2<<'\n';

    // create bitsets from full string
    std::string str = "10010";

    std::bitset<5> bs3(str);
    std::bitset<5> bs4(str, 1, 3);
    std::cout<<"bs3: "<<bs3<<'\n';
    std::cout<<"bs4: "<<bs4<<'\n';

    // exception handling
    /*
    try{
        std::string str1 = "10012";

        std::bitset<5> bs5(str1);
    }catch(std::exception& e){
        std::cout<<e.what()<<std::endl;
        }

    try{
        bs1[100] = 0;
    }catch(std::exception& e){
        std::cout<<e.what()<<std::endl;
        }*/

    // d)
    // set, reset test:
    bs1.set();
    std::cout<<"after bs1.set(), bs1: "<<bs1<<'\n';
    bs1.reset();
    std::cout<<"after bs1.reset(), bs1: "<<bs1<<'\n';

    // flip test:
    bs3.flip();
    std::cout<<"after bs3.flip(), bs3: "<<bs3<<'\n';

    // all, any, none test
    std::cout<<std::boolalpha;
    std::cout<<"bs1.all(): "<<bs1.all()<<'\n';
    std::cout<<"bs1.any(): "<<bs1.any()<<'\n';
    std::cout<<"bs1.none(): "<<bs1.none()<<'\n';

    std::cout<<"bs3.all(): "<<bs3.all()<<'\n';
    std::cout<<"bs3.any(): "<<bs3.any()<<'\n';
    std::cout<<"bs3.none(): "<<bs3.none()<<'\n';

    //access element
    std::cout<<"bs3[2]: "<<bs3[2]<<'\n';

    //count test:
    std::cout<<"bs2.count(): "<<bs2.count()<<'\n';

    //e) conversion from bitset to string, ulong and ullong
    auto strfrombs = bs3.to_string();
    auto ulongfrombs = bs3.to_ulong();
    auto ullongfrombs = bs3.to_ullong();

    //f)
    std::bitset<5> bs6(bs4);

    std::cout<<"bs4: "<<bs4<<'\n';
    std::cout<<"bs6: "<<bs6<<'\n';

    std::cout<<"Is bs6 equal to bs4? "<<(bs6 == bs4)<<'\n';

    bs6.flip();
    std::cout<<"Is bs6 equal to bs4 after fliped? "<<(bs6 == bs4)<<'\n';

    return 0;
}
