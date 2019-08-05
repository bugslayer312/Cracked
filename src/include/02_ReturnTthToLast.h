#pragma once

#include "LinkedList.h"

using ListNode = SingleListNode<int>;
using NodePtr = ListNode::NodePtr;

NodePtr ReturnKthToLast(NodePtr l, int k);
NodePtr ReturnKthToLast2(NodePtr l, int k);
NodePtr ReturnKthToLast3(NodePtr l, int k);
