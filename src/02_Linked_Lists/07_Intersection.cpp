// iven two (singly) linked lists, determine if the two lists intersect. Return the
// intersecting node. Note that the intersection is defined based on reference, not value.
// That is, if the kth node of the first linked list is the exact same node (by reference)
// as the jth node of the second linked list, then they are intersecting.

#include "07_Intersection.h"

NodePtr FindIntersection(NodePtr l1, NodePtr l2) {
    size_t len1 = CalcListLength(l1);
    size_t len2 = CalcListLength(l2);
    int diff = static_cast<int>(len1) - len2;
    while (l1 && l2) {
        if (diff) {
            if (diff < 0) {
                l2 = l2->Next;
                ++diff;
            }
            else {
                l1 = l1->Next;
                --diff;
            }
        }
        else {
            if (l1 == l2) {
                return l1;
            }
            l1 = l1->Next;
            l2 = l2->Next;
        }
    }
    return nullptr;
}
