#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T>
void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

struct Dsu {
  vector<int> p;

  Dsu(int n) {
    p.resize(n);
    for (int i = 0; i < n; i++) {
      p[i] = i;
    }
  }

  int Find(int x) { return x == p[x] ? x : p[x] = Find(p[x]); }

  int Join(int x, int y) {
    int px = Find(x), py = Find(y);
    if (px == py) return 0;
    p[px] = py;
    return 1;
  }
};

struct Edge {
  int to, id;
  Edge(int a, int b) : to(a), id(b) {}
};

struct Graph {
  vector<vector<Edge>> g;
  vector<int> vi, low, d, pi, is_b;
  int bridges_computed;

  int ticks, edges;

  Graph(int n, int m) {
    g.assign(n, vector<Edge>());
    is_b.assign(m, 0);
    vi.resize(n);
    low.resize(n);
    d.resize(n);
    pi.resize(n);
    edges = 0;
    bridges_computed = 0;
  }

  void AddEdge(int u, int v) {
    g[u].push_back(Edge(v, edges));
    g[v].push_back(Edge(u, edges));
    edges++;
  }

  void Dfs(int u) {
    vi[u] = true;
    d[u] = low[u] = ticks++;
    for (int i = 0; i < (int)g[u].size(); ++i) {
      int v = g[u][i].to;
      if (v == pi[u]) continue;
      if (!vi[v]) {
        pi[v] = u;
        Dfs(v);
        if (d[u] < low[v]) is_b[g[u][i].id] = true;

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
  void CompBridges() {
    fill(pi.begin(), pi.end(), -1);
    fill(vi.begin(), vi.end(), 0);
    fill(low.begin(), low.end(), 0);
    fill(d.begin(), d.end(), 0);
    ticks = 0;
    for (int i = 0; i < (int)g.size(); ++i)
      if (!vi[i]) Dfs(i);
    bridges_computed = true;
  }

  map<int, vector<Edge>> BridgesTree() {
    if (!bridges_computed) CompBridges();
    int n = g.size();
    Dsu dsu(g.size());
    for (int i = 0; i < n; i++)
      for (auto e : g[i])
        if (!is_b[e.id]) dsu.Join(i, e.to);

    map<int, vector<Edge>> tree;
    for (int i = 0; i < n; i++)
      for (auto e : g[i])
        if (is_b[e.id])
          tree[dsu.Find(i)].emplace_back(dsu.Find(e.to), e.id);

    return tree;
  }
};


void Dfs(map<int, vector<Edge>> &tree, vector<int> &d, int node) {
  for (auto e : tree[node]) {
    if (d[e.to] == -1) {
      d[e.to] = d[node] + 1;
      Dfs(tree, d, e.to);
    }
  }
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#define endl '\n'
#endif

  int n, m;
  cin >> n >> m;
  Graph graph(n, m);

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    graph.AddEdge(u - 1, v - 1);
  }

  map<int, vector<Edge>> tree = graph.BridgesTree();

  vector<int> d(n, -1);
  int start = tree.begin()->first;
  d[start] = 0;
  Dfs(tree, d, start);
  for (auto &it : tree)
    if (d[start] < d[it.first]) start = it.first;

  d.assign(n, -1);
  d[start] = 0;
  Dfs(tree, d, start);
  for (auto &it : tree)
    if (d[start] < d[it.first]) start = it.first;

  cout << d[start] << endl;

  return 0;
}
