#include "LinkedList2.h"

using ListNode = SingleListNode<int>;
using NodePtr = ListNode::NodePtr;

#include <iostream>

NodePtr FindLoopNode(NodePtr l) {
    if (!l) {
        return nullptr;
    }
    NodePtr p1 = l;
    NodePtr p2 = l;
    while (p1->Next && p1->Next->Next) {
        if(p1->Next->Next == p2->Next) {
            break;
        }
        p1 = p1->Next->Next;
        p2 = p2->Next;
    }
    if (p1->Next && p1->Next->Next) {
        p1 = p1->Next->Next;
        p2 = l;
        while (p1 != p2) {
            p1 = p1->Next;
            p2 = p2->Next;
        }
        return p1;
    }
    return nullptr;
}

int main() {
    NodePtr l = ListNode::Create({1, 2, 3, 4, 5});
    GetLastNode(l)->Next = l->Next->Next->Next->Next;
    NodePtr loopNode = FindLoopNode(l);
    std::cout << (loopNode ? std::to_string(loopNode->Data) : "No loop") << std::endl;
    std::cout << "-----\n";
    NodePtr l2 = ListNode::Create({1, 2, 3, 4, 5});
    loopNode = FindLoopNode(l2);
    std::cout << (loopNode ? std::to_string(loopNode->Data) : "No loop") << std::endl;
    return 0;
}
