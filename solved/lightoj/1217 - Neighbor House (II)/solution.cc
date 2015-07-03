using namespace std;
#include <bits/stdc++.h>

int dp[1111][3][3];

int go(vector<int> &a, int idx, bool prev, bool first) {

  if (idx == a.size() - 1) {
    if (!prev && !first)
      return a[idx];
    return 0;
  }
  if (dp[idx][prev][first] != -1)
    return dp[idx][prev][first];
  int ans = 0;
  if (!prev)
    ans = max(ans, go(a, idx + 1, 1, (idx == 0) ? 1 : first) + a[idx]);
  ans = max(ans, go(a, idx + 1, 0, first));

  return dp[idx][prev][first] = ans;
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];

  memset(dp, -1, sizeof dp);
  int ans = go(a, 0, 0, 0);
  printf("%d\n", ans);
}

int main() {
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}
