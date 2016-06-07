#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

const int MN = 1000 * 1000 + 10;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc; cin >> tc;
  while (tc--) {
    int n, k;
    cin >> n >> k;
    vector<int> dp(MN), r(MN), p(MN);
    vector<int> t(n);
    for (int i = 0; i < n; ++i) {
      cin >> t[i];
      r[t[i]] = 1;
    }
    for (int i = 0; i < n; ++i) {
      int q; cin >> q;
      p[t[i]] = max(p[t[i]], q);
    }

    for (int i = MN - 2; i >= 0; --i) {
      dp[i] = dp[i + 1];
      if (r[i] && i + k < MN)
        dp[i] = max(dp[i], p[i] + dp[i + k]);
    }
    cout << dp[0] << endl;
  }

  return 0;
}
