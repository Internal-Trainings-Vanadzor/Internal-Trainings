#ifndef MY_LINE
#define MY_LINE
#include "Point.hpp"
class Line{
    private:
        Point pointOne;
        Point pointTwo;
    
    public:
        Line(Point pointFirst, Point pointSecond);
        const float area();
        const bool contains(Point point);
};
#endif
