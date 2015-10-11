#ifndef MY_TRIANGLE_1 
#define MY_TRIANGLE_1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Point.hpp"
#include "Triangle.hpp"



Triangle::Triangle(Point point_first, 
           Point point_second, 
           Point point_thirds): 
           point_one(point_first), 
           point_two(point_second), 
           point_thirds(point_thirds) 
{
} 


float Triangle::area() {
    return area(this->point_one, this->point_two, this->point_thirds);
} 

//TBD: Add accuracy checking mechanism
float Triangle::area(Point point_1, Point point_2, Point point_3){
     return sqrt(fabs ((point_1.getX()*(point_2.getY() - point_3.getY())
            + point_2.getX()*(point_3.getY() - point_1.getY()) 
            + point_3.getX()*(point_1.getY() - point_2.getY()))*0.5));
} 

// coordinats of p x1, y1
bool Triangle::isInside(Point point) {
   /* Calculate area of triangle ABC */
   float A = area (this->point_one,  
                   this->point_two, 
                   this->point_thirds);
 
   /* Calculate area of triangle PBC */  
   float A1 = area (point, 
                    this->point_two,
                    this->point_thirds);
 
   /* Calculate area of triangle PAC */  
   float A2 = area (this->point_one, 
                     point,  
                     this->point_thirds);
 
   /* Calculate area of triangle PAB */   
   float A3 = area (this->point_one, 
                    this->point_two, 
                    point);
   /* Check if sum of A1, A2 and A3 is same as A */
   return (A == A1 + A2 + A3);
}
      


#endif
