#ifndef MY_REC 
#define MY_REC 

#include <iostream>
#include "point.cpp"
#include "object.cpp"

class MyRectangle {
    public:
        void setPoint1(const MyPoint& arg);
        void setPoint2(const MyPoint& arg);
        void setPoint3(const MyPoint& arg);
        void setPoint4(const MyPoint& arg);
        const MyPoint& getPoint1() const ;
        const MyPoint& getPoint2() const ;
        const MyPoint& getPoint3() const ;
        const MyPoint& getPoint4() const ;
        MyRectangle(const MyPoint& _p1, const MyPoint& _p2,
                MyPoint _p3, MyPoint _p4);
        MyRectangle(const MyRectangle&);
        ~MyRectangle();
        // 
        float area() const;
        bool isContains(const MyPoint&) const;
    private:
        float area(const MyPoint&, const MyPoint&, const MyPoint&) const;
    private:
        MyPoint _point1;
        MyPoint _point2;
        MyPoint _point3;
        MyPoint _point4;
};

#endif
