#include <gtest/gtest.h>

#include "03_DeleteMiddleNode.h"

class DeleteMiddleNodeSuite : public testing::Test {
protected:
    void SetUp() override {
        l = ListNode::Create({1, 5, 2, 4, 0, 3});
    }
    NodePtr l;
};

TEST_F(DeleteMiddleNodeSuite, Case1) {
    DeleteNode(l->Next);
    EXPECT_TRUE(ListsIsEqual(l, ListNode::Create({1, 2, 4, 0, 3})));
}

TEST_F(DeleteMiddleNodeSuite, Case2) {
    DeleteNode(l->Next->Next);
    EXPECT_TRUE(ListsIsEqual(l, ListNode::Create({1, 5, 4, 0, 3})));
}

TEST_F(DeleteMiddleNodeSuite, Case3) {
    DeleteNode(l->Next->Next->Next);
    EXPECT_TRUE(ListsIsEqual(l, ListNode::Create({1, 5, 2, 0, 3})));
}
/*
int main() {
    NodePtr l = ListNode::Create({1, 5, 2, 4, 0, 3});
    std::cout << l << std::endl;
    auto toDelete = l->Next->Next;
    std::cout << "Deleting " << toDelete->Data << " : ";
    DeleteNode(toDelete);
    std::cout << l << std::endl;
    toDelete = l->Next;
    std::cout << "Deleting " << toDelete->Data << " : ";
    DeleteNode(toDelete);
    std::cout << l << std::endl;
}
*/
