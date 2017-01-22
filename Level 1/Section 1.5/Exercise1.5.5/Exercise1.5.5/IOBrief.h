//===============================================================
// Level 1 Section 1.5 Exercise 1.5.5
// Author: Grant Liu
// Create Date: 1/8/2017
// Description: IOBrief class - h file
//===============================================================
#ifndef IOBRIEF_H
#define IOBRIEF_H
#include"IODevice.h"

class IOBrief : public IODevice { //A derived class from IODevice that display brief information of circle and line
public:
	void operator << (const Circle& c) override;
	void operator << (const Line& l) override;
};


#endif

