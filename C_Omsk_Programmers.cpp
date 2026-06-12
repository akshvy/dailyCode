#include<bits/stdc++.h>
using namespace std;

long long x;
map<pair<long long,long long>, long long> dp;

long long solve(long long a, long long b){

    if(a > b){
        swap(a,b);
    }

    if(a == b){
        return 0;
    }

    if(dp.count({a,b})){
        return dp[{a,b}];
    }

    long long ans = b - a;

    if(a > 0){
        long long r = a % x;

        ans = min(ans, r + 1 + solve(a / x, b));

        if(r != 0){
            ans = min(ans, (x - r) + 1 + solve(a / x + 1, b));
        }
    }

    if(b > 0){
        long long r = b % x;

        ans = min(ans, r + 1 + solve(a, b / x));

        if(r != 0){
            ans = min(ans, (x - r) + 1 + solve(a, b / x + 1));
        }
    }

    return dp[{a,b}] = ans;
}

int main(){
    int t;
    cin >> t;

    while(t--){

        long long a,b;
        cin >> a >> b >> x;

        dp.clear();

        cout << solve(a,b) << endl;
    }

    return 0;
}