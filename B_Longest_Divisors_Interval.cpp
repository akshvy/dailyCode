#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long a = 1;
	for (long long i = 2; i <= 50; i++)
	{
		a = lcm(a, i);
	}
	int t;
	cin >> t;
	while (t--)
	{
		
		long long n;
		cin >> n;

		
		int i = 1;

		while (n % i == 0) 
			i++;

		cout << i - 1 << endl;
	}
	return 0;
}
