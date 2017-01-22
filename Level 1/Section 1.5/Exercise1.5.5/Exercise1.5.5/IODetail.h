//===============================================================
// Level 1 Section 1.5 Exercise 1.5.5
// Author: Grant Liu
// Create Date: 1/8/2017
// Description: IODetail class - h file
//===============================================================
#ifndef IODETAIL_H
#define IODETAIL_H
#include"IODevice.h"

class IODetail : public IODevice {// A derived class from IODevice that displays detailed information of circle and line

public:
	void operator << (const Circle& c);
	void operator << (const Line& l);
};



#endif