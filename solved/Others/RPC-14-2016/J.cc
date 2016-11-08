#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl
#define forall(it, x) for (typeof x.begin() it = x.begin(); it != x.end(); ++it)

const int MN = 123;

long long p[MN][MN];
long long dp[MN][MN];

int n, m;
long long go(int i, int tengo) {
  if (i == n) return 0;
  if (tengo == 0) return 0;
  if (dp[i][tengo] != -1) return dp[i][tengo];
  
  long long best = go(i + 1, tengo);
  for (int j = 0; j < tengo; ++j) {
    best = max(best, go(i + 1, tengo - j - 1) + p[i][j]);
  }
  return dp[i][tengo] = best;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  cin >> m >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> p[i][j];
    }
  }
  memset(dp, -1, sizeof dp); 
  cout << go(0, m) << endl;
  return 0;
}
