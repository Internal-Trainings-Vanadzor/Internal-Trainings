#ifndef MY_LINE 
#define MY_LINE
#include <iostream>

class Line {

private:
      struct Point *point_one;
      struct Point *point_two;

public:
       /*
	* The constructor
	*
	*/
      Line(struct Point *point_first, struct Point *point_second); 

      /*
      * Check if it is some point
      */
      bool isPointInLine(float x1, float y1); 
};

#endif
