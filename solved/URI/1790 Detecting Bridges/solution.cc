#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

struct edge{
  int to, id;
  edge(int a, int b) : to(a), id(b) {}
};

struct graph {
  vector<vector<edge> > g;
  vector<int> vi, low, d, pi, is_b;

  int ticks, edges;

  graph(int n, int m) {
    g.assign(n, vector<edge>());
    is_b.assign(m, 0);
    vi.resize(n);
    low.resize(n);
    d.resize(n);
    pi.resize(n);
    edges = 0;
  }

  void add_edge(int u, int v) {
    g[u].push_back(edge(v, edges));
    g[v].push_back(edge(u, edges));
    edges++;
  }

  void dfs(int u) {
    vi[u] = true;
    d[u] = low[u] = ticks++;
    for (int i = 0; i < g[u].size(); ++i) {
      int v = g[u][i].to;
      if (v == pi[u]) continue;
      if (!vi[v]) {
        pi[v] = u;
        dfs(v);
        if (d[u] < low[v])
          is_b[g[u][i].id] = true;


        low[u] = min(low[u], low[v]);
      } else {
        low[u] = min(low[u], d[v]);
      }
    }
  }

  // Multiple edges from a to b are not allowed.
  // (they could be detected as a bridge).
  // If you need to handle this, just count
  // how many edges there are from a to b.
  void comp_bridges() {
    fill(pi.begin(), pi.end(), -1);
    fill(vi.begin(), vi.end(), 0);
    fill(low.begin(), low.end(), 0);
    fill(d.begin(), d.end(), 0);
    ticks = 0;
    for (int i = 0; i < g.size(); ++i)
      if (!vi[i]) dfs(i);
  }
};

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, p;
  while (cin >> n >> p) {
    graph g(n, p);
    for (int i = 0; i < p; ++i) {
      int u, v; cin >> u >> v;
      u--;v--;
      g.add_edge(u, v);
    }
    g.comp_bridges();
    cout << accumulate(g.is_b.begin(), g.is_b.end(), 0) << endl;
  }

  return 0;
}
