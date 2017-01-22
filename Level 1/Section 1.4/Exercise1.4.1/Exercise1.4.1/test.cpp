//===============================================================
// Level 1 Section 1.4 Exercise 1.4.1
// Author: Grant Liu
// Create Date: 1/7/2017
// Description: main file
//===============================================================
#include<functional>
#include<iostream>

using std::cout;
using std::endl;

//template alias for function wrapper
template<typename T>
using FunctionType = std::function<T (const T& t)>;

//print template function
template<typename T>
void print(const FunctionType<T>& f, T t){
  std::cout<<f(t)<<'\n';
}


//free function
double ff_square(const double& x){
  return x * x;
}

//functor
struct ftor_square{
  double operator()(const double& x){
    return x * x;
  }
};

//stored lambda function
 auto lambda_square = [](const double& x){return x * x;};

int main(){
  FunctionType<double> f;

  //Free function test:
  f = ff_square;
  cout << "Free function test: f(2) = "; 
  print(f, 2.0);

  //Functor test:
  f = ftor_square();
  cout << "Functor test: f(2) = ";
  print(f, 2.0);


  //Stored lambda expression test:
  f = lambda_square;
  cout<<"Stored lambda expression test: f(2) = ";
  print(f, 2.0);

  //Question: why codes below cannot compile?
  // print(lambda_square, 2.0);

  return 0;
}
