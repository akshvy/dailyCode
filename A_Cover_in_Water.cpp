#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        string s;
        cin >> s;

        int count = 0;
        int dot = 0;

        for(int i = 0; i < n; i++){
            if(s[i] == '.')
                dot++;
        }

        for(int i = 0; i <= n - 3; i++){
            if(s[i] == '.' && s[i+1] == '.' && s[i+2] == '.'){
                count++;
            }
        }

        if(count >= 1)
            cout << 2 << endl;   
        else
            cout << dot << endl;
    }

    return 0;
}
