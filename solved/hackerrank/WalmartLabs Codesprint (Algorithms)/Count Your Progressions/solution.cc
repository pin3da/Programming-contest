#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x << " = " << (x) << endl

const int MN = 212345;
int a[MN];
int nxt[MN][101];
const long long mod = 1e9 + 9;

int n;

map<int, long long> dp[123][3];

long long go(int i, int ant, int t, int d) {
  if (i == n) return t > 1;

  if (dp[ant][t].count(i)) return dp[ant][t][i];
  long long ans = go(nxt[i][ant + d], ant, t, d);

  if (a[i] + d < 101 && a[i] + d >= 0)
    ans = (ans + go(nxt[i][a[i] + d], a[i], min(2, t + 1), d)) % mod;
  return dp[ant][t][i] = ans;
}

int main() {
#ifdef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> a[i];

  for (int i = 0; i < 101; ++i)
    nxt[n - 1][i] = n;

  for (int i = n - 2; i >= 0; --i) {
    for (int j = 0; j < 101; ++j)
      nxt[i][j] = nxt[i + 1][j];
    nxt[i][a[i + 1]] = i + 1;
  }

  long long ans = 0;
  for (int d = -100; d <= 100; ++d) {
    for (int i = 0; i < 101; ++i)
      for (int j = 0; j < 3; ++j)
        dp[i][j].clear();

    for (int i = 0; i < n; ++i) {
      if (a[i] + d < 101 && a[i] + d >= 0)
        ans = (ans + go(nxt[i][a[i] + d], a[i], 1, d)) % mod;
    }
  }
  cout << (ans + n + 1) % mod << endl;

  return 0;
}
