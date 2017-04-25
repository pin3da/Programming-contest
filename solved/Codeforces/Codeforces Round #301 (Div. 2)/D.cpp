// http://codeforces.com/contest/540/problem/D

using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);

double dp[111][111][111][4];

int main() { ___
  int a, b, c;
  cin >> a >> b >> c;

  memset(dp, 0, sizeof dp);
  for (int i = 0; i < 111; ++i) {
    dp[i][0][0][0] = 1;
    dp[0][i][0][1] = 1;
    dp[0][0][i][2] = 1;
  }


    for (int t = 0; t < 3; ++t) {
      for (int r = 0; r < a + 10; ++r) {
        for (int s = 0; s < b + 10; ++s) {
          for (int p = 0; p < c + 10; ++p) {
            if (r > 0  && s == 0 && p == 0) continue;
            if (s > 0  && r == 0 && p == 0) continue;
            if (p > 0  && s == 0 && r == 0) continue;
            double ps = 0, pr = 0, pp = 0;
            if (r > 0 && s > 0) {
              ps = dp[r][s - 1][p][t] * 2.0 * ((r / double(r + s + p)) * (s / double(r + s + p - 1)));
            }
            if (r > 0 && p > 0) {
              pr = dp[r - 1][s][p][t] * 2.0 * ((r / double(r + s + p)) * (p / double(r + s + p - 1)));
            }
            if (s > 0 && p > 0) {
              pp = dp[r][s][p - 1][t] * 2.0 * ((s / double(r + s + p)) * (p / double(r + s + p - 1)));
            }
            double prep = 0;
            if (r > 1) prep += ((r / double(r + s + p)) * ((r - 1) / double(r + s + p - 1)));
            if (s > 1) prep += ((s / double(r + s + p)) * ((s - 1) / double(r + s + p - 1)));
            if (p > 1) prep += ((p / double(r + s + p)) * ((p - 1) / double(r + s + p - 1)));

            dp[r][s][p][t] = (ps + pr + pp) / (1.0 - prep);
          }
        }
      }
    }

  double x = dp[a][b][c][0];
  double y = dp[a][b][c][1];
  double z = dp[a][b][c][2];

  cout << fixed << setprecision(12) << dp[a][b][c][0] << " " << dp[a][b][c][1] << " " << dp[a][b][c][2] << endl;
  return 0;
}
