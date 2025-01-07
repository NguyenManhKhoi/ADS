#include <iostream>
using namespace std;

// Pseudo code
// 1. Assign input to variable n and convert to string
// 2. Create variable sum and assign 0 to it
// 3. Create a loop from 0 to length of n
// 4. Add the value of n at index i to sum
// 5. Return/print sum

int sumOfInt(string input) {
  int sum = 0; // T(n) = 1
  for (int i = 0; i < input.length(); i++) { // T(n) = n
    sum += input[i] - '0'; // T(n) = n
  }
}
// T(n) = 1 + n + n
// T(n) = 2n + 1
// T(n) = O(n)

int main() {
  string input;
  cout << "Enter a number: ";
  cin >> input;
  cout << "Sum of digits: " << sumOfInt(input) << endl;
  return 0;
}