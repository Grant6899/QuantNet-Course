//===============================================================
// Level 2 Section 2.4 Exercise 2.4.4
// Author: Grant Liu
// Create Date: 1/14/2017
// Description: main file
//===============================================================
#include<iostream>
#include<memory>
#include<vector>

// Base class
class Base
{
private:
public:
    Base() { }
    virtual void print() const = 0;
protected:
    virtual ~Base() { std::cout << "Base destructor\n\n"; }
};

// Derived class
class Derived : public Base
{
private:
public:
    Derived() : Base() { }
    ~Derived() { std::cout << "Derived destructor\n"; }
    void print() const { std::cout << "derived object\n";}
};

// Derived factory
std::shared_ptr<Derived> Derivedfactory(){
    return std::shared_ptr<Derived>(new Derived);
}

int main(){

    // a)
    std::vector<std::shared_ptr<Base>> vec_base1;
    //std::vector<std::unique_ptr<Base>> vec_base2; // This will not compile because Base is an abstract class, all base pointer pointing to the same address. A container has several unique pointers, but they cannot point to the same location, otherwise except the first pointer, all rest pointers will delete an invalid location.

    std::vector<std::shared_ptr<Derived>> vec_derived1;
    std::vector<std::unique_ptr<Derived>> vec_derived2; // This will compile because erived is not an abstract class, thus derived pointers can point to different places.

    // b) and c) Claims ten derived objects' storage and all of them are destructed. So no memory leaks.
    for(int i=0;i<10;++i)
        vec_derived1.push_back(Derivedfactory());

    return 0;
}
