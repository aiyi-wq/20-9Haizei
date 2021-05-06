/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 23 Jun 2020 01:57:15 PM CST
 ************************************************************************/
#include <stdio.h>
#include <gtest/gtest.h>

int add(int a, int b) {
    return a + b;
}

TEST(func, add) {
    EXPECT_EQ(add(2, 3), 5);
    EXPECT_EQ(add(3, 4), 7);
    ASSERT_EQ(add(3, 6), 8);
    EXPECT_EQ(add(-2, 3), 5);
    EXPECT_EQ(add(0, 3), 3);
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);//将命令行参数传递给gtest
    return RUN_ALL_TESTS();   //RUN_ALL_TESTS()运行所有测试案例
}
