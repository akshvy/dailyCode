#include <iostream>
#include <algorithm> // for min()
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        int ans = k; // Initialize with a large possible value
        int even_count = 0;

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            
            if (arr[i] % k == 0) {
                ans = 0;
            } else {
                // Calculate moves to reach next multiple of k
                ans = min(ans, k - (arr[i] % k));
            }

            // Keep track of even numbers for the k=4 special case
            if (arr[i] % 2 == 0) {
                even_count++;
            }
        }

        if (k == 4) {
            // Special case: we can make two numbers even (2 operations)
            // or one number even if one is already even (1 operation)
            // or 0 if we already have two even numbers.
            int moves_for_two_evens = max(0, 2 - even_count);
            ans = min(ans, moves_for_two_evens);
        }

        cout << ans << endl;
    }
    return 0;
}