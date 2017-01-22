//===============================================================
// Level 2 Section 2.7 Exercise 2.7.2
// Author: Grant Liu
// Create Date: 1/15/2017
// Description: main file
//===============================================================
#include<iostream>
#include<fstream>
#include<system_error>
#include<tuple>
#include<string>


// b) Function that returns the information pertaining to error condition argument
std::tuple<std::string, int, std::string> getErrorInformation(const std::error_condition& source){

    std::string error_message = source.message();

    int error_code = source.value();

    std::string category_name = source.category().name();

    return std::make_tuple(error_message, error_code, category_name);
}


int main(){

    // a) Create instances of std::error_condition
    std::error_condition default_condition = std::error_condition();
    std::cout<<"default_condition message: "<< default_condition.message()<<std::endl;

    std::error_condition value_condition = std::error_condition(33, std::system_category());
    std::cout<<"value_condition message: "<< value_condition.message()<<std::endl;

    std::error_condition errc_condition = std::make_error_condition(std::errc::invalid_argument);
    std::cout<<"errc_condition message: "<< errc_condition.message()<<"\n\n";

    // b) Function test:
    std::cout<<"errc_condition info:\n";
    auto info = getErrorInformation(errc_condition);

    std::cout<<"message: "<< std::get<0>(info)<<'\n';
    std::cout<<"error code: "<< std::get<1>(info)<<'\n';
    std::cout<<"category name: "<< std::get<2>(info)<<'\n';

    return 0;
}
