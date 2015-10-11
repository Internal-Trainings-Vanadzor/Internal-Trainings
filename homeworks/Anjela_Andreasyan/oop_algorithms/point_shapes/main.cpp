#include <iostream>
#include <stdlib.h>     
#include <time.h>  
#include <vector>

#include "Point.hpp"
#include "Line.hpp"
#include "Rect.hpp"
#include "Sort.hpp"
/*#include "Triangle.hpp"
#include "Circle.hpp"
#include "Elipse.hpp"*/

#include "Canvas.hpp"

int main(){

    Point p1(2, 3);
    Point p2(5, 6);
    Line line(p1, p2);
    Rect rect(p1, 6, 7);
    std::cout<<line.getLength()<<"\n";
    std::cout<<line.area()<<"\n";
    std::cout<<rect.area()<<"\n";
    int count = 15;
    std::vector<Rect> rects;
    srand (time(NULL));
    std::cout<<"Before sorting... \n";
    for( int i = 0; i<count; i++){
        int height =  rand() % 100 + 1;
        int width = rand() % 200 + 1;
        Rect recti(p1, height, width);
        std::cout<<"Rect i area " << recti.area()<<"\n";
        rects.push_back(recti);
    }
    SortShapes sort;
    sort.bubbleSort(&rects[0], count);
    std::cout<<"After sorting... \n";
    for(std::vector<Rect>::size_type i = 0; i != rects.size(); i++) {
        std::cout<<"Rect i area " << rects[i].area()<<"\n";
    }
    Canvas canvas;
    canvas.pointComponent();
    return 0;
}
