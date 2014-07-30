using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<< #x " = "<<(x)<<endl


const int MN  = 15050;
const int mod = 100000007;
int N,S,K;
long long dp[2][MN];

void solve() {
  cin>>N>>K>>S;

  memset(dp, 0, sizeof dp);

  dp[1][0] = 1;

  int i = 0;
  for (int ii = N - 1; ii >= 0; --ii, i ^= 1) {
    dp[i][0] = dp[i][1] = 0;
    for (int j = 1; j <= S; ++j) {

      long long tmp = dp[i ^ 1][j - 1];
      if (j - K >= 0)
        tmp = (tmp - dp[i ^ 1][j - K - 1] + mod) % mod;
      dp[i][j] = tmp;
      if (j)
        dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
    }
  }

  long long ans = dp[i ^ 1][S];
  while (ans < 0) ans += mod;
  cout<<(ans)%mod<<endl;

}

int main() { ___

  int t;cin>>t;
  for (int i = 0; i < t; ++i) {
    cout<<"Case "<<(i+1)<<": ";
    solve();
  }
  return 0;
}
