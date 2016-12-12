#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

const int MN = 123;
int d[MN][MN], p[MN][MN];

typedef pair<int, int> state;

int dx[] = {-1, 0, 1, 0};
int dy[] = { 0, 1, 0, -1};
string inst[] = {"UP", "RIGHT", "DOWN", "LEFT"};

const int inf = 123456;
void  bfs(vector<vector<char> > &g, int x, int y) {
  int n = g.size();
  for (int i = 0; i < MN; ++i)
    for (int j = 0; j < MN; ++j) {
      d[i][j] = inf;
      p[i][j] = -1;
    }

  d[x][y] = 0;
  p[x][y] = -1;
  deque<state> q;
  q.push_back(make_pair(x, y));
  while (!q.empty()) {
    state cur = q.front();q.pop_front();
    for (int i = 0; i < 4; ++i) {
      int nx = cur.first + dx[i],
          ny = cur.second + dy[i];
      if (nx >= 0 && nx < n && ny >= 0
          && ny < n && (d[nx][ny] == inf)) {

        d[nx][ny] = d[cur.first][cur.second] + 1;
        p[nx][ny] = i;
        q.push_back(make_pair(nx, ny));
      }
    }
  }
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif
  int n;
  cin >> n;
  vector<vector<char> > g(n, vector<char>(n));
  int s_x = 0, s_y = 0, e_x = 0, e_y = 0;
  cin >> s_x >> s_y;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      cin >> g[i][j];
      if (g[i][j] == 'm') {
        s_x = i;
        s_y = j;
      } else if (g[i][j] == 'p') {
        e_x = i;
        e_y = j;
      }
    }

  bfs(g, s_x, s_y);
  deque<string> ans;
  int x = e_x, y = e_y;
  while (p[x][y] != -1) {
    ans.push_front(inst[p[x][y]]);
    int nx = x - dx[p[x][y]];
    int ny = y - dy[p[x][y]];
    x = nx;
    y = ny;
  }


  // for (int i = 0; i < (int)ans.size(); ++i)
  //  cout << ans[i] << endl;
  cout << ans[0] << endl;

  return 0;
}
