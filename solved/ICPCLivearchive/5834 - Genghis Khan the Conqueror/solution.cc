using namespace std;
#include <bits/stdc++.h>
#define endl '\n'

struct edge{
  int u, v, c;
  edge() {}
  edge(int x, int y, int z) : u(x), v(y), c(z) {}
  bool operator < (const edge &o) const {
    if (c == o.c)
      return u + v < o.u + o.v;
    return c < o.c;
  }
};

const int MN = 3003;
int p[MN];

int fs(int x) {
  return p[x] == x ? x : p[x] = fs(p[x]);
}

void dfs(vector<vector<int>> &g, vector<int> &o,
          vector<bool> &vi, int node, int pi) {

  if (vi[node]) return;
  vi[node] = true;
  o.push_back(node);
  for (int i = 0; i < g[node].size(); ++i) {
    int to = g[node][i];
    if (to != pi)
      dfs(g, o, vi, to, node);
  }

}

void solve(int n, int m) {
  for (int i = 0; i < n; ++i)
    p[i] = i;

  vector<edge> edges(m);
  vector<vector<edge>> g(n);
  int u, v, c;
  for (int i = 0; i < m; ++i) {
    cin >> u >> v >> c;
    edges[i] = edge(u, v, c);
    g[u].push_back( edge(u, v, c));
    g[v].push_back( edge(v, u, c));
  }
  sort(edges.begin(), edges.end());
  for (int i = 0; i < n; ++i)
    sort(g[i].begin(), g[i].end());


  vector<vector<int>> tree(n);
  vector<edge> t_edges;
  vector<vector<int>> cost(n, vector<int> (n));
  vector<vector<bool>> in_tree(n, vector<bool> (n));
  int tree_cost = 0;

  for (int i = 0; i < m && t_edges.size() < n; ++i) {
    u = edges[i].u; v = edges[i].v; c = edges[i].c;
    if (fs(u) == fs(v))
      continue;

    p[fs(u)] = fs(v);

    t_edges.push_back(edges[i]);
    cost[u][v] = cost[v][u] = c;
    in_tree[u][v] = in_tree[v][u] = true;
    tree[u].push_back(v);
    tree[v].push_back(u);
    tree_cost += c;
  }

  vector<vector<int>> best(n, vector<int> (n, 1 << 24));
  for (int i = 0; i < t_edges.size(); ++i) {
    u = t_edges[i].u; v = t_edges[i].v;
    vector<int> origin;
    vector<bool> visited(n, false);
    dfs(tree, origin, visited, u, v);
    for (int j = 0; j < origin.size(); ++j) {
      int x = origin[j];
      for (int k = 0; k < g[x].size(); ++k) {
        int y = g[x][k].v;
        if (x == u && y == v)  continue;
        if (x == v && y == u)  continue;
        if (visited[y]) continue;
        best[u][v] = best[v][u] = min(min(best[u][v], best[v][u]), g[x][k].c);
        break;
      }
    }
  }

  int q; cin >> q;
  long double ans = 0;
  for (int i = 0; i < q; ++i) {
    cin >> u >> v >> c;
    if (in_tree[u][v]) {
      int rep = min(c, best[u][v]);
      ans += tree_cost - cost[u][v] + rep;
    } else {
      ans += tree_cost;
    }
  }

  ans /= q;
  cout << fixed << setprecision(4) << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m;
  while (cin >> n >> m && (n + m)) {
    solve(n, m);
  }
  return 0;
}
