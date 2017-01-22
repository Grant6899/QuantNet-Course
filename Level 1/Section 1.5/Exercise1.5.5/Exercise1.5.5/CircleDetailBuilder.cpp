#include"CircleDetailBuilder.h"
#include"Circle.h"
#include"IODetail.h"

ShapePointer CircleDetailBuilder::getShape() {
	ShapePointer shape_ptr = std::make_shared<Circle>();
	return shape_ptr;
}

IODevicePointer CircleDetailBuilder::getIODevice() {
	IODevicePointer io_ptr = std::make_shared<IODetail>();
	return io_ptr;
}

