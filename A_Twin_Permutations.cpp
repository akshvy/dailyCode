#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; 
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin>>a[i];
        } 
        vector<int> b(n);
        for(int i = 0; i < n; i++){
            b[i] = n+1 - a[i];
            cout<<b[i]<<" ";
        }
        cout<<endl;
    }
        return 0;
    }