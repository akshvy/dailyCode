#include<bits/stdc++.h>
using namespace std;
int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }
        int count1 = 0, count2 = 0;

        for(int i = 0; i < n; i++){
            if(arr[i] == 1){
                count1++;
            } else {
                count2++;
            }
        }
        if(count2%2 != 0){
            cout<<-1<<endl;
        }else if(count1 == n-1){
            cout<<1<<endl;
        }else{

        int target = count2/2;
        int sum = 0;
        for(int i = 0; i < n; i++){
            if(arr[i] == 2){
                sum++;
    }
            if(sum == target){
                cout<<i+1<<endl;
                break;
            }
        }
    }
}
    return 0;

}



