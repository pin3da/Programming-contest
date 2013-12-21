/**
* Manuel Pineda - UTP
*/
using namespace std;
#include <iostream>
#include <algorithm>
#include <cstring>

int n, duration[20];
int dp[1<<20][7];


int solve(){
    for (int i = 0 ; i<7 ; i++)
        dp[0][i] = 0;
        
    for (int bm = 1 ; bm < (1 << n) ; bm++) {
        for (int rem = 0 ; rem < 7 ; rem++) {
            dp[bm][rem] = (1<<30);
            for (int i=0 ; i < n ; i++) if (bm & (1 <<i)) {
                int newL = max(rem+1, duration[i]);
                dp[bm][rem] = min(dp[bm][rem], newL - rem + dp[bm ^ (1 << i)][newL - rem - 1]);
            }
        }
    }
    return dp[(1<<n)-1][0];
    
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int k;cin>>k;
    while(k--){
        cin>>n;
        for(int i=0;i<n;i++) cin >> duration[i];
        memset(dp,-1,sizeof(dp));
        cout<<solve()<<endl;
    }
    return 0;
}

