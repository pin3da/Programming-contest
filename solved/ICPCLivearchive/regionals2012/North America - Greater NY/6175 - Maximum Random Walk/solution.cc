using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

typedef long double dp_t;

dp_t L, R;

/*
dp_t go(int n, int r, int x) {
  if (n == 0)
    return r;

  dp_t ans = go(n - 1, max(x + 1, r), x + 1) * R;
  ans += go(n - 1, r, x - 1) * L;
  ans += go(n - 1, r, x) * (1 - L - R);
  return ans;
}
*/

const int MN = 2000 + 20;
dp_t dp[3][MN][MN];

void solve() {
  int n;
  cin >> n;
  cin >> L >> R;

  int t = 0;
  for (int i = 0; i < MN; ++i)
    for (int j = 0; j < MN; ++j)
      dp[t][i][j] = max(i - n, 0);


  int top = n << 1 | 1;
  for (int k = n; k >= 0; --k) {
    t ^= 1;
    for (int i = 0; i < top; ++i) {
      for (int j = 1; j < top; ++j) {
        dp[t][i][j] = R * dp[t ^ 1][max(i, j + 1)][j + 1] +
                      L * dp[t ^ 1][i][j - 1] +
                      (1.0 - R - L) * dp[t ^ 1][i][j];

      }
    }
  }

  t ^= 1;
  cout << fixed << setprecision(4) << dp[t][n][n] << endl;

}


int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    int id;
    cin >> id;
    cout << id << " ";
    solve();
  }
  return 0;
}
