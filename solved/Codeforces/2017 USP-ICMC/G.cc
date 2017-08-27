#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int cost[30][30];


long long dp[100000][30];
long long go(int k, int ant) {
  if (k == 0) return 0;
  if (dp[k][ant] != -1) return dp[k][ant];
  long long best = 100000LL * 100000LL;
  for (int i = 0; i < 26; i++) {
    best = min(best, cost[ant][i] + go(k - 1, i));
  }
  return dp[k][ant] = best;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  int k;
  cin >> k;
  for (int i = 0; i < 26; i++)
    for (int j = 0; j < 26; j++)
      cin >> cost[i][j];

  long long best = 100000LL * 100000LL;

  memset(dp, -1, sizeof dp);
  for (int i = 0; i < 26; i++)
    best = min(best, go(k - 1, i));
  cout << best << endl;
  return 0;
}
