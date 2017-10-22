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

