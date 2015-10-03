#include <iostream>

#include "Point.hpp"
#include "Line.hpp"
#include "Rect.hpp"
/*#include "Triangle.hpp"
#include "Circle.hpp"
#include "Elipse.hpp"*/

int main(){
    Point* p1 = new Point(2, 3);
    Point* p2 = new Point(5, 6);
    Line* line = new Line (p1, p2);
    Rect* rect = new Rect (p1, 6, 7);
    std::cout<<"Pass"<<"\n";
    std::cout<<(*line).getLength()<<"\n";
    std::cout<<(*rect).getArea()<<"\n";
    return 0;
}
