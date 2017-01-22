//===============================================================
// Level 1 Section 1.5 Exercise 1.5.5
// Author: Grant Liu
// Create Date: 1/8/2017
// Description: main file
//===============================================================
#include<iostream>
#include<tuple>
#include"Shape.h"
#include"Point.h"
#include"Line.h"
#include"Circle.h"
#include"IOBrief.h"
#include"IODetail.h"
#include"LineBriefBuilder.h"
#include"CircleDetailBuilder.h"


using std::tuple;
using std::cout;
using std::endl;


int main(){
//Test for IO classes, display function of Circle and Lines
  cout << "Test for IO classes, display function of Circle and Lines:" << endl;
  Circle circle(4, Point(-1,1));
  Line line(Point(0, 1), Point(1,0));

  IODetail iod;
  IOBrief iob;
  iod.operator<<(circle);
  
  line.display(iob);
  
  cout << endl;
  //Builder Tests:
  cout<<"Builder tests:"<<endl;
  LineBriefBuilder b1;
  auto tuple1 = b1.getProduct();
  std::get<0>(tuple1)->display(*std::get<1>(tuple1));
   
  CircleDetailBuilder b2;
  auto tuple2 = b2.getProduct();
  std::get<0>(tuple2)->display(*std::get<1>(tuple2));

  return 0;
}
