#include "LinkedList.h"

using namespace OldLinkedList;

#include <iostream>

void Partition(DoubleListNode<int>* l, int x) {
    auto tail = l;
    while (tail->Next) {
        tail = tail->Next;
    }
    while (l != tail) {
        if (l->Data < x) {
            l = l->Next;
            continue;
        }
        if (tail->Data >= x) {
            tail = tail->Prev;
            continue;
        }
        std::swap(l->Data, tail->Data);
    }
}

SingleListNode<int>* Partition(SingleListNode<int>* l, int x) {
    if (!l) {
        return nullptr;
    }
    SingleListNode<int>* head = new SingleListNode<int>(l->Data);
    head->Next = l->Next;
    l->Next = nullptr;
    SingleListNode<int>* node = head->Next;
    SingleListNode<int>* prev = head;
    while (node) {
        SingleListNode<int>* next = node->Next;
        if (node->Data < x) {
            node->Next = head;
            head = node;
            prev->Next = next;
        } else {
            prev = node;
        }
        node = next;
    }
    return head;
}

int main() {
    DoubleListNode<int> l1 = {3, 24, 8, 1, 15, 17, 2, 20, 34, 5, 4, 22, 26, 1};
    DoubleListNode<int> l2 = {3, 24, 8, 1, 15, 17, 2, 20, 34, 5, 4, 22, 26, 1};
    std::cout << &l1 << std::endl;
    Partition(&l1, 15);
    Partition(&l2, 20);
    std::cout << &l1 << std::endl;
    std::cout << &l2 << std::endl;
    std::cout << "-----\n";
    SingleListNode<int> l3 = {3, 24, 8, 1, 15, 17, 2, 20, 34, 5, 4, 22, 26, 1};
    std::cout << &l3 << std::endl;
    SingleListNode<int>* p3 = Partition(&l3, 20);
    std::cout << p3 << std::endl;
    delete p3;

    return 0;
}
