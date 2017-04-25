// http://codeforces.com/contest/9/problem/D

using namespace std;
#include <bits/stdc++.h>
#define D(x) cout<< #x " = "<<(x)<<endl

long long dp[36][36];

long long solve(int n,int h){
    if(dp[n][h] != -1) return dp[n][h];
    if(n == 0 and h == 0 ) return dp[n][h] = 1;
    if(n == 0) return dp[n][h] = 0;
    if(h == 0) return dp[n][h] = 0;
    
    long long ans = 0;
    for(int i = 0; i < n; ++i){
        long long t = 0;
        for(int j = 0; j < h; ++j)
            t += solve(n-i-1,j);
        long long t2 = 0;
        for(int j = 0; j < h -1; ++j)
            t2 += solve(i,j);
        ans += t*solve(i,h-1) + t2*solve(n-i-1,h-1);
    }
    return dp[n][h] = ans;
}

int main(){
    int n,h;
    while(cin>>n>>h){
        long long ans = 0;
        memset(dp, -1, sizeof dp);
        for(int i = h; i <= n; ++i)
            ans +=  solve(n,i);
        cout<<ans<<endl;
    }
    return 0;
}
