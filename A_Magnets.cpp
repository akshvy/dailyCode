#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    if (n==1){
        cout<<1<<endl;
        return 0;
    }
    
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int count=0;
    for(int i=0;i<n;i++){
        if(a[i] != a[i+1]){
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}