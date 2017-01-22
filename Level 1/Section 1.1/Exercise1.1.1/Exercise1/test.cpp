//===============================================================
// Level 1 Section 1.1 Exercise 1.1.1
// Author: Grant Liu
// Create Date: 1/5/2017
// Description: main file
//===============================================================

#include<tuple>
#include<array>
#include<iostream>
#include<limits>

using std::array;
using std::for_each;
using std::cout;
using std::endl;
using std::tuple;
using std::get;

//Print function for std::array
template<typename T, std::size_t N>
void print(const std::array<T, N>& arr){
  for (auto it = arr.begin();it<arr.end();++it)
    cout<<*it<<" ";

  cout<<endl;
}

int main(){

  //Initialize a std::array with size 10
  array<int, 10> a = {-91, 222, -103, 4, 5, 6, 18, 7,-3, 3}, a_copy = a;

  //Declare a number to be multiplied by the array
  int multiplier = 3;

  //Print the array before multipling
  cout<<"before multipling:"<<endl;
  print(a);

  //copy-by-value: Lambda function that multiplies each element of an array by a number
  for_each(a.begin(), a.end(), [=](int& element){element*=multiplier;});

  //Print the multiplied array
  cout<<"after multipling with copy-by-value function:"<<endl;
  print(a);

  //Print the array before multipling
  cout<<endl<<"before multipling:"<<endl;
  print(a_copy);

  //copy-by-reference: Lambda function that multiplies each element of an array by a number
  for_each(a_copy.begin(), a_copy.end(), [&](int& element){element*=multiplier;});

  //Print the multiplied array
  cout<<"after multipling with copy-by-reference function:"<<endl;
  print(a_copy);

  //Comments: For these two functions, it makes no difference no matter the capture variable is 
  //'copy-by-value' or a reference, because the captured variable - multiplier isn't modifed with
  //in Lambda function. Here we only change the reference of each element in the array by multpling
  //the multiplier.


  cout<<endl<<"Looking for minimum and maximum in the multiplied array..."<<endl;
  int _max = INT_MIN, _min = INT_MAX;

  //Define a Lambda funtion returning max and min of the array
  auto r = [&](const auto& arr){
    for (auto it = arr.begin(); it<arr.end();++it){
      if (*it > _max) _max = *it;
      if (*it < _min) _min = *it;
    }
    tuple<int, int> result = {_min, _max};
    return result;
  };

  //auto min_max_tuple = r(a);
  cout<<"maximum and minimum found by Lambda function:"<<endl<<get<0>(r(a))<<" "<<get<1>(r(a))<<endl;


  //std::minmax_element version
  cout<<"Minimum and maximum found by std::minmax_element:"<<endl;

  auto result = std::minmax_element(a.begin(), a.end());

  cout<<*result.first<<" "<<*result.second<<endl;

  //Yes, I got the same output as that from using Lambda function. 
  //We can store the lambda function into an auto variable for later use. 
  //And its implementation is easy to check above.


  return 0;
}
