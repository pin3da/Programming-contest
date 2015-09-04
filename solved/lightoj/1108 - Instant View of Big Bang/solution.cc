using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

const int inf = 1000000000;
struct edge{
  int v, w; edge(){} edge(int v, int w) : v(v), w(w) {}
};

void dfs(vector<vector<edge> > &g, vector<int> &vi, int node) {
  if (vi[node])
    return;
  vi[node] = true;
  for (int i = 0; i < g[node].size(); ++i) {
    dfs(g, vi, g[node][i].v);
  }
}

vector<int> bellman(vector<vector<edge> > &g, int s) {
  int n = g.size();
  vector<int> d(n, inf), p(n, -1), vi(n);
  vector<int> in_cycle;
  d[s] = 0;
  for (int i = 0; i < n - 1; ++i) {
    for (int u = 0; u < n; ++u) {
      for (int k = 0; k < g[u].size(); ++k) {
        int v = g[u][k].v, w = g[u][k].w;
        if (d[u] + w < d[v]) {
          d[v] = d[u] + w;
          p[v] = u;
        }
      }
    }
  }

  for (int i = 0; i < n - 1; ++i) {
    for (int u = 0; u < n; ++u) {
      for (int k = 0; k < g[u].size(); ++k) {
        int v = g[u][k].v, w = g[u][k].w;
        if (d[u] + w < d[v]) {
          dfs(g, vi, v);
        }
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    if (vi[i])
      in_cycle.push_back(i);
  }
  return in_cycle;
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<edge> > g(n + 1);
  int u, v, w;
  for (int i = 0; i < m; ++i) {
    cin >> v >> u >> w;
    g[u].push_back(edge(v, w));
  }
  for (int i = 0; i < n; ++i)
    g[n].push_back(edge(i, 1));

  vector<int> c = bellman(g, n);
  if (c.empty()) {
    puts("impossible");
    return;
  }

  for (int i = 0; i < c.size(); ++i) {
    if (i) printf(" ");
    printf("%d", c[i]);
  }
  printf("\n");
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
