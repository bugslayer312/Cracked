#include <iostream>
#include <stack>
#include <vector>
#include <exception>

class EmptyStackException : public std::exception
{
};

class IndexOverboundException : public std::exception
{
};

class SetOfStacks {
    std::vector<std::stack<int>> m_stacks;
    size_t m_chunkCapacity;

public:
    SetOfStacks(size_t chunkCapacity) :
        m_chunkCapacity(chunkCapacity) {
    }

    bool isEmpty() const {
        return m_stacks.empty();
    }

    int peek() const {
        if (isEmpty()) {
            throw EmptyStackException();
        }
        return m_stacks.back().top();
    }

    void push(int el) {
        if (m_stacks.empty() || m_stacks.back().size() == m_chunkCapacity) {
            m_stacks.push_back(std::stack<int>({el}));
        }
        else {
            m_stacks.back().push(el);
        }
    }

    void pop(int el) {
        if (isEmpty()) {
            throw EmptyStackException();
        }
        m_stacks.back().pop();
        if (m_stacks.back().empty()) {
            m_stacks.pop_back();
        }
    }

    void popAt(size_t i) {
        if (i >= m_stacks.size()) {
            throw IndexOverboundException();
        }
        m_stacks[i].pop();
        if (m_stacks[i].empty()) {
            m_stacks.erase(m_stacks.begin() + i);
        }
    }
};

int main() {
    return 0;
}
