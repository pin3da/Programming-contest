// http://codeforces.com/contest/358/problem/D

#include <bits/stdc++.h>

using namespace std;

const int MN = 3123;
int c[MN][4];
int dp[MN][4];
int n;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  while (cin >> n) {
    for (int i = 0; i < n; ++i) cin >> c[i][0];
    for (int i = 0; i < n; ++i) cin >> c[i][1];
    for (int i = 0; i < n; ++i) cin >> c[i][2];

    for (int i = 0; i < 3; ++i)
      dp[n - 1][i] = c[n - 1][i];

    for (int i = n - 2; i >= 0; --i)
      for (int j = 0; j < 2; ++j)
        dp[i][j] = max(dp[i + 1][1] + c[i][j], dp[i + 1][0] + c[i][j + 1]);
    cout << dp[0][0] << endl;
  }
  return 0;
}
