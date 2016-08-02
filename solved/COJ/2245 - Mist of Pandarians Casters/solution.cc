#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define debug(x) cout  << #x << " = " <<endl

int dp[22][22][22][22];

int go(vector<string> &g, int x1, int y1, int x2, int y2) {
  if (x2 - x1 < 0 || y2 - y1 < 0)
    return 0;

  if (dp[x1][y1][x2][y2] != -1)
    return dp[x1][y1][x2][y2];

  vector<int> mex(444);
  for (int i = x1; i <= x2; ++i) {
    for (int j = y1; j <= y2; ++j) {
      int cur = 0;
      if (g[i][j] == '-') {
        cur = go(g, x1, y1, i - 1, y2);
        cur ^= go(g, i + 1, y1, x2, y2);
      } else if (g[i][j] == '|') {
        cur = go(g, x1, y1, x2, j - 1);
        cur ^= go(g, x1, j + 1, x2, y2);
      } else {
        cur = go(g, x1, y1, i - 1, j - 1);
        cur ^= go(g, x1, j + 1, i - 1, y2);
        cur ^= go(g, i + 1, y1, x2, j - 1);
        cur ^= go(g, i + 1, j + 1, x2, y2);
      }
      mex[cur] = 1;
    }
  }

  for (int i = 0; i < mex.size(); ++i)
    if (!mex[i]) {
      // cout << x1 << " " << y1 << " " << x2 << " " << y2 << " : " << i << endl;
      return dp[x1][y1][x2][y2] = i;
    }
  assert(false);
}

int main() {
  int n, m;
  while (cin >> n >> m) {
    vector<string> g(n);
    for (auto &i : g) cin >> i;
    memset(dp, -1, sizeof dp);
    if (go(g, 0, 0, n - 1, m - 1) > 0)
      cout << "WIN" << endl;
    else
      cout << "LOSE" << endl;
  }
  return 0;
}
