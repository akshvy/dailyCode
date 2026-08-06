#include<bits/stdc++.h>
using namespace std; 

int main(){
    long long t;
    cin>>t; 
    while(t--){
        long long n, k;
        cin>>n>>k;

        string s;
        cin>>s;

        vector<int>frequency(26, 0);
        for(int i = 0; i < n; i++){
            frequency[s[i] - 'a']++;
        }

        long long odd_f = 0;
        for(int i = 0; i < 26; i++){
            odd_f += frequency[i] % 2;
        }

        if(odd_f > k +1){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }

        
    }
    return 0;
}