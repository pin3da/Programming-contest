using namespace std;
#include <bits/stdc++.h>

const int MS  = 500000;
const int MN  = 2 * MS + 10;
const int inf = MS * 10;

int dp[2][MN][2];

int go(vector<int> &a, int m) {

  int cur = 0;
  int n = a.size();
  for (int i = -MS; i < MS; ++i) {
    dp[cur][MS + i][1] = -inf;
    dp[cur][MS + i][0] = -inf;
  }
  dp[cur][MS + 0][1] = 0;

  for (int i = a.size() - 1;  i >= 0; --i) {
    cur ^= 1;
    for (int t = 0; t < 2; ++t) {
      for (int acc = -MS; acc <= MS; ++acc) {
        int best = dp[cur ^ 1][MS + acc + a[i]][1] + a[i];
        best = max(best, dp[cur ^ 1][MS + acc - a[i]][1] + a[i]);
        best = max(best, dp[cur ^ 1][MS + acc][0]);
        dp[cur][MS + acc][t] =  best;
      }
    }
  }
  return dp[cur][MS + 0][0];
}

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];

  int m = *max_element(a.begin(), a.end());
  // memset(dp, -1, sizeof dp);
  int ans = go(a, m);
  if (ans < 0)
    puts("impossible");
  else
    printf("%d\n", ans / 2);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc; cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}
