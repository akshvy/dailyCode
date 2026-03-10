#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long t;
	cin >> t; // Read the number of test cases
	while (t--)
	{
		long long n, p;
		cin >> n >> p; // Read the number of residents and the cost to share directly
		vector<pair<long long, long long>> v(n); // Vector to store pairs of (sharing cost, max shares)
		vector<long long> a(n), b(n); // Vectors to store max shares and sharing costs

		// Read the maximum number of residents each resident can share the announcement to
		for (int i = 0; i < n; i++)
			cin >> a[i];

		// Read the cost for each resident to share the announcement
		for (int i = 0; i < n; i++)
			cin >> b[i];

		// Populate the vector with pairs of (sharing cost, max shares)
		for (int i = 0; i < n; i++)
			v[i] = {b[i], a[i]};

		// Sort the vector based on sharing cost (ascending order)
		sort(v.begin(), v.end());

		long long minimum_cost = p; // Start with the cost of sharing to one resident directly
		long long already_shared = 1; // Start with one resident already informed

		// Iterate over the sorted vector
		for (auto it : v)
		{
			long long can_be_shared = it.second; // Max number of residents this resident can share with
			long long sharing_cost = it.first; // Cost for this resident to share

			// If the sharing cost is greater than or equal to direct sharing cost, break
			if (sharing_cost >= p)
				break;

			// If sharing with all possible residents exceeds total residents, adjust
			if (already_shared + can_be_shared > n)
			{
				minimum_cost += (n - already_shared) * sharing_cost;
				already_shared = n; // All residents are informed
				break;
			}
			else
			{
				minimum_cost += can_be_shared * sharing_cost; // Add cost for sharing
				already_shared += can_be_shared; // Update the count of informed residents
			}
		}

		// Add the cost for the remaining residents to be informed directly
		minimum_cost += (n - already_shared) * p;
		cout << minimum_cost << endl; // Output the minimum cost for this test case
	}
	return 0;
}

// Time Complexity (TC): O(nlogn) = O(10^5(log2(10^5))) = O(10^5 * 17) = O(1.7 * 10^6)
// Space Complexity (SC): O(n) = O(10^5)
