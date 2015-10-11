using namespace std;
#include <bits/stdc++.h>

const int MS  = 250000;
const int MN  = 2 * MS + 1;
const int inf = MS * 10;

int dp[2][MN];

int go(vector<int> &a, int m) {
  int cur = 0;
  for (int i = -MS; i <= MS; ++i) {
    dp[cur][MS + i] = -inf;
    dp[cur][MS + i] = -inf;
  }
  dp[cur][MS] = 0;

  for (int i = a.size() - 1;  i >= 0; --i) {
    cur ^= 1;
    for (int acc = -m; acc <= m; ++acc) {
      int best = -inf;
      if (acc + a[i] <= m) best = max(best, dp[cur ^ 1][MS + acc + a[i]] + a[i]);
      if (abs(acc - a[i]) <= m) best = max(best, dp[cur ^ 1][MS + acc - a[i]] + a[i]);
      best = max(best, dp[cur ^ 1][MS + acc]);
      dp[cur][MS + acc] =  best;
    }
  }

  return dp[cur][MS];
}

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];

  int m = accumulate(a.begin(), a.end(), 0);
  int ans = go(a, (m + 1)/ 2);
  if (ans <= 0)
    puts("impossible");
  else
    printf("%d\n", ans / 2);
}

int main() {
  // ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc; cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}
