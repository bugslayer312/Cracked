#include <gtest/gtest.h>

#include "06_Palindrome.h"

TEST(ListPalindrome, Case1) {
    auto l1 = ListNode::Create({'h', 'e', 'l', 'l', 'o', '1', 'o', 'l', 'l', 'e', 'h'});
    EXPECT_TRUE(IsPalindrome(l1));
}

TEST(ListPalindrome, Case2) {
    auto l1 = ListNode::Create({'h', 'e', 'l', 'l', 'o', 'o', 'l', 'l', 'e', 'h'});
    EXPECT_TRUE(IsPalindrome(l1));
}

TEST(ListPalindrome, Case3) {
    auto l1 = ListNode::Create({'h', 'e', 'l', 'o', 'o', 'l', 'l', 'e', 'h'});
    EXPECT_FALSE(IsPalindrome(l1));
}

TEST(ListPalindrome, Case4One) {
    auto l1 = ListNode::Create({'h'});
    EXPECT_TRUE(IsPalindrome(l1));
}

TEST(ListPalindrome, Case5Two) {
    auto l1 = ListNode::Create({'h', 'h'});
    EXPECT_TRUE(IsPalindrome(l1));
}

TEST(ListPalindrome, Case6) {
    auto l1 = ListNode::Create({'h', 'e', 'h'});
    EXPECT_TRUE(IsPalindrome(l1));
}

TEST(ListPalindrome, Case7Empty) {
    EXPECT_TRUE(IsPalindrome(nullptr));
}

