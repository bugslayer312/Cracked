// Write code to remove duplicates from an unsorted li nked list.
// FOLLOW UP
// How would you solve this problem if a temporary buffer is not allowed?

#include "01_RemoveDups.h"

#include <unordered_set>

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
