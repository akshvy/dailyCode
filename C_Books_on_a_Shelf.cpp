#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> h(n);
        for (int i = 0; i < n; i++) {
            cin >> h[i];
        }
        sort(h.begin(), h.end());

        vector<int> left, mid, right;

        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && h[j] == h[i]) {
                j++;
            }
            int cnt = j - i;
            int v = h[i];

            left.push_back(v);
            if (cnt >= 2) {
                right.push_back(v);
            }
            for (int k = 0; k < cnt - 2; k++) {
                mid.push_back(v);
            }

            i = j;
        }

        reverse(right.begin(), right.end());

        cout << left.size() + right.size() << "\n";

        for (int x : left) cout << x << " ";
        for (int x : mid) cout << x << " ";
        for (int x : right) cout << x << " ";
        cout << "\n";
    }
    return 0;
}