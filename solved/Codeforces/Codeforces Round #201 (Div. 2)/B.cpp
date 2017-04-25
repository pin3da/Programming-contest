// http://codeforces.com/contest/347/problem/B

using namespace std;
#include<bits/stdc++.h>


int main(){
    
    int n;
    while(cin>>n){
        vector<int> g(n);
        for(int i = 0; i< n; ++i)
            cin>>g[i];
        
        int ans = 0;
        int posible = 1;
        for(int i = 0; i< n; ++i){
            if(g[i]==i) ans++;
            else{
                if(g[g[i]] == i)posible = 2;
            }
        }
        if(ans==n)posible = 0;
        cout<<ans+posible<<endl;
    
    }
    
    
    return 0;
}