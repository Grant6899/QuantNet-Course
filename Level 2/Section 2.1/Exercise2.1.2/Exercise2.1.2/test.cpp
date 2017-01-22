//===============================================================
// Level 2 Section 2.1 Exercise 2.1.2
// Author: Grant Liu
// Create Date: 1/12/2017
// Description: main file
//===============================================================

#include<iostream>
#include<type_traits>

template<typename T>
void PrintImp(const T& t, std::true_type){ // Pointer Print Function
  std::cout<< *t <<std::endl; // Print what the pointer points
}

template<typename T>
void PrintImp(const T& t, std::false_type){ // Reference Print Function
  std::cout<< t <<std::endl; // Print the value directly
}

template<typename T>
void Print(const T& t){ // Function that will print the destination of a pointer(if pointer) or the referenced value(if reference)
  PrintImp(t, std::is_pointer<T>());

  //Question:: what's the difference between std::integral_constant<bool, value> and bool? It will not compile if we use PrintImp(t, std::is_pointer<T>::value) here.
}

int main(){

  // Declare several variables, some pointers and some scalar reference type
  int* int_ptr = new int(3);

  double double_value = 1.0;

  char* ch_ptr = new char('A');

  // Call Print function to test:
  Print(int_ptr); // Print its destination
  Print(double_value);// Print itself
  Print(ch_ptr);// Print its destination

  delete int_ptr;
  delete ch_ptr;

  return 0;
}
