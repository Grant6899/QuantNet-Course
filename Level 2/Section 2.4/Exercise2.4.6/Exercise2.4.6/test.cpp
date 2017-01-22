//===============================================================
// Level 2 Section 2.4 Exercise 2.4.6
// Author: Grant Liu
// Create Date: 1/14/2017
// Description: main file
//===============================================================
#include<iostream>
#include<memory>

int main(){

    // a)
    // Declare a shared_ptr pointing to d
    std::shared_ptr<double> d_sptr(new double(1.0));
    std::cout<<"d_sptr.use_count(): "<< d_sptr.use_count()<<'\n'; //1

    std::weak_ptr<double> d_wptr(d_sptr); // Will not change d_sptr.use_count()
    std::cout<<"d_sptr.use_count(): "<< d_sptr.use_count()<<'\n'; //1

    std::shared_ptr<double> d_sptr1(d_sptr);
    std::cout<<"d_sptr.use_count(): "<< d_sptr.use_count()<<'\n'; //2

    // b) assign a weak pointer to a shared pointer
    std::shared_ptr<double> d_sptr2(d_wptr);
    std::cout<<"d_sptr.use_count(): "<< d_sptr.use_count()<<'\n'; //3
    std::cout<<"d_wptr.use_count(): "<< d_wptr.use_count()<<'\n'; //3
    // check empty?
    std::cout<<std::boolalpha<<"Is d_wptr expired? "<< d_wptr.expired() <<'\n';
    // Weak_ptr to shared_ptr assignment will increase use_count()

    // c) assign a weak pointer to a weak pointer
    std::weak_ptr<double> d_wptr1(d_wptr);
    std::cout<<"d_sptr.use_count(): "<< d_sptr.use_count()<<'\n'; //3
    std::cout<<"d_wptr.use_count(): "<< d_wptr.use_count()<<'\n'; //3
    std::cout<<"d_wptr1.use_count(): "<< d_wptr1.use_count()<<'\n'; //3
    // Weak_ptr to weak_ptr assignment will not increase use_count()

    return 0;
}
