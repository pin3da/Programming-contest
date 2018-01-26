#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x " = " << (x) << endl

const long long inf = 1e9;

struct edge {
  int u, v, w;
  edge () {}
  edge (int a, int b) : v(a), w(b) {}
  edge (int a, int b, int c) : u(a), v(b), w(c) {}
  bool operator < (const edge &o) const {
    return w > o.w;
  }
};

typedef vector<vector<edge>> graph;

vector<long long> dijkstra(graph &g, int s) {
  int n = g.size();
  vector<long long> dist(n, inf);

  priority_queue<edge> q;
  dist[s] = 0;
  q.push(edge(s, 0));

  while (!q.empty()) {
    int cur = q.top().v;
    long long cur_w = q.top().w;
    q.pop();

    if (cur_w > dist[cur]) continue;

    for (auto e : g[cur]) {
      int to = e.v;
      long long w_extra = e.w;
      if (dist[cur] + w_extra < dist[to]) {
        dist[to] = dist[cur] + w_extra;
        q.push(edge(to, dist[to]));
      }
    }
  }

  return dist;
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
    for (int &i = pt[u]; i < int(g[u].size()); ++i) {
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

  int n, m, c;
  cin >> n >> m >> c;
  graph g(n);
  vector<edge> edges;

  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    g[u].emplace_back(u, v, w);
    g[v].emplace_back(v, u, w);
    edges.emplace_back(v, u, w);
  }

  vector<int> start(c);
  for (auto &i : start) {
    cin >> i;
    i--;
  }

  vector<long long> dist = dijkstra(g, 0);
  map<long long, vector<int>> groups;
  for (auto car : start) {
    groups[dist[car]].push_back(car);
  }

  Dinic flow(n + 10), cur_flow(n + 10);
  for (auto &e : edges) {
    if (dist[e.u] + e.w == dist[e.v])
      flow.AddEdge(e.v, e.u, 1);
    if (dist[e.v] + e.w == dist[e.u])
      flow.AddEdge(e.u, e.v, 1);
  }

  int sink = n;
  long long ans = 0;
  for (auto &g : groups) {
    cur_flow = flow;
    for (auto car : g.second) {
      cur_flow.AddEdge(sink, car, 1);
    }
    ans += cur_flow.MaxFlow(sink, 0);
  }

  cout << ans << endl;

  return 0;
}
