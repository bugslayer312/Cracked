#include "LinkedList.h"
#include <iostream>
#include <unordered_set>

using namespace OldLinkedList;

void RemoveDup1(DoubleListNode<int>* node) {
    std::unordered_set<int> hash;
    while (node) {
        auto next = node->Next;
        if (!hash.insert(node->Data).second) {
            DoubleListNode<int>::Remove(node);
        }

        node = next;
    }
}

void RemoveDup2(DoubleListNode<int>* node) {
    while (node) {
        int val = node->Data;
        auto next = node->Next;
        while (next) {
            auto afterNext = next->Next;
            if (next->Data == val) {
                DoubleListNode<int>::Remove(next);
            }
            next = afterNext;
        }
        node = node->Next;
    }
}

int main() {
    DoubleListNode<int> l1 = {4, 1, 0, 5, 10, 2, 1, 1, 0};
    DoubleListNode<int> l2 = {4, 1, 0, 5, 10, 2, 1, 1, 0, 4, 3};
    RemoveDup1(&l1);
    RemoveDup1(&l2);
    std::cout << &l1 << std::endl << &l2 << std::endl;
    return 0;
}
