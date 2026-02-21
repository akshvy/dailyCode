#include <iostream>
#include <vector>
using namespace std;

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        string s;
        cin >> s;

        bool zero = false;

        for (char c : s) {
            if (c == '0') {
                zero = true;
            }
        }

        if (!zero) {
            cout << -1 << endl;
            continue;
        }

        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                ans.push_back(i + 1);
            }
        }

        cout << ans.size() << endl;

        for (int x : ans) {
            cout << x << " ";
        }

        cout << endl;
    }
}