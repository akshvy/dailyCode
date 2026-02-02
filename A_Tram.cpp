#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;   

    int current = 0;
    int max_passengers = 0;

    while(t--) {
        int a, b;
        cin >> a >> b;

        current = current - a + b;   
        
        if(current > max_passengers) {
            max_passengers = current;   
        }
    }

    cout << max_passengers << endl;

    return 0;
}
