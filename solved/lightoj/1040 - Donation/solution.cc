using namespace std;
#include <bits/stdc++.h>

struct edge{
  int u, v, w;
  edge(int a, int b, int c): u(a), v(b), w(c) {}
  edge() {}

  bool operator < (const edge &o) const {
    return w < o.w;
  }
};

int p[111];

int fs(int x) {
  return p[x] == x ? x : (p[x] = fs(p[x]));
}

void join(int a, int b) {
  p[fs(a)] = fs(b);
}

void dfs(vector<vector<int> > &g, vector<bool> &v, int node) {
  if (v[node])
    return;

  v[node] = true;
  for (int i = 0; i < g[node].size(); ++i)
    dfs(g, v, g[node][i]);

}

void solve() {
  int n;
  cin >> n;
  vector<edge> edges;
  int t;
  int total = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      cin >> t;
      total += t;
      if (t > 0)
        edges.push_back(edge(i, j, t));
    }

  sort(edges.begin(), edges.end());

  for (int i = 0; i < n; ++i)
    p[i] = i;

  vector<vector<int> > g(n);
  for (int i = 0; i < edges.size(); ++i) {
    edge &e = edges[i];
    if (fs(e.u) != fs(e.v)) {
      total -= e.w;
      join(e.u, e.v);
      g[e.u].push_back(e.v);
      g[e.v].push_back(e.u);
    }
  }
  vector<bool> visited(n, false);
  dfs(g, visited, 0);
  for (int i = 0; i < n; ++i)
    if (!visited[i]) {
      printf("-1\n");
      return;
    }

  printf("%d\n", total);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }

  return 0;
}
