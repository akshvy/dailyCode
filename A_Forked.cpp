#include<bits/stdc++.h>
using namespace std; 
 
    int dy[4]{1, -1, -1, 1}, dx[4]{1, 1, -1, -1};

int main(){
      
    int t; 
    cin>>t;
    while(t--){
        int a, b;
        cin>>a>>b;
        int xk , yk; 
        cin>>xk>>yk;
        int qk, qy; 
        cin>>qk>>qy;

        set<pair<int , int>> khit, qhit;

        for(int i = 0; i < 4; i++){
            khit.insert({xk + dx[i]*a, yk + dy[i]*b});
            khit.insert({xk + dx[i]*b, yk + dy[i]*a});

            qhit.insert({qk + dx[i]*a, qy + dy[i]*b});
            qhit.insert({qk + dx[i]*b, qy + dy[i]*a});
        }
        int cnt = 0;

        for(auto position : khit){
            if(qhit.find(position) != qhit.end() )
            cnt++;
        }
        cout<<cnt<<endl;
        }
        
    }
