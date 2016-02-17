#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

const int MN = 101;
int dp[MN][MN][MN];

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n && n) {
    vector<vector<int>> a(n + 1, vector<int> (3));
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < 3; ++j)
        cin >> a[i + 1][j];

    memset(dp, 0, sizeof dp);
    dp[0][0][0] = 1;
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j <= n; ++j) {
        for (int k = 0; k <= n; ++k) {
          if (i > 0 && (a[i][0] % 3) == 0)
            dp[i][j][k] |= dp[i - 1][j][k];

          if (j > 0 && (a[j][1] % 3) == 0)
            dp[i][j][k] |= dp[i][j - 1][k];

          if (k > 0 && (a[k][2] % 3) == 0)
            dp[i][j][k] |= dp[i][j][k - 1];

          if (i > 0  && j > 0 && ((a[i][0] + a[j][1]) % 3) == 0)
            dp[i][j][k] |= dp[i - 1][j - 1][k];

          if (i > 0  && k > 0 && ((a[i][0] + a[k][2]) % 3) == 0)
            dp[i][j][k] |= dp[i - 1][j][k - 1];

          if (j > 0  && k > 0 && ((a[j][1] + a[k][2]) % 3) == 0)
            dp[i][j][k] |= dp[i][j - 1][k - 1];

          if (i > 0 && j > 0 && k > 0 && ((a[i][0] + a[j][1] + a[k][2]) % 3) == 0)
            dp[i][j][k] |= dp[i - 1][j - 1][k - 1];
        }
      }
    }

    cout << dp[n][n][n] << endl;
  }
  return 0;
}
