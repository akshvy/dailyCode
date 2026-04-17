#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; 
    cin >> t;
    while (t--)
    {
        long long n; 
        cin >> n;
        long long a[n]; 
        for (long long i = 0; i < n; i++) 
            cin >> a[i];
        

        long long positive_count = 0; 
        long long negative_count = 0; 
        for (long long i = 0; i < n; i++) 
        {
            if (a[i] == 1)
                positive_count++;
            else
                negative_count++;
        }

        long long operations = 0;
        while (positive_count < negative_count || negative_count % 2 == 1) 
        {
            operations++; 
            positive_count++; 
            negative_count--; 
        }

        cout << operations << endl; 
    }
    return 0;
}
