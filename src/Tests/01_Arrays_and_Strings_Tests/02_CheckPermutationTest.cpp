#include <gtest/gtest.h>

#include "02_CheckPermutation.h"

TEST(CheckPermutation, Case1) {
    EXPECT_FALSE(isPermutation("qweqrty", "rewqty"));
}

TEST(CheckPermutation, Case2) {
    EXPECT_TRUE(isPermutation("uirewoer", "iuwerroe"));
}

TEST(CheckPermutation, Case3) {
    EXPECT_TRUE(isPermutation("abcsdfsdfsf", "afdscfsdbsf"));
}

TEST(CheckPermutation, Case4) {
    EXPECT_FALSE(isPermutation("aaab", "aabb"));
}

TEST(CheckPermutation, Case5Empty) {
    EXPECT_TRUE(isPermutation("", ""));
}
