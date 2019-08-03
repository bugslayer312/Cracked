#include "LinkedList2.h"
#include <iostream>
#include <string>

using ListNode = SingleListNode<int>;
using NodePtr = ListNode::NodePtr;

std::pair<int, bool> ReturnKthToLast(NodePtr l, int k) {
    int size = 0;
    auto node = l;
    while (node) {
        ++size;
        node = node->Next;
    }
    if (size < k) {
        return std::make_pair(0, false);
    }
    node = l;
    while (size > k) {
        node = node->Next;
        --size;
    }
    return std::make_pair(node->Data, true);
}

std::pair<int, bool> ReturnKthToLast2(NodePtr l, int k) {
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
    return p1 ? std::make_pair(p1->Data, true) : std::make_pair(0, false);
}

// Recursion
std::pair<int, int> ReturnKthToLastRec(NodePtr l, int k) {
    if (l) {
        std::pair<int, int> result = ReturnKthToLastRec(l->Next, k);
        if (++result.second == k) {
            result.first = l->Data;
        }
        return result;
    }
    return {0, 0};
}

std::pair<int, bool> ReturnKthToLast3(NodePtr l, int k) {
    std::pair<int, int> recRes = ReturnKthToLastRec(l, k);
    return recRes.second >= k ? std::make_pair(recRes.first, true) : std::make_pair(0, false);
}

int main() {
    NodePtr l = ListNode::Create({4, 1, 0, 5, 10, 2, 1, 1, 0});
    auto res = ReturnKthToLast(l, 5);
    std::cout << (res.second ? std::to_string(res.first) : "Not found") << std::endl;
    res = ReturnKthToLast(l, 9);
    std::cout << (res.second ? std::to_string(res.first) : "Not found") << std::endl;
    res = ReturnKthToLast(l, 10);
    std::cout << (res.second ? std::to_string(res.first) : "Not found") << std::endl;
    std::cout << "----\n";
    res = ReturnKthToLast2(l, 5);
    std::cout << (res.second ? std::to_string(res.first) : "Not found") << std::endl;
    res = ReturnKthToLast2(l, 9);
    std::cout << (res.second ? std::to_string(res.first) : "Not found") << std::endl;
    res = ReturnKthToLast2(l, 10);
    std::cout << (res.second ? std::to_string(res.first) : "Not found") << std::endl;
    std::cout << "----\n";
    res = ReturnKthToLast3(l, 5);
    std::cout << (res.second ? std::to_string(res.first) : "Not found") << std::endl;
    res = ReturnKthToLast3(l, 9);
    std::cout << (res.second ? std::to_string(res.first) : "Not found") << std::endl;
    res = ReturnKthToLast3(l, 10);
    std::cout << (res.second ? std::to_string(res.first) : "Not found") << std::endl;
    return 0;
}
