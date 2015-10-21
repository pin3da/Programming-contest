using namespace std;
#include <bits/stdc++.h>

struct edge{
  int u, v, w;
  edge(int a, int b) : v(a), w(b) {}
};

void dfs(vector<vector<edge> >  &g, int node, int pi, int depth, int &dist,
         int &a, vector<int> &d) {
  for (int i = 0; i < g[node].size(); ++i) if (g[node][i].v != pi)
    dfs(g, g[node][i].v, node, depth + g[node][i].w, dist, a, d);
  if (depth > dist) {
    dist = depth;
    a = node;
  }
  d[node] = depth;
}

void solve() {
  int n, u, v, w;
  cin >> n;
  vector<vector<edge> > g(n);
  for (int i = 0; i < n - 1; ++i) {
    cin >> u >> v >> w;
    g[u].push_back(edge(v, w));
    g[v].push_back(edge(u, w));
  }

  int a, b, dist = 0;
  vector<int> da(n, -1), db(n, -1);
  dfs(g, 0, -1, 0, dist, a, da);
  dist = 0;
  dfs(g, a, -1, 0, dist, b, da);
  dfs(g, b, -1, 0, dist, a, db);

  for (int i = 0; i < n; ++i)
    printf("%d\n", max(da[i], db[i]));
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d:\n", i + 1);
    solve();
  }
  return 0;
}
