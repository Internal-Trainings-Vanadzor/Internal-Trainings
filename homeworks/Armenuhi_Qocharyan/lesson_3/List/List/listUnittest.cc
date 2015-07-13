#include <limits.h>
#include "interfaceList.h"
#include "gtest/gtest.h"

//TBD Investigate google tests' running mechanism and add new test cases

TEST(analyze, Positive_1) {
    struct Node *head = new Node;
    List list_object(10);	
    list_object.printList();
    EXPECT_EQ(10, list_object.head->data);
}


TEST(analyze, Positive_2) {
    struct Node *head = new Node;
    List list_object(10);	
    list_object.addMyNode(20,1);
    list_object.addMyNode(30,2);
    list_object.printList();
    EXPECT_EQ(30, list_object.searchNode(30)->data);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
