#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int x, y;
        cin >> x >> y;
        
        
        int min = (2*y) / (2*x + 1) + 1; 
        int max = (y - 1) / x;            
        
    if(min <= max){
        int a = min;
        int b = y - a * x;
            cout << a << " " << b << "\n";
        } else {
            cout << "-1\n";
        }
    }
    return 0;
}