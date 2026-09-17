#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; 
    cin>>t;
    while(t--){
        int n; 
        cin>>n;
        string s;
        cin>>s;
        
        int x = 1, y = 1; 

        for(int i = 1; i < n; i++){
        if(s[i] == s[i -1]){
            x++;
        }else{
            y = max(y, x);
            x = 1;
        }
            
        y = max(y, x);
        }
        cout<<y + 1<<endl;
        
    }
    return 0;
}