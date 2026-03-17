#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; 
    cin>>t;
    while(t--){
        long long n;
        cin>>n;

        if(n % 21 == 0){
            cout<<"o"<<endl;
        }
        string s = to_string(n);
            vector<int> arr;
        for(int i = 0; i < s.size(); i++){
            arr.push_back(s[i] - '0');
    }
        }
    }
    return 0;
