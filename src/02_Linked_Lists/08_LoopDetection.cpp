// Given a circular linked list, implement an algorithm that returns the node at the
// beginning of the loop.
// DEFINITION
// Circular linked list: A (corrupt) linked list in which a node's next pointer points
// to an earlier node, so as to make a loop in the linked list.
// EXAMPLE
// Input: A -> B -> C -> D -> E -> C [the same as earlier]
// Output: C

#include "08_LoopDetection.h"

NodePtr FindLoopNode(NodePtr l) {
    if (!l) {
        return nullptr;
    }
    NodePtr p1 = l;
    NodePtr p2 = l;
    while (p1->Next && p1->Next->Next) {
        if(p1->Next->Next == p2->Next) {
            break;
        }
        p1 = p1->Next->Next;
        p2 = p2->Next;
    }
    if (p1->Next && p1->Next->Next) {
        p1 = p1->Next->Next;
        p2 = l;
        while (p1 != p2) {
            p1 = p1->Next;
            p2 = p2->Next;
        }
        return p1;
    }
    return nullptr;
}
