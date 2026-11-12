#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        bool need[26] = {false};

        for (int i = 0; i < n / 2; i++) {
            int u = s[i] - 'a';
            int v = s[n - 1 - i] - 'a';
            if (u > v) swap(u, v);
            for (int x = u + 1; x <= v; x++) {
                need[x] = true;
            }
        }

        int ans = 0;
        for (int x = 0; x < 26; x++) {
            if (need[x]) ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}