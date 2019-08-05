#pragma once

#include "LinkedList.h"

using ListNode = SingleListNode<int>;
using NodePtr = ListNode::NodePtr;

NodePtr FindIntersection(NodePtr l1, NodePtr l2);
