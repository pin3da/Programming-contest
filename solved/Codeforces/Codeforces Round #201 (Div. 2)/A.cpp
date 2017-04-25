// http://codeforces.com/contest/347/problem/A

using namespace std;
#include<bits/stdc++.h>


int main(){
    
    int n;
    while(cin>>n){
        vector<int> g(n);
        for(int i = 0; i< n; ++i)
            cin>>g[i];
        
        sort(g.begin(),g.end());
        cout<<g[n-1]<<" ";
        for(int i = 1; i < n-1; ++i)
            cout<<g[i]<<" ";
        cout<<g[0]<<endl;
    }
    
    
    return 0;
}