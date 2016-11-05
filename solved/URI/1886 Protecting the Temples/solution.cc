#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

struct Edge {
  int u, v;
  LL cap, flow;
  Edge() {}
  Edge(int u, int v, LL cap): u(u), v(v), cap(cap), flow(0) {}
};

struct Dinic {
  int N;
  vector<Edge> E;
  vector<vector<int>> g;
  vector<int> d, pt;

  Dinic(int N): N(N), E(0), g(N), d(N), pt(N) {}

  void AddEdge(int u, int v, LL cap) {
    if (u != v) {
      E.emplace_back(Edge(u, v, cap));
      g[u].emplace_back(E.size() - 1);
      E.emplace_back(Edge(v, u, 0));
      g[v].emplace_back(E.size() - 1);
    }
  }

  bool BFS(int S, int T) {
    queue<int> q({S});
    fill(d.begin(), d.end(), N + 1);
    d[S] = 0;
    while(!q.empty()) {
      int u = q.front(); q.pop();
      if (u == T) break;
      for (int k: g[u]) {
        Edge &e = E[k];
        if (e.flow < e.cap && d[e.v] > d[e.u] + 1) {
          d[e.v] = d[e.u] + 1;
          q.emplace(e.v);
        }
      }
    }
    return d[T] != N + 1;
  }

  LL DFS(int u, int T, LL flow = -1) {
    if (u == T || flow == 0) return flow;
    for (int &i = pt[u]; i < g[u].size(); ++i) {
      Edge &e = E[g[u][i]];
      Edge &oe = E[g[u][i]^1];
      if (d[e.v] == d[e.u] + 1) {
        LL amt = e.cap - e.flow;
        if (flow != -1 && amt > flow) amt = flow;
        if (LL pushed = DFS(e.v, T, amt)) {
          e.flow += pushed;
          oe.flow -= pushed;
          return pushed;
        }
      }
    }
    return 0;
  }

  LL MaxFlow(int S, int T) {
    LL total = 0;
    while (BFS(S, T)) {
      fill(pt.begin(), pt.end(), 0);
      while (LL flow = DFS(S, T))
        total += flow;
    }
    return total;
  }
};

typedef vector<vector<int> > graph;

const int MN = 1234;
int color[MN];

void dfs(graph &g, Dinic &f, int node, int pi, int c) {
  if (color[node] != -1) return;
  color[node] = c;
  for (int i = 0; i < (int)g[node].size(); ++i) {
    int to = g[node][i];
    if (to == pi) continue;
    if (c == 0)
      f.AddEdge(node, to, 1);
    else
      f.AddEdge(to, node, 1);
    dfs(g, f, to, node, c ^ 1);
  }
}

void solve() {
  int n, m; cin >> n >> m;
  graph g(n);
  for (int i = 0; i < m; ++i) {
    int u, v; cin >> u >> v;
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  memset(color, -1, sizeof color);
  Dinic flow(n + 10);
  int source = n;
  int sink = source + 1;
  dfs(g, flow, 0, 0, 0);
  for (int i = 0; i < n; ++i) {
    if (color[i] == 0)
      flow.AddEdge(source, i, 1);
    else
      flow.AddEdge(i, sink, 1);
  }

  cout << n - flow.MaxFlow(source, sink) << endl;
}


int main() {
  int t; cin >> t;
  while (t--)
    solve();

  return 0;
}
