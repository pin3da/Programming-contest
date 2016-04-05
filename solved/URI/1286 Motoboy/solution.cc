#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int t[200], p[200];


long long dp[50][50];
long long go(int n, int i, int m) {
  if (n == i)
    return 0;

  if (dp[i][m] != -1)
    return dp[i][m];
  long long best = go(n, i + 1, m);
  if (m >= p[i]) {
    best = max(best, go(n, i + 1, m - p[i]) + t[i]);
  }
  return dp[i][m] = best;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n && n) {
    int m; cin >> m;
    for (int i = 0; i < n; ++i)
      cin >> t[i] >> p[i];

    /*int best = 0;
    int top = 1 << n;
    for (int i = 0; i < top; ++i) {
      int tot_p = 0;
      int cost = 0;
      for (int j = 0; j < n; ++j) {
        if ((i >> j) & 1) {
          tot_p += p[j];
          cost += t[j];
        }
      }
      if (tot_p <= m)
        best = max(best, cost);
    }*/

    memset(dp, -1, sizeof dp);
    long long best = go(n, 0, m);
    cout << best << " min." << endl;
  }
  return 0;
}

