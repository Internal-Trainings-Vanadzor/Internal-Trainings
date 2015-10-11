#ifndef MY_TRIANGLE 
#define MY_TRIANGLE
#include <iostream>
#include "Point.hpp"

class Triangle {

private:
      Point point_one;
      Point point_two;
      Point point_thirds;
      float area(Point point_1, Point point_2, Point point_3); 

public:
       /**
	* The constructor
	*
	*/
      Triangle(Point point_first, 
               Point point_second, 
               Point point_thirds); 

      /**
       * Calculate area
       */
      float area(); 
      /**
       * Check if it is some point
       */
      bool isInside(Point point); 
      
      
};

#endif
