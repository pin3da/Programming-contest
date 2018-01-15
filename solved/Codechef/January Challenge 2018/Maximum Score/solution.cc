#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x " = " << (x) << endl

const long long inf = 1e18;

void solve() {
  int n;
  cin >> n;
  vector<vector<long long>> a(n, vector<long long>(n));
  for (auto &it : a) {
    for (auto &i : it) cin >> i;
    sort(it.begin(), it.end());
  }

  vector<vector<long long>> dp(n, vector<long long>(n, -inf));
  for (int i = 0; i < n; i++)
    dp[0][i] = a[0][i];

  for (int i = 1; i < n; i++) {
    int j = -1;
    long long best = -inf;
    for (int k = 0; k < n; k++) {
      while (j + 1 < n && a[i - 1][j + 1] < a[i][k]) {
        best = max(best, dp[i - 1][j + 1]);
        j++;
      }
      if (j != -1) {
        dp[i][k] = best + a[i][k];
      }
    }
  }

  long long best = -1;
  for (int i = 0; i < n; i++) {
    if (dp[n - 1][i] > 0)
      best = max(best, dp[n - 1][i]);
  }
  cout << best << endl;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif
  int tc;
  cin >> tc;
  while (tc--)
    solve();
  return 0;
}
