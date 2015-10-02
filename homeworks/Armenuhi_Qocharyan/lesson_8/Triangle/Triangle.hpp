#ifndef MY_TRIANGLE 
#define MY_TRIANGLE
#include <iostream>

class Triangle {

private:
      struct Point *point_one;
      struct Point *point_two;
      struct Point *point_thirds;

public:
       /*
	* The constructor
	*
	*/
      Triangle(struct Point *point_first, 
               struct Point *point_second, 
               struct Point *point_thirds); 

      /*
       * Calculate area
       */
      int area(); 
      /*
      * Check if it is some point
      */
      bool isInside(int x1, int y1); 
      private: int area(int x1, int y1, int x2, int y2, int x3, int y3); 
      
      
};

#endif
