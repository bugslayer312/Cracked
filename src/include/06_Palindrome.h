#pragma once

#include "LinkedList.h"

using ListNode = SingleListNode<char>;
using NodePtr = ListNode::NodePtr;

bool IsPalindrome(NodePtr node);
