#include"Shape.h"
#include"stdlib.h"

using namespace std;

Shape::Shape(){
 m_id = rand();
}

Shape::Shape(const Shape& rhs){
  m_id = rhs.m_id;
}

Shape::Shape(const VoidFunctionType& fun){
  f_rotate = fun;
}

Shape& Shape::operator=(const Shape& rhs){
  //Avoiding assignment to itself
  if (&rhs != this){
    m_id = rhs.m_id;
    return *this;
  }
  else return *this;
}

Shape::~Shape(){}

string Shape::ToString() const{
  string temp = "ID: " + to_string(ID());
  return temp;
}

//Call protected member f in rotate function
void Shape::rotate(double d){f_rotate(d);}

//Setter to change the function member
void Shape::setRotateFun(const VoidFunctionType& fun){
  f_rotate = fun;
}

int Shape::ID() const{
  return m_id;
}
