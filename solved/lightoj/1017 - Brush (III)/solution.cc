#include <bits/stdc++.h>
using namespace std;

const int inf = 1 << 30;

const int MN = 111;
int nxt[MN], cnt[MN];
int dp[MN][MN];

int go(const vector<int> &x, int i, int k) {
  if (k < 0)
    return -inf;
  if (i >= x.size())
    return 0;

  if (dp[i][k] != -1)
    return dp[i][k];
  return dp[i][k] = max(go(x, nxt[i], k - 1) + cnt[i], go(x, i + 1, k));
}

void solve() {
  int n, w, k;
  scanf("%d%d%d", &n, &w, &k);
  vector<int> x(n), y(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &x[i], &y[i]);
  }
  sort(y.begin(), y.end());
  for (int i = 0; i < n; ++i) {
    int j;
    for (j = i; j < n && ((y[j] - y[i]) <= w); ++j);
    nxt[i] = j;
    cnt[i] = j - i;
  }
  memset(dp, -1, sizeof dp);
  printf("%d\n", go(y, 0, k));
}

int main() {
  int n;
  cin >> n;
  for (int tc = 0; tc < n; ++tc) {
    printf("Case %d: ", tc + 1);
    solve();
  }
  return 0;
}
