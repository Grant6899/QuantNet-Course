//===============================================================
// Level 2 Section 2.7 Exercise 2.7.4
// Author: Grant Liu
// Create Date: 1/15/2017
// Description: main file
//===============================================================
#include<iostream>
#include<system_error>
#include<tuple>
#include<string>

// b) Function that returns the information pertaining to error code argument
std::tuple<std::string, int, std::string> getErrorInformation(const std::error_code& source){

    std::string error_message = source.message();

    int error_code = source.value();

    std::string category_name = source.category().name();

    return std::make_tuple(error_message, error_code, category_name);
}


int main(){

    // a) default error code, error code ctor by value and category
    std::error_code default_code = std::error_code();
    std::cout<<"default_code message: "<<default_code.message()<<'\n';
    std::error_code code1 = std::error_code(10, std::generic_category());
    std::cout<<"code1 message: "<<code1.message()<<"\n\n";

    // b) funtion test:
    std::cout<<"code1 info:\n";
    auto info = getErrorInformation(code1);

    std::cout<<"message: "<<std::get<0>(info)<<'\n';
    std::cout<<"error code: "<<std::get<1>(info)<<'\n';
    std::cout<<"category name: "<<std::get<2>(info)<<'\n';

    // c) Equality/inequality test:
    std::error_condition condition1 = std::error_condition(10, std::generic_category());
    std::error_condition condition2 = std::make_error_condition(std::errc::no_such_file_or_directory);

    std::cout<<"code1.value: "<<code1.value()<<" condtion1.value: "<<condition1.value()<<'\n';
    std::cout<<"code1.category: "<<code1.category().name()<<" condtion1.category: "<<condition1.category().name()<<'\n';

	std::cout << std::boolalpha << "Is code1 == condition1? "<< (code1==condition1) << '\n';

    return 0;
}
