#include"Valve.h"

using namespace std;

Valve::Valve(){
  i_data = 1;
}

Valve::Valve(const Valve& rhs){
  i_data = rhs.i_data;
}

const Valve& Valve::operator=(const Valve& rhs){
  //Avoiding assignment to itself
  if (&rhs != this){
    i_data = rhs.i_data;
    return *this;
  }
  else return *this;
}

Valve::~Valve(){}

string Valve::ToString() const{
  string temp = "This is a valve";
  return temp;
}

int Valve::getData() const{
  return i_data;
}
