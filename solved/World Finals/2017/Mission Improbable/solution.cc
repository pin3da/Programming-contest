#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);  debug_out(t...); }
void read() {}
template <typename H, typename... T> void read(H &h, T&... t) { cin >> h; read(t...) ;}
template <typename H, typename... T> void read(vector<H> &h, T&... t) { for (auto &i : h) read(i); read(t...) ;}

#ifndef LOCAL
#define endl '\n'
#define debug(...) //
#else
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#endif

typedef long long LL;

struct edge {
  int u, v;
  LL cap, flow;
  edge() {}
  edge(int u, int v, LL cap): u(u), v(v), cap(cap), flow(0) {}
};

struct dinic {
  int N;
  vector<edge> E;
  vector<vector<int>> g;
  vector<int> d, pt;

  dinic(int N): N(N), E(0), g(N), d(N), pt(N) {}

  void add_edge(int u, int v, LL cap) {
    if (u != v) {
      E.emplace_back(edge(u, v, cap));
      g[u].emplace_back(E.size() - 1);
      E.emplace_back(edge(v, u, 0));
      g[v].emplace_back(E.size() - 1);
    }
  }

  bool bfs(int S, int T) {
    queue<int> q({S});
    fill(d.begin(), d.end(), N + 1);
    d[S] = 0;
    while(!q.empty()) {
      int u = q.front(); q.pop();
      if (u == T) break;
      for (int k: g[u]) {
        edge &e = E[k];
        if (e.flow < e.cap && d[e.v] > d[e.u] + 1) {
          d[e.v] = d[e.u] + 1;
          q.emplace(e.v);
        }
      }
    }
    return d[T] != N + 1;
  }

  LL dfs(int u, int T, LL flow = -1) {
    if (u == T || flow == 0) return flow;
    for (int &i = pt[u]; i < int(g[u].size()); ++i) {
      edge &e = E[g[u][i]];
      edge &oe = E[g[u][i]^1];
      if (d[e.v] == d[e.u] + 1) {
        LL amt = e.cap - e.flow;
        if (flow != -1 && amt > flow) amt = flow;
        if (LL pushed = dfs(e.v, T, amt)) {
          e.flow += pushed;
          oe.flow -= pushed;
          return pushed;
        }
      }
    }
    return 0;
  }

  LL max_flow(int S, int T) {
    LL total = 0;
    while (bfs(S, T)) {
      fill(pt.begin(), pt.end(), 0);
      while (LL flow = dfs(S, T))
        total += flow;
    }
    return total;
  }
};

void solve() {
  int n, m; cin >> n >> m;
  vector<vector<long long>> g(n, vector<long long>(m));
  read(g);

  long long total = 0, non_zero = 0;
  vector<long long> max_row(n), max_col(m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (g[i][j] != 0) {
        total += g[i][j];
        non_zero++;
      }
      max_row[i] = max(max_row[i], g[i][j]);
      max_col[j] = max(max_col[j], g[i][j]);
    }
  }

  int source = n + m;
  int sink = source + 1;
  dinic flow(sink + 10);

  for (int i = 0; i < n; i++) {
    if (max_row[i] > 1) {
      for (int j = 0; j < m; j++) {
        if ((max_row[i] == max_col[j]) && (g[i][j] != 0)) {
          flow.add_edge(i, n + j, 1);
        }
      }
      flow.add_edge(source, i, 1);
    }
  }

  for (int j = 0; j < m; j++) {
    if (max_col[j] > 1)
      flow.add_edge(n + j, sink, 1);
  }

  flow.max_flow(source, sink);

  for (auto id : flow.g[source]) {
    auto e = flow.E[id];
    if (e.flow == 0) {
      non_zero += max_row[e.v] - 1;
    }
  }

  for (int j = 0; j < m; j++) {
    if (max_col[j] > 1)
      non_zero += max_col[j] - 1;
  }
  cout << total - non_zero << endl;
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

