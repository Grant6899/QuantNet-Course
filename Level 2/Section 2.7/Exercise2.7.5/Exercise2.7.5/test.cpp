//===============================================================
// Level 2 Section 2.7 Exercise 2.7.5
// Author: Grant Liu
// Create Date: 1/15/2017
// Description: main file
//===============================================================
#include<iostream>
#include<system_error>
#include<fstream>
#include<string>

int main(){

	std::ifstream file(std::string("DOESNOTEXIST.txt"));

    try {
        // Set the exception mask of the file stream
        // In this case 1) logical error on I/O operation or
        // 2) read/write error on I/O operation
        file.exceptions(file.failbit | file.badbit);
    }
    catch (const std::ios_base::failure& e) {

        if (e.code() == std::io_errc::stream){
            // Create an error code instance ec1 with e.code as argument
            auto ec1 = std::error_code(e.code());
			// Create an error condition ec2 instance with ec1 as argument
            auto ec2 = std::error_condition(e.code().value(), e.code().category());
			// Print the properties value, message and error category of ec2:
			std::cout <<"ec2 value: " << ec2.value() << std::endl;
			std::cout <<"ec2 message: "<< ec2.message() << std::endl;
			std::cout <<"ec2 category: " << ec2.category().name() << std::endl;
        }

    }
    catch (...) {
        std::cout <<"catch all\n";
    }

    return 0;
}
