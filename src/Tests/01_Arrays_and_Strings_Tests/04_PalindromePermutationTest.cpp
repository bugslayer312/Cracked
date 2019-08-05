#include <gtest/gtest.h>

#include "04_PalindromePermutation.h"

TEST(PalindromePermutation, FirstCase1) {
    EXPECT_TRUE(isPalPerm("qweqrty ewqryt"));
}

TEST(PalindromePermutation, FirstCase2) {
    EXPECT_TRUE(isPalPerm("Tact Coa"));
}

TEST(PalindromePermutation, FirstCase3) {
    EXPECT_FALSE(isPalPerm("awsedril"));
}

TEST(PalindromePermutation, FirstCase4) {
    EXPECT_TRUE(isPalPerm("  abc ba caba "));
}

TEST(PalindromePermutation, FirstCase5Blank) {
    EXPECT_TRUE(isPalPerm("  "));
}

TEST(PalindromePermutation, FirstCase6Empty) {
    EXPECT_TRUE(isPalPerm(""));
}


// Second version

TEST(PalindromePermutation, SecondCase1) {
    EXPECT_TRUE(isPalPerm("qweqrty ewqryt"));
}

TEST(PalindromePermutation, SecondCase2) {
    EXPECT_TRUE(isPalPerm("Tact Coa"));
}

TEST(PalindromePermutation, SecondCase3) {
    EXPECT_FALSE(isPalPerm("awsedril"));
}

TEST(PalindromePermutation, SecondCase4) {
    EXPECT_TRUE(isPalPerm("  abc ba caba "));
}

TEST(PalindromePermutation, SecondCase5Blank) {
    EXPECT_TRUE(isPalPerm("  "));
}

TEST(PalindromePermutation, SecondCase6Empty) {
    EXPECT_TRUE(isPalPerm(""));
}
