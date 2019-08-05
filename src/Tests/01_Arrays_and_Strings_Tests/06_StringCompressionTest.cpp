#include <gtest/gtest.h>

#include "06_StringCompression.h"

TEST(StringCompression, Case1) {
    EXPECT_STREQ(Compress("aabcccccaaa").c_str(), "a2b1c5a3");
}

TEST(StringCompression, Case2) {
    EXPECT_STREQ(Compress("abcdd").c_str(), "abcdd");
}

TEST(StringCompression, Case3) {
    EXPECT_STREQ(Compress("aaaaaaaaa").c_str(), "a9");
}

TEST(StringCompression, Case4) {
    EXPECT_STREQ(Compress("abbccc").c_str(), "abbccc");
}

TEST(StringCompression, Case5) {
    EXPECT_STREQ(Compress("").c_str(), "");
}
