#include <limits.h>
#include "Array.h"
#include "gtest/gtest.h"

//TBD Need to add new test cases

TEST(analyze, Positive_1) {
    Array array = Array(10);
    array.insert(9, 8);
    array.printArray();
    EXPECT_EQ(8, array.get(9));
}


TEST(analyze, Positive_2) {
    Array array = Array(10);
    array.insert(9, 8);
    array.printArray();
    EXPECT_EQ(0, array.get(10));
    EXPECT_EQ(8, array.get(9));
    EXPECT_EQ(0, array.get(0));
    EXPECT_EQ(0, array.get(1));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
