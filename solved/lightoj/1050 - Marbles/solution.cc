using namespace std;
#include <bits/stdc++.h>

const int MN = 555;
double dp[MN][MN][5];

double go(int r, int b, int t) {
  if (dp[r][b][t] > -0.5)
    return dp[r][b][t];

  if (r + b == 1) {
    return dp[r][b][t] = b ? 1 : 0;
  }
  if (!t) {
    double ans = 0;
    if (r > 0)
      ans += go(r - 1, b, t ^ 1) * double(r) / (double) (r + b);
    if (b > 0)
      ans += go(r, b - 1, t ^ 1) * double(b) / (double) (r + b);
    return dp[r][b][t] = ans;
  }
  if (b > 0)
    return go(r, b - 1, t ^ 1);
  return dp[r][b][t] = 0;
}

void solve() {
  int r, b;
  cin >> r >> b;
  printf("%.10lf\n", go(r, b, 0));
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  for (int i = 0; i < MN; ++i) {
    for (int j = 0; j < MN; ++j) {
      dp[i][j][0] = dp[i][j][1] = -1;
    }
  }
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}
