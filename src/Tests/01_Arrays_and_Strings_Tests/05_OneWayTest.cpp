#include <gtest/gtest.h>

#include "05_OneWay.h"

TEST(OneWay, Case1) {
    EXPECT_TRUE(isNoMoreThan1LetterEdit("pale", "ple"));
}

TEST(OneWay, Case2) {
    EXPECT_TRUE(isNoMoreThan1LetterEdit("pales", "pale"));
}

TEST(OneWay, Case3) {
    EXPECT_TRUE(isNoMoreThan1LetterEdit("pale", "bale"));
}

TEST(OneWay, Case4) {
    EXPECT_FALSE(isNoMoreThan1LetterEdit("pale", "bake"));
}

TEST(OneWay, Case5) {
    EXPECT_TRUE(isNoMoreThan1LetterEdit("p", ""));
}

TEST(OneWay, Case6) {
    EXPECT_TRUE(isNoMoreThan1LetterEdit("abcd", "abcd"));
}

TEST(OneWay, Case7) {
    EXPECT_TRUE(isNoMoreThan1LetterEdit("", ""));
}

TEST(OneWay, Case8) {
    EXPECT_FALSE(isNoMoreThan1LetterEdit("ab", ""));
}
