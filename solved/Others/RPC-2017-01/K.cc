#include <bits/stdc++.h>

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
    for (int &i = pt[u]; i < (int)g[u].size(); ++i) {
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

void solve() {
  int n;
  cin >> n;

  Dinic g(n + 10);
  int source = n + 1,
      sink = n + 2;

  int total = 0;
  for (int i = 0; i < n; ++i) {
    double t; cin >> t;
    int cap = round(t * 100.0);
    g.AddEdge(source, i, cap);
    total += cap;
  }

  for (int i = 0; i < n; ++i) {
    double t; cin >> t;
    int cap = round(t * 100.0);
    g.AddEdge(i, sink, cap);
    total += cap;
  }

  vector<vector<int>> help(n, vector<int>(n));
  for (auto &it : help)
    for (auto &i : it) {
      double t; cin >> t;
      i = round(t * 100);
      total += i;
    }

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      g.AddEdge(i, j, help[i][j] + help[j][i]);

  cout << (total - g.MaxFlow(source, sink)) / 100.0 << endl;
}

int main() {
  cout << fixed << setprecision(2);
  int tc;
  cin >> tc;
  while (tc--)
    solve();

  return 0;
}
