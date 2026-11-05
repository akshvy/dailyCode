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
        vector<long long> a(n);
        long long S = 0;
        bool allOnes = true, interiorBig = false;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            S += a[i];
            if (a[i] >= 2) allOnes = false;
            if (i > 0 && i < n - 1 && a[i] >= 2) interiorBig = true;
        }

        if (allOnes) cout << -1 << '\n';
        else if (interiorBig) cout << S - 1 << '\n';
        else cout << a[0] + a[n - 1] - 1 << '\n';
    }
    return 0;
}