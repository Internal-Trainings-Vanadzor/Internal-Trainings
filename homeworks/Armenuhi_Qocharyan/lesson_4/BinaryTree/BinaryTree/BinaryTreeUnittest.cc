#include <limits.h>
#include "BinaryTree.h"
#include "gtest/gtest.h"

//TBD Need to add new test cases

TEST(analyze, Positive_1) {
    BinaryTree myTree;
    myTree.insert(8);
    myTree.insert(6);
    myTree.insert(12);
    Node *b = myTree.removeElement(12);
    Node *a = myTree.search(8);
    std::cout << a->exists << "\n";
    EXPECT_EQ(1, a->exists);

}


TEST(analyze, Positive_2) {
    BinaryTree myTree;
    myTree.insert(8);
    myTree.insert(6);
    myTree.insert(12);
    Node *b = myTree.removeElement(12);
    Node *a = myTree.search(8);
    std::cout << a->exists << "\n";
    EXPECT_EQ(0, b->exists);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
