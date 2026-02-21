#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int blocks = 1;
         for (int i = 1; i < n; i++) {
            if (s[i] != s[i-1])
                blocks++;
        }

        if (s[0] != s[n-1])
            blocks++;

        cout << min(blocks, n) << endl;
            
    }
}
        
