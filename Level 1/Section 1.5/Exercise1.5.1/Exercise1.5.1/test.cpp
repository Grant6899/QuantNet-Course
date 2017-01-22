//===============================================================
// Level 1 Section 1.5 Exercise 1.5.1
// Author: Grant Liu
// Create Date: 1/8/2017
// Description: main file
//===============================================================
#include<tuple>
#include<string>
#include<vector>
#include<algorithm>
#include"boost/date_time/gregorian/gregorian.hpp"
#include"boost/date_time/date_defs.hpp"

//Namespace declaration
using std::vector;
using std::get;
using std::cout;
using std::endl;
using namespace boost::gregorian;

//Alias for tuple
using Person = std::tuple<std::string, std::string, date>;

//funtion to print person information
void print(Person p){
  cout<<get<0>(p)<<", "<<get<1>(p)<<", "<<get<2>(p)<<endl;
}

int main(){

  //Initialize three persons
  Person p1 {"James", "New York", date(2002, Jan, 10)};
  Person p2 {"Francis", "Paris", date(2000, Feb, 1)};
  Person p3 {"Jee Hye", "Seoul", date(1998, Jun, 20)};

  //Create a vector to store three persons
  vector<Person> vec_student = {p1, p2, p3};

  //Sort them by birthdate
  std::sort(vec_student.begin(), vec_student.end(),
            [](const Person& p1, const Person& p2){
              return get<2>(p1) < get<2>(p2);
            });

  //Print out sorted result
  std::for_each(vec_student.begin(), vec_student.end(), print);

  return 0;
}
