using namespace std;
#include<bits/stdc++.h>

const int MN = 55;
int A[MN];
int C[MN];

const long long mod = 100000007;

int n, k;

void solve() {
  cin>>n>>k;
  for (int i = 0; i < n; ++i)
    cin>>A[i];
  for (int i = 0; i < n; ++i)
    cin>>C[i];

  long long dp[n + 1][k + 1];
  memset(dp, 0, sizeof dp);
  dp[n][k] = 1;

  for (int i = n - 1; i >= 0; --i) {
    for (int cur = 0; cur <= k; ++cur) {
      int acum = 0;
      for (int j = 0; j <= C[i]; ++j) {
        if (cur + acum <= k)
          dp[i][cur] = (dp[i][cur] + dp[i + 1][cur + acum] ) % mod;
        acum += A[i];
      }
    }
  }

  cout<<dp[0][0]<<endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc;
  cin>>tc;
  for (int i = 0; i < tc; ++i) {
    cout<<"Case "<<(i+1)<<": ";
    solve();
  }
  return 0;
}
