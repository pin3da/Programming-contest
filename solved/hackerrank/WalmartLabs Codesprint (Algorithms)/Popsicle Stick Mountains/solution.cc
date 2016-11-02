#include <bits/stdc++.h>

using namespace std;
#define debug(x) cout << #x << " = " << (x) << endl

const long long mod = 1e9 + 7;

const int MN = 4001;
long long dp[MN][MN / 2 + 1];

long long go(int stick, int level) {
  if (stick == 0) {
    return level == 0;
  }

  if (level > stick) return 0;

  if (dp[stick][level] != -1) return dp[stick][level];

  long long ans = go(stick - 1, level + 1);
  if (level > 0)
    ans = (ans + go(stick - 1, level - 1)) % mod;
  if (level == 0) ans = (ans + 1) % mod;
  return dp[stick][level] = ans;
}

int main() {
#ifdef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int t; cin >> t;
  memset(dp, -1, sizeof dp);
  while (t--) {
    int n; cin >> n;
    cout << (go(n, 0) -1 + mod) % mod << endl;
  }
  return 0;
}
