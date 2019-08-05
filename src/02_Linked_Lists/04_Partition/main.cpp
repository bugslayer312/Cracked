#include "LinkedList2.h"

#include <iostream>

using List2Node = DoubleListNode<int>;
using Node2Ptr = List2Node::NodePtr;

void Partition(Node2Ptr l, int x) {
    auto tail = l;
    while (tail->Next) {
        tail = tail->Next;
    }
    while (l != tail) {
        if (l->Data < x) {
            l = l->Next;
            continue;
        }
        if (tail->Data >= x) {
            tail = tail->Prev;
            continue;
        }
        std::swap(l->Data, tail->Data);
    }
}

using ListNode = SingleListNode<int>;
using NodePtr = ListNode::NodePtr;

NodePtr Partition(NodePtr l, int x) {
    if (!l) {
        return nullptr;
    }
    NodePtr head = ListNode::Create(l->Data);
    head->Next = l->Next;
    l->Next = nullptr;
    NodePtr node = head->Next;
    NodePtr prev = head;
    while (node) {
        NodePtr next = node->Next;
        if (node->Data < x) {
            node->Next = head;
            head = node;
            prev->Next = next;
        } else {
            prev = node;
        }
        node = next;
    }
    return head;
}

int main() {
    Node2Ptr l1 = List2Node::Create({3, 24, 8, 1, 15, 17, 2, 20, 34, 5, 4, 22, 26, 1});
    Node2Ptr l2 = List2Node::Create({3, 24, 8, 1, 15, 17, 2, 20, 34, 5, 4, 22, 26, 1});
    std::cout << l1 << std::endl;
    Partition(l1, 15);
    Partition(l2, 20);
    std::cout << l1 << std::endl;
    std::cout << l2 << std::endl;
    std::cout << "-----\n";
    NodePtr l3 = ListNode::Create({3, 24, 8, 1, 15, 17, 2, 20, 34, 5, 4, 22, 26, 1});
    std::cout << l3 << std::endl;
    NodePtr p3 = Partition(l3, 20);
    std::cout << p3 << std::endl;

    return 0;
}
