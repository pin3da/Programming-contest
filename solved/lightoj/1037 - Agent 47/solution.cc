using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

const int inf = 1 << 30;

const int MN = 15;
int dp[(1 << MN) + 1];

int go(vector<int> &h, vector<vector<int> > &d, int mask) {
  int t = __builtin_popcount(mask);
  if (t == h.size())
    return 0;

  if (dp[mask] != -1)
    return dp[mask];

  int ans = inf;
  for (int i = 0; i < h.size(); ++i) {
    if (!((mask >> i) & 1)) {
      ans = min(ans, h[i] + go(h, d, mask | (1 << i)));
      for (int j = 0; j < h.size(); ++j) {
        if ((mask >> j) & 1) {
          int damage = d[j][i];
          if (damage == 0) continue;
          ans = min(ans, ((h[i] + damage - 1) / damage) + go(h, d, mask | (1 << i)));
        }
      }
    }
  }

  return dp[mask] = ans;
}

void solve() {
  int n;
  cin >> n;
  vector<int> health(n);
  for (int i = 0; i < n; ++i)
    cin >> health[i];

  vector<vector<int> > d(n, vector<int>(n));
  char t;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> t;
      d[i][j] = t - '0';
    }
  }

  memset(dp, -1, sizeof dp);

  printf("%d\n", go(health, d, 0));
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
