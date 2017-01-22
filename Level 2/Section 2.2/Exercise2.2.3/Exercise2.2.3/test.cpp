//===============================================================
// Level 2 Section 2.2 Exercise 2.2.3
// Author: Grant Liu
// Create Date: 1/13/2017
// Description: main file
//===============================================================
#include<iostream>
#include<type_traits>
#include<limits>

// 1) Mapping integers to unsigned integers and vice versa.
using UnsignedIntType = std::make_unsigned<int>::type;
UnsignedIntType IntToUnsigned(int& source){
    return source + (std::numeric_limits<unsigned int>::max() - std::numeric_limits<int>::max());
}

int UnsignedToInt(UnsignedIntType& source){
    return source - (std::numeric_limits<unsigned int>::max() - std::numeric_limits<int>::max());
}


// 2) Add the const specifer to a type(object test)
class B{
public:
    void con_test() { std::cout << "Non-Const\n"; }
    void con_test() const { std::cout << "Const\n"; }
};

template <class T>
void call_ConTest(){
    T().con_test();
}

int main(){
    // 1) Int-> Unsigned Int Tests:

	int signed1 = -2147483647;
    UnsignedIntType unsigned1 = IntToUnsigned(signed1);
    std::cout<< "Int " << signed1 << " converted to unsigned int: "<< unsigned1 << std::endl;

    // Unsigned -> Int Tests:
    UnsignedIntType unsigned2 = 2147483648;
    int signed2 = UnsignedToInt(unsigned2);
    std::cout<< "Unsigned int " << unsigned2 <<" converted to signed int: "<< signed2 << "\n\n";

    // 2) Add/Remove const Test on object B:
    std::cout<<"B is ";
    call_ConTest<B>();
    std::cout<<"add_const<B>::type is ";
    call_ConTest<std::add_const<B>::type>();
    std::cout<<"const B is ";
    call_ConTest<const B>();
    std::cout<<"remove_const<const B> is ";
    call_ConTest<std::remove_const<const B>::type>();
    std::cout<<'\n';

    // 3) Add/Remove pointer:
    std::cout<<std::boolalpha;
    std::cout<<"Before add_pointer, is it pointer? "<<std::is_pointer<int>::value<<'\n';
    std::cout<<"After add_pointer, is it pointer? "<<std::is_pointer<std::add_pointer<int>::type>::value<<'\n';

    std::cout<<"Before remove_pointer, is it pointer? "<<std::is_pointer<double*>::value<<'\n';
    std::cout<<"After remove_pointer, is it pointer? "<<std::is_pointer<std::remove_pointer<double*>::type>::value<<"\n\n";

    // 4) Add/Remove volatile:
    std::cout<<"Before add_volatile, is it volatile? "<<std::is_volatile<int>::value<<'\n';
    std::cout<<"After add_volatile, is it volatile? "<<std::is_volatile<std::add_volatile<int>::type>::value<<'\n';

    std::cout<<"Before remove_volatile, is it volatile? "<<std::is_volatile<volatile char>::value<<'\n';
    std::cout<<"After remove_volatile, is it volatile? "<<std::is_volatile<std::remove_volatile<volatile char>::type>::value<<'\n';

    return 0;
}
