// http://codeforces.com/contest/313/problem/D

using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<<#x " = "<<(x)<<endl
#define MP 310

const long long inf = 1LL<<40;
long long c[MP][MP];
long long dp[MP][MP];
int n,m,k;

// Minimo costo de tapar almenos q huecos de i en adelante.

long long solve(int i,int q){
    if(q <= 0) return 0;    
    if(i == n+1) return inf;
    
    if(dp[i][q] != -1) return dp[i][q];

    long long ans = solve(i+1,q); // Decido no tapar el hueco i;
    
    for(int j = i; j <= n; ++j)
        ans = min(ans, solve(j+1, q - j + i-1) + c[i][j] );

    return dp[i][q] = ans;
}

int main(){
    while(cin>>n>>m>>k){
    
        for(int i = 0; i <= n; ++i)
            for(int j = 0; j <= n; ++j)
                c[i][j] = inf;
        
        memset(dp,-1,sizeof dp);
        
        int l,r;
        long long a;
        for(int i = 0; i< m; ++i){
            cin>>l>>r>>a;
            for(int j = l; j<=r ; ++j)
                c[l][j] = min(c[l][j],a);
        }
        
        long long ans =  solve(1,k); 
        cout<<((ans < inf)? ans : -1 )<<endl;
    }

    return 0;
}