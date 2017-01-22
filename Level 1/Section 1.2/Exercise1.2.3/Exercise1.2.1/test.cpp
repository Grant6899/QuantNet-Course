//===============================================================
// Level 1 Section 1.2 Exercise 1.2.3
// Author: Grant Liu
// Create Date: 1/6/2017
// Description: main file
//===============================================================

#include<iostream>
#include"c.h"

int main() {
	//Declare a vector
	vector<int> v = {1, 2, 3};

	C<int> c1(v), c2;

	//Print vectors before moving
	cout<<"Before moving,"<<endl<<"c1:";
	c1.print();

	cout<<"c2:";
	c2.print();

	//Move c1's content to c2
	c2 = std::move(c1);

	//Print vectors after first moving
	cout<<"After first moving,"<<endl<<"c1:";
	c1.print();

	cout<<"c2:";
	c2.print();

	C<int> c3(std::move(c2));

	//print vectors after second moving
	cout<<"After second moving,"<<endl<<"c1:";
	c1.print();

	cout<<"c2:";
	c2.print();

	cout<<"c3:";
	c3.print();

	// b) We confirm a move constructor or a move assignment operator is called in two ways. 
	// First, the copy constructor and copy assignment operator are mared deleted. 
	// Second, we print something when move constructor or assignment is called. 
	// Both prove our point here.

	// c) If we use a lvalue as the source of a move operation:

	//C<int> c4(c3); //This will not compile because it will look for the copy constructor,
	                 // which is marked deleted in this case.

	return 0;
}
