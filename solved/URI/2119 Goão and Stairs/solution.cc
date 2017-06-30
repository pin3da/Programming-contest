// Wrong Answer

#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

typedef pair<int, long long> stair;

const int MN = 10000 + 100;

long long dp[MN];

const long long mod = 1000000009LL;

long long go(vector<vector<stair>> &g, int node) {
  int last = g.size() - 1;
  if (node == last) return mod + 100;

  if (dp[node] != -1) return dp[node];

  long long best = 0;
  for (auto to : g[node])
    best = max(best, min(go(g, to.first), to.second));
  return dp[node] = best;
}

long long add(long long x, long long y) {
  x += y;
  if (x >= mod) return x - mod;
  return x;
}

long long dp_j[MN];

long long jumps(vector<int> &steps, long long len) {
  if (len <= 1) return 1;

  if (dp_j[len] != -1) return dp_j[len];
  long long ans = 0;
  for (int i = 0; i < (int)steps.size(); ++i) {
    if (len - steps[i] >= 0) ans = add(ans, jumps(steps, len - steps[i]));
  }
  return dp_j[len] = ans;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  int n, m, k;
  while (cin >> n >> m >> k) {
    memset(dp, -1, sizeof dp);
    memset(dp_j, -1, sizeof dp_j);
    vector<vector<stair>> g(n);
    vector<int> jump_len(k);
    for (auto &i : jump_len) cin >> i;
    for (int i = 0; i < m; ++i) {
      int u, v, w; cin >> u >> v >> w;
      if (u > v) swap(u, v);
      g[u].emplace_back(v, jumps(jump_len, w) % mod);
      // g[u].emplace_back(v, w);
    }
    cout << go(g, 0) << endl;
  }
  return 0;
}
