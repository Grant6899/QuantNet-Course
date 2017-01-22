#include"LineBriefBuilder.h"
#include"Line.h"
#include"IOBrief.h"

ShapePointer LineBriefBuilder::getShape() {
	ShapePointer shape_ptr = std::make_shared<Line>();
	return shape_ptr;
}

IODevicePointer LineBriefBuilder::getIODevice() {
	IODevicePointer io_ptr = std::make_shared<IOBrief>();
	return io_ptr;
}

