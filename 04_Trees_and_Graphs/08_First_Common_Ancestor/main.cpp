#include "Tree.h"

#include <iostream>
#include <set>

using Tree = TreeNode<int>;
using TreeNodePtr = Tree::TreeNodePtr;

using TreeEx = TreeNode2<int>;
using TreeExNodePtr = TreeEx::TreeNodePtr;

bool isDescendentOf(TreeExNodePtr node, TreeExNodePtr parent) {
    while (node) {
        if (node->Parent == parent) {
            return true;
        }
        node = node->Parent;
    }
    return false;
}

TreeExNodePtr FirstCommonAncestor(TreeExNodePtr n1, TreeExNodePtr n2) {
    while (n1->Parent) {
        if (isDescendentOf(n2, n1->Parent)) {
            return n1->Parent;
        }
        n1 = n1->Parent;
    }
    return nullptr;
}

struct Result{
    bool firstIsFound = false;
    bool secondIsFound = false;
};

TreeNodePtr FirstCommonAncestorRecursive(TreeNodePtr node, std::set<TreeNodePtr>& toFind) {
    if (!node) {
        return nullptr;
    }

    if(node->LeftChild) {
        TreeNodePtr ptr = FirstCommonAncestorRecursive(node->LeftChild, toFind);
        if (ptr) {
            return ptr;
        }
        toFind.erase(node->LeftChild);
        if (toFind.empty()) {
            return node;
        }
    }
    if(node->RightChild) {
        TreeNodePtr ptr = FirstCommonAncestorRecursive(node->RightChild, toFind);
        if (ptr) {
            return ptr;
        }
        toFind.erase(node->RightChild);
        if (toFind.empty()) {
            return node;
        }
    }

    return nullptr;
}

TreeNodePtr FirstCommonAncestor(TreeNodePtr root, TreeNodePtr n1, TreeNodePtr n2) {
    std::set<TreeNodePtr> toFind = {n1, n2};
    return FirstCommonAncestorRecursive(root, toFind);
}

int main() {
    TreeExNodePtr node = TreeEx::CreateBinaryTreeFromVector({1, 3, 5, 8});
    TreeExNodePtr n1 = FindInBinarySearchTree(node, 1);
    TreeExNodePtr n2 = FindInBinarySearchTree(node, 3);;
    TreeExNodePtr fca = FirstCommonAncestor(n1, n2);

    TreeNodePtr root = Tree::CreateBinaryTreeFromVector({1, 3, 5, 8});
    TreeNodePtr nn1 = FindInBinarySearchTree(root, 1);
    TreeNodePtr nn2 = FindInBinarySearchTree(root, 3);;
    TreeNodePtr nfca = FirstCommonAncestor(root, nn1, nn2);

    std::cout << n1->Data << " " << n2->Data << " " <<  (fca ? std::to_string(fca->Data) : "Not Found") << std::endl;
    std::cout << nn1->Data << " " << nn2->Data << " " <<  (nfca ? std::to_string(nfca->Data) : "Not Found") << std::endl;

    return 0;
}
