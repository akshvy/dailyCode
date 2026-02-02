#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;
        int arr[n]; 

        int L = (n + 1) / 2;
        int R = left + 1;

        arr[0] = L;
        left--; 

        
        for (int i = 1; i < n; i++) {
            if (i % 2 != 0) {
                arr[i] = R;
                R++;
            } else {
                arr[i] = L;
                L--;
            }
        }

        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}