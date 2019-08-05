#include <gtest/gtest.h>

#include "07_Intersection.h"

TEST(ListIntersection, Case1NoIntersect) {
    NodePtr l1 = ListNode::Create({4, 5, 6});
    NodePtr l2 = ListNode::Create({1, 2, 3, 4, 5, 6});
    EXPECT_EQ(FindIntersection(l1, l2), nullptr);
}

TEST(ListIntersection, Case2NoIntersect) {
    NodePtr l1 = ListNode::Create({4, 5, 6});
    NodePtr l2 = nullptr;
    EXPECT_EQ(FindIntersection(l1, l2), nullptr);
}

TEST(ListIntersection, Case3NoIntersect) {
    EXPECT_EQ(FindIntersection(nullptr, nullptr), nullptr);
}

TEST(ListIntersection, Case4Intersect) {
    NodePtr l1 = ListNode::Create({4, 5, 6});
    NodePtr l2 = FindIntersection(l1, l1->Next);
    EXPECT_NE(l2, nullptr);
    EXPECT_EQ(l2->Data, 5);
}

TEST(ListIntersection, Case4IntersectSelf) {
    NodePtr l1 = ListNode::Create({4, 5, 6});
    NodePtr l2 = FindIntersection(l1, l1);
    EXPECT_NE(l2, nullptr);
    EXPECT_EQ(l2->Data, 4);
}

TEST(ListIntersection, Case5IntersectWithOther) {
    NodePtr l1 = ListNode::Create({4, 5, 6});
    NodePtr l2 = ListNode::Create({0, 1, 2});
    l2->Next->Next->Next = l1->Next;
    NodePtr l3 = FindIntersection(l1, l2);
    EXPECT_NE(l3, nullptr);
    EXPECT_EQ(l3->Data, 5);
}
