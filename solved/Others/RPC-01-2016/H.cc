#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

typedef long double dt;

const dt eps = 1e-9;
int D;
dt win[22][22][4];
dt d[6];
dt dp[101][101];
dt win1[22];
dt win2[22];

dt go(int n, int m) {

  if (dp[n][m] > -0.5)
    return dp[n][m];

  if (m == 0)
    return dp[n][m] = 1.0;
  if (n == 1)
    return dp[n][m] = 0.0;

  int a = min(3, n - 1);

  dt ans = 0;
  if (a == 1) {
    for (int i = 1; i <= D; ++i) {
      if (m == 1)
        ans += (1.0 / d[1]) * (go(n, m - 1) * win1[i] + go(n - 1, m) * (1 - win1[i]));
      else
        ans += (1.0 / d[1]) * (go(n, m - 1) * win2[i] + go(n - 1, m) * (1 - win2[i]));
    }
  } else {
    for (int i = 1; i <= D; ++i) {
      for (int j = 1; j <= i; ++j) {
        dt prob;
        if (a == 2) {
          if (i == j) prob = 1.0 / d[2];
          else        prob = 2.0 / d[2];
        } else {
          if (i == j) {
            dt t = 3 * (i - 1) + 1;
            prob = t / d[3];
          } else {
            dt t = 6 * (j - 1) + 3;
            prob = t / d[3];
          }
        }

        double op1 = go(n, m - 1) * win1[i] + go(n - 1, m) * (1 - win1[i]);
        if (m > 1) {
          double op2 = 0;
          for (int bet = 0; bet <= 2; ++bet)
            op2 += go(n - bet, m - 2 + bet) * win[i][j][2 - bet];
          op1 = min(op1, op2);
        }
        ans += op1 * prob;
      }
    }
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

  for (int i = 1; i <= D; ++i)
    for (int j = 1; j <= i; ++j)
      for (int k = 1; k <= D; ++k)
        for (int q = 1; q <= D; ++q) {
          int best = i > max(q, k);
          int second = j > min(q, k);
          if (best && second)
            win[i][j][2] += 1.0 / d[2];
          else if (best || second)
            win[i][j][1] += 1.0 / d[2];
          else
            win[i][j][0] += 1.0 / d[2];
        }

  win1[0] = 0;
  win2[0] = 0;

  for (int i = 1; i <= D; ++i) {
    dt a = i - 1;
    win1[i] = a / d[1];
    win2[i] = a * a / d[2];
  }

  cout << fixed << setprecision(9) << go(m, n) << endl;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int tc; cin >> tc;
  while (tc--)
    solve();
  return 0;
}
