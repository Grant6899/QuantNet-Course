//===============================================================
// Level 2 Section 2.2 Exercise 2.2.2
// Author: Grant Liu
// Create Date: 1/13/2017
// Description: main file
//===============================================================
#include<iostream>
#include<type_traits>
#include<complex>
#include<vector>
#include<array>

class A {}; // test class for is_array testing

int main(){
    std::cout<<std::boolalpha;
    // a) std::is_array tests:
    std::cout<< "Is int array? "<< std::is_array<int>::value<<'\n';
    std::cout<< "Is complex<int> array? "<< std::is_array<std::complex<int>>::value<<'\n';
    std::cout<< "Is vector<double> array? "<< std::is_array<std::vector<double>>::value<<'\n';
    std::cout<< "Is A array? "<< std::is_array<A>::value<<'\n';
    std::cout<< "Is A[10] array? "<< std::is_array<A[10]>::value<<'\n';
    std::cout<< "Is array<int, 3> array? "<< std::is_array<std::array<int, 3>>::value<<'\n';
    std::cout<< "Is int[10] array? "<< std::is_array<int[10]>::value<<"\n\n";

    // b) Rank and Extent tests:

    std::cout<<"Rank of Array a is "<<std::rank<int[][3][4][5]>::value<<'\n';
    std::cout<<"Extent of Array a is "<<std::extent<int[][3][4][5]>::value<<"\n\n";

    // c) remove_extent and remove_all_extent tests:

    using A = std::remove_extent<int[][3][4][5]>::type;
    using B = std::remove_all_extents<int[][3][4][5]>::type;
    std::cout<<"Is A same int[3][4][5]? "<<std::is_same<int[3][4][5], A>::value<<'\n';
    std::cout<<"Is remove_all_extent result int? : "<<std::is_same<int, B>::value<<'\n';

    return 0;
}
