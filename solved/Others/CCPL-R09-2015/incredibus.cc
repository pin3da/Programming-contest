using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

int b, e, m, v;
const int inf = 1000000;

int seen[111][1010];

bool findx(vector<string> &g, int x, int y, int ny) {
  /*for (int i = y; i <= ny; ++i) {
    if (g[x][i] == 'X')
      return true;
  }
  return false;*/

  long long c = seen[x][ny];
  if (y)
    c -= seen[x][y - 1];
  return c > 0;
}


long long dp[111][1010];
long long go(vector<string> &g, int x, int y) {
  if (g.size() - 1 == x) {
    if (abs(y - e) <= v && findx(g, x, min(y, e), max(y, e)) == 0)
      return abs(y - e);
    return inf;
  }

  if (dp[x][y] != -1)
    return dp[x][y];

  long long best = inf;
  for (int i = -v; i <= v; ++i) {
    int ny = y + i;
    if (findx(g, x, min(ny, y), max(ny, y))) continue;
    if (ny >= 0 && ny < g[0].size() && g[x + 1][ny] == '.') {
      best = min(best, go(g, x + 1, ny) + abs(i));
    }
  }
  return dp[x][y] = best;
}

void solve(int n) {
  cin >> b >> e >> m >> v;
  vector<string> g(m);
  for (int i = 0; i < m; ++i) {
    cin >> g[i];
  }

  memset(seen, 0, sizeof seen);

  for (int i = 0; i < g.size(); ++i) {
    for (int j = 0; j < g[i].size(); ++j)
      seen[i][j] = (g[i][j] == 'X');
    for (int j = 1; j < g[i].size(); ++j)
      seen[i][j] += seen[i][j - 1];
  }

  memset(dp, -1, sizeof dp);
  long long ans = go(g, 0, b);
  if (ans < inf)
    cout << ans << endl;
  else
    cout << -1 << endl;
}

int main() {
  // ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n && n) {
    solve(n);
  }

  return 0;
}
