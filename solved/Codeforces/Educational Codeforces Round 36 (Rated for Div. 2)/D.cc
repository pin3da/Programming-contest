#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x " = " << (x) << endl

typedef vector<vector<int>> graph;

pair<int, int> in_cycle;
const int MN = 512;
int color[MN];

bool dfs(graph &g, int node) {
  if (color[node] == 0) {
    color[node] = 1;
    int ok = true;
    for (auto to : g[node]) {
      if (color[to] == 0) ok &= dfs(g, to);
      else if (color[to] == 1) {
        in_cycle = make_pair(node, to);
        return false;
      }
    }
    color[node] = 2;
    return ok;
  }
  return true;
}

int any_cycle(graph &g) {
  int n = g.size();
  memset(color, 0, sizeof color);
  for (int i = 0; i < n; i++) {
    if (!dfs(g, i))
      return true;
  }
  return false;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif


  int n, m;
  cin >> n >> m;
  graph g(n);

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    g[u - 1].emplace_back(v - 1);
  }

  if (!any_cycle(g)) {
    cout << "YES" << endl;
  } else {
    graph g2(n);
    for (int i = 0; i < n; i++) {
      for (auto j : g[i]) {
        if ((i == in_cycle.first) && (j == in_cycle.second))
          continue;
        g2[i].emplace_back(j);
      }
    }
    if (!any_cycle(g2)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}
