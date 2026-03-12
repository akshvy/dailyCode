#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        vector<int> a(n);
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        
        int count = 0;
        for(int i=0; i<n; i++){
            if(a[i] == k){
                count++;
            }
        }
        if(count > 0){
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}