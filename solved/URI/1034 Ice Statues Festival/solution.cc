#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc; cin >> tc;
  while (tc--) {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    vector<int> dp(m + 1);
    for (auto &i : a) {
      cin >> i;
      dp[i] = 1;
    }
    for (int i = 2; i <= m; ++i) {
      if (dp[i] == 0) dp[i] = i;
      for (auto &j : a) {
        if (i - j > 0)
          dp[i] = min(dp[i], dp[i - j] + 1);
      }
    }
    cout << dp[m] << endl;
  }
  return 0;
}
