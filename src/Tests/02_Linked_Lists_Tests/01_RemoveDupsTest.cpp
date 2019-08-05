#include <gtest/gtest.h>

#include "01_RemoveDups.h"

TEST(RemoveDups, Ver1Case1) {
    auto l1 = ListNode::Create({4, 1, 0, 5, 10, 2, 1, 1, 0});
    auto l2 = ListNode::Create({4, 1, 0, 5, 10, 2});
    RemoveDup1(l1);
    EXPECT_TRUE(ListsIsEqual(l1, l2));
}

TEST(RemoveDups, Ver1Case2) {
    auto l1 = ListNode::Create({4, 1, 0, 5, 10, 2, 1, 1, 0, 4, 3});
    auto l2 = ListNode::Create({4, 1, 0, 5, 10, 2, 3});
    RemoveDup1(l1);
    EXPECT_TRUE(ListsIsEqual(l1, l2));
}

TEST(RemoveDups, Ver1Case3Unique) {
    auto l1 = ListNode::Create({4, 1, 0, 5, 10, 2});
    auto l2 = ListNode::Create({4, 1, 0, 5, 10, 2});
    RemoveDup1(l1);
    EXPECT_TRUE(ListsIsEqual(l1, l2));
}

TEST(RemoveDups, Ver1Case4Empty) {
    NodePtr l1;
    NodePtr l2;
    RemoveDup1(l1);
    EXPECT_TRUE(ListsIsEqual(l1, l2));
}

TEST(RemoveDups, Ver2Case1) {
    auto l1 = ListNode::Create({4, 1, 0, 5, 10, 2, 1, 1, 0});
    auto l2 = ListNode::Create({4, 1, 0, 5, 10, 2});
    RemoveDup2(l1);
    EXPECT_TRUE(ListsIsEqual(l1, l2));
}

TEST(RemoveDups, Ver2Case2) {
    auto l1 = ListNode::Create({4, 1, 0, 5, 10, 2, 1, 1, 0, 4, 3});
    auto l2 = ListNode::Create({4, 1, 0, 5, 10, 2, 3});
    RemoveDup2(l1);
    EXPECT_TRUE(ListsIsEqual(l1, l2));
}

TEST(RemoveDups, Ver2Case3Unique) {
    auto l1 = ListNode::Create({4, 1, 0, 5, 10, 2});
    auto l2 = ListNode::Create({4, 1, 0, 5, 10, 2});
    RemoveDup2(l1);
    EXPECT_TRUE(ListsIsEqual(l1, l2));
}

TEST(RemoveDups, Ver2Case4Empty) {
    NodePtr l1;
    NodePtr l2;
    RemoveDup2(l1);
    EXPECT_TRUE(ListsIsEqual(l1, l2));
}
