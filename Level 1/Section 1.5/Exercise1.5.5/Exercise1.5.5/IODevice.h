//===============================================================
// Level 1 Section 1.5 Exercise 1.5.5
// Author: Grant Liu
// Create Date: 1/8/2017
// Description: iodevice class - h file
//===============================================================
//===============================================================
// Level 1 Section 1.5 Exercise 1.5.5
// Author: Grant Liu
// Create Date: 1/8/2017
// Description: IODevice class - h file
//===============================================================
#ifndef IODEVICE_H
#define IODEVICE_H

class Circle;
class Line;

class IODevice { // Interface for displaying CAD objects

public:
	virtual void operator << (const Circle& c) = 0;
	virtual void operator << (const Line& l) = 0;
};

#endif
