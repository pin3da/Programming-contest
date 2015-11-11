#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x " = " << (x) << endl

vector<vector<int> > dp;

long long go(vector<vector<int> > &g, int x, int y, int t) {
  if (x >= g.size())
    return 0;

  if (y >= g[x].size()) {
    if (t)
      return go(g, x + 2, 0, 0);
    else
      return go(g, x + 1, 0, 0);
  }

  if (dp[x][y] != -1)
    return dp[x][y];

  long long best = go(g, x, y + 2, 1) + g[x][y];
  best = max(best, go(g, x, y + 1, t));
  if (!t) {
    best = max(best, go(g, x + 1, 0, 0));
  }
  return dp[x][y] = best;
}

void solve(int n, int m) {
  vector<vector<int> > g(n, vector<int> (m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> g[i][j];
    }
  }
  dp = vector<vector<int> > (n, vector<int> (m, -1));
  cout << go(g, 0, 0, 0) << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m;
  while (cin >> n >> m && (n + m)) {
    solve(n, m);
  }
  return 0;
}
