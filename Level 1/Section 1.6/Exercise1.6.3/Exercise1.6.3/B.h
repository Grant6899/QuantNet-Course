//===============================================================
// Level 1 Section 1.6 Exercise 1.6.3
// Author: Grant Liu
// Create Date: 1/8/2017
// Description: b class - h file
//===============================================================
struct B {
  explicit B(int) {}
  explicit B(int, int) {}
  explicit operator int() const {return 0; }
};
