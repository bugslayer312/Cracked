#include "Tree.h"

#include <list>
#include <iostream>
#include <iterator>
#include <unordered_map>

using Tree = TreeNode<int>;
using TreeNodePtr = Tree::TreeNodePtr;

typedef std::unordered_map<TreeNodePtr, int> PartialSumCache;

void CalcPathCountWithSumRecursive(TreeNodePtr node, int sum, std::list<int>& partialSums, int& totalPaths) {
    std::list<int> locaPartialSum;
    if (node->LeftChild) {
        CalcPathCountWithSumRecursive(node->LeftChild, sum, locaPartialSum, totalPaths);
        partialSums.splice(partialSums.end(), locaPartialSum);
    }
    if (node->RightChild) {
        CalcPathCountWithSumRecursive(node->RightChild, sum, locaPartialSum, totalPaths);
        partialSums.splice(partialSums.end(), locaPartialSum);
    }
    for (auto it = partialSums.begin(); it != partialSums.end(); ++it) {
        *it += node->Data;
        if (*it == sum) {
            ++totalPaths;
        }
    }
    partialSums.push_back(node->Data);
}

int CalcPathCountWithSum(TreeNodePtr node, int sum) {
    std::list<int> partialSums;
    int totalPaths = 0;
    CalcPathCountWithSumRecursive(node, sum, partialSums, totalPaths);
    return totalPaths;
}

int main () {
    TreeNodePtr root = Tree::CreateBinaryTreeFromVector({1, -5, 0, 4, 3, 2, 7, -2, -1, 4, -5, 3, 1, 0, -2});
    for (int i = -5; i <= 5; ++i) {
        std::cout << "Sum: " << i << ", Paths: " << CalcPathCountWithSum(root, i) << std::endl;
    }

    return 0;
}
