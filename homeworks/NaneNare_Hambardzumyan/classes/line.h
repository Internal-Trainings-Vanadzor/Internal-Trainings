#ifndef MY_OBJECT 
#define MY_OBJECT 

#include <iostream>
#include "point.cpp"
#include "object.cpp"

class MyLine {
    public:
        void setStart(const MyPoint& arg);
        void setEnd(const MyPoint& arg);
        const MyPoint& getStart();
        const MyPoint& getEnd();
        MyLine(const MyPoint& _x , const MyPoint& _y );
        MyLine(MyLine&);
        ~MyLine();
        // 
        float area();
        bool isContains(MyPoint);
    private:
        float area(MyPoint, MyPoint);
    private:
        MyPoint _start;
        MyPoint _end;
};

#endif
