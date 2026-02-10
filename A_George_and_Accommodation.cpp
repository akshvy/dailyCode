#include <iostream>
using namespace std;

int main() {
    int t, m, n, count = 0;
    cin >> t;

    
    while (t--) {
        cin >> n >> m;
        if (m - n >= 2) {
            count++;
        }
    }

    cout << count;
    return 0;
}
