#include "Tree.h"

#include <iostream>

using Tree = TreeNode<int>;
using TreeNodePtr = Tree::TreeNodePtr;

int GetDepth(TreeNodePtr node) {
    if (!node) {
        return 0;
    }
    int l = GetDepth(node->LeftChild);
    int r = GetDepth(node->RightChild);
    if (l >= 0 && r >= 0 && std::abs(l - r) < 2) {
        return std::max(l, r) + 1;
    }
    return -1;
}

bool CheckIsBalanced(TreeNodePtr node) {
    return GetDepth(node) >= 0;
}

int main() {
    TreeNodePtr node = Tree::CreateBinaryTreeFromVector({1, 2, 3, 4, 5, 6, 7});
    std::cout << CheckIsBalanced(node) << std::endl;
    TreeNodePtr node1 = Tree::Create(10);
    node1->LeftChild = node;
    std::cout << CheckIsBalanced(node1) << std::endl;
    node1->RightChild = Tree::Create(15);
    std::cout << CheckIsBalanced(node1) << std::endl;
    node1->RightChild->LeftChild = Tree::Create(12);
    std::cout << CheckIsBalanced(node1) << std::endl;
}
