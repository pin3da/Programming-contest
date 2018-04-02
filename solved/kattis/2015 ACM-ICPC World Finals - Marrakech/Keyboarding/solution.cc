using namespace std;
#include <bits/stdc++.h>

const int MN = 55;
char g[MN][MN];

struct state {
  int x, y, k, cost;
  state(int a, int b, int c, int d) : x(a), y(b), k(c), cost(d) {}
  state() {}
};

bool vi[MN * MN][10001];

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int nxt[4][MN][MN];

int main() {
  int r, c;
  cin >> r >> c;
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      cin >> g[i][j];
    }
  }

  for (int j = 0; j < c; ++j) {
    for (int i = 0; i < r; ++i) {
      if (j == 0) {
        nxt[0][i][j] = 0;
      } else {
        if (g[i][j - 1] == g[i][j])
          nxt[0][i][j] = nxt[0][i][j - 1];
        else
          nxt[0][i][j] = j - 1;
      }
    }
  }
  for (int j = c - 1; j >= 0; --j) {
    for (int i = 0; i < r; ++i) {
      if (j == c - 1) {
        nxt[1][i][j] = c - 1;
      } else {
        if (g[i][j + 1] == g[i][j])
          nxt[1][i][j] = nxt[1][i][j + 1];
        else
          nxt[1][i][j] = j + 1;
      }
    }
  }

  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (i == 0)
        nxt[2][i][j] = 0;
      else
        if (g[i - 1][j] == g[i][j])
          nxt[2][i][j] = nxt[2][i - 1][j];
        else
          nxt[2][i][j] = i - 1;
    }
  }

  for (int i = r - 1; i >= 0; --i) {
    for (int j = 0; j < c; ++j) {
      if (i == r - 1)
        nxt[3][i][j] = r - 1;
      else
        if (g[i + 1][j] == g[i][j])
          nxt[3][i][j] = nxt[3][i + 1][j];
        else
          nxt[3][i][j] = i + 1;
    }
  }


  string target;
  cin >> target;
  target.push_back('*');

  memset(vi, 0, sizeof vi);
  deque<state> q;
  q.push_back(state(0, 0, 0, 0));
  while (!q.empty()) {
    state cur = q.front();
    q.pop_front();
    int x = cur.x;
    int y = cur.y;
    int k = cur.k;
    int cost = cur.cost;
    int idx = x * c + y;

    if (k == target.size()) {
      cout << cost << endl;
      return 0;
    }
    if (vi[idx][k]) continue;
    vi[idx][k] = true;

    if (g[x][y] == target[k]) {
      q.push_back(state(x, y, k + 1, cost + 1));
    }

    int nx = x, ny = nxt[0][x][y];
    if (g[nx][ny] != g[x][y])
      q.push_back(state(nx, ny, k, cost + 1));

    nx = x, ny = nxt[1][x][y];
    if (g[nx][ny] != g[x][y])
      q.push_back(state(nx, ny, k, cost + 1));

    nx = nxt[2][x][y], ny = y;
    if (g[nx][ny] != g[x][y])
      q.push_back(state(nx, ny, k, cost + 1));

    nx = nxt[3][x][y], ny = y;
    if (g[nx][ny] != g[x][y])
      q.push_back(state(nx, ny, k, cost + 1));

    /*for (int i = 0; i < 4; ++i) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
        if (g[x][y] == g[nx][ny])
          q.push_back(state(nx, ny, k, cost));
        else
          q.push_back(state(nx, ny, k, cost + 1));
      }
    }*/

  }

  return 0;
}
