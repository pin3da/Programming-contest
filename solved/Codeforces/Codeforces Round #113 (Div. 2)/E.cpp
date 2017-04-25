// http://codeforces.com/contest/166/problem/E

using namespace std;
#include <iostream>
#include <cstring>

typedef long long ll;

int mod = 1e9 + 7;

int dp[4][10000010];


void fill_dp(){
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    for(int i = 1; i <= 10000000; ++i){
        for(int j = 0; j< 4 ; ++j){
            for(int k = 0; k< 4 ; ++k){
                if(j==k)continue;
                dp[j][i] += dp[k][i-1];
                dp[j][i] %= mod;
            }
        }
    }
}

int main(){
    int n;
    fill_dp();
    while(cin>>n){
        cout<<dp[0][n]<<endl;
    }
    return 0;
}