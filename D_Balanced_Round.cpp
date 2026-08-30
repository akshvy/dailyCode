#include<bits/stdc++.h>
using namespace std;

int check(vector<int> arr, int k){

    sort(arr.begin(), arr.end() );
    int n = arr.size();
    int cnt = 1;
    int LN = 1; 

    for (int i = 1; i < n; i++){
        if (arr[i] - arr[i-1] <= k){
            cnt++;
        }else{
            cnt = 1;
        }
        LN = max(LN, cnt);
    }
    return n - LN;
} 
int main(){
     int t; 
     cin>>t;
     while (t--){
        int n, k;
        cin>>n>>k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++){
            cin>>arr[i];    
        }
        cout<<check(arr, k)<<endl;
     }
}