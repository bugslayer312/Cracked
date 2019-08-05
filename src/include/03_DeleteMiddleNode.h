#pragma once

#include "LinkedList.h"

using ListNode = SingleListNode<int>;
using NodePtr = ListNode::NodePtr;

void DeleteNode(NodePtr node);
