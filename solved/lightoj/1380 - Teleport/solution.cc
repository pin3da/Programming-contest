using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = "  << (x) << endl

const int inf = 1000000 + 10;

struct edge {
  int u, v, w;
  edge() {}
  edge(int a,int b,int c) : u(a), v(b), w(c) {}
  bool operator < (const edge& o) const {
    if (u == o.u)
      if (v == o.v)
        return w < o.w;
      else
        return v < o.v;
    return u < o.u;
  }
};

int dmst(vector<edge> &edges, int root, int n) {
  int ans = 0;
  int cur_nodes = n;
  while (true) {
    vector<int> lo(cur_nodes, inf), pi(cur_nodes, inf);
    for (int i = 0; i < edges.size(); ++i) {
      int u = edges[i].u, v = edges[i].v, w = edges[i].w;
      if (w < lo[v] and u != v) {
        lo[v] = w;
        pi[v] = u;
      }
    }

    lo[root] = 0;
    for (int i = 0; i < lo.size(); ++i) {
      if (i == root) continue;
      if (lo[i] == inf) return -1;
    }
    int cur_id = 0;
    vector<int> id(cur_nodes, -1), mark(cur_nodes, -1);
    for (int i = 0; i < cur_nodes; ++i) {
      ans += lo[i];
      int u = i;
      while (u != root and id[u] < 0 and mark[u] != i) {
        mark[u] = i;
        u = pi[u];
      }
      if (u != root and id[u] < 0) { // Cycle
         for (int v = pi[u]; v != u; v = pi[v])
           id[v] = cur_id;
         id[u] = cur_id++;
      }
    }

    if (cur_id == 0)
      break;

    for (int i = 0; i < cur_nodes; ++i)
      if (id[i] < 0) id[i] = cur_id++;

    for (int i = 0; i < edges.size(); ++i) {
      int u = edges[i].u, v = edges[i].v, w = edges[i].w;
      edges[i].u = id[u];
      edges[i].v = id[v];
      if (id[u] != id[v])
        edges[i].w -= lo[v];
    }
    cur_nodes = cur_id;
    root = id[root];
  }

  return ans;
}

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<edge> edges(m);
  for (int i = 0; i < m; ++i)
    cin >> edges[i].u >> edges[i].v >> edges[i].w;

  int ans  =  dmst(edges, k, n);
  if (ans < 0)
    printf("impossible\n");
  else
    printf("%d\n", ans);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int t; cin >> t;
  for (int i = 0; i < t; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }

  return 0;
}
