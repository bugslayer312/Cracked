#include "Tree.h"

#include <iostream>
#include <cstdlib>

struct TreeData {
    int Value;
    int CountWithSubTrees = 0;

    TreeData(int value) : Value(value) {}
};

using Tree = TreeNode<TreeData>;
using TreeNodePtr = Tree::TreeNodePtr;

int GetRandomPos(int treeSize) {
    return std::rand() % treeSize;
}

int CalcNodeCounts(TreeNodePtr node) {
    if (!node) {
        return 0;
    }

    return node->Data.CountWithSubTrees = CalcNodeCounts(node->LeftChild) + CalcNodeCounts(node->RightChild) + 1;
}

TreeNodePtr GetRandomNodeRecursive(TreeNodePtr root, int pos) {
    int rootPos = (root->LeftChild ? root->LeftChild->Data.CountWithSubTrees : 0);
    if (pos < rootPos) {
        return GetRandomNodeRecursive(root->LeftChild, pos);
    }
    else if (pos > rootPos) {
        return GetRandomNodeRecursive(root->RightChild, pos - rootPos - 1);
    }
    return root;
}

TreeNodePtr GetRandomNode(TreeNodePtr root) {
    int pos = std::rand() % root->Data.CountWithSubTrees;
    return GetRandomNodeRecursive(root, pos);
}

int main() {
    TreeNodePtr root = Tree::CreateBinaryTreeFromVector({1,2,3,4,5,6,7,8,9,10});
    CalcNodeCounts(root);
    for (int i = 0; i < 100; ++i) {
        std::cout << GetRandomNode(root)->Data.Value << std::endl;
    }
    return 0;
}
