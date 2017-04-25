// http://codeforces.com/contest/766/problem/E

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
  vector<long long> total(2);
  for (int to : g[node])
    for (int j = 0; j < 2; ++j)
      total[j] += go(g, val, to, j, k);

  for (int to : g[node]) {
    if (!cur) {
      ways += go(g, val, to, 1, k) * (total[0] - go(g, val, to, 0, k));
      ways += go(g, val, to, 0, k) * (total[1] - go(g, val, to, 1, k));
    } else {
      ways += go(g, val, to, 1, k) * (total[1] - go(g, val, to, 1, k));
      ways += go(g, val, to, 0, k) * (total[0] - go(g, val, to, 0, k));
    }

  }
  return ways / 2;
}

void direct(vector<vector<int>> &gu, int node, int pi,
    vector<vector<int>> &g) {

  for (int to : gu[node]) {
    if (to != pi) {
      g[node].push_back(to);
      direct(gu, to, node, g);
    }
  }
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  int n; cin >> n;
  vector<vector<int>> gu(n);
  vector<int> val(n);

  for (int &i : val) cin >> i;
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    u--;v--;
    gu[u].emplace_back(v);
    gu[v].emplace_back(u);
  }

  vector<vector<int>> g(n);
  direct(gu, 0, -1, g);

  long long ans = 0;
  for (int k = 0; k < 31; ++k) {
    memset(dp, -1, sizeof dp);
    for (int i = n - 1; i >= 0; --i) {
      ans += (1LL << k) * go(g, val, i, 1, k);
      ans += (1LL << k) * go2(g, val, i, k);
    }
  }
  cout << ans << endl;
  return 0;
}
