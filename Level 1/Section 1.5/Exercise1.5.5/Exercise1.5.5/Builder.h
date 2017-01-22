//===============================================================
// Level 1 Section 1.5 Exercise 1.5.5
// Author: Grant Liu
// Create Date: 1/8/2017
// Description: builder class - h file
//===============================================================
#ifndef BUILDER_H
#define BUILDER_H

#include<memory>
#include"Shape.h"
#include"IODevice.h"
#include<tuple>

using ShapePointer = std::shared_ptr<Shape>;
using IODevicePointer = std::shared_ptr<IODevice>;

class Builder { // A Builder hierarchy that builds shapes and io devices
public:	
	std::tuple<ShapePointer, IODevicePointer> getProduct() { // getProduct() by calling getShape and getIODevice
		std::tuple<ShapePointer, IODevicePointer> result { getShape(), getIODevice() };
		return result;
	}

	virtual ShapePointer getShape() = 0; 
	virtual IODevicePointer getIODevice() = 0;
};


#endif