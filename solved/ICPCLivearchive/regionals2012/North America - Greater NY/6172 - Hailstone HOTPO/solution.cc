#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MN = 100010;

ll dp[MN];
int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int p; cin >> p;
  memset(dp, -1, sizeof dp);
  while (p--) {
    int id; cin >> id;
    int n; cin >> n;
    if (dp[n] != -1) {
      cout << id << " " << dp[n] << endl;
      continue;
    }

    int ii = n;
    ll ans = 1;
    while (n != 1) {
      ans = max(ans, (ll)n);
      int np;
      if (n & 1)
        n = 3 * n + 1;
      else
        n = n >> 1;

    }
    dp[ii] = ans;
    cout << id << " " << ans << endl;
  }
  return 0;
}
