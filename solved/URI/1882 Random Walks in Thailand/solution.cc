// The test cases aren't ok. Waiting to rejudge.


#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

struct edge {
  int u, v;
  long long w;
  edge(int a, int b, long long c) : u(a), v(b), w(c) {}
  edge(int a, long long b) : u(0), v(a), w(b) {}
  bool operator < (const edge &o) const {
    return w > o.w;
  }
};

typedef vector<vector<edge>> graph;

const long long inf = 1000000000;
long long dijkstra(graph &g, int s, int t) {
  vector<long long> d(g.size(), inf);
  d[s] = 0;
  priority_queue<edge> q;
  q.push(edge(s, 0));
  while (!q.empty()) {
    int cur  = q.top().v;
    long long dist = q.top().w;
    q.pop();

    if (dist > d[cur]) continue;
    for (int i = 0; i < g[cur].size(); ++i) {
      int to = g[cur][i].v;
      long long w_extra = g[cur][i].w;
      if (dist + w_extra < d[to]) {
        d[to] = dist + w_extra;
        q.push(edge(to, d[to]));
      }
    }
  }
  return d[t];
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int t; cin >> t;
  cout << fixed << setprecision(3);
  while (t--) {
    int n, m, k; cin >> n >> m >> k;
    graph g(n + 10);
    for (int i = 0; i < m; ++i) {
      long long u, v, w; cin >> u >> v >> w;
      g[u].emplace_back(u, v, w);
      g[v].emplace_back(v, u, w);
    }
    cout << (double)min<long long>(dijkstra(g, 0, n - 1), n * k) << endl;
  }
  return 0;
}
