//===============================================================
// Level 1 Section 1.5 Exercise 1.5.5
// Author: Grant Liu
// Create Date: 1/8/2017
// Description: line brief class - h file
//===============================================================
#ifndef LINEBRIEFBUILDER_H
#define LINEBRIEFBUILDER_H

#include"Builder.h"
#include<memory>

class LineBriefBuilder : public Builder { // A derived class from builder that uses line and iobrief

public:
	ShapePointer getShape() override;
	IODevicePointer getIODevice() override;
};


#endif 
