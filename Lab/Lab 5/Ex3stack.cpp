#include <iostream>
#include <stack>

void insertionSortWithStack(std::stack<int>& stk) {
    std::stack<int> temp;

    while (!stk.empty()) {
        int current = stk.top();
        stk.pop();

        while (!temp.empty() && temp.top() > current) {
            stk.push(temp.top());
            temp.pop();
        }

        temp.push(current);
    }

    while (!temp.empty()) {
        stk.push(temp.top());
        temp.pop();
    }
}

int main() {
    std::stack<int> stk;
    stk.push(12);
    stk.push(11);
    stk.push(13);
    stk.push(5);
    stk.push(6);

    insertionSortWithStack(stk);

    std::cout << "Sorted stack: ";
    while (!stk.empty()) {
        std::cout << stk.top() << " ";
        stk.pop();
    }

    return 0;
}