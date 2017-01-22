//===============================================================
// Level 2 Section 2.3 Exercise 2.3.3
// Author: Grant Liu
// Create Date: 1/13/2017
// Description: function vector space templates - h file
//===============================================================
#ifndef FUNCTIONSPACE_H
#define FUNCTIONSPACE_H
#include<cmath>
#include<functional>

// Function map Domain to Range
template <typename R, typename D>
using FunctionType = std::function<R (const D x)>;

// Working function type
using ScalarFunction = FunctionType<double, double>;

// a) addition, multiplication, subtraction, unary additive inverse and scalar multiplication

// operator +
template <typename R, typename D>
FunctionType<R,D> operator + (const FunctionType<R,D>& f, const FunctionType<R,D>& g){
    // Addition of functions
    return [=] (const D& x) { return f(x) + g(x);};
}

// operator -
template <typename R, typename D>
FunctionType<R,D> operator - (const FunctionType<R,D>& f, const FunctionType<R,D>& g){
    // Subtraction of functions
    return [=] (const D& x) { return f(x) - g(x);};
}

// operator *
template <typename R, typename D>
FunctionType<R,D> operator * (const FunctionType<R,D>& f, const FunctionType<R,D>& g){
    // Multiplication of functions
    return [=] (const D& x) { return f(x) * g(x);};
}

// additive inverse
template <typename R, typename D>
FunctionType<R,D> operator - (const FunctionType<R,D>& f){
    // Additive inverse of functions
    return [=] (const D& x) { return - f(x);};
}

// scalar * FunctionType
template <typename R, typename D, typename T>
FunctionType<R,D> operator * (const T& scalar, const FunctionType<R,D>& f){
    // scalar multiplication of functions
    return [=] (const D& x) { return scalar * f(x);};
}

// FunctionType * scalar
template <typename R, typename D, typename T>
FunctionType<R,D> operator * (const FunctionType<R,D>& f, const T& scalar){
    // scalar multiplication of functions
    return [=] (const D& x) { return scalar * f(x);};
}

// operator /
template <typename R, typename D>
FunctionType<R,D> operator / (const FunctionType<R,D>& f, const FunctionType<R,D>& g){
    // scalar multiplication of functions
    return [=] (const D& x) { return f(x) / g(x);};
}

// operator <<
template <typename R, typename D>
FunctionType<R,D> operator << (const FunctionType<R,D>& f, const FunctionType<R,D>& g){
    // scalar multiplication of functions
    return [=] (const D& x) { return f(g(x));};
}

// b) cos, sin, tan, exp, log, abs and sqrt
// cos
template <typename R, typename D>
FunctionType<R,D> cos (const FunctionType<R,D>& f){
    // cos of functions
    return [=] (const D& x) { return std::cos(f(x));};
}

// sin
template <typename R, typename D>
FunctionType<R,D> sin (const FunctionType<R,D>& f){
    // sin of functions
    return [=] (const D& x) { return std::sin(f(x));};
}

// tan
template <typename R, typename D>
FunctionType<R,D> tan (const FunctionType<R,D>& f){
    // tan of functions
    return [=] (const D& x) { return std::tan(f(x));};
}

// exp
template <typename R, typename D>
FunctionType<R,D> exp (const FunctionType<R,D>& f){
    // exp of functions
    return [=] (const D& x) { return std::exp(f(x));};
}

// log
template <typename R, typename D>
FunctionType<R,D> log (const FunctionType<R,D>& f){
    // cos of functions
    return [=] (const D& x) { return std::log(f(x));};
}

// abs
template <typename R, typename D>
FunctionType<R,D> abs (const FunctionType<R,D>& f){
    // abs of functions
    return [=] (const D& x) { return std::abs(f(x));};
}

// sqrt
template <typename R, typename D>
FunctionType<R,D> sqrt (const FunctionType<R,D>& f){
    // sqrt of functions
    return [=] (const D& x) { return std::sqrt(f(x));};
}

// min
template <typename R, typename D>
FunctionType<R,D> min (const FunctionType<R,D>& f, const FunctionType<R,D>& g){
    // min of functions
    return [=] (const D& x) { return std::fmin(f(x), g(x));};
}

// max
template <typename R, typename D>
FunctionType<R,D> max (const FunctionType<R,D>& f, const FunctionType<R,D>& g){
    // max of functions
    return [=] (const D& x) { return std::fmax(f(x), g(x));};
}

#endif
