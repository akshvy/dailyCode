#include <iostream>
using namespace std;

int main() {
    int N, E;
    
    cin >> E >> N;
    
    int arr[N];
    
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    int count = 0;
    
    for(int i = 0; i < N; i++) {
        if(E >= arr[i]) {
            E -= arr[i];
            count++;
        } else {
            break;
        }
    }
    
    cout << count << endl;
    
    return 0;
}
