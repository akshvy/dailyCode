#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        int prev = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            char def = (i % 2 == 0) ? 'R' : 'B';
            int d = (s[i] == def) ? 0 : 1;
            if (d != prev) ans++;
            prev = d;
        }
        cout << ans << "\n";
    }
}