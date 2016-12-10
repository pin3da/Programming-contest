#include <bits/stdc++.h>

using namespace std;

const int ME = 1e7 + 100;
const long long inf = 1e18;

long long dp[ME];
int main() {
  int e, succ, fail;
  cout << fixed << setprecision(6);
  while (cin >> e >> succ >> fail && e) {
    for (int i = 1; i <= e; ++i) {
      dp[i] = 1;
      if (i > succ) dp[i] += dp[i - succ];
      if (i > fail) dp[i] += dp[i - fail];
      dp[i] = min(dp[i], inf);
    }
    long double ans = min(200.0 / dp[e], 225.0 / (dp[e] + 1));
    cout << ans << endl;
  }

  return 0;
}
