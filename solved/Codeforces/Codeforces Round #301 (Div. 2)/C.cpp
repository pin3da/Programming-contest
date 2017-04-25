// http://codeforces.com/contest/540/problem/C

using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

bool dfs(vector<vector<char> > &g, int xt, int yt, int x, int y) {
  if (g[x][y] == 'X')
    return x == xt && y == yt;

  g[x][y] = 'X';
  int n = g.size();
  int m = g[0].size();
  for (int k = 0; k < 4; ++k) {
    int nx = x + dx[k];
    int ny = y + dy[k];
    if (nx >= 0 && nx  < n && ny >= 0 && ny < m) {
      // g[x][y] = 'X';
      if (dfs(g, xt, yt, nx, ny)) {
        return true;
      }
      // g[x][y] = '.';
    }
  }
  return false;
}

int main() { ___
  int n, m;
  cin >> n >> m;
  vector<vector<char > > g(n, vector<char>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> g[i][j];
    }
  }

  int x, y, xt, yt;
  cin >> x >> y >> xt >> yt;
  x--;y--;xt--;yt--;
  g[x][y] = '.';

  bool reachable  = dfs(g, xt, yt, x, y);
  if (reachable)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;

  return 0;
}
