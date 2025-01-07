#include <stdio.h>
#include <stdlib.h>

// Function to perform binary search to find the correct insertion position.
int binarySearchInsertPosition(int* arr, int size, int v) {
    int left = 0;
    int right = size - 1;
    int mid;

    // Perform binary search.
    while (left <= right) {
        mid = left + (right - left) / 2;

        if (arr[mid] == v) {
            // If the value is already in the array, return the position.
            return mid;
        } else if (arr[mid] < v) {
            // If the value is greater, ignore the left half.
            left = mid + 1;
        } else {
            // If the value is smaller, ignore the right half.
            right = mid - 1;
        }
    }
    // Position where `v` should be inserted.
    return left;
}

// Function to insert `v` into the array `arr` at the correct position.
void insertIntoSortedArray(int* arr, int* size, int v) {
    // Find the position where `v` should be inserted.
    int position = binarySearchInsertPosition(arr, *size, v);

    // Shift elements to the right to make room for `v`.
    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert `v` into the array.
    arr[position] = v;
    // Increase the size of the array.
    (*size)++;
}

// Function to get user input for the sorted array.
void getUserInput(int* arr, int size) {
    printf("Enter %d sorted elements: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

// Function to get the value `v` to insert into the array.
void getValueToInsert(int* v) {
    printf("Enter the value to insert: ");
    scanf("%d", v);
}

// The main function where the execution of the program begins.
int main() {
    int size, valueToInsert;

    // Ask the user for the size of the array.
    printf("Enter the number of elements in the sorted array: ");
    scanf("%d", &size);

    // Dynamically allocate memory for the array with an extra space for the new element.
    int* sortedArray = (int*)malloc((size + 1) * sizeof(int));

    // Get the sorted array from the user.
    getUserInput(sortedArray, size);
    
    // Get the value to insert from the user.
    getValueToInsert(&valueToInsert);

    // Call the function to insert the value into the sorted array.
    insertIntoSortedArray(sortedArray, &size, valueToInsert);

    // Output the updated array to the console.
    printf("Updated array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", sortedArray[i]);
    }
    printf("\n");

    // Release the dynamically allocated memory.
    free(sortedArray);

    return 0;
}