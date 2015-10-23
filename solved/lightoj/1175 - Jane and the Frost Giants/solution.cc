using namespace std;
#include <bits/stdc++.h>

struct pos{
  int x, y;
  pos() {}
  pos(int a, int b) : x(a), y(b) {}
};

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

vector<vector<int> > bfs(vector<vector<char> > &g, vector<pos> &s, vector<vector<int> > &fi) {
  int n = g.size(), m = g[0].size();
  vector<vector<int> > ans(g.size(), vector<int> (g[0].size(), -1));
  queue<pos> q;
  for (int i = 0; i < s.size(); ++i) {
    ans[s[i].x][s[i].y] = 0;
    q.push(s[i]);
  }
  while (!q.empty()) {
    pos cur = q.front(); q.pop();
    for (int i = 0; i < 4; ++i) {
      int nx = cur.x + dx[i];
      int ny = cur.y + dy[i];
      if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
          g[nx][ny] != '#' && ans[nx][ny] == -1 &&
          (fi.size() == 0 || fi[nx][ny] > ans[cur.x][cur.y] + 1
           || fi[nx][ny] == -1)) {
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
  vector<pos> F, J;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> g[i][j];
      if (g[i][j] == 'F')
        F.push_back(pos(i, j));
      if (g[i][j] == 'J')
        J.push_back(pos(i, j));
    }
  }

  vector<vector<int> > tmp;
  vector<vector<int> > df = bfs(g, F, tmp);
  vector<vector<int> > dj = bfs(g, J, df);
  /*cout << endl;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << dj[i][j] << "\t";
    }
    cout << endl;
  }*/

  int ans = 1000;
  for (int i = 0; i < n; ++i) {
    if (dj[i][0] >= 0)      ans = min(ans, dj[i][0] + 1);
    if (dj[i][m - 1] >= 0)  ans = min(ans, dj[i][m - 1] + 1);
  }

  for (int i = 0; i < m; ++i) {
    if (dj[0][i] >= 0)      ans = min(ans, dj[0][i] + 1);
    if (dj[n - 1][i] >= 0)  ans = min(ans, dj[n - 1][i] + 1);
  }

  if (ans < 1000)
    printf("%d\n", ans);
  else
    puts("IMPOSSIBLE");
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}
