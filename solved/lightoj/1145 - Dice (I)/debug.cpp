using namespace std;
#include<bits/stdc++.h>
#define D(x) cout<< #x " = "<<(x)<<endl


const int MN  = 15050;
const int mod = 100000007;
int N,S,K;
long long dp[10001][MN];
long long t[10001][MN];

long long go(int i, int s) {
  if (s < 0) return 0;
  if (i == N) return s == 0;

  if (t[i][s] != -1) return t[i][s];
  long long ans = 0;
  for (int k = 1; k <= K; ++k) {
    ans = (ans + go(i+1, s -k)) % mod;
  }
  return t[i][s] = ans;
}


void solve() {
  cin>>N>>K>>S;


  memset(dp, 0, sizeof dp);
  memset(t, -1, sizeof t);

  dp[N][0] = 1;

  for (int i = N - 1; i >= 0; --i) {
    for (int j = 1; j <= S; ++j) {
#ifdef B
      long long tmp = 0;
      for (int k = 1; k <= K; ++k) {
        if (j - k >= 0)
          tmp = (tmp + dp[i + 1][j - k]) % mod;
      }
      dp[i][j] = tmp;
#else
      long long tmp = dp[i + 1][j - 1];
      if (j - K >= 0)
        tmp -= dp[i + 1][j - K - 1];
      dp[i][j] = tmp;
      if (j)
        dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
#endif
    }
  }

#ifdef B
  cout<<go(0, S)<<endl;
#endif
  long long ans = dp[0][S];
  while (ans < 0) ans += mod;
  cout<<(ans)%mod<<endl;

}

int main() {

  int t;cin>>t;
  for (int i = 0; i < t; ++i) {
    cout<<"Case "<<(i+1)<<": ";
    solve();
  }
  return 0;
}
