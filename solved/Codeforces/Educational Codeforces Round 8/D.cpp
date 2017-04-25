// http://codeforces.com/contest/628/problem/D

#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int m, d;

long long dp[2][2001][2][2];

const long long mod = 1000 * 1000 * 1000 + 7;

long long add(long long x, long long y) {
  x += y;
  if (x >= mod)
    x -= mod;
  return x;
}

long long fill_dp(string line) {
  int cur = 0;
  for (int i = 0; i <= m; ++i)
    for (int j = 0; j < 2; ++j)
      for (int k = 0; k < 2; ++k)
        dp[cur][i][j][k] = 0;

  dp[cur][0][0][1] = 1;
  dp[cur][0][1][1] = 1;
  dp[cur][0][0][2] = 1;
  dp[cur][0][1][2] = 1;

  for (int i = line.size() - 1; i >= 0; --i) {
    cur ^= 1;
    for (int acc = 0; acc < m; ++acc) {
      for (int t = 0; t < 2; ++t) {
        for (int f = 0; f < 2; ++f) {
          int mmax = t ? line[i] - '0' : 9;
          long long ans = 0;
          if (f > 0) {
            if ((i & 1)) {
              if (d <= mmax)
                ans = add(ans, dp[cur ^ 1][(acc * 10 + d) % m][t && (mmax == d)][f]);
            } else {
              for (int j = 0; j <= mmax; ++j) {
                if (j == d) continue;
                ans = add(ans, dp[cur ^ 1][(acc * 10 + j) % m][t  && (mmax == j)][f]);
              }
            }
          } else {
            ans = add(ans, dp[cur ^ 1][0][0][0]);
            for (int j = 1; j <= mmax; ++j) {
              if (d == j) continue;
              ans = add(ans, dp[cur ^ 1][(acc * 10 + j) % m][t && j == mmax][1]);
            }
          }
          dp[cur][acc][t][f] = ans;
        }
      }
    }
  }
  return dp[cur][0][1][0];
}

string minus1(string a) {
  for (int i = a.size() - 1; i >= 0; --i) {
    if (a[i] >= '1') {
      a[i]--;
      return a;
    }
    a[i] = '9';
  }
  return a;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  while (cin >> m >> d) {
    string lo, hi;
    cin >> lo >> hi;
    long long a = fill_dp(hi);
    lo = minus1(lo);
    long long b = fill_dp(lo);
    // D(a);D(b);
    cout << add(a - b, mod) << endl;
  }
  return 0;
}
