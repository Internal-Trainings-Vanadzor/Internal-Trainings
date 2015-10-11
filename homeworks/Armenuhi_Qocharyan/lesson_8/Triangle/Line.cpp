#include <math.h>
#include "Line.hpp"

Line::Line(Point pointFirst, Point pointSecond): pointOne(pointFirst), pointTwo(pointSecond){

}

const bool Line::contains(Point point){
     if (this->pointOne.getX() == this->pointTwo.getX() &&
         this->pointOne.getY() == this->pointTwo.getY()) {
         // pointOne and pointTwo same points
         return true;
     } else if (this->pointOne.getX() == this->pointTwo.getX() && 
                this->pointOne.getX() == point.getX()) {
         // x = const
         return true;
     } else if (this->pointOne.getY() == this->pointTwo.getY() &&
                this->pointOne.getY() == point.getY()) {
         // y = const
         return true;
     } else if ((point.getX() - this->pointOne.getX())*
         (this->pointTwo.getY() - this->pointOne.getY()) ==
         (this->pointTwo.getX() - this->pointOne.getX())*
         (point.getY() - this->pointOne.getY())) {
         //Pythagorean theorem 
         return true;
     } else {
         return false;
     }
}


const float Line::area(){
    return 0;
}
