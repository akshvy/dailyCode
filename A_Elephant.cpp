#include<iostream>
using namespace std;
int main() {
    int x;
    cin >> x;
     int total = 0;
     while (x){
        if (x == 1 || x ==2 || x ==3 || x == 4 || x == 5){
            total += 1;
            break;
        }
        else{
            x -= 5;
            total += 1;
            
        }
        
     }
     cout << total << endl;
    return 0;
    
}