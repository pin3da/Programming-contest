#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

const int MN = 111;
int c[MN];
int p[MN][MN];

int n, m, k;

const long long inf = 1LL << 60;

long long dp[MN][MN][MN];
long long go(int i, int l, int r) {
  if (i == n) {
    if (r == 1) return 0;
    return inf;
  }
  if (dp[i][l][r] != -1)
    return dp[i][l][r];

  if (c[i] != 0) return go(i + 1, c[i], r - (c[i] != l));

  long long best = inf;
  for (int j = 1; j <= m; ++j) {
    if (j != l && (i != 0)) {
      long long to = go(i + 1, j, r - 1);
      if (to != inf)
        best = min(best, to + p[i][j]);
    } else {
      long long to = go(i + 1, j, r);
      if (to != inf)
        best = min(best, to + p[i][j]);
    }
  }
  return dp[i][l][r] = best;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  while (cin >> n >> m >> k) {
    for (int i = 0; i < n; ++i)
      cin >> c[i];
    for (int i = 0; i < n; ++i)
      for (int j = 1; j <= m; ++j)
        cin >> p[i][j];


    memset(dp, -1, sizeof dp);
    long long ans = go(0, c[0], k);
    if (ans < inf)
      cout << ans << endl;
    else
      cout << -1 << endl;
  }

  return 0;
}
