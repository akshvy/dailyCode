#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector< long long> a(n);
        for(int i=0; i<n -1; i++){
            cin>>a[i];
        }

        long long sum = accumulate(a.begin(), a.end(), 0LL);

        cout<< -(sum)<<endl;
    }
    return 0;
}