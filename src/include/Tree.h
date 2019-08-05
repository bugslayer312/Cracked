#pragma once

#include <memory>
#include <vector>

template<template<typename> class Tree, class T>
void InOrderTraversal(std::shared_ptr<Tree<T>> node, void(*f)(std::shared_ptr<Tree<T>>)) {
    if (node) {
        InOrderTraversal(node->LeftChild, f);
        f(node);
        InOrderTraversal(node->RightChild, f);
    }
}

template<class T>
struct TreeNode {
    typedef std::shared_ptr<TreeNode<T>> TreeNodePtr;
    typedef void(*TreeNodeVisitFunc)(TreeNodePtr);

    T Data;
    TreeNodePtr LeftChild;
    TreeNodePtr RightChild;

    TreeNodePtr Clone() {
        TreeNodePtr result = Create(Data);
        if (LeftChild) {
            result->LeftChild = LeftChild->Clone();
        }
        if (RightChild) {
            result->RightChild = RightChild->Clone();
        }
        return result;
    }

    static TreeNodePtr Create(T const& data) {
        return TreeNodePtr(new TreeNode<T>(data));
    }

    static TreeNodePtr CreateBinaryTreeFromVector(std::vector<int> const& v) {
        return VectorToTreeRecur(v, 0, v.size());
    }

    static void InOrderTraversal(TreeNodePtr node, TreeNodeVisitFunc f) {
        ::InOrderTraversal(node, f);
    }
private:
    static TreeNodePtr VectorToTreeRecur(std::vector<int> const& v, size_t l, size_t r)
    {
        if (l >= r) {
            return nullptr;
        }
        size_t middle = (l + r) / 2;
        TreeNodePtr node = Create(v[middle]);
        node->LeftChild = VectorToTreeRecur(v, l, middle);
        node->RightChild = VectorToTreeRecur(v, middle+1, r);
        return node;
    }

private:
    TreeNode(T const& data) : Data(data) {}
};

template<class T>
struct TreeNode2
{
    typedef std::shared_ptr<TreeNode2<T>> TreeNodePtr;
    typedef void(*TreeNodeVisitFunc)(TreeNodePtr);

private:
    class ParentStorage {
        std::weak_ptr<TreeNode2<T>> m_ptr;
    public:
        ParentStorage() = default;
        ParentStorage(TreeNodePtr ptr): m_ptr(ptr) {}
        operator TreeNodePtr() {
            return m_ptr.lock();
        }
        operator bool() {
            return m_ptr.lock() != nullptr;
        }
        TreeNode2<T>* operator->() {
            if (TreeNodePtr ptr = m_ptr.lock()) {
                return ptr.get();
            }
            return nullptr;
        }
        bool operator==(TreeNodePtr rhs) const {
            return m_ptr.lock() == rhs;
        }
    };

public:
    T Data;
    TreeNodePtr LeftChild;
    TreeNodePtr RightChild;
    ParentStorage Parent;

    static TreeNodePtr Create(T const& data, TreeNodePtr parent = nullptr) {
        TreeNodePtr result = TreeNodePtr(new TreeNode2<T>(data));
        result->Parent = parent;
        return result;
    }

    static TreeNodePtr CreateBinaryTreeFromVector(std::vector<int> const& v) {
        return VectorToTreeRecur(v, 0, v.size(), nullptr);
    }

private:
    TreeNode2(T const& data) : Data(data) {}

    static TreeNodePtr VectorToTreeRecur(std::vector<int> const& v, size_t l, size_t r, TreeNodePtr parent)
    {
        if (l >= r) {
            return nullptr;
        }
        size_t middle = (l + r) / 2;
        TreeNodePtr node = Create(v[middle], parent);
        node->LeftChild = VectorToTreeRecur(v, l, middle, node);
        node->RightChild = VectorToTreeRecur(v, middle+1, r, node);
        return node;
    }

    static void InOrderTraversal(TreeNodePtr node, TreeNodeVisitFunc f) {
        ::InOrderTraversal(node, f);
    }
};

template<template<typename> class Tree, class T>
std::shared_ptr<Tree<T>> FindInBinarySearchTree(std::shared_ptr<Tree<T>> node, T const& value){
    if (node) {
        if (node->Data == value) {
            return node;
        }
        else if (node->Data > value) {
            return FindInBinarySearchTree(node->LeftChild, value);
        }
        else {
            return FindInBinarySearchTree(node->RightChild, value);
        }
    }
    return nullptr;
}
