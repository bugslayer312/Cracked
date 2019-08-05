#include "LinkedList2.h"

#include <iostream>

using ListNode = SingleListNode<int>;
using NodePtr = ListNode::NodePtr;

NodePtr FindIntersection(NodePtr l1, NodePtr l2) {
    size_t len1 = CalcListLength(l1);
    size_t len2 = CalcListLength(l2);
    int diff = static_cast<int>(len1) - len2;
    while (l1 && l2) {
        if (diff) {
            if (diff < 0) {
                l2 = l2->Next;
                ++diff;
            }
            else {
                l1 = l1->Next;

            }
        }
        else {
            if (l1 == l2) {
                return l1;
            }
            l1 = l1->Next;
            l2 = l2->Next;
        }
    }
    return nullptr;
}

int main() {
    NodePtr l1 = ListNode::Create({4, 5, 6});
    NodePtr l2 = ListNode::Create({1, 2, 3, 4, 5, 6});
    NodePtr l3 = ListNode::Create({7, 8, 9});
    GetLastNode(l1)->Next = l3;
    GetLastNode(l2)->Next = l3;
    std::cout << l1 << std::endl;
    std::cout << l2 << std::endl;
    NodePtr its = FindIntersection(l1, l2);
    std::cout << (its ? std::to_string(its->Data) : "No intersection") << std::endl;

    return 0;
}
