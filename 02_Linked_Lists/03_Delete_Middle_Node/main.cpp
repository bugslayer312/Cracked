#include "LinkedList.h"

using namespace OldLinkedList;

#include <iostream>

void DeleteNode(SingleListNode<int>* node) {
    std::swap(node->Data, node->Next->Data);
    auto afterNext = node->Next->Next;
    node->Next->Next = nullptr;
    delete node->Next;
    node->Next = afterNext;
}

int main() {
    SingleListNode<int> l = {1, 5, 2, 4, 0, 3};
    std::cout << &l << std::endl;
    auto toDelete = l.Next->Next;
    std::cout << "Deleting " << toDelete->Data << " : ";
    DeleteNode(toDelete);
    std::cout << &l << std::endl;
    toDelete = l.Next;
    std::cout << "Deleting " << toDelete->Data << " : ";
    DeleteNode(toDelete);
    std::cout << &l << std::endl;
}
