#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

const long long inf = 1000000000;
const int MN = 35000 + 100;
int a[MN];

long long dp[55][MN];

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  set<int> diff;
  for (int i = n - 1; i >= 0; i--) {
    diff.insert(a[i]);
    dp[1][i] = diff.size();
  }

  for (int j = 2; j <= k; j++) {
    for (int i = n - j; i >= 0; i--) {
      long long best = 0;
      long long ant = 0;
      diff.clear();
      for (int ii = i + 1; ii < n; ii++) {
        diff.insert(a[ii - 1]);
        best = max<long long>(best, dp[j - 1][ii] + diff.size());
        if (best < ant) break;
        ant = best;
      }
      dp[j][i] = best;
    }
  }
  cout << dp[k][0] << endl;
  return 0;
}
