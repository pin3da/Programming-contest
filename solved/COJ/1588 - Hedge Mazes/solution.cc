#include<bits/stdc++.h>
#define endl '\n'
#define debug(x) cout << #x << " = " << (x) << endl

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


struct state {
  int node;
  bool b;
  state(int a, bool x):  node(a), b(x) {}
};

const int MN = 10055;

int p[MN];

int fs(int x) {
  return x == p[x] ? x : p[x] = fs(p[x]);
}

int js(int x, int y) {
  p[fs(x)] = fs(y);
}

void solve(int nodes, int e, int q) {

  graph g(nodes, e);
  for (int i = 0; i < e; ++i) {
    int u, v; cin >> u >> v;
    u--;v--;
    g.add_edge(u, v);
  }
  g.comp_bridges();

  for (int i = 0; i < nodes + 10; ++i) p[i] = i;

  for (int i = 0; i < nodes; ++i) {
    for (auto &e : g.g[i]) {
      if (g.is_b[e.id]) {
        js(i, e.to);
      }
    }
  }
  for (int i = 0; i < q; ++i) {
    int u, v; cin >> u >> v;
    u--; v--;
    int ok = fs(u) == fs(v);
    puts(ok ? "Y": "N");
  }

  puts("-");
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int nodes, e, q;
  while (cin >> nodes >> e >> q && (nodes + e + q)) {
    solve(nodes, e, q);
  }

  return 0;
}
