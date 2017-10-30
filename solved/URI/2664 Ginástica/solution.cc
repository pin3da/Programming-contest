#include <bits/stdc++.h>

using namespace std;

long long mod = 100000LL * 10000LL + 7;

long long add(long long x, long long y) {
  x += y;
  if (x < mod) return x;
  return x % mod;
}

long long dp[55][100123];

long long go(int delta, int n, int d) {
  if (n == 0) {
    return d >= 0 && d <= delta;
  }
  if (d < 0 || d > delta) return 0;
  if (dp[n][d] != -1) return dp[n][d];
  long long ans = go(delta, n - 1, d - 1);
  return dp[n][d] = add(ans, go(delta, n - 1, d + 1));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t, n, m;
  cin >> t >> n >> m;
  int delta = m - n;

  long long ans = 0;
  memset(dp, -1, sizeof dp);
  for (int i = 0; i <= delta; i++) {
    ans = add(ans, go(delta, t - 1, i));
  }
  cout << ans << endl;

  return 0;
}
