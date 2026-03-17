#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            int servers = n - i; 
            if(arr[i] >= servers){
                ans = servers;
                break;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}