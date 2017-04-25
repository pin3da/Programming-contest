// http://codeforces.com/contest/60/problem/B

#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

typedef vector<vector<vector<char>>> ma;
typedef vector<vector<vector<int>>> mp;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int dz[] = {1, -1};


void dfs(ma &g, mp &vi, int x, int y, int z) {
  if (z < 0 || z >= g.size()) return;
  if (x < 0 || x >= g[0].size()) return;
  if (y < 0 || y >= g[0][0].size()) return;

  if (g[z][x][y] == '#') return;

  if (vi[z][x][y]) return;
  vi[z][x][y] = true;
  for (int i = 0; i < 2; ++i)
    dfs(g, vi, x, y, z + dz[i]);

  for (int i = 0; i < 4; ++i)
    dfs(g, vi, x + dx[i], y + dy[i], z);

}

void solve(int d) {
  int n, m;
  cin >> n >> m;
  ma g(d);
  mp vi(d);
  for (int i = 0; i < d; ++i) {
    g[i] = vector<vector<char>> (n, vector<char> (m));
    vi[i] = vector<vector<int>> (n, vector<int> (m));
    for (auto &j : g[i]) for (auto &k : j) cin >> k;
  }
  int x, y;
  cin >> x >> y;
  x--;y--;
  dfs(g, vi, x, y, 0);

  int ans = 0;
  for (int i = 0; i < d; ++i) {
    for (auto &j : vi[i]) for (auto &k : j) ans += k;
  }
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n; while (cin >> n)  solve(n);
  return 0;
}
