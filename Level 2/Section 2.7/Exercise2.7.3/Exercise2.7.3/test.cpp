//===============================================================
// Level 2 Section 2.7 Exercise 2.7.3
// Author: Grant Liu
// Create Date: 1/15/2017
// Description: main file
//===============================================================
#include<iostream>
#include<fstream>
#include<system_error>

int main(){

    // a) create error condition instances based on POSIX error codes
    std::error_condition error1 = std::make_error_condition(std::errc::io_error);
    std::error_condition error2 = std::make_error_condition(std::errc::network_unreachable);
    std::error_condition error3 = std::make_error_condition(std::errc::no_such_file_or_directory);
    std::error_condition error4 = std::make_error_condition(std::errc::not_a_socket);
    std::error_condition error5 = std::make_error_condition(std::errc::permission_denied);

    // b) create error condition object based on the value 128 and the generic error category

    std::error_condition error_code128 = std::error_condition(128, std::generic_category());

    // c) Use std::make_error_condition (with std::io_errc as argument) to create an instance of std::error_condition.
    std::error_condition error_io = std::make_error_condition(std::io_errc::stream); // This doesn't compile under gcc, why? Do different compilers have different hierachy of built-in classes?

    return 0;
}
