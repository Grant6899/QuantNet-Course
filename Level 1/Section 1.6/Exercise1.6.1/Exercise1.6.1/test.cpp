//===============================================================
// Level 1 Section 1.6 Exercise 1.6.1
// Author: Grant Liu
// Create Date: 1/8/2017
// Description: main file
//===============================================================
#include<iostream>
#include<memory>

using std::shared_ptr;

struct Base {
  virtual void draw() { std::cout << "print a base\n"; }
  virtual void draw() const {std::cout<< "const print a base\n";} // added the virtual function in base for derived overriding
  virtual void print() {} // void print() is overidden in derived classes with override specifier, the overidden function in base class must be virtual.
  ~Base() { std::cout << "bye base\n"; }
};

struct Derived : public Base{ // remove final here, because Derived2 is derived from Derived.
  void draw() override
  { std::cout << "print a derived\n"; }
  void draw() const override { std::cout<<"Derived draw() const called.\n";}
  void print() override { std::cout<< "Derived print() called\n";}
  // print marked as override but doesn't do any real overriding, implement added
  ~Derived() { std::cout << "bye derived\n";}
};


class Derived2 : public Derived
{

};

int main(){

  //create a smart pointer pointing a Base obj
  shared_ptr<Base> b1(new Base);
  b1->draw();
  b1->print();

  //create a smart pointer pointing a const Base obj
  shared_ptr<const Base> b2(new const Base);
  b2->draw();

  //create a smart pointer pointing a Derived obj
  shared_ptr<Base> d1(new Derived);
  d1->draw();
  d1->print();

  //create a smart pointer pointing a const Derived obj
  shared_ptr<const Base> d2(new const Derived);
  d2->draw();

  //create a smart pointer pointing a Derived2 obj
  shared_ptr<Base> dd(new Derived2);

  return 0;
}
