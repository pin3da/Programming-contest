#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);  debug_out(t...); }
void read() {}
template <typename H, typename... T> void read(H &h, T&... t) { cin >> h; read(t...) ;}

#ifndef LOCAL
#define endl '\n'
#define debug(...) //
#else
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#endif

struct crane {
  int w, s;
};

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
  vector<map<int, int>> id_edge;

  Dinic(int N): N(N), E(0), g(N), d(N), pt(N), id_edge(N) {}

  void AddEdge(int u, int v, LL cap) {
    if (u != v) {
      E.emplace_back(Edge(u, v, cap));
      g[u].emplace_back(E.size() - 1);

      id_edge[u][v] = g[u].back();

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

void solve() {
  int n; cin >> n;
  vector<crane> cranes(n);
  for (auto &i : cranes) cin >> i.w >> i.s;

  int m; cin >> m;
  vector<int> buildings(m);
  for (auto &i : buildings) cin >> i;

  int nodes = 2 * n + m;
  int source = nodes;
  int sink = nodes + 1;

  Dinic g(nodes + 10);

  for (int i = 0; i < n; i++) {

    g.AddEdge(i, n + i, 1);

    if (cranes[i].w == 0) { // start
      g.AddEdge(source, i, 1);
    }

    for (int j = 0; j < n; j++)
      if (cranes[j].w <= cranes[i].s)  //i can lift j
        g.AddEdge(n + i, j, 1);

    for (int j = 0; j < m; j++) {
      if (buildings[j] <= cranes[i].s)
        g.AddEdge(n + i, 2 * n + j, 1);
    }

  }

  for (int i = 0; i < m; i++) {
    g.AddEdge(2 * n + i, sink, 1);
  }

  vector<int> output_nodes;
  output_nodes.push_back(source);
  for (int i = 0; i < n; i++)
    output_nodes.push_back(i + n);

  if (g.MaxFlow(source, sink) == m) {
    for (int i = 0; i < m; i++) {
      deque<int> ans;
      int node = 2 * n + i;
      while (node != source) {
        for (auto out : output_nodes) {
          if (g.id_edge[out].count(node)) {
            int id = g.id_edge[out][node];
            Edge &e = g.E[id];
            if (e.flow == 1) {
              if (out != source) {
                node = out - n;
                ans.push_front(node);
              } else
                node = out;
              break;
            }
          }
        }
      }
      for (int i = 0; i < int(ans.size()); i++) {
        if (i) cout << " ";
        cout << ans[i] + 1;
      }
      cout << endl;
    }
  } else {
    cout << "impossible" << endl;
  }
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  //int tc; cin >> tc;
  //while (tc--)
  solve();
  return 0;
}

