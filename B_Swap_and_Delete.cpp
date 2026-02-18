#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int c0 = 0, c1 = 0;
    for (char c : s) {
        if (c == '0') c0++;
        else c1++;
    }

    if (c0 == c1) {
        cout << 0 << endl;
    } else {
        cout << abs(c0 - c1) << endl;
    }
}

int main() {
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}