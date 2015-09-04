using namespace std;
#include <bits/stdc++.h>

const int inf = 1 << 22;
struct entry{
  int p, c, w;
  entry() {}
};

int dp[101][10001][2];
int go(vector<entry> &a, int cur, int w, int taken) {
  if (cur == a.size())
    return 0;

  if (w < 0)
    return -inf;

  if (dp[cur][w][taken] != -1)
    return dp[cur][w][taken];

  int ans = -inf;
  if (!taken) {
    if (w - a[cur].c * a[cur].w >= 0) {
      ans = max(ans, go(a, cur + 1, w - a[cur].c * a[cur].w, 0));
      ans = max(ans, go(a, cur, w - a[cur].c * a[cur].w, 1));
    }
  } else {
    if (w - a[cur].w >= 0) {
      ans = max(ans, go(a, cur + 1, w - a[cur].w, 0) + a[cur].p);
      ans = max(ans, go(a, cur, w - a[cur].w, 1) + a[cur].p);
    }
  }

  return  dp[cur][w][taken] = ans;
}

void solve() {
  int n, w;
  cin >> n >> w;
  vector<entry> a(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i].p >> a[i].c >> a[i].w;

  memset(dp, - 1, sizeof dp);
  int ans = go(a, 0, w, 0);
  if (ans < 0)
    puts("Impossible");
  else
    printf("%d\n", ans);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}
