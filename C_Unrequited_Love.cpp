#include <bits/stdc++.h>
using namespace std;

static long long cntArr[50001];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        vector<int> a(n);
        for (auto &x : a) scanf("%d", &x);
        int m = n - 4;
        vector<int> v(m);
        for (int i = 0; i < m; i++) v[i] = a[i] + a[i + 2] - a[i + 4];

        long long ans = 0;
        const int OFF = 30000;   // fixed: v in [-30000, 20000]
        for (int i = 0; i < m; i++) {
            ans += cntArr[v[i] + OFF];
            cntArr[v[i] + OFF]++;
        }
        for (int i = 0; i < m; i++) cntArr[v[i] + OFF] = 0;

        for (int i = 0; i < m; i++) {
            if (i + 2 < m && v[i] == v[i + 2]) ans--;
            if (i + 4 < m && v[i] == v[i + 4]) ans--;
        }
        printf("%lld\n", ans);
    }
    return 0;
}