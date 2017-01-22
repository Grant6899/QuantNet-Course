//===============================================================
// Level 1 Section 1.1 Exercise 1.1.2
// Author: Grant Liu
// Create Date: 1/5/2017
// Description: main file
//===============================================================
#include<vector>
#include<iostream>
#include<numeric>
#include<algorithm>
#include<complex>

using std::vector;
using std::cout;
using std::endl;

// Generic lambda
auto MyMultiply = [](auto x, auto y) { return x * y; };

// Funtor definition
struct FOMultiply
{
	template <typename T>
	T operator () (const T& x, const T& y)
	{
		return x * y;
	}
};

// Free function definition
template <typename T>
T MyMultiply2(const T& x, const T& y) { return x * y; };

int main() {

	std::vector<int> vec{ 1,2,3,4,5 };

	//a.Implement and test the algorithm using the Generic Lambda

	const int initVal = 1;
	int acc_a = std::accumulate(vec.begin(), vec.end(), initVal, MyMultiply);

	cout << "output by Generic Lambda:" << acc_a << endl;

	// Using complex numbers

	using Complex = std::complex<double>;
	std::vector<Complex> complexArray{ Complex(1.0, 1.0), Complex(2.0, 2.0) };

	Complex initCVal(1.0, 1.0);

	// 1) Use Generic Lambda:
	Complex acc_a_1 = std::accumulate(complexArray.begin(), complexArray.end(), initCVal, MyMultiply);

	cout << "Complex test for generic lambda:" << acc_a_1 << endl;

	// 2) Use Functor:
	Complex acc_a_2 = std::accumulate(complexArray.begin(), complexArray.end(), initCVal, FOMultiply());

	cout << "Complex test for functor:" << acc_a_2 << endl;

	// 3) Use Free function:
	Complex acc_a_3 = std::accumulate(complexArray.begin(), complexArray.end(), initCVal, MyMultiply2<Complex>);

	cout << "Complex test for free function:" << acc_a_3 << endl;

	//Conclusion: the results turned out that accumulate can both accept generic lambda function, 
	//functor and free function as its fourth parameter. To confirm this point, we can check the 
	//description doc from 'http://www.cplusplus.com/reference/numeric/accumulate/?kw=accumulate'.
	//It says 'Binary operation taking an element of type T as first argument and an element in the 
	//range as second, and which returns a value that can be assigned to type T. This can either be 
	//a function pointer or a function object. The operation shall not modify the elements passed as 
	//its arguments'.


	//b.Implement the accumulation algorithm using an embedded lambda function in combination with 
	//std::for_each() and captured variables.

	//Here we have a vecter of int vectors, we are going to calculate the sum of each vector and add 
	//the sum to the end of each veator. And use a captured variable to store the sum of the whole matrix.

	vector<vector<int>> vv = { {1, 2, 3},
							   {4, 5, 6},
							   {7, 8, 9} };

	int sum_of_mat = 0;

	for_each(vv.begin(), vv.end(),
		[&sum_of_mat](auto& v) {
		int sub_total = std::accumulate(v.begin(), v.end(), 0, [](auto x, auto y) { return x + y; });
		v.push_back(sub_total);
		sum_of_mat += sub_total;
	});

	cout << "The sum of the matrix is: " << sum_of_mat << endl;

	cout << "The matrix becomes this after adding the sub_total of each line at the end:" << endl;

	for_each(vv.begin(), vv.end(), [](auto v) { for_each(v.begin(), v.end(), [](auto i) {cout << i << " "; }); cout << endl; });


	//c.Give an example of lambda functions that call a stored lambda function and an STL algorithm.

	//Actually we can slightly modify the code above, just store the addition into an auto variable.


	vv = { {1, 2, 3},
		   {4, 5, 6},
		   {7, 8, 9} };

	sum_of_mat = 0;

	auto MyAddition = [](auto x, auto y) { return x + y; };

	for_each(vv.begin(), vv.end(),
		[&](auto& v) {
		int sub_total = std::accumulate(v.begin(), v.end(), 0, MyAddition);
		v.push_back(sub_total);
		sum_of_mat += sub_total;
	});

	cout << "The sum of the matrix is: " << sum_of_mat << endl;

	cout << "The matrix becomes this after adding the sub_total of each line at the end:" << endl;

	for_each(vv.begin(), vv.end(), [](auto v) { for_each(v.begin(), v.end(), [](auto i) {cout << i << " "; }); cout << endl; });

	return 0;
}
