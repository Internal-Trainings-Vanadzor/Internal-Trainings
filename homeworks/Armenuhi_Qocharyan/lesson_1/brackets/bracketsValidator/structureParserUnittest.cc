#include <limits.h>
#include "interfaceStructureParser.h"
#include "gtest/gtest.h"

//TBD Investigate google tests' running mechanism and add new test cases

TEST(analyze, Positive_1) {
    StructureParser parser = StructureParser();
    std::string myString = "aaa{b}bb";
    bool t = parser.analyze(myString);
    EXPECT_EQ(1, t);

}

TEST(analyze, Positive_2) {
    StructureParser parser = StructureParser();
    std::string myString = "aaa'{b}'bb";
    bool t = parser.analyze(myString);
    EXPECT_EQ(1, t);

}

TEST(analyze, Positive_3) {
    StructureParser parser = StructureParser();
    std::string myString = "aaa'{b}'bb";
    bool t = parser.analyze(myString);
    EXPECT_EQ(1, t);

}

TEST(analyze, Positive_4) {
    StructureParser parser = StructureParser();
    std::string myString = "";
    bool t = parser.analyze(myString);
    EXPECT_EQ(1, t);

}

TEST(analyze, Positive_5) {
    StructureParser parser = StructureParser();
    std::string myString = "{}[]''";
    bool t = parser.analyze(myString);
    EXPECT_EQ(1, t);

}
TEST(analyze, Negative_1) {
    StructureParser parser = StructureParser();
    std::string myString = "aaa{bbb";
    bool t = parser.analyze(myString);
    EXPECT_EQ(0, t);

}


TEST(analyze, Negative_2) {
    StructureParser parser = StructureParser();
    std::string myString = "aaa'{'b}bb";
    bool t = parser.analyze(myString);
    EXPECT_EQ(0, t);

}


TEST(analyze, Negative_3) {
    StructureParser parser = StructureParser();
    std::string myString = "aaa[{b]}bb";
    bool t = parser.analyze(myString);
    EXPECT_EQ(0, t);

}



int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
