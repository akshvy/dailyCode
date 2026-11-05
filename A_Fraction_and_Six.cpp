#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        string p, q;
        cin >> n >> m >> p >> q;

        int cnt[26] = {0};
        for (char c : p) cnt[c - 'a']++;
        for (char c : q) cnt[c - 'a']--;
        cnt['s' - 'a']--;
        cnt['i' - 'a']--;
        cnt['x' - 'a']--;

        bool ok = true;
        for (int i = 0; i < 26; i++) if (cnt[i] != 0) ok = false;

        cout << (ok ? "YES" : "NO") << '\n';
    }
}