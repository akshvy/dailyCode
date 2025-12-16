#include<iostream>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    int scores[n];
    for (int i = 0; i < n; i++) {
        cin >> scores[i];
    }
    int pivot = scores[k - 1];
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (scores[i] > 0 && scores[i] >= pivot) {
            count++;
        }
    }
    cout << count << endl;
}