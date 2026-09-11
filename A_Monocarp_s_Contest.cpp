#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }

        if(n == 2 ){
            if(a[0] == 0 && a[1] == 0){
                cout<<"0"<<endl;
            }else{
                cout<<"-1"<<endl;
            }

        }else if(n == 3){
            if(a[0] == 0 && a[1] == 0 && a[2] == 0){
                cout<<"0"<<endl;
            }else if(a[0] == 1 && a[1] == 1 && a[2] == 1){
                cout<<"-1"<<endl;
            }else if(a[0] == 0 && a[1] == 1 && a[2] == 1){
                cout<<"-1"<<endl;
            }else if(a[0] == 1 && a[1] == 0 && a[2] == 1){
                cout<<"-1"<<endl;
            }else if(a[0] == 0 && a[1] == 1 && a[2] == 0){
                cout<<"0"<<endl;
            }else if(a[0] == 1 && a[1] == 1 && a[2] == 0){
                cout<<"-1"<<endl;
            }else{
                cout<<"1"<<endl;
            }
        }else{
             int cnt = 0; 
             for(int i = 0; i < n; i++){
                if(a[i] == 0){
                    cnt++;
                }
             }
             if(cnt >= 2){
                if(a[0] == 0 && a[n-1] == 0){
                    cout<<"0"<<endl;
                }else if(a[0] == 0 && a[n-1] == 1){
                    cout<<"1"<<endl;
                }else if(a[0] == 1 && a[n-1] == 0){
                    cout<<"1"<<endl;
                }else if(a[0] == 1 && a[n-1] == 1){
                    cout<<"2"<<endl;
                }
             }else{
                cout<<"-1"<<endl; 
             }
             
        }
         
        }
        
    }
