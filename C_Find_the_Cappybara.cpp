#include <iostream>
using namespace std;

int solve(int n){
    if(n <= 1) return n;
    int hmcut = 1 + solve(n/2);
    return hmcut;
}

int main(){
    int t;
    cin >> t;
    while(t--){
       int n;
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}
