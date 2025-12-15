#include<bits/stdc++.h>
using namespace std;

int main() {
    int x;
    
    vector<string>inputs;
    cin >> x;
    for (int i = 0; i < x; i++) {
         string temp="";
         cin>>temp;
         inputs.push_back(temp);
    }
    int res=0;
    for(string str:inputs){
        if(str=="++X" || str=="X++"){
            res++;
    }else{
        res--;
    }
}


    cout << res << endl;
}
