#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int dx[] = {1, 0, 0, -1};
int dy[] = {0, -1, 1, 0};
string ans[] = {"DOWN", "LEFT", "RIGHT", "UP"};

bool simulate(vector<vector<int>> &g, int i, int j, int nx, int ny) {
  int seen = false;
  if (nx >= 0 && nx < 4 && ny >= 0 && ny < 4) {
    if (g[nx][ny] == 0 || (g[nx][ny] == g[i][j])) {
      seen = true;
      g[nx][ny] += g[i][j];
      g[i][j] = 0;
    }
  }
  return seen;
}

bool valid(vector<vector<int>> g, int dir) {
  int seen = 0;
  if (dir == 3) {
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
        if (g[i][j] == 0) continue;
        int nx = i + dx[dir],
        ny = j + dy[dir];
        seen |= simulate(g, i, j, nx, ny);
      }
    }
  }
  if (dir == 2) {
    for (int j = 3; j >= 0; --j) {
      for (int i = 0; i < 4; ++i) {
        if (g[i][j] == 0) continue;
        int nx = i + dx[dir],
        ny = j + dy[dir];
        seen |= simulate(g, i, j, nx, ny);
      }
    }
  }
  if (dir == 1) {
    for (int j = 0; j < 4; ++j) {
      for (int i = 0; i < 4; ++i) {
        if (g[i][j] == 0) continue;
        int nx = i + dx[dir],
        ny = j + dy[dir];
        seen |= simulate(g, i, j, nx, ny);
      }
    }
  }

  if (dir == 0) {
    for (int i = 3; i >= 0; --i) {
      for (int j = 0; j < 4; ++j) {
        if (g[i][j] == 0) continue;
        int nx = i + dx[dir],
        ny = j + dy[dir];
        seen |= simulate(g, i, j, nx, ny);
      }
    }
  }
  return seen;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc; cin >> tc;
  while (tc--) {
    vector<vector<int>> g(4, vector<int>(4));
    int finished = 0;
    for (auto &i : g) for (auto &j : i) {
      cin >> j;
      if (j == 2048)
        finished = true;
    }

    int first = true;
    if (!finished) {
      for (int i = 0; i < 4; ++i) {
        if (valid(g, i)) {
          if (!first) cout << " ";
          first = false;
          cout << ans[i];
        }
      }
    }
    if (first)
      cout << "NONE";
    cout << endl;
  }

  return 0;
}
