#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

typedef long double ld;
const int MN = 3000000 + 1000;
ld s[MN];
ld dp[MN][4];

ld go(int n, int k) {
  if (k == 1)
    return s[n];

  if (dp[n][k] > -100) return dp[n][k];

  ld best = -1e100;
  for (int i = 1; n - i >= k - 1; ++i) {
    best = max(best, s[i] + go(n - i, k - 1));
  }
  return dp[n][k] = best;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  int n; cin >> n;
  for (int i = 1; i <= n; ++i) {
    s[i] = sin(i);
    for (int j = 0; j < 4; ++j)
      dp[i][j] = -1e100;
  }
  cout << fixed << setprecision(9) << go(n, 3) << endl;
  return 0;
}
