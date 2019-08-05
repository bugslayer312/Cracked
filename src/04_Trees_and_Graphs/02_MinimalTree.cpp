#include "Tree.h"

#include <iostream>
#include <vector>

using Tree = TreeNode<int>;
using TreeNodePtr = Tree::TreeNodePtr;

TreeNodePtr ArrayToTreeRecur(std::vector<int> const& v, size_t l, size_t r)
{
    if (l >= r) {
        return nullptr;
    }

    size_t middle = (l + r) / 2;
    TreeNodePtr node = Tree::Create(v[middle]);
    node->LeftChild = ArrayToTreeRecur(v, l, middle);
    node->RightChild = ArrayToTreeRecur(v, middle+1, r);
    return node;
}

TreeNodePtr SortedArrayToBinarySearchTree(std::vector<int> const& v) {
    return ArrayToTreeRecur(v, 0, v.size());
}

int main() {
    std::vector<int> v = {1, 2, 5, 6, 7, 9, 10, 15, 22, 28, 30};
    TreeNodePtr node = SortedArrayToBinarySearchTree(v);
    auto f = [](TreeNodePtr n){
        std::cout << n->Data << ' ';
    };
    Tree::InOrderTraversal(node, f);
    //InOrderTraversal(node);
}
