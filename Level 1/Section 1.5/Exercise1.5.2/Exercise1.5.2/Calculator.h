//===============================================================
// Level 1 Section 1.5 Exercise 1.5.2
// Author: Grant Liu
// Create Date: 1/8/2017
// Description: calculator class - h file
//===============================================================
#include<tuple>

//Calculator template for general cases
template<typename T, typename Tuple, std::size_t N>
  struct Calculator{
	//Recursive sum algorithm, keep calling itself until termination function is called
    static T Sum(const Tuple& source){
      return std::get<N-1>(source) + Calculator<T, Tuple, N-1>::Sum(source);
    }

	//Average function, call sum and get its return value over size of tuple.
    static T Average(const Tuple& source){
      return Sum(source)/(T)N;
    }

	//Recursive maximum algorithm
    static T Maximum(const Tuple& source){
      T temp = Calculator<T, Tuple, N-1>::Maximum(source);
      return std::get<N-1>(source) > temp? std::get<N-1>(source) : temp;
    }


  };

//Calculator template for terminating cases
template<typename T, typename Tuple>
  struct Calculator<T, Tuple, 1>{

   static T Sum(const Tuple& source){
      return std::get<0>(source);
   }

   static T Maximum(const Tuple& source){
     return std::get<0>(source);
   }

};
