// Implement an algorithm to find the kth to last element of a singly linked list.

#include "02_ReturnTthToLast.h"

NodePtr ReturnKthToLast(NodePtr l, int k) {
    int size = 0;
    auto node = l;
    while (node) {
        ++size;
        node = node->Next;
    }
    if (size < k) {
        return nullptr;
    }
    node = l;
    while (size > k) {
        node = node->Next;
        --size;
    }
    return node;
}

NodePtr ReturnKthToLast2(NodePtr l, int k) {
    NodePtr p1;
    auto p2 = l;
    int step = 1;
    while (p2) {
        if (step == k) {
            if (p1) {
                p1 = p1->Next;
            }
            else {
                p1 = l;
            }
        }
        else {
            ++step;
        }
        p2 = p2->Next;
    }
    return p1;
}

// Recursion
std::pair<NodePtr, int> ReturnKthToLastRec(NodePtr l, int k) {
    if (l) {
        std::pair<NodePtr, int> result = ReturnKthToLastRec(l->Next, k);
        if (++result.second == k) {
            result.first = l;
        }
        return result;
    }
    return {nullptr, 0};
}

NodePtr ReturnKthToLast3(NodePtr l, int k) {
    std::pair<NodePtr, int> recRes = ReturnKthToLastRec(l, k);
    return recRes.first;
}
