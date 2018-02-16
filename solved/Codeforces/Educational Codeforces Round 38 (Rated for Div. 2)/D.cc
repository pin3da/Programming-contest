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
  int to; long long w;
  edge (int a, long long c) : to(a), w(c) {}
};

typedef vector<vector<edge>> graph;

void add_edge(graph &g, int u, int v, long long w) {
  g[u].emplace_back(v, w);
  g[v].emplace_back(u, w);
}

const int MN = 300000 + 1000;

long long best[MN];
bool used[MN];

void solve() {
  int n, m;
  cin >> n >> m;
  graph g(n);

  for (int i = 0; i < m; i++) {
    int u, v; long long w;
    cin >> u >> v >> w;

    add_edge(g, u - 1, v - 1, w);
  }

  set<pair<long long, int>> q;
  for (int i = 0; i < n; i++) {
    cin >> best[i];
    q.insert(make_pair(best[i], i));
  }

  while (!q.empty()) {
    auto cur = q.begin();
    long long cur_w = cur->first;
    int node = cur->second;
    q.erase(cur);

    used[node] = 1;

    for (auto e: g[node]) {
      int to = e.to;
      long long tmp = 2LL * e.w + cur_w;
      if (tmp < best[to] && !used[to]) {
        q.erase(make_pair(best[to], to));
        best[to] = tmp;
        q.insert(make_pair(best[to], to));
      }
    }
  }

  for (int i = 0; i < n; i++) {
    cout << best[i] << " ";
  }
  cout << endl;
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

