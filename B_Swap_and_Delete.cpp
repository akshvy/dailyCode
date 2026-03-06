#include <iostream>
#include <string>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    
    int c0 = 0, c1 = 0;
    for (char c : s) {
        if (c == '0') c0++; else c1++;
    }
    
    // Find maximum k such that:
    // O_k (# of 1s in s[0..k-1]) <= c0
    // Z_k (# of 0s in s[0..k-1]) <= c1
    // Binary search or linear scan
    
    int maxK = 0;
    int ones = 0, zeros = 0;
    for (int k = 1; k <= n; k++) {
        if (s[k-1] == '1') ones++; else zeros++;
        if (ones <= c0 && zeros <= c1) {
            maxK = k;
        }
    }
    
    cout << (n - maxK) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}