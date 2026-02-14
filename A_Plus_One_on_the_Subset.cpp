#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        sort(a.begin(),a.end());

        set<int> used;
        for(int x: a){
            if(used.count(x)==0) used.insert(x);
            else if(used.count(x+1)==0) used.insert(x+1);
        }

        cout<<used.size()<<"\n";
    }
    return 0;
}