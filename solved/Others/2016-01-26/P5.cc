#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(vector<vector<char>> &g, vector<vector<int>> &vi, int x, int y, char T) {
  if (x < 0 || x >= g.size() || y < 0 || y >= g[0].size())
    return;
  if (vi[x][y] || g[x][y] == 'X')
    return;

  vi[x][y] = true;
  g[x][y] = T;
  for (int i = 0; i < 4; ++i)
    dfs(g, vi, x + dx[i], y + dy[i], T);

}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m;
  while (cin >> n >> m && (n + m)) {
    vector<vector<char>> g(n, vector<char>(m));
    for (auto &i : g)
      for (auto &j : i)
        cin >> j;

    vector<vector<int>> vi(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        if (!vi[i][j] && g[i][j] == 'T')
          dfs(g, vi, i, j, 'T');

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cout << g[i][j];
      }
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}
