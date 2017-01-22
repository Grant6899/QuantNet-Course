//===============================================================
// Level 2 Section 2.5&2.6 Exercise 2.5&6.2
// Author: Grant Liu
// Create Date: 1/14/2017
// Description: main file
//===============================================================
#include<iostream>
#include<limits>


template <typename T>
T eps(){
    T epsilon = 1.0;
    while ((1.0 + 0.5*epsilon) != 1.0) {
            epsilon *= 0.5;
    }
    return epsilon;
}


int main(){
    // a)
    std::cout<<"Double epsilon: "<<eps<double>()<<'\n';
    std::cout<<"Long double epsilon: "<<eps<long double>()<< '\n';
	std::cout << "Float epsilon: " << eps<float>() << "\n\n";  // Question: Epsilon calculated is 2.22045e-16, while std::numeric_limts<float>::epsilon = 1.9209e-07. Why are they inconsistent?

    // b)
    std::cout<<"Double epsilon: "<<std::numeric_limits<double>::epsilon()<<'\n';
    std::cout<<"Long double epsilon: "<<std::numeric_limits<long double>::epsilon()<<'\n';
	std::cout << "Float epsilon: " << std::numeric_limits<float>::epsilon() << '\n';

   
    return 0;
}
