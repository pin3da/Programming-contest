using namespace std;
#include <bits/stdc++.h>

int n;
int g[15][15];
int dp[(1 << 15) + 1];

int go(int mask) {
  if (mask == (1 << n) - 1)
    return 0;

  if (dp[mask] != -1)
    return dp[mask];

  int best = 1 << 30;
  for (int i = 0; i < n; ++i) {
    if (((mask >> i) & 1) == 0) {
      int nmask = mask | (1 << i);
      if (go(nmask) < (1 << 30)) {
        int tot = 0;
        for (int k = 0; k < n; ++k)
          if ((nmask >> k) & 1)
            tot += g[i][k];
        best = min(best, go(nmask) + tot);
      }
    }
  }
  return dp[mask] =  best;
}

void solve() {
  cin >> n;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      cin >> g[i][j];

  memset(dp, -1, sizeof dp);

  printf("%d\n", go(0));
}

int main() {
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}
