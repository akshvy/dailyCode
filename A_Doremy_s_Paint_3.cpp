#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
cin >> t;
while(t--){
int n;
cin >> n;
        vector<int> a(n);
for(auto& x : a){
cin >> x;
        }
        sort(a.begin(), a.end());
if(n == 2){
            cout << "YES" << endl;
            continue;
        }
int cnt = 0;
for(int i = 0; i < n-1; i++){
if(a[i] != a[i+1]){
                cnt++;
            }
        }
if(cnt == 0){
            cout << "YES" << endl;
        }else if(cnt == 1 && n % 2 == 1){
int c = count(a.begin(), a.end(), a[0]);
if(c == n/2 || c == n/2 + 1){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }else if(cnt == 1 && n % 2 == 0){
if(count(a.begin(), a.end(), a[0]) == n/2){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }else{
            cout << "NO" << endl;
        }
    }
return 0;
}