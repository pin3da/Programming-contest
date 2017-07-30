#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

struct edge {
  int to, w;
  edge(int a, int b) : to(a), w(b) {}
};

typedef vector<vector<edge>> graph;

long long dfs(graph &g, int node, int pi) {
  long long ans = 0;
  for (auto e : g[node]) {
    if (e.to == pi) continue;
    ans += e.w;
    ans += dfs(g, e.to, node);
  }
  return ans;
}

long long path(graph &g, int node, int pi) {
  long long ans = 0;
  for (auto e : g[node]) {
    if (e.to == pi) continue;
    ans = max(ans, e.w + path(g, e.to, node));
  }
  return ans;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif


  int n; cin >> n;
  graph g(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v, w; cin >> u >> v >> w;
    u--;v--;
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
  }

  long long total = 2LL * dfs(g, 0, -1);
  cout << total - path(g, 0, -1) << endl;
  return 0;
}
