#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
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


bool bi_col(vector<vector<edge> > &g, vector<bool> &vi, vector<int> &c,
            vector<int> &is_b,
            int node, int col, int &tot) {
  if (vi[node]) return c[node] == col;
  vi[node] = true;
  c[node] = col;

  int ok = true;
  for (int i = 0; i < g[node].size(); ++i)
    if (!is_b[g[node][i].id])
      ok &= bi_col(g, vi, c, is_b, g[node][i].to, col ^ 1, tot);

  tot++;
  return ok;
}

void solve() {
  int n, m;
  cin >> n >> m;
  graph g(n, m);
  int u, v;
  for (int i = 0; i < m; ++i) {
    cin >> u >> v;
    g.add_edge(u, v);
  }

  g.comp_bridges();

  vector<bool> vi(n);
  vector<int> col(n);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (!vi[i]) {
      int tot = 0;
      if (!bi_col(g.g, vi, col, g.is_b, i, 0, tot))
        ans += tot;
    }
  }
  printf("%d\n", ans);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc; cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}
