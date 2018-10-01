#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

void dfs(vector<vector<int>> &g, int node, vector<int> &p, vector<pair<int, int>> &d) {
  d[node].second = d[node].first;
  for (auto to : g[node]) {
    if (to == p[node]) continue;
    p[to] = node;
    d[to].first = d[node].first + 1;
    dfs(g, to, p, d);
    d[node].second = max(d[node].second, d[to].second);
  }
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#define endl '\n'
#endif

  int n, x;
  cin >> n >> x;
  x--;
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }

  vector<int> p1(n, -1), p2(n, -1);
  vector<pair<int, int>> d1(n), d2(n);
  dfs(g, 0, p1, d1);
  dfs(g, x, p2, d2);

  int c = p1[x];
  while (d1[c].first > d2[c].first) {
    x = c;
    c = p1[c];
  }

  cout << 2 * d1[x].second << endl;
  return 0;
}
