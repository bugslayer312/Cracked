#include <iostream>
#include <stack>
#include <exception>

class EmptyStackException : public std::exception
{
};

template<class T>
class MinStack {
    std::stack<std::pair<T, T>> m_stack;

public:
    void pop() {
        if (isEmpty()) {
            throw EmptyStackException();
        }
        m_stack.pop();
    }

    void push(T const& el) {
        m_stack.push(m_stack.empty() ? std::make_pair(el, el)
                                     : std::make_pair(el, std::min(el, m_stack.top().first)));
    }

    T& peek() {
        if (isEmpty()) {
            throw EmptyStackException();
        }
        return m_stack.top().first;
    }

    bool isEmpty() const {
        return m_stack.empty();
    }

    T const& min() {
        if (isEmpty()) {
            throw EmptyStackException();
        }
        return m_stack.top().second;
    }
};

int main() {
    MinStack<int> stack;
    stack.push(5);
    std::cout << stack.peek() << " " << stack.min() << std::endl;
    stack.push(3);
    std::cout << stack.peek() << " " << stack.min() << std::endl;
    stack.push(2);
    std::cout << stack.peek() << " " << stack.min() << std::endl;
    stack.push(4);
    std::cout << stack.peek() << " " << stack.min() << std::endl;
    for (int i = 0; i < 3;++i) {
        stack.pop();
        std::cout << stack.peek() << " " << stack.min() << std::endl;
    }
    return 0;
}
