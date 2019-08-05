#include <iostream>
#include <stack>
#include <cstdlib>

void SortStack(std::stack<int>& s) {
    std::stack<int> temp;
    while(!s.empty()) {
        int next = s.top();
        s.pop();
        int unloadCnt = 0;
        while (!temp.empty()) {
            if (next >= temp.top()) {
                break;
            }
            s.push(temp.top());
            temp.pop();
            ++unloadCnt;
        }
        temp.push(next);
        for (int i=0; i < unloadCnt; ++i) {
            temp.push(s.top());
            s.pop();
        }
    }
    while (!temp.empty()) {
        s.push(temp.top());
        temp.pop();
    }
}

int main() {
    std::stack<int> s;
    for (int i=0; i < 10; ++i) {
        s.push(std::rand() % 10);
    }
    SortStack(s);

    while (!s.empty()) {
        std::cout << s.top() << ' ';
        s.pop();
    }

    return 0;
}
