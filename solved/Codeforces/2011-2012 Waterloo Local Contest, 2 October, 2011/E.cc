#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

const int MN = 1234;
const int MC = 30;
const long long inf = 1LL << 60;

long long dp[MC][MN];
long long e[MC][MN];
long long loc[MC][MN];

int c, t, l;

void solve() {
  cin >> c >> t >> l;

  for (int i = 0; i < c; ++i)
    for (int j = 0; j < t; ++j)
      cin >> loc[i][j] >> e[i][j];

  for (int i = 0; i < t; ++i) {
    dp[c - 1][i] = e[c - 1][i] + llabs(l - loc[c - 1][i]);
  }

  for (int i = c - 2; i >= 0; --i) {
    for (int j = 0; j < t; ++j) {
      dp[i][j] = inf;
      for (int k = 0; k < t; ++k) {
        dp[i][j] = min(dp[i][j],
            e[i][j] + llabs(loc[i][j] - loc[i + 1][k]) + dp[i + 1][k]);
      }
    }
  }
  long long best = inf;
  for (int i = 0; i < t; ++i)
    best = min(best, loc[0][i] + dp[0][i]);
  cout << best << endl;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  int tc; cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
