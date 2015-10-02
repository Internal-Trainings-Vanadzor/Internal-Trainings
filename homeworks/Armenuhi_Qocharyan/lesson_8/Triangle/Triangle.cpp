#ifndef MY_TRIANGLE_1 
#define MY_TRIANGLE_1
#include <stdio.h>
#include <stdlib.h>
#include "Point.hpp"
#include "Triangle.hpp"



Triangle::Triangle(struct Point *point_first, 
           struct Point *point_second, 
           struct Point *point_thirds) {
    this->point_one = point_first;
    this->point_two = point_second;
    this->point_thirds = point_thirds;
} 


int Triangle::area() {
    return abs ((this->point_one->x *
           (this->point_two->y - this->point_thirds->y) + 
            this->point_two->x *
           (this->point_thirds->y - this->point_one->y) + 
            this->point_thirds->x * 
           (this->point_one->y - this->point_two->y))/2.0);
} 


int Triangle::area(int x1, int y1, int x2, int y2, int x3, int y3){
     return abs ((x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2))/2.0);
} 

// coordinats of p x1, y1
bool Triangle::isInside(int x1, int y1) {
   /* Calculate area of triangle ABC */
   int A = area (this->point_one->x, this->point_one->y, 
                   this->point_two->x, this->point_two->y, 
                   this->point_thirds->x, this->point_thirds->y);
 
   /* Calculate area of triangle PBC */  
   int A1 = area (x1, y1, this->point_two->x, this->point_two->y, 
                   this->point_thirds->x, this->point_thirds->y);
 
   /* Calculate area of triangle PAC */  
   int A2 = area (this->point_one->x, this->point_one->y, x1, y1,  
                    this->point_thirds->x, this->point_thirds->y);
 
   /* Calculate area of triangle PAB */   
   int A3 = area (this->point_one->x, this->point_one->y, 
                   this->point_two->x, this->point_two->y, x1, y1);
   
   /* Check if sum of A1, A2 and A3 is same as A */
   return (A == A1 + A2 + A3);
}
      


#endif
