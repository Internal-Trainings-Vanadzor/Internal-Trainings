#include <iostream>

#include "Point.hpp"
#include "Line.hpp"
#include "Rect.hpp"
/*#include "Triangle.hpp"
#include "Circle.hpp"
#include "Elipse.hpp"*/

int main(){
    Point p1(2, 3);
    Point p2(5, 6);
    Line line(p1, p2);
    Rect rect(p1, 6, 7);
    std::cout<<line.getLength()<<"\n";
    std::cout<<line.area()<<"\n";
    std::cout<<rect.area()<<"\n";
    return 0;
}
