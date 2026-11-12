#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << ((b - a == 1 && c - b == 1) ? "YES" : "NO") << "\n";
    }
}