#include <limits.h>
#include "BinaryTree.hpp"
#include "gtest/gtest.h"

//TBD Need to add new test cases

TEST(analyze, Positive_1) {
    BinaryTree myTree;
    myTree.insert(8);
    myTree.insert(6);
    myTree.insert(12);
    myTree.removeElement(12);
    myTree.removeElement(15);
    bool a = myTree.exists(8);
    EXPECT_EQ(1, a);

}


TEST(analyze, Positive_2) {
	//TBD
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
