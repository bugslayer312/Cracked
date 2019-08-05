#pragma once

#include "LinkedList.h"

using List2Node = DoubleListNode<int>;
using Node2Ptr = List2Node::NodePtr;

using ListNode = SingleListNode<int>;
using NodePtr = ListNode::NodePtr;

void Partition(Node2Ptr l, int x);
NodePtr Partition(NodePtr l, int x);
