#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; 
    cin >> t;
    while (t--)
    {
        long long n; 
        cin >> n;
        long long a[n]; 
        for (int i = 0; i < n; i++) 
            cin >> a[i];
     
        long long count_of_odd = 0; 
        for (int i = 0; i < n; i++) 
        {
            if (a[i] % 2 == 1) 
                count_of_odd++; 
        }
        
        
        if (count_of_odd % 2 == 1)
            cout << "NO" << endl; 
        else
            cout << "YES" << endl;
    }
    return 0;
}

