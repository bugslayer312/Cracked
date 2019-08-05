// Implement a function to check if a linked list is a palindrome.

#include "06_Palindrome.h"

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
    if (!node) {
        return true;
    }
    return IsPalindromeRecursion(node, CalcListLength(node)).first;
}

