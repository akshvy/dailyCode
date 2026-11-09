#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long t;
	cin >> t; // Read the number of test cases
	while (t--)
	{
		long long a, b, c;
		cin >> a >> b >> c; // Read the three integers a, b, c

		bool answer = false; // Initialize answer as false

		// Check if multiplying 'a' by some positive integer can make the sequence an AP
		long long new_a = 2 * b - c; // Calculate the potential new value for 'a'
		if (new_a / a > 0 && new_a % a == 0) // Check if new_a is a positive multiple of 'a'
			answer = true;

		// Check if multiplying 'b' by some positive integer can make the sequence an AP
		long long new_b = (a + c) / 2; // Calculate the potential new value for 'b'
		if (new_b / b > 0 && new_b % b == 0 && (c - a) % 2 == 0) // Check if new_b is a positive multiple of 'b' and (c-a) is even
			answer = true;

		// Check if multiplying 'c' by some positive integer can make the sequence an AP
		long long new_c = 2 * b - a; 
		if (new_c / c > 0 && new_c % c == 0) 
			answer = true;

		
		if (answer)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}


