#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        long long m;
        cin >> m;

        long long arr[m];
        for(int i = 0; i < m; i++) {
            cin >> arr[i];
        }

        long long mn = arr[0];
        long long mx = arr[0];

        for(int i = 1; i < m; i++) {
            if(arr[i] > mx)
                mx = arr[i];
            if(arr[i] < mn)
                mn = arr[i];
        }

        for(int i = 0; i < m; i++) {
            if(arr[i] % mn != 0) {
                cout << mx << endl;
                goto next;
            }
        }

        cout << mn << endl;

        next:;
    }

    return 0;
}
