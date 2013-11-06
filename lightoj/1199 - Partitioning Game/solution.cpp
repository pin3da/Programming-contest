using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define MP 10001

int g[MP];
int a[MP];


void precompute(){
    memset(g,0,sizeof g);
    
    for(int i = 3; i < MP; ++i){
        memset(a,0,sizeof a);
        
        for(int b = 1, c = i-1 ; b < c; ++b, --c)
            a[g[b] ^ g[c]] = true;
        
        int j = 0;
        while(a[j])++j;
        g[i] = j;
    }
}

string solve(){
    int n;cin>>n;
    int nim = 0;
    while(n--){
        int t;cin>>t;
        nim ^= g[t];
    }
    
    return (nim)?"Alice":"Bob";
    
}

int main(){ ___

    precompute();
    
    int tc;cin>>tc;
    for(int i = 0; i < tc; ++i)
        cout<<"Case "<<(i+1)<<": "<<solve()<<endl;

    return 0;
}
