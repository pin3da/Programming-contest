using namespace std;
#include <bits/stdc++.h>

struct pos{
  int x, y;
  pos() {}
  pos(int a, int b) : x(a), y(b) {}
};

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

vector<vector<int> > bfs(vector<vector<char> > &g, pos &s) {
  int n = g.size(), m = g[0].size();
  vector<vector<int> > ans(g.size(), vector<int> (g[0].size(), -1));
  ans[s.x][s.y] = 0;
  queue<pos> q;
  q.push(s);
  while (!q.empty()) {
    pos cur = q.front(); q.pop();
    for (int i = 0; i < 4; ++i) {
      int nx = cur.x + dx[i];
      int ny = cur.y + dy[i];
      if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
          g[nx][ny] != '#' && ans[nx][ny] == -1) {
        ans[nx][ny] = ans[cur.x][cur.y] + 1;
        q.push(pos(nx, ny));
      }
    }
  }
  return ans;
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<char> > g(n, vector<char>(m));
  pos F, J;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> g[i][j];
      if (g[i][j] == 'F')
        F.x = i, F.y = j;
      if (g[i][j] == 'J')
        J.x = i, J.y = j;
    }
  }

  vector<vector<int> > df = bfs(g, F);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << df[i][j] << " ";
    }
    cout << endl;
  }

}

int main() {
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}
