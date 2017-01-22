//===============================================================
// Level 2 Section 2.3 Exercise 2.3.4
// Author: Grant Liu
// Create Date: 1/13/2017
// Description: main file
//===============================================================
#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>

// Function maps Domain to Range
template <typename R, typename D>
using FunctionType = std::function<R (const D x)>;
// Working function type
using ScalarFunction = FunctionType<double, double>;


template <typename T>
std::function<T (const T&)> bind1st
(const std::function<T (const T&, const T&)>& f, const T& x_){
    // Bind to the second param y of f(x, y)
    return [=, x=x_](const T& y){ return f(x, y);};
}

template <typename T>
std::function<T (const T&)> bind2nd
(const std::function<T (const T&, const T&)>& f, const T& y_){
    // Bind to the second param y of f(x, y)
    return [=, y=y_](const T& x){ return f(x, y);};
}

// Question: why it will cause a debug error showing "abort() has been called" if I use [&, x=x_] here? The code below can run successfully under gcc.
/*
template <typename T>
std::function<T(const T&)> bind1st
(const std::function<T(const T&, const T&)>& f, const T& x_) {
	// Bind to the second param y of f(x, y)
	return [&, x = x_](const T& y) { return f(x, y); };
}

template <typename T>
std::function<T(const T&)> bind2nd
(const std::function<T(const T&, const T&)>& f, const T& y_) {
	// Bind to the second param y of f(x, y)
	return [&, y = y_](const T& x) { return f(x, y); };
}
*/

int main(){

    // Declare a lambda function f(x, y) = x + y;
    auto fxy = [](const double& x, const double& y) { return x + y;};


    double yval = 10.0; // fix the sencond param as 10.0
    ScalarFunction fx = bind2nd<double>(fxy, yval); // bind to the second param
    std::cout << "fx(3.0) = "<< fx(3.0) << std::endl;
	
	// Test new bind code on STL algorithms
    std::vector<double> vec(10, 2.0);
    std::transform(vec.begin(), vec.end(), vec.begin(), fx);
    std::cout<<"vec test: \n";
    for (auto i = 0; i< vec.size(); ++i)
        std::cout<<vec[i] << " ";
    std::cout<<std::endl;
	
    return 0;
}
