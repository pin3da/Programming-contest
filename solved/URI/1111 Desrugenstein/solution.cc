#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

struct st {
  int x, y, d;
  st () {}
  st (int a, int b, int c) : x(a), y(b), d(c) {}
};

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int bfs(vector<vector<int>> &g, int a, int b, int c, int d) {
  queue<st> q;
  int n = g.size();
  vector<vector<int>> seen(n, vector<int> (n));
  q.push(st(a, b, 0));
  while (!q.empty()) {
    int x = q.front().x,
        y = q.front().y,
        dist = q.front().d;
    q.pop();
    if (x == c && y == d)
      return dist;
    if (seen[x][y]) continue;
    seen[x][y] = true;
    for (int i = 0; i < 4; ++i) {
      if (g[x][y * 4 + i]) {
        int nx = x + dx[i],
            ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < n
            && !seen[nx][ny]) {
          q.push(st(nx, ny, dist + 1));
        }
      }
    }
  }
  return 2000;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n && n) {
    vector<vector<int>> g(n, vector<int>(4 * n));
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < 4 * n; ++j)
        cin >> g[i][j];

    int q; cin >> q;
    while (q--) {
      int a, b, c, d;
      cin >> a >> b >> c >> d;
      int dist = bfs(g, n -  1 - b, a, n - 1 - d, c);
      if (dist < 1000) {
        cout << dist << endl;
      } else {
        cout << "Impossible" << endl;
      }
    }
    cout << endl;
  }
  return 0;
}
