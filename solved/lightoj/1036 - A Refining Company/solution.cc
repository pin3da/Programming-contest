using namespace std;
#include <bits/stdc++.h>

const int MN = 555;
int dp[MN][MN];
int go(vector<vector<int> > &a, vector<vector<int> > &b, int i, int j) {
  if (i < 0 || j < 0)
    return 0;

  if (dp[i][j] != -1)
    return dp[i][j];

  return dp[i][j] = max(go(a, b, i - 1, j) + a[i][j], go(a, b, i, j - 1) + b[i][j]);
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int> > a(n, vector<int> (m)), b(n, vector<int> (m));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
      if (j)
        a[i][j] += a[i][j - 1];
    }

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      cin >> b[i][j];
      if (i)
        b[i][j] += b[i - 1][j];
    }

  memset(dp, -1, sizeof dp);
  printf("%d\n", go(a, b, n - 1, m - 1));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}
