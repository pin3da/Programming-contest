#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

struct edge{
  int from, to;
  edge() {}
  edge(int a, int b) : from(a), to(b) {}
};

typedef  vector<vector<edge>> graph;

int dfs(graph &g, vector<int> &v, int node) {

  v[node] = true;
  int total = 0;
  for (auto e : g[node])
    if (!v[e.to])
      total += dfs(g, v, e.to) + 1;

  return total;
}

void solve() {
  int x; cin >> x;
  int n, m;
  cin >> n >> m;
  edge e;
  graph g(n);
  vector<int> seen(n);
  for (int i = 0; i < m; ++i) {
    cin >> e.from >> e.to;
    g[e.from].push_back(e);
    g[e.to].emplace_back(e.to, e.from);
  }
  cout << dfs(g, seen, x) * 2 << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc; cin >> tc;
  for (int i = 0; i < tc; ++i) {
    solve();
  }
  return 0;
}

