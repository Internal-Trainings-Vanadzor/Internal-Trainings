#include <limits.h>
#include "Point.hpp"
#include "gtest/gtest.h"


TEST(analyze, Positive_1) {
    Point *point = new Point(1.1,2.0);
    bool isEqual = point->isMyPoint(1.1,2.0);
    delete point;	
    EXPECT_EQ(isEqual, true);
}


TEST(analyze, Negative_1) {
    Point *point = new Point(1.1,2.0);
    bool isEqual = point->isMyPoint(1.0,2.0);	
    delete point;	
    EXPECT_EQ(isEqual, false);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
