// http://codeforces.com/contest/407/problem/B

#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;
const int mod = 1000000007;

int add(int x, int y) {
  int ans = x + y;
  if (ans >= mod) ans -= mod;
  return ans;
}

void solve(int n) {
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
    i--;
  }
  vector<int> dp(n + 1);
  dp[0] = 2;
  for (int i = 1; i < n; ++i) {
    dp[i] = 2;
    for (int j = a[i]; j < i; ++j)
      dp[i] = add(dp[i], dp[j]);
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    // cout << dp[i] << endl;
    ans = add(ans, dp[i]);
  }
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n) solve(n);
  return 0;
}
