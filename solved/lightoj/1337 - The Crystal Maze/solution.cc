using namespace std;
#include <bits/stdc++.h>

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int dfs(vector<vector<char> > &g, vector<vector<int> > &color, int x, int y, int cur) {
  if (color[x][y] != -1)
    return 0;

  color[x][y] = cur;
  int ans = g[x][y] == 'C';
  for (int k = 0; k < 4; ++k) {
    int nx = x + dx[k];
    int ny = y + dy[k];
    if (nx >= 0 && nx < g.size() && ny >= 0 && ny < g[0].size()
          && g[nx][ny] != '#' && color[nx][ny] == -1)
    ans += dfs(g, color, nx, ny, cur);
  }
  return ans;
}

void solve() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<char> > g(n, vector<char>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> g[i][j];
    }
  }

  vector<vector<int> > color(n, vector<int>(m, -1));
  vector<int> ans(n * m, 0);
  int cur = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (color[i][j] == -1) {
        ans[cur] = dfs(g, color, i, j, cur);
        cur++;
      }
    }
  }
  int a, b;
  for (int i = 0; i < q; ++i) {
    cin >> a >> b;
    a--;b--;
    printf("%d\n", ans[color[a][b]]);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d:\n", i + 1);
    solve();
  }
  return 0;
}
