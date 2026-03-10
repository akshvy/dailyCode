#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
cin >> n;
string a;
cin >> a;

for(auto& x : a){
    x = tolower(x);
}

        set<char> seen(a.begin(), a.end()); 

if(seen.size() == 26){
        cout << "YES";
    }else{
        cout << "NO";
    }
return 0;
}
