#include "LinkedList2.h"
#include <iostream>
#include <unordered_set>

using ListNode = SingleListNode<int>;
using NodePtr = ListNode::NodePtr;

void RemoveDup1(NodePtr node) {
    std::unordered_set<int> hash;
    NodePtr prev;
    while (node) {
        auto next = node->Next;
        if (!hash.insert(node->Data).second) {
            prev->Next = next;
            node->Next = nullptr;
        } else {
            prev = node;
        }
        node = next;
    }
}

void RemoveDup2(NodePtr node) {
    while (node) {
        int val = node->Data;
        auto prev = node;
        auto next = node->Next;
        while (next) {
            auto afterNext = next->Next;
            if (next->Data == val) {
                prev->Next = afterNext;
                next->Next = nullptr;
            } else {
                prev = next;
            }
            next = afterNext;
        }
        node = node->Next;
    }
}

int main() {
    auto l1 = ListNode::Create({4, 1, 0, 5, 10, 2, 1, 1, 0});
    auto l2 = ListNode::Create({4, 1, 0, 5, 10, 2, 1, 1, 0, 4, 3});
    RemoveDup1(l1);
    RemoveDup2(l2);
    std::cout << l1 << std::endl << l2 << std::endl;
    return 0;
}
