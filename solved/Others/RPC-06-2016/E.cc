#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> graph;

void dfs(graph &g, vector<long long> &s,
    vector<long long> &ns) {

  for (int node = 0; node < g.size(); ++node)
    for (auto &to : g[node])
      ns[to] += s[node];
}

int main() {
  int n, m, s, t;
  while (cin >> n >> m >> s >> t) {
    graph g(n);
    for (int i = 0; i < m; ++i) {
      int u, v; cin >> u >> v;
      g[u].emplace_back(v);
      g[v].emplace_back(u);
    }
    vector<long long> sq(n);
    sq[s]++;
    for (int i = 0; i < t; ++i) {
      vector<long long> ns(n);
      dfs(g, sq, ns);
      sq = ns;
    }
    long long ans = 0;
    for (int i = 0; i < sq.size(); ++i) {
      ans += sq[i];
    }
    cout << ans << endl;
  }
  return 0;
}
