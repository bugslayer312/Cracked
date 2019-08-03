#include "Tree.h"

#include <iostream>
#include <iterator>
#include <deque>
#include <list>

using Tree = TreeNode<int>;
using TreeNodePtr = Tree::TreeNodePtr;

void PrintBSTSecuences(std::list<TreeNodePtr>::iterator icur,
                       std::list<TreeNodePtr>& working, std::list<int> passed)
{
    std::list<TreeNodePtr> workingCopy(working.begin(), icur);
    auto& node = *icur;
    ++icur;
    std::copy(icur, working.end(), std::back_inserter(workingCopy));
    if (node->LeftChild) {
        workingCopy.push_back(node->LeftChild);
    }
    if (node->RightChild) {
        workingCopy.push_back(node->RightChild);
    }
    passed.push_back(node->Data);

    if (workingCopy.empty()) {
        std::copy(passed.begin(), passed.end(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;
        return;
    }
    for (auto it = workingCopy.begin(); it != workingCopy.end(); ++it) {
        PrintBSTSecuences(it, workingCopy, passed);
    }
}

void PrintBSTSecuences(TreeNodePtr root) {
    std::list<TreeNodePtr> working {root};
    std::list<int> passed;
    PrintBSTSecuences(working.begin(), working, passed);
}

int main() {
    TreeNodePtr root = Tree::CreateBinaryTreeFromVector({1,2,3,4,5,6,7});
    PrintBSTSecuences(root);

    return 0;
}
