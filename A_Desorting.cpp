#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        vector<long long> a(n);

        for(long long i = 0; i < n; i++){
            cin >> a[i];
        }

        // Check if sorted
        bool sorted = true;
        for(long long i = 0; i < n-1; i++){
            if(a[i] > a[i+1]){
                sorted = false;
                break;
            }
        }

        if(!sorted){
            cout << 0 << endl;
            continue;
        }

        // Find minimum adjacent difference
        long long mn = LLONG_MAX;
        for(long long i = 0; i < n-1; i++){
            mn = min(mn, a[i+1] - a[i]);
        }

        // Answer
        cout << (mn / 2) + 1 << endl;
    }
}