#include <iostream>

using namespace std;

// Pseudocode:
// def findMax(a, b):
//     if a > b:
//         return a

void findMax(int &max, int a) {
  if (a > max) {
    max = a;
  }
}

// Pseudocode:
// def main():
//     n = int(input())
//     max = 0
//     for i in range(n):
//         a = int(input())
//         findMax(max, a)
//     print(max)

int main() {
    cout << "Enter the size of the array: ";
    int size;
    cin >> size;

    int arr[size];

    cout << "Enter the elements of the array, each separated by a space: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int max = arr[0];
    for (int i = 1; i <= size; i++) {
        findMax(max, arr[i]);
    }

    cout << "The maximum number is " << max << endl;
    return 0;
}

// Complexity: O(n)