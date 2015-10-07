using namespace std;
#include <bits/stdc++.h>

const int MN = 51;
long long dp[MN][MN][MN];

long long go(int i, int k, int m) {
  if (k < 0 || i < 0)
    return 0;

  if (i == 0)
    return k == 0;

  if (dp[i][k][m] != -1)
    return dp[i][k][m];

  long long ans = 0;
  for (int j = 1; j <= m; ++j) {
    ans += go(i - j, k - 1, m);
  }

  return dp[i][k][m] = ans;
}

void solve() {
  int n, k, m;
  cin >> n >> k >> m;

  long long ans = go(n, k, m);
  printf("%lld\n", ans);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc; cin >> tc;
  memset(dp, - 1, sizeof dp);
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}
