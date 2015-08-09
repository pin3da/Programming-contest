using namespace std;
#include <bits/stdc++.h>
#define endl '\n'


int dx[] = {-1, 1, 1, -1};
int dy[] = {-1, 1, -1, 1};

int best;

bool va(vector<vector<char>> &g, int a, int b) {
  return a >= 0  && b >= 0 && a < g.size()  && b < g[0].size();
}

void solve(vector<vector<char>> &g, int x, int y, int d) {
  for (int k = 0; k < 4; ++k) {
    int nx = x + dx[k];
    int ny = y + dy[k];
    int mx = nx + dx[k];
    int my = ny + dy[k];
    if (va(g, nx, ny) && va(g, mx, my) && g[nx][ny] == 'B' && g[mx][my] == '#') {
      g[nx][ny] = '#';
      solve(g, mx, my, d + 1);
      g[nx][ny] = 'B';
    }
  }
  best = max(best, d);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc;
  cin >> tc;
  while (tc--) {
    vector<vector<char>> g(10, vector<char> (10));
    for (int i = 0; i < 10; ++i) {
      for (int j = 0; j < 10; ++j) {
        cin >> g[i][j];
      }
    }

    best = 0;
    for (int i = 0; i < 10; ++i) {
      for (int j = 0; j < 10; ++j) {
        if (g[i][j] == 'W') {
          g[i][j] = '#';
          solve(g, i, j, 0);
          g[i][j] = 'W';
        }
      }
    }
    cout << best << endl;
  }
  return 0;
}
