#ifndef MY_LINE 
#define MY_LINE 

#include <iostream>
#include "point.cpp"
#include "object.cpp"

class MyLine {
    public:
        void setStart(const MyPoint& arg);
        void setEnd(const MyPoint& arg);
        const MyPoint& getStart() const;
        const MyPoint& getEnd() const;
        MyLine(const MyPoint& _x , const MyPoint& _y );
        MyLine(const MyLine&);
        ~MyLine();
        // 
        float area() const;
        bool isContains(const MyPoint&) const;
    private:
        MyPoint _start;
        MyPoint _end;
};

#endif
