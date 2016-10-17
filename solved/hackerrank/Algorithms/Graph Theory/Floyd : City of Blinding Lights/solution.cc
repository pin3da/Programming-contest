#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

const int MN = 444;

long long g[MN][MN];
const long long inf = 1LL << 40;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m;
  while (cin >> n >> m) {
    for (int i = 0; i < MN; ++i) {
      for (int j = 0; j < MN; ++j) {
        g[i][j] = inf;
      }
      g[i][i] = 0;
    }
    for (int i = 0; i < m; ++i) {
      int u, v, w;cin >> u >> v >> w;
      u--;v--;
      g[u][v] = w;
    }
    for (int k = 0; k < n; ++k)
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
          g[i][j] = min(g[i][j], g[i][k] + g[k][j]);

    int q; cin >> q;
    while (q--) {
      int u, v; cin >> u >> v;
      u--;v--;
      if (g[u][v] < inf)
        cout << g[u][v] << endl;
      else
        cout << -1 << endl;
    }
  }

  return 0;
}
