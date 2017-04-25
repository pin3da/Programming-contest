// http://codeforces.com/contest/659/problem/E

#include <bits/stdc++.h>

#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'
using namespace std;

typedef  vector<vector<int>> graph;

const int MN  = 100000 + 100 + 10 + 1;
int p[MN];

int fs(int x) {
  return (p[x] == x) ? x : p[x] = fs(p[x]);
}

void js(int x, int y) {
  p[fs(x)] = fs(y);
}

void dfs(graph &g, vector<int> &vi, int node) {
  if (vi[node]) return;
  vi[node] = true;
  for (auto &to : g[node])
    dfs(g, vi, to);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m;
  while (cin >> n >> m) {
    graph g(n);
    vector<pair<int, int>> edges(m);
    int u, v;
    for (int i = 0; i < m; ++i) {
      cin >> u >> v;
      u--;v--;
      g[u].emplace_back(v);
      g[v].emplace_back(u);
      edges[i] = make_pair(u, v);
    }

    vector<int> vi(n);
    for (int i = 0; i < n + 10; ++i) p[i] = i;

    for (int i = 0; i < m; ++i) {
      u = edges[i].first;
      v = edges[i].second;
      if (fs(u) == fs(v)) {
        if (!vi[u])
          dfs(g, vi, u);
      }
      js(u, v);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (!vi[i]) {
        ans++;
        dfs(g, vi, i);
      }
    }
    cout << ans << endl;
  }
  return 0;
}
