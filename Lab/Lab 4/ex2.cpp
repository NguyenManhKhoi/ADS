#include <stdio.h>

int isPalindrome(int arr[], int start, int end) {

    if (start >= end) {

        return 1; // It's a palindrome

    }

    

    if (arr[start] == arr[end]) {

        return isPalindrome(arr, start + 1, end - 1);

    }

    

    return 0; // Not a palindrome

}

int main() {

    int arr[] = {1, 2, 3, 2, 1}; // Example input

    int n = sizeof(arr) / sizeof(arr[0]);

    

    if (isPalindrome(arr, 0, n - 1)) {

        printf("The array is a palindrome.\n");

    } else {

        printf("The array is not a palindrome.\n");

    }

    

    return 0;

}
