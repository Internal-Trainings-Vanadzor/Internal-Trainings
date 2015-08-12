#include <limits.h>
#include "BinaryTree.hpp"
#include "gtest/gtest.h"

//TBD Need to add new test cases

TEST(analyze, Positive_left) {
    BinaryTree myTree;
    myTree.insert(8);
    myTree.insert(6);
    myTree.insert(12);
    myTree.insert(5);
    myTree.insert(4);
   // myTree.removeElement(12);
   // myTree.removeElement(15);
    Node* test = myTree.search(5);
    std::cout << test->right->key_value << "\n";
    EXPECT_EQ(6, test->right->key_value);
    std::cout << test->left->key_value << "\n";
    EXPECT_EQ(4, test->left->key_value);
    bool a = myTree.exists(8);
    std::cout << a << "---------------" << "\n";
    EXPECT_EQ(1, a);

}


TEST(analyze, Positive_right) {
    BinaryTree myTree;
    myTree.insert(8);
    myTree.insert(6);
    myTree.insert(12);
    myTree.insert(13);
    myTree.insert(14);
    Node* test = myTree.search(13);
    std::cout << test->right->key_value << "\n";
    EXPECT_EQ(14, test->right->key_value);
    std::cout << test->left->key_value << "\n";
    EXPECT_EQ(12, test->left->key_value);
	//TBD
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
