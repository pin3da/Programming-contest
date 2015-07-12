using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

const double eps = 1e-9;
int cmp(double x, double y, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

string line;

int right(int x) {
  return (x + 1) % 4;
}

int left(int x) {
  return (x - 1 + 4) % 4;
}

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

const int MN = 111;
int color[MN][MN][20][5];
int dp[MN][MN][20][5];


int w, c;
bool go(vector<vector<char> > &g, int x, int y, int s, int dir) {
  if (s == line.size())
    s = 0;

  if (g[x][y] == 'E') {
    color[x][y][s][dir] = 2;
    return dp[x][y][s][dir] = true;
  }

  if (color[x][y][s][dir] == 2) {
    return dp[x][y][s][dir];
  }
  else if (color[x][y][s][dir] == 1) {
    color[x][y][s][dir] = 2;
    return  dp[x][y][s][dir] = false;
  }


  color[x][y][s][dir] = 1;

  if (line[s] == 'S') {
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if (nx < 0 || nx >= w || ny < 0 || ny >= c || g[nx][ny] == 'X') {
      nx = x;
      ny = y;
    }

    dp[x][y][s][dir] = go(g, nx, ny, s + 1, dir);
    color[x][y][s][dir] = 2;
    return dp[x][y][s][dir];
  }
  else if (line[s] == 'R') {
    dp[x][y][s][dir] = go(g, x, y, s + 1, right(dir));
    color[x][y][s][dir] = 2;
    return dp[x][y][s][dir];
  } else {
    dp[x][y][s][dir] = go(g, x, y, s + 1, left(dir));
    color[x][y][s][dir] = 2;
    return dp[x][y][s][dir];
  }
}

int main() {
  while (cin >> w >> c) {
    int tot = 0;
    vector<vector<char> > g(w, vector<char>(c));
    for (int i = 0; i < w; ++i) {
      for (int j = 0; j < c; ++j) {
        cin >> g[i][j];
        if (g[i][j] != 'X')
          tot++;
      }
    }
    int st;
    cin >> st;
    cin >> line;

    memset(color, 0, sizeof color);
    memset(dp, false, sizeof dp);

    int cur = 0;
    for (int i = 0; i < w; ++i) {
      for (int j = 0; j < c; ++j) {
        if (g[i][j] != 'X' && go(g, i, j, 0, 0)) {
          cur++;
        }
      }
    }

    if (cur == tot) {
      cout << "OK" << endl;
    } else {
      cout << cur << endl;
    }
  }
  return 0;
}
