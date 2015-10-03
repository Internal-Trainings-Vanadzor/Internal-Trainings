#ifndef MY_POINT 
#define MY_POINT
#include <iostream>

class Point {

private:
      float x;
      float y;

public:
       /*
	* The constructor
	*
	*/
      Point(float x, float y); 

      /*
      * Check if it is some point
      */
      bool isMyPoint(float x1, float y1); 
};

#endif
