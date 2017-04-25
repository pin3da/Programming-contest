// http://codeforces.com/contest/118/problem/D

using namespace std;
#include <iostream>
#include <cstring>
#define D(x) cout<< #x " = "<<(x)<<endl

typedef long long ll;

int n1,n2,k1,k2;
const ll mod = 1e8;
ll dp[101][101][11][11];

ll solve(int a,int b, int c, int d){
    ll ans = 0;
    if(dp[a][b][c][d] != -1)return dp[a][b][c][d];
    if(a == 0 and b== 0) return 1;
    if(a > 0 and c > 0) ans+= solve(a-1,b,c-1,k2);
    if(b > 0 and d > 0) ans+= solve(a,b-1,k1,d-1);
    ans%= mod;
    return dp[a][b][c][d] = ans;
}

int main(){
    while(cin>>n1>>n2>>k1>>k2){
        memset(dp,-1,sizeof(dp));
        cout<<solve(n1,n2,k1,k2)<<endl;
    }
    return 0;
}