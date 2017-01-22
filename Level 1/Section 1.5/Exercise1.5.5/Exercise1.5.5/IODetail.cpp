#include"IODetail.h"
#include<iostream>
#include"Circle.h"
#include"Line.h"

using namespace std;


void IODetail::operator<<(const Circle& c) {
	cout << c.ToString() << endl;
	cout << "Diameter: " << c.Diameter() << endl;
	cout << "Circumference: " << c.Circumference() << endl;
	cout << "Area: " << c.Area() << endl;
}

void IODetail::operator<<(const Line& l) {
	cout << l.ToString() << endl;
	cout << "Length: " << l.Length() << endl;
}