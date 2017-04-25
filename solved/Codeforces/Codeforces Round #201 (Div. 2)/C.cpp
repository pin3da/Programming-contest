// http://codeforces.com/contest/347/problem/C

using namespace std;
#include<bits/stdc++.h>


int main(){
    
    int n;
    while(cin>>n){
        vector<int> g(n);
        for(int i = 0; i< n; ++i)
            cin>>g[i];
        
        sort(g.begin(),g.end());
        int mayor = g[n-1];
        int mio = g[0];
        for(int i = 0; i< n; ++i)
            mio = __gcd(mio,g[i]);
         
        if(mio == 1){
            int tmp = mayor - n;
            if(tmp%2)cout<<"Alice"<<endl;
            else cout<<"Bob"<<endl;
        }else{
            int tmp = (mayor/mio) - n;
            if(tmp%2) cout<<"Alice"<<endl;
            else cout<<"Bob"<<endl;
        }
    }
    
    
    return 0;
}