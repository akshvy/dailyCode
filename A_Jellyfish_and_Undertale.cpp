#include<bits/stdc++.h>
using namespace std; 

int main(){
    int t; 
    cin>>t; 
    while(t--){
        int a, b, n;
        cin>>a>>b>>n;

        int x[n];
        for(int i=0;i<n;i++){
            cin>>x[i];
        }

        long long max_num = b;

        for (int i = 0; i < n; i++)

			max_num += min(x[i], a - 1);

        cout<<max_num<<endl;
     
    }
    return 0;
}