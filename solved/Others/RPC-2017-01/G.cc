#include <bits/stdc++.h>

using namespace std;
const int MN = 555;
const int inf = 1000000;

int g[MN][MN];
int dist[MN][MN];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main() {

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      char t; cin >> t;
      g[i][j] = t - '0';
      dist[i][j] = inf;
    }
  }
  deque<pair<int, int>> q;
  dist[0][0] = 0;
  q.emplace_back(0, 0);
  while (!q.empty()) {
    auto cur = q.front();
    q.pop_front();
    for (int i = 0; i < 4; ++i) {
      int nx = cur.first + dx[i] * g[cur.first][cur.second];
      int ny = cur.second + dy[i] * g[cur.first][cur.second];
      if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
          (dist[cur.first][cur.second] + 1 < dist[nx][ny])) {
        dist[nx][ny] = dist[cur.first][cur.second] + 1;
        q.emplace_back(nx, ny);
      }
    }
  }

  if (dist[n - 1][m - 1] < inf)
    cout << dist[n - 1][m - 1] << endl;
  else
    cout << "IMPOSSIBLE" << endl;

  return 0;
}
