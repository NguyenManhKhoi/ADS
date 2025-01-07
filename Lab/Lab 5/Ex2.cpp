#include <iostream>
#include <vector>

int binarySearch(const std::vector<int> &array, int key, int low, int high) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (array[mid] == key)
            return mid;
        else if (array[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

void insertionSortWithBinarySearch(std::vector<int> &array) {
    int size = array.size();
    for (int i = 1; i < size; i++) {
        int current = array[i];
        int j = i - 1;
        int insertPosition = binarySearch(array, current, 0, j);
        while (j >= insertPosition) {
            array[j + 1] = array[j];
            j--;
        }
        array[insertPosition] = current;
    }
}

int main() {
    std::vector<int> elements = {12, 11, 13, 5, 6};
    insertionSortWithBinarySearch(elements);
    std::cout << "Sorted array: ";
    for (int value : elements) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
    return 0;
}