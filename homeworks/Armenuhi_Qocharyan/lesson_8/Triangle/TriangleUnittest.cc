#include <limits.h>
#include "Point.hpp"
#include "Triangle.hpp"
#include "gtest/gtest.h"


TEST(analyze, Positive_1) {
    Point *point_1 = new Point(4,0);
    Point *point_2 = new Point(0,0);
    Point *point_3 = new Point(2,15);
    Triangle *triangle = new Triangle(point_1,point_2,point_3);
    EXPECT_EQ(triangle->isInside(2,2), true);
    delete point_1;	
    delete point_2;	
    delete point_3;
    delete triangle;	
}



TEST(analyze, Negative_2) {
    Point *point_1 = new Point(1,0);
    Point *point_2 = new Point(6,5);
    Point *point_3 = new Point(0,4);
    Triangle *triangle = new Triangle(point_1,point_2,point_3);
    EXPECT_EQ(triangle->isInside(20,20), false);
    delete point_1;	
    delete point_2;	
    delete point_3;
    delete triangle;	
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
