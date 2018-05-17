#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);  debug_out(t...); }
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

void dfs(vector<vector<int>> &g, int node, int pi, vector<int> &sz) {
  sz[node] = 1;
  for (auto to : g[node]) {
    if (to != pi) {
      dfs(g, to, node, sz);
      sz[node] += sz[to];
    }
  }
}

void solve() {
  int n; cin >> n;
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v; cin >> u >> v;
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vector<int> sz(n);
  dfs(g, 0, -1, sz);

  if (n & 1) {
    cout << -1 << endl;
  } else {
    int ans = 0;
    for (auto it : sz) {
      ans += (it & 1) == 0;
    }
    cout << ans - 1 << endl;
  }
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#endif
  //int tc; cin >> tc;
  //while (tc--)
    solve();
  return 0;
}

