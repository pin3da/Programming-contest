#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

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

pair<vector<int>, vector<long long>> dijkstra(graph &g, int start) {
  int n = g.size();
  vector<long long> d(n, inf);
  vector<int> p(n, -1);
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
        p[to] = node;
        d[to] = dist + w_extra;
        q.push(edge(to, d[to]));
      }
    }
  }

  return {p, d};
}


int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#define endl '\n'
#endif

  freopen("dining.in", "r", stdin);
  freopen("dining.out", "w", stdout);

  int n, m, k;
  cin >> n >> m >> k;
  graph g(n);

  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--; v--;
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
  }

  multiset<pair<long long, int>> best;
  for (int i = 0; i < k; i++) {
    long long y;
    int node;
    cin >> node >> y;
    node--;
    best.insert({y, node});
  }

  vector<int> gain(n);

  while (best.size()) {
    auto pCur = best.begin();
    auto cur = *pCur;
    best.erase(pCur);

    gain[cur.second] = cur.first;

    for (auto e : g[cur.second]) {
      if (e.w * 2 <= cur.first) {
        long long extra = cur.first - (e.w * 2);
        if (gain[e.to] < extra) {
          gain[e.to] = extra;
          best.insert({extra, e.to});
        }
      }
    }
  }

  auto dist = dijkstra(g, n - 1).second;
  if (gain[n-1]) {
    for (int i = 0; i < n - 1; i++) {
      cout << 1 << endl;
    }
  } else {
     for (int i = 0; i < n - 1; i++) {
      cout << (gain[i] > 0) << endl;
    }
  }

  return 0;
}
