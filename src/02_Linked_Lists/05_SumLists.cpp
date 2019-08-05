// You have two numbers represented by a linked list, where each node contains
// a single digit. The digits are stored in reverse order, such that the 1 's
// digit is at the head of the list. Write a function that adds the two numbers
// and returns the sum as a linked list.
// EXAMPLE
// Input: (7-> 1 -> 6) + (5 -> 9 -> 2) .That is,617 + 295.
// Output: 2 -> 1 -> 9. That is, 912.
// FOLLOW UP
// Suppose the digits are stored in forward order. Repeat the above problem.
// EXAMPLE
// Input: (6 -> 1 -> 7) + (2 -> 9 -> 5) . That is,617 + 295 .
// Output: 9 -> 1 -> 2. That is, 912.


#include "05_SumLists.h"

#include <iostream>
#include <memory>

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

NodePtr SumRecursive(NodePtr l1, NodePtr l2, int rest) {
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

NodePtr Sum2(NodePtr l1, NodePtr l2) {
    return SumRecursive(l1, l2, 0);
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

NodePtr SumFwd2(NodePtr l1, NodePtr l2) {
    return Reverse(Sum(Reverse(l1), Reverse(l2)));
}
