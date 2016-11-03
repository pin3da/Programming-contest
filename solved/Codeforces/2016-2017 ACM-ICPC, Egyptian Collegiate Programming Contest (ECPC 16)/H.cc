#include <bits/stdc++.h>

using namespace std;
#define debug(x) cout << #x " = " << (x) << endl

const int MN = 11;
int dp[MN][MN][MN];
int p[MN][MN][MN];

void solve() {
  int n; cin >> n;
  memset(p, 0, sizeof p);
  memset(dp, 0, sizeof dp);
  for (int i = 0; i < n; ++i) {
    int x, y, z;
    cin >> x >> y >> z;
    x--;y--;z--;
    int h; cin >> h;
    p[x][y][z] += h;
  }

  for (int i = 0; i < MN; ++i) {
    for (int j = MN - 1; j >= 0; --j) {
      for (int k = MN - 1; k >= 0; --k) {
        dp[i][j][k] = p[i][j][k];
        int extra = 0;
        if (k + 1 < MN)
          extra = max(extra, dp[i][j][k + 1]);
        if (j + 1 < MN)
          extra = max(extra, dp[i][j + 1][k]);
        if (i > 0)
          extra = max(extra, dp[i - 1][j][k]);
        dp[i][j][k] += extra;
      }
    }
  }
  cout << dp[9][0][0] << endl;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  freopen("commandos.in", "r", stdin);
#endif

  int t; cin >> t;
  while (t--) solve();
  return 0;
}
