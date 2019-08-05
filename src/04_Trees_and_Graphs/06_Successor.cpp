#include "Tree.h"

#include <iostream>

using Tree = TreeNode2<int>;
using TreeNodePtr = Tree::TreeNodePtr;


TreeNodePtr GetNext(TreeNodePtr node) {
    if (!node) {
        return nullptr;
    }
    TreeNodePtr result = node->RightChild;
    if (result) {
        while (result->LeftChild) {
            result = result->LeftChild;
        }
        return result;
    }

    result = node;
    while (result->Parent) {
        if (result->Parent->LeftChild == result) {
            return result->Parent;
        }
        result = result->Parent;
    }
    return nullptr;
}

int main() {
    TreeNodePtr node = Tree::CreateBinaryTreeFromVector({1, 2, 3, 4, 5, 6, 7, 8});

    TreeNodePtr n = FindInBinarySearchTree(node, 1);
    while (n) {
        std::cout << n->Data << ' ';
        n = GetNext(n);
    }
    return 0;
}
