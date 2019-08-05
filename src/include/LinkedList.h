#pragma once

#include <initializer_list>
#include <iosfwd>
#include <memory>
//#include <iostream>

template<class T>
struct SingleListNode{
    typedef std::shared_ptr<SingleListNode> NodePtr;
    T Data;
    NodePtr Next;

    static NodePtr Create(T const& data) {
        return std::shared_ptr<SingleListNode<T>>(new SingleListNode<T>(data));
    }

    static NodePtr Create(std::initializer_list<T> const& l) {
        NodePtr head, prev;
        for (T const& el : l) {
            NodePtr cur = Create(el);
            if (prev) {
                prev->Next = cur;
            }
            else {
                head = cur;
            }
            prev = cur;
        }
        return head;
    }
    //~SingleListNode<T>() {
    //    std::cout << "Deleting " << Data << std::endl;
    //}

private:
    SingleListNode<T>() {}
    SingleListNode<T>(T const& data) : Data(data){}
};

template<class T>
struct DoubleListNode{
    typedef std::shared_ptr<DoubleListNode> NodePtr;

private:
    class PrevStorage{
        std::weak_ptr<DoubleListNode> m_ptr;

    public:
        PrevStorage() = default;
        PrevStorage(NodePtr ptr) : m_ptr(ptr){}
        operator NodePtr() {
            return m_ptr.lock();
        }
    };

public:
    T Data;
    PrevStorage Prev;
    NodePtr Next;

    static NodePtr Create(T const& data) {
        return std::shared_ptr<DoubleListNode<T>>(new DoubleListNode<T>(data));
    }

    static NodePtr Create(std::initializer_list<T> const& l) {
        NodePtr head, prev;
        for (T const& el : l) {
            NodePtr cur = Create(el);
            if (prev) {
                prev->Next = cur;
            }
            else {
                head = cur;
            }
            cur->Prev = prev;
            prev = cur;
        }
        return head;
    }

    static NodePtr Remove(NodePtr head, NodePtr toRemove) {
        NodePtr prev = toRemove->Prev;
        if (prev) {
            prev->Next = toRemove->Next;
        }
        else {
            head = toRemove->Next;
        }
        if (toRemove->Next) {
            toRemove->Next->Prev = prev;
            toRemove->Next = nullptr;
        }
        return head;
    }

    //~DoubleListNode() {
    //    std::cout << "Deleting " << Data << std::endl;
    //}
private:
    DoubleListNode();
    DoubleListNode(T const& data) : Data(data) {}
};

template<template<typename> class List, class T>
std::ostream& operator<<(std::ostream& os, std::shared_ptr<List<T>> node) {
    while (node) {
        os << node->Data << ' ';
        node = node->Next;
    }
    return os;
}

template<template<typename> class List, class T>
std::size_t CalcListLength(std::shared_ptr<List<T>> node) {
    std::size_t result = 0;
    while (node) {
        ++result;
        node = node->Next;
    }
    return result;
}

template<template<typename> class List, class T>
std::shared_ptr<List<T>> GetLastNode(std::shared_ptr<List<T>> node) {
    if (!node) {
        return nullptr;
    }
    while (node->Next) {
        node = node->Next;
    }
    return node;
}

template<template<typename> class List, class T>
bool ListsIsEqual(std::shared_ptr<List<T>> node1, std::shared_ptr<List<T>> node2) {
    while (node1) {
        if (!node2 || node2->Data != node1->Data) {
            return false;
        }
        node1 = node1->Next;
        node2 = node2->Next;
    }
    return !node1 && !node2;
}
