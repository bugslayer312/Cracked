#include "Graph.h"
#include <iostream>
#include <iterator>
#include <list>

bool DoDFS(Graph<char>& g, Graph<char>::Node& node, std::list<char>& result) {
    if (node.State == NodeState::Visiting) {
        return false;
    }
    if (node.State == NodeState::NotVisited) {
        node.State = NodeState::Visiting;
        for (auto& i : node.Adjacent) {
            if (!DoDFS(g, g.Nodes[i], result)) {
                return false;
            }
        }
        node.State = NodeState::Visited;
        result.push_back(node.Data);
    }
    return true;
}

bool CalcBuildOrder(Graph<char>& g, std::list<char>& result) {
    for (auto& kv : g.Nodes) {
        auto& node = kv.second;
        if (node.State == NodeState::NotVisited) {
            if (!DoDFS(g, node, result)) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    Graph<char> g({'a', 'b', 'c', 'd', 'e', 'f'}, {{'d', 'a'}, {'b', 'f'}, {'d', 'b'}, {'a', 'f'}, {'c', 'd'}});
    std::list<char> order;
    if (CalcBuildOrder(g, order)) {
        std::copy(order.begin(), order.end(), std::ostream_iterator<char>(std::cout, " "));
    }
    else {
        std::cout << "No order" << std::endl;
    }

    return 0;
}
