#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

const int MN = 123;
const int MM = 5432;

long long g[MN][MN];
int start[MM], dest[MM];

const int inf = 1e9;

int last_house;

long long dp[MN][MM];

long long go(int node, int house) {
  if (house == last_house)
    return 0;

  if (dp[node][house] != -1)
    return dp[node][house];

  long long op1 = g[node][start[house]]
    + g[start[house]][dest[house]]
    + go(dest[house], house + 1);

  if (house + 1 < last_house) {
    long long op2 = g[node][start[house]]
      + g[start[house]][start[house + 1]]
      + g[start[house + 1]][dest[house]]
      + g[dest[house]][dest[house + 1]]
      + go(dest[house + 1], house + 2);
    op1 = min(op1, op2);
  }

  return dp[node][house] = op1;
}

void solve() {

  for (int i = 0; i < MN; ++i)
    for (int j = 0; j < MN; ++j)
      g[i][j] = inf;

  int n, m, k;
  cin >> n >> m >> k;
  last_house = k;
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    u--;v--;
    g[u][v] = min<long long>(w, g[u][v]);
    g[v][u] = min<long long>(w, g[v][u]);
  }

  for (int i = 0; i < n; ++i) g[i][i] = 0;

  for (int k = 0; k < n; ++k)
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);

  for (int i = 0; i < k; ++i) {
    cin >> start[i] >> dest[i];
    start[i]--;
    dest[i]--;
  }

  memset(dp, -1, sizeof dp);
  long long ans = go(0, 0);
  if (ans < inf)
    cout << ans << endl;
  else
    cout << -1 << endl;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  int tc; cin >> tc;
  for (int i = 0; i < tc; ++i) {
    cout << "Case #" << (i + 1) << ": ";
    solve();
  }
  return 0;
}
