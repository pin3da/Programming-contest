#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

const int MN = 1001;
int n, m;
long long dp[MN][MN][4];
long long a[MN][MN];

const long long inf = 1LL << 60;

long long go1(int i, int j) {
  if (i == 0 && j == 0) return a[i][j];
  if (dp[i][j][0] != -1) return dp[i][j][0];
  long long best = 0;
  if (i) best = go1(i - 1, j) + a[i][j];
  if (j) best = max(best, go1(i, j - 1) + a[i][j]);
  return dp[i][j][0] = best;
}

long long go2(int i, int j) {
  if (i >= n || j >= m) return -inf;
  if (i == (n - 1) && j == (m - 1)) return a[i][j];
  if (dp[i][j][1] != -1) return dp[i][j][1];
  long long best = 0;
  if (i + 1 < n) best = go2(i + 1, j) + a[i][j];
  if (j + 1 < m) best = max(best, go2(i, j + 1) + a[i][j]);
  return dp[i][j][1] = best;
}

long long go3(int i, int j) {
  if (j >= m) return -inf;
  if (i == 0 && j == (m - 1)) return a[i][j];
  if (dp[i][j][2] != -1) return dp[i][j][2];
  long long best = 0;
  if (i) best = go3(i - 1, j) + a[i][j];
  if (j + 1 < m) best = max(best, go3(i, j + 1) + a[i][j]);
  return dp[i][j][2] = best;
}

long long go4(int i, int j) {
  if (i == (n - 1) && j == 0) return a[i][j];
  if (dp[i][j][3] != -1) return dp[i][j][3];
  long long best = 0;
  if (i + 1 < n) best = go4(i + 1, j) + a[i][j];
  if (j) best = max(best, go4(i, j - 1) + a[i][j]);
  return dp[i][j][3] = best;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  while (cin >> n >> m) {
    memset(dp, -1, sizeof dp);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        cin >> a[i][j];

    long long best = 0;
    for (int i = 1; i + 1 < n; ++i) {
      for (int j = 1; j + 1 < m; ++j) {
        long long tmp = go1(i, j - 1) + go2(i, j + 1)
          + go3(i - 1, j) + go4(i + 1, j);
        tmp = max(tmp, go1(i - 1, j) + go2(i + 1, j)
            + go3(i, j + 1) + go4(i, j - 1));
        best = max(best, tmp);
      }
    }
    cout << best << endl;
  }
  return 0;
}
