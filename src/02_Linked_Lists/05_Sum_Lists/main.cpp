// #include "LinkedList.h"
#include "LinkedList2.h"

// using namespace OldLinkedList;

#include <iostream>
#include <memory>

using ListNode = SingleListNode<int>;
using NodePtr = ListNode::NodePtr;

NodePtr Sum(NodePtr l1, NodePtr l2) {
    NodePtr head;
    NodePtr node;
    int rest = 0;
    while (l1 || l2) {
        int d1 = 0;
        int d2 = 0;
        if (l1) {
            d1 = l1->Data;
            l1 = l1->Next;
        }
        if (l2) {
            d2 = l2->Data;
            l2 = l2->Next;
        }
        int sum = d1 + d2 + rest;
        if (sum >= 10) {
            rest = 1;
            sum -= 10;
        }
        else {
            rest = 0;
        }
        if (node) {
            node->Next = ListNode::Create(sum);
            node = node->Next;
        }
        else {
            head = node = ListNode::Create(sum);
        }
    }
    if (rest) {
        node->Next = ListNode::Create(rest);
    }
    return head;
}

NodePtr SumRecursive(NodePtr l1, NodePtr l2, int rest = 0) {
    if (l1 || l2 || rest) {
        int sum = rest;
        if (l1) {
            sum += l1->Data;
            l1 = l1->Next;
        }
        if (l2) {
            sum += l2->Data;
            l2 = l2->Next;
        }
        auto node = ListNode::Create(sum % 10);
        node->Next = SumRecursive(l1, l2, sum / 10);
        return node;
    }
    return NodePtr();
}

NodePtr PadWithZeros(NodePtr node, size_t count) {
    for (size_t i = 0; i < count; ++i) {
        auto newNode = ListNode::Create(0);
        newNode->Next = node;
        node = newNode;
    }
    return node;
}

NodePtr SumFwdRecursive(NodePtr l1, NodePtr l2, int& carry) {
    if (l1) {
        int _carry = 0;
        auto next = SumFwdRecursive(l1->Next, l2->Next, _carry);
        int sum = _carry + l1->Data + l2->Data;
        carry = (sum >= 10 ? 1 : 0);
        auto result = ListNode::Create(sum % 10);
        result->Next = next;
        return result;
    }
    else {
        return nullptr;
    }
}

NodePtr SumFwd(NodePtr l1, NodePtr l2) {
    std::size_t len1 = CalcListLength(l1);
    std::size_t len2 = CalcListLength(l2);
    std::size_t len = std::max(len1, len2);
    if (len1 < len2) {
        l1 = PadWithZeros(l1, len - std::min(len1, len2));
    } else if (len1 > len2) {
        l2 = PadWithZeros(l2, len - std::min(len1, len2));
    }

    //std::cout << l1 << std::endl;
    //std::cout << l2 << std::endl;

    int carry = 0;
    NodePtr result = SumFwdRecursive(l1, l2, carry);
    if (carry) {
        auto node = ListNode::Create(carry);
        node->Next = result;
        result = node;
    }

    return result;
}

NodePtr Reverse(NodePtr head) {
    NodePtr prev;
    NodePtr node = head;
    while (node) {
        auto next = node->Next;
        node->Next = prev;
        prev = node;
        node = next;
    }
    return prev;
}

int main() {
    NodePtr l1 = ListNode::Create({7, 1, 6});
    NodePtr l2 = ListNode::Create({5, 9, 2});
    std::cout << l1 << std::endl;
    std::cout << l2 << std::endl;
    std::cout << Sum(l1, l2) << std::endl;
    std::cout << SumRecursive(l1, l2) << std::endl;
    std::cout << "-----\n";

    NodePtr l3 = ListNode::Create({9, 7, 8});
    NodePtr l4 = ListNode::Create({6, 8, 5});
    std::cout << l3 << std::endl;
    std::cout << l4 << std::endl;
    std::cout << Sum(l3, l4) << std::endl;
    std::cout << SumRecursive(l3, l4) << std::endl;
    std::cout << "-----\n";

    NodePtr l5 = ListNode::Create({7, 1, 6});
    NodePtr l6 = ListNode::Create({5, 9, 2});
    std::cout << Reverse(Sum(Reverse(l5), Reverse(l6))) << std::endl;
    NodePtr l7 = ListNode::Create({7, 1, 6});
    NodePtr l8 = ListNode::Create({9, 2, 3, 1});
    std::cout << SumFwd(l7, l8) << std::endl;
    std::cout << "-----\n";

    return 0;
}
