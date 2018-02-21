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

const long long max_weight = 3e6;


void solve() {
  int n, m;
  read(n, m);
  vector<map<int, int>> edges(n);
  int ok = true;
  graph g(n);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    read(u, v, w);
    u--; v--;
    if (u > v) swap(u, v);
    if (edges[u].count(v) && edges[u][v] != w)
      ok = false;

    edges[u][v] = w;
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
  }



  for (int i = 0; i < n; i++) {
    auto dist = dijkstra(g, i).second;

    for (auto to : edges[i]) {
      ok &= (dist[to.first] == to.second);
    }
  }

  if (!ok) {
    cout << -1 << endl;
  } else {

    for (int i = 0; i < n; i++) {
      auto dist = dijkstra(g, i).second;

      for (int j = 0; j < n; j++) {
        if (dist[j] == inf) {
          g[i].emplace_back(j, max_weight);
          g[j].emplace_back(i, max_weight);
          m++;
          edges[i][j] = max_weight;
        }
      }
    }

    cout << m << endl;
    for (int i = 0; i < n; i++) {
      for (auto it : edges[i]) {
        cout << i + 1 << " " << it.first + 1 << " " << it.second << endl;
      }
    }
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

