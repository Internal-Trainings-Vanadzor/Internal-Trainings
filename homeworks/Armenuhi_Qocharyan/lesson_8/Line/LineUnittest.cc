#include <limits.h>
#include "Point.hpp"
#include "Line.hpp"
#include "gtest/gtest.h"


TEST(analyze, Positive_1) {
    Point *point_1 = new Point(1.1,2.0);
    Point *point_2 = new Point(1.1,2.0);
    Line *line = new Line(point_1,point_2);
    bool isEqual = line->isPointInLine(1.1,2.0);
    delete point_1;	
    delete point_2;	
    delete line;	
    EXPECT_EQ(isEqual, true);
}


TEST(analyze, Positive_2) {
    Point *point_1 = new Point(1.1,3.0);
    Point *point_2 = new Point(1.1,2.0);
    Line *line = new Line(point_1,point_2);
    bool isEqual = line->isPointInLine(1.1,8.0);
    delete point_1;	
    delete point_2;	
    delete line;	
    EXPECT_EQ(isEqual, true);
}

TEST(analyze, Positive_3) {
    Point *point_1 = new Point(1.1,2.0);
    Point *point_2 = new Point(1.2,2.0);
    Line *line = new Line(point_1,point_2);
    bool isEqual = line->isPointInLine(1.0,2.0);
    delete point_1;	
    delete point_2;	
    delete line;	
    EXPECT_EQ(isEqual, true);
}


TEST(analyze, Positive_4) {
    Point *point_1 = new Point(1.0,1.0);
    Point *point_2 = new Point(2.0,2.0);
    Line *line = new Line(point_1,point_2);
    bool isEqual = line->isPointInLine(3.0,3.0);
    delete point_1;	
    delete point_2;	
    delete line;	
    EXPECT_EQ(isEqual, true);
}

TEST(analyze, Negative_1) {
    Point *point_1 = new Point(1.0,1.0);
    Point *point_2 = new Point(3.0,2.0);
    Line *line = new Line(point_1,point_2);
    bool isEqual = line->isPointInLine(3.0,3.0);
    delete point_1;	
    delete point_2;	
    delete line;	
    EXPECT_EQ(isEqual, false);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
