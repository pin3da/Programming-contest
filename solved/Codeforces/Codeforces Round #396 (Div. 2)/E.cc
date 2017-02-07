#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

const int MN = 1e5 + 100;

long long dp[MN][3];

long long go(vector<vector<int>> &g, vector<int> &val,
    int node, int x, const int &k) {

  if (dp[node][x] != -1)
    return dp[node][x];

  int cur = (val[node] >> k) & 1;
  long long ways = (cur == x);

  for (int to : g[node])
    ways += go(g, val, to, x ^ cur, k);

  return dp[node][x] = ways;
}

long long go2(vector<vector<int>> &g, vector<int> &val,
    int node, const int &k) {

  int cur = (val[node] >> k) & 1;
  long long ways = 0;
  for (int i = 0; i < (int)g[node].size(); ++i) {
    for (int j = i + 1; j < (int)g[node].size(); ++j) {
      int a = g[node][i], b = g[node][j];
      if (!cur) {
        ways += go(g, val, a, 1, k) * go(g, val, b, 0, k);
        ways += go(g, val, a, 0, k) * go(g, val, b, 1, k);
      } else {
        ways += go(g, val, a, 1, k) * go(g, val, b, 1, k);
        ways += go(g, val, a, 0, k) * go(g, val, b, 0, k);
      }
    }
  }
  return ways;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  int n; cin >> n;
  vector<vector<int>> g(n);
  vector<int> val(n);

  for (int &i : val) cin >> i;
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    u--;v--;
    if (u > v) swap(u, v);
    g[u].emplace_back(v);
  }

  long long ans = 0;
  for (int k = 0; k < 31; ++k) {
    memset(dp, -1, sizeof dp);
    for (int i = n - 1; i >= 0; --i) {
      ans += (1LL << k) * go(g, val, i, 1, k);
      if (g[i].size() >= 2)
        ans += (1LL << k) * go2(g, val, i, k);
    }
  }
  cout << ans << endl;
  return 0;
}
