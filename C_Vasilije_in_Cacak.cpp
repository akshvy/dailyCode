#include<bits/stdc++.h>
using namespace std; 

int main(){
    int t;
    cin >> t;
    while(t--){
        long long n, k, x;
        cin >> n >> k >> x;

        long long min = (k*(k + 1))/2;

        long long max = (n * (n + 1)) / 2 - ((n - k) * (n - k + 1)) / 2;
        
        if(x < min || x > max){
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
        }
    }
    return 0;
}