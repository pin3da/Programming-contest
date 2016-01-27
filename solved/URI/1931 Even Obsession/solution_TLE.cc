#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

const long long inf = 1000000000;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<vector<long long>> g(n, vector<long long>(n, inf));
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    u--;v--;
    g[u][v] = min<long long>(g[u][v], w);
    g[v][u] = min<long long>(g[v][u], w);
  }

  vector<vector<long long>> g2(n, vector<long long>(n, inf));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      for (int k = 0; k < n; ++k)
        g2[i][k] = min(g2[i][k], g[i][j] + g[j][k]);


  for (int k = 0; k < n; ++k)
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        g2[i][j] = min(g2[i][j], g2[i][k] + g2[k][j]);

  if (g2[0][n - 1] < inf)
    cout << g2[0][n - 1] << endl;
  else
    cout << -1 << endl;
  return 0;
}
