#include <iostream>
#include <queue>

void insertionSortWithQueue(std::queue<int>& q) {
    std::queue<int> sorted_q;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        while (!sorted_q.empty() && sorted_q.back() > current) {
            int temp = sorted_q.back();
            sorted_q.pop();
            q.push(temp);
        }

        sorted_q.push(current);
    }

    while (!sorted_q.empty()) {
        q.push(sorted_q.front());
        sorted_q.pop();
    }
}

int main() {
    std::queue<int> q;
    q.push(12);
    q.push(11);
    q.push(13);
    q.push(5);
    q.push(6);

    insertionSortWithQueue(q);

    std::cout << "Sorted queue: ";
    while (!q.empty()) {
        std::cout << q.front() << " ";
        q.pop();
    }

    return 0;
}