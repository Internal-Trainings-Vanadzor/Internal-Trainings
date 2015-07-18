#include <limits.h>
#include "custom_list.cpp"
#include "gtest/gtest.h"

TEST(FactorialTest, Positive) {
    MyList<int> obj;
    for (int i = 0; i < 5; ++i) {
        obj.push_first(i);
    }
    EXPECT_EQ(5, obj.get_size());
    obj.pop_index(0);
    EXPECT_EQ(4, obj.get_size());
    obj.pop_last();
    EXPECT_EQ(3, obj.get_size());
    obj.pop_first();
    EXPECT_EQ(2, obj.get_size());
    obj.push_last(7);
    EXPECT_EQ(3, obj.get_size());
    obj.push_index(1,9);
    EXPECT_EQ(4, obj.get_size());
    obj.clear();
    EXPECT_EQ(0, obj.get_size());
}

TEST(IsPrimeTest, Negative) {
    MyList<int> obj;
    for (int i = 0; i < 15; ++i) {
        obj.push_last(i);
    }
    EXPECT_EQ(15, obj.get_size());
    obj.pop_index(20);
    EXPECT_EQ(15, obj.get_size());
    obj.clear();
    EXPECT_EQ(0, obj.pop_last());
    EXPECT_EQ(0, obj.pop_first());
    EXPECT_EQ(0, obj.pop_index(20));
    obj.push_last(7);
    obj.push_last(6);
    obj.push_index(30,5);
    EXPECT_EQ(3, obj.get_size());
}

TEST(FactorialTest, Zero) {
    MyList<int> obj;
    EXPECT_EQ(0, obj.get_size());
    obj.push_last(7);
    EXPECT_EQ(7, obj.pop_index(5));
    EXPECT_EQ(0, obj.get_size());
}
