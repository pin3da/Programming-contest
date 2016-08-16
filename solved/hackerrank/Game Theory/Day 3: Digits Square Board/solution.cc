#include <bits/stdc++.h>

#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

int non_prime(int x) {
  return x != 2 && x != 3 && x != 5 && x!= 7;
}

int query(vector<vector<int> > &g, int a, int b, int x, int y) {
  return g[x][y] - g[x][b - 1] - g[a - 1][y] + g[a - 1][b - 1];
}

const int MN = 33;
int dp[MN][MN][MN][MN];

int go(vector<vector<int> > &g, int a, int b, int x, int y) {
  if (!query(g, a, b, x, y)) return 0;
  if ((x - a + 1) * (y - b + 1) == 1) return 0;

  if (dp[a][b][x][y] != -1) return dp[a][b][x][y];
  vector<int> mex(40);
  for (int i = a; i < x; ++i) {
    int gn = go(g, a, b, i, y) ^ go(g, i + 1, b, x, y);
    if (gn < 40) mex[gn] = true;
  }

  for (int i = b; i < y; ++i) {
    int gn = go(g, a, b, x, i) ^ go(g, a, i + 1, x, y);
    if (gn < 40) mex[gn] = true;
  }
  for (int i = 0; i < mex.size(); ++i) {
    if (!mex[i]) {
      return dp[a][b][x][y] = i;
    }
  }
  assert(false);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc; cin >> tc;
  while (tc--) {
    int n; cin >> n;
    vector<vector<int> > g(n + 1, vector<int> (n + 1));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        int t; cin >> t;
        g[i + 1][j + 1] = non_prime(t);
        g[i + 1][j + 1] += g[i][j + 1] + g[i + 1][j] - g[i][j];
      }
    }
    memset(dp, -1, sizeof dp);
    int ans = go(g, 1, 1, n, n);
    puts(ans ? "First": "Second");
  }

  return 0;
}
