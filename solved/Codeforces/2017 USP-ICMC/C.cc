#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

const int MN = 100055;
long long ans[20];
long long temp[MN][20];
long long shi[MN];

typedef vector<vector<int>> graph;

void dfs(graph &g, int node, int level) {
  temp[node][level] += shi[node];
  for (auto to : g[node]) {
    dfs(g, to, level + 1);
    for (int i = level + 1; i < 20; i++)
      temp[node][i] += temp[to][i];
  }
  ans[level] += temp[node][level];
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n, m, w;
  cin >> n >> m >> w;
  shi[0] = w;
  graph g(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--;v--;
    g[v].push_back(u);
    shi[u] = w;
  }

  dfs(g, 0, 0);

  while (m--) {
    int u; cin >> u;
    u--;
    for (int i = 0; i < 20; i++)
      ans[i] -= temp[u][i];
    long long best = 0;
    for (int i = 0; i < 20; i++)
      best = max(best, ans[i]);
    cout << best << endl;
    for (int i = 0; i < 20; i++)
      ans[i] += temp[u][i];
  }

  return 0;
}
