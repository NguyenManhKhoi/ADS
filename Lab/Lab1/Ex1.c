int main() {
	int n;
	cout << "Enter a number: ";
	cin >> n;
	for (int i = 2; i <= n; i++) {
		if (isSpheric(i) == 1) {
			cout << i << " ";
		}
	}
	return 0;
}
// Complexity: O(n^3)