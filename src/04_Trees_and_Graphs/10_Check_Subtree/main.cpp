#include "Tree.h"

#include <iostream>

using Tree = TreeNode<int>;
using TreeNodePtr = Tree::TreeNodePtr;

bool PreorderTraversalCompare(TreeNodePtr t1, TreeNodePtr t2) {
    if ((t1 && !t2) || (!t1 && t2)) {
        return false;
    }
    return !t1 || ((t1->Data == t2->Data) && PreorderTraversalCompare(t1->LeftChild, t2->LeftChild) &&
                                             PreorderTraversalCompare(t1->RightChild, t2->RightChild));
}

bool PreorderTraversalSearch(TreeNodePtr t1, TreeNodePtr t2) {
    if (!t2) {
        return true;
    }
    if (!t1) {
        return false;
    }
    if (PreorderTraversalCompare(t1, t2)) {
        return true;
    }
    return PreorderTraversalSearch(t1->LeftChild, t2) || PreorderTraversalSearch(t1->RightChild, t2);
}

int main() {
    TreeNodePtr t1 = Tree::CreateBinaryTreeFromVector({1,2,3,4,5,6,7,8,9,10});
    TreeNodePtr t2 = t1->LeftChild->RightChild->Clone();
    std::cout << PreorderTraversalSearch(t1, t2) << std::endl;
    t2->RightChild = Tree::CreateBinaryTreeFromVector({1,2,3,4});
    std::cout << PreorderTraversalSearch(t1, t2) << std::endl;

    return 0;
}
