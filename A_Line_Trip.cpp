#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, x;
        cin >> n >> x;

        int a[55];

        for(int i = 0; i < n; i++)
            cin >> a[i];

        int maxDist = a[0];  

        for(int i = 1; i < n; i++)
            maxDist = max(maxDist, a[i] - a[i-1]);

        maxDist = max(maxDist, 2 * (x - a[n-1]));

        cout << maxDist << endl;
    }

    return 0;
}
