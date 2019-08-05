#include <gtest/gtest.h>

#include "08_LoopDetection.h"

TEST(LoopDetection, Case1Null) {
    EXPECT_EQ(FindLoopNode(nullptr), nullptr);
}

TEST(LoopDetection, Case2One) {
    auto n = ListNode::Create(5);
    EXPECT_EQ(FindLoopNode(n), nullptr);
}

TEST(LoopDetection, Case3NoLoop) {
    auto n = ListNode::Create({2, 3, 6, 3, 7, 8, 9});
    EXPECT_EQ(FindLoopNode(n), nullptr);
}

TEST(LoopDetection, Case4LoopAtHead) {
    auto n = ListNode::Create({2, 4, 6, 3, 7, 8, 9});
    GetLastNode(n)->Next = n;
    auto ln = FindLoopNode(n);
    EXPECT_NE(ln, nullptr);
    EXPECT_EQ(ln, n);
}

TEST(LoopDetection, Case5LoopTwoElem) {
    auto n = ListNode::Create({2, 4, 6, 3, 7, 8, 9});
    auto prelast = n->Next->Next->Next->Next->Next;
    prelast->Next->Next = prelast;
    auto ln = FindLoopNode(n);
    EXPECT_NE(ln, nullptr);
    EXPECT_EQ(ln, prelast);
}

TEST(LoopDetection, Case6LoopOneElem) {
    auto n = ListNode::Create({2, 4, 6, 3, 7, 8, 9});
    auto last = GetLastNode(n);
    last->Next = last;
    auto ln = FindLoopNode(n);
    EXPECT_NE(ln, nullptr);
    EXPECT_EQ(ln, last);
}

TEST(LoopDetection, Case7ThirdStartsLoop) {
    auto n = ListNode::Create({2, 4, 6, 3, 7, 8, 9});
    auto last = GetLastNode(n);
    auto third = n->Next->Next;
    last->Next = third;
    auto ln = FindLoopNode(n);
    EXPECT_NE(ln, nullptr);
    EXPECT_EQ(ln, third);
}
