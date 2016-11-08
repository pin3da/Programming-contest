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

int s, t, m, n;
void do_graph(Dinic & mf, vector<pair<int,int> > & edges, int mid){
  for (int i = 1; i <= m; i++) {
    mf.AddEdge(s, i, 1);
  }
  for (int i = 0; i < m; i++) {
    mf.AddEdge(i + 1, edges[i].first + m, 1);
    mf.AddEdge(i + 1, edges[i].second + m, 1);
  }

  for(int i = 0; i < n; i++) {
    mf.AddEdge(m + i + 1, t, mid);
  }
}

int main(){
  int u, v;
  while(cin >> n >> m) {
    s = 0, t = n + m + 5;
    vector<pair<int,int> > edges(m);
    for (int i = 0; i < m; i++) {
      cin >> edges[i].first >> edges[i].second;
    }
    int lo = 0, hi = 100000;
    while (hi - lo > 1) {
      Dinic mf(n + m + 10);
      int mid = (hi + lo) >> 1;
      do_graph(mf, edges, mid);
      int flow = mf.MaxFlow(s, t);
      if (flow >= m) {
        hi = mid;
      }else {
        lo = mid + 1;
      }
    }
    Dinic mf(n + m + 10);
    do_graph(mf, edges, lo);
    int flow = mf.MaxFlow(s, t);
    if (flow >= m)
      cout << lo << endl;
    else
      cout << hi << endl;
  }

  return 0;
}

