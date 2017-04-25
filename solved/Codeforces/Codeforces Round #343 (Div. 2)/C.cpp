// http://codeforces.com/contest/629/problem/C

#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'
using namespace std;

const int MN = 2002;
long long dp[MN][MN];
const long long mod = 1000000000 + 7;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  dp[0][0] = 1;
  for (int i = 1; i < MN; ++i) {
    dp[i][0] = dp[i - 1][1];
    for (int j = 1; j < MN; ++j) {
      dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod;
      dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % mod;
    }
  }

  int n, m;
  while (cin >> n >> m) {
    m = n - m;
    string line;
    cin >> line;
    int op = 0, close = 0;
    for (auto &i : line) {
      if (i == '(') {
        op++;
      } else {
        op--;
      }
      close = min(op, close);
    }

    long long ans = 0;
    for (int i = 0; i <= m; ++i) {
      for (int j = 0; j <= i; ++j) {
        if (j + close >= 0 && j + op >= 0 && j + op <= m) {
          ans = (ans + dp[i][j] * dp[m - i][j + op]) % mod;
        }
      }
    }

    cout << ans << endl;
  }
  return 0;
}
