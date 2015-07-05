#include <limits.h>
#include "interfaceStructureParser.h"
#include "gtest/gtest.h"

//TBD Investigate google tests' running mechanism and add new test cases

TEST(analyze, positive) {
    StructureParser parser = StructureParser();
    std::string myString = "aaa{b}bb";
    bool t = parser.analyze(myString);
    EXPECT_EQ(1, t);

}

TEST(analyze, Negative) {
    StructureParser parser = StructureParser();
    std::string myString = "aaa{bbb";
    bool t = parser.analyze(myString);
    EXPECT_EQ(0, t);

}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
