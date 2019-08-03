#include <iostream>
#include <stack>
#include <exception>

class EmptyStackException : public std::exception
{
};

class Queue {
    std::stack<int> m_store;
    std::stack<int> m_read;
    bool m_isStore = true;

    void SwitchMode() {
        std::stack<int>& fromStack = m_isStore ? m_store : m_read;
        std::stack<int>& toStack = m_isStore ? m_read : m_store;
        while (!fromStack.empty()) {
            toStack.push(fromStack.top());
            fromStack.pop();
        }
        m_isStore = !m_isStore;
    }

public:
    void add(int el) {
        if (!m_isStore) {
            SwitchMode();
        }
        m_store.push(el);
    }

    bool isEmpty() const {
        return m_store.empty() && m_read.empty();
    }

    void remove() {
        if (isEmpty()) {
            throw EmptyStackException();
        }
        if (m_isStore) {
            SwitchMode();
        }
        m_read.pop();
    }

    int peek() {
        if (isEmpty()) {
            throw EmptyStackException();
        }
        if (m_isStore) {
            SwitchMode();
        }
        return m_read.top();
    }
};

int main() {
    Queue q;
    for (int i=0; i < 5;++i) {
        q.add(i);
    }
    for (int i=0; i < 4;++i) {
        std::cout << q.peek() << " ";
        q.remove();
    }
    std::cout << std::endl;
    for (int i=5; i < 10;++i) {
        q.add(i);
    }

    for (; !q.isEmpty();) {
        std::cout << q.peek() << " ";
        q.remove();
    }
    std::cout << std::endl;
}
