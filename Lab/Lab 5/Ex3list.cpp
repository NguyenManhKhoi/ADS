#include <iostream>
#include <list>

void insertionSortWithList(std::list<int>& lst) {
    for (auto it = std::next(lst.begin()); it != lst.end(); ++it) {
        int key = *it;
        auto insert_pos = std::prev(it);

        while (insert_pos != lst.begin() && *insert_pos > key) {
            std::next(insert_pos) = *insert_pos;
            --insert_pos;
        }

        std::next(insert_pos) = key;
    }
}

int main() {
    std::list<int> lst = {12, 11, 13, 5, 6};
    insertionSortWithList(lst);

    std::cout << "Sorted list: ";
    for (const auto& num : lst) {
        std::cout << num << " ";
    }

    return 0;
}