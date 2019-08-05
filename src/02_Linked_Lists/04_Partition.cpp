// Write code to partition a linked list around a value x, such that all nodes
// less than x come before all nodes greater than or equal to x . lf x is contained
// within the list, the values of x only need to be after the elements less than x
// (see below). The partition element x can appear anywhere in the "right partition";
// it does not need to appear between the left and right partitions.
// EXAMPLE
// Input: 3 -> 5 -> 8 -> 5 - > 10 -> 2 -> 1 [partition = 5)
// Output: 3 -> 1 -> 2 -> 10 -> 5 -> 5 -> 8

#include "04_Partition.h"

void Partition(Node2Ptr l, int x) {
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

NodePtr Partition(NodePtr l, int x) {
    if (!l) {
        return nullptr;
    }
    NodePtr head = ListNode::Create(l->Data);
    head->Next = l->Next;
    l->Next = nullptr;
    NodePtr node = head->Next;
    NodePtr prev = head;
    while (node) {
        NodePtr next = node->Next;
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
