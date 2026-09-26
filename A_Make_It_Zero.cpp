#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t; // Read the number of test cases
	while (t--)
	{
		long long n;
		cin >> n; // Read the length of the array
		long long a[n];
		for (int i = 0; i < n; i++) // Read the array elements
			cin >> a[i];
		// Check if the length of the array is even or odd
		if (n % 2 == 0) // If n is even
		{
			cout << 2 << endl; // Output the number of operations
			cout << 1 << " " << n << endl; // Perform operation on the entire array
			cout << 1 << " " << n << endl; // Repeat the operation
		}
		else // If n is odd
		{
			cout << 4 << endl; // Output the number of operations
			cout << 1 << " " << n - 1 << endl; // Perform operation on the first n-1 elements
			cout << 1 << " " << n - 1 << endl; // Repeat the operation
			cout << n - 1 << " " << n << endl; // Perform operation on the last two elements
			cout << n - 1 << " " << n << endl; // Repeat the operation
		}
	}
	return 0;
}

// Time Complexity (TC): O(n) = O(100)
// Space Complexity (SC): O(n) = O(100)
