// http://codeforces.com/contest/488/problem/C

using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x << " = " << (x) << endl

const int inf = 1 << 20;
const int MN = 222;

int dp[1001][MN][MN];

int solve(vector<int> &y, vector<int> &m, vector<int> &cost, int h, int a, int d) {

  if (h >= 1001 || a >= MN || d >= MN )
    return inf;

  if (dp[h][a][d] != -1)
    return dp[h][a][d];

  int hh = h + y[0];
  int aa = a + y[1];
  int dd = d + y[2];

  int damage = max(0, m[1] - dd);
  int ans = inf;
  if (damage < hh) {
    int x = ((damage == 0) ? inf : ((hh - 1) / damage));

    if (x * max(0, aa - m[2]) >= m[0])
      return dp[h][a][d] = 0;

    ans = min(ans, cost[1] + solve(y, m, cost, h, a + 1, d));
  }
  ans = min(ans, cost[0] + solve(y, m, cost, h + 1, a, d));
  ans = min(ans, cost[2] + solve(y, m, cost, h, a, d + 1));
  return dp[h][a][d] = ans;
}



int main() {
  vector<int> a(3), b(3), c(3);

  for (int i = 0; i < 3; ++i)
    cin >> a[i];

  for (int i = 0; i < 3; ++i)
    cin >> b[i];

  for (int i = 0; i < 3; ++i)
    cin >> c[i];

  memset(dp, -1, sizeof dp);
  cout << solve(a, b, c, 0, 0, 0) << endl;

  return 0;
}
y - 1) / damy;
  if (h - x * damm <= 0)
    return false;
  return true;
}

int main() {
  vector<int> a(3), b(3), c(3);

  for (int i = 0; i < 3; ++i)
    cin >> a[i];

  for (int i = 0; i < 3; ++i)
    cin >> b[i];

  for (int i = 0; i < 3; ++i)
    cin >> c[i];

  //memset(dp, -1, sizeof dp);
  //cout << solve(a, b, c, 0, 0, 0) << endl;

  int ans = inf;
  for (int i = 0; i < 1001; ++i) {
    for (int j = 0; j < MN; ++j) {
      for (int k = 0; k < MN; ++k) {
        int h  = a[0] + i;
        int at = a[1] + j;
        int de = a[2] + k;
        if (win(h, at, de, b[0], b[1], b[2])) {
          ans = min(ans, i * c[0] + j * c[1] + k * c[2]);
        }
      }
    }
  }

  cout << ans << endl;

  return 0;
}
eturn 0;
}

