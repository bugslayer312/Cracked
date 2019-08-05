#include "LinkedList2.h"
#include <iostream>

using ListNode = SingleListNode<int>;
using NodePtr = ListNode::NodePtr;

void DeleteNode(NodePtr node) {
    std::swap(node->Data, node->Next->Data);
    auto afterNext = node->Next->Next;
    node->Next->Next = nullptr;
    node->Next = afterNext;
}

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
