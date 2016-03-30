#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;
struct edge {
  int to;
  long long w;
  edge() {}
  edge(int a, long long b): to(a), w(b) {}
};

struct st {
  int node, dist;
  long long cost;
  st() {}
  st(int n, int d, long long c) :
    node(n), dist(d), cost(c) {}

  bool operator < (const st &o ) const {
    if (dist == o.dist) {
      if (cost == o.cost)
        return node > o.node;
      return cost > o.cost;
    }
    return dist > o.dist;
  }
};

typedef vector<vector<edge>> graph;

const long long inf = 1LL << 50;
long long dijkstra(graph &g, int k) {
  vector<long long> d(g.size(), inf);
  priority_queue<st> q;
  q.push(st(0, 1, 0));
  while (!q.empty()) {
    int node  = q.top().node,
        dist  = q.top().dist;
    long long cost = q.top().cost;
    q.pop();

    if (cost < d[node]) {
      d[node] = cost;

      for (int i = 0; i < g[node].size(); ++i) {
        int to = g[node][i].to;
        long long n_cost = cost + g[node][i].w;
        if (dist < k) {
          q.push(st(to, dist + 1, n_cost));
        }
      }
    }
  }
  return d[g.size() - 1];
}

long long bellman(graph &g, int k) {
  vector<long long> d(g.size(), inf);
  vector<long long> dn(g.size(), inf);
  d[0] = 0;
  for (int j = 0; j < k - 1; ++j) {
    for (int i = 0; i < g.size(); ++i) {
      for (auto & e : g[i]) {
        if (d[i] + e.w < d[e.to]) {
          dn[e.to] = d[i] + e.w;
        }
      }
    }
    for (int i = 0; i < dn.size(); ++i)
      d[i] = min(dn[i], d[i]);
  }
  return d[g.size() - 1];
}

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  graph g(n);
  int u, v;
  long long w;
  for (int i = 0; i < m; ++i) {
    cin >> u >> v >> w;
    g[u].emplace_back(v, w);
  }
  long long ans = dijkstra(g, k);
  //long long ans = bellman(g, k);
  if (ans < inf)
    cout << ans << endl;
  else
    cout << -1 << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
