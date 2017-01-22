//===============================================================
// Level 2 Section 2.5&2.6 Exercise 2.5&6.3
// Author: Grant Liu
// Create Date: 1/14/2017
// Description: main file
//===============================================================

#include<iostream>
#include<boost/math/special_functions/next.hpp>
#include<limits>
#include<iomanip>

int main(){

    // float_next test:
    std::cout<<std::setprecision(20);
    double a = 0.1;
    double a_next = boost::math::float_next(a);
    std::cout << "a = " << a << ", a_next = " << a_next << '\n';
    std::cout <<"float_distance(a, a_next) = "<< boost::math::float_distance(a, a_next)<< "\n\n";

    a = std::numeric_limits<double>::max();
    // b = boost::math::float_next(a); // Will throw an overflow error


    // float_prior test:
    a = 0.1;
    double a_prior = boost::math::float_prior(a);
    std::cout << "a = " << a << ", a_prior = " << a_prior << '\n';
    std::cout <<"float_distance(a, a_prior) = "<< boost::math::float_distance(a, a_prior) << "\n\n";

    a = std::numeric_limits<double>::min();
    // b = boost::math::float_prior(a); // Will throw an overflow error


    // float_advance test:
    a = 0.1;
    double a_advanced = boost::math::float_advance(a, 100);
    std::cout << "a = " << a << ", a_advanced = " << a_advanced << '\n';
    std::cout <<"float_distance(a, a_advanced) = "<< boost::math::float_distance(a, a_advanced) << "\n\n";


    // nextafter test:
    std::cout<< "nextafter(a, 1) is " << boost::math::nextafter(a, 1) << '\n';
    std::cout<< "nextafter(a, -1) is " << boost::math::nextafter(a, -1) << '\n';

    return 0;
}
