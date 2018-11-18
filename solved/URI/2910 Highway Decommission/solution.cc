#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

const long long inf = 1e12;

struct edge {
  int to;
  long long len, cost;
  bool operator < (const edge & o) const {
    if (len == o.len)
      return cost > o.cost;
    return len > o.len;
  }
};


int my_cmp(const edge &a, const edge &b) {
  if (a < b) return 1; // greater
  if (b < a) return -1;
  return 0;
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#define endl '\n'
#endif

  int n, m;
  cin >> n >> m;
  vector<vector<edge>> g(n);

  for (int i = 0; i < m; i++) {
    int u, v;
    long long l, c;
    cin >> u >> v >> l >> c;
    u--;
    v--;
    g[u].push_back({v, l, c});
    g[v].push_back({u, l, c});
  }

  priority_queue<edge> q;
  q.push({0, 0, 0});

  vector<edge> best(n, {0, inf, inf});
  best[0] = {0, 0, 0};

  vector<long long> cost(n, 0);

  while (!q.empty()) {
    auto s = q.top();
    q.pop();

    int node = s.to;

    if (my_cmp(s, best[node]) == 1) continue;

    for (auto e : g[node]) {
      int to = e.to;
      edge extra = {to, s.len + e.len, e.cost};
      if (my_cmp(extra, best[to]) == -1) {
        best[to] = extra;
        cost[to] = e.cost;
        q.push(extra);
      }
    }
  }

  long long total = 0;
  for (int i = 0; i < n; i++) {
    total += cost[i];
  }
  cout << total << endl;

  return 0;
}
