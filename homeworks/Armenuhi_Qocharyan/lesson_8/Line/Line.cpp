#ifndef MY_LINE_1 
#define MY_LINE_1
#include "Point.hpp"
#include "Line.hpp"



Line::Line(struct Point *point_first, struct Point *point_second) {
    this->point_one = point_first;
    this->point_two = point_second;
} 


bool Line::isPointInLine(float x1, float y1) {
    if (this->point_one->x == this->point_two->x && 
           this->point_one->y  == this->point_two->y) {
        // point_one and point_two same points
        return true;
    } else if (this->point_one->x == this->point_two->x == x1) {
        // x = const 
        return true;
    } else if (this->point_one->y == this->point_two->y == y1) {
        // y = const 
        return true;
    } else if ((x1-this->point_one->x)* 
               (this->point_two->y - this->point_one->y) ==
               (this->point_two->x - this->point_one->x)*
               (y1 - this->point_one->y)) {
        // 2 ketov ancnox uxxi havasarum@ errord keti koordinatner@ texadrelis talis e chshmarit nuynutyun :TBD translate this line :D 
        return true;
    } else {
        return false;
    }
}


#endif
