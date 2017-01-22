#include"IOBrief.h"
#include<iostream>
#include"Circle.h"
#include"Line.h"

using namespace std;


void IOBrief::operator<<(const Circle& c) {
	cout << c.ToString() << endl;
}

void IOBrief::operator<<(const Line& l) {
	cout << l.ToString() << endl;
}