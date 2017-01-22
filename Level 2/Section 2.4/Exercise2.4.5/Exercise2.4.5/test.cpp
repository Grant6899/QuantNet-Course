//===============================================================
// Level 2 Section 2.4 Exercise 2.4.5
// Author: Grant Liu
// Create Date: 1/14/2017
// Description: main file
//===============================================================
#include<iostream>
#include<memory>
#include"Point.h"
#include<cstdio>

// Point deleter
auto deleter = [](Point* pt)-> void{ std::cout << "Bye:" << *pt << std::endl;};

// Free function file deleter
void FreeFinalizer (FILE* file_ptr){
    std::fclose(file_ptr);
    std::cout<<"Free File closed.\n";
}

// Lambda file deleter
auto FileFinalizer = [](FILE* file_ptr) -> void { std::fclose(file_ptr); std::cout<<"File closed.\n";};


int main(){

    // Test for Point deleter
    using SmartPoint = std::shared_ptr<Point>;
    SmartPoint p1(new Point(), deleter);

    // Test for lambda file deleter
    std::shared_ptr<FILE> mySharedFile(std::fopen("test.txt", "w"), FileFinalizer);

    try {
        for (int n=0; n < 5 ;n++){
            fprintf (mySharedFile.get(), "Line %i \n",n+1);
            if (n > 3) throw -1; // Throw exception when n > 3
        }
    } catch (int) {
        //Test for Free function file deleter
        std::shared_ptr<FILE> mySharedFile1(std::freopen("test.txt", "w", mySharedFile.get()), FreeFinalizer);
        // This works well, smart pointer will automatically clear the memory.
    }

    return 0;
}
