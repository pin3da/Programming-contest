#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);  debug_out(t...); }
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int bfs(vector<vector<char>> &g, vector<vector<int>> &ti, int sx, int sy) {
  int n = g.size(), m = g[0].size();
  deque<pair<int, int>> q;
  vector<vector<int>> vi(n, vector<int>(m, m * n + 100));
  q.emplace_back(sx, sy);
  vi[sx][sy] = 0;
  ti[sx][sy] = 0;
  int total = 1;
  while (q.size()) {
    int x = q.front().first, y = q.front().second;
    q.pop_front();
    for (int k = 0; k < 4; k++) {
      int nx = x + dx[k], ny = y + dy[k];
      if (nx >= 0 && nx < n && ny >= 0 && ny < m && g[nx][ny] != '#') {
        if (vi[nx][ny] > (vi[x][y] + 1)) {
          ti[nx][ny] = total;
          vi[nx][ny] = vi[x][y] + 1;
          q.emplace_back(nx, ny);
          total++;
        }
      }
    }
  }
  return total;
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#endif

  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<char>> g(n, vector<char>(m));
  for (auto &row : g)
    for (auto &it : row)
      cin >> it;

  const int inf = n * m + 100;
  vector<vector<int>> vi(n, vector<int>(m, inf));

  int total = -1;
  for (int i = 0; i < n && total < 0; i++)
    for (int j = 0; j < m && total < 0; j++)
      if (g[i][j] == '.') {
        total = bfs(g, vi, i, j);
      }

  int target = total - k;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (vi[i][j] == inf) cout << "#";
      else if (vi[i][j] >= target) cout << "X";
      else  cout << ".";
    }
    cout << endl;
  }

  return 0;
}

