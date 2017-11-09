#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

struct point {
  int x, y;
};

bool adj(point a, point b) {
  int dx = abs(a.x - b.x);
  int dy = abs(a.y - b.y);
  if (dx == 0 && dy == 1) return true;
  if (dx == 1 && dy == 0) return true;
  return false;
}

typedef vector<vector<int>> graph;

void dfs(graph &g, vector<int> &col, int node, int c) {
  if (col[node] == -1) {
    col[node] = c;
    for (auto to: g[node]) {
      if (col[to] == -1)
        dfs(g, col, to, c ^ 1);
    }
  }
}

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



int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  int n;

  while (cin >> n) {
    vector<point> all(n);
    for (auto &i : all) cin >> i.x >> i.y;
    Dinic flow(n + 10);
    graph g(n);
    int source = n, sink = n + 1;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (adj(all[i], all[j])) {
          g[i].push_back(j);
          g[j].push_back(i);
        }
      }
    }
    vector<int> color(n, -1);
    int ans = 0;
    dfs(g, color, 0, 0);
    for (int i = 0; i < n; i++) {
      if (color[i] == 0) {
        flow.AddEdge(source, i, 1);
        for (auto to: g[i])
          flow.AddEdge(i, to, 1);
      } else {
        flow.AddEdge(i, sink, 1);
      }
    }
    cout << n - flow.MaxFlow(source, sink) << endl;
  }
  return 0;
}
