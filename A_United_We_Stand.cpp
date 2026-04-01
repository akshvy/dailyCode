#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        
        vector<int> b, c;
        int max = *max_element(a.begin(), a.end());



        for(int i = 0; i < n; i++){
            if(a[i] != max){
                b.push_back(a[i]);
            }else{
                c.push_back(a[i]);
            }
        }

        if(b.size() == 0){
            cout << "-1" << endl;
        }else{
            cout<<b.size()<<" "<<c.size()<<endl;
            for (auto it : b)
                cout << it << " ";
            cout << endl;

            for (auto it : c)
                cout << it << " ";
            cout << endl;
        }
        }
        
    
    return 0;
}









