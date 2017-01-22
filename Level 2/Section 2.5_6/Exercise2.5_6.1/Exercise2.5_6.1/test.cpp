//===============================================================
// Level 2 Section 2.5&2.6 Exercise 2.5&6.1
// Author: Grant Liu
// Create Date: 1/14/2017
// Description: main file
//===============================================================
#include<iostream>
#include<cmath>
#include<cfloat>
#include<limits>

// Number Classification Function
template <typename T>
const char* Classify(T t)
{
    switch (std::fpclassify(t))
        {
        case FP_INFINITE:  return "Inf";
        case FP_NAN: return "NaN";
        case FP_NORMAL:    return "normal";
        case FP_SUBNORMAL: return "subnormal";
        case FP_ZERO: return "zero";
        default:  return "unknown";
        }
}

int main(){
    //a) Classify function test:
    double val = std::numeric_limits<double>::max();

    std::cout<< "val: " << Classify(val) << '\n';
    std::cout<< "2.0 * val: " << Classify(2.0 * val) << '\n';
    std::cout<< "3.1415 + val: " << Classify(3.1415 + val) << '\n';

    double val2 = std::numeric_limits<double>::min() - 3.1415;
    std::cout<< "val2: " << Classify(val2) << '\n';
    std::cout<< "val2/2.0: " << Classify(val2/2.0) << '\n';
    std::cout<< "DBL_MIN/2: " << Classify(DBL_MIN/2) << "\n\n";

    //b) 'is' functions test:
    std::cout<<std::boolalpha;

    double factor = 2.0;
    //factor
    std::cout<< "Is factor finite? " << std::isfinite(factor) << '\n';
    std::cout<< "Is factor infinite? " << std::isinf(factor) << '\n';
    std::cout<< "Is factor nan? " << std::isnan(factor)<< '\n';
    std::cout<< "Is factor normal?: " << std::isnormal(factor) << "\n\n";

    val = factor * std::numeric_limits<double>::max();
    //val
    std::cout<< "Is val finite? " << std::isfinite(val) << '\n';
    std::cout<< "Is val infinite? " << std::isinf(val) << '\n';
    std::cout<< "Is val nan? " << std::isnan(val)<< '\n';
    std::cout<< "Is val normal?: " << std::isnormal(val) << "\n\n";

    //val - val
    std::cout<< "Is val - val finite? " << std::isfinite(val - val) << '\n';
    std::cout<< "Is val - val infinite? " << std::isinf(val - val) << '\n';
    std::cout<< "Is val - val nan? " << std::isnan(val - val)<< '\n';
    std::cout<< "Is val - val normal?: " << std::isnormal(val - val) << "\n\n";

    //std::sqrt(-1.0)
    std::cout<< "Is std::sqrt(-1.0) finite? " << std::isfinite(std::sqrt(-1.0)) << '\n';
    std::cout<< "Is std::sqrt(-1.0) infinite? " << std::isinf(std::sqrt(-1.0)) << '\n';
    std::cout<< "Is std::sqrt(-1.0) nan? " << std::isnan(std::sqrt(-1.0))<< '\n';
    std::cout<< "Is std::sqrt(-1.0) normal?: " << std::isnormal(std::sqrt(-1.0)) << "\n\n";

    //std::log(0.0)
    std::cout<< "Is std::log(0.0) finite? " << std::isfinite(std::log(0.0)) << '\n';
    std::cout<< "Is std::log(0.0) infinite? " << std::isinf(std::log(0.0)) << '\n';
    std::cout<< "Is std::log(0.0) nan? " << std::isnan(std::log(0.0))<< '\n';
    std::cout<< "Is std::log(0.0) normal?: " << std::isnormal(std::log(0.0)) << "\n\n";

    //std::exp(val)
    std::cout<< "Is std::exp(val) finite? " << std::isfinite(std::exp(val)) << '\n';
    std::cout<< "Is std::exp(val) infinite? " << std::isinf(std::exp(val)) << '\n';
    std::cout<< "Is std::exp(val) nan? " << std::isnan(std::exp(val))<< '\n';
    std::cout<< "Is std::exp(val) normal?: " << std::isnormal(std::exp(val)) << "\n\n";

    return 0;
}
