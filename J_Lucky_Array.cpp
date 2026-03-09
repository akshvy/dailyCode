#include<bits/stdc++.h>
using namespace std;
  
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0; i< n; i++){
        cin>>a[i];
    }

    int minVal = *min_element(a.begin(), a.end());

    int count =0;
    for(int i = 0; i< n; i++){
        if(a[i] == minVal){
            count++;
        }
}
   if(count % 2 == 0){
        cout<<"Unlucky"<<endl;
   }
   else{
        cout<<"Lucky"<<endl;
   }

   return 0;
}
