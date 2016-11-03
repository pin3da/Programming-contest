#include <bits/stdc++.h>

using namespace std;
#define debug(x) cout << #x " = " << (x) << endl

const int MN = 22;
long long dp[MN][MN];

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  freopen("popcorn.in", "r", stdin);
#endif

  dp[0][0] = 1;
  for (int i = 1; i < MN; ++i) {
    for (int j = 0; j <= i; ++j) {
      if ((j == 0) || (j == i))
        dp[i][j] = 1;
      else
        dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
    }
  }

  int t;
  cin >> t;
  while (t--) {
    int n, m; cin >> n >> m;
    cout << dp[n][m] << endl;
  }
  return 0;
}
