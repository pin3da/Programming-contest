#include <bits/stdc++.h>

using namespace std;
#define debug(x) cout << #x " = " << (x) << endl

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
  vector<vector<int> > g;
  vector<int> d, pt;

  Dinic(int N): N(N), E(0), g(N), d(N), pt(N) {}

  void AddEdge(int u, int v, LL cap) {
    if (u != v) {
      E.push_back(Edge(u, v, cap));
      g[u].push_back(E.size() - 1);
      E.push_back(Edge(v, u, 0));
      g[v].push_back(E.size() - 1);
    }
  }

  bool BFS(int S, int T) {
    queue<int> q;
    q.push(S);
    fill(d.begin(), d.end(), N + 1);
    d[S] = 0;
    while(!q.empty()) {
      int u = q.front(); q.pop();
      if (u == T) break;
      for (int it = 0; it < (int)g[u].size(); ++it) {
        int k = g[u][it];
        Edge &e = E[k];
        if (e.flow < e.cap && d[e.v] > d[e.u] + 1) {
          d[e.v] = d[e.u] + 1;
          q.push(e.v);
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


double pend(double h, double k, double x, double r) {
  return k - sqrt(r * r - (x - h) * (x - h));
}

int find_x(double x, int n, int m) {
  return int(x);
}

int find_y(double x, double y, double n, int m) {
  for (int i = 0; i < m; ++i) {
    double lower = pend(n * 0.5, i + n * 0.5, x, n * 0.5);
    double upper = pend(n * 0.5, i + 1.0 + n * 0.5, x, n * 0.5);
    if (lower < y && y < upper)
      return i;
  }
  return -1;
}

void solve() {
  int n, m, k;

  scanf("%d%d%d", &n, &m, &k);

  Dinic g(n + m + 10);

  int source = n + m;
  int sink = source + 1;
  for (int i = 0; i < n; ++i)
    g.AddEdge(source, i, 1);

  for (int i = 0; i < m; ++i)
    g.AddEdge(i + n, sink, 1);

  double upp = m + n * 0.5;
  for (int i = 0; i < k; ++i) {
    double x, y;
    scanf("%lf%lf", &x, &y);
    y = upp - y;
    int u = find_x(x, n, m);
    int v = find_y(x, y, n, m);
    g.AddEdge(u, v + n, 1);
  }
  printf("%d\n", (int) g.MaxFlow(source, sink));
}

int main() {
#ifndef LOCAL
  freopen("wall.in", "r", stdin);
#endif

  int t; scanf("%d", &t);
  while(t--) solve();

  return 0;
}
