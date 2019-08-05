#pragma once

#include <list>
#include <unordered_map>
#include <initializer_list>

enum class NodeState {
    NotVisited,
    Visiting,
    Visited
};

template<class T>
struct Graph {

    struct Node{
        T Data;
        NodeState State = NodeState::NotVisited;
        std::list<T> Adjacent;

        Node() = default;
        Node(T const& data) : Data(data) {}
    };

    std::unordered_map<T, Node> Nodes;

    Graph(std::initializer_list<T> const& vertexes, std::initializer_list<std::pair<T, T>> const& adjacents) {
        for (auto& v : vertexes) {
            Nodes[v] = Node(v);
        }
        for (auto& adj : adjacents) {
            Nodes[adj.first].Adjacent.push_back(adj.second);
        }
    }

    void FlushVisited() {
        for (auto& p : Nodes) {
            p.second.State = NodeState::NotVisited;
        }
    }
};
