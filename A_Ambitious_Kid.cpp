#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }

    long long minimum_operations = INT_MAX;
    for (int i = 0; i < n; i++) {
        minimum_operations = min(minimum_operations, (long long)abs(a[i]));
    }
    cout << minimum_operations << endl;

    return 0;
}