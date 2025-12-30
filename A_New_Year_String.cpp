#include <iostream>
#include <string>

using namespace std;

void solve() {
    int n;
    string s;
    if (!(cin >> n >> s)) return;

    bool has_2026 = (s.find("2026") != string::npos);
    bool has_2025 = (s.find("2025") != string::npos);

    if (has_2026 || !has_2025) {
        cout << 0 << endl;
    } else {
        cout << 1 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}