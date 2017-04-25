// http://codeforces.com/contest/713/problem/C

#include <bits/stdc++.h>

using namespace std;

const int MN = 3003;
int a[MN];
int b[MN];
long long dp[MN][MN];

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n) {
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      a[i] -= i;
      b[i] = a[i];
    }
    sort(b, b + n);
    int m = unique(b, b + n) - b;
    dp[0][0] = abs(a[0] - b[0]);
    for (int i = 1; i < m; ++i)
      dp[0][i] = min<long long>(dp[0][i - 1], abs(a[0] - b[i]));
    for (int i = 1; i < n; ++i)
      dp[i][0] = abs(a[i] - b[0]) + dp[i - 1][0];

    for (int i = 1; i < n; ++i)
      for (int j = 1; j < m; ++j)
        dp[i][j] = min<long long>(abs(a[i] - b[j]) + dp[i - 1][j], dp[i][j - 1]);

    cout << dp[n - 1][m - 1] << endl;
  }

  return 0;
}
