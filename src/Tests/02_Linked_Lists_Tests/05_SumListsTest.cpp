#include <gtest/gtest.h>

#include "05_SumLists.h"

class SumListsSuite : public testing::Test {
protected:
    void SetUp() override {
        l1 = ListNode::Create({7, 1, 6});
        l2 = ListNode::Create({5, 9, 2});
        l1suml2 = ListNode::Create({2, 1, 9});
        l3 = ListNode::Create({9, 7, 8});
        l4 = ListNode::Create({6, 8, 5});
        l3suml4 = ListNode::Create({5, 6, 4, 1});

        fl1 = ListNode::Create({7, 1, 6});
        fl2 = ListNode::Create({5, 9, 2});
        fl1sumfl2 = ListNode::Create({1, 3, 0, 8});
        fl3 = ListNode::Create({7, 1, 6});
        fl4 = ListNode::Create({9, 2, 3, 1});
        fl3sumfl4 = ListNode::Create({9, 9, 4, 7});
    }

    // backward representation
    NodePtr l1;
    NodePtr l2;
    NodePtr l1suml2;
    NodePtr l3;
    NodePtr l4;
    NodePtr l3suml4;
    // forward representation
    NodePtr fl1;
    NodePtr fl2;
    NodePtr fl1sumfl2;
    NodePtr fl3;
    NodePtr fl4;
    NodePtr fl3sumfl4;
};

TEST_F(SumListsSuite, BwdCase1) {
    EXPECT_TRUE(ListsIsEqual(Sum(l1, l2), l1suml2));
    EXPECT_TRUE(ListsIsEqual(Sum(l3, l4), l3suml4));
}

TEST_F(SumListsSuite, BwdCase2) {
    EXPECT_TRUE(ListsIsEqual(Sum2(l1, l2), l1suml2));
    EXPECT_TRUE(ListsIsEqual(Sum2(l3, l4), l3suml4));
}

TEST_F(SumListsSuite, FwdCase1) {
    EXPECT_TRUE(ListsIsEqual(SumFwd(fl1, fl2), fl1sumfl2));
    EXPECT_TRUE(ListsIsEqual(SumFwd(fl3, fl4), fl3sumfl4));
}

TEST_F(SumListsSuite, FwdCase2) {
    EXPECT_TRUE(ListsIsEqual(SumFwd2(fl1, fl2), fl1sumfl2));
}

TEST_F(SumListsSuite, FwdCase3) {
    EXPECT_TRUE(ListsIsEqual(SumFwd(fl3, fl4), fl3sumfl4));
}

/*
int main() {
    NodePtr l1 = ListNode::Create({7, 1, 6});
    NodePtr l2 = ListNode::Create({5, 9, 2});
    std::cout << l1 << std::endl;
    std::cout << l2 << std::endl;
    std::cout << Sum(l1, l2) << std::endl;
    std::cout << SumRecursive(l1, l2) << std::endl;
    std::cout << "-----\n";

    NodePtr l3 = ListNode::Create({9, 7, 8});
    NodePtr l4 = ListNode::Create({6, 8, 5});
    std::cout << l3 << std::endl;
    std::cout << l4 << std::endl;
    std::cout << Sum(l3, l4) << std::endl;
    std::cout << SumRecursive(l3, l4) << std::endl;
    std::cout << "-----\n";

    NodePtr l5 = ListNode::Create({7, 1, 6});
    NodePtr l6 = ListNode::Create({5, 9, 2});
    std::cout << Reverse(Sum(Reverse(l5), Reverse(l6))) << std::endl;
    NodePtr l7 = ListNode::Create({7, 1, 6});
    NodePtr l8 = ListNode::Create({9, 2, 3, 1});
    std::cout << SumFwd(l7, l8) << std::endl;
    std::cout << "-----\n";

    return 0;
}*/
