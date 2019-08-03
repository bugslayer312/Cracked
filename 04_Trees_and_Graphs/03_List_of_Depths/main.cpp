#include "Tree.h"

#include <iostream>
#include <list>
#include <queue>
#include <iterator>

using Tree = TreeNode<int>;
using TreeNodePtr = Tree::TreeNodePtr;

std::list<int> CreateListOfDepth(TreeNodePtr node, int depth) {
    std::list<int> result;
    std::queue<std::pair<TreeNodePtr, int>> q;
    q.push({node, 0});
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        if (cur.second < depth) {
            if (cur.first->LeftChild) {
                q.push({cur.first->LeftChild, cur.second+1});
            }
            if (cur.first->RightChild) {
                q.push({cur.first->RightChild, cur.second+1});
            }
        }
        else if (cur.second == depth) {
            result.push_back(cur.first->Data);
        }
    }
    return result;
}

int main(){
    TreeNodePtr node = Tree::CreateBinaryTreeFromVector({1, 2, 5, 3, 6, 7, 12, 3, 30, 9});
    int depth = 0;
    std::list<int> l;
    do {
        l = CreateListOfDepth(node, depth++);
        std::copy(l.begin(), l.end(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;
    } while(!l.empty());

    return 0;
}
