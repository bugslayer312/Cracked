#include "LinkedList2.h"

#include <iostream>

using ListNode = SingleListNode<char>;
using NodePtr = ListNode::NodePtr;

std::pair<bool, NodePtr> IsPalindromeRecursion(NodePtr first, size_t length) {
    NodePtr last = first;
    bool innerIsPalindrome = true;
    if (length > 2) {
        std::pair<bool, NodePtr> inner = IsPalindromeRecursion(first->Next, length-2);
        innerIsPalindrome = inner.first;
        last = inner.second;
    }
    else {
        if (length == 2) {
            last = first->Next;
        }
    }
    return std::make_pair(innerIsPalindrome && (first->Data == last->Data), last->Next);
}

bool IsPalindrome(NodePtr node) {
    return IsPalindromeRecursion(node, CalcListLength(node)).first;
}

int main() {
    auto l1 = ListNode::Create({'h', 'e', 'l', 'l', 'o', '1', 'o', 'l', 'l', 'e', 'h'});
    std::cout << l1 << " : " << IsPalindrome(l1) << std::endl;
    return 0;
}
