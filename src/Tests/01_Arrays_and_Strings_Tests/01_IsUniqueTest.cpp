#include <gtest/gtest.h>

#include "01_IsUnique.h"

TEST(IsUniqueTest, Test1Unique) {
    EXPECT_TRUE(IsUnique("awsedril"));
}

TEST(IsUniqueTest, Test1NotUnique) {
    EXPECT_FALSE(IsUnique("awsedaril"));
}

TEST(IsUniqueTest, Test1Empty) {
    EXPECT_TRUE(IsUnique(""));
}

TEST(IsUniqueTest, Test2Unique) {
    EXPECT_TRUE(IsUnique2("awsedril"));
}

TEST(IsUniqueTest, Test2NotUnique) {
    EXPECT_FALSE(IsUnique2("awsedaril"));
}

TEST(IsUniqueTest, Test2Empty) {
    EXPECT_TRUE(IsUnique2(""));
}

TEST(IsUniqueTest, Test3Unique) {
    EXPECT_TRUE(IsUnique3("awsedril"));
}

TEST(IsUniqueTest, Test3NotUnique) {
    EXPECT_FALSE(IsUnique3("awsedaril"));
}

TEST(IsUniqueTest, Test3Empty) {
    EXPECT_TRUE(IsUnique3(""));
}
