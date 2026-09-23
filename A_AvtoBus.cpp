#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; 
    cin>>t;
    while(t--){
        long long n; 
        cin>>n; 

        if(n < 4 || n % 2 != 0){
            cout<<-1<<endl;
        }else{
            cout<<(n+5)/6<< " "<<n/4<<endl;
        }
    }
}