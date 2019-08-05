#pragma once

#include "LinkedList.h"

using ListNode = SingleListNode<int>;
using NodePtr = ListNode::NodePtr;

NodePtr FindLoopNode(NodePtr l);
