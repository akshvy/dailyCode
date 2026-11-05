#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int x, y, z;
        cin >> x >> y >> z;
        int n = x + y + z;

        char c;
        if (y >= z) c = 'R';
        else if (z >= x) c = 'S';
        else c = 'P';

        cout << string(n, c) << '\n';
    }
    return 0;
}