// http://codeforces.com/contest/71/problem/B

using namespace std;
#include<bits/stdc++.h>
#define D(x) cout<<#x " = "<<(x)<<endl
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){ ___
    int n,k,t;
    
    while(cin>>n>>k>>t){
        vector<int> todos(n);
        int fill = floor(t*n/100.0);
        int y = floor((((t*n)/100.0) - fill )*(double)k);
        for(int i =0 ; i< fill; ++i)
            cout<<k<<" ";
        
        if(fill < n) cout<<y<<" ";
        
        for(int i = 0; i< n - fill - 1; ++i)
            cout<<"0 ";
            
        cout<<endl;
        
            
    }

    return 0;
}
