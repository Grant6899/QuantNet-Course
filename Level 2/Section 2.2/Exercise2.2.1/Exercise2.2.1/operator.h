//===============================================================
// Level 2 Section 2.2 Exercise 2.2.1
// Author: Grant Liu
// Create Date: 1/13/2017
// Description: operator function templates - h file
//===============================================================
#ifndef OPERATOR_H
#define OPERATOR_H

#include<iostream>
#include<vector>
#include<array>
#include<algorithm>
// Vector/Array Print Implementation
template<typename T>
void Print_impl(const T& t, std::true_type){

    for(auto it = t.begin(); it< t.end(); ++it){
        std::cout<<*it<<' ';
    }
    std::cout<<std::endl;
}
// Scalar Print Implementation
template<typename T>
void Print_impl(const T& t, std::false_type){
    std::cout<<t<<std::endl;
}

// Print function template
template<typename T>
void Print(const T& t){
    Print_impl(t, std::is_compound<T>());
}

// a) Addition function
// Vector/Array Addition Implementation
template<typename T>
T Addition_impl(const T& t1, const T& t2, std::true_type){
    T result = t1; // Initialization of returned result
    // Add two containers at each index
    for(auto it = t1.begin(); it< t1.end(); ++it){
        int index = std::distance(t1.begin(), it);
        result.at(index) = *it + t2.at(index);
    }

    return result;
}

// Scalar Addition Implementation
template<typename T>
T Addition_impl(const T& t1, const T& t2, std::false_type){
    return t1 + t2;
}

// Addition function template
template<typename T>
T Addition(const T& t1, const T& t2){
    return Addition_impl(t1, t2, std::is_compound<T>());
}

// b) Additive Inverse Funcction
// Vector/Array Additive Inverse Implementation
template<typename T>
T Additive_Inv_impl(const T& t, std::true_type){

    T result = t; // Initialization of returned result
    std::for_each(result.begin(), result.end(), [](auto& ele){ ele *= -1;});
    return result;
}

template<typename T>
T Additive_Inv_impl(const T& t, std::false_type){
    return t;
}

template<typename T>
T Additive_Inv(const T& t){
    return Additive_Inv_impl(t, std::is_compound<T>());
}

// c) Scalar Multification Funcction
// Vector/Array Scalar Multification Implementation
template<typename T1, typename T2>
T2 Multi_impl(const T1& t1, const T2& t2, std::true_type){

    T2 result = t2; // Initialization of returned result
    std::for_each(result.begin(), result.end(), [&](auto& ele){ ele *= t1;});
    return result;
}

template<typename T1, typename T2>
T2 Multi_impl(const T1& t1, const T2& t2, std::false_type){
    return t1 * t2;
}

template<typename T1, typename T2>
T2 Scalar_Multi(const T1& t1, const T2& t2){
    return Multi_impl(t1, t2, std::is_compound<T2>());
}

#endif
