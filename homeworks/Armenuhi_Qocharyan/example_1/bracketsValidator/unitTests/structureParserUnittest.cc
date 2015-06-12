#include <limits.h>
#include "implementationStructureParser.h"
#include "gtest/gtest.h"

//TBD Investigate google tests' running mechanism and add new test cases

TEST(analyze, positive) {
    std::string myString = "aaa{b}bb";
    StructureParser test = StructureParser();
    EXPECT_EQ(1, test.analyze(myString));

}

TEST(analyze, Negative) {
    std::string myString = "aaa{bbb";
    StructureParser test = StructureParser();
    EXPECT_EQ(0, test.analyze(myString));

}

TEST(analyze, Negative1) {
    std::string myString = "aaa[{b]aa}bb";
    StructureParser test = StructureParser();
    EXPECT_EQ(0, test.analyze(myString));

}


TEST(analyze, Negative2) {
    std::string myString = "aaa[{b}][aabb";
    StructureParser test = StructureParser();
    EXPECT_EQ(0, test.analyze(myString));

}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
