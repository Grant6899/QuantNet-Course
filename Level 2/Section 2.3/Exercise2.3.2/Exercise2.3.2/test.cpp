//===============================================================
// Level 2 Section 2.3 Exercise 2.3.2
// Author: Grant Liu
// Create Date: 1/13/2017
// Description: main file
//===============================================================
#include<iostream>
#include<vector>
#include<array>
#include<functional>

int main(){
    // a) Move Semantic Modification
    int size = 4;
    double val = 2.71;
    std::vector<double> data(size, val);

    // Default capture mode (not preferred)
    auto fun = [data = std::move(data)]() mutable{
        for (std::size_t i = 0; i < data.size(); ++i){ data[i] = 3.14; std::cout << data[i] << ",";} std::cout << '\n';};


    fun();

    // 'data' still exists and has been modified
    for (std::size_t i = 0; i < data.size(); ++i){
        data[i] = 3.14;
        std::cout << data[i] << ":";
        }

    std::cout<<"Size of data after lambda: "<<data.size()<<"\n\n";

    // Question: If we don't call fun() after declaration, data is still moved. Does that mean std::move() happens at fun's declaration but not when it's called?

    //=======================================================================

    // b) C++14 init capture with local variables
    int x = 1'000'000; // This is a digit separator

    auto fun4 = [&r = x](){ r *= 2; std::cout<< "\nr: " << r; };

    std::cout<<"before calling, x = "<< x;

    fun4();

    std::cout<<"\nafter calling, x = "<< x << std::endl;

    //=======================================================================

    // c) Migrate lambda capture with C++11 to C++14
    std::cout<<'\n';
    int size2 = 3; double val2 = 1.41;
    std::vector<double> data2(size2, val2);
    std::vector<int> data3 = { 1, 2, 3 }; // Change array to vector to make this example more reasonable.

    // init capture in c++14
    auto fun5 = [array = std::move(data2), array2 = std::move(data3)]() mutable{
        for (std::size_t i = 0; i < array.size(); ++i){
            array[i] = 3.14; std::cout <<array[i]<<"/";
        }
        std::cout <<'\n';
        for (std::size_t i = 0; i < array2.size(); ++i){
            array2[i] = 2; std::cout <<array2[i]<<"/";
            }};

    fun5();

    // check whether data has been moved:
    if (0 == data2.size() && 0 == data3.size()) {
        std::cout <<"\nDouble arrays have no elements, OK\n";
    }
    else{
        std::cout <<"\n Ouch!\n";
        for (std::size_t i = 0;i<data2.size(); ++i)
            std::cout<<data2[i]<<"^";
        for (std::size_t i = 0; i < data3.size(); ++i)
            std::cout<<data3[i]<<"^";
    }

    return 0;
}
