using namespace std;
#include <bits/stdc++.h>
#define D(x)  cout << #x " = " << (x) << endl

void dfs(vector<vector<int> > &g, vector<bool> &vi, int cur, long long &e, long long &n) {
  if (vi[cur])
    return;
  vi[cur] = true;
  n++;
  for (int i = 0; i < g[cur].size(); ++i) {
      e++;
      dfs(g, vi, g[cur][i], e, n);
  }
}

int main() {
  long long n, m, r, e;
  cin >> n >> m >> r >> e;
  vector<vector<int> > g(n);
  int u, v;
  for (int i = 0; i < m; ++i) {
    cin >> u >> v;
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vector<bool> visited(n);
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    if (!visited[i]) {
      long long edges = 0, nodes = 0;
      dfs(g, visited, i, edges, nodes);
      edges >>= 1;
      ans += min( (( (nodes * (nodes - 1 ) ) >> 1) - edges) * r, nodes * e);
    }
  }
  cout << ans << endl;
  return 0;
}
