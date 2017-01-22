//===============================================================
// Level 1 Section 1.5 Exercise 1.5.4
// Author: Grant Liu
// Create Date: 1/8/2017
// Description: main file
//===============================================================

#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>

using std::cout;
using std::endl;
using std::vector;
using std::tuple;

//funtion to find index i satisfying v[i]<=x<v[i+1]
// std::find() is not approprite because when source = {1, 2, 2, 3} and x = 2.5.
// We cannot locate the second 2 with std::find(). But with std::upper_bound(), we
// can always find the first element greater than x, which is 3 here, then we return
// the element before it.
template<typename T>
int find_i_before_x(const T& x, const vector<T>& source){
  auto it_greater = std::upper_bound(source.begin(), source.end(), x);
  return std::distance(source.begin(), it_greater);
}



//function to calculate max absolute error and relative error.
template<typename T>
tuple<T, int, T, int> error_bet_vec(const vector<T>& v1, const vector<T>& v2, int range_st, int range_ed){

  vector<T> v_abs_diff, v_re_diff; // vector to save abs error and relative error for each index in [i,j]

  T abs_diff;
  int index;

  //Calculate abs error vector and relative error vector 
  for (auto it = v1.begin() + range_st; it<=v1.begin() + range_ed;++it){
    index = it - v1.begin();
    abs_diff = std::abs(*it - *(v2.begin() + index));
    v_abs_diff.push_back(abs_diff);
    v_re_diff.push_back(abs_diff/(*it));
  }
 
  //Use std::max_element and std::distance to get the iterator and index of the element that generating
  // max abs error and relative error respectively.
  auto max_abs_it = std::max_element(v_abs_diff.begin(), v_abs_diff.end());
  auto max_re_it = std::max_element(v_re_diff.begin(), v_re_diff.end());
  int max_abs_index = range_st + std::distance(v_abs_diff.begin(), max_abs_it);
  int max_re_index = range_st + std::distance(v_re_diff.begin(), max_re_it);

  tuple<T, int, T, int> result {*max_abs_it, max_abs_index, *max_re_it, max_re_index};

  return result;
}


int main(){

// Declare a source vector
  vector<double> vec = {1.0, 2.0, 2.0, 3.1};

  std::sort(vec.begin(), vec.end());

  double x = 2.5;

  cout<<"find index given x = 2.5:  "<<find_i_before_x(x, vec)<<endl;

  vector<double> v1 = {0, 1, 2, 3, 4}, v2 = {1.3, 2.5, 3.1, -1, 0};

  double max_abs, max_abs_i, max_re, max_re_i;

  // Use std::tie to retrieve data in result tuple
  std::tie(max_abs, max_abs_i, max_re, max_re_i) = error_bet_vec(v1, v2, 1, 3);

  cout<<"max_abs: "<<max_abs<<endl;
  cout<<"max_abs_i: "<<max_abs_i<<endl;
  cout<<"max_re: "<<max_re<<endl;
  cout<<"max_re_i: "<<max_re_i<<endl;


  return 0;
}
