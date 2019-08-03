#include <initializer_list>
#include <iosfwd>

namespace OldLinkedList {

template<class T>
struct SingleListNode{
    T Data;
    SingleListNode* Next = nullptr;

    SingleListNode(T const& data) : Data(data) {}
    SingleListNode(std::initializer_list<T> const& l) {
        SingleListNode* prev = nullptr;
        SingleListNode* cur = this;
        for (T const& el : l) {
            if (cur) {
                cur->Data = el;
            }
            else {
                cur = new SingleListNode(el);
                prev->Next = cur;
            }
            prev = cur;
            cur = cur->Next;
        }
    }

    ~SingleListNode() {
        if (Next) {
            delete Next;
        }
    }
};

template<class T>
struct DoubleListNode{
    T Data;
    DoubleListNode* Prev = nullptr;
    DoubleListNode* Next = nullptr;

    DoubleListNode(T const& data) : Data(data) {}
    DoubleListNode(std::initializer_list<T> const& l) {
        DoubleListNode* prev = nullptr;
        DoubleListNode* cur = this;
        for (T const& el : l) {
            if (cur) {
                cur->Data = el;
            }
            else {
                cur = new DoubleListNode(el);
                prev->Next = cur;
            }
            cur->Prev = prev;
            prev = cur;
            cur = cur->Next;
        }
    }
    ~DoubleListNode() {
        if (Next) {
            delete Next;
        }
    }

    static void Remove(DoubleListNode<T>* toRemove) {
        if (toRemove->Prev) {
            toRemove->Prev->Next = toRemove->Next;
        }
        if (toRemove->Next) {
            toRemove->Next->Prev = toRemove->Prev;
            toRemove->Next = nullptr;
        }
        delete toRemove;
    }
};

template<template<typename> class List, class T>
std::ostream& operator<<(std::ostream& os, List<T>* l) {
    while (l) {
        os << l->Data << ' ';
        l = l->Next;
    }
    return os;
}

}
