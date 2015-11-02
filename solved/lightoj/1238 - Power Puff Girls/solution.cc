using namespace std;
#include <bits/stdc++.h>

const int inf = 20 * 20 * 20;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int bfs(vector<vector<char> > &g, int i, int j) {
  int n = g.size(), m = g[0].size();
  vector<vector<int> > dist(n, vector<int>(m, inf));
  queue<pair<int, int> > q;
  q.push(make_pair(i, j));
  dist[i][j] = 0;
  while (!q.empty()) {
    int x = q.front().first,
        y = q.front().second;
    q.pop();

    if (g[x][y] == 'h')
      return dist[x][y];

    for (int k = 0; k < 4; ++k) {
      int nx = x + dx[k],
          ny = y + dy[k];
      if (nx >= 0 && nx < n && ny >= 0 && ny < m
          && g[nx][ny] != '#' && g[nx][ny] != 'm'
          && dist[nx][ny] == inf) {
        dist[nx][ny] = dist[x][y] + 1;
        q.push(make_pair(nx, ny));
      }
    }
  }
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<char> > g(n, vector<char> (m));
  int ax, ay, bx, by, cx, cy;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> g[i][j];
      if (g[i][j] == 'a')
        ax = i, ay = j;
      if (g[i][j] == 'b')
        bx = i, by = j;
      if (g[i][j] == 'c')
        cx = i, cy = j;
    }
  }

  int best = 0;
  best = max(best, bfs(g, ax, ay));
  best = max(best, bfs(g, bx, by));
  best = max(best, bfs(g, cx, cy));
  printf("%d\n", best);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc; cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}
