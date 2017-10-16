#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

struct edge {
  int to;
  long long w;
  edge () {}
  edge (int a, long long b) : to(a), w(b) {}
  bool operator < (const edge &o) const {
    return w > o.w;
  }
};

typedef vector<vector<edge>> graph;

const long long inf = 1000000LL * 10000000LL;

vector<long long> dijkstra(graph &g, int start) {
  int n = g.size();
  vector<long long> d(n, inf);
  d[start] = 0;
  priority_queue<edge> q;
  q.push(edge(start, 0));

  while (!q.empty()) {
    int node = q.top().to;
    long long dist = q.top().w;
    q.pop();

    if (dist > d[node]) continue;

    for (int i = 0; i < (int)g[node].size(); i++) {
      int to = g[node][i].to;
      long long w_extra = g[node][i].w;

      if (dist + w_extra < d[to]) {
        d[to] = dist + w_extra;
        q.push(edge(to, d[to]));
      }
    }
  }
  return d;
}


void solve() {
  int n, m, f, s, t;
  cin >> n >> m >> f >> s >> t;
  graph g(n);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
  }

  vector<long long> dist_s = dijkstra(g, s);
  vector<long long> dist_t = dijkstra(g, t);

  long long best = dist_s[t];
  for (int i = 0; i < f; i++) {
    int u, v; cin >> u >> v;
    best = min(best, dist_s[u] + dist_t[v]);
  }
  cout << best << endl;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  solve();
  return 0;
}
