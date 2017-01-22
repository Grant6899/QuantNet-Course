#include"Shape.h"
#include"stdlib.h"
#include"time.h"

using namespace std;

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

string Shape::ToString() const{
  string temp = "ID: " + to_string(ID());
  return temp;
}


int Shape::ID() const{
  return m_id;
}
