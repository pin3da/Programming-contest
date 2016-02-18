#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

typedef long double dt;

const dt eps = 1e-9;
int D;
dt win[4][4][4];
dt d[6];
dt dp[101][101];
dt go(int n, int m) {

  if (dp[n][m] > -0.5)
    return dp[n][m];

  if (m == 0)
    return dp[n][m] = 1.0;
  if (n == 1)
    return dp[n][m] = 0.0;

  int a = min(3, n - 1);
  int b = min(2, m);

  dt ans = 0;
  if (b == 1) {
    ans += go(n, m - 1) * win[a][1][1];
    ans += go(n - 1, m) * win[a][1][0];
  } else {
    int bet = min(a, 2);
    dt options = 0;
    for (int i = 0; i <= bet; ++i) {
      ans += go(n - i, m - bet + i) * win[a][2][bet - i];
      options += win[a][2][bet - i];
    }
    assert(fabs(1 - options) < eps);
  }
  return dp[n][m] = ans;
}

void solve() {
  int n, m;
  cin >> D >> m >> n;
  d[0] = 1.0;
  for (int i = 1; i < 6; ++i) {
    d[i] = d[i - 1] * D;
  }

  memset(win, 0, sizeof win);
  for (int i = 0; i < 101; ++i)
    for (int j = 0; j < 101; ++j)
      dp[i][j] = -1;

  for (int i = 1; i <= D; ++i) {
    for (int j = 1; j <= D; ++j) {
      if (i > j) win[1][1][1] += 1.0 / d[2];
      else       win[1][1][0] += 1.0 / d[2];

      for (int k = 1; k <= D; ++k) {
        if (max(i, j) > k) win[2][1][1] += 1.0 / d[3];
        else               win[2][1][0] += 1.0 / d[3];

        if (i > max(j, k)) win[1][2][1] += 1.0 / d[3];
        else               win[1][2][0] += 1.0 / d[3];

        // 2 vs 2
        vector<int> tmp({i, j});
        sort(tmp.begin(), tmp.end());
        if ((k < tmp[1] && tmp[1] <= (D + 1) / 2)
            || (k >= tmp[1] && tmp[0] <= (D + 1) / 2)) {

          for (int ll = 1; ll <= D; ++ll) {
            if (max(i, j) > max(k, ll)) {
              if (min(i, j) > min(k, ll)) win[2][2][2] += 1.0 / d[4];
              else                        win[2][2][1] += 1.0 / d[4];
            } else {
              if (min(i, j) > min(k, ll)) win[2][2][1] += 1.0 / d[4];
              else                        win[2][2][0] += 1.0 / d[4];
            }
          }
        } else {
          if (max(i, j) > k) win[2][2][1] += 1.0 / d[3];
          else               win[2][2][0] += 1.0 / d[3];
        }

        for (int ll = 1; ll <= D; ++ll) {
          int a = max(max(i, j), k);
          if (a > ll) win[3][1][1] += 1.0 / d[4];
          else        win[3][1][0] += 1.0 / d[4];


          vector<int> tmp({i, j, k});
          sort(tmp.begin(), tmp.end());
          if (  (ll < tmp[2] && tmp[2] <= (D + 1) / 2)
              ||(ll >= tmp[2] && tmp[1] <= (D + 1) / 2)) {

            for (int m = 1; m <= D; ++m) {
              if (tmp[2] > max(ll, m)) {
                if (tmp[1] > min(ll, m)) win[3][2][2] += 1.0 / d[5];
                else                     win[3][2][1] += 1.0 / d[5];
              } else {
                if (tmp[1] > min(ll, m)) win[3][2][1] += 1.0 / d[5];
                else                     win[3][2][0] += 1.0 / d[5];
              }
            }
          } else {
            if (tmp[2] > ll) win[3][2][1] += 1.0 / d[4];
            else             win[3][2][0] += 1.0 / d[4];
          }
        }
      }
    }
  }


  assert(fabs(1 - (win[3][2][0] + win[3][2][1] + win[3][2][2])) < eps);
  assert(fabs(1 - (win[2][2][0] + win[2][2][1] + win[2][2][2])) < eps);
  assert(fabs(1 - (win[1][2][0] + win[1][2][1] + win[1][2][2])) < eps);
  assert(win[1][2][2] < eps);
  assert(win[2][1][2] < eps);
  assert(win[3][1][2] < eps);
  assert(win[1][3][2] < eps);
  assert(fabs(1 - (win[3][1][0] + win[3][1][1] + win[3][1][2])) < eps);
  assert(fabs(1 - (win[2][1][0] + win[2][1][1] + win[2][1][2])) < eps);
  assert(fabs(1 - (win[1][1][0] + win[1][1][1] + win[1][1][2])) < eps);

  debug(win[1][1][1]);
  debug(win[1][1][0]);
  cout << fixed << setprecision(9) << go(m, n) << endl;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int tc; cin >> tc;
  while (tc--) {
    solve();
  }

  return 0;
}
