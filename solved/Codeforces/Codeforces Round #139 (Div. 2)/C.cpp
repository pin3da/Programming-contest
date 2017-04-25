// http://codeforces.com/contest/225/problem/C

using namespace std;
#include <bits/stdc++.h>

#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

const long long inf = 1LL << 55;

int x, y;

long long dp[1111][1111][3];

long long go(vector<vector<long long>> &cost, int i, int c, int t) {
  if (i == cost[0].size()) {
    if (c >= x && c <= y)
      return 0;
    return inf;
  }

  if (dp[i][c][t] != -1)
    return dp[i][c][t];

  long long best = inf, d;
  if (c < x) {
    d = go(cost, i + 1, c + 1, t);
    if (d < inf)
      best = min(best, d + cost[t][i]);
  } else {
    d = go(cost, i + 1, 1, t ^ 1);
    if (d < inf)
      best = min(best, d + cost[t ^ 1][i]);
    if (c < y) {
      d = go(cost, i + 1, c + 1, t);
      if (d < inf)
        best = min(best, d + cost[t][i]);
    }
  }
  return dp[i][c][t] = best;
}

void solve(int n, int m) {
  vector<vector<char>> g(n, vector<char>(m));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      cin >> g[i][j];


  vector<vector<long long>> c(2, vector<long long>(m, 0));
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      c[0][i] += (g[j][i] != '.');
      c[1][i] += (g[j][i] != '#');
    }
  }
  memset(dp, -1, sizeof dp);
  cout << min(go(c, 0, 0, 0), go(c, 0, 0, 1)) << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m;
  while (cin >> n >> m >> x >> y) {
    solve(n, m);
  }
  return 0;
}
