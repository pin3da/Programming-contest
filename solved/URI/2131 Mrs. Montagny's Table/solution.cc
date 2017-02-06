#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

typedef vector<vector<int>> graph;

bool dfs(graph &g, vector<int> col, int node, int c) {
  if (col[node] != -1)
    return col[node] == c;

  col[node] = c;
  for (int to : g[node]) {
    if (!dfs(g, col, to, c ^ 1))
      return false;
  }
  return true;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  int n, m;
  int it = 1;
  while (cin >> n >> m) {
    graph g(n);
    while (m--) {
      int u, v; cin >> u >> v;
      u--;v--;
      g[u].push_back(v);
      g[v].push_back(u);
    }

    vector<int> c(n, -1);
    int ok = true;
    for (int i = 0; i < n; ++i) {
      if (c[i] == -1)
        ok &= dfs(g, c, i, 0);
    }
    cout << "Instancia " << it++ << endl;
    cout << (ok ? "sim" : "nao") << endl;
    cout << endl;
  }

  return 0;
}

