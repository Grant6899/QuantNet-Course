//==============================================================
// Level 2 Section 2.1 Exercise 2.1.3
// Author: Grant Liu
// Create Date: 1/12/2017
// Description: shape class - cpp file
//===============================================================
#include"Shape.h"
#include"stdlib.h"
#include"time.h"

Shape::Shape(){
 m_id = rand();
}

Shape::Shape(const Shape& rhs){
  m_id = rhs.m_id;
}

const Shape& Shape::operator=(const Shape& rhs){
  //Avoiding assignment to itself
  if (&rhs != this){
    m_id = rhs.m_id;
    return *this;
  }
  else return *this;
}

Shape::~Shape(){}

std::string Shape::ToString() const{
  std::string temp = "ID: " + std::to_string(ID());
  return temp;
}

void Shape::rotate(double d){}

int Shape::ID() const{
  return m_id;
}
