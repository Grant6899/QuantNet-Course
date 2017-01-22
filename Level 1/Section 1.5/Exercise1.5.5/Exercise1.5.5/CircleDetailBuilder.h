//===============================================================
// Level 1 Section 1.5 Exercise 1.5.5
// Author: Grant Liu
// Create Date: 1/8/2017
// Description: circle detail builder class - h file
//===============================================================
#ifndef CIRCLEDETAILBUILDER_H
#define CIRCLEDETAILBUILDER_H

#include"Builder.h"
#include<memory>

class CircleDetailBuilder : public Builder { // A derived class from builder that uses iobrief and circle

public:
	ShapePointer getShape() override;
	IODevicePointer getIODevice() override;
};


#endif 
