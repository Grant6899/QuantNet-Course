//===============================================================
// Level 2 Section 2.7 Exercise 2.7.1
// Author: Grant Liu
// Create Date: 1/15/2017
// Description: main file
//===============================================================

#define BOOST_ERROR_CODE_HEADER_ONLY
#include"boost/system/error_code.hpp"
#include<iostream>
#include<fstream>
#include<system_error>

// boost error condition
boost::system::error_condition BoostPrintFile(std::string filename){

    std::ifstream ifs(filename.c_str());

    if (!ifs.is_open())
        return boost::system::errc::make_error_condition(boost::system::errc::no_such_file_or_directory);

    std::cout<<ifs.rdbuf()<<std::endl;

    ifs.close();

    return boost::system::error_condition();
}

// std c++11 error condition
std::error_condition StdPrintFile(std::string filename){

    std::ifstream ifs(filename.c_str());

    if (!ifs.is_open())
        return std::make_error_condition(std::errc::no_such_file_or_directory);

    std::cout<<ifs.rdbuf()<<std::endl;

    ifs.close();

    return std::error_condition();
}



int main(){

	// boost test:
    // Print an existing file
    std::cout<<BoostPrintFile("test.txt").message()<<'\n';
    // Print an file not existing
    std::cout<<BoostPrintFile("NOFILE.txt").message()<<'\n';

    // std test:
    // Print an existing file
    std::cout<<StdPrintFile("test.txt").message()<<'\n';
    // Print an file not existing
    std::cout<<StdPrintFile("NOFILE.txt").message()<<'\n';
	

    return 0;
}
