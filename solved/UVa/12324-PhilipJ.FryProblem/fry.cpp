/**
* Manuel Pineda
* Accepted, 0.102
*/
using namespace std;
#include <iostream>
#include <cstring>
#include <algorithm>

int t[110];
int d[110];
int n;
int dp[110][110];

int solve(int trip, int dm){
    if(dm > n) dm = n;
    if(trip == n) return 0;
    if(dp[trip][dm] != -1) return dp[trip][dm];
    int a = t[trip] + solve(trip+1,dm + d[trip]);
    int b = (1<<30);
    if(dm){
        b = (t[trip]>>1) + solve(trip+1,dm + d[trip] -1);
    }
    
    return dp[trip][dm] = min(a,b);
}

int main(){

    while(cin>>n and n){
        for(int i = 0; i< n; ++i)
            cin>>t[i]>>d[i];
        
        memset(dp,-1,sizeof(dp));
        cout<<solve(0,0)<<endl;
    }
    return 0;
}

