#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        stack<int> st;
        vector<bool> printed(n + 1, false);

        int cur = 1;

        for (char c : s) {
            if (c == '1') {
                // Put current document into memory
                st.push(cur);
            }
            else if (c == '2') {
                if (!st.empty()) {
                    // Print top document from memory
                    printed[st.top()] = true;
                    st.pop();
                }
                else {
                    // Memory empty -> print current document
                    printed[cur] = true;
                }
            }
            else { // c == '3'
                // Quick print current document
                printed[cur] = true;
            }

            cur++;
        }

        vector<int> ans;

        for (int i = 1; i <= n; i++) {
            if (!printed[i]) {
                ans.push_back(i);
            }
        }

        cout << ans.size() << '\n';

        for (int x : ans) {
            cout << x << ' ';
        }

        cout << '\n';
    }

    return 0;
}