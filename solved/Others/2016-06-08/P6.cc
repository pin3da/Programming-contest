#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

const int MN = 10000 + 1;
long long dp[2][MN];

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;

  while (cin >> n) {
    vector<long long> a(n);
    for (auto &i : a) cin >> i;

    memset(dp, 0, sizeof dp);
    int it = 0;
    for (int len = 2; len <= n; len += 2) {
      int next = it ^ 1;
      for (int j = 0; j + len - 1 < n; ++j) {
        dp[it][j] = a[j] + min(dp[next][j + 1], dp[next][j + 2]);
        dp[it][j] = max(dp[it][j], a[j + len - 1] + min(dp[next][j], dp[next][j + 1]));
      }
      it = next;
    }
    it ^= 1;
    cout << dp[it][0] << endl;;
  }
  return 0;
}
