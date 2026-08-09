#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;

        int valid_ways = 0;

        for(int s1 = 0; s1 <= 1; s1++){
            for(int s2 = 0; s2 <= 1; s2++){
                bool possible = true;

                for(int i = 0; i < n; i++){
                    int expected;
                    if(i % 2 == 0){
                        expected = ((i / 2) % 2 == 0) ? s1 : (1 - s1);
                    }else{
                        expected = (((i - 1) / 2) % 2 == 0) ? s2 : (1 - s2);
                    }

                    if(s[i] != '?' && (s[i] - '0') != expected){
                        possible = false;
                        break;
                    }
                }

                if(possible){
                    valid_ways++;
                }
            }
        }

        cout << valid_ways % 998244353 << endl;
    }
    return 0;
}