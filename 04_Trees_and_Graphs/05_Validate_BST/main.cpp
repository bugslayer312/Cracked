#include "Tree.h"

#include <iostream>
#include <limits>

using Tree = TreeNode<int>;
using TreeNodePtr = Tree::TreeNodePtr;

bool isBSTrecursive(TreeNodePtr node, int& min, int& max) {
    min = max = node->Data;
    int localMin, localMax;
    if (node->LeftChild) {
        if (!isBSTrecursive(node->LeftChild, localMin, localMax) || localMax > node->Data){
            return false;
        }
        min = localMin;
    }
    if (node->RightChild) {
        if (!isBSTrecursive(node->RightChild, localMin, localMax) || localMin <= node->Data){
            return false;
        }
        max = localMax;
    }
    return true;
}

bool isBST(TreeNodePtr node) {
    int min, max;
    return node && isBSTrecursive(node, min, max);
}

bool isInRange(TreeNodePtr node, int min, int max) {
    if (node->Data < min || node->Data > max) {
        return false;
    }
    if (node->LeftChild && !isInRange(node->LeftChild, min, node->Data)){
        return false;
    }
    if (node->RightChild && !isInRange(node->RightChild, node->Data, max)){
        return false;
    }
    return true;
}

bool isBST2(TreeNodePtr node) {
    return node && isInRange(node, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
}

bool isBST3Recursive(TreeNodePtr node, int& last) {
    if (node->LeftChild && !isBST3Recursive(node->LeftChild, last)) {
        return false;
    }

    if (node->Data < last) {
        return false;
    }

    last = node->Data;

    if (node->RightChild && !isBST3Recursive(node->RightChild, last)) {
        return false;
    }

    return true;
}

bool isBST3(TreeNodePtr node) {
    int last = std::numeric_limits<int>::min();
    return node && isBST3Recursive(node, last);
}

int main() {
    TreeNodePtr node = Tree::CreateBinaryTreeFromVector({1, 4, 5, 6, 7, 9, 11, 13});
    std::cout << isBST(node) << std::endl;
    std::cout << isBST2(node) << std::endl;
    std::cout << isBST3(node) << std::endl;
    std::cout << "-----\n";
    node = Tree::CreateBinaryTreeFromVector({1, 4, 2, 6, 7, 9, 11, 13});
    std::cout << isBST(node) << std::endl;
    std::cout << isBST2(node) << std::endl;
    std::cout << isBST3(node) << std::endl;
    return 0;
}
