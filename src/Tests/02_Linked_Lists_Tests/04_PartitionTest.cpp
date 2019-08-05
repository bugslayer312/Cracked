#include <gtest/gtest.h>

#include "04_Partition.h"

template<template<typename> class List, class T>
bool CheckPartition(std::shared_ptr<List<T>> l, int x) {
    while (l) {
        if (l->Data >= x) {
            break;
        }
        l = l->Next;
    }
    while (l) {
        if (l->Data < x) {
            return false;
        }
        l = l->Next;
    }
    return true;
}

TEST(Partition, DoubleLinkedListCase1) {
    Node2Ptr l1 = List2Node::Create({3, 24, 8, 1, 15, 17, 2, 20, 34, 5, 4, 22, 26, 1});
    Partition(l1, 15);
    EXPECT_TRUE(CheckPartition(l1, 15)) << l1;
}

TEST(Partition, DoubleLinkedListCase2) {
    Node2Ptr l1 = List2Node::Create({3, 24, 8, 1, 15, 17, 2, 20, 34, 5, 4, 22, 26, 1});
    Partition(l1, 20);
    EXPECT_TRUE(CheckPartition(l1, 20)) << l1;
}

TEST(Partition, SingleLinkedListCase1) {
    NodePtr l1 = ListNode::Create({3, 24, 8, 1, 15, 17, 2, 20, 34, 5, 4, 22, 26, 1});
    l1 = Partition(l1, 12);
    EXPECT_TRUE(CheckPartition(l1, 12)) << l1;
}

TEST(Partition, SingleLinkedListCase2) {
    NodePtr l1 = ListNode::Create({3, 24, 8, 1, 15, 17, 2, 20, 34, 5, 4, 22, 26, 1});
    l1 = Partition(l1, 18);
    EXPECT_TRUE(CheckPartition(l1, 18)) << l1;
}


/*
 int main() {
    Node2Ptr l1 = List2Node::Create({3, 24, 8, 1, 15, 17, 2, 20, 34, 5, 4, 22, 26, 1});
    Node2Ptr l2 = List2Node::Create({3, 24, 8, 1, 15, 17, 2, 20, 34, 5, 4, 22, 26, 1});
    std::cout << l1 << std::endl;
    Partition(l1, 15);
    Partition(l2, 20);
    std::cout << l1 << std::endl;
    std::cout << l2 << std::endl;
    std::cout << "-----\n";
    NodePtr l3 = ListNode::Create({3, 24, 8, 1, 15, 17, 2, 20, 34, 5, 4, 22, 26, 1});
    std::cout << l3 << std::endl;
    NodePtr p3 = Partition(l3, 20);
    std::cout << p3 << std::endl;

    return 0;
}

*/
