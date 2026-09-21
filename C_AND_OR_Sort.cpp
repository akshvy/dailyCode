#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        string s;
        cin>>n>>s;

        int ones = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '1'){
                ones++;
            }
        }

        if(s[0] == '1'){
            cout<<n - ones<<endl;
            continue;
        }

        int ans = ones;
        int prefOnes = 0;

        for(int i = 0; i < n; i++){
            if(s[i] == '1'){
                int suffZeros = (n - i - 1) - (ones - prefOnes - 1);
                ans = min(ans, prefOnes + suffZeros);
                prefOnes++;
            }
        }

        cout<<ans<<endl;
    }
}